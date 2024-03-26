/***********************************************************************
// Workshop # 8, Virtual Functions and Abstract Base Classes
//
// File: Account.h
// Version 1.0
// Date: 26/3/2024
// Author: Thanatorn Wongthanaporn
// Description
// This file defines the Account class
// -----------------------------------------------------------
// Name            Date            Reason
//
***********************************************************************/
#ifndef SENECA_ACCOUNT_H
#define SENECA_ACCOUNT_H
#include "iAccount.h"
namespace seneca {
  class Account: public iAccount {
    double m_balance;
    public:
      Account(double);
      bool credit(double) override;
      bool debit(double) override;
      virtual ~Account() {}
    protected:
      double balance() const;
  };
}

#endif // !SENECA_ACCOUNT_H

