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

enum BATTLE_MANU {
	BM_NONE,
	BM_ATTACK,
	BM_RUN
};

#define NAME_SIZE	32
#define ITEM_DESC_LENGTH	512
#define INVENTORY_MAX		20
#define STROE_WEAPON_MAX	3
#define	STORE_ARMOR_MAX		3
#define LEVEL_MAX			10

// �������� �ʿ��� ����ġ ����� �����.

const int	g_iLevelUpExp[LEVEL_MAX] = { 4000, 10000, 20000, 35000, 50000, 70000,
100000, 150000, 200000, 400000 };

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
	_tagInventory	tInventory;
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

_tagMonster CreatMonster(const char* pName, int iAttackMin, int iAttackMax, int iArmorMin,
	int iArmorMax, int iHP, int iMP, int iLevel, int iExp, int iGoldMin, int iGoldMax) {
	_tagMonster tMonster = {};

	strcpy_s(tMonster.strName, pName);
	tMonster.iAttackMin = iAttackMin;
	tMonster.iAttackMax = iAttackMax;
	tMonster.iArmorMin = iArmorMin;
	tMonster.iArmorMax = iArmorMax;
	tMonster.iHP = iHP;
	tMonster.iHPMax = iHP;
	tMonster.iMP = iMP;
	tMonster.iMPMax = iMP;
	tMonster.iLevel = iLevel;
	tMonster.iExp = iExp;
	tMonster.iGoldMin = iGoldMin;
	tMonster.iGoldMax = iGoldMax;

	return tMonster;

}

void SetMonster(_tagMonster* pMonsterArr) {
	pMonsterArr[0] = CreatMonster("���", 20, 30, 2, 5, 100,
		10, 1, 1000, 500, 1500);
	pMonsterArr[1] = CreatMonster("Ʈ��", 80, 130, 60, 90, 2000,
		100, 5, 7000, 6000, 8000);
	pMonsterArr[2] = CreatMonster("�巹��", 250, 500, 200, 400, 30000,
		20000, 10, 30000, 20000, 50000);
}

void OutputBattleTag(int iMenu) {
	switch (iMenu) {
	case MT_EASY:
		cout << "***************** ���� *****************" << endl;
		break;
	case MT_NORMAL:
		cout << "***************** ���� *****************" << endl;
		break;
	case MT_HARD:
		cout << "**************** ����� ****************" << endl;
		break;
	}
}

void OutputPlayer(_tagPlayer* pPlayer) {
	cout << "================ Player ================" << endl;
	cout << "�̸� : " << pPlayer->strName << "\t���� : " <<
		pPlayer->strJobName << endl;
	cout << "���� : " << pPlayer->iLevel << "\t����ġ : " <<
		pPlayer->iExp << " / " << g_iLevelUpExp[pPlayer->iLevel - 1] << endl;

	// ���⸦ �����ϰ� ���� ��� ���ݷ¿� ������ݷ��� �߰��Ͽ� ����Ѵ�.
	if (pPlayer->bEquip[EQ_WEAPON] == true) {
		cout << "���ݷ� : " << pPlayer->iAttackMin << " + " <<
			pPlayer->tEquip[EQ_WEAPON].iMin << " - " <<
			pPlayer->iAttackMax << " + " << pPlayer->tEquip[EQ_WEAPON].iMax;
	}
	else {
		cout << "���ݷ� : " << pPlayer->iAttackMin << " - " <<
			pPlayer->iAttackMax;
	}

	// ���� �����ϰ� ���� ��� ���¿� �� ������ �߰��Ͽ� ����Ѵ�.
	if(pPlayer->bEquip[EQ_ARMOR] == true) {
		cout << "\t���� : " << pPlayer->iArmorMin << " + " <<
			pPlayer->tEquip[EQ_ARMOR].iMin << " - " <<
			pPlayer->iArmorMax << " + " << pPlayer->tEquip[EQ_ARMOR].iMax;
	}
	else {
		cout << "\t���� : " << pPlayer->iArmorMin << " - " <<
			pPlayer->iArmorMax << endl;
	}

	cout << "ü�� : " << pPlayer->iHP << " / " << pPlayer->iHPMax <<
		"\t���� : " << pPlayer->iMP << " / " << pPlayer->iMPMax;

	if (pPlayer->bEquip[EQ_WEAPON]) {
		cout << "�������� : " << pPlayer->tEquip[EQ_WEAPON].strName;
	}
	else {
		cout << "�������� : ����";
	}

	if (pPlayer->bEquip[EQ_ARMOR]) {
		cout << "������ : " << pPlayer->tEquip[EQ_ARMOR].strName;
	}
	else {
		cout << "������ : ����";
	}

	cout << "������� : " << pPlayer->tInventory.iGold << " Gold" << endl;
}

