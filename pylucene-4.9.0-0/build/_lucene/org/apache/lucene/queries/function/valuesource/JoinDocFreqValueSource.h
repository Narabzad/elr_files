#ifndef org_apache_lucene_queries_function_valuesource_JoinDocFreqValueSource_H
#define org_apache_lucene_queries_function_valuesource_JoinDocFreqValueSource_H

#include "org/apache/lucene/queries/function/valuesource/FieldCacheSource.h"

namespace org {
  namespace apache {
    namespace lucene {
      namespace index {
        class AtomicReaderContext;
      }
      namespace queries {
        namespace function {
          class FunctionValues;
        }
      }
    }
  }
}
namespace java {
  namespace lang {
    class Object;
    class Class;
    class String;
  }
  namespace util {
    class Map;
  }
  namespace io {
    class IOException;
  }
}
template<class T> class JArray;

namespace org {
  namespace apache {
    namespace lucene {
      namespace queries {
        namespace function {
          namespace valuesource {

            class JoinDocFreqValueSource : public ::org::apache::lucene::queries::function::valuesource::FieldCacheSource {
            public:
              enum {
                mid_init$_4a264742,
                mid_description_14c7b5c5,
                mid_equals_290588e2,
                mid_getValues_4c566485,
                mid_hashCode_54c6a179,
                max_mid
              };

              static ::java::lang::Class *class$;
              static jmethodID *mids$;
              static bool live$;
              static jclass initializeClass(bool);

              explicit JoinDocFreqValueSource(jobject obj) : ::org::apache::lucene::queries::function::valuesource::FieldCacheSource(obj) {
                if (obj != NULL)
                  env->getClass(initializeClass);
              }
              JoinDocFreqValueSource(const JoinDocFreqValueSource& obj) : ::org::apache::lucene::queries::function::valuesource::FieldCacheSource(obj) {}

              static ::java::lang::String *NAME;

              JoinDocFreqValueSource(const ::java::lang::String &, const ::java::lang::String &);

              ::java::lang::String description() const;
              jboolean equals(const ::java::lang::Object &) const;
              ::org::apache::lucene::queries::function::FunctionValues getValues(const ::java::util::Map &, const ::org::apache::lucene::index::AtomicReaderContext &) const;
              jint hashCode() const;
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
      namespace queries {
        namespace function {
          namespace valuesource {
            extern PyTypeObject PY_TYPE(JoinDocFreqValueSource);

            class t_JoinDocFreqValueSource {
            public:
              PyObject_HEAD
              JoinDocFreqValueSource object;
              static PyObject *wrap_Object(const JoinDocFreqValueSource&);
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
