#include <iostream>

class DrawAPI { //�긴�� ������ �������̽� ����
public:
    //�����Լ� drawCircle
    virtual void drawCircle(int radius, int x, int y) = 0;
};

//DrawAPI �������̽��� �����ϴ� ��ü���� �긴�� ������ Ŭ���� ����
class RedCircle : public DrawAPI { //DrawAPI�� ��ӹ޴� RedCircle Ŭ����
public:     //drawCircle �Լ� ����
    void drawCircle(int radius, int x, int y) override {
        std::cout << "Drawing Circle[ color: red, radius: " 
            << radius << ", x: " << x << ", " << y << "]" << std::endl;
    }
};

class GreenCircle : public DrawAPI { //DrawAPI�� ��ӹ޴� GreenCircle Ŭ����
public:     //drawCircle �Լ� ����
    void drawCircle(int radius, int x, int y) override {
        std::cout << "Drawing Circle[ color: green, radius: " 
            << radius << ", x: " << x << ", " << y << "]" << std::endl;
    }
};

class Shape { //DrawAPI �������̽��� ����ϴ� �߻� Ŭ���� Shape ����
protected:
    DrawAPI* drawAPI;

public:
    Shape(DrawAPI* drawAPI) : drawAPI(drawAPI) {}
    virtual void draw() = 0;
};

class Circle : public Shape { //Shape �������̽��� �����ϴ� ��ü���� Ŭ���� ����
private:
    int x, y, radius;

public:
    Circle(int x, int y, int radius, DrawAPI* drawAPI) : Shape(drawAPI), x(x), y(y), radius(radius) {}

    void draw() override { //draw �Լ� ����, ����� drawCircle �Լ� ȣ��
        drawAPI->drawCircle(radius, x, y);
    }
};

int main() {
    //redCircle, GreenCircle ��ü ����
    Shape* redCircle = new Circle(100, 100, 10, new RedCircle());
    Shape* greenCircle = new Circle(100, 100, 10, new GreenCircle());

    //draw �Լ��� ���� ���
    redCircle->draw();
    greenCircle->draw();

    return 0;
}