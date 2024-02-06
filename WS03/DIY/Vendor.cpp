#include "Vendor.h"
#include "Icecream.h"
#include <iostream>
#include <ostream>
namespace seneca {
void Vendor::setEmpty() { this->icecreams = nullptr; }
void Vendor::takeOrders() {
  std::cout << "Seneca Icecream shop" << std::endl
            << "          @" << std::endl
            << "        (' .)" << std::endl
            << "       (*.`. )" << std::endl
            << "        \\###/" << std::endl
            << "         \\#/" << std::endl
            << "          V" << std::endl
            << "How many Icecreams?" << std::endl;
  std::cout << "> ";
  std::cin >> this->numIcecreams;
  this->icecreams = new Icecream[numIcecreams];
  for (int i = 0; i < this->numIcecreams; i++) {
    std::cout << "Order number " << i + 1 << ":" << std::endl;
    this->icecreams[i].getOrder();
  }
}
void Vendor::displayOrders() {
  double priceSum = 0., tax = .0;
  std::cout << "********** Order Summary **********" << std::endl;
  for (int i = 0; i < this->numIcecreams; i++) {
    std::cout << "Order No: " << i + 1 << ":" << std::endl;
    this->icecreams[i].printOrder();
    priceSum += this->icecreams[i].getPrice();
    if (i + 1 != this->numIcecreams) {
      std::cout << std::endl;
    }
  }
  std::cout << "-----------------------------------" << std::endl;
  std::cout.width(25);
  std::cout << std::left << "Price:";
  std::cout.width(10);
  std::cout << std::right << priceSum << std::endl;

  std::cout.width(25);
  std::cout << std::left << "Tax:";
  std::cout.width(10);
  std::cout << std::right << (tax = .13 * priceSum) << std::endl;

  std::cout.width(25);
  std::cout << std::left << "Total Price ($):";
  std::cout.width(10);
  std::cout << std::right << priceSum + tax << std::endl;
}
void Vendor::clearData() { delete[] this->icecreams; }
} // namespace seneca
