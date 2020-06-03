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
	int iAINumber[25] = {}; // ai�� ���� �迭
		
	for (int i = 0; i < 25; ++i) {
		iNumber[i] = i + 1;
		iAINumber[i] = i + 1; // ai�� ���� ����
	}

	int iTemp, iDx1, iDx2;

	for (int i = 0; i < 100; ++i) {
		iDx1 = rand() % 25;
		iDx2 = rand() % 25;

		iTemp = iNumber[iDx1];
		iNumber[iDx1] = iNumber[iDx2];
		iNumber[iDx2] = iTemp;

		// ai ���� ����
		iDx1 = rand() % 25;
		iDx2 = rand() % 25;

		iTemp = iAINumber[iDx1];
		iAINumber[iDx1] = iAINumber[iDx2];
		iAINumber[iDx2] = iTemp;
	}

	int iBingo = 0, iAIBingo = 0;
	int iAIMode;

	// AI���̵��� �����Ѵ�.
	while(true){
		system("cls");
		cout << "1. Easy" << endl;
		cout << "2. Hard" << endl;
		cout << "AI ��带 �����ϼ���. : ";
		
		cin >> iAIMode;

		if (iAIMode >= AM_EASY && iAIMode <= AM_HARD) {
			break;
		}
	}


	
	// ���� �ȵ� ��� �迭�� ������ش�.
	int iNoneSelect[25] = {};
	// ���� �ȵ� ���� ������ �����Ѵ�.
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

		// ai ������ ���
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

		// ai ���� �� ���� ����Ѵ�.
		cout << "AIBingo Line : " << iAIBingo << endl;


		if (iBingo >= 5) {
			cout << "5�� �̻��� ���� �ϼ��߽��ϴ�. Player �¸�." << endl;
			break;
		}
		else if (iAIBingo >= 5) {
			cout << "AI �¸�" << endl;
			break;
		}

		cout << "AI�� ���� '" << iAIInput << "'��(��) �����߽��ϴ�." << endl;
		cout << "���ڸ� �Է��ϼ���(0 : ����) : ";
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

		// �ߺ��� �ƴ϶�� AI�� ���ڵ� ã�Ƽ� *�� �ٲ��ش�.
		for (int i = 0; i < 25; ++i) {
			if (iInput == iAINumber[i]) {
				iAINumber[i] = INT_MAX;
				break;
			}
		}
		
		//AI�� ������ �Ѵ�. AI�� �����ϴ� ���� AI��忡 ���� �޶�����.
		switch (iAIMode) {
			/*
			AI Easy ���� ���� AI�� ���� ��� �� *�� �ٲ��� ���� ���� ����� ����
			�� ����� �ϳ��� �����ϰ� �Ѵ�.(�����ϰ�)
			*/
		case AM_EASY:
			// ���þȵ� ���ڸ���� ������ش�.
			// ���þȵ� ���� ������ ����� ���鶧 ī�������ش�.
			iNoneSelectCount = 0;
			for (int i = 0; i < 25; ++i) {
				// ������ڰ� *�� �ƴҰ��
				if(iAINumber[i] != INT_MAX) {
					// *�� �ƴ� ������ ��� iNoneSelectCount�� �ε����� Ȱ���Ѵ�.
					// ���� �ȵ� ��Ͽ� �߰��Ҷ����� ������ 1�� �������Ѽ� �� ���þȵ� ������ 
					// �����ش�.
					// �׷��� 0���� ī��Ʈ�� �����̹Ƿ� 0���� �ְ� ++�ؼ� 1�� �߰��Ǿ��ٶ��
					// �Ѵ�.
					iNoneSelect[iNoneSelectCount] = iAINumber[i];
					++iNoneSelectCount;
				}
			}

			// for���� ���������� �Ǹ� ���þȵ� ����� ���������
			// ���þȵ� ����� ������ ��������� �ȴ�.
			// ���þȵ� ����� ������ ������ �ϳ��� ���ڸ� ������ ���� 
			// �ε����� �����ϰ� �����ش�.

			
			iAIInput = iNoneSelect[rand() % iNoneSelectCount];

			break;
		case AM_HARD:
			// �ϵ���� ���� ������ ������ �ϼ� ���ɼ��� ���� ���� ����
			// ã�Ƽ� �� �ٿ� �ִ� ������ �ϳ��� *�� ������ش�.
			int iLine = 0;
			int iStarCount = 0;
			int iSaveCount = 0;

			// ���� ���� �� ���� *�� ���� ������ ã�Ƴ���.
			for (int i = 0; i < 5; ++i) {
				// iStarCount���� �ʱ�ȭ�� ���� �ٸ��� ���� ��ִ��� Ȯ���� �� �ִ�.
				iStarCount = 0;
				for (int j = 0; j < 5; ++j) {
					if (iAINumber[i * 5 + j] == INT_MAX) {
						++iStarCount;
					}
				
				}
				// ���� 5�� �̸��̾�� �ϰ� ���� ���� �ƴϰ� 
				// ������ ���� ���� ���� ������ ������ ���� ���ƾ� ���� ���� �����̹Ƿ�
				// ��ü���ְ� ����� �� ���� ��ü�Ѵ�.
				if (iStarCount < 5 && iSaveCount < iStarCount) {
					iLine = i;
					iSaveCount = iStarCount;
				}
			}

			// ���� ������ ���� ���� ���� ���ΰ� ���� ���ε��� ���Ͽ� ���� ���� ����
			// ������ ���Ѵ�.
			for (int i = 0; i < 5; ++i) {
				iStarCount = 0;
				for (int j = 0; j < 5; ++j) {
					if (iAINumber[j * 5 + i] == INT_MAX) {
						++iStarCount;
					}
				}
				if (iStarCount < 5 && iSaveCount < iStarCount) {
					// ���ζ����� 5 ~ 9�� �ǹ̸� �ο��ߴ�.
					iLine = i + 5;
					iSaveCount = iStarCount;
				}
			}

			// ���� -> ������ �밢�� üũ
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

			// ������ -> ���� �밢�� üũ
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
			
			// ��� ������ ���������� iLine�� ���ɼ��� ���� ���� �� ��ȣ�� ����ȴ�.
			// �� �ٿ� �ִ� *�� �ƴ� ������ �ϳ��� �����ϰ� �Ѵ�.
			// �������� ���
			if (iLine <= LN_H5) {
				// �������� ��� iLine�� 0 ~ 4 ������ ���̴�.
				for (int i = 0; i < 5; ++i) {
					// ���� �ٿ��� *�� �ƴ� ���ڸ� ã�Ƴ���.
					if(iAINumber[iLine * 5 + i] != INT_MAX){
						iAIInput = iAINumber[iLine * 5 + i];
						break;
					}
				}
			}
			else if (iLine <= LN_V5) {
				// �������� ��� iLine�� 5~9 ������ ���̴�.
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

		// AI�� ���ڸ� ���������Ƿ� �÷��̾�� AI�� ���ڸ� *�� �ٲ��ش�.
		for (int i = 0; i < 25; ++i) {
			if (iNumber[i] == iAIInput) {
				iNumber[i] = INT_MAX;
				break;
			}
		}

		// AI ���ڸ� �ٲ��ش�.
		for (int i = 0; i < 25; ++i) {
			if (iAINumber[i] == iAIInput) {
				iAINumber[i] = INT_MAX;
				break;
			}
		}

		/*
		// AI�� ���ڸ� �����Ѵ�.
		bool bAIAcc = true;
		
		
		while (bAIAcc) {
			cout << "AI�� ���ڸ� �����մϴ�. : ";
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