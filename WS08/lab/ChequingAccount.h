/***********************************************************************
// Workshop # 8, Virtual Functions and Abstract Base Classes
//
// File: ChequingAccount.h
// Version 1.0
// Date: 26/3/2024
// Author: Thanatorn Wongthanaporn
// Description
// This file defines the Account class
// -----------------------------------------------------------
// Name            Date            Reason
//
***********************************************************************/
#ifndef SENECA_CHEQUEACCT_H
#define SENECA_CHEQUEACCT_H
#include <ostream>
#include "Account.h"
namespace seneca  {
  class ChequingAccount: public Account {
    double m_tnsFee;
    double m_mnthFee;
    public:
    ChequingAccount(double,double,double);
    bool credit(double) override;
    bool debit(double) override;
    void monthEnd() override;
    void display(std::ostream&) const override;
  };
}

#endif // !SENECA_CHEQUEACCT_H

