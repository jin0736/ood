#include <iostream>

class DrawAPI { //브릿지 구현자 인터페이스 생성
public:
    //가상함수 drawCircle
    virtual void drawCircle(int radius, int x, int y) = 0;
};

//DrawAPI 인터페이스를 구현하는 구체적인 브릿지 구현자 클래스 생성
class RedCircle : public DrawAPI { //DrawAPI를 상속받는 RedCircle 클래스
public:     //drawCircle 함수 구현
    void drawCircle(int radius, int x, int y) override {
        std::cout << "Drawing Circle[ color: red, radius: " 
            << radius << ", x: " << x << ", " << y << "]" << std::endl;
    }
};

class GreenCircle : public DrawAPI { //DrawAPI를 상속받는 GreenCircle 클래스
public:     //drawCircle 함수 구현
    void drawCircle(int radius, int x, int y) override {
        std::cout << "Drawing Circle[ color: green, radius: " 
            << radius << ", x: " << x << ", " << y << "]" << std::endl;
    }
};

class Shape { //DrawAPI 인터페이스를 사용하는 추상 클래스 Shape 생성
protected:
    DrawAPI* drawAPI;

public:
    Shape(DrawAPI* drawAPI) : drawAPI(drawAPI) {}
    virtual void draw() = 0;
};

class Circle : public Shape { //Shape 인터페이스를 구현하는 구체적인 클래스 생성
private:
    int x, y, radius;

public:
    Circle(int x, int y, int radius, DrawAPI* drawAPI) : Shape(drawAPI), x(x), y(y), radius(radius) {}

    void draw() override { //draw 함수 구현, 실행시 drawCircle 함수 호출
        drawAPI->drawCircle(radius, x, y);
    }
};

int main() {
    //redCircle, GreenCircle 객체 생성
    Shape* redCircle = new Circle(100, 100, 10, new RedCircle());
    Shape* greenCircle = new Circle(100, 100, 10, new GreenCircle());

    //draw 함수를 통해 출력
    redCircle->draw();
    greenCircle->draw();

    return 0;
}