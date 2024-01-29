// Name: Thanatorn Wongthanaporn
// email: twongthanaporn@myseneca.ca
// id: 161197223
// Date: 24/1/2024
//
//I have done all the coding by myself and only copied the code 
//that my professor provided to complete my workshops and assignments.
#ifndef SENECA_GUEST_H
#define SENECA_GUEST_H

namespace seneca {
  struct Guest {
    char* m_firstName;
    char* m_lastName;
    bool m_adult;
  };

  /// sets the Guest variables
  /// \param guest struct Guest variable to store
  /// \param first first name to store
  /// \param last last name to store
  /// \param age age, set m_adult flag to true if age>18
  void set (Guest& guest, const char* first, const char* last, int age);

  /// Prints the guest name.
  /// \param guest struct Geuest object to be printed
  void print(const Guest& guest);
  
  /// books the guest information from the console
  /// \param guest variable to store
  void book(Guest& guest);

  /// vacates the guest by deallocating memory
  /// \param guest struct object to be deallocate
  void vacate(Guest& guest);
}

#endif // !SENECA_GUEST_H
