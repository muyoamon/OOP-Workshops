// Name: Thanatorn Wongthanaporn
// Email: twongthanaporn@myseneca.ca 
// id: 161197223
// Date: 2/4/2024

// I have done all the coding by myself and only copied the code that my
// professor provided to complete my workshops and assignments.
#include "LibraryItem.h"
#include <cstring>
#include <ostream>
namespace seneca {
  LibraryItem::LibraryItem() {
    m_title = nullptr;
    m_year = 0;
  }
  LibraryItem::LibraryItem(const char* title, const int year) {
    m_title = new char[strlen(title) + 1];
    strncpy(m_title, title, strlen(title) + 1);
    m_year = year;
  }
  LibraryItem::LibraryItem(LibraryItem& other) : LibraryItem() {
   *this = other;
  }
  LibraryItem& LibraryItem::operator=(LibraryItem& other) {
    delete [] m_title;
    this->m_title = new char[strlen(other.m_title) + 1];
    strncpy(this->m_title, other.m_title, strlen(other.m_title)+1);
    this->m_year = other.m_year;
    return *this;
  }
  LibraryItem::~LibraryItem() {
    delete [] m_title;
  }
  std::ostream& LibraryItem::display(std::ostream& ostr) const {
    ostr << "Title: ";
    ostr << m_title;
    ostr << " (" << m_year << ")";
    return ostr;
  }
}
