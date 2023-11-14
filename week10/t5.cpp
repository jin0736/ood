#include <iostream>
#include <cassert>     

class CEO { //rank1 클래스
    std::string s;
public:
    CEO() : s("CEO") {} //CEO의 생성자
    virtual void what() {   //자신이 어떤 타입인지 출력하는 함수
        std::cout << s << std::endl;
    }
    virtual ~CEO() {} //가상 소멸자
};

class CPO { //rank2 클래스
    std::string s;
public:
    CPO() : s("CPO") {} //CPO의 생성자
    virtual void what() {
        std::cout << s << std::endl;
    }
    virtual ~CPO() {} //가상 소멸자
};

//rank3 클래스, rank1 rank2 클래스를 다중 상속 받음
class Manager : public CEO, public CPO {
    std::string s;
public:
    Manager() : s("Manager") {} //Manager의 생성자
    void what() {
        std::cout << s << std::endl;
    }
    ~Manager() {} //소멸자
};

//rank 4 클래스, rank3 클래스를 상속받음
class Staff : public Manager {
    std::string s;
public:
    Staff() : s("Staff") {} //Staff의 생성자
    void what() {
        std::cout << s << std::endl;
    }
    ~Staff() {} //소멸자
};

int main() {
    //CPO* 선언(변수명 cpo)하고 하위 rank object 할당(upcasting)
    CPO* cpo = new Staff;  
    //CEO* 선언(변수명 ceo)하고 하위 rank object 할당(upcasting)
    CEO* ceo = new Staff;
    //Staff* 선언(변수명 staff)하고 cpo downcasting(dynamic_cast) 진행
    Staff* staff = dynamic_cast<Staff*>(cpo);
    //Staff* 선언(변수명 staff2)하고 ceo downcasting(dynamic_cast) 진행
    Staff* staff2 = dynamic_cast<Staff*>(ceo);
    //Manager* 선언(변수명 manager)하고 downcasting(dynamic_cast) 진행
    Manager* manager = dynamic_cast<Manager*>(cpo);
    
    //assert함수 사용하여 staff, staff2, manager 포인터 변수가 nullptr이 아닌지 확인
    assert(staff != nullptr);
    assert(staff2 != nullptr);
    assert(manager != nullptr);

    //delete를 사용하여 동적으로 할당된 메모리 해제
    delete cpo;
    delete ceo;

    return 0;
}