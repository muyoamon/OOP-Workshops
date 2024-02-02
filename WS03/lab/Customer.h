// Name: Thanatorn Wongthanaporn
// email: twongthanaporn@myseneca.ca
// id: 161197223
// Date: 1/1/2024
//
//I have done all the coding by myself and only copied the code 
//that my professor provided to complete my workshops and assignments.
#ifndef SENECA_CUSTOMER_H
#define SENECA_CUSTOMER_H

#include "Car.h"

namespace seneca {
  class Customer {
    int m_id;
    char* m_name;
    Car* m_car;
    public:
  /// check if object is in a safe empty state;
  /// \return true if empty
    bool isEmpty() const;
  /// set object to safe empty state
    void setEmpty();
  /// deallocate the allocated memory
    void deallocateMemory();
   /// set Customer object
   /// \param customerId customer ID
   /// \param name customer's name
   /// \param car car object
    void set(int customerId, const char* name, const Car* car);
  ///  display Customer object
    void display() const;
  /// return car object
  /// \return car object
    const Car& car() const;
  };
}

#endif // !SENECA_CUSTOMER_H
