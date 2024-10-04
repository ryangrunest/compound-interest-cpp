
#include <iostream>
#include <iomanip>
#include "account.h"
#include "helpers.h"

using namespace std;

Account::Account() { // initial constructor
  CLEAR_CONSOLE();

  std::cout << "Enter initial investment amount (Ex. 500): " << endl; // get initial investment
  std::cin >> initialInvestment;

  CLEAR_CONSOLE();

  std::cout << "Enter monthly deposit (Ex. 50): " << endl; // get monthly deposit
  std::cin >> monthlyDeposit;

  CLEAR_CONSOLE();

  std::cout << "Enter annual interest (Ex. 5.3): " << endl; // get annual interest
  std::cin >> annualInterest;
  
  CLEAR_CONSOLE();

  std::cout << "Enter number of years (Ex. 5): " << endl; // get number of years of investments
  std::cin >> numYears;
  
  CLEAR_CONSOLE();
};

void Account::DisplayDataInput() {
  CLEAR_CONSOLE();

  std::cout << "********************************************************" << endl;
  std::cout << "********************* Data Input ***********************" << endl;
  std::cout << endl;

  std::cout << "Initial Investment Amount: $";
  FIXED_FLOAT(initialInvestment);
  std::cout << endl;
  std::cout << endl;

  std::cout << "Monthly Deposit: $";
  FIXED_FLOAT(monthlyDeposit);
  std::cout << endl;
  std::cout << endl;

  std::cout << "Annual Interest: ";
  FIXED_FLOAT(annualInterest);
  std::cout << "%" << endl;
  std::cout << endl;

  std::cout << "Number Of Years: " << numYears << endl;
  std::cout << endl;
  
  std::cout << "Press Enter / Return To Continue . . ." << endl;
}

void Account::DisplayChartWithoutInvestments() {
  int currentYear;
  int currentMonth;
  double currentValue = initialInvestment; // set currentValue as initial investment to start
  double monthlyInterest;
  double yearEndInterest;

  std::cout << "  Balance And Interest Without Additional Monthly Deposits  " << endl;
  std::cout << "============================================================" << endl;
  std::cout << "Year        Year End Balance        Year End Earned Interest" << endl;
  std::cout << "------------------------------------------------------------" << endl;

  for (currentYear = 1; currentYear <= numYears; currentYear++) { // for each year in num years
    monthlyInterest = 0.00; // reset interest
    yearEndInterest = 0.00;

    for (currentMonth = 1; currentMonth <= 12; currentMonth++) { // for each month
      monthlyInterest = currentValue * ((annualInterest / 100) / 12); // calculate interest for the month
      currentValue += monthlyInterest; // calculate value for the year
      yearEndInterest += monthlyInterest;
    }

    std::cout // display data
      << currentYear << "           " 
      << currentValue << "                     " 
      << yearEndInterest
      << endl;
  }

  std::cout << "============================================================" << endl;
};

void Account::DisplayChartWithInvestments() {
  int currentYear;
  int currentMonth;
  double currentValue = initialInvestment; // set currentValue as initial investment to start
  double monthlyInterest;
  double yearEndInterest;
  
  std::cout << "    Balance And Interest With Additional Monthly Deposits   " << endl;
  std::cout << "============================================================" << endl;
  std::cout << "Year        Year End Balance        Year End Earned Interest" << endl;
  std::cout << "------------------------------------------------------------" << endl;
  std::cout << "============================================================" << endl;

  for (currentYear = 1; currentYear <= numYears; currentYear++) { // do same calculations for each year as above
    yearEndInterest = 0.00;
    monthlyInterest = 0.00;

    for (currentMonth = 1; currentMonth <= 12; currentMonth++) {
      monthlyInterest = (currentValue + monthlyDeposit) * ((annualInterest / 100) / 12);
      currentValue += monthlyInterest;
      yearEndInterest += monthlyInterest;
      currentValue += monthlyDeposit; // except this time, add monthly deposit.
    }

    std::cout // display data
      << currentYear << "           " 
      << currentValue << "                     " 
      << yearEndInterest
      << endl;
  }
};

int Account::ValidateValues() {
  // initial investment should be less than 100k and not negative
  if (initialInvestment > 100000.00 || initialInvestment <= 0.001) {
    std::cout << "Initial investment is too low or high. Try again." << endl;
    return 1;
  }

  // same with monthly deposits
  if (monthlyDeposit > 100000.00 || monthlyDeposit <= 0.001) {
    std::cout << "Monthly deposit is too low or high. Try again." << endl;
    return 1;
  }

  // annual interest should be less than 50%, and non negative.
  if (annualInterest > 50.00 || annualInterest <= 0.001) {
    std::cout << "Annual interest is too low or high. Try again." << endl;
    return 1;
  }

  // number of years should be less than 100, and non negative.
  if (numYears > 100 || numYears <= 1) {
    std::cout << "Number of years is too low or high. Try again." << endl;
    return 1;
  }

  return 0;
}
