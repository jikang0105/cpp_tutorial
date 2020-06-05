/*
관리프로그램 만들기
도서 대여 프로그램 만들기
1. 책 등록
2. 책 대여
3. 책 반납
4. 책 목록
5. 종료

책 구조체는 이름, 대여금액, 책번호, 대여여부가 필요하다.

책 목록을 선택하면 책 정보를 출력해준다.
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
	// 대여불가 0(true), 대여가능 >= 1(false)
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
	// 단일 책의 개수.
	int iBookCount = 0;
	// 책의 종류(중복되는 책은 세지 않는다.)
	int iBooksCount = 0;

	while (true) {

		system("cls");
		cout << "1. 책 등록" << endl;
		cout << "2. 책 대여" << endl;
		cout << "3. 책 반납" << endl;
		cout << "4. 책 목록" << endl;
		cout << "5. 종료" << endl;

		cout << "매뉴를 선택하세요. : ";
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
			cout << "=============== 책 등록 ===============";
			
			if (iBooksCount == BOOK_MAX) {
				break;
			}

			cout << "책 이름 : ";
			cin.getline(tBookArr[iBookIdx].strName, NAME_SIZE);
			cin.ignore(1024, '\t');

			cout << "대여 금액 : ";
			cin.getline(tBookArr[iBookIdx].strPrise, PRISE_SIZE);
			cin.ignore(1024, '\t');

			cout << "책 번호 : ";
			cin.getline(tBookArr[iBookIdx].strNumber, NUMBER_SIZE);
			cin.ignore(1024, '\t');

			cout << "권 수 : ";
			cin >> iBookCount;
				
			tBookArr[iBookIdx].iBCount = iBookCount;

			// 서 bRent값에 0을 부여하여 대여 가능한 상태로 만든다.
			tBookArr[iBookIdx].iRent = iBookCount;

			tBookArr[iBookIdx].iBsCount += iBookCount;

			++iBooksCount;
			++iBookNumber;


			break;
		case MENU_RENT:
			break;
		case MENU_RETURN:
			break;
		case MENU_LIST:
			system("cls");
			for(int i = 0; i <)
			break;
		case MENU_END:
			break;
		}
	}
}