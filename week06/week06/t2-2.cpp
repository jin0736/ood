#include <iostream>
#include <exception>

//���ο� Exception�� ������ Ŭ����
class NewException : public std::exception {
public:
    //Ŭ������ ������. ����� �޽����� �Ű������� �޴´�.
    NewException(const char* msg) : message(msg) {}

    //what() �Լ��� �������̵��Ͽ� ����� �޽����� ��ȯ�ϵ��� �Ѵ�.
    const char* what() {
        return message;
    }

private:
    const char* message;    //���ο� exception�� �����ϴ� �޽���
};

int main() {
    try {
        //NewException�� �߻���Ű�� what()���� ��ȯ�� ���ڿ��� �Ű������� �޴´�.
        throw NewException("NewException");
    }
    catch (NewException& e) {
        std::cout << "My exception is " << e.what() << std::endl;
        //My exception is NewException
    }

    return 0;
}