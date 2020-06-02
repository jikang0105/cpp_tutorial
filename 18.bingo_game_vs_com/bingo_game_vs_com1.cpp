#include <iostream>
#include <time.h>

using namespace std;

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

	// AI���̵��� �����Ѵ�.

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
			}
		}

		iBingo = 0;

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

	}

}