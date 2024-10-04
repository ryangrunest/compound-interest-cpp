#include <iostream>
#include <iomanip>

// clear the console
void CLEAR_CONSOLE() {
  std::cout << "\x1B[2J\x1B[H";
}

// display doubles with 2 decimals
void FIXED_FLOAT(double x) {
  std::cout << std::fixed << std::setprecision(2) << x;
}