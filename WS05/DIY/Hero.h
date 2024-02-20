// Name: Thanatorn Wongthanaporn
// Email: twongthanaporn@myseneca.ca 
// id: 161197223
// Date: 20/2/2024

// I have done all the coding by myself and only copied the code that my
// professor provided to complete my workshops and assignments.
#ifndef SENECA_HERO_H
#define SENECA_HERO_H
#include "Power.h"
#include <iostream>
#include <ostream>
namespace seneca {
class Hero {
  char m_name[MAX_NAME_LENGTH + 1];
  Power *m_power;
  int m_numPower;
  int m_powerLevel;

public:
  Hero();
  Hero(const char *name, Power power[], int numPower);
  ~Hero();
  
  void recalculatePowerLevel();

  std::ostream& display(std::ostream& os=std::cout) const;

  void operator+=(Power& power);
  void operator-=(const int& value);

  bool operator>(Hero& rhs);
  bool operator<(Hero& rhs);
  
  Hero& operator<<(Power& power);
};
Hero& operator>>(Power& power, Hero& hero);


} // namespace seneca

#endif // !SENECA_HERO_H
