#include <iostream>
#include <cassert>     

class BaseClass { //부모 클래스
    std::string s;  //타입명 저장

public:
    BaseClass() : s("Base") {}  //BaseClass의 생성자
    virtual void what() {   //자신이 어떤 타입인지 출력하는 함수
        std::cout << s << std::endl;
    }
    
};

class DerivedClass : public BaseClass { //BaseClass를 상속받는 자식 클래스
    std::string s;

public:
    DerivedClass() : s("Derived") {}    //DerivedClass의 생성자
    void what() {
        std::cout << s << std::endl;
    }
    
};

int main() {
    BaseClass b;    //BaseClass 선언
    DerivedClass d; //DerivedClass 선언

    BaseClass* base = &d;   // BaseClass* 선언과 DerivedClass 할당

    //DerivedClass* 선언 및 downcasting(dynamic_cast)
    DerivedClass* derived = dynamic_cast<DerivedClass*>(base);
    
    if (derived) {  //객체 생성 유무를 확인하기 위한 if/else문
        std::cout << "Everything is OKAY" << std::endl;
    }
    else {
        std::cout << "failed" << std::endl;
    }

    return 0;
}