// Learncpp.com: section 11.10- Using function templates in multiple files
/*
#include <iostream>

// In main.cpp, we call addOne<int> and addOne<double>. However, since the
// compiler can’t see the definition for function template addOne, it can’t
// instantiate those functions inside main.cpp. It does see the forward
// declaration for addOne though, and will assume those functions exist
// elsewhere and will be linked in later.

// When the compiler goes to compile add.cpp, it will see the definition for
// function template addOne. However, there are no uses of this template in
// add.cpp, so the compiler will not instantiate anything. The end result is
// that the linker is unable to connect the calls to addOne<int> and
// addOne<double> in main.cpp to the actual functions, because those functions
// were never instantiated.

// The most conventional way to address this issue is to put all your template
// code in a header (.h) file instead of a source (.cpp) file:
#include "add.h"

template <typename T> T addOne(T x); // function template forward declaration

int main() {
  std::cout << addOne(1) << '\n';
  std::cout << addOne(2.3) << '\n';

  return 0;
}

// That way, any files that need access to the template can #include the
// relevant header, and the template definition will be copied by the
// preprocessor into the source file. The compiler will then be able to
// instantiate any functions that are needed.

// You may be wondering why this doesn’t cause a violation of the one-definition
// rule (ODR). The ODR says that types, templates, inline functions, and inline
// variables are allowed to have identical definitions in different files. So
// there is no problem if the template definition is copied into multiple files
// (as long as each definition is identical).
 */

// ##############################################
// Another example
#include "max.h" // import template definition for max<T>(T, T)
#include <iostream>

void foo(); // forward declaration for function foo

int main() {
  std::cout << max(3, 5) << '\n';
  foo();

  return 0;
}

// In the above example, both main.cpp and foo.cpp #include "max.h" so the code
// in both files can make use of the max<T>(T, T) function template.

// Best Practice- Templates that are needed in multiple files should be defined
// in a header file, and then #included wherever needed. This allows the
// compiler to see the full template definition and instantiate the template
// when needed.
