#include <iostream>
using namespace std;


double add(double x, double y);
double subtract(double x, double y);
double multiply(double x, double y);
double divide(double x, double y);
int remainder(int x, int y);


int main() {
    int choice;
    double number1, number2, result;
    
    cout << "Select operation you wanted to perform :" << endl;
    cout << "1. Addition of two numbers" << endl;
    cout << "2. Subtraction of two numbers" << endl;
    cout << "3. Multiplication of two numbers" << endl;
    cout << "4. Division of two numbers" << endl;
    cout << "5. Remainder of two divisable  numbers" << endl;
    
    cout << "Enter your choice (1/2/3/4/5): ";
    cin >> choice;
    
    if (choice < 1 || choice > 5) 
    {
        cout << "Invalid input. Please try again." << endl;
        return 1;
    }
    
    cout << "Enter the first number: ";
    cin >> number1;
    
    cout << "Enter the second number: ";
    cin >> number2;
    
    switch (choice) {
        case 1:
            result = add(number1, number2);
            cout << number1 << " + " << number2 << " = " << result << endl;
            break;
        case 2:
            result = subtract(number1, number2);
            cout << number1 << " - " << number2 << " = " << result << endl;
            break;
        case 3:
            result = multiply(number1, number2);
            cout << number1 << " * " << number2 << " = " << result << endl;
            break;
        case 4:
            if (number2 == 0) 
            {
                cout << "Error: Division by zero is not allowed." << endl;
                return 1;
            }
            result = divide(number1, number2);
            cout << number1 << " / " << number2 << " = " << result  << endl;
            break;
            
            case 5:
            if (number2 == 0) 
            {
                cout << "Error:division is not possible so reminder is undefined." << endl;
                return 1;
            }
            result = remainder(number1, number2);
            cout << number1 << " % " << number2 << " = " << result  << endl;
            break;
            
        default:
            cout << "Invalid choice. Please try again." << endl;
            return 1;
            
    }
    
    return 0;
}

double add(double x, double y) {
    return x + y;
}

double subtract(double x, double y) {
    return x - y;
}

double multiply(double x, double y) {
    return x * y;
}

double divide(double x, double y) {
    return x / y;
}
int remainder(int x, int y) {
    return x % y;
}
