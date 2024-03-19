// Name: Thanatorn Wongthanaporn
// Email: twongthanaporn@myseneca.ca 
// id: 161197223
// Date: 19/3/2024

// I have done all the coding by myself and only copied the code that my
// professor provided to complete my workshops and assignments.
#include "BankAccount.h"
#include <string.h>
namespace seneca  {
 double BankAccount::getBalance() const {
  return m_balance;
 }
 void BankAccount::setBalance(double balance) {
   m_balance = balance;
 }
 void BankAccount::writeCurrency(std::ostream& out, double amount) const {
   out << "$";
   out.precision(2);
   out << amount;
 }

 BankAccount::BankAccount(const char* name, Date openDate, DepositInfo depInfo, double balance) {
   strncpy(m_name, name, ACCOUNT_NAME_LEN);
   m_opendate = openDate;
   m_depinfo = depInfo;
   m_balance = balance;
 }

 std::ostream& BankAccount::write(std::ostream& out) const {
   out << m_name << " | ";
   writeCurrency(out, m_balance);
   out << " | ";
   out << m_opendate << " | ";
   out << m_depinfo;
   return out;
 }

 std::istream& BankAccount::read(std::istream& in) {
   char buffer[1000];
   std::cout << "Name: ";
   in >> buffer;
   strncpy(m_name, buffer, 50);
   std::cout << "Opening Balance: ";
   in >> m_balance;
   std::cout << "Date Opened (year month day): ";
   in >> m_opendate;
   in >> m_depinfo;
   return in;
 }

 std::istream& operator>>(std::istream& in, BankAccount& acct) {
   return acct.read(in);
 }

 std::ostream& operator<<(std::ostream& out, const BankAccount& acct) {
   return acct.write(out);
 }
}
