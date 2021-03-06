#ifndef org_apache_lucene_queryparser_xml_builders_TermsQueryBuilder_H
#define org_apache_lucene_queryparser_xml_builders_TermsQueryBuilder_H

#include "java/lang/Object.h"

namespace org {
  namespace apache {
    namespace lucene {
      namespace queryparser {
        namespace xml {
          class QueryBuilder;
        }
      }
      namespace search {
        class Query;
      }
      namespace analysis {
        class Analyzer;
      }
    }
  }
}
namespace java {
  namespace lang {
    class Class;
  }
}
template<class T> class JArray;

namespace org {
  namespace apache {
    namespace lucene {
      namespace queryparser {
        namespace xml {
          namespace builders {

            class TermsQueryBuilder : public ::java::lang::Object {
            public:
              enum {
                mid_init$_31619410,
                max_mid
              };

              static ::java::lang::Class *class$;
              static jmethodID *mids$;
              static bool live$;
              static jclass initializeClass(bool);

              explicit TermsQueryBuilder(jobject obj) : ::java::lang::Object(obj) {
                if (obj != NULL)
                  env->getClass(initializeClass);
              }
              TermsQueryBuilder(const TermsQueryBuilder& obj) : ::java::lang::Object(obj) {}

              TermsQueryBuilder(const ::org::apache::lucene::analysis::Analyzer &);
            };
          }
        }
      }
    }
  }
}

#include <Python.h>

namespace org {
  namespace apache {
    namespace lucene {
      namespace queryparser {
        namespace xml {
          namespace builders {
            extern PyTypeObject PY_TYPE(TermsQueryBuilder);

            class t_TermsQueryBuilder {
            public:
              PyObject_HEAD
              TermsQueryBuilder object;
              static PyObject *wrap_Object(const TermsQueryBuilder&);
              static PyObject *wrap_jobject(const jobject&);
              static void install(PyObject *module);
              static void initialize(PyObject *module);
            };
          }
        }
      }
    }
  }
}

#endif
