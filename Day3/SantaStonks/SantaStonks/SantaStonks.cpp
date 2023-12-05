// SantaStonks.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

//Prototype
std::vector<std::vector<int>> FileOpener();
long long findOptimalStockTrade(std::vector<int> dayOfStonks, int , long long funds);
int main()
{
    std::cout << "Hello World!\n";
    std::vector<std::vector<int>> stonks = FileOpener();
    int day = 0;
    long long funds = 200000;
    for (std::vector<int> dayOfStonks : stonks) {
        day++;
       funds = findOptimalStockTrade(dayOfStonks, day, funds);
        /*for (int stonk : dayOfStonks) {
            std::cout << stonk << ",";
        }*/
        std::cout << "\n";
    }
    std::cout << "\n" << funds;
}

long long findOptimalStockTrade(std::vector<int> dayOfStonks, int day, long long funds) {
    int minNum = 1000000;
    int maxNum = 0;
    int minIndex = 0;
    int maxIndex = 0;
    int profitMargin = 0;
    long long profit = 0;
    for (int i = 0; i < dayOfStonks.size(); i++) {
      if (dayOfStonks[i] < minNum) {
          for (int j = i + 1; j < dayOfStonks.size(); j++) {
              /*if (dayOfStonks[j] - dayOfStonks[i] > profitMargin) {
                  minNum = dayOfStonks[i];
                  minIndex = i;
              }*/
              if (dayOfStonks[j] - dayOfStonks[i] > profitMargin) {
                  profitMargin = dayOfStonks[j] - dayOfStonks[i];
                  minNum = dayOfStonks[i];
                  maxNum = dayOfStonks[j];
                  std::cout << profitMargin << "\n";
              }
        }  
        }
        
            /*if (dayOfStonks[i] - minNum > profitMargin) {
            profitMargin = dayOfStonks[i] - minNum;
            maxNum = dayOfStonks[i];
            maxIndex = i;
        }*/
    }
    long long rest = funds % minNum;
    profit = (funds / minNum) * (long long)maxNum + rest;
    std::cout << "Day " << day << "Stock Purchase Price : " << minNum << "Stock Sell Price : " << maxNum << "Profit : " << profit;
    return profit;
}

std::vector<std::vector<int>> FileOpener() {
    std::vector<int> Stonks;
    std::vector<std::vector<int>> allStonks;
    std::ifstream file("input.txt");
    std::string line;
    while (getline(file, line)) {
        std::istringstream iss(line);
        std::string token;
        while (getline(iss, token,',')) {

            Stonks.push_back(std::stoi(token));

        }
        allStonks.push_back(Stonks);
        Stonks.clear();
    }

    return allStonks;
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
