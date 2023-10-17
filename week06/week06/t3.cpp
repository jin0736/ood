#include <iostream>

class A {   //생성자와 소멸자가 정의된 클래스
public:
    //클래스의 생성자. 정수 값을 매개변수로 받고 생성될 때 출력을 진행한다.
    A(int value) : value(value) {
        std::cout << "Constructor()" << std::endl;
    }

    //클래스의 소멸자. 생성될 때 출력을 진행한다.
    ~A() {
        std::cout << "Destructor()" << std::endl;
    }

    int getValue() const {  //값을 반환하는 함수
        return value;
    }

private:
    int value;  //매개변수로 받아 오류처리에서 출력할 변수
};

int main() {
    try {
        A object(10);   //객체 생성
        throw object.getValue();    //값을 throw 한다.
    } catch (int value) {
        std::cout << "Catch " << value << std::endl; //throw된 값 10 출력
    }

    return 0;
}