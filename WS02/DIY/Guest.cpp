// Name: Thanatorn Wongthanaporn
// email: twongthanaporn@myseneca.ca
// id: 161197223
// Date: 24/1/2024
//
//I have done all the coding by myself and only copied the code 
//that my professor provided to complete my workshops and assignments.
#include "Guest.h"
#include <cstring>
#include <iostream>

namespace seneca {
  
  void set (Guest& guest, const char* first, const char* last, int age) 
  {
    int firstLen = 0, lastLen = 0;
    
    if (first == nullptr || last == nullptr) {
      return;
    }
    while (first[firstLen] != '\0') {
      firstLen++;
    }
    while (last[lastLen]) {
      lastLen++;
    }
    guest.m_firstName = new char[firstLen];
    strcpy(guest.m_firstName, first);
    guest.m_lastName = new char[lastLen];
    strcpy(guest.m_lastName, last);

    guest.m_adult = (age > 18) ? true : false; 

  }

  void print(const Guest& guest)
  {
    if (guest.m_firstName == nullptr || !strcmp(guest.m_firstName,"") ||
        guest.m_lastName == nullptr || !strcmp(guest.m_lastName,""))
    {
      std::cout << "Vacated!" << std::endl;
    }
    else 
    {
      std::cout << guest.m_firstName << " " << guest.m_lastName;
      if (!guest.m_adult)
      {
        std::cout << "(Child)";
      }
      std::cout<< std::endl;
    }
  }
  
  void book(Guest& guest)
  {
    char fname[50] = "";
    char lname[50] = "";
    int age;
    std::cout << "Name: ";
    std::cin >> fname;   
    std::cout << "Lastname: ";
    std::cin >> lname;
    std::cout << "Age: ";
    std::cin >> age;
    set(guest,fname,lname,age);
  }
  
  void vacate(Guest& guest)
  {
    if (guest.m_firstName != nullptr)
    {
      delete guest.m_firstName;
      guest.m_firstName = nullptr;
    }
    if (guest.m_lastName != nullptr)
    {
      delete guest.m_lastName;
      guest.m_lastName = nullptr;
    }
  }
}
