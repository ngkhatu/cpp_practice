
#include <iostream>
#include <string>

// learncpp.com: section 12.14- Type deduction with Pointers, References, and
// const

/*
// ###############################top########################################
int main() {
  int a{5};
  auto b{a}; // b deduced as an int

  return 0;
}
// #################################bottom######################################
 */
// ###############################top########################################

/* // Type deduction will drop references. Can reapply the defintion
std::string &getRef(); // some function that returns a reference

int main() {
  auto ref{getRef()}; // type deduced as std::string (not std::string&)
  auto &ref2{getRef()}; // std::string& (reference dropped, reference reapplied)

  return 0;
} */
// #################################bottom######################################

// ###############################top########################################
/* // Top-level const
const int x;    // this const applies to x, so it is top-level
int *const ptr; // this const applies to ptr, so it is top-level

// Low Level Consts
const int &ref; // this const applies to the object being referenced, so it is
                // low-level
const int *ptr; // this const applies to the object being pointed to, so it is
                // low-level

// A reference to a const value is always a low-level const. A pointer can have
// a top-level, low-level, or both kinds of const
const int
    *const ptr; // the left const is low-level, the right const is top-level */
// #################################bottom######################################

// ###############################top########################################

const std::string &
getConstRef(); // some function that returns a reference to const

int main() {
  auto ref1{getConstRef()}; // std::string (reference dropped, then top-level
                            // const dropped from result)

  return 0;
}
// #################################bottom######################################
// ###############################top########################################
#include <string>

const std::string &
getConstRef(); // some function that returns a const reference

int main() {
  auto ref1{
      getConstRef()}; // std::string (reference and top-level const dropped)
  const auto ref2{getConstRef()}; // const std::string (reference dropped, const
                                  // dropped, const reapplied)

  auto &ref3{getConstRef()};       // const std::string& (reference dropped and
                                   // reapplied, low-level const not dropped)
  const auto &ref4{getConstRef()}; // const std::string& (reference dropped and
                                   // reapplied, low-level const not dropped)

  return 0;
}
// #################################bottom######################################
// ###############################top########################################
#include <iostream>
#include <string_view>

constexpr std::string_view hello{"Hello"}; // implicitly const

constexpr const std::string_view &
getConstRef() // function is constexpr, returns a const std::string_view&
{
  return hello;
}

int main() {
  auto ref1{getConstRef()}; // std::string_view (reference dropped and top-level
                            // const dropped)
  constexpr auto ref2{
      getConstRef()}; // constexpr const std::string_view (reference dropped and
                      // top-level const dropped, constexpr applied, implicitly
                      // const)

  auto &ref3{getConstRef()}; // const std::string_view& (reference reapplied,
                             // low-level const not dropped)
  constexpr const auto &ref4{
      getConstRef()}; // constexpr const std::string_view& (reference reapplied,
                      // low-level const not dropped, constexpr applied)

  return 0;
}
// #################################bottom######################################
// ###############################top########################################
#include <string>

std::string *getPtr(); // some function that returns a pointer

int main() {
  auto ptr1{getPtr()}; // std::string*

  return 0;
}
// #################################bottom######################################
// ###############################top########################################
#include <string>

std::string *getPtr(); // some function that returns a pointer

int main() {
  auto ptr1{getPtr()};  // std::string*
  auto *ptr2{getPtr()}; // std::string*

  return 0;
}
// #################################bottom######################################
// ###############################top########################################
#include <string>

std::string *getPtr(); // some function that returns a pointer

int main() {
  auto ptr3{*getPtr()};  // std::string (because we dereferenced getPtr())
  auto *ptr4{*getPtr()}; // does not compile (initializer not a pointer)

  return 0;
}
// #################################bottom######################################
// ###############################top########################################
#include <string>

std::string *getPtr(); // some function that returns a pointer

int main() {
  const auto ptr1{getPtr()}; // std::string* const
  auto const ptr2{getPtr()}; // std::string* const

  const auto *ptr3{getPtr()}; // const std::string*
  auto *const ptr4{getPtr()}; // std::string* const

  return 0;
}
// #################################bottom######################################
// ###############################top########################################
#include <string>

int main() {
  std::string s{};
  const std::string *const ptr{&s};

  auto ptr1{ptr};  // const std::string*
  auto *ptr2{ptr}; // const std::string*

  auto const ptr3{ptr}; // const std::string* const
  const auto ptr4{ptr}; // const std::string* const

  auto *const ptr5{ptr}; // const std::string* const
  const auto *ptr6{ptr}; // const std::string*

  const auto const ptr7{ptr};  // error: const qualifer can not be applied twice
  const auto *const ptr8{ptr}; // const std::string* const

  return 0;
}
// #################################bottom######################################
* /

    // ###############################top########################################

    // #################################bottom######################################
    // ###############################top########################################

    // #################################bottom######################################
    // ###############################top########################################

    // #################################bottom######################################
    // ###############################top########################################

    // #################################bottom######################################
