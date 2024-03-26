/***********************************************************************
// Workshop # 8, Virtual Functions and Abstract Base Classes
//
// File: SavingAccount.h
// Version 1.0
// Date: 26/3/2024
// Author:  Thanatorn Wongthanaporn
// Description
// This file defines the SavingsAccount class
// -----------------------------------------------------------
// Name            Date            Reason
//
***********************************************************************/
#ifndef SENECA_SAVINGSACC_H
#define SENECA_SAVINGSACC_H
#include "Account.h"
#include <iostream>
namespace seneca {
  class SavingsAccount: public Account {
    double m_interestRate;
    public:
    SavingsAccount(double, double);
    ~SavingsAccount() {}
    void monthEnd() override;
    void display(std::ostream&) const override;
  };
}
#endif // !SENECA_SAVINGSACC_H

