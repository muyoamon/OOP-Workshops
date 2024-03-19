// Name: Thanatorn Wongthanaporn
// Email: twongthanaporn@myseneca.ca 
// id: 161197223
// Date: 19/3/2024

// I have done all the coding by myself and only copied the code that my
// professor provided to complete my workshops and assignments.
#ifndef SENECA_BANKACCOUNT_H
#define SENECA_BANKACCOUNT_H

#include "DepositUtility.h"
#include <iostream>

#define ACCOUNT_NAME_LEN 50

namespace seneca {
  class BankAccount {
    char m_name[ACCOUNT_NAME_LEN + 1];
    Date m_opendate;
    DepositInfo m_depinfo;
    double m_balance;
    protected:
    double getBalance() const;
    void setBalance(double balance);
    void writeCurrency(std::ostream& out, double amount) const;
    public:
    BankAccount(const char* name, Date openDate, DepositInfo depInfo, double balance);
    std::ostream& write(std::ostream& out) const;
    std::istream& read(std::istream& in);
  };
  std::istream& operator>>(std::istream& in, BankAccount& acct);
  std::ostream& operator<<(std::ostream& out, const BankAccount& acct);
}

#endif // !SENECA_BANKACCOUNT_H

