#include <iostream>
#include <string>
#include <iomanip>

class Employee {    //직원들의 정보를 표현하기 위한 Employee 클래스
public:
    //Employee 클래스의 생성자. 직원의 정보를 초기화한다.
    Employee(std::string emp_id, std::string name, int age, std::string address, float salary)
        : emp_id(emp_id), name(name), age(age), address(address), salary(salary) {}

    std::string get_emp_id() {  //id를 반환하는 함수
        return emp_id;
    }

    std::string get_name() {    //이름을 반환하는 함수
        return name;
    }

    int get_age() { //나이를 반환하는 함수
        return age;
    }

    std::string get_address() { //주소를 반환하는 함수
        return address;
    }

    float get_salary() {    //급여를 반환하는 함수
        return salary;
    }

private:
    std::string emp_id; //직원의 id
    std::string name;   //직원의 이름
    int age;    //직원의 나이
    std::string address;    //직원의 주소
    float salary;   //직원의 급여
};

//Employee 클래스를 상속받은 Manager 클래스.
class Manager : public Employee {
public:
    //Manager 클래스의 생성자. 직원의 정보를 초기화한다.
    Manager(std::string emp_id, std::string name, int age, std::string address, float salary, int team_size)
        : Employee(emp_id, name, age, address, salary), team_size(team_size) {}

    int get_team_size() {   //관리하는 팀원들의 수를 반환하는 함수
        return team_size;
    }

private:
    int team_size;  //매니저가 관리하는 팀원들의 수

};

int main() {
    Manager manager("EMP001", "Manager 이름", 35, "seoul", 5000.00, 10); //객체 생성과 매개변수 전달

    std::cout << "Manager Information" << std::endl;
    std::cout << " Employee ID : " << manager.get_emp_id() << std::endl; // Employee ID : EMP001
    std::cout << " Name : " << manager.get_name() << std::endl; // Name : Manager 이름
    std::cout << " Age : " << manager.get_age() << std::endl; // Age : 35
    std::cout << " Address : " << manager.get_address() << std::endl; // Address : seoul
    std::cout << std::fixed << std::setprecision(2); //소수점 출력 범위 설정
    std::cout << " Salary : $" << manager.get_salary() << std::endl; // Salary : $5000.00
    std::cout << "Team Size : " << manager.get_team_size() << std::endl; //Team Size : 10

    return 0;
}