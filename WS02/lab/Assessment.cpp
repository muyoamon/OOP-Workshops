// Name: Thanatorn Wongthanaporn
// email: twongthanaporn@myseneca.ca
// id: 161197223
// Date: 24/1/2024
//
//I have done all the coding by myself and only copied the code 
//that my professor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Assessment.h"
namespace seneca {
  bool read(int& value, FILE* fptr)
  {
    return fscanf(fptr, "%d", &value) != EOF;
  }

  bool read(double& value, FILE* fptr)
  {
    return fscanf(fptr, "%lf", &value) != EOF;
  }

  bool read(char* cstr, FILE* fptr)
  {
    return fscanf(fptr, ",%60[^\n]\n", cstr) != EOF;
  }

  bool read(Assessment& assess, FILE* fptr)
  {
    double mark;
    char title[60+1];
    int length;
    bool ret = false;
    if (read(mark, fptr) && read(title, fptr))
    {
      length = strlen(title);
      assess.m_mark = new double(mark);
      assess.m_title = new char[length+1];
      strcpy(assess.m_title, title);
      ret = true;
    }
    return ret;
  }

  void freeMem(Assessment*& aptr, int size) 
  {
    int i;
    for (i=0;i<size;i++)
    {
      delete aptr[i].m_title;
      delete aptr[i].m_mark;
    }
    delete aptr;
  }

  int read(Assessment*& aptr, FILE* fptr)
  {
    int sSize, cSize = 0;
    if (read(sSize,fptr))
    {
      aptr = new Assessment[sSize];
      while (read(aptr[cSize],fptr) && (cSize < sSize))
      {
        cSize++;
      }
      if (cSize != sSize)
      {
        freeMem(aptr, cSize);
        cSize = 0;
      }
    }
    return cSize;

  }

  
}
