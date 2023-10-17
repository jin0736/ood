#include <iostream>
#include <string>

//����� �̸�, ����, �ּҸ� �����ϴ� Person Ŭ����
class Person {
public:
    //Person Ŭ������ ������. �̸�, ����, �ּҸ� �ʱ�ȭ�Ѵ�.
    Person(const std::string& name, int age, const std::string& address)
        : name(name), age(age), address(address) {}

    std::string getName() const {   //�̸��� ��ȯ�ϴ� �Լ�
        return name;
    }
    int getAge() const {    //���̸� ��ȯ�ϴ� �Լ�
        return age;
    }

    std::string getAddress() const {    //�ּҸ� ��ȯ�ϴ� �Լ�
        return address;
    }

private:
    std::string name;   //����� �̸�
    int age;    //����� ����
    std::string address;    //����� �ּ�
};

//Person Ŭ������ ����ϴ� Student Ŭ����
class Student : public Person {
public:
    //Student Ŭ������ ������. �̸�, ����, �ּ�, �й��� �ʱ�ȭ�Ѵ�.
    Student(const std::string& name, int age, const std::string& address, const std::string& studentID)
        : Person(name, age, address), studentID(studentID) {}

    std::string getStudentID() const {  //�й��� ��ȯ�ϴ� �Լ� �߰�
        return studentID;
    }

private:
    std::string studentID;  //�л��� �й�
};

int main() {
    Student student("�̼���", 10, "daejeon", "202202492"); //��ü ������ �Ű����� ����

    std::cout << "Student Information" << std::endl;
    std::cout << "Name : " << student.getName() << std::endl;  //Name : �̼���
    std::cout << "Age : " << student.getAge() << std::endl;  //Age : 10
    std::cout << "Address : " << student.getAddress() << std::endl;  //Address : daejeon
    std::cout << "Student ID : " << student.getStudentID() << std::endl;  //Student ID : 202202492

    return 0;
}