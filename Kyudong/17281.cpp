#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <cstring>
using namespace std;

int inning_player[51][10];
int base[4]; //홈, 1루,2루 3루
int N;
int ans = INT_MIN;

int order[10];
bool Select[10];

void initbase()
{
	for (int i = 0; i < 4; i++)
		base[i] = 0;
}


void playgame()
{
	int score = 0;//temp
	int start_player = 1;

	initbase();
	for (int inning = 1; inning < N + 1; inning++)
	{
		int outcount = 0;
		bool next_inning = false;
		initbase();
		//이닝당 반복문
		while (1)
		{
			for (int playernum = start_player; playernum < 10; playernum++)
			{
				int player = inning_player[inning][order[playernum]];

				if (player == 0) outcount++;

				else if (player == 1)
				{
					for (int i = 3; i >= 1; i--)  
					{
						if (base[i] == 1)
						{
							if (i == 3)          
							{
								base[i] = 0;
								score++;          
							}
							else
							{
								base[i + 1] = 1; 
								base[i] = 0;
							}
						}
					}
					base[1] = 1;
				}

				else if (player == 2)
				{
					for (int i = 3; i >= 1; i--)
					{
						if (base[i] == 1)
						{
							if (i == 3 || i == 2)
							{
								base[i] = 0;
								score++;
							}
							else
							{
								base[i + 2] = 1;
								base[i] = 0;
							}
						}
					}
					base[2] = 1;
				}

				else if (player == 3)
				{
					for (int i = 3; i >= 1; i--)
					{
						if (base[i] == 1)
						{
							base[i] = 0;
							score++;
						}
					}
					base[3] = 1;

				}

				else if (player == 4)
				{
					for (int i = 1; i <= 3; i++)
					{
						if (base[i] == 1)
						{
							base[i] = 0;
							score++;             
						}
					}
					score++;
				}
				//다음이닝 넘어갈때 순서가 이전이닝 마지막선수 다음선수부터 시작해야되서
				if (outcount == 3)
				{
					start_player = playernum + 1;
					if (start_player == 10) start_player = 1;
					next_inning = true;
					break;//for문 깨주고
				}

			}
			if (next_inning == true) break; //while문깨주고
			start_player = 1;

		}
	}
	ans = max(ans, score);
}

void makeorder(int count)//dfs 선수들 순서 정해주는거
{
	if (count == 10)
	{
		playgame();
		return;
	}

	for (int i = 1; i < 10; i++)
	{
		if (Select[i] == true) continue;
		Select[i] = true;
		order[i] = count;
		makeorder(count + 1);
		Select[i] = false; 
	}

}

int main()
{
	cin >> N;
	for (int i = 1; i < N + 1; i++)
		for (int j = 1; j < 10; j++)
			cin >> inning_player[i][j];

	Select[4] = true;
	order[4] = 1;
	makeorder(2);

	cout << ans;
	return 0;
}