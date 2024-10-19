// Learncpp.com: section 10.5- Arithmetic Conversion

/*
But what happens when the operands of a binary operator are of different types?

??? y { 2 + 3.5 };
In this case, operator+ is being given one operand of type int and another of
type double. Should the result of the operator be returned as an int, a double,
or possibly something else altogether?

In C++, certain operators require that their operands be of the same type. If
one of these operators is invoked with operands of different types, one or both
of the operands will be implicitly converted to matching types using a set of
rules called the usual arithmetic conversions. The matching type produced as a
result of the usual arithmetic conversion rules is called the common type of the
operands.

The following operators require their operands to be of the same type:
------------------------------------------------------------------------
The binary arithmetic operators: +, -, *, /, %
The binary relational operators: <, >, <=, >=, ==, !=
The binary bitwise arithmetic operators: &, ^, |
The conditional operator ?: (excluding the condition, which is expected to be of
type bool)


The usual arithmetic conversion rules are somewhat complex, so we’ll simplify a
bit. The compiler has a ranked list of types that looks something like this:
------------------------------------------------------------------------
long double (highest rank)
double
float
long long
long
int (lowest rank)
The following rules are applied to find a matching type:

If one operand is an integral type and the other a floating point type, the
integral operand is converted to the type of the floating point operand (no
integral promotion takes place).

Otherwise, any integral operands are numerically promoted (see 10.2 --
Floating-point and integral promotion).

If one operand is signed and the other unsigned, special rules apply (see below)
Otherwise, the operand with lower rank is converted to the type of the operand
with higher rank.

*/
/*
#include <iostream>
#include <typeinfo> // for typeid()

int main() {
  int i{2};
  std::cout << typeid(i).name() << '\n'; // show us the name of the type for i

  double d{3.5};
  std::cout << typeid(d).name() << '\n'; // show us the name of the type for d

  std::cout << typeid(i + d).name() << ' ' << i + d
            << '\n'; // show us the type of i + d

  return 0;

  // Note that your compiler may display something slightly different, as the
  // names output by typeid.name() are implementation-specific.
  // int
  // double
  // double 5.5
}
 */

//------------------------------------------------------------------
/* // Two values of type short
#include <iostream>
#include <typeinfo> // for typeid()

int main() {
  short a{4};
  short b{5};
  std::cout << typeid(a + b).name() << ' ' << a + b
            << '\n'; // show us the type of a + b

  return 0;
  // Because neither operand appears on the priority list, both operands undergo
  // integral promotion to type int. The result of adding two ints is an int, as
  // you would expect:
  // int 9
}
 */
//------------------------------------------------------------------

/* // This prioritization hierarchy and conversion rules can cause some
problematic
// issues when mixing signed and unsigned values

#include <iostream>
#include <typeinfo> // for typeid()

int main() {
  std::cout << typeid(5u - 10).name() << ' ' << 5u - 10
            << '\n'; // 5u means treat 5 as an unsigned integer

  return 0;
}
// Result is (j) unsigned int 4294967291
// Due to the conversion rules, the int operand is converted to an unsigned int.
// And since the value -5 is out of range of an unsigned int, we get a result we
// don’t expect.
 */
//------------------------------------------------------------------

// Another counterintuitive result
#include <iostream>

int main() {
  std::cout << std::boolalpha << (-3 < 5u) << '\n';

  return 0;
}
// While it’s clear to us that 5 is greater than -3, when this expression
// evaluates, -3 is converted to a large unsigned int that is larger than 5.
// Thus, the above prints false rather than the expected result of true.

// This is one of the primary reasons to avoid unsigned integers -- when you mix
// them with signed integers in arithmetic expressions, you’re at risk for
// unexpected results. And the compiler probably won’t even issue a warning.

// ##########################################################################

// std::common_type and std::common_type_t
//.........................................
// std::common_type and the useful type alias std::common_type_t (both defined
// in the <type_traits> header) can be used for just this purpose.

// For example, std::common_type_t<int, double> returns the common type of int
// and double, and std::common_type_t<unsigned int, long> returns the common
// type of unsigned int and long.
