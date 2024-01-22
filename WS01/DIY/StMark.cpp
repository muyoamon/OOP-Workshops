//Name:     Thanatorn Wongthanaporn
//Email:    twongthanaporn@myseneca.ca
//ID:       161197223
//Date:     16/1/2023

//I have done all the coding by myself and only copied the code that my professor 
// provided to complete my workshops and assignments.

#include <iostream>
#include "StMark.h"
#include "file.h"
#include "io.h"

namespace seneca {
	bool printReport(const char* filename)
	{
		StMark marks[MAX_STUDENTS] = { {0} };
		int size;

		if (openFile(filename))
		{
			size = readMarks(marks);
			sortStMarks(marks, size);
			printStMarks(marks, size);
		}
		else
		{
			return false;
		}
	}

	int printStMarks(const StMark* arr, const int size)
	{
		int i;
		for (i = 0; i < size; i++)
		{
			printInt(i+1, 3);
			std::cout << ":[";
			printInt(arr[i].mark, 3);
			std::cout << "] " << arr[i].name << " " << arr[i].surname << std::endl;
		}
		return i;
	}

	void sortStMarks(StMark* arr, const int size)
	{
		int sorted = size-1;
		int i;
		StMark temp = { 0 };
		while (sorted != 0)
		{
			for (i = 0; i < sorted; i++)
			{
				if (arr[i].mark < arr[i + 1].mark)
				{
					temp = arr[i + 1];
					arr[i + 1] = arr[i];
					arr[i] = temp;
				}
			}
			sorted--;
		}
	}
}