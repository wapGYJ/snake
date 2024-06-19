#include "Snake.h"
#include"common.h"
Snake::Snake() {
    // ��ʼ���������������λ��
    int mid = GRID_SIZE / 2;
    x[0] = mid;
    y[0] = mid;
   x[1] = mid;
   y[1] = mid - 1;
   x[2] = mid;
   y[2] = mid - 1;
    length =3;
    directionX = 0;
    directionY = 1;  // ��ʼ��������
}

int Snake::getHeadX() const {
    return x[0];
}

int Snake::getHeadY() const {
    return y[0];
}

void Snake::changeDirection(int x, int y) {
    // ȷ���߲��ܷ����ƶ�
    if (directionX == -x && directionY == -y) {
        return;
    }
    directionX = x;
    directionY = y;
}

void Snake::move(int foodX, int foodY) {
    // ����β���ƶ�����ͷ��λ��
    for (int i = length - 1; i > 0; --i) {
        x[i] = x[i - 1];
        y[i] = y[i - 1];
    }

    // ���ݵ�ǰ�ƶ����������ͷλ��
    x[0] += directionX;
    y[0] += directionY;

    // ����Ƿ�Ե�ʳ�����Ե��������ߵĳ���
    if (x[0] == foodX && y[0] == foodY) {
        length++;
        // ����һ�����ȵĲ���λ��ԭ����β��
        x[length - 1] = x[length - 2];
        y[length - 1] = y[length - 2];
    }
}

bool Snake::checkCollision() const {
    // �߽���
    if (x[0] < 0 || x[0] >= GRID_SIZE || y[0] < 0 || y[0] >= GRID_SIZE) {
        return true;
    }

    return false;
}
