/*
야구게임 만들기 
1 ~ 9 사이의 랜덤한 숫자 3개를 얻어온다. 단, 숫자는 중복되어서는 안된다.
3개의 숫자는 * * * 의 형태로 출력되고 이 3개의 숫자를 맞추는 게임이다.
사용자는 이 3개의 숫자를 맞출때까지 계속해서 3개씩 숫자를 입력한다.
만약 맞춰야할 숫자가 7 3  8 일 경우
사용자는 3 개의 숫자를 계속 입력한다.

1 2 4 를 입력했을 경우 1 2 4 는 맞춰야할 숫자 중 아무것도 없으므로 Out을 출력한다.

7 5 9 를 입력했을 경우 7은 맞춰야할 숫자중 있고 위치도 같으므로 strike이다.
5 9는 없으므로 출력은 1strike 0ball을 출력한다.

7 8 6 을 입력했을 경우 7은 1strike 8은 숫자는 있지만 위치가 다르므로 ball이 된다.
1strike 1ball을 출력한다.

이렇게 출력을 하고 입력을 받으면서 최종적으로 3개의 숫자를 자리까지 모두 일치하게 입력하면
게임이 종료된다. 만약 입력받은 숫자 3개중 한개라도 0이 있을경우 게임을 종료한다.*/

#include <iostream>
#include <time.h>

using namespace std;

int main() {

	srand((unsigned int)time(0));

	int iOtoN[9] = { 0 };

	for (int i = 0; i < 9; ++i) {
		iOtoN[i] = i + 1;
	}

	int iTemp, iDx1, iDx2;

	for (int i = 0; i < 100; ++i) {
		iDx1 = rand() % 9;
		iDx1 = rand() % 8;

		iTemp = iOtoN[iDx1];
		iOtoN[iDx1] = iOtoN[iDx2];
		iOtoN[iDx2] = iTemp;
	}

	// iOtoN[0], iOtoN[1], iOtoN[2]가 1~9의 숫자 중 랜덤으로 정해짐.

	int iPn[3] = { 0 };

	cout << "재미있는 야구게임!" << endl;
	cout << "computer가 3개의 숫자를 정했습니다. 숫자와 순서를 맞춰주세요.";
	cout << "(입력한 숫자중 0이 있으면 게임이 종료됩니다.)" << endl;

	int iStrike = 0;
	int iBall = 0

	while (true) {
		cout << "입력 : ";
		cin >> iPn[0], iPn[1], iPn[2];
				
		// iPn[0]을 0, iOtoN[]들과 비교
		for (int i = 0; i < 4; ++i) {
			if (iPn[i] == 0) {
				cout << "0을 입력하셨으므로 게임이 종료됩니다." << endl;
				break;
			}
			
			if (iPn[i] == iOtoN[0]) {
				if (i == 0) {
					++iStrike;
				}
				else {
					++iBall;
				}
			}
			
			if (iPn[i] == iOtoN[1]) {
				if (i == 1) {
					++iStrike;
				}
				else {
					++iBall;
				}
			}

			if (iPn[i] == iOtoN[2] {
				if (i == 2) {
					++iStrike;
				}
				else {
					++iBall;
				}
			}
		}

		cout << iStrike << "strike, " << iBall << "ball" << endl;

		// 3strike 3개의 숫자와 위치를 모두 맞췄을 경우
		if (iPn[0] == iOtoN[0] && iPn[1] == iOtoN[1] && iPn[3] == iOtoN[3]) {
			cout << "게임에서 승리하셨습니다." << endl;
			break;
		}


		// 0을 입력할 경우
		//if (iPn[0] == 0 || iPn[1] == 0 || iPn[2] == 0) {
		//	cout << "0을 입력하셨으므로 게임이 종료됩니다." << endl;
		//	break;
		//}


		// 숫자와 위치 하나도 맞추지 못했을 경우
		else if(iPn[0])

		// 3개의 숫자와 위치를 맞췄을 경우
		else if (iPn[0] == iOtoN[0] && iPn[1] == iOtoN[1] && iPn[3] == iOtoN[3]) {
			cout << "게임에서 승리하셨습니다." << endl;
			break;
		}
		// 숫자와 위치 하나도 맞추지 못
	}

}