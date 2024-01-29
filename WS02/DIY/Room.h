// Name: Thanatorn Wongthanaporn
// email: twongthanaporn@myseneca.ca
// id: 161197223
// Date: 24/1/2024
//
//I have done all the coding by myself and only copied the code 
//that my professor provided to complete my workshops and assignments.
#ifndef SENECA_ROOM_H
#define SENECA_ROOM_H

#include "Guest.h"

namespace seneca {
  struct Room {
    char m_roomNumber[6];
    int m_noOfGuests;
    Guest* m_guests;
  };

  /// sets the Room 
  /// \param room room object to be set
  /// \param numberOfGuests number of m_guests
  /// \param roomNumber room number
  void set(Room& room, int numberOfGuests, const char* roomNumber);

  /// print the room number and name of guest 
  /// \param room struct Room object
  void print(const Room& room);

  /// Books the room using stdin
  /// \param room struct room object to be set
  void book(Room& room);

  /// vacate the room, deallocate the memory
  /// \param room struct Room object to be deallocate
  void vacate(Room& room);
}

#endif // !SENECA_ROOM_H

