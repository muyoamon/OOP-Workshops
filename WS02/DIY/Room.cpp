// Name: Thanatorn Wongthanaporn
// email: twongthanaporn@myseneca.ca
// id: 161197223
// Date: 24/1/2024
//
//I have done all the coding by myself and only copied the code 
//that my professor provided to complete my workshops and assignments.
#include "Room.h"
#include "Guest.h"
#include <cstring>
#include <iostream>

namespace seneca {

void set(Room &room, int numberOfGuests, const char *roomNumber) {
  room.m_noOfGuests = numberOfGuests;
  strncpy(room.m_roomNumber, roomNumber, 5);
  room.m_roomNumber[5] = '\0';

}

void print(const Room &room) {
  int i;
  if (room.m_noOfGuests == 0 || room.m_guests == nullptr ||
      !strcmp(room.m_roomNumber,"")) {
    std::cout << "Empty Room!" << std::endl;
  } else {
    std::cout << "Room Number: ";
    std::cout << room.m_roomNumber << std::endl;
    for (i=0;i<room.m_noOfGuests;i++) {
      std::cout << "    ";
      print(room.m_guests[i]);
    }
  }

}

void book(Room &room) {
  char rNumber[6] = "";
  int nGuests = 0;
  std::cout << "Room number: ";
  std::cin >> rNumber;
  std::cout << "Number of guests: ";
  std::cin >> nGuests;
  room.m_guests = new Guest[nGuests];
  for (int i=0;i<nGuests;i++) {
    std::cout << i+1 << ":" << std::endl;
    book(room.m_guests[i]);
  }
}

void vacate(Room &room) {
  if (room.m_guests != nullptr) {
    
    for (int i=0;i<room.m_noOfGuests;i++) {
      vacate(room.m_guests[i]);
    }
    delete room.m_guests;
    room.m_guests = nullptr;
  }
}
} // namespace seneca
