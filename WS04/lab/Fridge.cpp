/***********************************************************************
// OOP244 Workshop #4 p1
//
// File	Fridge.cpp
// Version 1.0
// Date: Summer 2023
// Author Michael Huang
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
// Name: Thanatorn Wongthanaporn
// email: twongthanaporn@myseneca.ca
// id: 161197223
// Date: 1/1/2024
//
// I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS
#include "Fridge.h"
#include <cstring>
#include <iostream>
using namespace std;

namespace seneca {

const char *Food::name() const { return m_name; }
int Food::weight() const { return m_weight; }
Food::Food() {}

Food::Food(const char *nm, int wei) {
  strncpy(m_name, nm, NAME_LEN);
  m_weight = wei;
}

Fridge::Fridge() {
  this->m_numFoods = 0;
  this->m_model = nullptr;
}

Fridge::Fridge(Food farr[], int nf, const char *mod) {
  this->m_numFoods = 0;
  this->m_model = nullptr;
  if (nf > 0 && mod != nullptr && strcmp(mod, "")) {
    this->m_numFoods = nf;
    this->m_model = new char[strlen(mod) + 1];
    strcpy(m_model, mod);
    for (int i = 0; i < nf; i++) {
      this->m_foods[i] = Food(farr[i].name(), farr[i].weight());
    }
  }
}

Fridge::~Fridge() { delete[] this->m_model; }

bool Fridge::addFood(const Food &f) {
  bool success = false;
  if (this->m_numFoods < FRIDGE_CAP) {
    this->m_foods[this->m_numFoods] = Food(f.name(), f.weight());
    this->m_numFoods++;
    success = true;
  }
  return success;
}
void Fridge::changeModel(const char *m) {
  if (m != nullptr && strcmp(m, "")) {
    delete this->m_model;
    this->m_model = new char[strlen(m) + 1];
    strcpy(m_model, m);
  }
}
bool Fridge::fullFridge() const { return this->m_numFoods == FRIDGE_CAP; }
bool Fridge::findFood(const char *f) const {
  bool found = 0;
  for (int i = 0; i < this->m_numFoods; i++) {
    if (strcmp(this->m_foods[i].name(), f) == 0) {
      found = 1;
    }
  }
  return found;
}
std::ostream &Fridge::display(std::ostream &os) const {
  if (this->m_numFoods > 0 && this->m_model != nullptr &&
      strcmp(this->m_model, "")) {
    os << "Fridge Model: " << this->m_model << endl;
    os << "Food count: " << this->m_numFoods << " Capacity: " << FRIDGE_CAP
       << endl;
    os << "List of Foods" << endl;
    for (int i = 0; i < this->m_numFoods; i++) {
      os.width(NAME_LEN);
      os << this->m_foods[i].name() << " | " << this->m_foods[i].weight()
         << endl;
    }
  }
  return os;
}

} // namespace seneca
