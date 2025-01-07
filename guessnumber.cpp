#include <iostream>
#include <time.h>
using namespace std;
int num[4];
int guess[4];
int guessnumber;
int x = 0, y = 0;
bool nguess = 0;
int guesstime = 0;
int main()
{
	srand(time(NULL));
	for (int i = 0; i < 4; i++)
	{
		num[i] = 0 + rand() % 10;
	}
	cout << "请猜4个数字" << endl;
	while (guesstime <= 9)
	{
		x = 0, y = 0;
		cin >> guessnumber;
		guess[0] = guessnumber / 1000;
		guessnumber -= 1000 * guess[0];
		guess[1] = guessnumber / 100;
		guessnumber -= 100 * guess[1];
		guess[2] = guessnumber / 10;
		guessnumber -= 10 * guess[2];
		guess[3] = guessnumber;
		bool a = 1, b = 1, c = 1, d = 1;
		for (int i = 0; i < 4; i++)
		{
			if (num[i] == guess[i])
			{
				x++;
				switch (i)
				{
				case 0: a = 0; break;
				case 1: b = 0; break;
				case 2: c = 0; break;
				case 3: d = 0; break;
				}
			}
		}
		for (int j = 0; j < 4; j++)
		{
			for (int i = 0; i < 4; i++)
				if (guess[j] == num[i] && i != j)
				{
					bool s = 0;
					switch (i)
					{
					case 0: if (a) { y++; a = 0; s = 1; }break;
					case 1: if (b) { y++; b = 0; s = 1; } break;
					case 2: if (c) { y++; c = 0; s = 1; } break;
					case 3: if (d) { y++; d = 0; s = 1; } break;
					}
					if (s)
						break;
				}
		}
		if (x == 4)
		{
			nguess = 1;
			break;
		}
		else
		{
			cout << "结果: " << x << "A" << y << "B,还剩" << 9 - guesstime << "次猜测机会" << endl;
		}
		guesstime++;
	}
	if (nguess)
		cout << "恭喜你，猜对了！" << endl;
	else
	{
		cout << "正确答案是: " << num[0] << " " << num[1] << " " << num[2] << " " << num[3] << endl;
	}
	return 0;
}
