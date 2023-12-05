#include <iostream>
#include <algorithm>
#include <forward_list>

template <typename ForwardIterator, typename Compare>   //버블 정렬 함수
void bubble_sort(ForwardIterator first, ForwardIterator last, Compare comp) {
    auto end = last;    //현재 검사 범위의 끝
    while (first != end) {  //검사 범위가 비어있지 않을 때까지 반복
        auto new_end = first; //각 반복에서 최대(최소) 원소가 이동한 위치를 나타내는 변수
        for (auto it = first; std::next(it) != end; ++it) {
            if (comp(*it, *std::next(it))) {    //두 원소 비교
                std::iter_swap(it, std::next(it));  //두 원소교환
                new_end = std::next(it);  // 최대(최소) 원소가 이동한 위치 갱신
            }
        }
        end = new_end;  //다음 반복 검사 범위를 갱신
    }
}

class compGreater {  //오름차순 정렬에 사용되는 functor
public:
    bool operator()(const int& a, const int& b) const {
        return a > b;   //a가 b보다 크면 true 반환
    }
};

class compLess {  //내림차순 정렬에 사용되는 functor
public:
    bool operator()(const int& a, const int& b) const {
        return a < b;   //a가 b보다 작으면 true 반환
    }
};

int main() {
    std::forward_list<int> values{ 7, 0, 6, 1, 5, 2, 4, 3 };  //정렬할 숫자 리스트

    // 오름차순 정렬
    std::cout << "오름차순 정렬" << std::endl;
    bubble_sort(values.begin(), values.end(), compGreater());
    for (const auto value : values) {   //오름차순 정렬된 리스트 출력
        std::cout << " " << value ;
    }
    std::cout << std::endl;

    // 내림차순 정렬
    std::cout << "내림차순 정렬" << std::endl;
    bubble_sort(values.begin(), values.end(), compLess());
    for (const auto value : values) {   //내림차순 정렬된 리스트 출력
        std::cout << " " << value;
    }
    std::cout << std::endl;

    return 0;
}
