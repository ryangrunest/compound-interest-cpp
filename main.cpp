/*
  Ryan Grunest
  10/4/2024
*/

#include <iostream>

using namespace std;

void ClearConsole() {
  std::cout << "\x1B[2J\x1B[H";
}

class Account {
  double initialInvestment;
  double monthlyDeposit;
  double annualInterest;
  int numYears;

  public:
    Account() {
      ClearConsole();

      std::cout << "Enter initial investment amount (Ex. 500): " << endl;
      std::cin >> initialInvestment;

      ClearConsole();

      std::cout << "Enter monthly deposit (Ex. 50): " << endl;
      std::cin >> monthlyDeposit;

      ClearConsole();

      std::cout << "Enter annual interest (Ex. 5.3): " << endl;
      std::cin >> annualInterest;
      
      ClearConsole();

      std::cout << "Enter number of years (Ex. 5): " << endl;
      std::cin >> numYears;
    };

    void DisplayDataInput() {
      ClearConsole();

      std::cout << "****************************" << endl;
      std::cout << "******* Data Input *********" << endl;
      std::cout << "Initial Investment Amount: " << initialInvestment << endl;
      std::cout << "Monthly Deposit: " << monthlyDeposit << endl;
      std::cout << "Annual Interest: " << annualInterest << endl;
      std::cout << "Number Of Years: " << numYears << endl;
      std::cout << "Press Any Key To Continue . . ." << endl;
    };

    void DisplayChartWithoutInvestments() {
      int currentYear;
      int currentMonth;
      double currentValue = initialInvestment;
      double yearEndInterest;

      std::cout << "  Balance And Interest Without Additional Monthly Deposits  " << endl;
      std::cout << "============================================================" << endl;
      std::cout << "Year        Year End Balance        Year End Earned Interest" << endl;
      std::cout << "------------------------------------------------------------" << endl;

      for (currentYear = 1; currentYear <= numYears; currentYear++) {
        yearEndInterest = 0.00;

        for (currentMonth = 1; currentMonth <= 12; currentMonth++) {
          yearEndInterest = currentValue * ((annualInterest / 100) / 12);
          currentValue += yearEndInterest;
        }

        std::cout 
          << currentYear << "           " 
          << currentValue << "                     " 
          << yearEndInterest
          << endl;
      }

      std::cout << "============================================================" << endl;
    };

    void DisplayChartWithInvestments() {
      int currentYear;
      int currentMonth;
      double currentValue = initialInvestment;
      double yearEndInterest;
      
      std::cout << "    Balance And Interest With Additional Monthly Deposits   " << endl;
      std::cout << "============================================================" << endl;
      std::cout << "Year        Year End Balance        Year End Earned Interest" << endl;
      std::cout << "------------------------------------------------------------" << endl;
      std::cout << "============================================================" << endl;

      for (currentYear = 1; currentYear <= numYears; currentYear++) {
        yearEndInterest = 0.00;

        for (currentMonth = 1; currentMonth <= 12; currentMonth++) {
          yearEndInterest = (currentValue + monthlyDeposit) * ((annualInterest / 100) / 12);
          currentValue += yearEndInterest;
          currentValue += monthlyDeposit;
        }

        std::cout 
          << currentYear << "           " 
          << currentValue << "                     " 
          << yearEndInterest
          << endl;
      }
    }
};

int main() {
  Account account; 

  account.DisplayDataInput();

  ClearConsole();

  account.DisplayChartWithoutInvestments();
  account.DisplayChartWithInvestments();

  return 0;
}