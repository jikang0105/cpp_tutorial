#include <iostream>
#include <time.h>

using namespace std;

int main() {

	/*
	반복문 : 특정 작업을 반복해서 수행해주는 기능이다.
	종류 : for, while, do while 3종류가 존재한다.
	while(조건식) {} 의 형태로 구성된다.
	while문은 조건식을 체크해서 true일 경우 코드블럭 안의 코드가 동작되고 다시 조건식을 체크한다.
	조건식이 false가 되면 while문을 빠져나오게 된다.
	반복문 안에서 break를 만나게 되면 해당 반복문을 빠져나오게 된다.
	*/

	int iNumber = 0;

	while (iNumber < 10) {
		cout << iNumber << endl;
		++iNumber;

		if (iNumber == 4)
			break;
	}

	// 화면을 깨끗히 지워준다.
	system("cls");

	// 난수테이블 생성
	srand((unsigned int)time(0));

	enum RPS {
		RPS_R = 1,
		RPS_P,
		RPS_S,
		RPS_END
	};

	int iPlayer;
	int iAI;

	while (true) {
		cout << " 주먹(1), 보자기(2), 가위(3), 종료(4) 중에서 하나를 선택하세요 : " << endl;
		cin >> iPlayer;

		if (iPlayer < RPS_R || iPlayer > RPS_END) {
			cout << "잘못된 값을 입력하였습니다." << endl;
			// 일시정지
			system("pause");
			// 반복문의 시작점으로 이동시켜주는 기능
			continue;
		}

		else if (iPlayer == RPS_END) {
			break;
		}

		// 봇이 선택을 한다.
		iAI = (rand() % RPS_S) + RPS_R;

		switch (iAI) {
		case RPS_R:
			cout << "AI는 주먹을 냈습니다. ";
			break;
		case RPS_P:
			cout << "AI는 보자기를 냈습니다. ";
			break;
		case RPS_S:
			cout << "AI는 가위를 냈습니다. ";
			break;
		}
		/*
		if (iPlayer == iAI) {
			cout << "게임에서 비겼습니다." << endl;
		}

		else if (iPlayer + 1 == iAI || iPlayer - 2 == iAI) {
			cout << "게임어서 졌습니다." << endl;
		}

		else {
			cout << "게임에서 이겼습니다." << endl;
		}
		*/
		
		int iWin = iPlayer - iAI;

		/*
		if (iWin == 1 || iWin == -2) {
			cout << "Player 승리" << endl;
		}
		else if (iWin == 0) {
			cout << "비김" << endl;
		}
		else {
			cout << "AI 승리" << endl;
		}
		*/

		switch (iWin) {
		case 1:
		case -2:
			cout << "Player 승리" << endl;
			break;
		case 0:
			cout << "비김" << endl;
			break;
		default:
			cout << "AI 승리" << endl;
			break;
		}
		system("pause");
	}

	return 0;
}