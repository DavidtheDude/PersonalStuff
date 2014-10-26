/* 
 * File:   verbs.h
 * Author: Bradley Evans
 *
 * Created on October 18, 2014, 8:39 PM
 */

#ifndef VERBS_H
#define	VERBS_H

#include <iostream>
#include <map>
#include <string>

#include "nouns.h"
#include "classes.h"
#include "functions.h"
#include "cmdtree.h"

/*
 * See the nouns.h header for better documentation on what exactly this
 * is doing.
 */
class Verbs{
private:
    enum class Verb
    {
        ask,        // ask a question
        quit,       // quit the game
        look,       // look at a thing
        invalid     // verb was invalid

    };
    std::map < std::string, Verb > knownVerbs;
public:
    Verbs();
    Verb parseVerb(const std::string &abcd){
        std::string n = knownVerbs.find(abcd);
        if ( n == knownVerbs.end() ) {
        return Verb::invalid;
    }
    };

    int verbProc (Nouns noun, Verbs verb);
    
    

    
                                              

};
#endif	/* VERBS_H */

