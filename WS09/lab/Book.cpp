#include "Book.h"
#include "LibraryItem.h"
#include <cstring>
#include <ostream>
namespace seneca {
  Book::Book(const char* title, const int year, const char* author) : LibraryItem(title,year) {
    m_author = new char[strlen(author) + 1];
    strncpy(m_author,author,strlen(author) + 1);
  }
  Book::Book(Book& other) : LibraryItem() {
    m_author = nullptr;
    *this = other;
  }
  Book& Book::operator=(Book& other) {
    LibraryItem::operator=(other);
    m_author = new char[strlen(other.m_author) + 1];
    strncpy(m_author,other.m_author,strlen(other.m_author) + 1);
    return *this;
  }
  Book::~Book() {
    delete[] m_author;
  }
  std::ostream& Book::display(std::ostream& ostr) const {
    LibraryItem::display(ostr);
    ostr << std::endl;
    ostr << "Author: ";
    ostr << m_author;
    return ostr;
  }
  bool Book::operator>(const Book& other) const {
    return strcmp(this->m_author, other.m_author) > 0;
  }
}
