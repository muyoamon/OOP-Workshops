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

