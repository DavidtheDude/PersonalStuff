#include "verbs.h"
using namespace std;

Verbs::Verbs(){
knownVerbs = 
    {   
        {   "ask",      Verb::ask       },  // ask
        {   "quit",     Verb::quit      },  // quit
        {   "exit",     Verb::quit      },
        {   "look",     Verb::look      },  // look
        {   "examine",  Verb::look      }

    };

}

/*
 * Send the verb off to be paired with nouns.
 
Verb Verbs::parseVerb(const std::string &abcd){
        std::string n = knownVerbs.find(abcd);
        if ( n == knownVerbs.end() ) {
        return Verb::invalid;
    }
 */

int Verbs::verbProc (Nouns noun, Verbs verb) {
    switch (verb) {
        case Verb::ask:     ask(noun);
        case Verb::look:    look(noun);
    }
    return 0;
}
#endif	/* VERBS_H */


