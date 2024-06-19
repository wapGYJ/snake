#include "Game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>  // ����ʱ����ز���
#include <thread>  // �����߳���ز���>
#include <conio.h> // ���ڻ�ȡ����̨����

Game::Game() {
    // ��ʼ�����������
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
}

void Game::run() {
    initialize();  // ��ʼ����Ϸ״̬

    while (true) {
        processInput();  // �����û�����
        update();  // ������Ϸ״̬
        render();  // ��Ⱦ��Ϸ����
         std::this_thread::sleep_for(std::chrono::seconds(1));
        // �����Ϸ�Ƿ����
        if (snake.checkCollision()) {
            gameOver();
            break;
        }
    }
}

void Game::initialize() {
    // ��ʼ����Ϸ����
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (i == 0 || j == 0 || i == GRID_SIZE - 1 || j == GRID_SIZE - 1) {
                grid[i][j] = -2;  // �߽�
            }
            else {
                grid[i][j] = 0;  // �������
            }
        }
    }

    // ��ʼ���ߵ�λ��
    snake = Snake();
    grid[snake.getHeadX()][snake.getHeadY()] = 200;
    // ��ʼ��ʳ���λ��
    food.generateNewPosition();
}

void Game::processInput() {
    // �����û����룬�ı��ߵ��ƶ�����
    if (_kbhit()) {  // ����Ƿ��а�������
        char input = _getch();  // ��ȡ��������
        int dirX = 0, dirY = 0;
        switch (input) {
        case 'w':  // ��
            dirX = -1;
            dirY = 0;
            break;
        case 's':  // ��
            dirX = 1;
            dirY = 0;
            break;
        case 'a':  // ��
            dirX = 0;
            dirY = -1;
            break;
        case 'd':  // ��
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
    // �����ǰ���������ϵ���ʾ
    for (int i = 0; i < snake.length; ++i) {
        grid[snake.x[i]][snake.y[i]] = 0;
    }

    // �ƶ���
    snake.move(food.getX(), food.getY());

    // �����µ����������ϵ���ʾ
    for (int i = 0; i < snake.length; ++i) {
        grid[snake.x[i]][snake.y[i]] = (i == 0) ? 200 : 100;  // 200��ʾ��ͷ, 100��ʾ����
    }

    // ����Ե���ʳ���������ʳ��
    if (snake.getHeadX() == food.getX() && snake.getHeadY() == food.getY()) {
        food.generateNewPosition();
    }
}



void Game::render() const {
    system("cls");

    // ��ӡ��Ϸ����
    for (int i = 0; i < GRID_SIZE; ++i) {
        for (int j = 0; j < GRID_SIZE; ++j) {
            if (i == food.getX() && j == food.getY()) {
                std::cout << " F";  // ��ʾʳ��
            }
            else if (grid[i][j] == 200) {
                std::cout << " @";  // ��ʾ��ͷ
            }
            else if (grid[i][j] == 100) {
                std::cout << " *";  // ��ʾ����
            }
            else if (grid[i][j] == -2) {
                std::cout << "#";   // ��ʾ�߽�
            }
            else {
                std::cout << "  ";  // ��ʾ�ո�
            }
        }
        std::cout << std::endl;
    }
}

void Game::gameOver() const {
    // ��Ϸ��������
    std::cout << "Game Over! Your score: " <<  std::endl;
}
