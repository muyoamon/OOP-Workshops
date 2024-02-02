// Name: Thanatorn Wongthanaporn
// email: twongthanaporn@myseneca.ca
// id: 161197223
// Date: 1/1/2024
//
//I have done all the coding by myself and only copied the code 
//that my professor provided to complete my workshops and assignments.
#include "Car.h"
#include <cstring>
#include <cstdio>
namespace seneca {

  bool Car::isEmpty() const {
    bool empty = true;
    empty = m_makeModel == nullptr || !strcmp(m_makeModel, "");
    empty = empty || m_serviceDesc == nullptr || !strcmp(m_serviceDesc, "");
    return empty;
  }

  void Car::setEmpty() {
    m_licencePlate[0] = '\0';
    m_makeModel = nullptr;
    m_serviceDesc = nullptr;
    m_cost = 0.;
  }
  void Car::deallocateMemory() {
    delete[] m_makeModel;
    delete[] m_serviceDesc;
  }
  void Car::set(const char plateNo[], const char *carMakeModel,
           const char *serviceDesc, double serviceCost) {
    bool invalid = false;
    this->deallocateMemory();
    this->setEmpty();
    invalid = !strcmp(plateNo, "");
    invalid = invalid || carMakeModel == nullptr || !strcmp(carMakeModel, "");
    invalid = invalid || serviceDesc == nullptr || !strcmp(serviceDesc, "");
    if (!invalid) {
      strcpy(m_licencePlate, plateNo);
      m_makeModel = new char[strlen(carMakeModel) + 1];
      strcpy(m_makeModel, carMakeModel);
      m_serviceDesc = new char[strlen(serviceDesc) + 1];
      strcpy(m_serviceDesc, serviceDesc);
      m_cost = serviceCost;
    }
  }
  void Car::display() const {
    if (!this->isEmpty()) {
      printf("%15s%-20s\n", "License Plate: ", m_licencePlate);
      printf("%15s%-20s\n", "Model: ", m_makeModel);
      printf("%15s%-20s\n", "Service Name: ", m_serviceDesc);
      printf("%15s%-20.2lf\n", "Service Cost: ", m_cost);
    }
  }
}
