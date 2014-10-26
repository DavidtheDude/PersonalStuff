#include "nouns.h"

using namespace std;

Nouns::Nouns(){
    knownNouns = 
        {
        {   "name",         Noun::name          },
        {   "base",         Noun::base          },
        {   "attack",       Noun::attack        },
        {   "suspect",      Noun::suspect       }

        };
}

void Nouns::ask (Noun noun) 
{
    switch (noun) {
        case Noun::name:    cmd_ask_name();    // "ask name"
        case Noun::base:    break;
        case Noun::attack:  break;
        case Noun::suspect: break;
        default:            cout << "\nYou should think of a better question." << endl;
        
    }
}

void Nouns::look (Nouns noun)
{
    switch (noun) {
        case Noun::invalid: cout << "\nI don't see anything like that here." << endl;
                            break;
        case Noun::suspect: cmd_look_suspect();     // look suspect
        case Noun::attack: break; //invalid
        case Noun::base: break; //invalid
        case Noun::name: break; //invalid
    }
}

