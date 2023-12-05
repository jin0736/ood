#include <iostream>

template <typename T>
auto sum(T x) { //마지막 피연산자에서 호출됨
    return x;
}

template <typename T, typename... Args>
auto sum(T x, Args... args) {   //재귀 호출로 가변 인자들을 더한다.
    return x + sum(args...);
}

//평균을 구하는 template 함수
template <typename... Args>
auto average(Args... args) {
    auto sumResult = sum(args...);  //인자들의 총합을 저장하는 변수 
 
    //sizeof를 이용하여 인자의 개수를 분모, 인자의 합을 분자로 하여 평균 반환
    return sumResult/sizeof...(args);   
}

int main() {
    std::cout << average(1, 2, 3, 4, 10, 10) << std::endl; // average = 5
    return 0;
}
