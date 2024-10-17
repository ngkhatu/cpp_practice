// Learncpp.com: section 9.5- std::cin and handling invalid input

// Simplified view of how operator>> works for input:

/*
1) First, leading whitespace (spaces, tabs, and newlines at the front of the
buffer) is discarded from the input buffer. This will discard any unextracted
newline character remaining from a prior line of input.
2) If the input buffer is now empty, operator>> will wait for the user to enter
more data. Leading whitespace is again discarded.
3) operator>> then extracts as many consecutive characters as it can, until it
encounters either a newline character (representing the end of the line of
input) or a character that is not valid for the variable being extracted to. The
result of the extraction is as follows:

* If any characters were extracted in step 3 above, extraction is a success. The
extracted characters are converted into a value that is then assigned to the
variable.
* If no characters could be extracted in step 3 above, extraction has
failed. The object being extracted to is assigned the value 0 (as of C++11), and
any future extractions will immediately fail (until std::cin is cleared).
*/

// ----------------------------
// process of checking whether user input conforms to what the program is
// expecting is called input validation. 3 Basic Ways:
/*
Inline (as the user types):
---------------------------
* Prevent the user from typing invalid input in the first place.

Post-entry (after the user types):
---------------------------------
* Let the user enter whatever they want into a string, then validate whether the
string is correct, and if so, convert the string to the final variable format.
* Let the user enter whatever they want, let std::cin and operator>> try to
extract it, and handle the error cases.
*/

/*
We can generally separate input text errors into four types:
-----------------------
* Input extraction succeeds but the input is meaningless to the program (e.g.
entering ‘k’ as your mathematical operator).
- The solution here is simple: do input validation. This usually consists of 3
steps:

- Check whether the user’s input was what you were expecting.
  > If so, return the value to the caller.
  > If not, tell the user something went wrong and have them try again.

* Input extraction succeeds but the user enters additional input (e.g. entering
‘*q hello’ as your mathematical operator).
* Input extraction fails (e.g. trying to enter ‘q’ into a numeric input).
* Input extraction succeeds but the user overflows a numeric value.
*/

// ###################################
// Error case 2: Extraction succeeds but with extraneous input

/* // Ignore characters
std::cin.ignore(100, '\n'); // clear up to 100 characters out of the buffer, or
                            // until a '\n' character is removed

// To ignore everything up to and including the next ‘\n’ character, we call
std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

#include <limits> // for std::numeric_limits

void ignoreLine() {
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

double getDouble() {
  std::cout << "Enter a decimal number: ";
  double x{};
  std::cin >> x;

  ignoreLine();
  return x;
}
 */
// ###############################################
/* // Error case 3: Extraction fails

// In order to get std::cin working property again, we typically need do three
// things:

// * Detect that a prior extraction has failed.
// * Put std::cin back in normal operation mode.
// * Remove the input that caused the failure (so the next extraction request
// doesn’t fail in an identical manner).

if (std::cin.fail()) // If the previous extraction failed
{
  // Let's handle the failure
  std::cin.clear(); // Put us back in 'normal' operation mode
  ignoreLine();     // And remove the bad input
}
// Because std::cin has a Boolean conversion indicating whether the last input
// succeeded, it’s more idiomatic to write the above as following:
if (!std::cin) // If the previous extraction failed
{
  // Let's handle the failure
  std::cin.clear(); // Put us back in 'normal' operation mode
  ignoreLine();     // And remove the bad input
}

// Integrated into getDouble function
double getDouble() {
  while (true) // Loop until user enters a valid input
  {
    std::cout << "Enter a decimal number: ";
    double x{};
    std::cin >> x;

    if (!std::cin) // If the previous extraction failed
    {
      // Let's handle the failure
      std::cin.clear(); // Put us back in 'normal' operation mode
      ignoreLine();     // And remove the bad input
      continue;
    }

    // Our extraction succeeded
    ignoreLine(); // Ignore any additional input on this line
    return x;     // Return the value we extracted
  }
}

// It is fine to call clear() even when extraction hasn’t failed -- it won’t do
// anything. In cases where we are going to call ignoreLine() regardless of
// whether we succeeded or failed, we can essentially combine the two cases:
double getDouble() {
  while (true) // Loop until user enters a valid input
  {
    std::cout << "Enter a decimal number: ";
    double x{};
    std::cin >> x;

    bool success{std::cin}; // Remember whether we had a successful extraction
    std::cin
        .clear(); // Put us back in 'normal' operation mode (in case we failed)
    ignoreLine(); // Ignore any additional input on this line (regardless)

    if (success) // If we actually extracted a value
      return x;  // Return it (otherwise, we go back to top of loop)
  }
}
 */

