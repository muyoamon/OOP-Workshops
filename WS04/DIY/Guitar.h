/***********************************************************************
// OOP244 Workshop #4 p2: tester program
// File  main.cpp
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
// Date: 13/2/2024
//
// I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
#include <ostream>
#define _CRT_SECURE_NO_WARNINGS
#ifndef SENECA_GUITAR_H
#define SENECA_GUITAR_H

#include <iostream>

namespace seneca{

  const int MAT_LEN = 10;
  const int MOD_LEN = 15;
  class GuitarStr {
     char m_material[MAT_LEN]{};
     double m_gauge{};
  public:
     const char* material()const;
     double gauge()const;
     GuitarStr();
     GuitarStr(const char* ma, double ga);
     bool operator==(const GuitarStr& rhs) const;
  };
  class Guitar {
    GuitarStr* m_strings;
    int m_numStrings;
    char m_model[MOD_LEN + 1];
  public:
    Guitar(const char* mod="Stratocaster");
    Guitar(GuitarStr strs[], int ns, const char* mod);
    ~Guitar();
    bool changeString(const GuitarStr& gs, int sn);
    void reString(GuitarStr strs[], int ns);
    void deString();
    bool strung() const;
    bool matchGauge(double ga) const;
    std::ostream& display(std::ostream& os = std::cout) const;
  };

}

#endif
