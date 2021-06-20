/*
* Strfry ����: O(n)
https://www.acmicpc.net/problem/11328
*/
#include <iostream>
#include <cstring>
using namespace std;

bool compareArr(int* arr1, int* arr2, int size);
int* cntAlphabet(string str);

int main()
{
	int testSize;
	cin >> testSize;

	for (int i = 0; i < testSize; i++)
	{
		string str1, str2;
		cin >> str1;
		cin >> str2;

		if (str1.length() != str2.length())
		{
			cout << "Impossible" << endl;
		}

		else if (compareArr(cntAlphabet(str1), cntAlphabet(str2), 26))
		{
			cout << "Possible" << endl;
		}
		else
		{
			cout << "Impossible" << endl;
		}

	}


	return 0;
}

//Array�� ������(true) �ٸ���(false) ��
bool compareArr(int* arr1, int* arr2, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (arr1[i] != arr2[i])
			return false;
	}
	return true;
}

//���ĺ�a~z���� ���� ��� �ִ��� ���� �迭�� ����� ��ȯ ex)a -> 1000000...
int* cntAlphabet(string str)
{
	int* cnt = new int[26]();

	for (int i = 0; i < str.length(); i++)
	{
		cnt[(int)str[i] - 97]++;
	}
	
	/*for (int i = 0; i < 26; i++)
	{
		cout << cnt[i] << " ";
	}
	cout << endl;*/

	return cnt;
}


