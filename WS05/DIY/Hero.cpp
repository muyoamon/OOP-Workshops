// Name: Thanatorn Wongthanaporn
// Email: twongthanaporn@myseneca.ca 
// id: 161197223
// Date: 20/2/2024

// I have done all the coding by myself and only copied the code that my
// professor provided to complete my workshops and assignments.
#include "Hero.h"
#include "Power.h"
#include <cstring>
#include <ostream>
namespace seneca {
  
  Hero::Hero() {
    strncpy(this->m_name,"",MAX_NAME_LENGTH);
    this->m_power = nullptr;
    this->m_numPower = 0;
    this->m_powerLevel = 0;
  }
  Hero::Hero(const char *name, Power power[], int numPower) {
    strncpy(this->m_name, name, MAX_NAME_LENGTH);
    this->m_numPower = numPower;
    this->m_power = new Power[numPower];
    for (int i=0;i<this->m_numPower;i++) {
      this->m_power[i] = power[i];
    }
    this->recalculatePowerLevel();
  }
  Hero::~Hero() {
    delete[] this->m_power;
  }
  void Hero::recalculatePowerLevel() {
    this->m_powerLevel = 0;
    for (int i=0;i<this->m_numPower;i++) {
      this->m_powerLevel += this->m_power[i].checkRarity();
    }
    this->m_powerLevel*= this->m_numPower;
  }
  std::ostream& Hero::display(std::ostream& os) const {
    os << "Name: " << this->m_name << std::endl;
    displayDetails(this->m_power, this->m_numPower);
    os << "Power Level: " << this->m_powerLevel << std::endl;
    return os;
  }


  void Hero::operator+=(Power& power) {
    int i;
    Power* temp = new Power[this->m_numPower + 1];
    for (i=0;i<this->m_numPower;i++) {
      temp[i] = this->m_power[i];
    }
    temp[m_numPower++] = power;
    delete[] this->m_power;
    this->m_power = temp;
    this->recalculatePowerLevel();
  }
  void Hero::operator-=(const int& value) {
    this->m_powerLevel -= value;
  }

  bool Hero::operator>(Hero& rhs) {
    return this->m_powerLevel > rhs.m_powerLevel;
  }
  bool Hero::operator<(Hero& rhs) {
    return this->m_powerLevel < rhs.m_powerLevel;
  }
  
  Hero& Hero::operator<<(Power& power) {
    *this += power;
    return *this;
  }
  Hero& operator>>(Power& power, Hero& hero) {
    hero += power;
    return hero;
  }
  
    
}
