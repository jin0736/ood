#include <iostream>

class Class {   //객체에 대한 증감연산자가 가능하도록 오버로딩을 구현한 클래스
private:
    int value;  //객체의 값을 저장하는 변수
public:
    //Class 의 생성자, value의 값이 지정되지 않으면 기본값을 5로 함
    Class(int val = 5) : value(val) {}  

    //postfix unary overloading

    Class operator++(int) {
        Class temp(value);  //현재 객체 값 임시 저장
        ++value;    //객체 값 1 증가
        return temp;    //증가 전 임시 객체 반환
    }
    
    //prefix unary overloading
    Class& operator++() {
        ++value;    //객체 값 1 증가
        return *this;   //객체 참조 반환
    }

    //클래스 외부에서 값을 가져오기 위한 함수    
    int getValue() {
        return value;
    }
    
};

int main() {
    Class a; //객체 a 생성
    std::cout << a.getValue() << " (초기값), ";    //초기값 5
    a++; 
    std::cout << a.getValue() << " (a++ 결과), "; //6
    ++a; 
    std::cout << a.getValue() << " (++a 결과)";   //7

    return 0;
}