#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"


using namespace std;

#define DELAY_CONST 100000

// Declare a pointer to a GameMechs object globally
GameMechs* myGM = nullptr;
Player* myPlayer = nullptr;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();
    while (!myGM->getExitFlagStatus())  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();
    myGM = new GameMechs(); // Initialize the GameMechs object
    myPlayer = new Player(myGM);
    myGM->setExitFalse();   // Ensure the exit flag is initially false
    objPos tempPos{-1,-1,'o'}; //make shift setup to not touch generateItem yet, do this soon
    //myPlayer->getPlayerPos(tempPos);
    //myGM->generateFood(tempPos);//how to turn into arraylist operation

    }

void GetInput(void)
{
   myGM->getInput();
}

void RunLogic(void)
{
    myPlayer->updatePlayerDir();
    myPlayer->movePlayer();

    myGM->clearInput();

}

void DrawScreen(void)
{
   MacUILib_clearScreen();

    bool drawn;
    objPos playerPosition;

    objPosArrayList* playerBody = myPlayer->getPlayerPos();
    objPos tempBody;

    objPos tempFoodPos;
    //myGM -> getFoodPos(tempFoodPos);

    for(int i = 0; i < myGM->getBoardSizeY(); i++){
        for (int j = 0; j < myGM->getBoardSizeX(); j++){

            drawn = false;
           
            for(int k = 0; k < playerBody->getSize(); k++){
                playerBody->getElement(tempBody, k);
                if(tempBody.x == j && tempBody.y == i){
                    MacUILib_printf("%c", tempBody.symbol);
                    drawn = true;
                    break;
                }
            }

            if(drawn) continue;
            //drawing border
            if (i == 0 || i == myGM->getBoardSizeY() - 1 || j==0 || j == myGM->getBoardSizeX() - 1) //might be wrong
            {
                MacUILib_printf("%c", '#');
            }
           
            /*else if(j == tempFoodPos.x && i == tempFoodPos.y)
            {
                MacUILib_printf("%c", tempFoodPos.symbol);
            }*/
            else 
            {
                MacUILib_printf("%c", ' ');
            }
        }

        MacUILib_printf("\n");
    }

    MacUILib_printf("Score: %d\n", myGM->getScore());//have to update later

    //MacUILib_printf("Food Pos: <%d, %d>\n",tempFoodPos.x, tempFoodPos.y);

}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();

    delete myPlayer; 
    myPlayer = nullptr;

    delete myGM;
    myGM = nullptr;
    MacUILib_uninit();
}
