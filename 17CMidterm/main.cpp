/* 
 * File:   main.cpp
 * Author: David
 *
 * Created on November 6, 2014, 2:08 PM
 * 1)  Vector - Fill a vector with random inputs.  Write a function
                vector *top(vector x,int p) that returns in a
                vector the top p elements of the x input vector.
 * 
 * 3)  Vector - Fill a vector with random inputs.  Write a function
                statClass *stat(vector x) that returns a class that
                contains the min,max and average of the x vector but
                also uses a map to solve the mode problem and returns
                the important elements for the mode.

 * 4)  List -   Try using a list that does 1)
 * 
 * 6)  List -   Try using a list that implements 3)
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include <ctime>
#include <list>
#include <map>
#include <string>
#include <iomanip>
#include "statClass.h"
#include "LstatClass.h"

using namespace std;
void problem1();
void problem3();
void problem4();
void problem6();

vector <int> *top2(vector<int>, int);
list <int> *top4(list<int>, int);
statClass *stat(vector<int> x);
LstatClass *lstat(list<int> x);

/*
 * 
 */
int main(int argc, char** argv) {
    char k;
    do {
        cout << "Enter the problem you would like to view" << endl;
        cout << "1. Problem 1" << endl;
        cout << "3. Problem 3" << endl;
        cout << "4. Problem 4" << endl;
        cout << "6. Problem 6" << endl;
        cout << "0 to end" << endl;

        cin >> k;
        switch (k) {
            case '1': problem1();
                break;
            case '3': problem3();
                break;
            case '4': problem4();
                break;
            case'6': problem6();
        }
        cout << endl;
        cin.ignore();
    } while (k != 0);

    return 0;
}

void problem6(){
    unsigned seed = time(0);
    srand(seed);
    list <int> x;
    int iNum = rand() % 40 + 10; //random amount of inputs

    for (int i = 0; i < iNum; i++) {
        x.push_back(rand() % 10 + 1); //filling the vector
    }
    cout<<"Data: ";
    for(int i=0; i<x.size(); i++){
        cout<<x.front()<<" ";
        x.push_back(x.front());
        x.pop_front();
    }
    cout<<endl;
    LstatClass *k = lstat(x);
    
    std::map<int, int> mode = k->rmode();
    int min = k->rmin();
    int max = k->rmax();
    float average = k->raverage();
    cout << "Min: " << min << endl;
    cout << "Max: " << max << endl;
    cout << "Average: " << average << fixed << setprecision(2) << endl;
    cout << "Mode Data: "<<endl;
    for (std::map<int, int>::iterator iter = mode.begin(); iter != mode.end(); ++iter) {
        cout << iter->first << " occurred " << iter->second << endl;
    }
}

void problem3() {
    unsigned seed = time(0);
    srand(seed);
    vector <int> x;
    int iNum = rand() % 40 + 10; //random amount of inputs

    for (int i = 0; i < iNum; i++) {
        x.push_back(rand() % 10 + 1); //filling the vector
    }
    cout<<"Data: ";
    for(int i=0; i<x.size(); i++)
        cout<<x[i]<<" ";
    cout<<endl;
    statClass *k = stat(x);
    
    std::map<int, int> mode = k->rmode();
    int min = k->rmin();
    int max = k->rmax();
    float average = k->raverage();
    cout << "Min: " << min << endl;
    cout << "Max: " << max << endl;
    cout << "Average: " << average << fixed << setprecision(2) << endl;
    cout << "Mode Data: "<<endl;
    for (std::map<int, int>::iterator iter = mode.begin(); iter != mode.end(); ++iter) {
        cout << iter->first << " occurred " << iter->second << endl;
    }
}

void problem4() {
    unsigned seed = time(0);
    srand(seed);
    list<int> x;
    list<int>::iterator iter;
    int iNum = rand() % 100 + 1; //random amount of inputs
    unsigned seed1 = time(0);
    srand(seed1);
    int p = rand() % 20 + 1; //amount of "top" elements of the x input vector

    for (int i = 0; i < iNum; i++) {
        x.push_back(rand() % 1000 + 1); //filling the vector
    }
    list <int> *k = top4(x, p); //pointer list

    cout << "Index:    " << iNum << endl;
    cout << "Original: "; //output
    int count = 0;
    for (iter = x.begin(); iter != x.end(); iter++) {
        cout << *iter << " ";
        count++;
        if (count == 20) {
            cout << endl << "          ";
            count = 0;
        }
    }
    cout << endl;
    cout << "P:        " << p << endl;
    cout << "Top:      ";
    for (iter = k->begin(); iter != k->end(); iter++) {
        cout << *iter << " ";
    }
    cout << endl;
    //deletions
    k->erase(k->begin(), k->end());
}

void problem1() {
    unsigned seed = time(0);
    srand(seed);
    vector <int> x;
    int iNum = rand() % 100 + 1; //random amount of inputs
    unsigned seed1 = time(0);
    srand(seed1);
    int p = rand() % 20 + 1; //amount of "top" elements of the x input vector

    for (int i = 0; i < iNum; i++) {
        x.push_back(rand() % 1000 + 1); //filling the vector
    }
    vector <int> *k = top2(x, p); //pointer vector

    cout << "Index:    " << iNum << endl; //index
    cout << "Original: "; //output
    int count = 1;
    for (int i = 0; i < iNum; i++) { //outputting original
        cout << x[i] << " ";
        count++;
        if (count == 20) {
            cout << endl << "          ";
            count = 0;
        }
    }
    cout << endl;
    cout << "P:        " << p << endl; //top of stack
    cout << "Top:      ";
    for (int i = 0; i < p; i++) {
        cout << (*k)[i] << " ";
    }
    cout << endl;
    //deletions
    k->erase(k->begin(), k->end());
}

LstatClass *lstat(list<int> x){
    LstatClass *k = new LstatClass;
    k->faverage(x);
    k->fmax(x);
    k->fmin(x);
    k->fmode(x);
    return k;
}

statClass *stat(vector<int> x) {
    statClass *k = new statClass;
    k->faverage(x);
    k->fmax(x);
    k->fmin(x);
    k->fmode(x);
    return k;
}

list <int> *top4(list<int> x, int p) {
    list <int> *k = new list<int>;
    for (int i = 0; i < p; i++) {
        k->push_back(x.front());
        x.pop_front();
    }
    return k;
}

vector<int> *top2(vector<int> x, int p) {
    vector <int> *k = new vector<int>;
    for (int i = 0; i < p; i++) {
        k->push_back(x.at(i));
    }
    return k;
}



