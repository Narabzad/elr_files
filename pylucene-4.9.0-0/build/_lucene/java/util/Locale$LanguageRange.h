#ifndef java_util_Locale$LanguageRange_H
#define java_util_Locale$LanguageRange_H

#include "java/lang/Object.h"

namespace java {
  namespace lang {
    class Class;
    class String;
  }
  namespace util {
    class Map;
    class List;
  }
}
template<class T> class JArray;

namespace java {
  namespace util {

    class Locale$LanguageRange : public ::java::lang::Object {
    public:
      enum {
        mid_init$_5fdc3f48,
        mid_init$_493fce5f,
        mid_equals_290588e2,
        mid_getRange_14c7b5c5,
        mid_getWeight_54c6a174,
        mid_hashCode_54c6a179,
        mid_mapEquivalents_7f198911,
        mid_parse_0feb8f08,
        mid_parse_d2cd8932,
        max_mid
      };

      static ::java::lang::Class *class$;
      static jmethodID *mids$;
      static bool live$;
      static jclass initializeClass(bool);

      explicit Locale$LanguageRange(jobject obj) : ::java::lang::Object(obj) {
        if (obj != NULL)
          env->getClass(initializeClass);
      }
      Locale$LanguageRange(const Locale$LanguageRange& obj) : ::java::lang::Object(obj) {}

      static jdouble MAX_WEIGHT;
      static jdouble MIN_WEIGHT;

      Locale$LanguageRange(const ::java::lang::String &);
      Locale$LanguageRange(const ::java::lang::String &, jdouble);

      jboolean equals(const ::java::lang::Object &) const;
      ::java::lang::String getRange() const;
      jdouble getWeight() const;
      jint hashCode() const;
      static ::java::util::List mapEquivalents(const ::java::util::List &, const ::java::util::Map &);
      static ::java::util::List parse(const ::java::lang::String &);
      static ::java::util::List parse(const ::java::lang::String &, const ::java::util::Map &);
    };
  }
}

#include <Python.h>

namespace java {
  namespace util {
    extern PyTypeObject PY_TYPE(Locale$LanguageRange);

    class t_Locale$LanguageRange {
    public:
      PyObject_HEAD
      Locale$LanguageRange object;
      static PyObject *wrap_Object(const Locale$LanguageRange&);
      static PyObject *wrap_jobject(const jobject&);
      static void install(PyObject *module);
      static void initialize(PyObject *module);
    };
  }
}

#endif
