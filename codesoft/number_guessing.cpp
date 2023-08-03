#include <iostream>
#include <cstdlib>
#include <ctime>

int generateRandomNumber(int lower_bound, int upper_bound)
{
    return rand() % (upper_bound - lower_bound + 1) + lower_bound;
}

int main()
{
    srand(static_cast<unsigned>(time(0)));

    int lower_bound = 1;
    int upper_bound = 1000;
    int secret_number = generateRandomNumber(lower_bound, upper_bound);
    int user_guess;

    std::cout << "Welcome to the Guess the Number Game!" << std::endl;
    std::cout <<  "thinking of a number between " << lower_bound << " and  " << upper_bound <<std::endl;

    while (true) 
    {
        std::cout << "Take a guess: ";
        std::cin >> user_guess;

        if (user_guess == secret_number) 
        {
            std::cout << "Congratulations! You guessed the correct number " << secret_number << "." << std::endl;
            break;
        } 
        else if (user_guess < secret_number) 
        {
            std::cout << " your guessed number is  low. Try again." << std::endl;
        } 
        else 
        {
            std::cout << "your guessed number is  high. Try again." << std::endl;
        }
    }

    return 0;
}