

// If addOne were a non-template function, this program would work fine: In
// main.cpp, the compiler would be satisfied with the forward declaration of
// addOne, and the linker would connect the call to addOne() in main.cpp to the
// function definition in add.cpp.

// But because addOne is a template, this program doesn’t work, and we get a
// linker error.

/* template <typename T>
T addOne(T x) // function template definition
{
  return x + 1;
}
 */
