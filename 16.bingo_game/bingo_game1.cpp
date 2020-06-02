/*
���� ��������� ����� ����.
1 ~ 25������ ���ڰ� �ְ� �� ���ڸ� ���� ��� 5 X 5�� ����Ѵ�
�÷��̾�� ���ڸ� �Է¹޴´�. 1 ~ 25 ������ ���ڸ� �Է¹޾ƾ� �Ѵ�.
0�� �Է��ϸ� ������ �����Ѵ�.

���ڸ� �Է¹޾����� ���ڸ���� �Է¹��� ���ڸ� ã�Ƽ� *�� ����� �ش�.
���ڸ� *�� ���� �Ŀ� ���� �� ���� üũ�Ѵ� 5 X 5�̱� ������ ���� 5�� ���� 5��
�밢�� 2���� ���� �� �ִ�. �������� ���������� üũ�ؼ� ȭ�鿡 �����ش�.
5�� �̻��� ��� ������ �����Ѵ�.
*/

#include <iostream>
#include <time.h>

using namespace std;

int main() {
	srand((unsigned int)time(0));

	int iNumber[25] = {};

	// 1 ~ 25 ���� ���ڸ� �־��ش�.
	for (int i = 0; i < 25; ++i) {
		iNumber[i] = i + 1;
	}

	// ���ڸ� �����ش�.
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

		// ���ڸ� 5 x 5�� ����Ѵ�.
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

		// �ټ��� 5�̻��� ��� ������ �����Ѵ�.
		if (iBingo >= 5) {
			break;
		}

		cout << "���ڸ� �Է��ϼ���(0 : ����) : ";
		int iInput;
		cin >> iInput;

		if (iInput == 0) {
			break;
		}
		else if (iInput < 1 || iInput > 25) {
			continue;
		}

		// �ߺ��Է��� üũ�ϱ� ���� �����̴�. �⺻������ �ߺ��Ǿ��ٶ�� �ϱ�����
		// true�� ����־���.
		bool bAcc = true;

		// ��� ���ڸ� ���ʴ�� �˻��ؼ� �Է��� ���ڿ� ���� ���ڰ� �ִ����� ã�Ƴ���.
		for (int i = 0; i < 25; ++i) {
			// ���� ���ڰ� �������
			if (iInput == iNumber[i]) {
				// ���ڸ� ã���� ��� �ߺ��� ���ڰ� �ƴϹǷ� bAcc������ false�� �����.
				bAcc = false;

				//���ڸ� *�� �����ϱ����� Ư���� ���� INT_MAX�� ���ش�.
				iNumber[i] = INT_MAX;

				//���̻� �ٸ� ���ڸ� ã�ƺ� �ʿ䰡 �����Ƿ� for���� ����������.
				break;
			}
		}

		// bAcc ������ true�� ��� �ߺ��� ���ڸ� �Է��ؼ� ���ڸ� *�� �ٲ��� �������Ƿ�
		// �ٽ� �Է¹ް� continue���ش�.
		if (bAcc) {
			continue;
		}

		// ���� �� ���� üũ�ϴ� ���� �Ź� ���ڸ� �Է��Ҷ����� ó������ ���� ī��Ʈ�� �Ұ��̴�.
		// �׷��Ƿ� iBingo ������ 0���� �Ź� �ʱ�ȭ �ϰ� ���Ӱ� �� ���� �����ֵ��� �Ѵ�.
		iBingo = 0;

		// ����, ���� �� ���� �����ش�.
		int iStar1 = 0, iStar2 = 0;
		for (int i = 0; i < 5; ++i) {
			// ������ üũ�ϱ� ���� ���� 0���� �� ������ �ʱ�ȭ �Ѵ�.
			iStar1 = iStar2 = 0;
			for (int j = 0; j < 5; ++j) {
				// ���� �� ������ �����ش�.
				if (iNumber[i * 5 + j] == INT_MAX) {
					++iStar1;
				}
				// ���� �� ������ �����ش�.
				if (iNumber[j * 5 + i] == INT_MAX) {
					++iStar2;
				}
			}

			// j for���� ���������� ���� ���� ���� ���� �� ������ �����
			// iStar1������ ���� �ȴ�. iStar1�� ���� 5�̸� ������ ��� *�̶��
			// �ǹ��̹Ƿ� ���� �� ī��Ʈ�� �߰����ش�.
			if (iStar1 == 5) {
				++iBingo;
			}
			if (iStar2 == 5) {
				++iBingo;
			}

			// ���ʻ�ܿ��� ������ �ϴ����� ���� �밢�� üũ
			iStar1 = 0;
			for (int i = 0; i < 25; i += 6) {
				if (iNumber[i] == INT_MAX) {
					++iStar1;
				}
			}

			if (iStar1 == 5) {
				++iBingo;
			}

			// ������ ��ܿ��� ���� �ϴ����� ���� �밢�� üũ
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
			cout << "5���� �ϼ��߽��ϴ�." << endl;
			break;
		}

		cout << "iBingo : " << iBingo << endl;


		cout << "���ڸ� �Է��ϼ���.(0 : ����) : ";
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
	cout << endl << "������ �����մϴ�." << endl;*/
}