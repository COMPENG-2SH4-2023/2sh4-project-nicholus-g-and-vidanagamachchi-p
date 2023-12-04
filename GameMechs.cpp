#include "GameMechs.h"
#include "MacUILib.h"

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
    if (MacUILib_hasChar()) 
    {  // Check if there is input
        char newinput = MacUILib_getChar(); // Get the input from the UI library
        setInput(newinput);  // Set the input in the GameMechs object

        // Check for the 'Q' or 'q' key to exit the game
        if (input == 'Q' || input == 'q') 
        {
            exitFlag = true; // Set the exit flag to true
        }
    }
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


