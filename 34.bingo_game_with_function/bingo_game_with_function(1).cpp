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

// �Լ��� ����� ���� �κ����� ���� �� �մ�.
void SetNumber(int* pArray);
void Shuffle(int* pArray);
AI_MODE SelectAIMode();
void OutputNumber(int* pArray, int iBingo);
bool ChangeNumber(int* pArray, int iInput);


int main() {
	srand((unsigned int)time(0));

	// ai���̵� ������
	int iAIMode = SelectAIMode();



	int iNumber[25] = {};
	int iAINumber[25] = {};

	SetNumber(iNumber);
	SetNumber(iAINumber);

	Shuffle(iNumber);
	Shuffle(iAINumber);

	int iBingo = 0, iAIBingo = 0;

	// ���� �ȵ� ��� �迭�� ������ش�.
	int iNoneSelect[25] = {};

	// ���� �ȵ� ���� ������ �����Ѵ�.
	int iNoneSelectCount = 0;

	int iAIInput = NULL;

	while (true) {
		system("cls");
		cout << "============== PLAYER ==============" << endl;
		OutputNumber(iNumber, iBingo);
		cout << "Bingo Line : " << iBingo << endl << endl;

		cout << "============= COMPUTER =============" << endl;

		switch (iAIMode) {
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
			cout << "5�� �̻��� ������ �ϼ��߽��ϴ�. Player �¸�." << endl;
			break;
		}
		else if (iAIBingo >= 5) {
			cout << "AI �¸�" << endl;
			break;
		}

		cout << "AI�� ���� '" << iAIInput << "'��(��) �����߽��ϴ�." << endl;

		int iInput = 0;
		cout << "���ڸ� �Է����ּ���.( 0 : ���� ) : ";
		cin >> iInput;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "1 ~ 25 ������ ���ڸ� �Է����ּ���." << endl;
			system("pause");
			continue;
		}

		if (iInput == 0) {
			cout << "���������� �����մϴ�." << endl;
			system("pause");
			break;
		}
		else if (iInput < 1 || 25 < iInput) {
			cout << "1 ~ 25 ������ ���ڸ� �Է����ּ���." << endl;
			system("pause");
			continue;
		}
		
		bool bAcc = ChangeNumber(iNumber, iInput);

		

		if (bAcc) {
			cout << "�̹� ������ �����Դϴ�." << endl;
			system("pause");
			continue;
		}
		
		// ai ���� �����
		else {
			ChangeNumber(iAINumber, iInput);
		}

		// ai ���̵� ����
		switch (iAIMode) {
		case AM_EASY :
			iNoneSelectCount = 0;
			for (int i = 0; i < 25; ++i) {
				if (iAINumber[i] != INT_MAX) {
					iNoneSelect[iNoneSelectCount] = iAINumber[i];
					++iNoneSelectCount;
				}
			}

			iAIInput = iNoneSelect[rand() % iNoneSelectCount];

			break;
		case AM_HARD :
			int iLine = 0;
			int iStarCount = 0;
			int iSaveCount = 0;

			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 5; j++) {
					if (iAINumber[i * 5 + j] == INT_MAX) {
						++iStarCount;
					}
				}
				if (iStarCount < 5 && iSaveCount < iStarCount) {
					iLine = i;
					iSaveCount = iStarCount;
				}
			}

			for (int i = 0; i < 5; i++) {
				for (int j = )
			}

			break;



		}
	

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
		cout << "AI ���̵��� �����ϼ��� : ";
		cin >> iAIMode;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			cout << AM_EASY << " ~ " << AM_HARD << "�� �ش��ϴ� ���ڸ� �Է����ּ���." << endl;
			system("pause");
			continue;
		}
		else if (iAIMode < 1 || 2 < iAIMode) {
			cout << AM_EASY << " ~ " << AM_HARD << "�� �ش��ϴ� ���ڸ� �Է����ּ���." << endl;
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
	// ������� ���ԵǸ� return false�� ���� �ȵ� ���̹Ƿ� ���� ���ڰ� ���ٴ� ���̴�.
	// ��, �ߺ��� ���ڸ� �Է��߱� ������ true�� �����Ѵ�.
}
