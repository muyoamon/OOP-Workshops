#ifndef SENECA_BOOK_H
#define SENECA_BOOK_H
#include "LibraryItem.h"
namespace seneca  {
  class Book : public LibraryItem {
    char* m_author;
    public:
    Book(const char * title, const int year, const char* author);
    Book(Book& other);
    ~Book() override;
    Book& operator=(Book& other);
    std::ostream & display(std::ostream &ostr = std::cout) const override;
    bool operator >(const Book& other) const;
  };
}

#endif // !SENECA_BOOK_H
