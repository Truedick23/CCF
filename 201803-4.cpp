
#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <time.h>
#include <vector>
#include <list>

using namespace std;
//201803-4  �������
struct Chess {
	int num[3][3];	//��ǰ����
	int Sum;		//���Ƶ�Ψһ��ʶ
	bool flag;		//��ʾ����˭����
	int score;		//�÷�
};
map<int, Chess>Array;	//�����������ľ���

struct My_int {
	int score;
	bool Flag;
	bool operator <(const My_int& s)const
	{
		if (Flag == 1)
			return score > s.score;		//��С��
		else
			return score < s.score;			//����
	}
};
void Get_Num(Chess &D)
{
	int Sum = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> D.num[i][j];
			Sum += D.num[i][j] * pow(3, i * 3 + j);
		}
	}
	D.flag = 0;		//����Alice��X
	D.Sum = Sum;
}
bool Judge(int num[3][3], int &p)
{
	int Zreo_Num = 0;
	int ff = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (num[i][j] == 0)
				Zreo_Num++;
		}
	}
	for (int i = 0; i < 3; i++)
	{
		if (num[i][i] != 0)
		{
			if ((num[i][0] == num[i][1] && num[i][1] == num[i][2]) || (num[0][i] == num[1][i] && num[1][i] == num[2][i]))
			{
				ff = num[i][i]; break;
			}
			else if (i == 1 && ((num[0][0] == num[1][1] && num[1][1] == num[2][2]) || (num[0][2] == num[1][1] && num[1][1] == num[2][0])))
			{
				ff = num[i][i]; break;
			}
		}
	}
	if (ff == 0 && Zreo_Num == 0)	//���������û��ʤ����
	{
		p = 0; return 1;		//ƽ�֣�����
	}
	else if (ff == 1)	//Aliceʤ��
	{
		p = Zreo_Num + 1; return 1;	//����
	}
	else if (ff == 2)	//Bobʤ��
	{
		p = -Zreo_Num - 1; return 1;	//����
	}
	else
		return 0;	//��Ϸû����
}
int Find_Score(Chess D)
{
	if (Array.find(D.Sum) == Array.end())	//��ʾ��û�м�������־��Ƶķ���
	{
		int p;
		if (bool F = Judge(D.num, p))		//�Ѿ��ֳ�ʤ��
			return p;
		priority_queue<My_int> S;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (D.num[i][j] == 0)
				{
					Chess Save = D;
					Save.num[i][j] = 1 + D.flag;
					Save.Sum += Save.num[i][j]*pow(3, i * 3 + j);
					Save.flag = !D.flag;	//�������ӵ���
					My_int s;
					s.score = Find_Score(Save);
					s.Flag = D.flag;
					S.push(s);
				}
			}
		}
		D.score = S.top().score;
		Array[D.Sum] = D;		//���浱ǰ���ƽ����������
		return D.score;		//��������
	}
	else
		return Array[D.Sum].score;
}
int main()
{
	int i, j, N, M;
	Chess Data;
	cin >> N;

	//int mm = Find_Score(Data);

	for (i = 0; i < N; i++)
	{
		Get_Num(Data);
		M = Find_Score(Data);
		cout << M << endl;
	}

	cin >> N;
	return 0;
}
