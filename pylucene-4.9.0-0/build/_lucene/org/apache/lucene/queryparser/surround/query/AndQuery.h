#ifndef org_apache_lucene_queryparser_surround_query_AndQuery_H
#define org_apache_lucene_queryparser_surround_query_AndQuery_H

#include "org/apache/lucene/queryparser/surround/query/ComposedQuery.h"

namespace org {
  namespace apache {
    namespace lucene {
      namespace queryparser {
        namespace surround {
          namespace query {
            class SrndQuery;
            class BasicQueryFactory;
          }
        }
      }
      namespace search {
        class Query;
      }
    }
  }
}
namespace java {
  namespace lang {
    class Class;
    class String;
  }
  namespace util {
    class List;
  }
}
template<class T> class JArray;

namespace org {
  namespace apache {
    namespace lucene {
      namespace queryparser {
        namespace surround {
          namespace query {

            class AndQuery : public ::org::apache::lucene::queryparser::surround::query::ComposedQuery {
            public:
              enum {
                mid_init$_4136185e,
                mid_makeLuceneQueryFieldNoBoost_1aaeee30,
                max_mid
              };

              static ::java::lang::Class *class$;
              static jmethodID *mids$;
              static bool live$;
              static jclass initializeClass(bool);

              explicit AndQuery(jobject obj) : ::org::apache::lucene::queryparser::surround::query::ComposedQuery(obj) {
                if (obj != NULL)
                  env->getClass(initializeClass);
              }
              AndQuery(const AndQuery& obj) : ::org::apache::lucene::queryparser::surround::query::ComposedQuery(obj) {}

              AndQuery(const ::java::util::List &, jboolean, const ::java::lang::String &);

              ::org::apache::lucene::search::Query makeLuceneQueryFieldNoBoost(const ::java::lang::String &, const ::org::apache::lucene::queryparser::surround::query::BasicQueryFactory &) const;
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
        namespace surround {
          namespace query {
            extern PyTypeObject PY_TYPE(AndQuery);

            class t_AndQuery {
            public:
              PyObject_HEAD
              AndQuery object;
              static PyObject *wrap_Object(const AndQuery&);
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
