#include <iostream>

class Shape {   //������ ���� �߻� �⺻ Ŭ����
public:
    virtual void draw() = 0; //������ Ư���� ����ϴ� �Լ�
};

class Rectangle : public Shape {  //���簢���� ���� ��ü���� Ŭ����
public:
    void draw() override {
        std::cout << "Shape: Rectangle" << std::endl;
    }
};

class Circle : public Shape {  //���� ���� ��ü���� Ŭ����
public:
    void draw() override {
        std::cout << "Shape: Circle" << std::endl;
    }
};

//������ ���ڷ����͸� �߰��ϱ� ���� �߻� ���ڷ����� Ŭ����
class ShapeDecorator : public Shape { 
protected:
    Shape* decoratedShape;  //���ڷ����ͷ� ����� ����

public:
    ShapeDecorator(Shape* decoratedShape) : decoratedShape(decoratedShape) {}

    void draw() override {
        decoratedShape->draw();
    }
};

//���� �׵θ��� �߰��ϴ� ��ü���� ���ڷ����� Ŭ����
class RedShapeDecorator : public ShapeDecorator {
public:
    RedShapeDecorator(Shape* decoratedShape) : ShapeDecorator(decoratedShape) {}

    void draw() override {
        decoratedShape->draw(); 
        setRedBorder();   //���� ��¿� �׵θ� ��� �߰�
    }

private:
    void setRedBorder() {
        std::cout << "Border Color: Red" << std::endl;
    }
};

int main() {
    Shape* circle = new Circle();   //�⺻ ��
    Shape* redCircle = new RedShapeDecorator(new Circle()); //���� �׵θ� ��
    Shape* redRectangle = new RedShapeDecorator(new Rectangle()); //���� �׵θ� ���簢��

    std::cout << "Circle with normal border" << std::endl;
    circle->draw(); //�� Ư�� ���

    std::cout << "\nCircle of red border" << std::endl;
    redCircle->draw();      //���� �׵θ� �� Ư�� ���

    std::cout << "\nRectangle of red border" << std::endl;
    redRectangle->draw();   //���� �׵θ� ���簢�� Ư�� ���

    return 0;
}
