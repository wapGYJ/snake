#ifndef SNAKE_H
#define SNAKE_H

#define MAX_BODY_LENGTH 100  // 假设蛇的最大长度

class Snake {
public:
    Snake();  // 构造函数
    int getHeadX() const;  // 获取蛇头 x 坐标
    int getHeadY() const;  // 获取蛇头 y 坐标
    void changeDirection(int x, int y);  // 改变蛇的移动方向
    void move(int foodX, int foodY);  // 移动蛇，并检查是否吃到食物
    bool checkCollision() const;  // 检查是否发生碰撞
    int length;  // 蛇的长度
    int x[MAX_BODY_LENGTH];  // 蛇身体每节的 x 坐标
    int y[MAX_BODY_LENGTH];  // 蛇身体每节的 y 坐标


private:
   
    int directionX;  // 蛇移动的方向 x 分量
    int directionY;  // 蛇移动的方向 y 分量
};

#endif 
