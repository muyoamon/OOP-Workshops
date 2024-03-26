/***********************************************************************
// Workshop # 8, Virtual Functions and Abstract Base Classes
//
// File: SavingsAccount.cpp
// Version 1.0
// Date: 26/3/2024
// Author: Thanatorn Wongthanaporn
// Description
// This file implements the SavingsAccount class
// -----------------------------------------------------------
// Name            Date            Reason
//
***********************************************************************/
#include "SavingsAccount.h"
#include <ostream>
namespace seneca {
  SavingsAccount::SavingsAccount(double balance, double interest) : Account(balance) {
    m_interestRate = interest;
  }
  void SavingsAccount::monthEnd() {
    credit(balance() * m_interestRate);
  }
  void SavingsAccount::display(std::ostream& ostr) const {
    ostr.setf(std::ios_base::fixed);
    ostr << "Account type: Savings" << std::endl;
    ostr << "Balance: $";
    ostr.precision(2);
    ostr << balance() << std::endl;
    ostr << "Interest Rate (%): ";
    ostr.precision(2);
    ostr << m_interestRate * 100 << std::endl;
    ostr.unsetf(std::ios_base::fixed);
  }
}
