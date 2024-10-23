// Learncpp.com: Section 15.8- Friend non-member functions

/* #include <iostream>

class Value {
private:
  int m_value{};

public:
  explicit Value(int v) : m_value{v} {}

  bool isEqualToMember(const Value &v) const;
  friend bool isEqualToNonmember(const Value &v1, const Value &v2);
};

bool Value::isEqualToMember(const Value &v) const {
  return m_value == v.m_value;
}

bool isEqualToNonmember(const Value &v1, const Value &v2) {
  return v1.m_value == v2.m_value;
}

int main() {
  Value v1{5};
  Value v2{6};

  std::cout << v1.isEqualToMember(v2) << '\n';
  std::cout << isEqualToNonmember(v1, v2) << '\n';

  return 0;
}
 */

// ##############################################

/* #include <iostream>

class Humidity; // forward declaration of Humidity

class Temperature {
private:
  int m_temp{0};

public:
  explicit Temperature(int temp) : m_temp{temp} {}

  friend void printWeather(
      const Temperature &temperature,
      const Humidity &humidity); // forward declaration needed for this line
};

class Humidity {
private:
  int m_humidity{0};

public:
  explicit Humidity(int humidity) : m_humidity{humidity} {}

  friend void printWeather(const Temperature &temperature,
                           const Humidity &humidity);
};

void printWeather(const Temperature &temperature, const Humidity &humidity) {
  std::cout << "The temperature is " << temperature.m_temp
            << " and the humidity is " << humidity.m_humidity << '\n';
}

int main() {
  Humidity hum{10};
  Temperature temp{12};

  printWeather(temp, hum);

  return 0;
}
 */
// #############################################################
/*
#include <iostream>

class Accumulator {
private:
  int m_value{0}; // if we rename this

public:
  void add(int value) { m_value += value; } // we need to modify this

  friend void print(const Accumulator &accumulator);
};

void print(const Accumulator &accumulator) {
  std::cout << accumulator.m_value; // and we need to modify this
}

int main() {
  Accumulator acc{};
  acc.add(5); // add 5 to the accumulator

  print(acc); // call the print() non-member function

  return 0;
} */
// ---------------------------------------------------------
#include <iostream>

class Accumulator {
private:
  int m_value{0};

public:
  void add(int value) { m_value += value; }
  int value() const { return m_value; } // added this reasonable access function
};

void print(const Accumulator &accumulator) // no longer a friend of Accumulator
{
  std::cout
      << accumulator.value(); // use access function instead of direct access
}

int main() {
  Accumulator acc{};
  acc.add(5); // add 5 to the accumulator

  print(acc); // call the print() non-member function

  return 0;
}
