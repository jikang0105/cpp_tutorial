#include <iostream>

using namespace std;

int main() {

	int iNumber1 = 1111;
	int iNumber = 2222;
	int* pNum = &iNumber;

	// ���� ������ : *�� 2�� ���δ�. �Ϲ� ������ ����� �Ϲݺ����� �޸� �ּҸ� �����ϴ�
	// ������� ���������ʹ� �������� �������̴�. ��, ���������ʹ� ������ ������ �޸� �ּҸ�
	// �����ϴ� �������̴�.
	int** ppNum = &pNum;

	*ppNum = &iNumber1;
	*pNum = 3333;

	cout << "iNumber1 : " << iNumber1 << endl;
	cout << "iNumber : " << iNumber << endl;
	cout << "iNumber Addr : " << &iNumber << endl;
	cout << "*pNum : " << *pNum << endl;
	cout << "pNum Value : " << pNum << endl;
	cout << "pnum Addr : " << &pNum << endl;
	cout << "*ppNum : " << *ppNum << endl;
	cout << "**ppNum : " << **ppNum << endl;
	cout << "ppNum : " << ppNum << endl;
	cout << "ppNum Addr : " << &ppNum << endl;

	return 0;
}