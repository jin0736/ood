#include <iostream>

class Shape {   //도형에 대한 추상 기본 클래스
public:
    virtual void draw() = 0; //도형의 특성을 출력하는 함수
};

class Rectangle : public Shape {  //직사각형에 대한 구체적인 클래스
public:
    void draw() override {
        std::cout << "Shape: Rectangle" << std::endl;
    }
};

class Circle : public Shape {  //원에 대한 구체적인 클래스
public:
    void draw() override {
        std::cout << "Shape: Circle" << std::endl;
    }
};

//도형에 데코레이터를 추가하기 위한 추상 데코레이터 클래스
class ShapeDecorator : public Shape { 
protected:
    Shape* decoratedShape;  //데코레이터로 장식할 도형

public:
    ShapeDecorator(Shape* decoratedShape) : decoratedShape(decoratedShape) {}

    void draw() override {
        decoratedShape->draw();
    }
};

//빨간 테두리를 추가하는 구체적인 데코레이터 클래스
class RedShapeDecorator : public ShapeDecorator {
public:
    RedShapeDecorator(Shape* decoratedShape) : ShapeDecorator(decoratedShape) {}

    void draw() override {
        decoratedShape->draw(); 
        setRedBorder();   //기존 출력에 테두리 출력 추가
    }

private:
    void setRedBorder() {
        std::cout << "Border Color: Red" << std::endl;
    }
};

int main() {
    Shape* circle = new Circle();   //기본 원
    Shape* redCircle = new RedShapeDecorator(new Circle()); //빨간 테두리 원
    Shape* redRectangle = new RedShapeDecorator(new Rectangle()); //빨간 테두리 직사각형

    std::cout << "Circle with normal border" << std::endl;
    circle->draw(); //원 특성 출력

    std::cout << "\nCircle of red border" << std::endl;
    redCircle->draw();      //빨간 테두리 원 특성 출력

    std::cout << "\nRectangle of red border" << std::endl;
    redRectangle->draw();   //빨간 테두리 직사각형 특성 출력

    return 0;
}
