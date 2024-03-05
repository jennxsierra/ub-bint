#include <iostream>
using namespace std;

void doubleNumber(int *, int *);
int findMinimum(const int *, int );
void printArray(const int *, int );
int numberOfOdds(const int *, int);

int main()
{
    //ask the user to enter two numbers
    int num1, num2;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    int *num1ptr = &num1;
    int *num2ptr = &num2;
    doubleNumber(num1ptr, num2ptr);

    cout << "Number 1 has been updated to "  << num1;
    cout << "\nNumber 2 has been updated to "  << num2;

    const int size = 10;
    int array1[size] = {2,3,4,5,6,7};

    cout << "\n\nThe array contains the following values: ";
    printArray(array1, size);

    int result = findMinimum(array1, size);
    cout << "\n\nThe minimum value in the array is: " << result;

    int oddCount = numberOfOdds(array1, size);
    cout << "\n\nThe number of odd numbers in the array is: " << oddCount;

    return 0;
}

//This function will double each of the numbers entered
//example user enters 5, 10. The numbers will be changed to 10, 20
void doubleNumber(int *var1, int *var2) {
    *var1 *= 2;
    *var2 *= 2;
}


//this function will find the smallest number in an array and return that number
void printArray(const int *aptr, int size) {
    cout << endl;
    for (int i = 0 ; i < size; ++i) {
        cout << *(aptr +i) << " ";
    }
}

//This function will print all the smallest number in the array
int findMinimum(const int *aptr, int size) {
    int min = 1;

    for (int i = 0; i < size; ++i) {
        if (*(aptr + i) < min)
            min = *(aptr + i);
    }

    return min;
}

//this function will return the number of odd numbers in the array
int numberOfOdds(const int *aptr, int size) {
    int count = 0;

    for (int i = 0; i < size; ++i) {
        if (*(aptr + i) % 2 != 0) {
            count++;
        }
    }

    return count;
}