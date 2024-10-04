/*
  Ryan Grunest
  10/4/2024
*/

#include <iostream>
#include <iomanip>

using namespace std;

// clear the console
void CLEAR_CONSOLE() {
  std::cout << "\x1B[2J\x1B[H";
}

// display doubles with 2 decimals
void FIXED_FLOAT(double x) {
  cout << std::fixed << std::setprecision(2) << x;
}

class Account {
  double initialInvestment;
  double monthlyDeposit;
  double annualInterest;
  int numYears;

  public:
    Account() { // initial constructor
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

    void DisplayDataInput() { // display initial data
      CLEAR_CONSOLE();

      std::cout << "********************************************************" << endl;
      std::cout << "********************* Data Input ***********************" << endl;
      std::cout << endl;

      std::cout << "Initial Investment Amount: $";
      FIXED_FLOAT(initialInvestment);
      cout << endl;
      cout << endl;

      std::cout << "Monthly Deposit: $";
      FIXED_FLOAT(monthlyDeposit);
      cout << endl;
      cout << endl;

      std::cout << "Annual Interest: ";
      FIXED_FLOAT(annualInterest);
      cout << "%" << endl;
      cout << endl;

      std::cout << "Number Of Years: " << numYears << endl;
      cout << endl;
      
      std::cout << "Press Enter / Return To Continue . . ." << endl;
    };

    void DisplayChartWithoutInvestments() { // display chart without monthly investments
      int currentYear;
      int currentMonth;
      double currentValue = initialInvestment; // set currentValue as initial investment to start
      double yearEndInterest;

      std::cout << "  Balance And Interest Without Additional Monthly Deposits  " << endl;
      std::cout << "============================================================" << endl;
      std::cout << "Year        Year End Balance        Year End Earned Interest" << endl;
      std::cout << "------------------------------------------------------------" << endl;

      for (currentYear = 1; currentYear <= numYears; currentYear++) { // for each year in num years
        yearEndInterest = 0.00; // reset interest

        for (currentMonth = 1; currentMonth <= 12; currentMonth++) { // for each month
          yearEndInterest = currentValue * ((annualInterest / 100) / 12); // calculate interest for the month
          currentValue += yearEndInterest; // calculate value for the year
        }

        std::cout // display data
          << currentYear << "           " 
          << currentValue << "                     " 
          << yearEndInterest
          << endl;
      }

      std::cout << "============================================================" << endl;
    };

    void DisplayChartWithInvestments() { // display chart with monthly investments
      int currentYear;
      int currentMonth;
      double currentValue = initialInvestment; // set currentValue as initial investment to start
      double yearEndInterest;
      
      std::cout << "    Balance And Interest With Additional Monthly Deposits   " << endl;
      std::cout << "============================================================" << endl;
      std::cout << "Year        Year End Balance        Year End Earned Interest" << endl;
      std::cout << "------------------------------------------------------------" << endl;
      std::cout << "============================================================" << endl;

      for (currentYear = 1; currentYear <= numYears; currentYear++) { // do same calculations for each year as above
        yearEndInterest = 0.00;

        for (currentMonth = 1; currentMonth <= 12; currentMonth++) {
          yearEndInterest = (currentValue + monthlyDeposit) * ((annualInterest / 100) / 12);
          currentValue += yearEndInterest;
          currentValue += monthlyDeposit; // except this time, add monthly deposit.
        }

        std::cout // display data
          << currentYear << "           " 
          << currentValue << "                     " 
          << yearEndInterest
          << endl;
      }
    };

    int ValidateValues() { // validate values
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
};

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