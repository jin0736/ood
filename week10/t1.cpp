#include <iostream>
#include <string>

//Shape에 대한 인터페이스 만들기
class Shape {
public:
    //가상함수 draw
    virtual void draw() = 0;
};

//동일한 인터페이스를 구현하는 구체적인 클래스 생성
class RoundedRectangle : public Shape { //Shape를 상속받는 RoundedRectangle 클래스
public:
    void draw() override {  //도형 모양 출력하는 draw함수 구현
        std::cout << "Inside RoundedRectangle::draw() method." << std::endl;
    }
};

//Shape를 상속받는 RoundedSquare 클래스
class RoundedSquare : public Shape {
public:
    void draw() override {  //도형 모양 출력하는 draw함수 구현
        std::cout << "Inside RoundedSquare::draw() method." << std::endl;
    }
};

//Shape를 상속받는 Rectangle 클래스
class Rectangle : public Shape {
public:
    void draw() override {  //도형 모양 출력하는 draw함수 구현
        std::cout << "Inside Rectangle::draw() method." << std::endl;
    }
};

class Square : public Shape { //Shape를 상속받는 Square 클래스
public:
    void draw() override {  //도형 모양 출력하는 draw함수 구현
        std::cout << "Inside Square::draw() method." << std::endl;
    }
};

//Normal and Rounded Shape 객체에 대한 팩토리를 얻기 위한 추상 클래스 생성
class AbstractFactory {
public:
    //가상함수 getShape
    virtual Shape* getShape(const std::string& shapeType) = 0;
};

//구체적인 클래스의 객체 생성을 위한 AbstractFactory를 확장하는 Factory 클래스를 생성
class ShapeFactory : public AbstractFactory { //AbstractFactory를 상속받는 ShapeFactory 클래스
public:
    Shape* getShape(const std::string& shapeType) override {
        if (shapeType == "RECTANGLE") { //Rectangle 객체 생성
            return new Rectangle();
        }
        else if (shapeType == "SQUARE") { //Square 객체 생성
            return new Square();
        }
        return nullptr;
    }
};

//AbstractFactory를 상속받는 RoundedShapeFactory 클래스
class RoundedShapeFactory : public AbstractFactory {
public:
    Shape* getShape(const std::string& shapeType) override {
        if (shapeType == "RECTANGLE") { //RoundedRectangle 객체 생성
            return new RoundedRectangle();
        }
        else if (shapeType == "SQUARE") { //RoundedSquare 객체 생성
            return new RoundedSquare();
        }
        return nullptr;
    }
};

//rounded 정보를 전달하여 팩토리를 얻게 함
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

// AbstractFactoryPatternDemo 클래스 정의
int main() {
    //ShapeFactory 만들기
    AbstractFactory* shapeFactory = FactoryProducer::getFactory(false);
    //Shape Rectangle 객체 생성 및 draw 함수 호출
    Shape* shape1 = shapeFactory->getShape("RECTANGLE");
    shape1->draw();
    //Shape Square 객체 생성 및 draw 함수 호출
    Shape* shape2 = shapeFactory->getShape("SQUARE");
    shape2->draw();

    //RoundedShapeFactory 만들기
    AbstractFactory* shapeFactory1 = FactoryProducer::getFactory(true);
    //RoundedRectangle 객체 생성 및 draw 함수 호출
    Shape* shape3 = shapeFactory1->getShape("RECTANGLE");
    shape3->draw();
    //RoundedSquare 객체 생성 및 draw 함수 호출
    Shape* shape4 = shapeFactory1->getShape("SQUARE");
    shape4->draw();

    //메모리 누수 방지를 위해 동적으로 할당한 객체들을 삭제
    delete shape1;
    delete shape2;
    delete shape3;
    delete shape4;

    return 0;
}