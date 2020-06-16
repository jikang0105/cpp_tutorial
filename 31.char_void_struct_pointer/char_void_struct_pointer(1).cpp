#include <iostream>

using namespace std;

struct _tagStudent {
	int iKor;
	int iEng;
	int iMath;
	int iTotal;
	float	fAvg;
};

int main() {

	int iNumber = 100;

	// �ٲ��� ���� ����� ���ڿ��鸸 �� ������� Ȱ���Ѵ�. ���� ���ڿ��� �ٲ� ���ɼ��� �ִٸ�,
	// ������ �迭�� �����Ͽ� ���ڸ� �Ҵ��Ѵ�.
	const char* pText = "�׽�Ʈ ���ڿ�";
	
	cout << pText << endl;
	cout << (int*)pText << endl;
		
	/*
	����̹Ƿ� ������ �Ұ��� �ϴ�.
	pText[1] = 'a';
	pText[2] = 'b';
	*/

	// �����Ͱ� ����Ű�� ����� �޶�����
	pText = "abcd";

	cout << pText << endl;
	cout << (int*)pText << endl;

	pText = "abcdefg";

	cout << pText << endl;
	cout << (int*)pText << endl;

	// �迭�� ������ �����Ͽ� ���ڸ� �Ҵ��ϴ� ��� ���ڰ� ����� �ƴ� ������ �ȴ�.
	char str[8] = "adcdefg";

	cout << str << endl;
	cout << (int*)str << endl;
	cout << (int*)&str[0] << endl;

	_tagStudent tStudent = {};

	tStudent.iKor = 100;

	_tagStudent* pStudent = &tStudent;

	// ������ �켱���� ������ .�� ���� �ν��ϰ� �ȴ�. �޸� �ּ�.�� �߸��� �����̴�.
	// �׷��Ƿ� *pStudent�� ��ȣ�� ������ �Ŀ� .�� �̿��ؼ� ����Ű�� ����� ���������
	// �����ؾ� �Ѵ�.
	(*pStudent).iKor = 50;

	// �޸��ּ�-> �� �̿��ؼ� ����Ű�� ����� ����� ������ �� �ִ�.
	pStudent->iKor = 80;

	cout << tStudent.iKor << endl;

	// void : Ÿ���� ����. void�� ������ Ÿ���� Ȱ���� �� �ִ�.
	// void* ������ �����ϰ� �Ǹ� �� ������ � Ÿ���� �޸� �ּҵ� ��� ���尡���ϴ�.
	// ��, �������� �Ұ����ϰ� �޸� �ּҸ� ���� �����ϴ�.
	void* pVoid = &iNumber;

	cout << "iNumber Address : " << pVoid << endl;
	// �������� �Ұ����ϴ�.
	//*pvoid = 10;
	
	// ����ȯ�� �ϸ� �����ϴ�.
	int* pConvert = (int*)pVoid;
	*pConvert = 10101010;
	// ������ �������ε� �����ϴ�.
	*((int*)pVoid) = 9999;
	cout << iNumber << endl;

	pVoid = &tStudent;

	cout << "tStudent Address : " << pVoid << endl;


	return 0;
}