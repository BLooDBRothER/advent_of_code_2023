#include <iostream>
#include <unistd.h>
#include "inputFile.h"

using namespace std;

string constructEachDayInputFilePath(string day) {
    // Buffer to hold the current working directory
    char buffer[PATH_MAX];

    if (getcwd(buffer, sizeof(buffer)) != nullptr) {
        // Print the current working directory
        std::cout << "Current Execution Path: " << buffer << std::endl;
    } else {
        // Handle error if getcwd fails
        std::cerr << "Error getting current working directory." << std::endl;
    }

    cout << "Solution for the day" << day << endl;
    return "./day" + day + "/input.txt";
}

vector<string> readInput(string dayNo) {

    InputFile inputFile(constructEachDayInputFilePath(dayNo));

    return inputFile.getInput();
}
