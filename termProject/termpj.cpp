#include <iostream>
#include <list>
#include <windows.h>
#include <conio.h>
#include <mutex>
#include <thread>
using namespace std;

const int SCREEN_WIDTH = 41;    //콘솔의 x축 길이
const int SCREEN_HEIGHT = 12;   //콘솔의 y축 칸 수

//문자열의 길이. x축을 4등분 한 후 양 옆으로 한 칸씩 여유를 둠
const int WORD_LENGTH = ((SCREEN_WIDTH - 5) / 4) - 2;
const int MAX_HEALTH = 50;  //최대 체력. 0이 되면 게임 종료
int speed_cnt = 0;  //주기적으로 하강 속도를 조정하기 위한 변수
atomic<int> speed = 2000;   //문자열의 하강 속도. 초기에는 2초
int score = 0;  //문자열을 제대로 입력했을 때 10씩 증가
string option = ""; //사용자 입력으로 랜덤 문자열 구성

mutex mtx; //공유 자원 동시 접근 제어

//컴포넌트 인터페이스
class Component {
public:
    virtual string operation() const = 0;
};

//구상 컴포넌트
class ConcreteComponent : public Component {
public:
    string operation() const override {
        return "";
    }
};

//기초 데코레이터 클래스
class Decorator : public Component {
protected:
    Component* component;

public:
    Decorator(Component* component) : component(component) {}

    string operation() const override {
        return component->operation();
    }
};

//알파벳 데코레이터
class AlphabetDecorator : public Decorator {
public:
    AlphabetDecorator(Component* component) : Decorator(component) {}

    string operation() const override {
        return component->operation() + "abcdefghijklmnopqrstuvwxyz";
    }
};

//숫자 데코레이터
class NumberDecorator : public Decorator {
public:
    NumberDecorator(Component* component) : Decorator(component) {}

    string operation() const override {
        return component->operation() + "0123456789";
    }
};

//특수문자 데코레이터
class SpecialDecorator : public Decorator {
public:
    SpecialDecorator(Component* component) : Decorator(component) {}

    string operation() const override {
        return component->operation() + "!@#$%^&*";
    }
};


class MyString {  //문자열과 그 위치를 저장하기 위해 만든 클래스
private:
    string word;
    int wordx, wordy;

public:
    //생성시 문자열을 입력받고, 화면 최상단 랜덤한 x축 위치 정보 저장
    MyString(string w) {
        word = w;
        wordx = ((rand() % 4) * 10 + 2);
        wordy = 0;
    }

    int getX() {    //x좌표 반환
        return wordx;
    }

    int getY() {    //y좌표 반환
        return wordy;
    }

    string getStr() {   //문자열 반환
        return word;
    }

    void setY(int y) {  //y좌표 설정
        wordy = y;
    }
};

void gotoxy(int x, int y) { //콘솔창 원하는 위치로 커서 이동
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

string generateString(string option) {  //랜덤 문자열을 생성하는 함수
    srand(static_cast<unsigned int>(time(nullptr)));
    string randomString;    //반환할 문자열
    for (int i = 0; i < WORD_LENGTH && i < option.length(); ++i) {
        int index = rand() % option.length();
        randomString += option[index];
    }

    if (speed_cnt > 2) {    //문자열을 3개 생성할 때마다 하강 속도 랜덤 조정
        speed = (rand() % 3 + 1) * 1000;
        speed_cnt = 0;
    }
    speed_cnt++;

    return randomString;
}

void printString(list<MyString>& list) {    //문자열을 출력하는 함수
    std::list<MyString>::iterator it = list.begin();
    //for문을 돌면서 리스트에 있는 문자열을 출력함
    for (it = list.begin(); it != list.end(); it++) {
        gotoxy(it->getX(), it->getY());
        cout << it->getStr();
    }
}

void down(list<MyString>& list) {   //문자열을 하강시키는 함수
    std::list<MyString>::iterator it = list.begin();
    //for문을 돌면서 리스트에 있는 문자열의 wordy를 1 증가시켜 한 칸 하강하도록 함
    for (it = list.begin(); it != list.end(); it++) {
        it->setY(it->getY() + 1);
    }
}

void handleInput(list<MyString>& myStringList, string& input, int& hp) {
    while (hp > 0) {
        while (_kbhit()) {
            char ch = _getch();
            if (ch == 13) { //엔터키 입력시
                {
                    lock_guard<mutex> lock(mtx);
                    list<MyString>::iterator it = myStringList.begin();

                    //리스트를 순회하며 입력과 동일한 문자열을 찾음
                    while (it != myStringList.end()) {
                        if (input == it->getStr()) {//찾으면 리스트에서 문자열 삭제, 점수 10 증가    
                            it = myStringList.erase(it);
                            score += 10;
                            //사라지는 문자열이 최상단 문자열이면 새로운 문자열 생성
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

                input = ""; //사용자 입력 비우기
            }
            else if (ch == 8) { //백스페이스키 입력시
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

void getOption() {  //게임 시작 전 랜덤 문자열의 구성을 입력받는 함수
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

    list<MyString> myStringList;    //문자열을 저장하는 리스트
    myStringList.push_back(MyString(generateString(option)));
    int hp = MAX_HEALTH;    //hp를 최대 체력으로 설정

    string input;   //사용자 입력
    //사용자 입력 딜레이를 줄이기 위해 입력을 받는 스레드 생성
    thread inputThread(handleInput, ref(myStringList), ref(input), ref(hp));

    while (hp > 0) {
        {
            lock_guard<mutex> lock(mtx); //Lock the mutex
            cout << "\033[2J\033[H";    //화면 클리어
            for (int i = 0; i < SCREEN_HEIGHT; i++) {
                for (int j = 0; j < 5; j++) {
                    cout << "|         ";
                }
                cout << "\n";

            }

            gotoxy(0, SCREEN_HEIGHT);   //좌측 하단에 hp와 사용자 입력 출력
            cout << "-----------------------------------------" << endl;
            cout << "Your hp: " << hp << endl;
            cout << "Your input: " << input;

            printString(myStringList);  //문자열 출력

            down(myStringList); //문자열 하강

            if (prev(myStringList.end())->getY() > 3) {//문자열이 생성되고 3칸 하강한 후에 새로운 문자열 생성
                myStringList.push_back(MyString(generateString(option)));
            }

            //문자열이 바닥에 닿으면 리스트에서 제거하고 hp 10 깎음
            if (myStringList.begin()->getY() == SCREEN_HEIGHT) {
                myStringList.pop_front();
                hp -= 10;
            }
        }

        Sleep(speed);   //하강 속도 조절
    }

    inputThread.join(); //스레드 종료 기다림

    //화면 클리어하고 점수(입력한 문자열의 수 * 10) 출력
    cout << "\033[2J\033[H";
    cout << "Game Over! Your score is " << score << " points!";

    return 0;
}
