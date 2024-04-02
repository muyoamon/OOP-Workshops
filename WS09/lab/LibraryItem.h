// Name: Thanatorn Wongthanaporn
// Email: twongthanaporn@myseneca.ca 
// id: 161197223
// Date: 2/4/2024

// I have done all the coding by myself and only copied the code that my
// professor provided to complete my workshops and assignments.
#ifndef SENECA_LIBITEM_H
#define SENECA_LIBITEM_H
#include <iostream>
namespace seneca  {
  class LibraryItem {
    char* m_title;
    int m_year;
    public:
    LibraryItem();
    LibraryItem(const char* title, const int year);
    LibraryItem(LibraryItem& other);
    LibraryItem& operator=(LibraryItem& other);
    virtual ~LibraryItem();
    virtual std::ostream& display(std::ostream& ostr=std::cout) const;
  };
}

#endif // !SENECA_LIBITEM_H

