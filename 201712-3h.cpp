// Cronlab.cpp: 定义控制台应用程序的入口点。
//
#include<iostream>
#include<string>
#include<time.h>
#include<sstream>
#include<set>
#include<vector>
#include<algorithm>
#define MIN 0
#define HOUR 1
#define DAY 2
#define MON 3
#define WEEK 4
using namespace std;
/*W= (d+2*m+3*(m+1)/5+y+y/4-y/100+y/400+1) mod 7
在公式中d表示日期中的日数，m表示月份数，y表示年数。
这是一个根据日期来判断星期几的公式，当然即使没有这个公式我觉得也能推出来*/
string Mon[13] = { "ZERO","JAN","FEB","MAR","APR","MAY","JUN","JUL","AUG","SEP","OCT"
,"NOV","DEC" };
string NMon[13] = { "0","1","2","3","4","5","6","7","8","9","10","11","12" };
string Week[7] = { "SUN","MON","TUE","WED","THU","FRI","SAT" };
string NWeek[7] = { "0","1","2","3","4","5","6" };
struct Out {
	unsigned long long time;
	int NIns;
}*pOut;
vector<struct Out> Outs;
void English2Number(string &res)
{
	/*将所有的小写字母转化为大写字母*/
	int pos;
	for (unsigned int i = 0; i < res.length(); ++i)
	{
		if (res[i] >('a' - 1) && res[i] < ('z' + 1))
			res[i] += ('A' - 'a');
	}
	/*将英文缩写转换成数字*/
	for (int i = 0; i < 13; ++i)
	{
		if ((pos = res.find(Mon[i])) != -1)
		{
			res.replace(pos, 3, NMon[i]);
		}
	}
	for (int i = 0; i < 7; ++i)
	{
		if ((pos = res.find(Week[i])) != -1)
		{
			res.replace(pos, 3, NWeek[i]);
		}
	}
	return;
}
void S2Number(string &res, int Code)
{
	int pos;
	if ((pos = res.find("*")) != -1)
	{
		switch (Code)
		{
		case MIN:
			res.replace(pos, pos + 1, "0-59");
			break;
		case HOUR:
			res.replace(pos, pos + 1, "0-23");
			break;
		case WEEK:
			res.replace(pos, pos + 1, "0-6");
			break;
		case DAY:
			res.replace(pos, pos + 1, "1-31");
			break;
		case MON:
			res.replace(pos, pos + 1, "1-12");
			break;
		default:
			break;
		}
	}
}
void R2Number(string &res, set<unsigned long long> & U)
{
	unsigned int pos;
	int begin, end;
	int n1, n2;
	while ((pos = res.find("-")) != -1)
	{
		/*判断是一位数还是两位数*/
		if (pos>1 && res[pos - 2] >= '0'&&res[pos - 2] <= '9')
			begin = pos - 2;
		else
			begin = pos - 1;
		if (pos<res.length() - 1 && res[pos + 2] >= '0'&&res[pos + 2] <= '9')
			end = pos + 2;
		else
			end = pos + 1;
		stringstream ss;
		ss << res.substr(begin, pos - begin);
		ss >> n1;
		ss.clear();
		ss << res.substr(pos + 1, end - pos);
		ss >> n2;
		res.erase(begin, end - begin + 1);
		for (int i = n1; i <= n2; ++i)
		{
			U.insert(i);
		}
	}
}
void T2Number(string &res, set<unsigned long long>& U)
{
	if (res == "")return;
	int pos;
	int n;
	while ((pos = res.find(",")) != -1)
	{
		stringstream ss;
		ss << res.substr(0, pos);
		ss >> n;
		U.insert(n);
		res.erase(0, pos + 1);
	}
	stringstream ss;
	ss << res;
	ss >> n;
	U.insert(n);

}
bool sort_by_time(const struct Out &A, const struct Out &B)
{
	if (A.time < B.time)
		return true;
	else if (A.time == B.time&&A.NIns<B.NIns)
	{
		return true;
	}
	else
		return false;
}
int main()
{
	int n;
	cin >> n;
	string begin, end;
	/*提取出开始和结束的年份*/
	cin >> begin;
	cin >> end;
	int year1, year2;
	stringstream ss;
	ss << begin.substr(0, 4);
	ss >> year1;
	ss.clear();
	ss << end.substr(0, 4);
	ss >> year2;
	unsigned long long Nbegin, Nend;
	ss.clear();
	ss << begin;
	ss >> Nbegin;
	ss.clear();
	ss << end;
	ss >> Nend;
	vector<string> Ins;
	for (int i = 0; i < n; ++i)
	{
		string min, hour, day, mon, week;
		cin >> min; cin >> hour; cin >> day;
		cin >> mon; cin >> week;
		string ins;
		cin >> ins;
		Ins.push_back(ins);
		/*第一步去除英文*/
		English2Number(mon); English2Number(week);
		/*第二步将*用数字替换 */
		S2Number(min, MIN); S2Number(hour, HOUR); S2Number(day, DAY); S2Number(mon, MON); S2Number(week, WEEK);
		/*第三步处理带范围的数字*/
		set<unsigned long long> Smin; set<unsigned long long> Shour; set<unsigned long long>Sday; set<unsigned long long>Smon; set<unsigned long long>Sweek;
		R2Number(min, Smin); R2Number(hour, Shour); R2Number(day, Sday); R2Number(mon, Smon); R2Number(week, Sweek);
		/*第四步处理普通的数字*/
		T2Number(min, Smin); T2Number(hour, Shour); T2Number(day, Sday); T2Number(mon, Smon); T2Number(week, Sweek);
		/*第五步将各位数字组合生成一新数字*/
		set<unsigned long long>::iterator Imin; set<unsigned long long>::iterator Ihour; set<unsigned long long>::iterator Iday; set<unsigned long long>::iterator Iweek; set<unsigned long long>::iterator Imon;
		for (unsigned long long y = year1; y <= year2; y++)
		{
			unsigned long long y1;
			for (Imon = Smon.begin(); Imon != Smon.end(); Imon++)
			{
				unsigned long long m = *Imon;
				if (m == 1 || m == 2)
				{
					m += 12;
					y1 = y - 1;
				}
				else
				{
					y1 = y;
				}
				for (Iday = Sday.begin(); Iday != Sday.end(); Iday++)
				{
					/*检查当月是否有这一天*/
					if (*Iday > 30 && (*Imon == 2 || *Imon == 4 || *Imon == 6 || *Imon == 9 || *Imon == 11))
						continue;
					if (!((y % 100 != 0 && y % 4 == 0) ||(y % 400 == 0)) && *Iday > 28 && *Imon == 2)//平年
						continue;
					if (((y % 100 != 0 && y % 4 == 0) ||(y % 400 == 0)) && *Iday > 29 && *Imon == 2)//闰年，2000年是闰年
						continue;
					/*检查这一天是否是否符合给定的星期*/
					for (Iweek = Sweek.begin(); Iweek != Sweek.end(); Iweek++)
					{
						if (*Iweek == (*Iday + 2 * m + 3 * (m + 1) / 5 + y1 + y1 / 4 - y1 / 100 + y1 / 400 + 1) % 7)
							break;
					}
					if (Iweek == Sweek.end())
						continue;

					for (Ihour = Shour.begin(); Ihour != Shour.end(); Ihour++)
					{
						for (Imin = Smin.begin(); Imin != Smin.end(); Imin++)
						{
							/*最终组合出正确的时间*/
							unsigned long long time = 0;
							time += *Imin;
							time += *Ihour * 100;
							time += (*Iday) * 10000;
							time += (*Imon) * 1000000;
							time+=(y) * 100000000;

							if (time<Nbegin || time>=Nend)
								continue;
							struct Out out;
							out.time = time;
							out.NIns = i;
							Outs.push_back(out);
						}
					}
				}
			}
		}

	}
	sort(Outs.begin(), Outs.end(), sort_by_time);
	vector<Out>::iterator i;
	for (i = Outs.begin(); i < Outs.end(); ++i)
	{
		cout << (*i).time << " " << Ins[(*i).NIns] << endl;
	}
	//system("pause");
	return 0;
}

