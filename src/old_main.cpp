#include <iostream>
#include <string>

const double PI = 3.14159;
const int LIGHT_SPEED = 299792458;
const int WIDTH = 1920;
const int HEIGHT = 1080;

namespace first {
int x = 1;
}

namespace second {
int x = 2;
}

void doSomethinghere() {
  // doing something here
  std::cout << "Doing something here!" << std::endl;
} // namespace secondvoid doSomethinghere()

double calcCircumference(double radius = 0.0) {
  double circumference = PI * 2 * radius;

  return circumference;
}

void trynewNamespace() {
  using namespace second;
  std::cout << "x=" << x << std::endl;
}

void saveTime() {
  using namespace std;

  string testing = "Something New";

  cout << "Testing " << testing << endl;

  return;
}

void safesaveTime() {
  using std::cout;
  using std::endl;
  using std::string;

  string testing = "Something New";

  cout << "Testing " << testing << endl;

  return;
}

void tryTypeDef() {
  typedef std::string text_t;

  text_t myname = "Nikhil";

  std::cout << "My name is " << myname << std::endl;

  return;
}

void tryUsingKeyword() {

  using text_t = std::string;
  using number_t = int;
  auto x = 5;
  text_t myname = "Nikhil";
  number_t age = 101;

  std::cout << "My name and age is " << myname << age << std::endl;

  return;
}

void askNameAge() {

  std::string name;
  int age;

  std::cout << "What's your name?: ";
  std::cin >> name;

  std::cout << "What's your age?: ";
  std::cin >> age;

  std::cout << "Hello " << name << "\n";
  std::cout << "You are " << age << " years old";
}

int main(int, char **) {
  std::cout << "Hello, etf now oureo from hworld!\n";
  std::cout << "Here again" << std::endl;
  // int and doubles
  double gpa = 5.5;
  int mult = 5;

  // boolean values
  bool isit = false;

  // if and else statements
  if (isit == true) {
    std::cout << gpa * mult << std::endl;
  } else if (isit == false) {
    std::cout << "Failed!" << std::endl;
  }

  // chars and strings
  char dolls = '$';
  std::string name = "Nikhil";

  std::cout << dolls << " something else here " << name << std::endl;

  doSomethinghere();

  std::cout << "circ calc: " << calcCircumference(10.0) << std::endl;

  int x = 0;

  std::cout << "x=" << x << std::endl;
  std::cout << "x=" << first::x << std::endl;
  std::cout << "x=" << second::x << std::endl;

  trynewNamespace();

  saveTime();
  safesaveTime();
  tryTypeDef();
  tryUsingKeyword();

  return 0;
}
