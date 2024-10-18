// Learncpp.com: section 10.1- Implicit Type conversion

/*
When a type conversion is invoked (whether implicitly or explicitly), the
compiler will determine whether it can convert the value from the current type
to the desired type. If a valid conversion can be found, then the compiler will
produce a new value of the desired type. Note that type conversions don’t change
the value or type of the value or object being converted.

If the compiler can’t find an acceptable conversion, then the compilation will
fail with a compile error. Type conversions can fail for any number of reasons.
For example, the compiler might not know how to convert a value between the
original type and the desired type. In other cases, statements may disallow
certain types of conversions
*/
// int x { 3.5 }; // brace-initialization disallows conversions that result in
// data loss

/*
The standard conversions can be broadly divided into 4 categories, each covering
different types of conversions:

- Numeric promotions (covered in lesson 10.2 -- Floating-point and integral
promotion)
- Numeric conversions (covered in lesson 10.3 -- Numeric conversions)
- Arithmetic conversions (covered in lesson 10.5 -- Arithmetic conversions)
- Other conversions (which includes various pointer and reference conversions)

When a type conversion is needed, the compiler will see if there are standard
conversions that it can use to convert the value to the desired type. The
compiler may apply zero, one, or (in certain cases) two standard conversions in
the conversion process.

*/
