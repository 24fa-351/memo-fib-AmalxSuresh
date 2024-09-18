#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define ARRAY_BUFFER 100

unsigned long long fib_array[ARRAY_BUFFER] = { 0 }; //declare array

unsigned long long iterative_fibonacci_provider (unsigned long long input);
unsigned long long recursive_fibonacci_provider (unsigned long long input);
unsigned long long iterative_fibonacci(unsigned long long input);
unsigned long long recursive_fibonacci(unsigned long long input);

int main(int argc, char *argv[]) {
    //get rid of compiler error for not using argc parameter
    (void)argc;

    unsigned long long user_input;
    
    char fibonacci_method;

    // User input integer
    sscanf(argv[1], "%lld", &user_input);

    // Iterative or recursive method
    fibonacci_method = argv[2][0];

    if (fibonacci_method == 'i') {
        printf("%lld", iterative_fibonacci(user_input));
    } else {
        printf("%lld", recursive_fibonacci(user_input));
    }

    return 0;
}

unsigned long long iterative_fibonacci_provider (unsigned long long input) {
    unsigned long long previous_one = 1, previous_two = 0, num = 0;

    for (int i = 0; i <= input; i++) {
       if (i > 2) {
          num = previous_one + previous_two;
          previous_two = previous_one;
          previous_one = num;
       }
    }
    return num;
}

unsigned long long iterative_fibonacci (unsigned long long input) {
    fib_array[2] = 1; //base case for fib(2) needs manual declaration

    if(input <= 2 || fib_array[input] != 0) {
        return fib_array[input];
    }
    else {
        fib_array[input] = iterative_fibonacci_provider(input);
        return fib_array[input];
    }
}

unsigned long long recursive_fibonacci_provider (unsigned long long input) { 
    if (input == 1) {
       return 0;
    }
    else if (input == 2) {
       return 1;
    }
    else {
        return recursive_fibonacci (input-1) + recursive_fibonacci (input-2); //put values in the array
    }
}

unsigned long long recursive_fibonacci(unsigned long long input) {
    fib_array[2] = 1; //base case for fib(2) needs manual declaration

    if(input <= 2 || fib_array[input] != 0) { //return fibbed value if it's already in array
        return fib_array[input];
    }
    else {
        fib_array[input] = recursive_fibonacci_provider(input);
        return fib_array[input];
    }
}

