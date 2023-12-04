// ClickClackLockCrack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <locale>

// Function Prototype
std::vector<std::string> getArrayFromFile(const std::string& fileName);
void CountClickClacks(std::vector<std::string> arrayOfClickers);
int main()
{
    std::locale::global(std::locale("en_US.UTF-8"));
    std::cout << "Hello World!\n";
   std::vector<std::string> clickClackArray = getArrayFromFile("log.txt");
   CountClickClacks(clickClackArray);
}
void CountClickClacks(std::vector<std::string> arrayOfClickers) {
    std::vector<bool> lockPins(7);
    int sucesses = 0;
    for (std::string line : arrayOfClickers) {
        std::cout << line << "\n";
        
        int pinPosition = ((int)line.back() - '0') -1;
        if (line == " ") {
            std::cout << "Total locks picked:" << sucesses;
            break;
        }
        if (line.find("klikk") != std::string::npos) {
            std::cout << "click" << "\n";
            lockPins[pinPosition] = true;
        }
        else {
            std::cout << "clack" << "\n";
            lockPins[pinPosition] = false;
        }
        if (std::all_of(lockPins.begin(), lockPins.end(), [](bool v) { return v; })) {
            std::fill(lockPins.begin(), lockPins.end(), false);
            std::cout << "Lock Picked! Number of Locks Picked: " << sucesses << "\n";
            sucesses++;
        }
        
    }
    std::cout << "Total locks picked:" << sucesses;
}
 std::vector<std::string> getArrayFromFile(const std::string& fileName) {
     std::vector<std::string> lines;
     std::ifstream file(fileName);

     std::string line;
     while (getline(file, line)) {
         std::istringstream iss(line);
         std::string token;
         

         while (getline(iss, token, ',')) { // Split at each comma
             lines.push_back(token);
         };
     }
     file.close();
     return lines;

}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
