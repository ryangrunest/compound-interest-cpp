#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account
{
  public: 
    Account();
    void DisplayDataInput();
    void DisplayChartWithoutInvestments();
    void DisplayChartWithInvestments();
    int ValidateValues();
  private: 
    double initialInvestment;
    double monthlyDeposit;
    double annualInterest;
    int numYears;
};

#endif