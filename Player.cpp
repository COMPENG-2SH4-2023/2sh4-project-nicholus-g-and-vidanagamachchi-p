#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;
    symbol = '*';

    // more actions to be included
    // Set playerPos to the center of the board
    playerPos.x = mainGameMechsRef->getBoardSizeX() / 2;
    playerPos.y = mainGameMechsRef->getBoardSizeY() / 2;
}


Player::~Player()
{
    // delete any heap members here
}

void Player::getPlayerPos(objPos &returnPos)
{
    // return the reference to the playerPos array list
    returnPos = playerPos;
}

void Player::updatePlayerDir()
{
    // PPA3 input processing logic   
    char input = mainGameMechsRef->getInput();  
    if (input != 0) 
    {  // if not null character
        switch (input) 
        {
            case ' ':  // exit
                mainGameMechsRef->setExitTrue();  
                break;
            case 'w':
            case 'W':
                if (myDir == LEFT || myDir == RIGHT || myDir == STOP) 
                {
                    myDir = UP;
                }
                break;
            case 'a':
            case 'A':
                if (myDir == UP || myDir == DOWN || myDir == STOP) 
                {
                    myDir = LEFT;
                }
                break;
            case 's':
            case 'S':
                if (myDir == LEFT || myDir == RIGHT || myDir == STOP) 
                {
                    myDir = DOWN;
                }
                break;
            case 'd':
            case 'D':
                if (myDir == UP || myDir == DOWN || myDir == STOP) 
                {
                    myDir = RIGHT;
                }
                break;
        }
        mainGameMechsRef->clearInput();  
    }     
}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
    switch (myDir) 
    {
        case UP:
            playerPos.y -= 1;
            break;
        case DOWN:
            playerPos.y += 1;
            break;
        case LEFT:
            playerPos.x -= 1;
            break;
        case RIGHT:
            playerPos.x += 1;
            break;
        case STOP:
            // No movement for STOP
            break;
    }
    wrapPosition();
}

void Player::wrapPosition() 
{
    int boardSizeX = mainGameMechsRef->getBoardSizeX();  
    int boardSizeY = mainGameMechsRef->getBoardSizeY();  

    // Implement wrap-around logic as shown in PPA3
    if (playerPos.x < 1) 
    {
        playerPos.x = boardSizeX - 2;
    } 
    else if (playerPos.x >= boardSizeX - 1) 
    {
        playerPos.x = 1;
    }
    if (playerPos.y < 1) 
    {
        playerPos.y = boardSizeY - 2;
    } 
    else if (playerPos.y >= boardSizeY - 1) 
    {
        playerPos.y = 1;
    }
}

