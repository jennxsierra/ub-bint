#include <iostream>

using namespace std;

/*This code serves as practice on Functions.

Function Declaration:*/

//Returns the area of a square from a user given number.
double AreaOfSquare (double side);

//Returns the last digit from the user's age.
int getLastDigit (int age);

//Returns true if user given number is even, false otherwise.
bool isEven(int number);

//Returns true if user given number is odd, false otherwise.
bool isOdd(int number);

//Prints 'n' copies of character 'c'
void multiPrint(int n,char c);

//Returns larger of 2 numbers
double max2(double num1, double num2);

//Returns true if user given number is multiple of 5, false otherwise.
bool isMultipleOfFive(int number);

//Returns FizzBuzz if user given number is multiple of 5 & 3, nothing otherwise.
void fizzBuzz(int number);

int main()
{
    cout << "Function Practice:\n";
    cout << "-------------------\n";
    
    //Function Tests:
    
    cout << "Function #1: Calculates the area of a square.\n";
    
    double side;
    
    cout << "\nEnter the length of a side of a square: ";
    cin >> side;
    
    double area = AreaOfSquare (side);
    cout << "The area of the square is " << area;
    
    cout << "\n---------------------------------------------------------------------";
    cout << "\nFunction #2: Prints the last digit of your age.\n";
    
    double age;
    
    cout << "\nEnter your age: ";
    cin >> age;
    
    int lastdigit = getLastDigit (age);
    cout << "The last digit of your age is " << lastdigit;
    
    cout << "\n---------------------------------------------------------------------";
    cout << "\nFunction #3: Verifies if a number is even.\n";
    
    double number;
    
    cout << "\nEnter a number: ";
    cin >> number;
    
    cout << "Is " << number << " even? ";
    cout << (isEven(number) ? "True" : "False");
    
    cout << "\n---------------------------------------------------------------------";
    cout << "\nFunction #4: Verifies if a number is odd.\n";
    
    cout << "\nEnter a number: ";
    cin >> number;
    
    cout << "Is " << number << " odd? ";
    cout << (isOdd(number) ? "True" : "False");
    
    cout << "\n---------------------------------------------------------------------";
    cout << "\nFunction #5: Prints any character as many times as you specify.\n";
    
    char c;
    int n;
    
    cout << "\nEnter a character: ";
    cin >> c;
    
    cout << "Enter the amount of times you would like to print it: ";
    cin >> n;
    
    cout << "Result: "; 
    multiPrint (n, c);
    
    cout << "\n---------------------------------------------------------------------";
    cout << "\nFunction #6: Determines the larger of 2 numbers.\n";
    
    double num1, num2;
    
    cout << "\nEnter a number: ";
    cin >> num1;
    
    cout << "Enter a second number: ";
    cin >> num2;
    
    cout << "The larger number is " << max2(num1, num2);
    
    cout << "\n---------------------------------------------------------------------";
    cout << "\nFunction #7: Determines if a number is a multiple of 5.\n";
    
    cout << "\nEnter a number: ";
    cin >> number;
    
    cout << "Is " << number << " a multiple of 5? ";
    cout << (isMultipleOfFive(number) ? "True" : "False");
    
    cout << "\n---------------------------------------------------------------------";
    cout << "\nFunction #8: Prints 'FizzBuzz' if a number is a multiple of 5 & 3.\n";
    
    cout << "\nEnter a number: ";
    cin >> number;
    
    cout << "Result: ";
    fizzBuzz(number);
    

    return 0;
}

//Function Definitions:

double AreaOfSquare (double side)
{
    return side * side;
}

int getLastDigit (int age)
{
    return age % 10;
}

bool isEven(int number)
{
    return number % 2 == 0;
}

bool isOdd(int number)
{
    return number % 2 != 0;
}

void multiPrint(int n,char c)
{
    for (int i = 0; i < n; i++)
        cout << c << " ";
}

double max2(double num1, double num2)
{
    if (num2 > num1)
        return num2;
    else
        return num1;
}

bool isMultipleOfFive(int number)
{
    return number % 5 == 0;
}

void fizzBuzz(int number)
{
    if (isMultipleOfFive(number) && number % 3 ==0)
        cout << "FizzBuzz\n";
    else
        cout << number << "\n";
}