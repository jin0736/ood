#include <iostream>
#include <exception>

//새로운 Exception을 정의한 클래스
class NewException : public std::exception {
public:
    //what() 함수를 오버라이딩하여 새로운 exception을 정의한다.
    const char* what() {
        return "NewException";
    }
};

int main() {
    try {
        //NewException을 발생시킨다.
        throw NewException();
    }
    catch (NewException& e) {
        std::cout << "My exception is " << e.what() << std::endl;
        //My exception is NewException
    }

    return 0;
}