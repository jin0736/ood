#include <iostream>
#include <string>
#include <algorithm>

template<typename T>
double min_value(T x) { //마지막 피연산자에서 호출됨
    return static_cast<double>(x);
}

template<typename T, typename... Args>
double min_value(T x, Args... args) { //재귀 호출로 최소값 찾기
    double remain = min_value(args...); //첫 인자를 제외한 나머지를 다시 함수로
    return std::min(static_cast<double>(x), remain); //작은 값 반환
}

int main() {
    auto x = min_value(42, 3.14, 11.1f, -2);   //최소값 저장, 타입 자동 추론
    std::cout << x;     //-2 출력

    getchar();
    return 0;
}
