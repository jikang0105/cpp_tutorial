/*
�������α׷� �����
���� �뿩 ���α׷� �����
1. å ���
2. å �뿩
3. å �ݳ�
4. å ���
5. ����

å ����ü�� �̸�, �뿩�ݾ�, å��ȣ, �뿩���ΰ� �ʿ��ϴ�.

å ����� �����ϸ� å ������ ������ش�.
*/

#include <iostream>

using namespace std;

#define NAME_SIZE		64
#define PRISE_SIZE		32
#define NUMBER_SIZE		32
#define BOOK_MAX		10


struct _tagBook {
	char	strName[NAME_SIZE];
	char	strPrise[PRISE_SIZE];
	char	strNumber[NUMBER_SIZE];
	int		iBCount; 
	int		iBsCount;
	// �뿩�Ұ� 0(true), �뿩���� >= 1(false)
	int		iRent;
};

enum MENU {
	MENU_NONE,
	MENU_INSERT,
	MENU_RENT,
	MENU_RETURN,
	MENU_LIST,
	MENU_END
};

int main() {

	_tagBook tBookArr[BOOK_MAX] = {};
	int iBookIdx = 0;
	// ���� å�� ����.
	int iBookCount = 0;
	// å�� ����(�ߺ��Ǵ� å�� ���� �ʴ´�.)
	int iBooksCount = 1;

	char strName[NAME_SIZE] = {};

	int iRBookCount = 0;

	while (true) {

		system("cls");
		cout << "1. å ���" << endl;
		cout << "2. å �뿩" << endl;
		cout << "3. å �ݳ�" << endl;
		cout << "4. å ���" << endl;
		cout << "5. ����" << endl;

		cout << "�Ŵ��� �����ϼ���. : ";
		int iChoice;
		cin >> iChoice;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(1024,'\n');
			continue;
		}

		switch (iChoice) {
		case MENU_INSERT:
			system("cls");
			cout << "=============== å ��� ===============";
			
			if (iBooksCount == BOOK_MAX) {
				break;
			}

			cout << "å �̸� : ";
			cin.getline(tBookArr[iBookIdx].strName, NAME_SIZE);
			cin.ignore(1024, '\n');

			cout << "�뿩 �ݾ� : ";
			cin.getline(tBookArr[iBookIdx].strPrise, PRISE_SIZE);
			cin.ignore(1024, '\n');

			cout << "å ��ȣ : ";
			cin.getline(tBookArr[iBookIdx].strNumber, NUMBER_SIZE);
			cin.ignore(1024, '\n');

			cout << "�� �� : ";
			cin >> iBookCount;
				
			tBookArr[iBookIdx].iBCount = iBookCount;

			// �� iRent���� �� ���� �����ϰ� 0�̵Ǹ� �뿩 �Ұ����� ���·� �����.
			tBookArr[iBookIdx].iRent = iBookCount;

			tBookArr[iBookIdx].iBsCount += iBooksCount;

			++iBooksCount;
			
			cout << "å �߰� �Ϸ�" << endl;

			break;
		case MENU_RENT:
			break;
		case MENU_RETURN:
			system("cls");
			cout << "=============== å �ݳ� ===============" << endl;
			cin.ignore(1024, '\n');
			cout << "�ݳ��� å�� �Է��ϼ��� : ";
			cin.getline(strName, NAME_SIZE);
			cin.ignore(1024, '\n');
			

			for (int i = 0; i < iBooksCount; ++i) {
				if(strcmp(tBookArr[i].strName, strName) == 0){
					cout << "�ݳ��� �� ���� �Է��ϼ��� : ";
					cin >> iRBookCount;
					tBookArr[i].iBCount += iRBookCount;
					cout << tBookArr[i].strName << iRBookCount << "���� �ݳ��Ǿ����ϴ�." << endl;
					break;
				}

			}

			break;
		case MENU_LIST:
			system("cls");
			cout << "=============== å ��� ===============" << endl;
			for (int i = 0; i <= iBookIdx; ++i) {
				cout << "å �̸� : " << tBookArr[i].strName << endl;
				cout << "å ���� : " << tBookArr[i].strPrise << endl;
				cout << "å ��ȣ : " << tBookArr[i].strNumber << endl;
				cout << "�� �� : " << tBookArr[i].iBCount << endl;
				if (tBookArr[iBookIdx].iBCount > 0) {
					cout << "�뿩 ����" << endl;
				}
				else {
					cout << "�뿩 �Ұ�" << endl;
				}
			}
			break;
		case MENU_END:
			break;
		}
		system("pause");
	}
}