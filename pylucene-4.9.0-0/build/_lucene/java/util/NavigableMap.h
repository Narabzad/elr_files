#ifndef java_util_NavigableMap_H
#define java_util_NavigableMap_H

#include "java/util/SortedMap.h"

namespace java {
  namespace lang {
    class Object;
    class Class;
  }
  namespace util {
    class NavigableSet;
    class Map$Entry;
  }
}
template<class T> class JArray;

namespace java {
  namespace util {

    class NavigableMap : public ::java::util::SortedMap {
    public:
      enum {
        mid_ceilingEntry_7a966293,
        mid_ceilingKey_a932a95f,
        mid_descendingKeySet_1d81e42d,
        mid_descendingMap_6ede266b,
        mid_firstEntry_2971780b,
        mid_floorEntry_7a966293,
        mid_floorKey_a932a95f,
        mid_headMap_f28f2984,
        mid_headMap_a5e6fd88,
        mid_higherEntry_7a966293,
        mid_higherKey_a932a95f,
        mid_lastEntry_2971780b,
        mid_lowerEntry_7a966293,
        mid_lowerKey_a932a95f,
        mid_navigableKeySet_1d81e42d,
        mid_pollFirstEntry_2971780b,
        mid_pollLastEntry_2971780b,
        mid_subMap_fbdcba88,
        mid_subMap_775b2171,
        mid_tailMap_f28f2984,
        mid_tailMap_a5e6fd88,
        max_mid
      };

      static ::java::lang::Class *class$;
      static jmethodID *mids$;
      static bool live$;
      static jclass initializeClass(bool);

      explicit NavigableMap(jobject obj) : ::java::util::SortedMap(obj) {
        if (obj != NULL)
          env->getClass(initializeClass);
      }
      NavigableMap(const NavigableMap& obj) : ::java::util::SortedMap(obj) {}

      ::java::util::Map$Entry ceilingEntry(const ::java::lang::Object &) const;
      ::java::lang::Object ceilingKey(const ::java::lang::Object &) const;
      ::java::util::NavigableSet descendingKeySet() const;
      NavigableMap descendingMap() const;
      ::java::util::Map$Entry firstEntry() const;
      ::java::util::Map$Entry floorEntry(const ::java::lang::Object &) const;
      ::java::lang::Object floorKey(const ::java::lang::Object &) const;
      ::java::util::SortedMap headMap(const ::java::lang::Object &) const;
      NavigableMap headMap(const ::java::lang::Object &, jboolean) const;
      ::java::util::Map$Entry higherEntry(const ::java::lang::Object &) const;
      ::java::lang::Object higherKey(const ::java::lang::Object &) const;
      ::java::util::Map$Entry lastEntry() const;
      ::java::util::Map$Entry lowerEntry(const ::java::lang::Object &) const;
      ::java::lang::Object lowerKey(const ::java::lang::Object &) const;
      ::java::util::NavigableSet navigableKeySet() const;
      ::java::util::Map$Entry pollFirstEntry() const;
      ::java::util::Map$Entry pollLastEntry() const;
      ::java::util::SortedMap subMap(const ::java::lang::Object &, const ::java::lang::Object &) const;
      NavigableMap subMap(const ::java::lang::Object &, jboolean, const ::java::lang::Object &, jboolean) const;
      ::java::util::SortedMap tailMap(const ::java::lang::Object &) const;
      NavigableMap tailMap(const ::java::lang::Object &, jboolean) const;
    };
  }
}

#include <Python.h>

namespace java {
  namespace util {
    extern PyTypeObject PY_TYPE(NavigableMap);

    class t_NavigableMap {
    public:
      PyObject_HEAD
      NavigableMap object;
      PyTypeObject *parameters[2];
      static PyTypeObject **parameters_(t_NavigableMap *self)
      {
        return (PyTypeObject **) &(self->parameters);
      }
      static PyObject *wrap_Object(const NavigableMap&);
      static PyObject *wrap_jobject(const jobject&);
      static PyObject *wrap_Object(const NavigableMap&, PyTypeObject *, PyTypeObject *);
      static PyObject *wrap_jobject(const jobject&, PyTypeObject *, PyTypeObject *);
      static void install(PyObject *module);
      static void initialize(PyObject *module);
    };
  }
}

#endif
