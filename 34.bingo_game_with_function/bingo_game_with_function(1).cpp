#include <iostream>
#include <time.h>

using namespace std;

enum AI_MODE {
	AM_EASY = 1,
	AM_HARD
};

enum LINE_NUMBER {
	LN_H1, LN_H2, LN_H3, LN_H4, LN_H5,
	LN_V1, LN_V2, LN_V3, LN_V4, LN_V5,
	LN_D1, LN_D2
};

// 함수는 선언과 정의 부분으로 나눌 수 잇다.
void SetNumber(int* pArray);
void Shuffle(int* pArray);
AI_MODE SelectAIMode();
void OutputNumber(int* pArray, int iBingo);
bool ChangeNumber(int* pArray, int iInput);
int SelectAINumber(int* pArray, AI_MODE eMode);
int BingoCounting(int* pArray);
int BingoCountingH(int* pArray);
int BingoCountingV(int* pArray);
int BingoCountingLTD(int* pArray);
int BingoCountingRTD(int* pArray);

int main() {
	srand((unsigned int)time(0));

	// ai난이도 고르기
	AI_MODE eAIMode = SelectAIMode();



	int iNumber[25] = {};
	int iAINumber[25] = {};

	SetNumber(iNumber);
	SetNumber(iAINumber);

	Shuffle(iNumber);
	Shuffle(iAINumber);

	int iBingo = 0, iAIBingo = 0;

	// 선택 안된 목록 배열을 만들어준다.
	int iNoneSelect[25] = {};

	// 선택 안된 숫자 개수를 저장한다.
	int iNoneSelectCount = 0;

	int iAIInput = NULL;

	while (true) {
		system("cls");
		cout << "============== PLAYER ==============" << endl;
		OutputNumber(iNumber, iBingo);
		cout << "Bingo Line : " << iBingo << endl << endl;

		cout << "============= COMPUTER =============" << endl;

		switch (eAIMode) {
		case AM_EASY:
			cout << "AIMode : Easy" << endl;
			break;
		case AM_HARD:
			cout << "AIMode : Hard" << endl;
			break;
		}

		OutputNumber(iAINumber, iAIBingo);
		cout << "AIBingo Line : " << iAIBingo << endl << endl;

		if (iBingo >= 5) {
			cout << "5줄 이상의 빙고를 완성했습니다. Player 승리." << endl;
			break;
		}
		else if (iAIBingo >= 5) {
			cout << "AI 승리" << endl;
			break;
		}

		cout << "AI가 숫자 '" << iAIInput << "'을(를) 선택했습니다." << endl;

		int iInput = 0;
		cout << "숫자를 입력해주세요.( 0 : 종료 ) : ";
		cin >> iInput;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "1 ~ 25 사이의 숫자만 입력해주세요." << endl;
			system("pause");
			continue;
		}

		if (iInput == 0) {
			cout << "빙고게임을 종료합니다." << endl;
			system("pause");
			break;
		}
		else if (iInput < 1 || 25 < iInput) {
			cout << "1 ~ 25 사이의 숫자만 입력해주세요." << endl;
			system("pause");
			continue;
		}
		
		bool bAcc = ChangeNumber(iNumber, iInput);

		

		if (bAcc) {
			cout << "이미 지워진 숫자입니다." << endl;
			system("pause");
			continue;
		}
		
		// ai 숫자 지우기
		else {
			ChangeNumber(iAINumber, iInput);
		}

		// ai 난이도 설정
		iAIInput = SelectAINumber(iAINumber, eAIMode);

		ChangeNumber(iNumber, iAIInput);

		ChangeNumber(iAINumber, iAIInput);
	
		iBingo = BingoCounting(iNumber);
		iAIBingo = BingoCounting(iAINumber);

	}
}

void SetNumber(int* pArray) {
	for (int i = 0; i < 25; i++) {
		pArray[i] = i + 1;
	}
}

void Shuffle(int* pArray) {
	int iTemp, iDx1, iDx2;

	for (int i = 0; i < 100; i++) {
		iDx1 = rand() % 25;
		iDx2 = rand() % 25;

		iTemp = pArray[iDx1];
		pArray[iDx1] = pArray[iDx2];
		pArray[iDx2] = iTemp;		
	}
}


AI_MODE SelectAIMode() {

	int iAIMode = 0;

	while (true) {
		cout << "1. EASY" << endl;
		cout << "2. HARD" << endl;
		cout << "AI 난이도를 선택하세요 : ";
		cin >> iAIMode;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			cout << AM_EASY << " ~ " << AM_HARD << "에 해당하는 숫자를 입력해주세요." << endl;
			system("pause");
			continue;
		}
		else if (iAIMode < 1 || 2 < iAIMode) {
			cout << AM_EASY << " ~ " << AM_HARD << "에 해당하는 숫자를 입력해주세요." << endl;
			system("pause");
			continue;
		}
		break;
	}

	return(AI_MODE)iAIMode;
}

void OutputNumber(int* pArray, int iBingo) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (pArray[i * 5 + j] == INT_MAX) {
				cout << "*\t";
			}
			else {
				cout << pArray[i * 5 + j] << "\t";
			}
		}
		cout << endl;
	}
}

