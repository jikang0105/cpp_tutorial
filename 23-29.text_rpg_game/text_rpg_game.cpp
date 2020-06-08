#include <iostream>
#include <time.h>
using namespace std;

enum MAIN_MENU {
	MN_NONE,
	MN_MAP,
	MN_STORE,
	MN_INVENTORY,
	MN_EXIT
};

enum MAP_TYPE {
	MT_NONE,
	MT_EASY,
	MT_NORMAL,
	MT_HARD,
	MT_BACK,
};

enum JOB {
	JOB_NONE,
	JOB_KNIGHT,
	JOB_ARCHER,
	JOB_WIZARD,
	JOB_END
};

enum BATTLE {
	BA_NONE,
	BA_ATTACK,
	BA_RUN
};

#define NAME_SIZE 32

struct _tagInventory {
	int		iGold;
};

struct _tagPlayer {
	char	strName[NAME_SIZE];
	char	strJobName[NAME_SIZE];
	JOB		eJob;
	int		iAttackMin;
	int		iAttackMax;
	int		iArmorMin;
	int		iArmorMax;
	int		iHP;
	int		iHPMax;
	int		iMP;
	int		iMPMax;
	int		iExp;
	int		iLevel;
	_tagInventory	tInventory;
};

struct _tagMonster {
	char	strName[NAME_SIZE];
	int		iAttackMin;
	int		iAttackMax;
	int		iArmorMin;
	int		iArmorMax;
	int		iHP;
	int		iHPMax;
	int		iMP;
	int		iMPMax;
	int		iLevel;
	int		iExp;
	int		iGoldMin;
	int		iGoldMax;
};

