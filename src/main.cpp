// Learncpp.com: section 15.3- Nested types (Member types)

#include <iostream>
#include <string>
#include <string_view>

// Class types
// * Data members
// * Member Functions
// * Nested Types (Member Types)
//  -To create a nested type, you simply define the type inside the class, under
//  the appropriate access specifier
/*
enum class FruitType { apple, banana, cherry };

class Fruit {

private:
  FruitType m_type{};
  int m_percentageEaten{0};

public:
  Fruit(FruitType type) : m_type{type} {}

  FruitType getType() { return m_type; }
  int getPercentageEaten() { return m_percentageEaten; }

  bool isCherry() { return m_type == FruitType::cherry; }
};

int main() {

  Fruit apple{FruitType::apple};

  if (apple.getType() == FruitType::apple)
    std::cout << "I am an apple";
  else
    std::cout << "I am not an apple";

  return 0;
}
 */

// #################################################
/*
// BEST PRACTICE- Define any nested types at the top of your class type.

// class types act as a scope region for names declared within, just as
// namespaces do. Therefore
// * the fully qualified name of Type is Fruit::Type, and
// * the fully qualified name of the apple enumerator is Fruit::apple

class Fruit {

  // Type is defined under the public access specifier, so that the type name
  // and enumerators can be directly accessed by the public.
public:
  // FruitType has been moved inside the class, under the public access
  // specifier We've also renamed it Type and made it an enum rather than an
  // enum class

  // Nested type names must be fully defined before they can be used, so they
  // are usually defined first
  enum Type { apple, banana, cherry };

private:
  Type m_type{};
  int m_percentageEaten{0};

public:
  Fruit(Type type) : m_type{type} {}

  Type getType() { return m_type; }
  int getPercentageEaten() { return m_percentageEaten; }

  // Within the members of the class, we do not need to use the fully qualified
  // name
  bool isCherry() {
    return m_type == cherry;
  } // Inside members of Fruit, we no longer need to prefix enumerators with
    // FruitType::
};

int main() {
  // Outside the class, we must use the fully qualified name (e.g.
  // Fruit::apple).
  Fruit apple{Fruit::apple};

  if (apple.getType() == Fruit::apple)
    std::cout << "I am an apple";
  else
    std::cout << "I am not an apple";

  return 0;
}

// Since the class itself is now acting as a scope region, it’s somewhat
// redundant to use a scoped enumerator as well.
// * unscoped enum- access enumerators as Fruit::apple
// * scoped enum- access enumerators as Fruit::Type::apple
 */
// ###########################################################

// Class types can also contain nested typedefs or type aliases:
class Employee {
public:
  using IDType = int;

private:
  std::string m_name{};
  IDType m_id{};
  double m_wage{};

public:
  Employee(std::string_view name, IDType id, double wage)
      : m_name{name}, m_id{id}, m_wage{wage} {}

  const std::string &getName() { return m_name; }
  IDType getId() { return m_id; } // can use unqualified name within class
};

int main() {
  Employee john{"John", 1, 45000};
  Employee::IDType id{
      john.getId()}; // must use fully qualified name outside class

  std::cout << john.getName() << " has id: " << id << '\n';

  return 0;
}
