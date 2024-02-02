// Name: Thanatorn Wongthanaporn
// email: twongthanaporn@myseneca.ca
// id: 161197223
// Date: 1/1/2024
//
//I have done all the coding by myself and only copied the code 
//that my professor provided to complete my workshops and assignments.
#ifndef SENECA_CAR_H
#define SENECA_CAR_H

namespace seneca {

class Car {
  char m_licencePlate[8 + 1];
  char *m_makeModel;
  char *m_serviceDesc;
  double m_cost;
public:
  /// check if object is in a safe empty state;
  /// \return true if empty
  bool isEmpty() const;
  /// set object to safe empty state
  void setEmpty();
  /// deallocate the allocated memory
  void deallocateMemory();
  /// set car information
  /// \param plateNo platen number
  /// \param carMakeModel model of a car
  /// \param serviceDesc service description
  /// \param serviceCost cost of the service
  void set(const char plateNo[], const char *carMakeModel,
           const char *serviceDesc, double serviceCost);
  //  display Car object
  void display() const;
};
} // namespace seneca
#endif // !SENECA_CAR_H
