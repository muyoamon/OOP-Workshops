/***********************************************************************
// OOP244 Workshop #4 p2: tester program
//
// Version 1.0
// Date: Summer 2023
// Author Michael Huang
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
// Name: Thanatorn Wongthanaporn
// email: twongthanaporn@myseneca.ca
// id: 161197223
// Date: 13/1/2024
//
// I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS
#include "Guitar.h"
#include <cstring>
#include <iostream>
using namespace std;

namespace seneca {
const char *GuitarStr::material() const { return m_material; }
double GuitarStr::gauge() const { return m_gauge; }
GuitarStr::GuitarStr(){};

GuitarStr::GuitarStr(const char *ma, double ga) {
  strncpy(m_material, ma, MAT_LEN);
  m_gauge = ga;
};

bool GuitarStr::operator==(const GuitarStr &rhs) const {
  return this->m_gauge == rhs.m_gauge &&
         !strcmp(this->m_material, rhs.m_material);
}

Guitar::Guitar(const char *mod) {
  this->m_strings = nullptr;
  this->m_numStrings = 0;
  strncpy(this->m_model, mod, strlen(mod) + 1);
}
Guitar::Guitar(GuitarStr strs[], int ns, const char *mod) {
  this->m_numStrings = ns;
  this->m_strings = new GuitarStr[ns];
  strncpy(this->m_model, mod, strlen(mod) + 1);
  for (int i = 0; i < ns; i++) {
    this->m_strings[i] = strs[i];
  }
}
Guitar::~Guitar() { delete[] this->m_strings; }

bool Guitar::changeString(const GuitarStr &gs, int sn) {
  return sn < this->m_numStrings ? (this->m_strings[sn] = gs) == this->m_strings[sn] : 0;
}
void Guitar::reString(GuitarStr strs[], int ns) {
  delete[] this->m_strings;
  this->m_strings = new GuitarStr[ns];
  this->m_numStrings = ns;
  for (int i = 0; i < ns; i++) {
    this->m_strings[i] = strs[i];
  }
}
void Guitar::deString() {
  delete[] this->m_strings;
  this->m_numStrings = 0;
  this->m_strings = nullptr;
}
bool Guitar::strung() const {
  return this->m_strings != nullptr;
}
bool Guitar::matchGauge(double ga) const {
  bool match = false;
  for (int i=0;i<this->m_numStrings;i++) {
    if (this->m_strings[i].gauge() == ga) match=true;
  }
  return match;
}
std::ostream &Guitar::display(std::ostream &os) const {
  if (!strcmp(this->m_model, "") || this->m_numStrings == 0) {
    os << "***Empty Guitar***" << endl;
  } else {
    os << "Guitar Model: " << this->m_model << endl;
    os << "Strings: " << this->m_numStrings << endl;
    if (this->strung()) {
      for (int i=0;i<this->m_numStrings;i++) {
        os << "#" << i+1;
        os.width(MAT_LEN);
        os.precision(1);
        os << this->m_strings[i].material() << " | " << this->m_strings[i].gauge() << endl;
      }
    }
  }
  return os;
}
} // namespace seneca
