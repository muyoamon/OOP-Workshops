// Name: Thanatorn Wongthanaporn
// email: twongthanaporn@myseneca.ca
// id: 161197223
// Date: 6/2/2024
//
//I have done all the coding by myself and only copied the code 
//that my professor provided to complete my workshops and assignments.
#include "Icecream.h"
#include <climits>
#include <cstring>
#include <iostream>
#include <ostream>
namespace seneca {

//                            0          10          21     27           39 53
const char Icecream::flavourList[53] =
    "Chocolate\0Strawberry\0Mango\0Tutti fruit\0Almond crunch";
void Icecream::getFlavour() {
  bool valid = 1;
  std::cout << "Select flavour:" << std::endl;
  std::cout << "----------------" << std::endl;
  std::cout << "1: Chocolate" << std::endl;
  std::cout << "2: Strawberry" << std::endl;
  std::cout << "3: Mango" << std::endl;
  std::cout << "4: Tutti fruit" << std::endl;
  std::cout << "5: Almond crunch" << std::endl;
  std::cout << "----------------" << std::endl;
  do {
    valid = 1;
    std::cout << "> ";
    std::cin >> this->flavour;
    if (!(valid = std::cin.good())) {
      std::cout << "Invalid entry, retry" << std::endl;
      std::cin.clear();
      std::cin.ignore(INT_MAX, '\n');
    } else if (!(valid = this->flavour > 0 && this->flavour < 6)) {
      std::cout << "Invlid value(1<=val<=5)" << std::endl;
    }
  } while (!valid);
}
void Icecream::getOrder() {
  this->getFlavour();
  this->getScoops();
  this->getVanillaWafer();
  this->price = 5*this->nScoops + ((this->flavour == 1) ? 1*nScoops : 0) + !!vanillaWafer * 5; 
}

void Icecream::printOrder() const {
  char flavourStr[35]; 
  strcpy(flavourStr, getFlavourString(this->flavour));
  strcat(flavourStr, " flavour:");
  std::cout << "Order details:                Price" << std::endl;
  std::cout << "-----------------------------------" << std::endl;
  std::cout << "Number of scoops, " << this->nScoops << " total:";
  std::cout.width(9);
  std::cout.precision(2);
  std::cout << std::right << std::fixed << (double) 5.0 * this->nScoops << std::endl;
  std::cout.width(30);
  std::cout << std::left << flavourStr;
  if (flavour == 1) {
    std::cout.width(5);
    std::cout << std::right << nScoops * 1.;
  }
  std::cout << std::endl;
  std::cout.width(30);
  std::cout << std::left << "Vanilla Wafer:";
  std::cout.width(5);
  std::cout << std::right << (this->vanillaWafer ? 5.0 : 0.0) << std::endl;
  std::cout.width(30);
  std::cout << std::left << "Price:";
  std::cout.width(5);
  std::cout << std::right << this->price << std::endl;
  //std::cout << "-----------------------------------" << std::endl;
  
}
void Icecream::getScoops() {
  bool valid;
  std::cout << "Number of Scoops (max 3)" << std::endl;
  do {
    valid = 1;
    std::cout << "> ";
    std::cin >> this->nScoops;
    if (!(valid = std::cin.good())) {
      std::cout << "Invalid entry, retry" << std::endl;
      std::cin.clear();
      std::cin.ignore(INT_MAX, '\n');
    } else if (!(valid = this->nScoops > 0 && this->nScoops < 4)) {
      std::cout << "Invlid value(1<=val<=3)" << std::endl;
    }
  } while (!valid);
}
void Icecream::getVanillaWafer() {
  bool valid;
  char c;
  std::cout << "Vanilla wafer cone?" << std::endl << "(Y)es/(N)o ";
  do {
    valid = 1;
    std::cout << "> ";
    std::cin >> c;
    if (!(valid = (c == 'y' || c == 'Y' || c == 'n' || c == 'N'))) {
      std::cout << "Only Y or N are acceptable:" << std::endl;
    }
  } while (!valid);
  this->vanillaWafer = (c == 'y' || c == 'Y') ? true : false;
}

const char *Icecream::getFlavourString(int flavour) const {

  int pos;
  switch (flavour) {
  case 1:
    pos = 0;
    break;
  case 2:
    pos = 10;
    break;
  case 3:
    pos = 21;
    break;
  case 4:
    pos = 27;
    break;
  case 5:
    pos = 39;
    break;
  default:
    pos = 53;
  }
  return &this->flavourList[pos];
}

double Icecream::getPrice() const {
  return this->price;
}
} // namespace seneca