int main() {

	// ������ �����Ҷ� �÷��̾� ������ �����ϰ� �Ѵ�.
	_tagPlayer	tPlayer = {};
		
	// �÷��̾� �̸��� �Է¹޴´�.
	cout << "�̸� : ";
	cin.getline(tPlayer.strName, NAME_SIZE - 1);

	int iJob = JOB_NONE;

	while(iJob == JOB_NONE) {
		system("cls");
		cout << "1. ���" << endl;
		cout << "2. �ü�" << endl;
		cout << "3. ������" << endl;
		cout << "������ �����ϼ��� : ";
		cin >> iJob;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		else if (iJob <= JOB_NONE || iJob >= JOB_END) {
			iJob = JOB_NONE;
		}
	}
	tPlayer.iLevel = 1;
	tPlayer.iExp = 0;
	tPlayer.eJob = (JOB)iJob;
	tPlayer.tInventory.iGold = 10000;

	switch (tPlayer.eJob) {
	case JOB_KNIGHT:
		strcpy_s(tPlayer.strJobName, "���");
		tPlayer.iAttackMin = 5;
		tPlayer.iAttackMax = 10;
		tPlayer.iArmorMin = 15;
		tPlayer.iArmorMax = 20;
		tPlayer.iHPMax = 500;
		tPlayer.iHP = 500;
		tPlayer.iMPMax = 100;
		tPlayer.iMP = 100;
		break;

	case JOB_ARCHER:
		strcpy_s(tPlayer.strJobName, "�ü�");
		tPlayer.iAttackMin = 10;
		tPlayer.iAttackMax = 15;
		tPlayer.iArmorMin = 10;
		tPlayer.iArmorMax = 25;
		tPlayer.iHPMax = 400;
		tPlayer.iHP = 400;
		tPlayer.iMPMax = 200;
		tPlayer.iMP = 200;
		break;
	case JOB_WIZARD:
		strcpy_s(tPlayer.strJobName, "������");
		tPlayer.iAttackMin = 15;
		tPlayer.iAttackMax = 20;
		tPlayer.iArmorMin = 5;
		tPlayer.iArmorMax = 10;
		tPlayer.iHPMax = 300;
		tPlayer.iHP = 300;
		tPlayer.iMPMax = 300;
		tPlayer.iMP = 300;
		break;
	}

	// ���͸� �����Ѵ�.
	_tagMonster	tMonsterArr[MT_BACK - 1] = {};

	// ������ ����
	strcpy_s(tMonsterArr[0].strName, "������");
	tMonsterArr[0].iAttackMin = 20;
	tMonsterArr[0].iAttackMax = 30;
	tMonsterArr[0].iArmorMin = 2;
	tMonsterArr[0].iArmorMax = 5;
	tMonsterArr[0].iHP = 100;
	tMonsterArr[0].iHPMax = 100;
	tMonsterArr[0].iMP = 10;
	tMonsterArr[0].iMPMax = 10;
	tMonsterArr[0].iLevel = 1;
	tMonsterArr[0].iExp = 1000;
	tMonsterArr[0].iGoldMin = 500;
	tMonsterArr[0].iGoldMax = 1500;

	// Ʈ�� ����
	strcpy_s(tMonsterArr[1].strName, "Ʈ��");
	tMonsterArr[1].iAttackMin = 80;
	tMonsterArr[1].iAttackMax = 130;
	tMonsterArr[1].iArmorMin = 60;
	tMonsterArr[1].iArmorMax = 90;
	tMonsterArr[1].iHP = 2000;
	tMonsterArr[1].iHPMax = 2000;
	tMonsterArr[1].iMP = 100;
	tMonsterArr[1].iMPMax = 100;
	tMonsterArr[1].iLevel = 5;
	tMonsterArr[1].iExp = 7000;
	tMonsterArr[1].iGoldMin = 6000;
	tMonsterArr[1].iGoldMax = 8000;

	// �巡�� ����
	strcpy_s(tMonsterArr[2].strName, "�巡��");
	tMonsterArr[2].iAttackMin = 250;
	tMonsterArr[2].iAttackMax = 500;
	tMonsterArr[2].iArmorMin = 200;
	tMonsterArr[2].iArmorMax = 400;
	tMonsterArr[2].iHP = 30000;
	tMonsterArr[2].iHPMax = 30000;
	tMonsterArr[2].iMP = 20000;
	tMonsterArr[2].iMPMax = 20000;
	tMonsterArr[2].iLevel = 10;
	tMonsterArr[2].iExp = 30000;
	tMonsterArr[2].iGoldMin = 20000;
	tMonsterArr[2].iGoldMax = 50000;

	while (true) {
		system("cls");
		cout << "********************** �κ� **********************" << endl;
		cout << "1. ��" << endl;
		cout << "2. ����" << endl;
		cout << "3. ����" << endl;
		cout << "4. ����" << endl;
		cout << "�޴��� �����ϼ��� : ";
		int iMenu;
		cin >> iMenu;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}

		if (iMenu == MN_EXIT) {
			break;
		}

		switch (iMenu) {
		case MN_MAP:
			while (true) {
				system("cls");
				cout << "********************** �� **********************" << endl;
				cout << "1. ����" << endl;
				cout << "2. ����" << endl;
				cout << "3. �����" << endl;
				cout << "4. �ڷΰ���" << endl;
				cout << "���� �����ϼ��� : ";
				cin >> iMenu;

				if (cin.fail()) {
					cin.clear();
					cin.ignore(1024, '\n');
					continue;
				}
				// �� if���� ���� break�� �� �޴��� �����ֱ� ���� while�� ���������Ƿ�
				// �� while���� ����������.
				if (iMenu == MT_BACK) {
					break;
				}
								
					// ������ �޴����� 1�� ���ָ� ���� �迭�� �ε����� �ȴ�.
					// �׷��� �ؼ� �ش� ���� ���͸� �������ش�.
				_tagMonster	tMonster = tMonsterArr[iMenu - 1];

				while (true) {
					switch (iMenu) {
					case MT_EASY:
						cout << "********************** ���� **********************" << endl;
						break;
					case MT_NORMAL:
						cout << "********************** ���� **********************" << endl;
						break;
					case MT_HARD:
						cout << "********************** ����� **********************" << endl;
						break;
					}

					// �÷��̾� ������ ����Ѵ�.
					cout << "==================== Player ====================" << endl;
					cout << "�̸� : " << tPlayer.strName << "\t���� : " <<
						tPlayer.strJobName << endl;
					cout << "���� : " << tPlayer.iLevel << "\t����ġ : " <<
						tPlayer.iExp << endl;
					cout << "���ݷ� : " << tPlayer.iAttackMin << " - " <<
						tPlayer.iAttackMax << "\t���� : " << tPlayer.iArmorMin <<
						" - " << tPlayer.iArmorMax << endl;
					cout << "ü�� : " << tPlayer.iHP << " / " << tPlayer.iHPMax <<
						"\t���� : " << tPlayer.iMP << " / " << tPlayer.iMPMax << endl;
					cout << "������� : " << tPlayer.tInventory.iGold << " Gold" << endl << endl;

					// ���� ���� ���
					cout << "==================== Monster ====================" << endl;
					cout << "�̸� : " << tMonster.strName << "\t���� : " <<
						tMonster.iLevel << endl;
					cout << "���ݷ� : " << tMonster.iAttackMin << " - " <<
						tMonster.iAttackMax << "\t���� : " << tMonster.iArmorMin <<
						" - " << tMonster.iArmorMax << endl;
					cout << "ü�� : " << tMonster.iHP << " / " << tMonster.iHPMax <<
						"\t���� : " << tMonster.iMP << " / " << tMonster.iMPMax << endl;
					cout << "ȹ�����ġ : " << tMonster.iExp << "\tȹ���� : " <<
						tMonster.iGoldMin << " - " << tMonster.iGoldMax << endl;

					cout << "1. ����" << endl;
					cout << "2. ��������" << endl;
					cout << "�޴��� �����ϼ��� : ";
					cin >> iMenu;

					if (cin.fail()) {
						cin.clear();
						cin.ignore(1024, '\n');
						continue;
					}
					else if (iMenu == BA_RUN) {
						break;
					}

					switch (iMenu) {
					case BA_ATTACK: {
						int iAttack = rand() % (tPlayer.iAttackMax - tPlayer.iArmorMin + 1) + (tPlayer.iAttackMin + 1) +
							
					}
						break;
					}
				}
			}
			break;
		case MN_STORE:
			break;
		case MN_INVENTORY:
			break;
		default:
			cout << "�߸� �����Ͽ����ϴ�." << endl;
			break;
		}
	}
}