/* 
 * File:   LstatClass.h
 * Author: David
 *
 * Created on November 7, 2014, 6:45 PM
 */

#ifndef LSTATCLASS_H
#define	LSTATCLASS_H
#include <list>
#include <algorithm>
#include <map>

class LstatClass {
public:
    LstatClass();
    LstatClass(const LstatClass& orig);
    virtual ~LstatClass();
    void fmin(std::list<int>);
    void fmax(std::list<int>);
    void faverage(std::list<int>);
    void fmode(std::list<int>);
    int rmin();
    int rmax();
    float raverage();
    std::map<int, int> rmode();
private:
    int min;
    int max;
    float average;
    std::map<int, int> mode;
};

#endif	/* LSTATCLASS_H */

