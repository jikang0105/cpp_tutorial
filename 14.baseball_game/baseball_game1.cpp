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

	// 1 ~ 9 까지 숫자를 설정한다.
	for (int i = 0; i < 9; ++i) {
		iOtoN[i] = i + 1;
	}

	// 설정된 숫자를 섞어준다.
	int iTemp, iDx1, iDx2;

	for (int i = 0; i < 100; ++i) {
		iDx1 = rand() % 9;
		iDx2 = rand() % 9;

		iTemp = iOtoN[iDx1];
		iOtoN[iDx1] = iOtoN[iDx2];
		iOtoN[iDx2] = iTemp;
	}

	cout << " * * * " << endl;
	
	int iStrike = 0, iBall = 0;
	int iPn[3] = { 0 };
	int iGameCount = 1;

	cout << "재미있는 야구게임!" << endl;
	cout << "computer가 3개의 숫자를 정했습니다. 숫자와 순서를 맞춰주세요.";
	cout << "(입력한 숫자 중 0이 있으면 게임이 종료됩니다.)" << endl;



	while (true) {
		cout << iGameCount << " 회" << endl;
		cout << "입력 : ";
		cin >> iPn[0] >> iPn[1] >> iPn[2];
		cout << iPn[0] << iPn[1] << iPn[2] << endl;

		// 종료 또는 예외 조건
		if (iPn[0] == 0 || iPn[1] == 0 || iPn[2] == 0) {
			break;
		}
		else if (iPn[0] < 0 || iPn[0] > 9 || iPn[1] < 0 || iPn[1] > 9 ||
			iPn[2] < 0 || iPn[2] > 9) {
			cout << "잘못된 숫자를 입력하였습니다." << endl;
			continue;
		}
		else if (iPn[0] == iPn[1] || iPn[0] == iPn[2] || iPn[1] == iPn[2]) {
			cout << "중복된 숫자를 입력하였습니다." << endl;
			continue;
		}

		// 매번 iStrike와 iBall의 수가 달라지기 때문에 0으로 초기화 하고 다시 계산한다.
		iStrike = iBall = 0;

		// i for문은 맞춰야 할 숫자의 인덱스를 구한다.
		for (int i = 0; i < 3; ++i) {

			// j for문은 입력받은 숫자의 인덱스를 구한다.
			for (int j = 0; j < 3; ++j) {

				// i가 0일때 j는 0 ~ 2 까지 반복하게 된다. 즉, 맞춰야할 숫자의 첫번째 값과
				// 입력받은 숫자의 첫번째, 두번째, 세번째를 차례대로 비교하여
				// 같은 값이 있는지를 찾아낸다.
				if (iOtoN[i] == iPn[j]) {

					// 같은 값이 있을 경우 iStrike 아니면 iBall 이므로 자리가 같은 지를
					// 체크해본다. i 와 j는 현재 맞춰야할 숫자의 인덱스와 입력받은 숫자의
					// 인덱스이고 두 값이 같으므로 이 인덱스가 곧 위치가 된다. 인덱스가
					// 서로 같을경우 자리까지 같다는 의미이므로 Strike를 증가하고 
					// 그게 아니라면 자리가 다르다는 의미이므로 Ball을 증가시킨다.
					if (i == j) {
						++iStrike;
					}
					else {
						++iBall;
					}

					// 입력받은 숫자와 맞춰야할 숫자를 비교할때 같은 수가 있으면 이 뒤로는
					// 더이상 같은 수가 없으므로 다음 맞춰야 할 숫자로 바로 비교하면 된다.
					// 그래서 break를 해서 j for문을 빠져나가고 ++i가 되게 하여 다음 맞춰야할
					// 숫자와 다시 비교하게 한다.
					break;
				}
			}
		}

		if (iStrike == 3) {
			cout << "숫자를 모두 맞췄습니다." << endl;
			break;
		}
		else if (iStrike == 0 && iBall == 0) {
			cout << "Out" << endl;
		}
		else {
			cout << iStrike << "strike " << iBall << "ball" << endl;
		}

		++iGameCount;
		/*
		istrike = iball = 0;

		// ipn[0]을 0, ioton[]들과 비교
		for (int i = 0; i < 3; ++i) {
			if (ipn[i] == 0) {
				cout << "0을 입력하셨으므로 게임이 종료됩니다." << endl;
				break;
			}

			if (ipn[i] == ioton[0]) {
				if (i == 0) {
					++istrike;
				}
				else {
					++iball;
				}
			}

			if (ipn[i] == ioton[1]) {
				if (i == 1) {
					++istrike;
				}
				else {
					++iball;
				}
			}

			if (ipn[i] == ioton[2]) {
				if (i == 2) {
					++istrike;
				}
				else {
					++iball;
				}
			}

		}

		// 3strike 3개의 숫자와 위치를 모두 맞췄을 경우
		if (ipn[0] == ioton[0] && ipn[1] == ioton[1] && ipn[2] == ioton[2]) {
			cout << istrike << "strike, " << iball << "ball" << endl;
			cout << "게임에서 승리하셨습니다." << endl;
			break;
		}

		if (istrike == 0 && iball == 0) {
			cout << "out!" << endl;
			continue;
		}
		else {
			cout << istrike << "strike, " << iball << "ball" << endl;
			continue;
		}
	}
	*/
	}
}