// #########################################
/* //  Checking for EOF

// It is fine to call clear() even when extraction hasn’t failed -- it won’t do
// anything. In cases where we are going to call ignoreLine() regardless of
// whether we succeeded or failed, we can essentially combine the two cases:
#include <limits> // for std::numeric_limits

void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// returns true if extraction failed, false otherwise
bool clearFailedExtraction()
{
    // Check for failed extraction
    if (!std::cin) // If the previous extraction failed
    {
        if (std::cin.eof()) // If the user entered an EOF
        {
            std::exit(0); // Shut down the program now
        }

        // Let's handle the failure
        std::cin.clear(); // Put us back in 'normal' operation mode
        ignoreLine();     // And remove the bad input

        return true;
    }

    return false;
}

 */

// ###############################################
/* // Error case 4: Extraction succeeds but the user overflows a numeric value
#include <cstdint>
#include <iostream>

int main()
{
    std::int16_t x{}; // x is 16 bits, holds from -32768 to 32767
    std::cout << "Enter a number between -32768 and 32767: ";
    std::cin >> x;

    std::int16_t y{}; // y is 16 bits, holds from -32768 to 32767
    std::cout << "Enter another number between -32768 and 32767: ";
    std::cin >> y;

    std::cout << "The sum is: " << x + y << '\n';
    return 0;
} */
/*
What happens if the user enters a number that is too large (e.g. 40000)?
In the above case, std::cin goes immediately into “failure mode”, but also
assigns the closest in-range value to the variable. When the entered value is
larger than the largest possible value for the type, the closest in-range value
is the largest possible value for the type. Consequently, x is left with the
assigned value of 32767. Additional inputs are skipped, leaving y with the
initialized value of 0. We can handle this kind of error in the same way as a
failed extraction.*/
// #####################################

// Putting it all together
#include <cstdlib> // for std::exit
#include <iostream>
#include <limits> // for std::numeric_limits

void ignoreLine() {
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// returns true if extraction failed, false otherwise
bool clearFailedExtraction() {
  // Check for failed extraction
  if (!std::cin) // If the previous extraction failed
  {
    if (std::cin.eof()) // If the stream was closed
    {
      std::exit(0); // Shut down the program now
    }

    // Let's handle the failure
    std::cin.clear(); // Put us back in 'normal' operation mode
    ignoreLine();     // And remove the bad input

    return true;
  }

  return false;
}

double getDouble() {
  while (true) // Loop until user enters a valid input
  {
    std::cout << "Enter a decimal number: ";
    double x{};
    std::cin >> x;

    if (clearFailedExtraction()) {
      std::cout << "Oops, that input is invalid.  Please try again.\n";
      continue;
    }

    ignoreLine(); // Remove any extraneous input
    return x;     // Return the value we extracted
  }
}

char getOperator() {
  while (true) // Loop until user enters a valid input
  {
    std::cout << "Enter one of the following: +, -, *, or /: ";
    char operation{};
    std::cin >> operation;

    if (!clearFailedExtraction()) // we'll handle error messaging if extraction
                                  // failed below
      ignoreLine(); // remove any extraneous input (only if extraction succeded)

    // Check whether the user entered meaningful input
    switch (operation) {
    case '+':
    case '-':
    case '*':
    case '/':
      return operation; // Return the entered char to the caller
    default:            // Otherwise tell the user what went wrong
      std::cout << "Oops, that input is invalid.  Please try again.\n";
    }
  }
}

void printResult(double x, char operation, double y) {
  std::cout << x << ' ' << operation << ' ' << y << " is ";

  switch (operation) {
  case '+':
    std::cout << x + y << '\n';
    return;
  case '-':
    std::cout << x - y << '\n';
    return;
  case '*':
    std::cout << x * y << '\n';
    return;
  case '/':
    if (y == 0.0)
      break;

    std::cout << x / y << '\n';
    return;
  }

  std::cout << "???"; // Being robust means handling unexpected parameters as
                      // well, even though getOperator() guarantees operation is
                      // valid in this particular program
}

int main() {
  double x{getDouble()};
  char operation{getOperator()};
  double y{getDouble()};

  // Handle division by 0
  while (operation == '/' && y == 0.0) {
    std::cout << "The denominator cannot be zero.  Try again.\n";
    y = getDouble();
  }

  printResult(x, operation, y);

  return 0;
}
