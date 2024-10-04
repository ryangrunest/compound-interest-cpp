/*
  Ryan Grunest
  10/4/2024
*/

#include <iostream>
#include <iomanip>
#include "account.h"
#include "helpers.h"

using namespace std;

int main() {
  Account account; // init account

  if (account.ValidateValues() == 0) { // make sure inputs are valid
    account.DisplayDataInput(); // display input data

    std::cin.ignore(2); // wait for user to hit enter

    CLEAR_CONSOLE(); // clear console

    account.DisplayChartWithoutInvestments(); // display chart
    account.DisplayChartWithInvestments(); // display chart
    return 0; // return 0, all is well
  } else {
    return 1; // oh no, something went wrong
  }
}