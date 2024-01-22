/***********************************************************************
OOP244 Workshop # p2: 
Version 1.0
Date	   winter 2024
Author	Fardad Soleimanloo
Description
  tests the file module of workshop 1 part 2(DIY)
Revision History
-----------------------------------------------------------
Name            Date            Reason
***********************************************************************/
#ifndef SENECA_STMARK_H
#define SENECA_STMARK_H

#define MAX_STUDENTS 1024
namespace seneca {

   /// <summary>
   /// Record of a mark received by a student.
   /// </summary>
   struct StMark {
      char name[21];
      char surname[31];
      int mark;
   };


   /// <summary>
   /// Tries to open the students' mark data file. 
   /// If successful it will print a report based on the 
   /// date in the file.
   /// </summary>
   /// <param name="filename">, holds the data file name</param>
   /// <returns>True if the date files is opened succesfully, 
   /// otherwise returns false</returns>
   bool printReport(const char* filename);

   /// <summary>
   /// Print students' mark array
   /// </summary>
   /// <param name="arr">, array of students' mark</param>
   /// <param name="size">, size of the array</param>
   /// <returns>Number of line printed</returns>
   int printStMarks(const StMark* arr, const int size);

   /// <summary>
   /// Sort students' mark array sorted by mark
   /// </summary>
   /// <param name="arr">, array of students' mark</param>
   /// <param name="size">, size of the array</param>
   /// <returns>None</returns>
   void sortStMarks(StMark* arr, const int size);

}
#endif // !SENECA_STMARK_H


