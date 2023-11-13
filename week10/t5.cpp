#include <iostream>
#include <cassert>     

class CEO { //rank1 Ŭ����
    std::string s;
public:
    CEO() : s("CEO") {} //CEO�� ������
    virtual void what() {   //�ڽ��� � Ÿ������ ����ϴ� �Լ�
        std::cout << s << std::endl;
    }
};

class CPO { //rank2 Ŭ����
    std::string s;
public:
    CPO() : s("CPO") {} //CPO�� ������
    virtual void what() {
        std::cout << s << std::endl;
    }
};

//rank3 Ŭ����, rank1 rank2 Ŭ������ ���� ��� ����
class Manager : public CEO, public CPO {
    std::string s;
public:
    Manager() : s("Manager") {} //Manager�� ������
    void what() {
        std::cout << s << std::endl;
    }
};

//rank 4 Ŭ����, rank3 Ŭ������ ��ӹ���
class Staff : public Manager {
    std::string s;
public:
    Staff() : s("Staff") {} //Staff�� ������
    void what() {
        std::cout << s << std::endl;
    }
};

int main() {
    //CPO* ����(������ cpo)�ϰ� ���� rank object �Ҵ�(upcasting)
    CPO* cpo = new Staff;  
    //CEO* ����(������ ceo)�ϰ� ���� rank object �Ҵ�(upcasting)
    CEO* ceo = new Staff;
    //Staff* ����(������ staff)�ϰ� cpo downcasting(dynamic_cast) ����
    Staff* staff = dynamic_cast<Staff*>(cpo);
    //Staff* ����(������ staff2)�ϰ� ceo downcasting(dynamic_cast) ����
    Staff* staff2 = dynamic_cast<Staff*>(ceo);
    //Manager* ����(������ manager)�ϰ� downcasting(dynamic_cast) ����
    Manager* manager = dynamic_cast<Manager*>(cpo);
    
    //assert�Լ� ����Ͽ� staff, staff2, manager ������ ������ nullptr�� �ƴ��� Ȯ��
    assert(staff != nullptr);
    assert(staff2 != nullptr);
    assert(manager != nullptr);

    return 0;
}