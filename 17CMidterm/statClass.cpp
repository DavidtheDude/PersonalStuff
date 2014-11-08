/* 
 * File:   statClass.cpp
 * Author: David
 * 
 * Created on November 6, 2014, 9:24 PM
 */

#include "statClass.h"

statClass::statClass() {
}

statClass::statClass(const statClass& orig) {
}

statClass::~statClass() {
}

int statClass::rmin() {
    return min;
}

void statClass::fmin(std::vector<int> x) {
    min = x[0];
    for (int i = 1; i < x.size(); i++) {
        if (min > x[i])
            min = x[i];
    }
}

int statClass::rmax() {
    return max;
}

void statClass::fmax(std::vector<int> x) {
    max = x[0];
    for (int i = 1; i < x.size(); i++) {
        if (max < x[i])
            max = x[i];
    }
}

float statClass::raverage() {
    return average;
}

void statClass::faverage(std::vector<int> x) {
    int sum = 0;
    for (int i = 0; i < x.size(); i++) {
        sum += x[i];
    }
    average = (float) sum / x.size();
}

std::map<int, int> statClass::rmode() {
    return mode;
}

void statClass::fmode(std::vector<int> x) {
    //initialize
    //size of map
    mode[x[0]] = 0;
    bool exists = false;
    /***************************************************
     *adding to the map if the number does not exist yet*
     **************************************************/
    //step through vector
    for (int i = 0; i < x.size(); i++) {
        //check if the current vector number is already in the map
        if (mode.find(x[i]) != mode.end()) {
            exists = true;
            int k = mode.find(x[i])->second;
            k++;
            mode.find(x[i])->second = k;
        } else
            exists = false;
        //if it doesn't exist then add it to the map
        if (exists != true) {
            mode[x[i]] = 1;
        }
    }
}

