/* 
 * File:   Dice.cpp
 * Author: David
 * 
 * Created on October 25, 2014, 10:17 PM
 */

#include "Dice.h"
#include <ctime>
#include <time.h>

int Dice::roll (int size) {  
    int result;
    srand(clock());
    result = rand() % size;
    // Delay, to ensure the same time isn't used for each dice roll accidentally.
    clock_t start_time = clock();
    clock_t end_time = 10 + start_time;
    do { /* nothing */ } while ( clock() < end_time);
    return(result);
}