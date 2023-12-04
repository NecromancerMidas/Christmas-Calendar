#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

std::vector<int> getGoals(const std::string &filename)
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
                array.push_back(std::stoi(token));
            }
            catch (const std::invalid_argument &e)
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

    return array;
}

int main()
{
    int startingSum = 50000;

    std::vector<int> bets = getGoals("goals.txt");
    std::cout << bets[0] << std::endl;
    // Now you can use the bets vector as needed
}
