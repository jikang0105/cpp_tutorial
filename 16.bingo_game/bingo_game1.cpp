/*
숫자 빙고게임을 만들어 보자.
1 ~ 25까지의 숫자가 있고 이 숫자를 골고루 섞어서 5 X 5로 출력한다
플레이어에게 숫자를 입력받는다. 1 ~ 25 사이의 숫자를 입력받아야 한다.
0을 입력하면 게임을 종료한다.

숫자를 입력받았으면 숫자목록중 입력받은 숫자를 찾아서 *로 만들어 준다.
숫자를 *로 만든 후에 빙고 줄 수를 체크한다 5 X 5이기 때문에 가로 5줄 세로 5줄
대각선 2줄이 나올 수 있다. 빙고줄이 몇줄인지를 체크해서 화면에 보여준다.
5줄 이상일 경우 게임을 종료한다.
*/

#include <iostream>
#include <time.h>

using namespace std;

int main() {
	srand((unsigned int)time(0));

	int iNumber[25] = {};

	// 1 ~ 25 까지 숫자를 넣어준다.
	for (int i = 0; i < 25; ++i) {
		iNumber[i] = i + 1;
	}

	// 숫자를 섞어준다.
	int iTemp, iDx1, iDx2;
	for (int i = 0; i < 100; ++i) {
		iDx1 = rand() % 25;
		iDx2 = rand() % 25;

		iTemp = iNumber[iDx1];
		iNumber[iDx1] = iNumber[iDx2];
		iNumber[iDx2] = iTemp;
	}

	int iBingo = 0;

	while (true) {
		system("cls");

		// 숫자를 5 x 5로 출력한다.
		for (int i = 0; i < 5; ++i) {
			for (int j = 0; j < 5; ++j) {
				if (iNumber[i * 5 + j] == INT_MAX) {
					cout << "*\t";
				}
				else {
					cout << iNumber[i * 5 + j] << "\t";
				}
			}

			cout << endl;
		}
		
		cout << "Bingo Line : " << iBingo << endl;

		// 줄수가 5이상일 경우 게임을 종료한다.
		if (iBingo >= 5) {
			break;
		}

		cout << "숫자를 입력하세요(0 : 종료) : ";
		int iInput;
		cin >> iInput;

		if (iInput == 0) {
			break;
		}
		else if (iInput < 1 || iInput > 25) {
			continue;
		}

		// 중복입력을 체크하기 위한 변수이다. 기본적으로 중복되었다라고 하기위해
		// true로 잡아주었다.
		bool bAcc = true;

		// 모든 숫자를 차례대로 검사해서 입력한 숫자와 같은 숫자가 있는지를 찾아낸다.
		for (int i = 0; i < 25; ++i) {
			// 같은 숫자가 있을경우
			if (iInput == iNumber[i]) {
				// 숫자를 찾았을 경우 중복된 숫자가 아니므로 bAcc변수를 false로 만든다.
				bAcc = false;

				//숫자를 *로 변경하기위해 특수한 값인 INT_MAX로 해준다.
				iNumber[i] = INT_MAX;

				//더이상 다른 숫자를 찾아볼 필요가 없으므로 for문을 빠져나간다.
				break;
			}
		}

		// bAcc 변수가 true일 경우 중복된 숫자를 입력해서 숫자를 *로 바꾸지 못했으므로
		// 다시 입력받게 continue해준다.
		if (bAcc) {
			continue;
		}

		// 빙고 줄 수를 체크하는 것은 매번 숫자를 입력할때마다 처음부터 새로 카운트를 할것이다.
		// 그러므로 iBingo 변수를 0으로 매번 초기화 하고 새롭게 줄 수를 구해주도록 한다.
		iBingo = 0;

		// 가로, 세로 줄 수를 구해준다.
		int iStar1 = 0, iStar2 = 0;
		for (int i = 0; i < 5; ++i) {
			// 한줄을 체크하기 전에 먼저 0으로 별 개수를 초기화 한다.
			iStar1 = iStar2 = 0;
			for (int j = 0; j < 5; ++j) {
				// 가로 별 개수를 구해준다.
				if (iNumber[i * 5 + j] == INT_MAX) {
					++iStar1;
				}
				// 세로 별 개수를 구해준다.
				if (iNumber[j * 5 + i] == INT_MAX) {
					++iStar2;
				}
			}

			// j for문을 빠져나오고 나면 현재 줄의 가로 별 개수가 몇개인지
			// iStar1변수에 들어가게 된다. iStar1의 값이 5이면 한줄이 모두 *이라는
			// 의미이므로 빙고 줄 카운트를 추가해준다.
			if (iStar1 == 5) {
				++iBingo;
			}
			if (iStar2 == 5) {
				++iBingo;
			}

			// 왼쪽상단에서 오른쪽 하단으로 가는 대각선 체크
			iStar1 = 0;
			for (int i = 0; i < 25; i += 6) {
				if (iNumber[i] == INT_MAX) {
					++iStar1;
				}
			}

			if (iStar1 == 5) {
				++iBingo;
			}

			// 오른쪽 상단에서 왼쪽 하단으로 가는 대각선 체크
			iStar1 = 0;
			for (int i = 4; i <= 20; i += 4) {
				if (iNumber[i] == INT_MAX) {
					++iStar1;
				}
			}

			if (iStar1 == 5) {
				++iBingo;
			}
		}
	}


	/*int iNumber[26] = {};


	for (int i = 0; i < 25; ++i) {
		iNumber[i] = i + 1;
	}

	iNumber[25] = INT_MAX;
	int iStarIndex = 25;

	int iTemp, iDx1, iDx2;

	for (int i = 0; i < 100; ++i) {
		iDx1 = rand() % 25;
		iDx2 = rand() % 25;

		iTemp = iNumber[iDx1];
		iNumber[iDx1] = iNumber[iDx2];
		iNumber[iDx2] = iTemp;
	}

	
	while (true) {

		system("cls");

		int iHo[5] = {}, iVer[5] = {}, iDia[2] = {};
		int iBingo = 0;


		for (int i = 0; i < 5; ++i) {
			for (int j = 0; j < 5; ++j) {
				if (iNumber[i * 5 + j] == INT_MAX) {
					cout << "*\t";
				}
				else {
					cout << iNumber[i * 5 + j] << "\t";
				}
			}
			cout << endl;
		}

		for (int i = 0; i < 5; ++i) {
			for(int j = 0; j < 5; ++j) {
				if(iNumber[i * 5 + j] == INT_MAX){
					++iHo[i];
					++iVer[j];
					if (i == j) {
						++iDia[0];
					}
					if (i + j == 4) {
						++iDia[1];
					}
				}
				
			}
		}

		cout << "iHo[0] : " << iHo[0] << ", iVer[0] : " << iVer[0] << endl;
		cout << "iHo[1] : " << iHo[1] << ", iVer[1] : " << iVer[1] << endl;
		cout << "iHo[2] : " << iHo[2] << ", iVer[2] : " << iVer[2] << endl;
		cout << "iHo[3] : " << iHo[3] << ", iVer[3] : " << iVer[3] << endl;
		cout << "iHo[4] : " << iHo[4] << ", iVer[4] : " << iVer[4] << endl;
		cout << "iDia[0] : " << iDia[0] << ", iDia[1] : " << iDia[1] << endl;
		

		for (int i = 0; i < 5; ++i) {
			if (iHo[i] == 5 || iVer[i] == 5) {
				++iBingo;
			}
		}

		for (int i = 0; i < 2; ++i) {
			if (iDia[i] == 5) {
				++iBingo;
			}
		}

		if (iBingo == 5) {
			cout << "5빙고를 완성했습니다." << endl;
			break;
		}

		cout << "iBingo : " << iBingo << endl;


		cout << "숫자를 입력하세요.(0 : 종료) : ";
		int iInput;
		cin >> iInput;

		if (0 > iInput && iInput > 25) {
			continue;
		}

		if (iInput == 0) {
			break;
		}

		for (int i = 0; i < 25; ++i) {
			if (iInput == iNumber[i]) {
				iNumber[i] = iNumber[iStarIndex];

				continue;
			}
		}

	}
	cout << endl << "게임을 종료합니다." << endl;*/
}