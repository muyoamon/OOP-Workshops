/***********************************************************************
// OOP244 Workshop #5 Lab (part 1)
//
// File  bankaccount.cpp
// Version v0.8 Oct 21st 2023
// Author  Jitesh Arora
// Description
//
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
***********************************************************************/
// Name: Thanatorn Wongthanaporn
// Email: twongthanaporn@myseneca.ca 
// id: 161197223
// Date: 16/2/2024

// I have done all the coding by myself and only copied the code that my
// professor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS

#include "bankaccount.h"
#include <cstring>
#include <iostream>

using namespace std;

namespace seneca {
// Default Constructor with default arguments
bankAccount::bankAccount(const char *name, bool checking) {
  m_userName[0] = '\0'; // Empty string implies is account is not open
  setup(name, checking);
}

// Open bank account: setup can only be done once!
bool bankAccount::setup(const char *name, bool checking) {
  if (isOpen())
    return false;
  if (name == nullptr)
    return false;

  strcpy(m_userName, name);
  m_monthlyTransactions = 0;
  m_checking = checking;
  m_funds = 0;
  return true;
}

// Account is open if user name string is not empty
bool bankAccount::isOpen() const { return (m_userName[0] != '\0'); }

// ADD: Type Conversion, Unary & Binary Operators; + Additional Methods

bankAccount::operator bool() const { return this->isOpen(); }

bankAccount::operator double() const { return this->m_funds; }

bankAccount &bankAccount::operator++() {
  if (this->isOpen() && this->m_funds > 0.) {
    switch ((int)this->m_checking) {
    case 1:
      this->m_funds *= 1 + CHECK_INTEREST / 100;
      break;
    case 0:
      this->m_funds *= 1 + SAVING_INTEREST / 100;
      break;
    default:
      break;
    }
  }
  return *this;
}

bankAccount &bankAccount::operator--() {
  if (this->isOpen()) {
    switch ((int)this->m_checking) {
    case 1:
      this->m_funds -= CHECK_TRS_FEE * this->m_monthlyTransactions;
      break;
    case 0:
      this->m_funds -= SAVING_TRS_FEE * this->m_monthlyTransactions;
      break;
    default:
      break;
    }
  }
  return *this;
}

bool bankAccount::operator+=(double value) {
  bool success = false;
  if ((success = this->isOpen())) {
    this->m_funds += value;
    this->m_monthlyTransactions++;
    cout.precision(2);
    cout.setf(cout.fixed);
    cout << "Deposit $" << value << " for " << this->m_userName << endl;
    cout.unsetf(cout.fixed);
  }
  return success;
}

bool bankAccount::operator-=(double value) {
  bool success = this->isOpen();
  if (success) {
    this->m_funds -= value;
    this->m_monthlyTransactions++;
    cout.precision(2);
    cout.setf(cout.fixed);
    cout << "Withdraw $" << value << " for " << this->m_userName << endl;
    cout.unsetf(cout.fixed);
  }
  return success;
}

bool bankAccount::operator==(const bankAccount &rhs) const {
  return !strcmp(this->m_userName, rhs.m_userName) &&
         this->m_funds == rhs.m_funds && this->m_checking == rhs.m_checking;
}

bool bankAccount::operator>(double rhs) const { return this->m_funds > rhs; }

bool bankAccount::operator<=(double rhs) const {
  return !(this->m_funds > rhs);
}

bool bankAccount::operator<<(bankAccount &rhs) {
  bool success = false;
  double funds = 0.;
  if ((success = this->isOpen() && rhs.isOpen())) {
    funds = rhs;
    cout.precision(2);
    cout.setf(cout.fixed);
    cout << "Transfer $" << funds << " from " << rhs.m_userName << " to "
         << this->m_userName << endl;
    cout.unsetf(cout.fixed);
    *this += funds;
    rhs -= funds;
  }
  return success;
}

void bankAccount::display(void) const {
  char backupFill;
  cout << "Display Account -> User:";
  cout.width(ACCT_MAXLEN_USER);
  backupFill = cout.fill('-');
  if (this->isOpen()) {
    cout << this->m_userName << " | ";
    cout.fill(backupFill);
    cout.width(8);
    cout << (this->m_checking ? "Checking" : "Savings") << " | Balance: $";
    cout.width(8);
    cout.precision(2);
    cout.setf(cout.fixed);
    cout << this->m_funds << " | Transactions:";
    cout.unsetf(cout.fixed);
    cout.fill('0');
    cout.width(3);
    cout << this->m_monthlyTransactions << endl;
  } else {
    cout << " NOT OPEN" << endl;
  }
  cout.fill(backupFill);
}
// ADD: Global Helper Functions

bool operator>(double lhs, const bankAccount &rhs) { return rhs <= lhs; }
bool operator<=(double lhs, const bankAccount &rhs) { return rhs > lhs; }

} // namespace seneca
