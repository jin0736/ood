#include <iostream>
#include <string>

//사람의 이름, 나이, 주소를 저장하는 Person 클래스
class Person {
public:
    //Person 클래스의 생성자. 이름, 나이, 주소를 초기화한다.
    Person(const std::string& name, int age, const std::string& address)
        : name(name), age(age), address(address) {}

    std::string getName() const {   //이름을 반환하는 함수
        return name;
    }
    int getAge() const {    //나이를 반환하는 함수
        return age;
    }

    std::string getAddress() const {    //주소를 반환하는 함수
        return address;
    }

private:
    std::string name;   //사람의 이름
    int age;    //사람의 나이
    std::string address;    //사람의 주소
};

//Person 클래스를 상속하는 Student 클래스
class Student : public Person {
public:
    //Student 클래스의 생성자. 이름, 나이, 주소, 학번을 초기화한다.
    Student(const std::string& name, int age, const std::string& address, const std::string& studentID)
        : Person(name, age, address), studentID(studentID) {}

    std::string getStudentID() const {  //학번을 반환하는 함수 추가
        return studentID;
    }

private:
    std::string studentID;  //학생의 학번
};

int main() {
    Student student("이서진", 10, "daejeon", "202202492"); //객체 생성과 매개변수 전달

    std::cout << "Student Information" << std::endl;
    std::cout << "Name : " << student.getName() << std::endl;  //Name : 이서진
    std::cout << "Age : " << student.getAge() << std::endl;  //Age : 10
    std::cout << "Address : " << student.getAddress() << std::endl;  //Address : daejeon
    std::cout << "Student ID : " << student.getStudentID() << std::endl;  //Student ID : 202202492

    return 0;
}