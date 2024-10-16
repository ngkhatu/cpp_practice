// Learncpp.com: section 5.10- Introduction to std::string_view (part 1)

#include <iostream>
#include <string>
#include <string_view>

// BEST PRACTICE- Prefer std::string_view over std::string when you need a
// read-only string, especially for function parameters.

void printString(std::string str) // str makes a copy of its initializer
{
  std::cout << str << '\n';
}

// str provides read-only access to whatever argument is passed in
void printSV(std::string_view str) // now a std::string_view
{
  std::cout << str << '\n';
}

int main() {
  std::string s{"Hello, world!"}; // s makes a copy of its initializer

  printString(s);
  printSV(s);

  // One of the neat things about a std::string_view is how flexible it is. A
  // std::string_view object can be initialized with a C-style string, a
  // std::string, or another std::string_view:

  std::string_view s1{
      "Hello, world!"}; // initialize with C-style string literal
  std::cout << s1 << '\n';

  std::string_view s2{s}; // initialize with std::string
  std::cout << s2 << '\n';

  std::string_view s3{s2}; // initialize with std::string_view
  std::cout << s3 << '\n';

  // Both a C-style string and a std::string will implicitly convert to a
  // std::string_view. Therefore, a std::string_view parameter will accept
  // arguments of type C-style string, a std::string, or std::string_view:

  printSV("Hello, world!"); // call with C-style string literal

  std::string s4{"Hello, world!"};
  printSV(s4); // call with std::string

  std::string_view s5{s4};
  printSV(s5); // call with std::string_view

  // Because std::string makes a copy of its initializer (which is expensive),
  // C++ won’t allow implicit conversion of a std::string_view to a std::string.
  // This is to prevent accidentally passing a std::string_view argument to a
  // std::string parameter, and inadvertently making an expensive copy where
  // such a copy may not be required.

  // However, if this is desired, we have two options:
  //* Explicitly create a std::string with a std::string_view initializer (which
  // is allowed, since this will rarely be done unintentionally)
  //* Convert an existing std::string_view to a std::string using static_cast

  std::string_view sv{"Hello, world!"};

  // printString(sv);   // compile error: won't implicitly convert
  // std::string_view to a std::string

  std::string s6{
      sv}; // okay: we can create std::string using std::string_view initializer
  printString(s6); // and call the function with the std::string

  printString(static_cast<std::string>(
      sv)); // okay: we can explicitly cast a std::string_view to a std::string

  // Assigning a new string to a std::string_view causes the std::string_view to
  // view the new string. It does not modify the prior string being viewed in
  // any way
  std::string name{"Alex"};
  std::string_view strv{name}; // sv is now viewing name
  std::cout << strv << '\n';   // prints Alex

  strv = "John";             // sv is now viewing "John" (does not change name)
  std::cout << strv << '\n'; // prints John

  std::cout << name << '\n'; // prints Alex

  using namespace std::string_literals;      // access the s suffix
  using namespace std::string_view_literals; // access the sv suffix
  std::cout << "foo\n";   // no suffix is a C-style string literal
  std::cout << "goo\n"s;  // s suffix is a std::string literal
  std::cout << "moo\n"sv; // sv suffix is a std::string_view literal

  // Unlike std::string, std::string_view has full support for constexpr:
  constexpr std::string_view s7{
      "Hello, world!"}; // s is a string symbolic constant
  std::cout << s7
            << '\n'; // s will be replaced with "Hello, world!" at compile-time
  return 0;
}