void OutputMonster(_tagMonster* pMonster) {
	cout << "=============== Monster ===============" << endl;
	cout << "�̸� : " << pMonster->strName << "\t���� : " <<
		pMonster->iLevel << endl;
	cout << "���ݷ� : " << pMonster->iAttackMin << " - " <<
		pMonster->iAttackMax << endl;
	cout << "ü�� : " << pMonster->iHP << " / " << pMonster->iHPMax <<
		"\t���� : " << pMonster->iMP << " / " << pMonster->iMPMax << endl;
	cout << "ȹ�����ġ : " << pMonster->iExp << "\tȹ���� : " <<
		pMonster->iGoldMin << " - " << pMonster->iGoldMax << endl << endl;
}

int OutputBattleMenu() {
	//int iBattle = BM_NONE;
	//while (iBattle == BM_NONE) {
		cout << "1. ����" << endl;
		cout << "2. ��������" << endl;
		cout << "�޴��� �����ϼ��� : ";
		int iBattle = InputInt();

		if (iBattle == INT_MAX || iBattle <= BM_NONE || iBattle > BM_RUN) {
			return BM_NONE;
		}

		return iBattle;
	//}

}

void RunBattle(_tagPlayer* pPlayer, _tagMonster* pMonsterArr, int iMenu) {
	_tagMonster tMonster = pMonsterArr[iMenu - 1];

	while (true) {
		system("cls");
		OutputBattleTag(iMenu);

		// �÷��̾� ���
		OutputPlayer(pPlayer);

		// ���� ���
		OutputMonster(&tMonster);

		switch (OutputBattleMenu()) {
		case BM_ATTACK:
			break;
		case BM_RUN:
			return;
		}

	}
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

// Map�� ���õ� ������ ó���Ѵ�.
void RunMap(_tagPlayer* pPlayer, _tagMonster* pMonsterArr) {

	bool	bLoop = true;

	while (bLoop) {
		int iMenu = OutputMapMenu();

		if (MT_BACK == iMenu) {
			return;
		}
		else if (MT_NONE == iMenu) {
			continue;
		}

		// ������ �����Ѵ�.
		RunBattle(pPlayer, pMonsterArr, iMenu);
	}
}

int SelectJob() {
	int iJob = JOB_NONE;
	while (iJob == JOB_NONE) {
		system("cls");
		cout << "1. ���" << endl;
		cout << "2. �ü�" << endl;
		cout << "3. ������" << endl;
		cout << "������ �����ϼ��� : ";
		iJob = InputInt();

		if (iJob <= JOB_NONE || iJob > JOB_END) {
			iJob = JOB_NONE;
		}
	}
	return iJob;
}

void SetPlayer(_tagPlayer* pPlayer) {
	// �÷��̾��� �̸��� �Է¹޴´�.
	cout << "�̸� : ";
	cin.getline(pPlayer->strName, NAME_SIZE - 1);

	pPlayer->eJob = (JOB)SelectJob();
	pPlayer->iLevel = 1;
	pPlayer->iExp = 0;
	pPlayer->tInventory.iGold = 10000;

	switch (pPlayer->eJob) {
	case JOB_KNIGHT:
		strcpy_s(pPlayer->strJobName, "���");
		pPlayer->iAttackMin = 5;
		pPlayer->iAttackMax = 10;
		pPlayer->iArmorMin = 15;
		pPlayer->iArmorMax = 20;
		pPlayer->iHPMax = 500;
		pPlayer->iHP = 100;
		pPlayer->iMP = 100;
		pPlayer->iMPMax = 100;
		break;
	case JOB_ARCHER:
		strcpy_s(pPlayer->strJobName, "�ü�");
		pPlayer->iAttackMin = 10;
		pPlayer->iAttackMax = 15;
		pPlayer->iArmorMin = 10;
		pPlayer->iArmorMax = 15;
		pPlayer->iHPMax = 400;
		pPlayer->iHP = 400;
		pPlayer->iMP = 200;
		pPlayer->iMPMax = 200;
		break;
	case JOB_WIZARD:
		strcpy_s(pPlayer->strJobName, "������");
		pPlayer->iAttackMin = 15;
		pPlayer->iAttackMax = 20;
		pPlayer->iArmorMin = 5;
		pPlayer->iArmorMax = 10;
		pPlayer->iHPMax = 300;
		pPlayer->iHP = 300;
		pPlayer->iMP = 300;
		pPlayer->iMPMax = 300;

	}
}



int main() {

	srand((unsigned int)time(0));


	// ������ �����Ҷ� �÷��̾� ������ �����ϰ� �Ѵ�.
	_tagPlayer	tPlayer = {};

	// �÷��̾��� ������ �����Ѵ�.
	SetPlayer(&tPlayer);

	// ���͸� �����Ѵ�.
	_tagMonster tMonsterArr[MT_BACK - 1] = {};

	SetMonster(tMonsterArr);

	bool	bLoop = true;

	while (bLoop) {
		switch (OutputMainMenu()) {
		case MM_MAP:
			RunMap(&tPlayer, tMonsterArr); // �� ���� ������ ó���Ѵ�.
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