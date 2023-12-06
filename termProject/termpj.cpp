#include <iostream>
#include <list>
#include <windows.h>
#include <conio.h>
#include <mutex>
#include <thread>
using namespace std;

const int SCREEN_WIDTH = 41;    //�ܼ��� x�� ����
const int SCREEN_HEIGHT = 12;   //�ܼ��� y�� ĭ ��

//���ڿ��� ����. x���� 4��� �� �� �� ������ �� ĭ�� ������ ��
const int WORD_LENGTH = ((SCREEN_WIDTH - 5) / 4) - 2;
const int MAX_HEALTH = 50;  //�ִ� ü��. 0�� �Ǹ� ���� ����
int speed_cnt = 0;  //�ֱ������� �ϰ� �ӵ��� �����ϱ� ���� ����
atomic<int> speed = 2000;   //���ڿ��� �ϰ� �ӵ�. �ʱ⿡�� 2��
int score = 0;  //���ڿ��� ����� �Է����� �� 10�� ����
string option = ""; //����� �Է����� ���� ���ڿ� ����

mutex mtx; //���� �ڿ� ���� ���� ����

//������Ʈ �������̽�
class Component {
public:
    virtual string operation() const = 0;
};

//���� ������Ʈ
class ConcreteComponent : public Component {
public:
    string operation() const override {
        return "";
    }
};

//���� ���ڷ����� Ŭ����
class Decorator : public Component {
protected:
    Component* component;

public:
    Decorator(Component* component) : component(component) {}

    string operation() const override {
        return component->operation();
    }
};

//���ĺ� ���ڷ�����
class AlphabetDecorator : public Decorator {
public:
    AlphabetDecorator(Component* component) : Decorator(component) {}

    string operation() const override {
        return component->operation() + "abcdefghijklmnopqrstuvwxyz";
    }
};

//���� ���ڷ�����
class NumberDecorator : public Decorator {
public:
    NumberDecorator(Component* component) : Decorator(component) {}

    string operation() const override {
        return component->operation() + "0123456789";
    }
};

//Ư������ ���ڷ�����
class SpecialDecorator : public Decorator {
public:
    SpecialDecorator(Component* component) : Decorator(component) {}

    string operation() const override {
        return component->operation() + "!@#$%^&*";
    }
};


class MyString {  //���ڿ��� �� ��ġ�� �����ϱ� ���� ���� Ŭ����
private:
    string word;
    int wordx, wordy;

public:
    //������ ���ڿ��� �Է¹ް�, ȭ�� �ֻ�� ������ x�� ��ġ ���� ����
    MyString(string w) {
        word = w;
        wordx = ((rand() % 4) * 10 + 2);
        wordy = 0;
    }

    int getX() {    //x��ǥ ��ȯ
        return wordx;
    }

    int getY() {    //y��ǥ ��ȯ
        return wordy;
    }

    string getStr() {   //���ڿ� ��ȯ
        return word;
    }

    void setY(int y) {  //y��ǥ ����
        wordy = y;
    }
};

