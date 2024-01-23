#ifndef SENECA_ASSESSMENT_H
#define SENECA_ASSESSMENT_H

#include <cstdio>

namespace seneca {
struct Assessment {
  double *m_mark;
  char *m_title;
};

/// Reads one integer
/// @param value variable to store
/// @param fptr pointer to file
/// @return true if success, false otherwise.
bool read(int& value, FILE* fptr);

/// Reads one double
/// @param value variable to store
/// @param fptr pointer to file
/// @return true if success, false otherwise.
bool read(double& value, FILE* fptr);

/// Skip a comma, reads string no longer than 60 characters
/// @param value variable to store
/// @param fptr pointer to file
/// @return true if success, false otherwise.
bool read(char* cstr, FILE* fptr);

/// allocate dynamic double and cstring into field of Assessment structure
/// @param assess Assessment variable
/// @param fptr pointer to file
/// @return true if success, false otherwise.
bool read(Assessment& assess, FILE* fptr);

/// free memory of assessment allocated field
/// @param aptr pointer to dynamic Assessment array
/// @param fptr pointer to file
void freeMem(Assessment*& aptr, int size);

/// Allocate dyanmic Assessment array according to file
/// @param assess Assessment variable
/// @param fptr pointer to file
/// @return size of Assessment array if number matches,
/// otherwise return zero
int read(Assessment*& aptr, FILE* fptr);

} // namespace seneca
#endif // !SENECA_ASSESSMENT_H
