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

    int file_contents_number, j = 0;
    unsigned long long user_input, total_number;
    
    char fibonacci_method, file_name[50], file_contents[1000];

    FILE *open_file;

    // User input integer
    sscanf(argv[1], "%d", &user_input);

    // Iterative or recursive method
    fibonacci_method = argv[2][0];

    // File name input
    strncpy(file_name, argv[3], sizeof(file_name));

    open_file = fopen(file_name, "r");
    if (open_file == NULL) {
        return EXIT_FAILURE;
    }

    // Read the contents of the file
    fgets(file_contents, sizeof(file_contents), open_file);

    //Isolate integer as string 
    for (int i = 0; file_contents[i] != '\0'; i++) {
        if (file_contents[i] != '"') {
            file_contents[j++] = file_contents[i];

        }
    }
    file_contents[j] = '\0';

    file_contents_number = atoi(file_contents);

    total_number = user_input + file_contents_number;

    if (fibonacci_method == 'i') {
        printf("%lld", iterative_fibonacci(total_number));
    } else {
        printf("%lld", recursive_fibonacci(total_number));
    }

    fclose(open_file);
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

