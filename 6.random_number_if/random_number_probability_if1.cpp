#include <iostream>
#include <time.h> // 시간에 관련된 기능들

using namespace std;

int main() {
	
	
	//난수 발생
	srand((unsigned int)time(0)); // time(0) : 현재시간을 기준으로 시간을 불러오는 것

	cout << rand() << endl;
	cout << rand() << endl;
	cout << rand() << endl;
	cout << (rand() % 101) << endl; // 0~100 사이의 난수.
	cout << (rand() % 101 + 100) << endl; // 100 ~ 200 사이의 난수.
	cout << ((rand() % 10000) / 100.f) << endl; // 0 ~ 99.99 사이의 난수.

	int iUpgrade = 0;
	cout << "Upgrand 기본 수치를 입력하세요 : ";
	cin >> iUpgrade;

	// 강화 확률을 구한다.
	float fPercent = rand() % 10000 / 100.f;
	
	// 강화 확률 : 업그레이드가 0 ~ 3 : 100% 성공. 4 ~ 6 : 40%, 7 ~ 9 : 10%
	// 10 ~ 13 : 1%, 14 ~ 15 : 0.01%
	cout << "Upgrede : " << iUpgrade << endl;
	cout << "Percent : " << fPercent << endl;

	if (iUpgrade <= 3)
		cout << "강화 성공" << endl;
	else if (4 <= iUpgrade && iUpgrade <= 6) {
		if (fPercent < 40.f)
			cout << "강화 성공" << endl;
		else
			cout << "강화 실패" << endl;
	}
	else if (7 <= iUpgrade && iUpgrade <= 9) {
		if (fPercent < 10.f)
			cout << "강화 성공" << endl;
		else
			cout << "강화 실패" << endl;
	}
	else if (10 <= iUpgrade && iUpgrade <= 13) {
		if (fPercent < 1.f)
			cout << "강화 성공" << endl;
		else
			cout << "강화 실패" << endl;
	}
	else if (14 <= iUpgrade && iUpgrade <= 15) {
		if (fPercent < 0.01f)
			cout << "강화 성공" << endl;
		else
			cout << "강화 실패" << endl;
	}

	return 0;
}