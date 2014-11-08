/* 
 * File:   LstatClass.cpp
 * Author: David
 * 
 * Created on November 7, 2014, 6:45 PM
 */

#include "LstatClass.h"

LstatClass::LstatClass() {
}

LstatClass::LstatClass(const LstatClass& orig) {
}

LstatClass::~LstatClass() {
}

int LstatClass::rmin() {
    return min;
}

void LstatClass::fmin(std::list<int> x) {
    min = x.front();
    x.erase(x.begin());
    int size = x.size();
    for (int i = 1; i < size; i++) {
        if (min > x.front())
            min = x.front();
        x.erase(x.begin());
    }
}

int LstatClass::rmax() {
    return max;
}

void LstatClass::fmax(std::list<int> x) {
    max = x.front();
    x.erase(x.begin());
    int size = x.size();
    for (int i = 1; i < size; i++) {
        if (max < x.front())
            max = x.front();
        x.erase(x.begin());
    }
}

float LstatClass::raverage() {
    return average;
}

void LstatClass::faverage(std::list<int> x) {
    int sum = 0;
    for (int i = 0; i < x.size(); i++) {
        sum += x.front();
        x.erase(x.begin());
    }
    average = (float) sum / x.size();
}

std::map<int, int> LstatClass::rmode() {
    return mode;
}

void LstatClass::fmode(std::list<int> x) {
    //initialize
    //size of map
    mode[x.front()] = 0;
    bool exists = false;
    int size = x.size();
    /***************************************************
     *adding to the map if the number does not exist yet*
     **************************************************/
    //step through list
    for (int i = 0; i < size; i++) {
        //check if the current list number is already in the map
        if (mode.find(x.front()) != mode.end()) {
            exists = true;
            mode.find(x.front())->second++;
        } else
            exists = false;
        //if it doesn't exist then add it to the map
        if (exists != true) {
            mode[x.front()] = 1;
        }
        x.erase(x.begin());
    }
}

