#include "GameMechs.h"

GameMechs::GameMechs()
{
    boardSizeX = 30;  // Default board width
    boardSizeY = 15;  // Default board height
    input = 0;        // No input
    exitFlag = false; // Game continues to run
    loseFlag = false;
}

GameMechs::GameMechs(int boardX, int boardY)
{
    boardSizeX = boardX;
    boardSizeY = boardY;
    input = 0;        // No input
    exitFlag = false; // Game continues to run
    loseFlag = false;
}

// do you need a destructor?



bool GameMechs::getExitFlagStatus()
{
    return exitFlag;
}

char GameMechs::getInput()
{
    return input;
}

int GameMechs::getBoardSizeX()
{
    return boardSizeX;
}

int GameMechs::getBoardSizeY()
{
    return boardSizeY;
}

void GameMechs::setExitTrue() 
{
    exitFlag = true;
}

void GameMechs::setExitFalse() 
{
    exitFlag = false;
}

void GameMechs::setInput(char this_input)
{
    input = this_input;
}

void GameMechs::clearInput()
{
    input = 0; // Reset input
}

void GameMechs::incrementScore(int increment) 
{
    score += increment;
}

void GameMechs::toggleLoseFlag() 
{
    loseFlag = !loseFlag;
}

bool GameMechs::getLoseFlag() const 
{ 
    return loseFlag; 
}

int GameMechs::getScore()
{ 
    return score; 
}


