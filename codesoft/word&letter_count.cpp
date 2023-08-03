#include <iostream>
#include <string>
#include <sstream>

int countWords(const std::string& text) 
{
    std::stringstream ss(text);
    std::string word;
    int wordCount = 0;

    while (ss >> word)
    {
        wordCount++;
    }

    return wordCount;
}

int countLetters(const std::string& text)
{
    int letterCount = 0;

    for (char c : text)
    {
        if (isalpha(c)) 
        {
            letterCount++;
        }
    }

    return letterCount;
}

int main()
{
    std::cout << "Word and Letter Counting Program" << std::endl;
    std::cout << "-----------------------------" << std::endl;

    std::string user_input;
    std::cout << "Enter the File name: ";
    std::getline(std::cin, user_input);

    int wordCount = countWords(user_input);
    int letterCount = countLetters(user_input);

    std::cout << "Total word count of the input file name: " << wordCount << " words." << std::endl;
    std::cout << "Total letter count of the input file name : " << letterCount << " letters." << std::endl;

    return 0;
}