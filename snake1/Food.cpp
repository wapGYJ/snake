#include "Food.h"
#include <cstdlib>
#include <ctime>
#include"common.h"
Food::Food() {
    srand(time(0));  
    generateNewPosition(); 
}
Food::~Food() {
   
}
int Food::getX() const {
    return x;
}

int Food::getY() const {
    return y;
}

void Food::generateNewPosition() {
    x = rand() % (GRID_SIZE-5)+2;
    y = rand() % (GRID_SIZE-5)+2;
}