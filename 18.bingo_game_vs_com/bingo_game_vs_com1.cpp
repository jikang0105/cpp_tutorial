#include <iostream>
#include <time.h>

using namespace std;

enum AI_MODE {
	AM_EASY = 1,
	AM_HARD
};

enum LINE_NUMBER {
	LN_H1,	LN_H2,	LN_H3,	LN_H4,	LN_H5,
	LN_V1,	LN_V2,	LN_V3,	LN_V4,	LN_V5,
	LN_D1,  LN_D2
};

int main() {
	
	srand((unsigned int)time(0));

	int iNumber[25] = {};
	int iAINumber[25] = {}; // ai용 숫자 배열
		
	for (int i = 0; i < 25; ++i) {
		iNumber[i] = i + 1;
		iAINumber[i] = i + 1; // ai용 숫자 기입
	}

	int iTemp, iDx1, iDx2;

	for (int i = 0; i < 100; ++i) {
		iDx1 = rand() % 25;
		iDx2 = rand() % 25;

		iTemp = iNumber[iDx1];
		iNumber[iDx1] = iNumber[iDx2];
		iNumber[iDx2] = iTemp;

		// ai 숫자 섞기
		iDx1 = rand() % 25;
		iDx2 = rand() % 25;

		iTemp = iAINumber[iDx1];
		iAINumber[iDx1] = iAINumber[iDx2];
		iAINumber[iDx2] = iTemp;
	}

	int iBingo = 0, iAIBingo = 0;
	int iAIMode;

	// AI난이도를 선택한다.
	while(true){
		system("cls");
		cout << "1. Easy" << endl;
		cout << "2. Hard" << endl;
		cout << "AI 모드를 선택하세요. : ";
		
		cin >> iAIMode;

		if (iAIMode >= AM_EASY && iAIMode <= AM_HARD) {
			break;
		}
	}


	
	// 선택 안된 목록 배열을 만들어준다.
	int iNoneSelect[25] = {};
	// 선택 안된 숫자 개수를 저장한다.
	int iNoneSelectCount = 0;

	int iAIInput = NULL;

	while (true) {

		system("cls");

		cout << "============= Player ==============" << endl;
		for (int i = 0; i < 5; ++i) {
			for (int j = 0; j < 5; ++j) {
				if(iNumber[i * 5 + j] == INT_MAX){
					cout << "*\t";
				}
				else {
					cout << iNumber[i * 5 + j] << "\t";
				}
			}
			cout << endl;
		}

		cout << "Bingo Line : " << iBingo << endl << endl;

		// ai 빙고판 출력
		cout << "============= AI ==============" << endl;

		switch (iAIMode) {
		case AM_EASY:
			cout << "AIMode : Easy" << endl;
			break;
		case AM_HARD:
			cout << "AIMode : Hard" << endl;
			break;
		}

		for (int i = 0; i < 5; ++i) {
			for (int j = 0; j < 5; ++j) {
				if (iAINumber[i * 5 + j] == INT_MAX) {
					cout << "*\t";
				}
				else {
					cout << iAINumber[i * 5 + j] << "\t";
				}
			}
			cout << endl;
		}

		// ai 빙고 줄 수를 출력한다.
		cout << "AIBingo Line : " << iAIBingo << endl;


		if (iBingo >= 5) {
			cout << "5줄 이상의 빙고를 완성했습니다. Player 승리." << endl;
			break;
		}
		else if (iAIBingo >= 5) {
			cout << "AI 승리" << endl;
			break;
		}

		cout << "AI가 숫자 '" << iAIInput << "'을(를) 선택했습니다." << endl;
		cout << "숫자를 입력하세요(0 : 종료) : ";
		int iInput = 0;
		
		cin >> iInput;

		if (iInput == 0) {
			break;
		}
		else if (iInput < 1 || 25 < iInput) {
			continue;
		}

		bool bAcc = true;

		for (int i = 0; i < 25; ++i) {
			if (iInput == iNumber[i]) {
				bAcc = false;
				iNumber[i] = INT_MAX;
				break;
			}
		}

		if (bAcc) {
			continue;
		}

		// 중복이 아니라면 AI의 숫자도 찾아서 *로 바꿔준다.
		for (int i = 0; i < 25; ++i) {
			if (iInput == iAINumber[i]) {
				iAINumber[i] = INT_MAX;
				break;
			}
		}
		
		//AI가 선택을 한다. AI가 선택하는 것은 AI모드에 따라서 달라진다.
		switch (iAIMode) {
			/*
			AI Easy 모드는 현재 AI의 숫자 목록 중 *로 바뀌지 않은 숫자 목록을 만들어서
			그 목록중 하나를 선택하게 한다.(랜덤하게)
			*/
		case AM_EASY:
			// 선택안된 숫자목록을 만들어준다.
			// 선택안된 숫자 개수는 목록을 만들때 카운팅해준다.
			iNoneSelectCount = 0;
			for (int i = 0; i < 25; ++i) {
				// 현재숫자가 *이 아닐경우
				if(iAINumber[i] != INT_MAX) {
					// *이 아닌 숫자일 경우 iNoneSelectCount를 인덱스로 활용한다.
					// 선택 안된 목록에 추가할때마다 개수를 1씩 증가시켜서 총 선택안된 개수를 
					// 구해준다.
					// 그런데 0부터 카운트가 시작이므로 0번에 넣고 ++해서 1개 추가되었다라고
					// 한다.
					iNoneSelect[iNoneSelectCount] = iAINumber[i];
					++iNoneSelectCount;
				}
			}

			// for문을 빠져나오게 되면 선택안된 목록이 만들어지고
			// 선택안된 목록의 개수가 만들어지게 된다.
			// 선택안된 목록의 숫자중 랜덤한 하나의 숫자를 얻어오기 위해 
			// 인덱스를 랜덤하게 구해준다.

			
			iAIInput = iNoneSelect[rand() % iNoneSelectCount];

			break;
		case AM_HARD:
			// 하드모드는 현재 숫자중 빙고줄 완성 가능성이 가장 높은 줄을
			// 찾아서 그 줄에 있는 숫자중 하나를 *로 만들어준다.
			int iLine = 0;
			int iStarCount = 0;
			int iSaveCount = 0;

			// 가로 라인 중 가장 *이 많은 라인을 찾아낸다.
			for (int i = 0; i < 5; ++i) {
				// iStarCount변수 초기화를 통해 줄마다 별이 몇개있는지 확인할 수 있다.
				iStarCount = 0;
				for (int j = 0; j < 5; ++j) {
					if (iAINumber[i * 5 + j] == INT_MAX) {
						++iStarCount;
					}
				
				}
				// 별이 5개 미만이어야 하고 빙고 줄이 아니고 
				// 기존에 별이 가장 많은 라인의 별보다 별이 많아야 가장 많은 라인이므로
				// 교체해주고 저장된 별 수를 교체한다.
				if (iStarCount < 5 && iSaveCount < iStarCount) {
					iLine = i;
					iSaveCount = iStarCount;
				}
			}

			// 가로 라인중 가장 별이 많은 라인과 세로 라인들을 비교하여 별이 가장 많은
			// 라인을 구한다.
			for (int i = 0; i < 5; ++i) {
				iStarCount = 0;
				for (int j = 0; j < 5; ++j) {
					if (iAINumber[j * 5 + i] == INT_MAX) {
						++iStarCount;
					}
				}
				if (iStarCount < 5 && iSaveCount < iStarCount) {
					// 세로라인은 5 ~ 9로 의미를 부여했다.
					iLine = i + 5;
					iSaveCount = iStarCount;
				}
			}

			// 왼쪽 -> 오른쪽 대각선 체크
			iStarCount = 0;
			for (int i = 0; i < 25; i += 6) {
				if (iAINumber[i] == INT_MAX) {
					++iStarCount;
				}
			}
			if (iStarCount < 5 && iSaveCount < iStarCount) {
				iLine = LN_D1;
				iSaveCount = iStarCount;
			}

			// 오른쪽 -> 왼쪽 대각선 체크
			iStarCount = 0;
			for (int i = 4; i <=20; i += 4) {
				if (iAINumber[i] == INT_MAX) {
					++iStarCount;
				}
			}
			if (iStarCount < 5 && iSaveCount < iStarCount) {
				iLine = LN_D2;
				iSaveCount = iStarCount;
			}
			
			// 모든 라인을 조사했으면 iLine에 가능성이 가장 높은 줄 번호가 저장된다.
			// 그 줄에 있는 *이 아닌 숫자중 하나를 선택하게 한다.
			// 가로줄일 경우
			if (iLine <= LN_H5) {
				// 가로줄일 경우 iLine이 0 ~ 4 사이의 값이다.
				for (int i = 0; i < 5; ++i) {
					// 현재 줄에서 *이 아닌 숫자를 찾아낸다.
					if(iAINumber[iLine * 5 + i] != INT_MAX){
						iAIInput = iAINumber[iLine * 5 + i];
						break;
					}
				}
			}
			else if (iLine <= LN_V5) {
				// 세로줄일 경우 iLine이 5~9 사이의 값이다.
				for (int i = 0; i < 5; ++i) {
					if (iAINumber[i * 5 + (iLine - 5)] != INT_MAX) {
						iAIInput = iAINumber[i * 5 + (iLine - 5)];
						break;
					}
				}
			}
			else if (iLine == LN_D1) {
				for (int i = 0; i < 25; i += 6) {
					if (iAINumber[i] != INT_MAX) {
						iAIInput = iAINumber[i];
						break;
					}
				}
			}
			else if (iLine == LN_D2) {
				for (int i = 4; i <= 20; i += 4) {
					if (iAINumber[i] != INT_MAX) {
						iAIInput = iAINumber[i];
						break;
					}
				}
			}
			break;
		}

		// AI가 숫자를 선택했으므로 플레이어와 AI의 숫자를 *로 바꿔준다.
		for (int i = 0; i < 25; ++i) {
			if (iNumber[i] == iAIInput) {
				iNumber[i] = INT_MAX;
				break;
			}
		}

		// AI 숫자를 바꿔준다.
		for (int i = 0; i < 25; ++i) {
			if (iAINumber[i] == iAIInput) {
				iAINumber[i] = INT_MAX;
				break;
			}
		}

		/*
		// AI가 숫자를 선택한다.
		bool bAIAcc = true;
		
		
		while (bAIAcc) {
			cout << "AI가 숫자를 선택합니다. : ";
			int iAIInput = rand() % 25 + 1;

			
			for (int i = 0; i < 25; ++i) {
				if (iAIInput == iAINumber[i]) {
					bAIAcc = false;
					iAINumber[i] = INT_MAX;
					break;
				}
			}

			if (bAIAcc) {
				continue;
			}

			for (int i = 0; i < 25; ++i) {
				if (iAIInput == iNumber[i]) {
					iNumber[i] = INT_MAX;
					break;
				}
			}
		}
		*/



		int iHo[5] = {}, iVer[5] = {}, iDia[2] = {};
		int iAIHo[5] = {}, iAIVer[5] = {}, iAIDia[2] = {};

		for (int i = 0; i < 5; ++i) {
			for (int j = 0; j < 5; ++j) {
				if (iNumber[i * 5 + j] == INT_MAX) {
					++iHo[i], ++iVer[j];
					if (i == j) {
						++iDia[0];
					}
					if (i + j == 4) {
						++iDia[1];
					}
				}
				if (iAINumber[i * 5 + j] == INT_MAX) {
					++iAIHo[i], ++iAIVer[j];
					if (i == j) {
						++iAIDia[0];
					}
					if (i + j == 4) {
						++iAIDia[1];
					}
				}
			}
		}

		iBingo = 0;
		iAIBingo = 0;

		for (int i = 0; i < 5; ++i) {
			if (iHo[i] == 5 || iVer[i] == 5) {
				++iBingo;
			}
			if (iAIHo[i] == 5 || iAIVer[i] == 5) {
				++iAIBingo;
			}
		}

		for (int i = 0; i < 2; ++i) {
			if (iDia[i] == 5) {
				++iBingo;
			}
			if (iAIDia[i] == 5) {
				++iAIBingo;
			}
		}

	}

}