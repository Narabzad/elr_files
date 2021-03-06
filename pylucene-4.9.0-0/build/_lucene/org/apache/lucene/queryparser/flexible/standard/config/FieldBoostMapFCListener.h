#ifndef org_apache_lucene_queryparser_flexible_standard_config_FieldBoostMapFCListener_H
#define org_apache_lucene_queryparser_flexible_standard_config_FieldBoostMapFCListener_H

#include "java/lang/Object.h"

namespace org {
  namespace apache {
    namespace lucene {
      namespace queryparser {
        namespace flexible {
          namespace core {
            namespace config {
              class FieldConfigListener;
              class QueryConfigHandler;
              class FieldConfig;
            }
          }
        }
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
        namespace flexible {
          namespace standard {
            namespace config {

              class FieldBoostMapFCListener : public ::java::lang::Object {
              public:
                enum {
                  mid_init$_0b1f7132,
                  mid_buildFieldConfig_aaab7c6b,
                  max_mid
                };

                static ::java::lang::Class *class$;
                static jmethodID *mids$;
                static bool live$;
                static jclass initializeClass(bool);

                explicit FieldBoostMapFCListener(jobject obj) : ::java::lang::Object(obj) {
                  if (obj != NULL)
                    env->getClass(initializeClass);
                }
                FieldBoostMapFCListener(const FieldBoostMapFCListener& obj) : ::java::lang::Object(obj) {}

                FieldBoostMapFCListener(const ::org::apache::lucene::queryparser::flexible::core::config::QueryConfigHandler &);

                void buildFieldConfig(const ::org::apache::lucene::queryparser::flexible::core::config::FieldConfig &) const;
              };
            }
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
        namespace flexible {
          namespace standard {
            namespace config {
              extern PyTypeObject PY_TYPE(FieldBoostMapFCListener);

              class t_FieldBoostMapFCListener {
              public:
                PyObject_HEAD
                FieldBoostMapFCListener object;
                static PyObject *wrap_Object(const FieldBoostMapFCListener&);
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
}

#endif
