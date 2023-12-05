#include <iostream>
#include <string>
#include <algorithm>

template<typename T>
double min_value(T x) { //������ �ǿ����ڿ��� ȣ���
    return static_cast<double>(x);
}

template<typename T, typename... Args>
double min_value(T x, Args... args) { //��� ȣ��� �ּҰ� ã��
    double remain = min_value(args...); //ù ���ڸ� ������ �������� �ٽ� �Լ���
    return std::min(static_cast<double>(x), remain); //���� �� ��ȯ
}

int main() {
    auto x = min_value(42, 3.14, 11.1f, -2);   //�ּҰ� ����, Ÿ�� �ڵ� �߷�
    std::cout << x;     //-2 ���

    getchar();
    return 0;
}
