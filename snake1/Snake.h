#ifndef SNAKE_H
#define SNAKE_H

#define MAX_BODY_LENGTH 100  // �����ߵ���󳤶�

class Snake {
public:
    Snake();  // ���캯��
    int getHeadX() const;  // ��ȡ��ͷ x ����
    int getHeadY() const;  // ��ȡ��ͷ y ����
    void changeDirection(int x, int y);  // �ı��ߵ��ƶ�����
    void move(int foodX, int foodY);  // �ƶ��ߣ�������Ƿ�Ե�ʳ��
    bool checkCollision() const;  // ����Ƿ�����ײ
    int length;  // �ߵĳ���
    int x[MAX_BODY_LENGTH];  // ������ÿ�ڵ� x ����
    int y[MAX_BODY_LENGTH];  // ������ÿ�ڵ� y ����


private:
   
    int directionX;  // ���ƶ��ķ��� x ����
    int directionY;  // ���ƶ��ķ��� y ����
};

#endif 
