#include <iostream>
#include <exception>

//���ο� Exception�� ������ Ŭ����
class NewException : public std::exception {
public:
    //what() �Լ��� �������̵��Ͽ� ���ο� exception�� �����Ѵ�.
    const char* what() {
        return "NewException";
    }
};

int main() {
    try {
        //NewException�� �߻���Ų��.
        throw NewException();
    }
    catch (NewException& e) {
        std::cout << "My exception is " << e.what() << std::endl;
        //My exception is NewException
    }

    return 0;
}