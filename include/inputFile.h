#include <iostream>
#include <fstream>

using namespace std;

class InputFile {
    private:
        fstream fileInput;

    public:
        InputFile(string fileName) {
            fileInput.open(fileName, ios::in);
        }

        vector<string> getInput() {
            string eachLine;
            vector<string> input;
            while(fileInput >> eachLine) {
                cout << eachLine;
                input.push_back(eachLine);
            }

            closeFile();

            return input;

        }

        void closeFile() {
            fileInput.close();
        }
};
