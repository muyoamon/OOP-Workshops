// Name: Thanatorn Wongthanaporn
// email: twongthanaporn@myseneca.ca
// id: 161197223
// Date: 1/1/2024
//
//I have done all the coding by myself and only copied the code 
//that my professor provided to complete my workshops and assignments.
#include "Customer.h"
#include <cstring>
#include <cstdio>
namespace seneca {

bool Customer::isEmpty() const {
  bool empty = true;
  empty = m_name == nullptr || !strcmp(m_name, "");
  empty = empty || m_car == nullptr;
  return empty;
}
void Customer::setEmpty() {
  m_id = 0;
  m_car = nullptr;
  m_name = nullptr;
}
void Customer::deallocateMemory() {
  delete[] m_name;
}
void Customer::set(int customerId, const char *name, const Car *car) {
  bool invalid = false;
  this->deallocateMemory();
  this->setEmpty();
  
  invalid = name == nullptr || !strcmp(name, "");
  invalid = invalid || car == nullptr;

  if (!invalid) {
    m_id = customerId;
    m_car = (Car*) car;
    m_name = new char[strlen(name) + 1];
    strcpy(m_name,name);
  }
}
void Customer::display() const {
  if (!this->isEmpty()) {
    printf("%15s%-20d\n", "Customer ID: ", m_id);
    printf("%15s%-20s\n", "First Name: ", m_name);
    m_car->display();
  }
}
const Car& Customer::car() const {
  return *m_car;
}
} // namespace seneca
