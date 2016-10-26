/**
 * generate.c
 *
 * CS50 AP
 * Problem 3-6
 *
 * Generates pseudorandom numbers in [0,LIMIT), one per line.
 *
 * Usage: generate n [s]
 *
 * where n is number of pseudorandom numbers to print
 * and s is an optional seed
 */
 
#define _XOPEN_SOURCE

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// constant
#define LIMIT 65536

int main(int argc, string argv[])
{
    // exits the code and gives the usage of the program if the user inputs
    // anything other than 2 or 3 arguments
    if (argc != 2 && argc != 3)
    {
        printf("Usage: generate n [s]\n");
        return 1;
    }

    // converts the second argument to an integer
    int n = atoi(argv[1]);

    // if there is a seed, changes that seed to a long int,
    // then seeds the prng with that number
    if (argc == 3)
    {
        srand48((long int) atoi(argv[2]));
    }
    // if no seed is inputted, seeds the prng with the system's time
    else
    {
        srand48((long int) time(NULL));
    }

    // prints "n" amount of pseudo-random numbers
    for (int i = 0; i < n; i++)
    {
        printf("%i\n", (int) (drand48() * LIMIT));
    }

    // success
    return 0;
}