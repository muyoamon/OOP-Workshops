#include "io.h"
namespace seneca {
    void printInt(int value, int fieldWidth) {
        std::cout << value;
        for (int i = 0; i < fieldWidth - intDigits(value); i++) {
            std::cout << " ";
        }
    }
    int intDigits(int value) {
        int count = (value == 0);
        while (value != 0) {
            value /= 10;
            ++count;
        }
        return count;
    }

    // Performs a fool-proof integer entry
    int getInt(int min, int max) {
        int val = min - 1;
        bool done = false;
        while (!done) {
            std::cin >> val;
            if (val < min || val > max) {
                std::cout << "Invalid value!" << std::endl << "The value must be between " << min << " and " << max << ": ";
            }
            else {
                done = true;
            }
        }
        return val;
    }

    // moves the cursor backwards
    void goBack(int n) {
        for (int i = 0; i < n; std::cout << "\b", i++);
    }

    // draw line
    void labelLine(int n, const char* label) {
        std::cout << "+";
        for (int i = 0; i < n - 2; std::cout << "-", i++);
        std::cout << "+";
        if (label) {
            goBack(n - 4);
            std::cout << label;
        }
        std::cout << std::endl;
    }
    void line(int n) {
        std::cout << "+";
        for (int i = 0; i < n - 2; std::cout << "-", i++);
        std::cout << "+";
        std::cout << std::endl;
    }

    // displays the user interface menu
    int menu(int noOfSamples) {
        line(28);
        std::cout << "| No Of Samples: ";
        printInt(noOfSamples, 5);
        std::cout << "     |" << std::endl;
        line(28);
        std::cout << "| 1- Set Number of Samples |" << std::endl;
        std::cout << "| 2- Enter Samples         |" << std::endl;
        std::cout << "| 3- Graphs                |" << std::endl;
        std::cout << "| 0- Exit                  |" << std::endl;
        std::cout << "\\ >                        /";
        goBack(24);

        return getInt(0, 3);
    }
}