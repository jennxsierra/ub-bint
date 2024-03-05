#include <iostream>

int sum_from_to(int,int);

int main()
{
    std::cout << sum_from_to(4,7) << std::endl;
    std::cout << sum_from_to(-3,1) << std::endl;
    std::cout << sum_from_to(7,4) << std::endl;
    std::cout << sum_from_to(9,9) << std::endl;

    return 0;
}

int sum_from_to(int first,int last) {
    int num;
    int sum = 0;

    if(first < last) {
        num = first;
        while(num <= last) {
            if(num % 2 != 0) {
                sum += num;
            }
            num++;
        }
    } else if (last < first) {
        num = last;
        while(num <= first) {
            if(num % 2 != 0) {
                sum += num;
            }
            num++;
        }
    } else {
        sum = first;
    }

    return sum;
}
