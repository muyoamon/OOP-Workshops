// Name: Thanatorn Wongthanaporn
// Email: twongthanaporn@myseneca.ca 
// id: 161197223
// Date: 19/3/2024

// I have done all the coding by myself and only copied the code that my
// professor provided to complete my workshops and assignments.
#ifndef SENECA_SAVINGSACCT_H
#define SENECA_SAVINGSACCT_H
#include "BankAccount.h"
#include "DepositUtility.h"
namespace seneca  {
  class SavingsAccount : BankAccount {
    double m_interest;
    Date m_interestDate;
    void writeInterest(std::ostream& out) const;

    public:
    SavingsAccount(const char* name, Date openDate, DepositInfo depinfo, double balance, double interest, Date interestDate): BankAccount(name, openDate, depinfo, balance), m_interest(interest), m_interestDate(interestDate) {}
    void applyInterest(Date& dt);
    std::ostream& write(std::ostream& out) const ;
    std::istream& read(std::istream& in);

  };

  std::istream& operator>>(std::istream& in, SavingsAccount& acct);
  std::ostream& operator<<(std::ostream& out, const SavingsAccount& acct);
}

#endif // !SENECA_SAVINGSACCT_H

