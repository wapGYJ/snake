#ifndef GAME_H
#define GAME_H

#include "Snake.h"
#include "Food.h"
#include "Common.h"  

class Game {
public:
    Game(); 
    void run();  // ÓÎÏ·Ö÷Ñ­»·

private:
    int grid[GRID_SIZE][GRID_SIZE];   
    Snake snake;  
    Food food;    

    void initialize();    
    void processInput(); 
    void update();        
    void render() const; 
    void gameOver() const;  
};

#endif 
