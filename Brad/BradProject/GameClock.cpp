/* 
 * File:   GameClock.cpp
 * Author: David
 * 
 * Created on October 25, 2014, 10:14 PM
 */

#include "GameClock.h"
#include <string>
#include <time.h>

void Gameclock::downtick(int loss) {    ///< To decrement the time counter.
    timeleft-=loss;
}

int Gameclock::currtime() {             ///< Displays time remaining.
    return(timeleft);
}

void Gameclock::initialize() {
    srand(time(NULL));
    timeleft = 20 + (rand()%20);
}

