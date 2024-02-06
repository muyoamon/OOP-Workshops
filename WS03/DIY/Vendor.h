// Name: Thanatorn Wongthanaporn
// email: twongthanaporn@myseneca.ca
// id: 161197223
// Date: 6/2/2024
//
//I have done all the coding by myself and only copied the code 
//that my professor provided to complete my workshops and assignments.
#ifndef SENECA_VENDOR_H
#define SENECA_VENDOR_H

#include "Icecream.h"
namespace seneca {
class Vendor {
  Icecream* icecreams;
  int numIcecreams;
  public:
    void setEmpty();
    void takeOrders();
    void displayOrders();
    void clearData();
};
}

#endif // !SENECA_VENDOR_H

