#include "Snake.h"
#include"common.h"
Snake::Snake() {
    // 初始化蛇在网格的中心位置
    int mid = GRID_SIZE / 2;
    x[0] = mid;
    y[0] = mid;
   x[1] = mid;
   y[1] = mid - 1;
   x[2] = mid;
   y[2] = mid - 1;
    length =3;
    directionX = 0;
    directionY = 1;  // 初始方向向右
}

int Snake::getHeadX() const {
    return x[0];
}

int Snake::getHeadY() const {
    return y[0];
}

void Snake::changeDirection(int x, int y) {
    // 确保蛇不能反向移动
    if (directionX == -x && directionY == -y) {
        return;
    }
    directionX = x;
    directionY = y;
}

void Snake::move(int foodX, int foodY) {
    // 将蛇尾部移动到蛇头的位置
    for (int i = length - 1; i > 0; --i) {
        x[i] = x[i - 1];
        y[i] = y[i - 1];
    }

    // 根据当前移动方向更新蛇头位置
    x[0] += directionX;
    y[0] += directionY;

    // 检查是否吃到食物，如果吃到则增加蛇的长度
    if (x[0] == foodX && y[0] == foodY) {
        length++;
        // 新增一个长度的部分位于原来的尾部
        x[length - 1] = x[length - 2];
        y[length - 1] = y[length - 2];
    }
}

bool Snake::checkCollision() const {
    // 边界检测
    if (x[0] < 0 || x[0] >= GRID_SIZE || y[0] < 0 || y[0] >= GRID_SIZE) {
        return true;
    }

    return false;
}
