#include <iostream>
#include <string>

//Shape�� ���� �������̽� �����
class Shape {
public:
    //�����Լ� draw
    virtual void draw() = 0;
};

//������ �������̽��� �����ϴ� ��ü���� Ŭ���� ����
class RoundedRectangle : public Shape { //Shape�� ��ӹ޴� RoundedRectangle Ŭ����
public:
    void draw() override {  //���� ��� ����ϴ� draw�Լ� ����
        std::cout << "Inside RoundedRectangle::draw() method." << std::endl;
    }
};

//Shape�� ��ӹ޴� RoundedSquare Ŭ����
class RoundedSquare : public Shape {
public:
    void draw() override {  //���� ��� ����ϴ� draw�Լ� ����
        std::cout << "Inside RoundedSquare::draw() method." << std::endl;
    }
};

//Shape�� ��ӹ޴� Rectangle Ŭ����
class Rectangle : public Shape {
public:
    void draw() override {  //���� ��� ����ϴ� draw�Լ� ����
        std::cout << "Inside Rectangle::draw() method." << std::endl;
    }
};

class Square : public Shape { //Shape�� ��ӹ޴� Square Ŭ����
public:
    void draw() override {  //���� ��� ����ϴ� draw�Լ� ����
        std::cout << "Inside Square::draw() method." << std::endl;
    }
};

//Normal and Rounded Shape ��ü�� ���� ���丮�� ��� ���� �߻� Ŭ���� ����
class AbstractFactory {
public:
    //�����Լ� getShape
    virtual Shape* getShape(const std::string& shapeType) = 0;
};

//��ü���� Ŭ������ ��ü ������ ���� AbstractFactory�� Ȯ���ϴ� Factory Ŭ������ ����
class ShapeFactory : public AbstractFactory { //AbstractFactory�� ��ӹ޴� ShapeFactory Ŭ����
public:
    Shape* getShape(const std::string& shapeType) override {
        if (shapeType == "RECTANGLE") { //Rectangle ��ü ����
            return new Rectangle();
        }
        else if (shapeType == "SQUARE") { //Square ��ü ����
            return new Square();
        }
        return nullptr;
    }
};

//AbstractFactory�� ��ӹ޴� RoundedShapeFactory Ŭ����
class RoundedShapeFactory : public AbstractFactory {
public:
    Shape* getShape(const std::string& shapeType) override {
        if (shapeType == "RECTANGLE") { //RoundedRectangle ��ü ����
            return new RoundedRectangle();
        }
        else if (shapeType == "SQUARE") { //RoundedSquare ��ü ����
            return new RoundedSquare();
        }
        return nullptr;
    }
};

//rounded ������ �����Ͽ� ���丮�� ��� ��
class FactoryProducer {
public:
    static AbstractFactory* getFactory(bool rounded) {
        if (rounded) {  //rounded
            return new RoundedShapeFactory();
        }
        else {  //normal
            return new ShapeFactory();
        }
    }
};

// AbstractFactoryPatternDemo Ŭ���� ����
int main() {
    //ShapeFactory �����
    AbstractFactory* shapeFactory = FactoryProducer::getFactory(false);
    //Shape Rectangle ��ü ���� �� draw �Լ� ȣ��
    Shape* shape1 = shapeFactory->getShape("RECTANGLE");
    shape1->draw();
    //Shape Square ��ü ���� �� draw �Լ� ȣ��
    Shape* shape2 = shapeFactory->getShape("SQUARE");
    shape2->draw();

    //RoundedShapeFactory �����
    AbstractFactory* shapeFactory1 = FactoryProducer::getFactory(true);
    //RoundedRectangle ��ü ���� �� draw �Լ� ȣ��
    Shape* shape3 = shapeFactory1->getShape("RECTANGLE");
    shape3->draw();
    //RoundedSquare ��ü ���� �� draw �Լ� ȣ��
    Shape* shape4 = shapeFactory1->getShape("SQUARE");
    shape4->draw();

    //�޸� ���� ������ ���� �������� �Ҵ��� ��ü���� ����
    delete shape1;
    delete shape2;
    delete shape3;
    delete shape4;

    return 0;
}