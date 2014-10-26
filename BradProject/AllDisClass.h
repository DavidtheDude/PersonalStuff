/* 
 * File:   AllDisClass.h
 * Author: David
 *
 * Created on October 25, 2014, 10:23 PM
 */

#ifndef ALLDISCLASS_H
#define	ALLDISCLASS_H

class AllDisClass {
public:
    AllDisClass();
    AllDisClass(const AllDisClass& orig);
    virtual ~AllDisClass();
private:
    enum class Noun
     {
        // Interrogation subjects
        name,                   // ask the subject his name
        base,                   // where is the rebel base?
        attack,                 // when will the attack be?
        suspect,                // The person you're interrogating

        invalid
    };

};

#endif	/* ALLDISCLASS_H */

