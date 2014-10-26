/* 
 * File:   GameClock.h
 * Author: David
 *
 * Created on October 25, 2014, 10:14 PM
 */

#ifndef GAMECLOCK_H
#define	GAMECLOCK_H

class Gameclock {                       ///< Tracks in game time remaining
        int timeleft;
    public:
        void downtick(int);
        int currtime();
        void initialize();
};

#endif	/* GAMECLOCK_H */

