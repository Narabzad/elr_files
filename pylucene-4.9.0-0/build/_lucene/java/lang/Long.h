#ifndef java_lang_Long_H
#define java_lang_Long_H

#include "java/lang/Number.h"

namespace java {
  namespace lang {
    class NumberFormatException;
    class Comparable;
    class Object;
    class Class;
    class String;
  }
}
template<class T> class JArray;

namespace java {
  namespace lang {

    class Long : public ::java::lang::Number {
    public:
      enum {
        mid_init$_0ee6df2f,
        mid_init$_5fdc3f48,
        mid_bitCount_0ee6df30,
        mid_byteValue_54c6a172,
        mid_compare_a7e12cbb,
        mid_compareTo_da55802e,
        mid_compareUnsigned_a7e12cbb,
        mid_decode_ee9f94be,
        mid_divideUnsigned_a7e12cb8,
        mid_doubleValue_54c6a174,
        mid_equals_290588e2,
        mid_floatValue_54c6a176,
        mid_getLong_ee9f94be,
        mid_getLong_9f081a1d,
        mid_getLong_9a12142f,
        mid_hashCode_54c6a179,
        mid_hashCode_0ee6df30,
        mid_highestOneBit_0ee6df33,
        mid_intValue_54c6a179,
        mid_longValue_54c6a17a,
        mid_lowestOneBit_0ee6df33,
        mid_max_a7e12cb8,
        mid_min_a7e12cb8,
        mid_numberOfLeadingZeros_0ee6df30,
        mid_numberOfTrailingZeros_0ee6df30,
        mid_parseLong_5fdc3f54,
        mid_parseLong_6e53ccda,
        mid_parseUnsignedLong_5fdc3f54,
        mid_parseUnsignedLong_6e53ccda,
        mid_remainderUnsigned_a7e12cb8,
        mid_reverse_0ee6df33,
        mid_reverseBytes_0ee6df33,
        mid_rotateLeft_25d05c93,
        mid_rotateRight_25d05c93,
        mid_shortValue_54c6a163,
        mid_signum_0ee6df30,
        mid_sum_a7e12cb8,
        mid_toBinaryString_3e02f30e,
        mid_toHexString_3e02f30e,
        mid_toOctalString_3e02f30e,
        mid_toString_14c7b5c5,
        mid_toString_3e02f30e,
        mid_toString_36a2b01a,
        mid_toUnsignedString_3e02f30e,
        mid_toUnsignedString_36a2b01a,
        mid_valueOf_62a69723,
        mid_valueOf_ee9f94be,
        mid_valueOf_212f058c,
        max_mid
      };

      static ::java::lang::Class *class$;
      static jmethodID *mids$;
      static bool live$;
      static jclass initializeClass(bool);

      explicit Long(jobject obj) : ::java::lang::Number(obj) {
        if (obj != NULL)
          env->getClass(initializeClass);
      }
      Long(const Long& obj) : ::java::lang::Number(obj) {}

      static jint BYTES;
      static jlong MAX_VALUE;
      static jlong MIN_VALUE;
      static jint SIZE;
      static ::java::lang::Class *TYPE;

      Long(jlong);
      Long(const ::java::lang::String &);

      static jint bitCount(jlong);
      jbyte byteValue() const;
      static jint compare(jlong, jlong);
      jint compareTo(const Long &) const;
      static jint compareUnsigned(jlong, jlong);
      static Long decode(const ::java::lang::String &);
      static jlong divideUnsigned(jlong, jlong);
      jdouble doubleValue() const;
      jboolean equals(const ::java::lang::Object &) const;
      jfloat floatValue() const;
      static Long getLong(const ::java::lang::String &);
      static Long getLong(const ::java::lang::String &, jlong);
      static Long getLong(const ::java::lang::String &, const Long &);
      jint hashCode() const;
      static jint hashCode(jlong);
      static jlong highestOneBit(jlong);
      jint intValue() const;
      jlong longValue() const;
      static jlong lowestOneBit(jlong);
      static jlong max$(jlong, jlong);
      static jlong min$(jlong, jlong);
      static jint numberOfLeadingZeros(jlong);
      static jint numberOfTrailingZeros(jlong);
      static jlong parseLong(const ::java::lang::String &);
      static jlong parseLong(const ::java::lang::String &, jint);
      static jlong parseUnsignedLong(const ::java::lang::String &);
      static jlong parseUnsignedLong(const ::java::lang::String &, jint);
      static jlong remainderUnsigned(jlong, jlong);
      static jlong reverse(jlong);
      static jlong reverseBytes(jlong);
      static jlong rotateLeft(jlong, jint);
      static jlong rotateRight(jlong, jint);
      jshort shortValue() const;
      static jint signum(jlong);
      static jlong sum(jlong, jlong);
      static ::java::lang::String toBinaryString(jlong);
      static ::java::lang::String toHexString(jlong);
      static ::java::lang::String toOctalString(jlong);
      ::java::lang::String toString() const;
      static ::java::lang::String toString(jlong);
      static ::java::lang::String toString(jlong, jint);
      static ::java::lang::String toUnsignedString(jlong);
      static ::java::lang::String toUnsignedString(jlong, jint);
      static Long valueOf(jlong);
      static Long valueOf(const ::java::lang::String &);
      static Long valueOf(const ::java::lang::String &, jint);
    };
  }
}

#include <Python.h>

namespace java {
  namespace lang {
    extern PyTypeObject PY_TYPE(Long);

    class t_Long {
    public:
      PyObject_HEAD
      Long object;
      static PyObject *wrap_Object(const Long&);
      static PyObject *wrap_jobject(const jobject&);
      static void install(PyObject *module);
      static void initialize(PyObject *module);
    };
  }
}

#endif
