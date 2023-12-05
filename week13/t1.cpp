#include <iostream>

template <typename T>
auto sum(T x) { //������ �ǿ����ڿ��� ȣ���
    return x;
}

template <typename T, typename... Args>
auto sum(T x, Args... args) {   //��� ȣ��� ���� ���ڵ��� ���Ѵ�.
    return x + sum(args...);
}

//����� ���ϴ� template �Լ�
template <typename... Args>
auto average(Args... args) {
    auto sumResult = sum(args...);  //���ڵ��� ������ �����ϴ� ���� 
 
    //sizeof�� �̿��Ͽ� ������ ������ �и�, ������ ���� ���ڷ� �Ͽ� ��� ��ȯ
    return sumResult/sizeof...(args);   
}

int main() {
    std::cout << average(1, 2, 3, 4, 10, 10) << std::endl; // average = 5
    return 0;
}
