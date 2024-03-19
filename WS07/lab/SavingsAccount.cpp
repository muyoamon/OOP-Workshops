// Name: Thanatorn Wongthanaporn
// Email: twongthanaporn@myseneca.ca 
// id: 161197223
// Date: 19/3/2024

// I have done all the coding by myself and only copied the code that my
// professor provided to complete my workshops and assignments.
#include "SavingsAccount.h"
#include "BankAccount.h"
namespace seneca  {
  void SavingsAccount::writeInterest(std::ostream& out) const {
    out.precision(3);
    out << m_interest;
    out << "%";
  }
  void SavingsAccount::applyInterest(Date& dt) {
    double balance = this->getBalance();
    double interest = balance * m_interest / 100;
    std::cout << "   ";
    writeCurrency(std::cout, balance);
    std::cout << " + ";
    writeCurrency(std::cout, interest);
    std::cout << interest << " (";
    writeInterest(std::cout);
    std::cout << ") = ";
    setBalance(interest+balance);
    writeCurrency(std::cout, interest + balance);
    std::cout << " | " << m_interestDate << " => " << dt;
    m_interestDate = dt;
  
  }

  std::ostream& SavingsAccount::write(std::ostream& out) const {
    this->BankAccount::write(out);
    out << " | ";
    writeInterest(out);
    out << " | " << m_interestDate;
    return out;
  }

  std::istream& SavingsAccount::read(std::istream& in) {
    this->BankAccount::read(in);
    std::cout << "Interest Date (year month day): ";
    in >> m_interestDate;
    std::cout << "Interest Rate: ";
    in >> m_interest;
    return in;
  }
  
  std::istream& operator>>(std::istream& in, SavingsAccount& acct) {
    return acct.read(in);
  }
  std::ostream& operator<<(std::ostream& out, const SavingsAccount& acct) {
    return acct.write(out);   
  }
}
