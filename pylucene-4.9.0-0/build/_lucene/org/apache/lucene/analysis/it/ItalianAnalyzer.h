#ifndef org_apache_lucene_analysis_it_ItalianAnalyzer_H
#define org_apache_lucene_analysis_it_ItalianAnalyzer_H

#include "org/apache/lucene/analysis/util/StopwordAnalyzerBase.h"

namespace org {
  namespace apache {
    namespace lucene {
      namespace util {
        class Version;
      }
      namespace analysis {
        namespace util {
          class CharArraySet;
        }
      }
    }
  }
}
namespace java {
  namespace lang {
    class String;
    class Class;
  }
}
template<class T> class JArray;

namespace org {
  namespace apache {
    namespace lucene {
      namespace analysis {
        namespace it {

          class ItalianAnalyzer : public ::org::apache::lucene::analysis::util::StopwordAnalyzerBase {
          public:
            enum {
              mid_init$_0d96cf33,
              mid_init$_83eafe28,
              mid_init$_c9d7e4a3,
              mid_getDefaultStopSet_d2d3505c,
              mid_createComponents_1be39cae,
              max_mid
            };

            static ::java::lang::Class *class$;
            static jmethodID *mids$;
            static bool live$;
            static jclass initializeClass(bool);

            explicit ItalianAnalyzer(jobject obj) : ::org::apache::lucene::analysis::util::StopwordAnalyzerBase(obj) {
              if (obj != NULL)
                env->getClass(initializeClass);
            }
            ItalianAnalyzer(const ItalianAnalyzer& obj) : ::org::apache::lucene::analysis::util::StopwordAnalyzerBase(obj) {}

            static ::java::lang::String *DEFAULT_STOPWORD_FILE;

            ItalianAnalyzer(const ::org::apache::lucene::util::Version &);
            ItalianAnalyzer(const ::org::apache::lucene::util::Version &, const ::org::apache::lucene::analysis::util::CharArraySet &);
            ItalianAnalyzer(const ::org::apache::lucene::util::Version &, const ::org::apache::lucene::analysis::util::CharArraySet &, const ::org::apache::lucene::analysis::util::CharArraySet &);

            static ::org::apache::lucene::analysis::util::CharArraySet getDefaultStopSet();
          };
        }
      }
    }
  }
}

#include <Python.h>

namespace org {
  namespace apache {
    namespace lucene {
      namespace analysis {
        namespace it {
          extern PyTypeObject PY_TYPE(ItalianAnalyzer);

          class t_ItalianAnalyzer {
          public:
            PyObject_HEAD
            ItalianAnalyzer object;
            static PyObject *wrap_Object(const ItalianAnalyzer&);
            static PyObject *wrap_jobject(const jobject&);
            static void install(PyObject *module);
            static void initialize(PyObject *module);
          };
        }
      }
    }
  }
}

#endif
