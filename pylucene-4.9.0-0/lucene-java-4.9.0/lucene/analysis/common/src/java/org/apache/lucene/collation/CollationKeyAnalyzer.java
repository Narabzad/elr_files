package org.apache.lucene.collation;

/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


import org.apache.lucene.analysis.Analyzer;
import org.apache.lucene.analysis.core.KeywordTokenizer;
import org.apache.lucene.util.IndexableBinaryStringTools; // javadoc @link
import org.apache.lucene.util.Version;

import java.text.Collator;
import java.io.Reader;

/**
 * <p>
 *   Configures {@link KeywordTokenizer} with {@link CollationAttributeFactory}.
 * </p>
 * <p>
 *   Converts the token into its {@link java.text.CollationKey}, and then
 *   encodes the CollationKey either directly or with 
 *   {@link IndexableBinaryStringTools} (see <a href="#version">below</a>), to allow 
 *   it to be stored as an index term.
 * </p>
 * <p>
 *   <strong>WARNING:</strong> Make sure you use exactly the same Collator at
 *   index and query time -- CollationKeys are only comparable when produced by
 *   the same Collator.  Since {@link java.text.RuleBasedCollator}s are not
 *   independently versioned, it is unsafe to search against stored
 *   CollationKeys unless the following are exactly the same (best practice is
 *   to store this information with the index and check that they remain the
 *   same at query time):
 * </p>
 * <ol>
 *   <li>JVM vendor</li>
 *   <li>JVM version, including patch version</li>
 *   <li>
 *     The language (and country and variant, if specified) of the Locale
 *     used when constructing the collator via
 *     {@link Collator#getInstance(java.util.Locale)}.
 *   </li>
 *   <li>
 *     The collation strength used - see {@link Collator#setStrength(int)}
 *   </li>
 * </ol> 
 * <p>
 *   The <code>ICUCollationKeyAnalyzer</code> in the analysis-icu package 
 *   uses ICU4J's Collator, which makes its
 *   its version available, thus allowing collation to be versioned
 *   independently from the JVM.  ICUCollationKeyAnalyzer is also significantly
 *   faster and generates significantly shorter keys than CollationKeyAnalyzer.
 *   See <a href="http://site.icu-project.org/charts/collation-icu4j-sun"
 *   >http://site.icu-project.org/charts/collation-icu4j-sun</a> for key
 *   generation timing and key length comparisons between ICU4J and
 *   java.text.Collator over several languages.
 * </p>
 * <p>
 *   CollationKeys generated by java.text.Collators are not compatible
 *   with those those generated by ICU Collators.  Specifically, if you use 
 *   CollationKeyAnalyzer to generate index terms, do not use
 *   ICUCollationKeyAnalyzer on the query side, or vice versa.
 * </p>
 * <a name="version"/>
 * <p>You must specify the required {@link Version}
 * compatibility when creating CollationKeyAnalyzer:
 * <ul>
 *   <li> As of 4.0, Collation Keys are directly encoded as bytes. Previous
 *   versions will encode the bytes with {@link IndexableBinaryStringTools}.
 * </ul>
 */
public final class CollationKeyAnalyzer extends Analyzer {
  private final Collator collator;
  private final CollationAttributeFactory factory;
  private final Version matchVersion;
  
  /**
   * Create a new CollationKeyAnalyzer, using the specified collator.
   * 
   * @param matchVersion See <a href="#version">above</a>
   * @param collator CollationKey generator
   */
  public CollationKeyAnalyzer(Version matchVersion, Collator collator) {
    this.matchVersion = matchVersion;
    this.collator = collator;
    this.factory = new CollationAttributeFactory(collator);
  }
  
  /**
   * @deprecated Use {@link CollationKeyAnalyzer#CollationKeyAnalyzer(Version, Collator)}
   *   and specify a version instead. This ctor will be removed in Lucene 5.0
   */
  @Deprecated
  public CollationKeyAnalyzer(Collator collator) {
    this(Version.LUCENE_3_1, collator);
  }

  @Override
  protected TokenStreamComponents createComponents(String fieldName,
      Reader reader) {
    if (matchVersion.onOrAfter(Version.LUCENE_4_0)) {
      KeywordTokenizer tokenizer = new KeywordTokenizer(factory, reader, KeywordTokenizer.DEFAULT_BUFFER_SIZE);
      return new TokenStreamComponents(tokenizer, tokenizer);
    } else {
      KeywordTokenizer tokenizer = new KeywordTokenizer(reader);
      return new TokenStreamComponents(tokenizer, new CollationKeyFilter(tokenizer, collator));
    }
  }
}
