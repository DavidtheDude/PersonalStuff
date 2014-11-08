/* 
 * File:   statClass.h
 * Author: David
 *
 * Created on November 6, 2014, 9:24 PM
 */

#ifndef STATCLASS_H
#define	STATCLASS_H
#include <vector>
#include <map>
#include <algorithm>

class statClass {
public:
    statClass();
    statClass(const statClass& orig);
    virtual ~statClass();
    void fmin(std::vector<int>);
    void fmax(std::vector<int>);
    void faverage(std::vector<int>);
    void fmode(std::vector<int>);
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

#endif	/* STATCLASS_H */

