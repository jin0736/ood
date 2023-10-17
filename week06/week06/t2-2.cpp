#include <iostream>
#include <exception>

//새로운 Exception을 정의한 클래스
class NewException : public std::exception {
public:
    //클래스의 생성자. 출력할 메시지를 매개변수로 받는다.
    NewException(const char* msg) : message(msg) {}

    //what() 함수를 오버라이딩하여 출력할 메시지를 반환하도록 한다.
    const char* what() {
        return message;
    }

private:
    const char* message;    //새로운 exception을 정의하는 메시지
};

int main() {
    try {
        //NewException을 발생시키고 what()에서 반환할 문자열을 매개변수로 받는다.
        throw NewException("NewException");
    }
    catch (NewException& e) {
        std::cout << "My exception is " << e.what() << std::endl;
        //My exception is NewException
    }

    return 0;
}