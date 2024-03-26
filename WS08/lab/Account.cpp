/***********************************************************************
// Workshop # 8, Virtual Functions and Abstract Base Classes
//
// File: Account.cpp
// Version 1.0
// Date: 26/3/2024
// Author: Thanatorn Wongthanaporn
// Description
// This file implements the Account class
// -----------------------------------------------------------
// Name            Date            Reason
//
***********************************************************************/
#include "Account.h"
namespace seneca {
  Account::Account(double balance) {
    m_balance = balance;
  }
  bool Account::credit(double amount) {
    return amount >= 0 ? (m_balance += amount) || 1 : 0;
  }
  bool Account::debit (double amount) {
    return amount >= 0 ? (m_balance -= amount) || 1 : 0;
  }
  double Account::balance() const {
    return m_balance;
  }
}
