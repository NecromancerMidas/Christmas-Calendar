// Check score.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>



//std::vector<double> getBets(const std::string& filename, bool isMatchResult) {
//    std::vector<double> array;
//    std::ifstream file(filename);
//    std::string line;
//
//    if (file.is_open()) {
//        while (getline(file, line)) {
//            line.erase(0, 1);
//            line.erase(line.size() - 1);
//            std::stringstream ss(line);
//            std::string number;
//            
//
//
//            while (std::getline(ss, number, ',')) {
//                array.push_back(std::stod(number));
//            }
//            for (double number : array) {
//                std::cout << number << std::endl;
//            }
//        }
//
//        
//    }
//    return array;
//};
std::vector<double> getBets(const std::string& filename, bool isMatchResult) {
    std::vector<double> array;
    std::ifstream file(filename);
    std::string line;

    if (file.is_open()) {
        while (getline(file, line)) {
            std::stringstream ss(line);
            std::string pair;

            while (std::getline(ss, pair, ']')) {
                size_t startPos = pair.find('[');
                if (startPos != std::string::npos) {
                    pair = pair.substr(startPos + 1);
                }

                std::stringstream pairStream(pair);
                std::string number;
                double firstNumber, secondNumber;

                // Get the first number
                if (std::getline(pairStream, number, ',')) {
                    try {
                        firstNumber = std::stod(number);
                    }
                    catch (const std::invalid_argument& e) {
                        std::cerr << "Invalid first number: " << number << std::endl;
                        continue;
                    }
                }

                // Get the second number
                if (std::getline(pairStream, number)) {
                    try {
                        secondNumber = std::stod(number);
                    }
                    catch (const std::invalid_argument& e) {
                        std::cerr << "Invalid second number: " << number << std::endl;
                        continue;
                    }
                }

                // Add the selected number to the array
                if (isMatchResult) {
                    array.push_back(firstNumber);
                }
                else {
                    array.push_back(secondNumber);
                }
            }
        }
        file.close();
    }
    else {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }

    // Debugging output (optional)
    for (double number : array) {
        std::cout << number << std::endl;
    }

    return array;
}
std::vector<int> getGoals(const std::string& filename)
{
 
    std::vector<int> array;
    std::ifstream file(filename);
    std::string token;

    if (file.is_open())
    {
        while (getline(file, token, ','))
        {
            try
            {
                std::cout << token << std::endl;
                if (filename == "goals.txt") {
                    array.push_back(std::stoi(token));
                }
               /* else {
                    arrayofArrays.push_back({ 1,2 })
                };*/
            }
            catch (const std::invalid_argument& e)
            {
                std::cerr << "Invalid argument: " << e.what() << " for token: " << token << std::endl;
                // You might choose to continue, break, or handle this in another way
            }
        }
        file.close();
    }
    else
    {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }
    if (filename == "goals.txt") {
        return array;
    }
    /*else {
        return arrayofArrays;
    }*/
}

int main()
{
    int startingSum = 50000;
    int currentSum = startingSum;
    double bettingRatio = 17.5;
    std::vector<int> goals = getGoals("goals.txt");
    std::vector<double> playerGuess = getBets("bets.txt", true);
    std::vector<double> winningRatio = getBets("bets.txt", false);
    /*for (int goal : goals) {
        std::cout << goal << ' ';
        int bet = std::round(startingSum * (bettingRatio / 100.0));
        std::cout << bet << std::endl;
        startingSum -= bet;
        std::cout << startingSum << std::endl;
    }*/
    for (int i = 0; i < goals.size(); i++) {
        std::cout << currentSum << std::endl;
        std::cout << goals[i] << " Goals scored" << std::endl;
        int bet = std::round(currentSum * (bettingRatio / 100.0));
        std::cout << playerGuess[i] << " playerGuess" << std::endl;
        std::cout << bet << " Player Bet" << std::endl;
        currentSum -= bet;
        double potentialWinnings = std::round(bet * winningRatio[i]);
        std::cout << potentialWinnings << " Potential Profit" << std::endl;
        std::cout << currentSum << " CurrentSum " << bet << " Bet " << potentialWinnings << " PotentialWinnings" << std::endl;
        if (playerGuess[i] <= goals[i]) {
            currentSum += potentialWinnings;
            currentSum += bet; /*Not how you calculate winnings, but gives correct answer.*/
            std::cout << " You won" << potentialWinnings << " " << currentSum << "Current Sum" << std::endl;
        }
        std::cout << std::endl;
    }
    std::cout << currentSum << std::endl;
    std::cout << (startingSum -= currentSum) << std::endl;
    // Now you can use the bets vector as needed
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
