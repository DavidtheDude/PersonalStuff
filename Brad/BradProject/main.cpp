
#include <iostream>
#include <string>
#include "GameClock.h"
#include "Dice.h"
using namespace std;

enum class Noun
{
   // Interrogation subjects
   name,                   // ask the subject his name
   base,                   // where is the rebel base?
   attack,                 // when will the attack be?
   suspect,                // The person you're interrogating
   invalid
};
enum class Verb
{
    ask,        // ask a question
    quit,       // quit the game
    look,       // look at a thing
    invalid     // verb was invalid

};

std::map < std::string, Noun > knownNouns = 
        {
        {   "name",         Noun::name          },
        {   "base",         Noun::base          },
        {   "attack",       Noun::attack        },
        {   "suspect",      Noun::suspect       }

        };
    std::map < std::string, Verb > knownVerbs = 
    {   
        {   "ask",      Verb::ask       },  // ask
        {   "quit",     Verb::quit      },  // quit
        {   "exit",     Verb::quit      },
        {   "look",     Verb::look      },  // look
        {   "examine",  Verb::look      }

    }; 
struct Suspect_s {                      // Defines the suspect's statistics.     
    // The likelihood the suspect will take a certain action.
    int     minimize,       ///< give minimum amount of cooperation, delay tactic
            silence,        ///< ignore interrogation
            distort,        ///< misinformation, with some truth
            distract;       ///< distract
    // primary three responses
    int     comply,         ///< answer at all
            honest,         ///< be honest
            deception;      ///< be deceptive
    // other modifiers
    int     exhaustion,     ///< tired
            pain,           ///< result of torture
            hatred;         ///< hatred, willingness to do anything to deny information
};
Suspect_s suspect;

// FUNCTION DECLARATIONS
        // go here

Noun parseNoun(std::string &);
Verb parseVerb(const std::string &);
int verbProc (Noun noun, Verb verb);
void ask (Noun noun);
void ask (Noun noun);
void look (Noun noun);
char validateInput (Verb verb, Noun noun);
void localPause ();
void readInput (char* &command, const int MAXL, std::string &noun, std::string &verb);
char verifyExit(char exitChoice);
void initializeSuspect();
void introduction();
void printLine(std::string filename, int line);
void cmd_ask_name();
void cmd_look_suspect();

    const int MAXL = 50;    // maximum character array length

int main() 
{
    // Main Variables.
    


    char    command[MAXL];          // character array to store user command
    char    *ptrcmd = command;      // character pointer to read user command
    string  noun;                   // user gives me a noun
    string  verb;                   // user gives me a verb
    Noun    pNoun;                  // A parsed out noun, associated with an enum
    Verb    pVerb;                  // A parsed out verb, associated with an enum
    char    control;                // Control / Command Character
    // Classes and Structures
    Gameclock clock;        // tracks time, tick time down using clock.downtick(loss);
    
    clock.initialize();
    initializeSuspect();
    
    introduction();
       
    do {
        cout << "\nTime remaining: " << clock.currtime() << " turns.";
        readInput(ptrcmd,MAXL,noun,verb);       // take a command from the user and prepare it for parsing
        clock.downtick(1);                      // decrement the clock
        pNoun = parseNoun(noun);                // parse the noun
        pVerb = parseVerb(verb);                // now parse the verb
        control = validateInput(pVerb,pNoun);   // validate the input
        if (control == 'X') {                   // if input is invalid, say so...
            cout << "I'm sorry, I don't know how to \"" << ptrcmd << ".\"" << endl;
            clock.downtick(-1);                 // ... and don't run out the clock for bad input.
        } else if (control == 'E') {            // if an exit condition is detected, then exit the game
            cout << "\nExiting the game..." << endl;
            return 0;    
        } else {
            verbProc(pNoun,pVerb);              // if input is valid, process it
        }
                   
    } while (clock.currtime() > 0);
    
}
Noun parseNoun(std::string &noun)
    {
        auto n = knownNouns.find(noun);
        if ( n == knownNouns.end() ) {
            return Noun::invalid;
        }
        return n->second;
    }

Verb parseVerb(const std::string &abcd){
    
        std::string n = knownVerbs.find(abcd);
        if ( n == knownVerbs.end() ) {
        return Verb::invalid;
    }
}
int verbProc (Noun noun, Verb verb){
    switch (verb) {
        case Verb::ask:     ask(noun);
        case Verb::look:    look(noun);
    }
    return 0;
}
void ask (Noun noun) 
{
    switch (noun) {
        case Noun::name:    cmd_ask_name();    // "ask name"
        case Noun::base:    break;
        case Noun::attack:  break;
        case Noun::suspect: break;
        default:            cout << "\nYou should think of a better question." << endl;
        
    }
}
void look (Noun noun)
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
char validateInput (Verb verb, Noun noun)
{
    char exitChoice = 'n';
    if (verb == Verb::invalid) {
        return('X');
    } else if (verb == Verb::quit) {
        return(verifyExit(exitChoice));
    }
    if (noun == Noun::invalid) {
        return('X');
    }
    return('0');
}

