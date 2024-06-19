#include "Game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>  // 用于时间相关操作
#include <thread>  // 用于线程相关操作>
#include <conio.h> // 用于获取控制台输入

Game::Game() {
    // 初始化随机数种子
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
}

void Game::run() {
    initialize();  // 初始化游戏状态

    while (true) {
        processInput();  // 处理用户输入
        update();  // 更新游戏状态
        render();  // 渲染游戏界面
         std::this_thread::sleep_for(std::chrono::seconds(1));
        // 检查游戏是否结束
        if (snake.checkCollision()) {
            gameOver();
            break;
        }
    }
}

void Game::initialize() {
    // 初始化游戏网格
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (i == 0 || j == 0 || i == GRID_SIZE - 1 || j == GRID_SIZE - 1) {
                grid[i][j] = -2;  // 边界
            }
            else {
                grid[i][j] = 0;  // 清空网格
            }
        }
    }

    // 初始化蛇的位置
    snake = Snake();
    grid[snake.getHeadX()][snake.getHeadY()] = 200;
    // 初始化食物的位置
    food.generateNewPosition();
}

void Game::processInput() {
    // 处理用户输入，改变蛇的移动方向
    if (_kbhit()) {  // 检测是否有按键输入
        char input = _getch();  // 获取按键输入
        int dirX = 0, dirY = 0;
        switch (input) {
        case 'w':  // 上
            dirX = -1;
            dirY = 0;
            break;
        case 's':  // 下
            dirX = 1;
            dirY = 0;
            break;
        case 'a':  // 左
            dirX = 0;
            dirY = -1;
            break;
        case 'd':  // 右
            dirX = 0;
            dirY = 1;
            break;
        default:
            break;
        }
        snake.changeDirection(dirX, dirY);
    }
}

void Game::update() {
    // 清除当前蛇在网格上的显示
    for (int i = 0; i < snake.length; ++i) {
        grid[snake.x[i]][snake.y[i]] = 0;
    }

    // 移动蛇
    snake.move(food.getX(), food.getY());

    // 更新新的蛇在网格上的显示
    for (int i = 0; i < snake.length; ++i) {
        grid[snake.x[i]][snake.y[i]] = (i == 0) ? 200 : 100;  // 200表示蛇头, 100表示蛇身
    }

    // 如果吃到了食物，重新生成食物
    if (snake.getHeadX() == food.getX() && snake.getHeadY() == food.getY()) {
        food.generateNewPosition();
    }
}



void Game::render() const {
    system("cls");

    // 打印游戏网格
    for (int i = 0; i < GRID_SIZE; ++i) {
        for (int j = 0; j < GRID_SIZE; ++j) {
            if (i == food.getX() && j == food.getY()) {
                std::cout << " F";  // 显示食物
            }
            else if (grid[i][j] == 200) {
                std::cout << " @";  // 显示蛇头
            }
            else if (grid[i][j] == 100) {
                std::cout << " *";  // 显示蛇身
            }
            else if (grid[i][j] == -2) {
                std::cout << "#";   // 显示边界
            }
            else {
                std::cout << "  ";  // 显示空格
            }
        }
        std::cout << std::endl;
    }
}

void Game::gameOver() const {
    // 游戏结束处理
    std::cout << "Game Over! Your score: " <<  std::endl;
}
