/***********************************************************************
// Workshop # 8, Virtual Functions and Abstract Base Classes
//
// File: ChequingAccount.cpp
// Version 1.0
// Date: 26/3/2024
// Author: Thanatorn Wongthanaporn
// Description
// This file implements the ChequingAccount class
// -----------------------------------------------------------
// Name            Date            Reason
//
***********************************************************************/
#include "ChequingAccount.h"
#include "Account.h"
#include <ostream>
namespace seneca {
  ChequingAccount::ChequingAccount(double balance, double transFee, double monthlyFee) : Account(balance) {
    m_tnsFee = transFee;
    m_mnthFee = monthlyFee;
  }
  bool ChequingAccount::credit(double amount) {
    return Account::credit(amount) && Account::debit(m_tnsFee);
  }
  bool ChequingAccount::debit(double amount) {
    return Account::debit(amount) && Account::debit(m_tnsFee);
  }
  void ChequingAccount::monthEnd() {
    Account::debit(m_mnthFee);
  }
  void ChequingAccount::display(std::ostream& ostr) const {
    ostr.setf(std::ios_base::fixed);
    ostr << "Account type: Chequing" << std::endl;
    ostr << "Balance: $";
    ostr.precision(2);
    ostr << balance() << std::endl;
    ostr << "Per Transaction Fee: ";
    ostr.precision(2);
    ostr << m_tnsFee << std::endl;
    ostr << "Monthly Fee: ";
    ostr.precision(2);
    ostr << m_mnthFee << std::endl;
    ostr.unsetf(std::ios_base::fixed);
  }
}
