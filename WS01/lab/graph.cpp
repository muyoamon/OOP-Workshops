#include "graph.h"
namespace seneca {
    // Maximum number of samples in an graph
    const int MAX_NO_OF_SAMPLES = 20;
    const int GRAPH_WIDTH = 65;

    // prints a graph comparing the sample values visually 
    void printGraph(int samples[], int noOfSamples, const char* label) {
        int max = findMax(samples, noOfSamples);
        labelLine(GRAPH_WIDTH + 10, label);
        for (int i = 0; i < noOfSamples; i++) {
            printBar(samples[i], max);
        }
        line(GRAPH_WIDTH + 10);
    }

    // prints a scaled bar relevant to the maximum value in samples array
    void printBar(int val, int max) {
        int i;
        int barlength = GRAPH_WIDTH * val / max;
        std::cout << "| ";
        for (i = 0; i < barlength; i++) {
            std::cout << "*";
        }
        std::cout << " ";
        printInt(val, (GRAPH_WIDTH + 6 - barlength));
        std::cout << "|" << std::endl;
    }

    // Fills the samples array with the statistic samples
    void getSamples(int samples[], int noOfSamples) {
        int i;
        for (i = 0; i < noOfSamples; i++) {
            line(28);
            std::cout << "\\ " << (i + 1) << "/";
            printInt(noOfSamples, 2);
            std::cout << ":                    /";
            goBack(20);
            samples[i] = getInt(1, 1000000);
        }
    }

    // finds the largest sample in the samples array, if it is larger than GRAPH_WIDTH,
    // otherwise it will return GRAPH_WIDTH. 
    int findMax(int samples[], int noOfSamples) {
        int max = samples[0];
        int i;
        for (i = 1; i < noOfSamples; i++) {
            if (max < samples[i]) max = samples[i];
        }
        return max < GRAPH_WIDTH ? GRAPH_WIDTH : max;
    }
}