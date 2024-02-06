#ifndef SENECA_ICECREAM_H
#define SENECA_ICECREAM_H

namespace seneca {
class Icecream {
  
  const static char flavourList[53];
  int flavour;
  int nScoops;
  bool vanillaWafer;
  double price;

public:
  /// get the flavour from customer
  void getFlavour();
  /// get icecream order from customer
  void getOrder();
  /// print the icecream order
  void printOrder() const;
  /// get the number of scoops from customer
  void getScoops();
  /// get the Vanilla Wafer option from customer
  void getVanillaWafer();
  /// return flavour from flavour num
  /// \param flavour flavour to get index
  /// \return flavour string
  const char* getFlavourString(int flavour) const;
  /// get price of icecream
  /// \return price of icecream
  double getPrice() const;
};
} // namespace seneca

#endif // !SENECA_ICECREAM_H
