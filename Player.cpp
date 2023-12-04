#include "Player.h"
#include <iostream>

Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    objPos tempPos;
    tempPos.setObjPos(mainGameMechsRef->getBoardSizeX() / 2,
                      mainGameMechsRef->getBoardSizeY() / 2,
                        '*');

    // more actions to be included ----> can write in simpler way
    playerPosList = new objPosArrayList();
    playerPosList->insertHead(tempPos);
}

Player::~Player()
{
    // delete any heap members here
    delete playerPosList;
}

objPosArrayList* Player::getPlayerPos()
{
    // return the reference to the playerPos arrray list
    return playerPosList;
}

void Player::updatePlayerDir()
{
    // PPA3 input processing logic    
    char control = mainGameMechsRef->getInput();
    std::cout << "Input received: " << control << std::endl; // Debug statement

if(control != 0)
{
    switch(control)
    {
        case 'W':
        case 'w':
            if(myDir != UP && myDir != DOWN)
                myDir = UP;
            break;
        case 'A': 
        case 'a':
            if(myDir != LEFT && myDir != RIGHT)
                myDir = LEFT;
            break;
        case 'S':
        case 's':
            if(myDir != UP && myDir != DOWN)
                myDir = DOWN;
            break;
        case 'D':
        case 'd':
            if(myDir != LEFT && myDir != RIGHT)
                myDir = RIGHT;
            break;
        default:
            break;
    }    
     std::cout << "Direction after input: " << myDir << std::endl; // Debug statement

}
}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
   
    objPos currentHead; //holds pos information of current head
    playerPosList->getHeadElement(currentHead);
    std::cout << "Current head before move: " << currentHead.x << ", " << currentHead.y << std::endl; // Debug statement


    switch(myDir)
    {
        case UP:
            currentHead.y--;
            if(currentHead.y <= 0) //wraparound logic
                currentHead.y = mainGameMechsRef -> getBoardSizeY() - 2;
            break;
        case DOWN:
            currentHead.y++;
            if(currentHead.y >= mainGameMechsRef->getBoardSizeY()) //wraparound logic
                currentHead.y = 1;
            break;
        case LEFT:
            currentHead.x--;
            if(currentHead.x <= 0)
                currentHead.x = mainGameMechsRef->getBoardSizeX() - 2;
            break;
        case RIGHT:
            currentHead.x++;
            if(currentHead.x >= mainGameMechsRef->getBoardSizeX())
                currentHead.x = 1;
            break;
        case STOP:
        default:
            break;
       

    }
    std::cout << "New head after move: " << currentHead.x << ", " << currentHead.y << std::endl; // Debug statement
    playerPosList->insertHead(currentHead);
    playerPosList->removeTail();
}


