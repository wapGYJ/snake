#ifndef FOOD_H
#define FOOD_H

#include <cstdlib>
#include <ctime>

class Food {
public:
    Food(); 
    ~Food();
    int getX() const;  
    int getY() const;  
    void generateNewPosition();  // 生成新的食物位置

private:
    int x;  
    int y;  
};

#endif