bool ChangeNumber(int* pArray, int iInput) {
	for (int i = 0; i < 25; i++) {
		if (iInput == pArray[i]) {
			pArray[i] = INT_MAX;
			return false;
		}
	}
	// 여기까지 오게되면 return false가 동작 안된 것이므로 같은 숫자가 없다는 것이다.
	// 즉, 중복된 숫자를 입력했기 때문에 true를 리턴한다.
}


int SelectAINumber(int* pArray, AI_MODE eMode) {
	
	// 선택 안된 목록 배열을 만들어준다.
	int iNoneSelect[25] = {};

	// 선택 안된 숫자 개수를 저장한다.
	int iNoneSelectCount = 0;
	
	switch (eMode) {
	case AM_EASY:
		iNoneSelectCount = 0;
		for (int i = 0; i < 25; ++i) {
			if (pArray[i] != INT_MAX) {
				iNoneSelect[iNoneSelectCount] = pArray[i];
				++iNoneSelectCount;
			}
		}

		return iNoneSelect[rand() % iNoneSelectCount];

		break;
	case AM_HARD:
		int iLine = 0;
		int iStarCount = 0;
		int iSaveCount = 0;

		for (int i = 0; i < 5; i++) {
			iStarCount = 0;
			for (int j = 0; j < 5; j++) {
				if (pArray[i * 5 + j] == INT_MAX) {
					++iStarCount;
				}
			}
			if (iStarCount < 5 && iSaveCount < iStarCount) {
				iLine = i;
				iSaveCount = iStarCount;
			}
		}

		for (int i = 0; i < 5; i++) {
			iStarCount = 0;
			for (int j = 0; j < 5; j++) {
				if (pArray[j * 5 + i] == INT_MAX) {
					++iStarCount;
				}
			}
			if (iStarCount < 5 && iSaveCount < iStarCount) {
				iLine = i + 5;
				iSaveCount = iStarCount;
			}
		}

		iStarCount = 0;
		for (int i = 0; i < 25; i += 6) {
			if (pArray[i] == INT_MAX) {
				++iStarCount;
			}
		}
		if (iStarCount < 5 && iSaveCount < iStarCount) {
			iLine = LN_D1;
			iSaveCount = iStarCount;
		}

		iStarCount = 0;
		for (int i = 4; i < 20; i += 4) {
			if (pArray[i] == INT_MAX) {
				++iStarCount;
			}
		}
		if (iStarCount < 5 && iSaveCount < iStarCount) {
			iLine = LN_D2;
			iSaveCount = iStarCount;
		}

		if (iLine < LN_H5) {
			for (int i = 0; i < 5; ++i) {
				if (pArray[iLine * 5 + i] != INT_MAX) {
					return pArray[iLine * 5 + i];
				}
			}
		}
		else if (iLine < LN_V5) {
			for (int i = 0; i < 5; i++) {
				if (pArray[i * 5 + (iLine - 5)] != INT_MAX) {
					return pArray[i * 5 + (iLine - 5)];
				}
			}
		}
		else if (iLine == LN_D1) {
			for (int i = 0; i < 25; i += 6) {
				if (pArray[i] != INT_MAX) {
					return pArray[i];
				}
			}
		}
		else if (iLine == LN_D2) {
			for (int i = 4; i <= 20; i += 4) {
				if (pArray[i] != INT_MAX) {
					return pArray[i];
				}
			}
		}
		break;
	}
	return -1;
}

int BingoCounting(int* pArray) {
	int iBingo = 0;
	// 가로줄체크
	iBingo += BingoCountingH(pArray);
	// 세로줄체크
	iBingo += BingoCountingV(pArray);
	// 왼쪽 상단 대각선체크
	iBingo += BingoCountingLTD(pArray);
	// 오른쪽 상단 대각선체크
	iBingo += BingoCountingRTD(pArray);

	return iBingo;
}
int BingoCountingH(int* pArray) {
	int iStar1 = 0, iBingo = 0;
	for (int i = 0; i < 5; ++i) {
		iStar1 = 0;
		for (int j = 0; j < 5; ++j) {
			if (pArray[i * 5 + j] == INT_MAX) {
				++iStar1;
			}
		}
		if (iStar1 == 5) {
			++iBingo;
		}
	}
	return iBingo;
}
int BingoCountingV(int* pArray) {
	int iStar1 = 0, iBingo = 0;
	for (int i = 0; i < 5; ++i) {
		iStar1 = 0;
		for (int j = 0; j < 5; ++j) {
			if (pArray[j * 5 + i] == INT_MAX) {
				++iStar1;
			}
		}
		if (iStar1 == 5) {
			++iBingo;
		}
	}
	return iBingo;
}
int BingoCountingLTD(int* pArray) {
	int iStar1 = 0, iBingo = 0;
	for (int i = 0; i < 25; i += 6) {
		if (pArray[i] == INT_MAX) {
				++iStar1;
		}
		
		if (iStar1 == 5) {
			++iBingo;
		}
	}
	return iBingo;
}
int BingoCountingRTD(int* pArray) {
	int iStar1 = 0, iBingo = 0;
	for (int i = 4; i < 21; i += 4) {
		if (pArray[i] == INT_MAX) {
			++iStar1;
		}

		if (iStar1 == 5) {
			++iBingo;
		}
	}
	return iBingo;
}