// SwoleSanta.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <locale>
#include <numeric>


//Fill array with reps. Only if the new rep is higher than the last rep. If not, save array. And go next.
//Fill Second array with reps. If second is larger or equal but higher sum replace first array.
//Output total reps.

//ProtoTypes
std::vector<std::string> getArrayFromFile(const std::string& fileName);
void SantaWorkout(std::vector<std::string> reps);
int arraySum(std::vector<int> vector);
int main()
{
    std::cout << "Hello World!\n";
    std::vector<std::string> reps = getArrayFromFile("reps.txt");
    SantaWorkout(reps);

}
void SantaWorkout(std::vector<std::string> reps) {
    std::vector<int> mostConsecutiveReps;
    std::vector<int> potentiallyMoreConsecutiveReps;
    int lastLine = 0;
    for (std::string line : reps) {
        std::cout << line << "\n";
        int numberOfReps = stoi(line);
        
        std::cout << numberOfReps << "\n";
        if (numberOfReps > lastLine) {
            lastLine = numberOfReps;
            potentiallyMoreConsecutiveReps.push_back(lastLine);
            numberOfReps = 0;
        }
        else {
            int sum1 = arraySum(mostConsecutiveReps);
            int sum2 = arraySum(potentiallyMoreConsecutiveReps);
            if ((mostConsecutiveReps.size() < potentiallyMoreConsecutiveReps.size()) || 
                (mostConsecutiveReps.size() == potentiallyMoreConsecutiveReps.size() && sum1 < sum2)) 
            {
                mostConsecutiveReps = potentiallyMoreConsecutiveReps;
            }
            potentiallyMoreConsecutiveReps.clear();
            lastLine = numberOfReps;
            potentiallyMoreConsecutiveReps.push_back(lastLine);
        }
        
    }
    int sum1 = arraySum(mostConsecutiveReps);
    int sum2 = arraySum(potentiallyMoreConsecutiveReps);
    if (potentiallyMoreConsecutiveReps.size() > mostConsecutiveReps.size() ||
        (potentiallyMoreConsecutiveReps.size() == mostConsecutiveReps.size() && sum2 > sum1)) {
        mostConsecutiveReps = potentiallyMoreConsecutiveReps;
    }
    // too lazy to dry this.
    std::cout << arraySum(mostConsecutiveReps) <<"\n";
    for (int line : mostConsecutiveReps) {
        std::cout << line << " ";
    }
}
int arraySum(std::vector<int> vector) {

    int sum = 0;
    return std::accumulate(vector.begin(),vector.end(),sum);
}
    std::vector<std::string> getArrayFromFile(const std::string & fileName) {
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