void gotoxy(int x, int y) { //�ܼ�â ���ϴ� ��ġ�� Ŀ�� �̵�
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

string generateString(string option) {  //���� ���ڿ��� �����ϴ� �Լ�
    srand(static_cast<unsigned int>(time(nullptr)));
    string randomString;    //��ȯ�� ���ڿ�
    for (int i = 0; i < WORD_LENGTH && i < option.length(); ++i) {
        int index = rand() % option.length();
        randomString += option[index];
    }

    if (speed_cnt > 2) {    //���ڿ��� 3�� ������ ������ �ϰ� �ӵ� ���� ����
        speed = (rand() % 3 + 1) * 1000;
        speed_cnt = 0;
    }
    speed_cnt++;

    return randomString;
}

void printString(list<MyString>& list) {    //���ڿ��� ����ϴ� �Լ�
    std::list<MyString>::iterator it = list.begin();
    //for���� ���鼭 ����Ʈ�� �ִ� ���ڿ��� �����
    for (it = list.begin(); it != list.end(); it++) {
        gotoxy(it->getX(), it->getY());
        cout << it->getStr();
    }
}

void down(list<MyString>& list) {   //���ڿ��� �ϰ���Ű�� �Լ�
    std::list<MyString>::iterator it = list.begin();
    //for���� ���鼭 ����Ʈ�� �ִ� ���ڿ��� wordy�� 1 �������� �� ĭ �ϰ��ϵ��� ��
    for (it = list.begin(); it != list.end(); it++) {
        it->setY(it->getY() + 1);
    }
}

void handleInput(list<MyString>& myStringList, string& input, int& hp) {
    while (hp > 0) {
        while (_kbhit()) {
            char ch = _getch();
            if (ch == 13) { //����Ű �Է½�
                {
                    lock_guard<mutex> lock(mtx);
                    list<MyString>::iterator it = myStringList.begin();

                    //����Ʈ�� ��ȸ�ϸ� �Է°� ������ ���ڿ��� ã��
                    while (it != myStringList.end()) {
                        if (input == it->getStr()) {//ã���� ����Ʈ���� ���ڿ� ����, ���� 10 ����    
                            it = myStringList.erase(it);
                            score += 10;
                            //������� ���ڿ��� �ֻ�� ���ڿ��̸� ���ο� ���ڿ� ����
                            if (it == myStringList.end()) {
                                myStringList.push_back(MyString(generateString(option)));
                            }
                            break;
                        }
                        else {
                            ++it;
                        }
                    }
                }

                input = ""; //����� �Է� ����
            }
            else if (ch == 8) { //�齺���̽�Ű �Է½�
                lock_guard<mutex> lock(mtx);
                if (!input.empty()) {
                    input.pop_back();
                }
            }
            else {
                lock_guard<mutex> lock(mtx);
                input += ch;
            }
        }
    }
}

void getOption() {  //���� ���� �� ���� ���ڿ��� ������ �Է¹޴� �Լ�
    Component* stack = new ConcreteComponent();
    char choice;

    while (true) {
        cout << "choice: (Alphabet:1, Numbers:2, Special Characters:3, Done:0): ";
        cin >> choice;

        if (choice == '0')
            break;
        else if (choice == '1')
            stack = new AlphabetDecorator(stack);
        else if (choice == '2')
            stack = new NumberDecorator(stack);
        else if (choice == '3')
            stack = new SpecialDecorator(stack);
        else {
            cout << "Invalid input. Please enter again" << endl;
        }
    }
    option = stack->operation();
}

int main() {
    getOption();

    list<MyString> myStringList;    //���ڿ��� �����ϴ� ����Ʈ
    myStringList.push_back(MyString(generateString(option)));
    int hp = MAX_HEALTH;    //hp�� �ִ� ü������ ����

    string input;   //����� �Է�
    //����� �Է� �����̸� ���̱� ���� �Է��� �޴� ������ ����
    thread inputThread(handleInput, ref(myStringList), ref(input), ref(hp));

    while (hp > 0) {
        {
            lock_guard<mutex> lock(mtx); //Lock the mutex
            cout << "\033[2J\033[H";    //ȭ�� Ŭ����
            for (int i = 0; i < SCREEN_HEIGHT; i++) {
                for (int j = 0; j < 5; j++) {
                    cout << "|         ";
                }
                cout << "\n";

            }

            gotoxy(0, SCREEN_HEIGHT);   //���� �ϴܿ� hp�� ����� �Է� ���
            cout << "-----------------------------------------" << endl;
            cout << "Your hp: " << hp << endl;
            cout << "Your input: " << input;

            printString(myStringList);  //���ڿ� ���

            down(myStringList); //���ڿ� �ϰ�

            if (prev(myStringList.end())->getY() > 3) {//���ڿ��� �����ǰ� 3ĭ �ϰ��� �Ŀ� ���ο� ���ڿ� ����
                myStringList.push_back(MyString(generateString(option)));
            }

            //���ڿ��� �ٴڿ� ������ ����Ʈ���� �����ϰ� hp 10 ����
            if (myStringList.begin()->getY() == SCREEN_HEIGHT) {
                myStringList.pop_front();
                hp -= 10;
            }
        }

        Sleep(speed);   //�ϰ� �ӵ� ����
    }

    inputThread.join(); //������ ���� ��ٸ�

    //ȭ�� Ŭ�����ϰ� ����(�Է��� ���ڿ��� �� * 10) ���
    cout << "\033[2J\033[H";
    cout << "Game Over! Your score is " << score << " points!";

    return 0;
}
