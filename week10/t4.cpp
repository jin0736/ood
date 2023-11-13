#include <iostream>
#include <cassert>     

class BaseClass { //�θ� Ŭ����
    std::string s;  //Ÿ�Ը� ����

public:
    BaseClass() : s("Base") {}  //BaseClass�� ������
    virtual void what() {   //�ڽ��� � Ÿ������ ����ϴ� �Լ�
        std::cout << s << std::endl;
    }
    
};

class DerivedClass : public BaseClass { //BaseClass�� ��ӹ޴� �ڽ� Ŭ����
    std::string s;

public:
    DerivedClass() : s("Derived") {}    //DerivedClass�� ������
    void what() {
        std::cout << s << std::endl;
    }
    
};

int main() {
    BaseClass b;    //BaseClass ����
    DerivedClass d; //DerivedClass ����

    BaseClass* base = &d;   // BaseClass* ����� DerivedClass �Ҵ�

    //DerivedClass* ���� �� downcasting(dynamic_cast)
    DerivedClass* derived = dynamic_cast<DerivedClass*>(base);
    
    if (derived) {  //��ü ���� ������ Ȯ���ϱ� ���� if/else��
        std::cout << "Everything is OKAY" << std::endl;
    }
    else {
        std::cout << "failed" << std::endl;
    }

    return 0;
}