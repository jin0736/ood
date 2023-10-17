#include <iostream>

class A {   //�����ڿ� �Ҹ��ڰ� ���ǵ� Ŭ����
public:
    //Ŭ������ ������. ���� ���� �Ű������� �ް� ������ �� ����� �����Ѵ�.
    A(int value) : value(value) {
        std::cout << "Constructor()" << std::endl;
    }

    //Ŭ������ �Ҹ���. ������ �� ����� �����Ѵ�.
    ~A() {
        std::cout << "Destructor()" << std::endl;
    }

    int getValue() const {  //���� ��ȯ�ϴ� �Լ�
        return value;
    }

private:
    int value;  //�Ű������� �޾� ����ó������ ����� ����
};

int main() {
    try {
        A object(10);   //��ü ����
        throw object.getValue();    //���� throw �Ѵ�.
    } catch (int value) {
        std::cout << "Catch " << value << std::endl; //throw�� �� 10 ���
    }

    return 0;
}