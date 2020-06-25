#include<iostream>
#include<time.h>
using namespace std;

enum MAIN_MANU {
	MM_NONE,
	MM_MAP,
	MM_STORE,
	MM_INVENTORY,
	MM_EXIT
};

enum MAP_TYPE {
	MT_NONE,
	MT_EASY,
	MT_NORMAL,
	MT_HARD,
	MT_BACK
};

enum JOB {
	JOB_NONE,
	JOB_KNIGHT,
	JOB_ARCHER,
	JOB_WIZARD,
	JOB_END
};

enum ITEM_TYPE {
	IT_NONE,
	IT_WEAPON,
	IT_ARMOR,
	IT_BACK
};

enum EQUIP {
	EQ_WEAPON,
	EQ_ARMOR,
	EQ_MAX
};

#define NAME_SIZE	32
#define ITEM_DESC_LENGTH	512
#define INVENTORY_MAX		20
#define STROE_WEAPON_MAX	3
#define	STORE_ARMOR_MAX		3
#define LEVEL_MAX			10

struct _tagItem {
	char	strName[NAME_SIZE];
	char	strTypeName[NAME_SIZE];
	ITEM_TYPE eType;
	int		iMin;
	int		iMax;
	int		iPrice;
	int		iSell;
	int		strDesc[ITEM_DESC_LENGTH];
};

struct _tagInventory {
	_tagItem	tItem[INVENTORY_MAX];
	int		iItemCount;
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
	_tagItem	tEquip[EQ_MAX];
	bool		bEquip[EQ_MAX];
};

struct _tagMonster {
	char strName[NAME_SIZE];
	int iAttackMin;
	int iAttackMax;
	int iArmorMin;
	int iArmorMax;
	int iHP;
	int iHPMax;
	int iMP;
	int iMPMax;
	int iLevel;
	int iExp;
	int iGoldMin;
	int iGoldMax;
};

// ���� �Է��� �޴´�. �Է� �������� ó�����ְ� INT_MAX�� �����ϸ� �Է� �����̴�.
int InputInt() {
	int iInput;
	cin >> iInput;

	if (cin.fail()) {
		cin.clear();
		cin.ignore(1024, '\n');
		return INT_MAX; // INT_MAX�� ���ϵǸ� �Է��� �߸��ƴٴ� �ǹ̷� ����� ��.
	}

	return iInput;
}

// ���� �޴��� ȭ�鿡 �����ְ� �Է¹��� �޴��� ��ȯ�Ѵ�. �Է� ������ ��� Ȥ�� �߸��� ��ȣ�� 
// �Է��� ��� 0�� ��ȯ�Ѵ�.
int OutputMainMenu() {
	system("cls");
	cout << "***************** �κ� *****************" << endl;
	cout << "1. ��" << endl;
	cout << "2. ����" << endl;
	cout << "3. ����" << endl;
	cout << "4. ����" << endl;
	cout << "�޴��� �����ϼ���. : ";
	int iMenu = InputInt();

	if (iMenu == INT_MAX || iMenu <= MM_NONE || iMenu > MM_EXIT) {
		return MM_NONE;
	}

	return iMenu;
}

int OutputMapMenu() {
	system("cls");
	cout << "****************** �� ******************" << endl;
	cout << "1. ����" << endl;
	cout << "2. ����" << endl;
	cout << "3. �����" << endl;
	cout << "4. �ڷΰ���" << endl;
	int iMenu = InputInt();

	if (iMenu == INT_MAX || iMenu <= MT_NONE || iMenu > MT_BACK) {
		return MT_NONE;
	}

	return iMenu;
}

// Map�� ���õ� ������ ó���Ѥ�.
void RunMap() {

	bool	bLoop = true;

	while (bLoop) {
		switch (OutputMapMenu()) {
		case MT_EASY:
			break;
		case MT_NORMAL:
			break;
		case MT_HARD:
			break;
		case MT_BACK:
			bLoop = false;
			break;
		}
	}

}

void SelectJob() {
	int iJob = JOB_NONE;
	while (iJob == JOB_NONE) {
		system("cls");
		cout << "1. ���" << endl;
		cout << "2. �ü�" << endl;
		cout << "3. ������" << endl;
		cout << "������ �����ϼ��� : ";
		iJob = InputInt();

		if (iJob == INT_MAX || iJob <= JOB_NONE || iJob > JOB_END) {
			iJob = JOB_NONE;
		}
	}
}

void SetPlayer(_tagPlayer* pPlayer) {
	// �÷��̾��� �̸��� �Է¹޴´�.
	cout << "�̸� : ";
	cin.getline(pPlayer->strName, NAME_SIZE - 1);
}

int main() {

	srand((unsigned int)time(0));


	// ������ �����Ҷ� �÷��̾� ������ �����ϰ� �Ѵ�.
	_tagPlayer	tPlayer = {};

	// �÷��̾��� ������ �����Ѵ�.
	SetPlayer(&tPlayer);


	bool	bLoop = true;

	while (bLoop) {
		switch (OutputMainMenu()) {
		case MM_MAP:
			RunMap(); // �� ���� ������ ó���Ѵ�.
			break;
		case MM_STORE:
			break;
		case MM_INVENTORY:
			break;
		case MM_EXIT:
			bLoop = false;
			break;
		}
	}


	return 0;
}