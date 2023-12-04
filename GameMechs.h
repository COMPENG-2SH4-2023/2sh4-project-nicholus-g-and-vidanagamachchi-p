#ifndef GAMEMECHS_H
#define GAMEMECHS_H

#include <cstdlib>
#include <time.h>

#include "objPos.h"
#include "objPosArrayList.h"


using namespace std;


class GameMechs
{
    // Construct the remaining declaration from the project manual.

    // Only some sample members are included here

    // You will include more data members and member functions to complete your design.

    private:
        char input;
        bool exitFlag;
        
        int boardSizeX;
        int boardSizeY;

        int score = 0;
        bool loseFlag;

        //objPos foodPos;//private member for foor position

    public:
        GameMechs();
        GameMechs(int boardX, int boardY);
        
        bool getExitFlagStatus();
        void setExitTrue();
        void setExitFalse();

        char getInput();
        void setInput(char this_input);
        void clearInput();

        int getBoardSizeX();
        int getBoardSizeY();
      
        bool getLoseFlag() const;
        int getScore();
        void toggleLoseFlag();
        void incrementScore(int increment);

        /*bool isPositionInPlayerBody(const objPosArrayList* playerBody, const objPos& position) const;

        void generateFood(objPos& newFood, const objPosArrayList& playerBody);
        //need to accept the player body array list
        // go through each array list element to make sure thay are all blocked off from random food generation
        void getFoodPos(objPos& returnPos) const;*/

};

#endif