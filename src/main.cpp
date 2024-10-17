// Learncpp.com: section 9.4- Detecting and Handling Errors

// most errors occur due to faulty assumptions made by the programmer and/or a
// lack of proper error detection/handling.
/*
* When a function returns, the programmer may have assumed the called function
was successful when it was not.
* When a program receives input (either from the user, or a file), the
programmer may have assumed the input was in the correct format and semantically
valid when it was not.
* When a function has been called, the programmer may have assumed the arguments
would be semantically valid when they were not.
*/

// If the error is so bad that the program can not continue to operate properly,
// this is called a non-recoverable error (also called a fatal error). In such
// cases, the best thing to do is terminate the program. If your code is in
// main() or a function called directly from main(), the best thing to do is let
// main() return a non-zero status code. However, if you’re deep in some nested
// subfunction, it may not be convenient or possible to propagate the error all
// the way back to main(). In such a case, a halt statement (such as
// std::exit()) can be used.

#include <iostream>

double doIntDivision(int x, int y) {
  if (y == 0) {
    std::cout << "Error: Could not divide by zero\n";
    std::exit(1);
  }
  return x / y;
}

int main() {

  double result = doIntDivision(5, 0);

  std::cout << result << std::endl;
  return 0;
}
/*
* Use std::cout for all conventional, user-facing text.
* For an interactive program, use std::cout for normal user-facing error
messages (e.g. “Your input was invalid”). Use std::cerr or a logfile for status
and diagnostic information that may be helpful for diagnosing issues but
probably isn’t interesting for normal users. This can include technical warnings
and errors (e.g. bad input to function x), status updates (e.g. successfully
opened file x, failed to connect to internet service x), percentage completion
of long tasks (e.g. encoding 50% complete), etc…
* For a non-interactive program (tool or service), use std::cerr for error
output only (e.g. could not open file x). This allows errors to be displayed or
parsed separately from normal output.
* For any application type that is transactional in nature (e.g. one that
processes specific events, such as an interactive web browser or non-interactive
web server), use a logfile to produce a transactional log of events that can be
reviewed later. This can include outputting to the logfile which file is being
processed, updates on the percentage complete, timestamps of when it started
certain stages of computing, warning and error messages, etc…
*/
