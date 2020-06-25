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

// 숫자 입력을 받는다. 입력 오류까지 처리해주고 INT_MAX를 리턴하면 입력 오류이다.
int InputInt() {
	int iInput;
	cin >> iInput;

	if (cin.fail()) {
		cin.clear();
		cin.ignore(1024, '\n');
		return INT_MAX; // INT_MAX가 리턴되면 입력이 잘못됐다는 의미로 쓰기로 함.
	}

	return iInput;
}

// 메인 메뉴를 화면에 보여주고 입력받은 메뉴를 반환한다. 입력 오류일 경우 혹은 잘못된 번호를 
// 입력한 경우 0을 반환한다.
int OutputMainMenu() {
	system("cls");
	cout << "***************** 로비 *****************" << endl;
	cout << "1. 맵" << endl;
	cout << "2. 상점" << endl;
	cout << "3. 가방" << endl;
	cout << "4. 종료" << endl;
	cout << "메뉴를 선택하세요. : ";
	int iMenu = InputInt();

	if (iMenu == INT_MAX || iMenu <= MM_NONE || iMenu > MM_EXIT) {
		return MM_NONE;
	}

	return iMenu;
}

int OutputMapMenu() {
	system("cls");
	cout << "****************** 맵 ******************" << endl;
	cout << "1. 쉬움" << endl;
	cout << "2. 보통" << endl;
	cout << "3. 어려움" << endl;
	cout << "4. 뒤로가기" << endl;
	int iMenu = InputInt();

	if (iMenu == INT_MAX || iMenu <= MT_NONE || iMenu > MT_BACK) {
		return MT_NONE;
	}

	return iMenu;
}

// Map에 관련된 동작을 처리한ㄷ.
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
		cout << "1. 기사" << endl;
		cout << "2. 궁수" << endl;
		cout << "3. 마법사" << endl;
		cout << "직업을 선택하세요 : ";
		iJob = InputInt();

		if (iJob == INT_MAX || iJob <= JOB_NONE || iJob > JOB_END) {
			iJob = JOB_NONE;
		}
	}
}

void SetPlayer(_tagPlayer* pPlayer) {
	// 플레이어의 이름을 입력받는다.
	cout << "이름 : ";
	cin.getline(pPlayer->strName, NAME_SIZE - 1);
}

int main() {

	srand((unsigned int)time(0));


	// 게임을 시작할때 플레이어 정보를 설정하게 한다.
	_tagPlayer	tPlayer = {};

	// 플레이어의 정보를 정의한다.
	SetPlayer(&tPlayer);


	bool	bLoop = true;

	while (bLoop) {
		switch (OutputMainMenu()) {
		case MM_MAP:
			RunMap(); // 맵 관련 루프를 처리한다.
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