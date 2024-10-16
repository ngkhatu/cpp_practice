// Learncpp.com: section 5.11- std::string_view (part 2)

// introduction to owners and viewers

// std::string is an owner

// You might be wondering why std::string makes an expensive copy of its
// initializer. When an object is instantiated, memory is allocated for that
// object to store whatever data it needs to use throughout its lifetime. This
// memory is reserved for the object, and guaranteed to exist for as long as the
// object does. It is a safe space. std::string (and most other objects) copy
// the initialization value they are given into this memory so that they can
// have their own independent value to access and manipulate later. Once the
// initialization value has been copied, the object is no longer reliant on the
// initializer in any way.

// std::string_view is a viewer

// std::string_view takes a different approach to initialization. Instead of
// making an expensive copy of the initialization string, std::string_view
// creates an inexpensive view of the initialization string. The
// std::string_view can then be used whenever access to the string is required.

//* It is important to note that a std::string_view remains dependent on the
// initializer through its lifetime. If the string being viewed is modified or
// destroyed while the view is still being used, unexpected or undefined
// behavior will result.
// - A std::string_view that is viewing a string that has been destroyed is
// sometimes called a dangling view.

#include <iostream>
#include <string>
#include <string_view>

/* // Invalidated objects can often be revalidated (made valid again) by setting
// them back to a known good state. For an invalidated std::string_view, we can
// do this by assigning the invalidated std::string_view object a valid string
// to view

// Because local variables are destroyed at the end of the function, returning a
// std::string_view that is viewing a local variable will result in the returned
// std::string_view being invalid, and further use of that std::string_view will
// result in undefined behavior
std::string_view getBoolName(bool b) {
  std::string t{"true"};  // local variable
  std::string f{"false"}; // local variable

  if (b)
    return t; // return a std::string_view viewing t

  return f; // return a std::string_view viewing f
} // t and f are destroyed at the end of the function

int main() {
  std::string s{"Hello, world!"};
  std::string_view sv{s}; // sv is now viewing s

  s = "Hello, universe!"; // modifies s, which invalidates sv (s is still valid)
  std::cout << sv << '\n'; // undefined behavior

  sv = s;                  // revalidate sv: sv is now viewing s again
  std::cout << sv << '\n'; // prints "Hello, universe!"

  std::cout << getBoolName(true) << ' ' << getBoolName(false)
            << '\n'; // undefined behavior

  return 0;
}
 */
std::string_view firstAlphabetical(std::string_view s1, std::string_view s2) {
  return s1 < s2 ? s1 : s2; // uses operator?: (the conditional operator)
}

std::string_view getBoolName(bool b) {
  if (b)
    return "true"; // return a std::string_view viewing "true"

  return "false"; // return a std::string_view viewing "false"
} // "true" and "false" are not destroyed at the end of the function

int main() {

  // There are two main cases where a std::string_view can be returned safely.
  // First, because C-style string literals exist for the entire program, it’s
  // fine (and useful) to return C-style string literals from a function that
  // has a return type of std::string_view.
  std::cout << getBoolName(true) << ' ' << getBoolName(false) << '\n'; // ok

  std::string a{"World"};
  std::string b{"Hello"};

  // Second, it is generally okay to return a function parameter of type
  // std::string_view:
  std::cout << firstAlphabetical(a, b) << '\n'; // prints "Hello"
  // one important subtlety here. If the argument is a temporary object (that
  // will be destroyed at the end of the full expression containing the function
  // call), the std::string_view return value must be used in the same
  // expression. After that point, the temporary is destroyed and the
  // std::string_view is left dangling

  std::string_view str{"Peach"};
  std::cout << str << '\n';

  // Remove 1 character from the left side of the view
  str.remove_prefix(1);
  std::cout << str << '\n';

  // Remove 2 characters from the right side of the view
  str.remove_suffix(2);
  std::cout << str << '\n';

  str = "Peach"; // reset the view
  std::cout << str << '\n';

  return 0;
}
