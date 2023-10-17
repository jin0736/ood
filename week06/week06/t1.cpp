#include <iostream>

class Class {   //��ü�� ���� ���������ڰ� �����ϵ��� �����ε��� ������ Ŭ����
private:
    int value;  //��ü�� ���� �����ϴ� ����
public:
    //Class �� ������, value�� ���� �������� ������ �⺻���� 5�� ��
    Class(int val = 5) : value(val) {}  

    //postfix unary overloading

    Class operator++(int) {
        Class temp(value);  //���� ��ü �� �ӽ� ����
        ++value;    //��ü �� 1 ����
        return temp;    //���� �� �ӽ� ��ü ��ȯ
    }
    
    //prefix unary overloading
    Class& operator++() {
        ++value;    //��ü �� 1 ����
        return *this;   //��ü ���� ��ȯ
    }

    //Ŭ���� �ܺο��� ���� �������� ���� �Լ�    
    int getValue() {
        return value;
    }
    
};

int main() {
    Class a; //��ü a ����
    std::cout << a.getValue() << " (�ʱⰪ), ";    //�ʱⰪ 5
    a++; 
    std::cout << a.getValue() << " (a++ ���), "; //6
    ++a; 
    std::cout << a.getValue() << " (++a ���)";   //7

    return 0;
}