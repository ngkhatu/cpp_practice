
#include <iostream>
#include <string>
#include <string_view>

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

/* const std::string &getConstRef(); // some function that returns a reference
to const

int main() {
  auto ref1{getConstRef()}; // std::string (reference dropped, then top-level
                            // const dropped from result)

  return 0;
}
// since getConstRef() returns a const std::string&, the reference is dropped
// first, leaving us with a const std::string. This const is now a top-level
// const, so it is also dropped, leaving the deduced type as std::string.
 */
// #################################bottom######################################
// ###############################top########################################
/* // reapply a reference and/or const:
const std::string &
getConstRef(); // some function that returns a const reference

int main() {
  auto ref1{
      getConstRef()}; // std::string (reference and top-level const dropped)
  const auto ref2{getConstRef()}; // const std::string (reference dropped, const
                                  // dropped, const reapplied)

  auto &ref3{getConstRef()}; // const std::string& (reference dropped and
                             // reapplied, low-level const not dropped)
  // Normally the reference would be dropped first, but
  // since we’ve reapplied the reference, it is not dropped.
  // That means the type is still const std::string&. And
  // since this const is a low-level const, it is not
  // dropped. Thus the deduced type is const std::string&.

  // The ref4 case works similarly to ref3, except we’ve reapplied the const
  // qualifier as well. Since the type is already deduced as a reference to
  // const, us reapplying const here is redundant. That said, using const here
  // makes it explicitly clear that our result will be const (whereas in the
  // ref3 case, the constness of the result is implicit and not obvious).

  const auto &ref4{getConstRef()}; // const std::string& (reference dropped and
                                   // reapplied, low-level const not dropped)

  return 0;
}
// BEST PRACTICE- If you want a const reference, reapply the const qualifier
// even when it’s not strictly necessary, as it makes your intent clear and
// helps prevent mistakes. */
// #################################bottom######################################
// ###############################top########################################

/* // * Constexpr is not part of an expression’s type, so it is not deduced by
auto
// * When defining a constexpr reference to a const variable (e.g. constexpr
// const int&), we need to apply both constexpr (which applies to the reference)
// and const (which applies to the type being referenced).
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
 */
//  #################################bottom######################################
//  ###############################top########################################
/* // Unlike references, type deduction does not drop pointers
std::string *getPtr(); // some function that returns a pointer

int main() {
  auto ptr1{getPtr()}; // std::string*

  return 0;
} */
// #################################bottom######################################
//  ###############################top########################################
/* // We can also use an asterisk in conjunction with pointer type deduction
// (auto*) to make it clearer that the deduced type is a pointer:
std::string *getPtr(); // some function that returns a pointer

int main() {
  auto ptr1{getPtr()};  // std::string*
  auto *ptr2{getPtr()}; // std::string*
  auto ptr3{*getPtr()};  // std::string (because we dereferenced getPtr())
  auto *ptr4{*getPtr()}; // does not compile (initializer not a pointer)

  return 0;
}*/
// #################################bottom######################################
//  ###############################top########################################
/* // there are differences in how auto and auto* behave when we introduce const
// into the equation.

// we have both the const pointer and the pointer to const cases to think about,
// and we also have auto vs auto*. Just like with references, only top-level
// const is dropped during pointer type deduction.

std::string *getPtr(); // some function that returns a pointer

int main() {
  const auto ptr1{getPtr()}; // std::string* const
  auto const ptr2{getPtr()}; // std::string* const
  // When we use either auto const or const auto, we’re saying, “make whatever
  // the deduced type is const”. So in the case of ptr1 and ptr2, the deduced
  // type is std::string*, and then const is applied, making the final type
  // std::string* const. This is similar to how const int and int const mean the
  // same thing.

  const auto *ptr3{getPtr()}; // const std::string*
  auto *const ptr4{getPtr()}; // std::string* const
  // when we use auto*, the order of the const qualifier matters. A const on the
  // left means “make the deduced pointer type a pointer to const”, whereas a
  // const on the right means “make the deduced pointer type a const pointer”.
  // Thus ptr3 ends up as a pointer to const, and ptr4 ends up as a const
  // pointer.

  return 0;
} */
// #################################bottom######################################
//  ###############################top########################################
// example where the initializer is a const pointer to const
int main() {
  std::string s{};
  const std::string *const ptr{&s};

  auto ptr1{ptr};  // const std::string*
  auto *ptr2{ptr}; // const std::string*
  // The top-level const (the const on the pointer itself) is dropped. The
  // low-level const on the object being pointed to is not dropped. So in both
  // cases, the final type is const std::string*.

  auto const ptr3{ptr}; // const std::string* const
  const auto ptr4{ptr}; // const std::string* const
  // he top-level const is dropped, but we’re reapplying it. The low-level const
  // on the object being pointed to is not dropped. So in both cases, the final
  // type is const std::string* const

  auto *const ptr5{ptr}; // const std::string* const
  const auto *ptr6{ptr}; // const std::string*
  // In both cases, the top-level const is dropped. For ptr5, the auto* const
  // reapplies the top-level const, so the final type is const std::string*
  // const. For ptr6, the const auto* applies const to the type being pointed to
  // (which in this case was already const), so the final type is const
  // std::string*

  const auto const ptr7{ptr};  // error: const qualifer can not be applied twice
  const auto *const ptr8{ptr}; // const std::string* const
  // In the ptr7 case, we’re applying the const qualifier twice, which is
  // disallowed, and will cause a compile error.

  // And finally, in the ptr8 case, we’re applying const on both sides of the
  // pointer (which is allowed since auto* must be a pointer type), so the
  // resulting types is const std::string* const.

  return 0;
}
// BEST PRACTICE: If you want a const pointer, pointer to const, or const
// pointer to const, reapply the const qualifier(s) even when it’s not
// strictly necessary, as it makes your intent clear and helps prevent
// mistakes.

// TIP: Consider using auto* when deducing a pointer type. Using auto* in this
// case makes it clearer that we are deducing a pointer type, enlists the
// compiler’s help to ensure we don’t deduce a non-pointer type, and gives you
// more control over const.

// #################################bottom######################################

// ###############################top########################################

// #################################bottom######################################
// ###############################top########################################

// #################################bottom######################################
// ###############################top########################################

// #################################bottom######################################
// ###############################top########################################

// #################################bottom######################################
