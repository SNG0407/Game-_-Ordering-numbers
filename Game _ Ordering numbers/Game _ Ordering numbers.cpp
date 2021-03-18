// 숫자퍼즐 게임.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <time.h>

#include <conio.h> //콘솔 창에서 입출력 하는 기능들을 제공해주는 헤더 파일

using namespace std;
int main()
{
    srand((unsigned int)time(0));

    int iNumber[25] = {};

    for (int i = 0; i < 24; i++) {
        iNumber[i] = i + 1;
    }

    iNumber[24] = INT_MAX;

    int iStarIndex = 24; // 인트 멕스의 위치

    int iTemp, idx1, idx2;
    for (int i = 0; i < 100; i++) {
        idx1 = rand() % 24;//idx1 은 0~23까지 랜덤 숫자
        idx2 = rand() % 24;

        iTemp = iNumber[idx1];
        iNumber[idx1] = iNumber[idx2];
        iNumber[idx2] = iTemp;
    }

    while (true) {
        system("cls");

        //줄번호 * 가로 개수 + 칸 번호 /이걸 내가 찾아내다니 ㅋㅋ
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (iNumber[(i * 5) + j] < 10) {
                    cout << "[0" << iNumber[(i * 5) + j] << "]" << "\t";
                }
                else if (iNumber[i * 5 + j] == INT_MAX) {
                    cout << "[" << " *" << "]" << "\t";
                }
                else {
                    cout << "[" << iNumber[(i * 5) + j] << "]" << "\t";
                }
            }
            cout << "\n";
        }
        bool bWin = true;
        //퍼즐 맞췄는지 확인하기 --> 확인은 셔플을 안해보면 됨
        for (int i = 0; i < 24; i++) {
            if (iNumber[i] != i + 1) {
                bWin = false;
                break;
            }
        }
        if (bWin == true) {
            cout << "숫자를 다 맞췄습니다." << endl;
        }
        cout << "w : 위 // s : 아래 // a : 왼쪽 // d : 오른쪽 // q : 종료" << endl;
        char cInput = _getch(); // getch 함수는 문자 1개를 받자마자 입력받는 함수 Enter를 치지 않아도 문자 반환해줌
        if (cInput == 'q' || cInput == 'Q') {
            break;
        }
        switch (cInput) {

            //위로 가는 기능
        case 'w':
        case 'W':

            if (iStarIndex >= 5) {
                iTemp = iNumber[iStarIndex];
                iNumber[iStarIndex] = iNumber[iStarIndex - 5];
                iNumber[iStarIndex - 5] = iTemp;
                iStarIndex -= 5;
            }
            /*else {
                continue;
            }*/ //필요 없는 코드였네
            break;

            //밑으로 가는 기능
        case 's':
        case 'S':
            if (iStarIndex < 20) {
                iTemp = iNumber[iStarIndex];
                iNumber[iStarIndex] = iNumber[iStarIndex + 5];
                iNumber[iStarIndex + 5] = iTemp;
                iStarIndex += 5;
            }
            break;

            //왼쪽으로 가는 기능
        case 'a':
        case 'A':
            if ((iStarIndex) % 5 != 0) {
                iTemp = iNumber[iStarIndex];
                iNumber[iStarIndex] = iNumber[iStarIndex - 1];
                iNumber[iStarIndex - 1] = iTemp;
                iStarIndex -= 1;
            }
            break;

            //오룬쪽으로 가는 기능
        case 'd':
        case 'D':
            if ((iStarIndex + 1) % 5 != 0) { // i % 5 != 4 도 같은 말이야
                iTemp = iNumber[iStarIndex];
                iNumber[iStarIndex] = iNumber[iStarIndex + 1];
                iNumber[iStarIndex + 1] = iTemp;
                iStarIndex += 1;
            }
            break;


        }

    }
    cout << "게임을 종료합니다." << endl;
    return 0;
}
