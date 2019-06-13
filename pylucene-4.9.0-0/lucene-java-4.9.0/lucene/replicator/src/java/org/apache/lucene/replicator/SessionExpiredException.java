package org.apache.lucene.replicator;

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

import java.io.IOException;

/**
 * Exception indicating that a revision update session was expired due to lack
 * of activity.
 * 
 * @see LocalReplicator#DEFAULT_SESSION_EXPIRATION_THRESHOLD
 * @see LocalReplicator#setExpirationThreshold(long)
 * 
 * @lucene.experimental
 */
public class SessionExpiredException extends IOException {
  
  /**
   * @see IOException#IOException(String, Throwable)
   */
  public SessionExpiredException(String message, Throwable cause) {
    super(message, cause);
  }
  
  /**
   * @see IOException#IOException(String)
   */
  public SessionExpiredException(String message) {
    super(message);
  }
  
  /**
   * @see IOException#IOException(Throwable)
   */
  public SessionExpiredException(Throwable cause) {
    super(cause);
  }
  
}