void localPause ()
{
        cout << endl;
        cin.ignore();
        cout << "Press [ENTER] to continue...";
        cin.get();
        cout << endl;
}

void readInput (char* &command, const int MAXL, string &noun, string &verb) // take in the user's command
{
    int     i = 0;      ///< iterator 1
    int     n = 0;      ///< iterator 2
    
    char    cstrnoun[MAXL];         ///< cstring for the inbound noun
    char    cstrverb[MAXL];         ///< cstring for the inbound verb
    char    *nounptr = cstrnoun;    // cstring pointer, noun
    char    *verbptr = cstrverb;    // cstring pointer, verb
    int     inputLength;            // total length of the string
        
    cin.clear();
    cout    << "\nPlease enter your command. Use a verb followed by a noun such as 'ask name.'" << endl
            << "> ";
    cin.getline(command,MAXL);          ///< get your command
    inputLength = cin.gcount();         ///< how long was last input?
    cout    << "\nYour command was: " << command << endl;
       
    // Parse the command into a noun or a verb.
    
    do {
        cstrverb[i]=command[i];        
        i++;
    } while (command[i] != ' ');
    cstrverb[i] = '\0';             // place a delimiter character at the end of the noun
    i++;
    
    do {
        cstrnoun[n]=command[i];
        i++;
        n++;
    } while (i < inputLength);
    for (i=0;i<n;i++) {
        if (cstrnoun[i]==' ') {
            cstrnoun[i] = '\0';
            i=n;
        }
    }          
    noun = nounptr;
    verb = verbptr;
}

char verifyExit(char exitChoice)
{
    bool loop = true;
    cout    << "\nAre you sure you want to quit? You will lose all progress! [Y/N]" << endl
            << "> ";
    cin     >> exitChoice;
    do {
        switch (exitChoice) {
            case 'y':   return('E');
            case 'Y':   return('E');
            case 'n':   return('0');
            case 'N':   return('0');
        }
    } while (loop);
    return ('0');
}
    
void initializeSuspect()
{
    Dice dice;
    
    suspect.minimize    = 50 + dice.roll(50);
    suspect.silence     = 50 + dice.roll(50);
    suspect.distort     = 50 + dice.roll(50);
    suspect.distract    = 50 + dice.roll(50);
    suspect.comply      = dice.roll(10);
    suspect.honest      = dice.roll(10);
    suspect.deception   = dice.roll(10);
    
    // debug
    cout    << "Minimize: " << suspect.minimize
            << "Silence:  " << suspect.silence;
}

void introduction()
{
    cmd_look_suspect();
}

void printLine(string filename, int line)
{
    char        descrip[11][500] = {0};
    char        *ch_arr = descrip[0];
    fstream     text;
    int         y = 0;
    
    cout << "\nfile: " << filename << " line: " << line << endl;
    
    text.open(filename,ios::in);
    if (!text.is_open()) {         
        cout << "\nCould not open " << filename << "." << endl;
    } else {
        while (!text.eof())
        {
            ch_arr = descrip[y];
            text.getline(ch_arr,500);
            y++;
        }                
    }
    text.close();
    ch_arr = descrip[line];
    cout    << " " << ch_arr << endl;
        
}
// SYNTAX cmd_[noun]_[verb] ()

// ask
void cmd_ask_name() {       // ask name
    Dice dice;
    int result;
    result = dice.roll(100);
    if ((suspect.silence - suspect.comply - suspect.exhaustion) > result) {
        cout << "\nThe suspect sits there quietly." << endl;
    } else if ((suspect.silence - suspect.comply - suspect.exhaustion) <= result) {
        result = dice.roll(100);
        if (result > (suspect.deception - suspect.exhaustion)) {
            cout << "He gives you his real name!" << endl;
        } else {
            cout << "He lies about his name." << endl;
        }
    }
    suspect.exhaustion++;                
}
        
// look
void cmd_look_suspect()     // look suspect
{
    int         statePosture;
    string      descfile;
    
    // Pull statePosture line from suspect_posture.txt.
    statePosture    = ((suspect.comply + suspect.silence) / 20);
    descfile        = "suspect_posture.txt";
    
    printLine(descfile,statePosture);
    
}








