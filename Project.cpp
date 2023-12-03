#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"


using namespace std;

#define DELAY_CONST 100000

// Declare a pointer to a GameMechs object globally
GameMechs* gameMechanics = nullptr;
Player* player = nullptr;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();
    while (!gameMechanics->getExitFlagStatus())  
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
    gameMechanics = new GameMechs(); // Initialize the GameMechs object
    player = new Player(gameMechanics);
    gameMechanics->setExitFalse();   // Ensure the exit flag is initially false
}

void GetInput(void)
{
   if (MacUILib_hasChar()) {  // Check if there is input
        char input = MacUILib_getChar(); // Get the input from the UI library
        gameMechanics->setInput(input);  // Set the input in the GameMechs object

        // Check for the 'Q' or 'q' key to exit the game
        if (input == 'Q' || input == 'q') 
        {
            gameMechanics->setExitTrue(); // Set the exit flag to true
        }
    }
}

void RunLogic(void)
{
    
}

void DrawScreen(void)
{
    MacUILib_clearScreen();    

    if (gameMechanics->getLoseFlag()) 
    {
        cout << "Game Over! You have lost." << endl;
    }
   
    objPos playerPosition;
    player->getPlayerPos(playerPosition); 

    // Draw the game border and objects
    for (int i = 0; i < gameMechanics->getBoardSizeY(); ++i) {
        for (int j = 0; j < gameMechanics->getBoardSizeX(); ++j) {
            if (i == 0 || i == gameMechanics->getBoardSizeY() - 1 || j == 0 || j == gameMechanics->getBoardSizeX() - 1) 
            {
                cout << '#';
            } else if (i == playerPosition.y && j == playerPosition.x) 
            {
                cout << playerPosition.getSymbol(); 
            } 
            else 
            {
                
                cout << ' ';
            }
        }
        cout << endl;
    }
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();

    delete player; 
    player = nullptr;

    delete gameMechanics;
    gameMechanics = nullptr;
    MacUILib_uninit();
}
