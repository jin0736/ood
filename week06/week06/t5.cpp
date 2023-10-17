#include <iostream>
#include <string>
#include <iomanip>

class Employee {    //�������� ������ ǥ���ϱ� ���� Employee Ŭ����
public:
    //Employee Ŭ������ ������. ������ ������ �ʱ�ȭ�Ѵ�.
    Employee(std::string emp_id, std::string name, int age, std::string address, float salary)
        : emp_id(emp_id), name(name), age(age), address(address), salary(salary) {}

    std::string get_emp_id() {  //id�� ��ȯ�ϴ� �Լ�
        return emp_id;
    }

    std::string get_name() {    //�̸��� ��ȯ�ϴ� �Լ�
        return name;
    }

    int get_age() { //���̸� ��ȯ�ϴ� �Լ�
        return age;
    }

    std::string get_address() { //�ּҸ� ��ȯ�ϴ� �Լ�
        return address;
    }

    float get_salary() {    //�޿��� ��ȯ�ϴ� �Լ�
        return salary;
    }

private:
    std::string emp_id; //������ id
    std::string name;   //������ �̸�
    int age;    //������ ����
    std::string address;    //������ �ּ�
    float salary;   //������ �޿�
};

//Employee Ŭ������ ��ӹ��� Manager Ŭ����.
class Manager : public Employee {
public:
    //Manager Ŭ������ ������. ������ ������ �ʱ�ȭ�Ѵ�.
    Manager(std::string emp_id, std::string name, int age, std::string address, float salary, int team_size)
        : Employee(emp_id, name, age, address, salary), team_size(team_size) {}

    int get_team_size() {   //�����ϴ� �������� ���� ��ȯ�ϴ� �Լ�
        return team_size;
    }

private:
    int team_size;  //�Ŵ����� �����ϴ� �������� ��

};

int main() {
    Manager manager("EMP001", "Manager �̸�", 35, "seoul", 5000.00, 10); //��ü ������ �Ű����� ����

    std::cout << "Manager Information" << std::endl;
    std::cout << " Employee ID : " << manager.get_emp_id() << std::endl; // Employee ID : EMP001
    std::cout << " Name : " << manager.get_name() << std::endl; // Name : Manager �̸�
    std::cout << " Age : " << manager.get_age() << std::endl; // Age : 35
    std::cout << " Address : " << manager.get_address() << std::endl; // Address : seoul
    std::cout << std::fixed << std::setprecision(2); //�Ҽ��� ��� ���� ����
    std::cout << " Salary : $" << manager.get_salary() << std::endl; // Salary : $5000.00
    std::cout << "Team Size : " << manager.get_team_size() << std::endl; //Team Size : 10

    return 0;
}