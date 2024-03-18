
/*
Write a program lab6 - cal - everything.c which accepts two non - zero interger numbers a and b.The program returns the result of the following calculation line by line :

Sum a + b

Difference a - b

Product a * b

Devision a / b

Power a ^ b

Natural Logarithm log(a) + log(b)

Keep two digits after the decimal point.You may need the library math.h to solve this task.Also, you need to find a way to use function pointer instead of just calling every function.

Example:

Input:

. / lab5 - cal - everything 10 2

Output :

    12.00
    8.00
    20.00
    5.00
    100.00
    3.00
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct sum Sum;

struct sum {
    int a, b;
    int sum = a + b;
};

Sum &getSum(){
    static Sum p = { 3, 4 };
    return p;
}

int main(int argc, char** argv) {
    
    Sum &getSum = getSum();

    printf(""
    
    return 0;
}
