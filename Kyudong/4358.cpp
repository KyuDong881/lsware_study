#include <iostream>
#include <string>
#include <map>

using namespace std;
map<string, float> m;
	
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);//���� ���
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
	//eof������ ����
	cout << fixed;
	cout.precision(4);
	map<string, float>::iterator i;
	for (i = m.begin(); i != m.end(); i++)
	{
		float value = (i->second / cnt) * 100;
		cout << i->first << " ";
		cout << value << "\n";
	}
	//map�̰� ���� �ڵ����� ��������?? Ű��������?? ������������
	return 0;

}