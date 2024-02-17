/***********************************************************************
// OOP244 Workshop #5 Lab (part 1)
//
// File  bankaccount.h
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
#pragma once
#ifndef SENECA_BANKACCOUNT_H_
#define SENECA_BANKACCOUNT_H_

namespace seneca {
const int ACCT_MAXLEN_USER = 16; // Max Length of user name
const double CHECK_TRS_FEE = 1.25;
const double CHECK_INTEREST = .5; // in percentage
const double SAVING_TRS_FEE = 3.5;
const double SAVING_INTEREST = 2.5; // in percentage
// Class Definition
class bankAccount {

private:
  // Data Members
  char m_userName[ACCT_MAXLEN_USER];
  double m_funds;
  bool m_checking;
  int m_monthlyTransactions;

  bool isOpen() const;

public:
  bankAccount(const char *name = nullptr, bool checking = false);
  bool setup(const char *name, bool checking);

  operator bool() const;
  operator double() const;

  bankAccount &operator++();
  bankAccount &operator--();

  bool operator+=(double);
  bool operator-=(double);

  bool operator==(const bankAccount &) const;
  bool operator>(double) const;
  bool operator<=(double) const;

  bool operator<<(bankAccount &);

  void display(void) const;
};

bool operator>(double lhs, const bankAccount &rhs);
bool operator<=(double lhs, const bankAccount &rhs);

} // namespace seneca
#endif
