#include"game_body.h"

int main()
{

	int time = 0, judge = 1; int k = 0;
	while (judge)
	{
		menu();
		string  n = "";
		cin >> n;

		if (n == "1")
		{
			print1();
		next1:int m = 0;
			cin >> m;
			if (1 == m)
			{
				print2(time);
				judge = 0;
			}

			else if (0 == m)
			{
				cout << "退出游戏，祝您愉快" << endl;
				judge = 0;
			}
			else if (m != 0 && m != 1)
			{
				cout << "输入错误，请重新输入" << endl;
				goto next1;
			}
			break;
		}
		else if (n == "0")cout << "退出游戏" << endl;
		else
		{
			cout << "输入错误，请重新选择" << endl;
		}
	}

	if (time == 1)
	{
		cout << "在游玩开始前，请输入此次游玩的人数" << endl;
		cout << "每一个玩家可以输入自己的游戏昵称" << endl;
		cout << "请输入游玩人数" << "   "; int n, m; cin >> n; m = n;
		if (n > 1000) { cout << "超出最大人数限制（最多为1000），请自动重启" << endl; return 0; }
		else
		{
			player* s = new player[n];

			for (int i = 0; i < n; ++i)
			{
				cout << "您是玩家" << i + 1 << endl;
				cout << "请输入你的游戏昵称: "; cin >> s[i].name;
				list_in(i, s);
				play_choose(time, i);
				if (time == 0 || time == -1) { time = 1; k++; }
			}
			delete[]s; s = NULL;

		}
	}
	keep(k);
	return 0;
}
