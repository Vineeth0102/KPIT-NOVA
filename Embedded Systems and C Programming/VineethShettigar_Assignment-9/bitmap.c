#include "bitmap.h"

/*
    
   The function should return the total value as per conditions defined below.

    Total reward points are calculated for every step number between minimum 
    and maximum step count, with the following rules:

●	If the difference between maximum and minimum steps recorded is less than 5,  
    total rewards are equal to the sum of all numbers between minimum and maximum step numbers (both inclusive).

●	If the difference between minimum and maximum is over 5, following rules are applicable
        a.	For every odd number divisible by 5, number times 5 is added to the total rewards. 
            If the number is divisible by 7, the square of the number is added to the total if the 
            number is at least twice the minimum step count else only 7 is added to the total.
        b.	If the number is divisible by both 5 and 7, 35 is added to the total.
        c.	For every even number which is a power of 2 (e.g 2, 4, 8, 16, etc), number times 10 
            is added to the total. If the number is divisible by both 4 and 8, 32 is added to the total



*/

struct Limits {
    unsigned short minimum;
    unsigned short maximum;
};

int isPowerOfTwo(unsigned short n) {
    return (n && !(n & (n - 1)));
}



int calculateTotalRewards(struct Limits values) {
    unsigned short min = values.minimum;
    unsigned short max = values.maximum;
    int totalRewards = 0;

    if (max - min < 5) {
        for (unsigned short i = min; i <= max; i++) {
            totalRewards += i;
        }
    } else {
        for (unsigned short i = min; i <= max; i++) {
            if (i % 5 == 0 && i % 7 == 0) {
                totalRewards += 35;
            } else if (i % 5 == 0) {
                if (i % 7 == 0) {
                    if (i >= 2 * min) {
                        totalRewards += i * i;
                    } else {
                        totalRewards += 7;
                    }
                } else {
                    totalRewards += i * 5;
                }
            } else if (isPowerOfTwo(i)) {
                if (i < 10) {
                    totalRewards += i * 10;
                } else if (i % 4 == 0 && i % 8 == 0) {
                    totalRewards += 32;
                }
            }
        }
    }

    return totalRewards;
}
