#include <iostream>
#include <algorithm>
#include <forward_list>

template <typename ForwardIterator, typename Compare>   //���� ���� �Լ�
void bubble_sort(ForwardIterator first, ForwardIterator last, Compare comp) {
    auto end = last;    //���� �˻� ������ ��
    while (first != end) {  //�˻� ������ ������� ���� ������ �ݺ�
        auto new_end = first; //�� �ݺ����� �ִ�(�ּ�) ���Ұ� �̵��� ��ġ�� ��Ÿ���� ����
        for (auto it = first; std::next(it) != end; ++it) {
            if (comp(*it, *std::next(it))) {    //�� ���� ��
                std::iter_swap(it, std::next(it));  //�� ���ұ�ȯ
                new_end = std::next(it);  // �ִ�(�ּ�) ���Ұ� �̵��� ��ġ ����
            }
        }
        end = new_end;  //���� �ݺ� �˻� ������ ����
    }
}

class compGreater {  //�������� ���Ŀ� ���Ǵ� functor
public:
    bool operator()(const int& a, const int& b) const {
        return a > b;   //a�� b���� ũ�� true ��ȯ
    }
};

class compLess {  //�������� ���Ŀ� ���Ǵ� functor
public:
    bool operator()(const int& a, const int& b) const {
        return a < b;   //a�� b���� ������ true ��ȯ
    }
};

int main() {
    std::forward_list<int> values{ 7, 0, 6, 1, 5, 2, 4, 3 };  //������ ���� ����Ʈ

    // �������� ����
    std::cout << "�������� ����" << std::endl;
    bubble_sort(values.begin(), values.end(), compGreater());
    for (const auto value : values) {   //�������� ���ĵ� ����Ʈ ���
        std::cout << " " << value ;
    }
    std::cout << std::endl;

    // �������� ����
    std::cout << "�������� ����" << std::endl;
    bubble_sort(values.begin(), values.end(), compLess());
    for (const auto value : values) {   //�������� ���ĵ� ����Ʈ ���
        std::cout << " " << value;
    }
    std::cout << std::endl;

    return 0;
}
