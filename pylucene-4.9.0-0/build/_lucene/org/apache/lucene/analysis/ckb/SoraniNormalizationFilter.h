#ifndef org_apache_lucene_analysis_ckb_SoraniNormalizationFilter_H
#define org_apache_lucene_analysis_ckb_SoraniNormalizationFilter_H

#include "org/apache/lucene/analysis/TokenFilter.h"

namespace org {
  namespace apache {
    namespace lucene {
      namespace analysis {
        class TokenStream;
      }
    }
  }
}
namespace java {
  namespace lang {
    class Class;
  }
  namespace io {
    class IOException;
  }
}
template<class T> class JArray;

namespace org {
  namespace apache {
    namespace lucene {
      namespace analysis {
        namespace ckb {

          class SoraniNormalizationFilter : public ::org::apache::lucene::analysis::TokenFilter {
          public:
            enum {
              mid_init$_c7c794dc,
              mid_incrementToken_54c6a16a,
              max_mid
            };

            static ::java::lang::Class *class$;
            static jmethodID *mids$;
            static bool live$;
            static jclass initializeClass(bool);

            explicit SoraniNormalizationFilter(jobject obj) : ::org::apache::lucene::analysis::TokenFilter(obj) {
              if (obj != NULL)
                env->getClass(initializeClass);
            }
            SoraniNormalizationFilter(const SoraniNormalizationFilter& obj) : ::org::apache::lucene::analysis::TokenFilter(obj) {}

            SoraniNormalizationFilter(const ::org::apache::lucene::analysis::TokenStream &);

            jboolean incrementToken() const;
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
        namespace ckb {
          extern PyTypeObject PY_TYPE(SoraniNormalizationFilter);

          class t_SoraniNormalizationFilter {
          public:
            PyObject_HEAD
            SoraniNormalizationFilter object;
            static PyObject *wrap_Object(const SoraniNormalizationFilter&);
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
