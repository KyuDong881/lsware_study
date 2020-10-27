#include <iostream>
#include <string>
#include <map>

using namespace std;
map<string, float> m;
	
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);//성능 향상
	string str;
	float cnt = 0;

	while (getline(cin, str))
	{
		cnt++;
		if (m.find(str) != m.end())
		{
			m[str] += 1;
		}
		else
			m[str] = 1;
	}
	//eof들어오면 종료
	cout << fixed;
	cout.precision(4);
	map<string, float>::iterator i;
	for (i = m.begin(); i != m.end(); i++)
	{
		float value = (i->second / cnt) * 100;
		cout << i->first << " ";
		cout << value << "\n";
	}
	//map이게 원래 자동으로 정렬해줌?? 키값에따라서?? 오름차순으로
	return 0;

}