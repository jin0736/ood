#include <iostream>
/*
refArray �迭�� ������ �޾� �ִ밪�� ���ϰ� �ش� ���� ��ȯ�ϴ� findMax �Լ� �ۼ�
*/

int findMax(int (&arr)[5]) {
	int max = arr[0];
	for (int i = 1; i < 5; i++) {
		if (arr[i] > max)
			max = arr[i];
	}
	return max;
}

int main() {
	int array[5] = { 1, 3, 5, 7, 9 };
	int(&refArray)[5] = array;
	std::cout << "The maximum value is: " << findMax(refArray) << std::endl;
	return 0;
}