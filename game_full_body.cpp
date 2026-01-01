
#include"game_body.h"
using namespace std;
const int L = 1000;
player p[L];
string name2[L];//排名输出需要的
double e[L];//用于映射的新的分数

void keep(int k)
{
	ofstream cc("list.txt");
	if (!cc.is_open())
	{
		cerr << "error:unable to open input file:" << list << endl;
	}
	else
	{
		cc<<"  " << "游戏排名" << endl;
		for(int i=0;i<k;++i)
		{
		cc<<"第" <<i+1<<"名：  " << p[i].name << "  " <<"游戏得分： " << p[i].score << endl;
		}
	}
	cc.close();
}

void menu()
{
	cout<<endl;
	cout << "*********************" << endl;
	cout << "********************" << endl;
	cout << "******欢迎游玩*******" << endl;
	cout << "*****输入'1'查看规则*****" << endl;
	cout << "*****输入'0'退出*****" << endl;
	cout << "********************" << endl;
}
void print1()
{
	cout<<endl;
	cout<<"本程序的所有游戏为控制台游戏，无可视化界面，请见谅"<<endl;
	cout << "游玩前，请您知晓所有的游戏，并按相应的数字进行游戏" << endl;
	cout<<"游戏可供多人分批次进行游玩，并且有每个人的排名"<<endl;
	cout << "请先让我告知所有的游戏规则" << endl;
	cout << "您一开始有0次游玩次数，但当您的游戏次数为0时，您可参与获得游玩机会的问答" << endl;
	cout << "在游戏中通关可以获得相应分数，并获取一次游玩机会" << endl;
	cout<<"您的初始分数为7分，当分数达到77时，可找作者兑换奖品"<<endl;
	cout<<"相同分数时先达到该分数的排名在前位"<<endl;
	cout << "游戏菜单：（1）扫雷游戏 （2）重生（3）猜数字游戏  " << endl;
	cout<<endl;
	cout << endl; cout << endl; cout << endl;
	cout << "现在您可按'1'来进行游玩机会问答，也可以按'0'退出游戏" << endl;
}
void print2(int &time)
{
	cout<<endl;
	cout<<"请问作者帅吗？"<<endl;
	cout<<"扣1回答帅，扣0回答不帅"<<endl;
	int s;cin>>s;
	if(s==1)++time;
	else if(s!=1)error();
	
}
void error()
{
	while(1)cout<<"程序崩溃，执行失败";
}


void play_choose(int&time,int f)
{
	cout<<endl;
	next3:cout<<"输入游戏对应的序号即可开始游戏"<<endl;
	cout << "游戏菜单：（1）扫雷游戏 （2）重生（3）猜数字游戏   " << endl;
	/*int n;
	cin >> n;
	switch (n)
	{
	case 1: { game1(time, f); break; }
	case 2: { cout << "暂无权限游玩此游戏（或许在另外的游戏里面能获得权限呢）" << endl; goto next3; break; }
	case 3: { game3(time, f); break; }
	default: { error(); break; }
	}*/
	string n;
	cin>>n;
	
		if(n=="1"){game1(time, f);  }
		else if(n=="2"){cout << "暂无权限游玩此游戏（或许在另外的游戏里面能获得权限呢）" << endl; goto next3;}
		else if(n=="3"){game3(time, f);  }
		else {error();}
	}


void judge_end(int& time,int f)
{
	list(f);
	if (time == 0)
	{
		cout << "游戏结束" << endl;
		list_out(f);
		 if (e[f] >= 40)
		{
		
			cout<<"你的分数已经达到了40分以上"<<endl;
			cout<<"就此死亡，你甘心吗？"<<endl;
			cout<<"(1)甘心   (2)不甘心"<<endl;
			cout<<"输入你的抉择吧，玩家"<<endl;
			int x;cin>>x;
			if(x==1)cout<<"再见了玩家，但请你在今后的任何选择中都不要后悔过自己的选择"<<endl;
			else if(x==2){time++;game2(time,f); }
		}

	}
	if(time==-1){
		cout << "游戏彻底结束" << endl;
		list_out(f);
	}
	if (time == 1)
	{
		cout<<"你仍有机会进行游戏"<<endl;
		cout<<"输入 1 可查看排名与分数(输入其他直接开始选择游戏)"<<endl;
		cout<<"何必在意排名，直接梭哈到底"<<endl;
		int a;cin>>a;if(1==a)list_out(f);else cout<<"输入错误，说明你不在意排名，强者(doge)"<<endl;
		play_choose(time,f);
	}
}
void list_in(int n,player s[])
{
	if(n<=L)
	{ 
		p[n].name=s[n].name;
		name2[n]=s[n].name;
		e[n]=7.0;
	}
}
void list(int n)
{
	//排序前要更新一下
	string t=name2[n];
	
	for (int i = 0; i <=n; ++i)
	{
		if(p[i].name==t)p[i].score=e[n];
	}

	//排序一下
	if(n>=1)
	{ 
		for (int i = 0; i <=n - 1; ++i)
		{
			double tmp1=0;string tmp2="";
			for (int j=i+1;j<=n;++j)
			{
				if(p[i].score<p[j].score)
				{ 
					tmp1=p[i].score;tmp2=p[i].name;
					p[i].score=p[j].score;p[i].name=p[j].name;
					p[j].score=tmp1;p[j].name=tmp2;
				}
			}
		}
	}
}
void list_out(int n)
{
	cout<<"排名为"<<endl;
	cout<<"排名   " << "昵称" << "   " << "分数" << endl;
	for(int i=0;i<=n;++i)
	{
		cout<<"第" <<i+1<<"名   " << p[i].name << "   " << p[i].score << endl;
	}
	int cnt=0;
	string tmp=name2[n];
	for (int i = 0; i <= n; ++i)
	{
		cnt++;
		if (p[i].name == tmp)
		{
			break; 
		}
		
	}
	//bug:这里需要注意一下，因为p的排名变化导致目前玩家的顺序变化，但是n不变，所以这里需要把n的值变为玩家排名才行
	//修改方案可以为把n变为cnt，但涉及好多f与n的变化，比较麻烦。所以可以创建一个新的score数组用来存分数，在进行判断时先找到玩家再赋予值
	cout<<"玩家"<<name2[n]<<"  您的排名为第"<<cnt<<"名"<<endl;
	cout<<endl;
}
void game3(int &Time,int f)//猜数字
{
	srand((unsigned int)time(NULL));
	cout<<"请选择游戏难度："<<endl;
	cout<<"（1）猜25以内的数字（2）猜50以内的数字（3）猜100以内的数字（4）猜500以内的数字"<<endl;
	cout<<"猜测次数依次为3，4，6，8次，猜到得分依次为5分，10分，15分，20分"<<endl;
	cout<<"那么，请拥有无限好运的你输入相应的数字开始游戏吧"<<endl;
	int n=0,m=0,count=0;
	next1: cin>>n;
	switch (n)
	{
		default :
		{
			cout<<"选择错误，请重新选择"<<endl;
			goto next1;
			break;
		}
		case 1:
		{
			count=3;
			int n1=rand()%26;
			while(count)
			{ 
				cout<<"请输入你猜的数字"<<endl;
				cin>>m;
				if (m > n1)
				{
					--count;
					cout<<"你输入的值偏大，请重新输入"<<endl;
					cout<<"你还有"<<count<<"次机会"<<endl;
				}
				else if (m < n1)
				{
					--count;
					cout << "你输入的值偏小，请重新输入" << endl;
					cout << "你还有" << count << "次机会" << endl;
				}
				else if (m == n1)
				{
					cout<<"恭喜你猜对了"<<endl;
					count=0;
					e[f]+=5;
				}
			 }
			 if(m!=n1)
			 {
			 Time = 0;
			 e[f] += 0;
			 cout<<"正确的数字是"<<n1<<endl;
			 }
			judge_end(Time,f);
			break;
		}
		case 2:
		{
			count = 4;
			int n1 = rand() % 51;
			while (count)
			{
				cout << "请输入你猜的数字" << endl;
				cin >> m;
				if (m > n1)
				{
					--count;
					cout << "你输入的值偏大，请重新输入" << endl;
					cout << "你还有" << count << "次机会" << endl;
				}
				else if (m < n1)
				{
					--count;
					cout << "你输入的值偏小，请重新输入" << endl;
					cout << "你还有" << count << "次机会" << endl;
				}
				else if (m == n1)
				{
					cout << "恭喜你猜对了"<<endl;
					count = 0;
					e[f] += 10;
				}
			}
			if (m!=n1)
			{
				Time = 0;
				e[f] += 0;
				cout << "正确的数字是" << n1 << endl;
			}
			judge_end(Time, f);
			break;
		}
		case 3:
		{
			count = 6;
			int n1 = rand() % 101;
			while (count)
			{
				cout << "请输入你猜的数字" << endl;
				cin >> m;
				if (m > n1)
				{
					--count;
					cout << "你输入的值偏大，请重新输入" << endl;
					cout << "你还有" << count << "次机会" << endl;
				}
				else if (m < n1)
				{
					--count;
					cout << "你输入的值偏小，请重新输入" << endl;
					cout << "你还有" << count << "次机会" << endl;
				}
				else if (m == n1)
				{
					cout << "恭喜你猜对了"<<endl;
					count = 0;
					e[f] += 15;
				}
			}
			if (m!=n1)
			{
				Time = 0;
				e[f] += 0;
				cout << "正确的数字是" << n1 << endl;
			}
			judge_end(Time,f);
			break;
		}
		case 4:
		{
			count = 8;
			int n1 = rand() % 501;
			while (count)
			{
				cout << "请输入你猜的数字" << endl;
				cin >> m;
				if (m > n1)
				{
					--count;
					cout << "你输入的值偏大，请重新输入" << endl;
					cout << "你还有" << count << "次机会" << endl;
				}
				else if (m < n1)
				{
					--count;
					cout << "你输入的值偏小，请重新输入" << endl;
					cout << "你还有" << count << "次机会" << endl;
				}
				else if (m == n1)
				{
					cout << "恭喜你猜对了"<<endl;
					count = 0;
					e[f] += 20;
				}
			}
			if (m!=n1)
			{
				Time = 0;
				e[f] += 0;
				cout << "正确的数字是" << n1 << endl;
			}
			judge_end(Time,f);
			break;
		}
		case 5:{e[f]+= 40; Time = 1; judge_end(Time, f); break; }
	}
}
//double  game1_enable(int n)
//{
//
//	int a=0, b=0;
//	//在这里面实现扫雷游戏的代码
//	if(n<=4)
//	{
//		;
//		//加上判断条件
//	}
//	else if(n==5)
//	{
//		cout << "请输入自定义的长与宽" << endl;
//		cin >> a >> b;
//		//动态数组实现自定义的扫雷
//		//加上判断条件
//	}
//	
//double s[6] = { 0.0,10.0,16.0,20.0,24.0,((a * b) / 22.0 )*2};
//	return s[n];//判断条件满足
//	return s[0];//判断条件不满足
//	
//}
double  game1_enable(int n)
{
	int a = 0, b = 0;
	int hang=0,lie=0,lei=0;
	//在这里面实现扫雷游戏的代码
	if (n <= 4)
	{
		switch (n)
			{
			case 1:
			{
				hang = 5; lie = 5; lei = 5;
				break;
			}
			case 2:
			{
				hang = 8; lie = 8; lei = 8;
				break;
			}
			case 3:
			{
				hang = 15; lie = 15; lei = 15;
				break;
			}
			case 4:
			{
				hang = 27; lie = 27; lei = 27;
				break;
			}
			}
		//加上判断条件
	}
	else if (n == 5)
	{
		cout << "请输入自定义的长与宽(均不大于100并且大于10)" << endl;
		cin >> a >> b;
		if(a>=100||b>=100||a<10||b<10)
		{
			do
		{cout<<"请重新输入"<<endl;cin>>a>>b;}while(a>=100||b>=100 || a < 10 || b < 10);
		
		}
		hang = a;
		lie = b;
		lei = (int)sqrt(hang * lie);
		//动态数组实现自定义的扫雷
		//加上判断条件
	}
	double s[6] = { 0.0,10.0,16.0,20.0,24.0,((a * b) / 22.0) * 2 };//分数的分布
	char** blei = new char* [hang];//blei是后台布置雷区
	for (int i = 0; i < hang; i++)
	{
		blei[i] = new char[lie];
	}
	char** wanjia = new char* [hang];//wanjia是给玩家的显示区
	for (int i = 0; i < hang; i++)
	{
		wanjia[i] = new char[lie];
	}
	int win = hang * lie - lei;//win是一共需要点开的非雷数（胜利条件）
	int flei = 0;//flei是玩家已点开的非雷数
	for (int i = 0; i < hang; i++)
		for (int j = 0; j < lie; j++)
		{
			blei[i][j] = '0';
			wanjia[i][j] = '#';
		}
	srand((unsigned)time(NULL));
	int yblei = 0;//yblei是已经布置的雷数
	while (yblei < lei)
	{
		int x = rand() % hang;
		int y = rand() % lie;
		if (blei[x][y] != '*')//*是雷
		{
			blei[x][y] = '*';
			yblei++;
		}
	}
	for (int i = 0; i < hang; i++)
		for (int j = 0; j < lie; j++)
		{
			if (blei[i][j] == '*')
			{
				continue;
			}
			int qlei = 0;//qlei指周围一圈有的雷数
			int shang = i - 1, xia = i + 1, zuo = j - 1, you = j + 1;//上下左右
			if (shang < 0)
				shang = 0;
			if (xia >= hang)
				xia = hang - 1;
			if (zuo < 0)
				zuo = 0;
			if (you >= lie)
				you = lie - 1;
			for (int m = shang; m <= xia; m++)
				for (int n = zuo; n <= you; n++)
				{
					if (m == i && n == j)

						continue;
					else if (blei[m][n] == '*')
						qlei++;
				}
			blei[i][j] = '0' + qlei;
		}
	while (1)
	{

		cout << "扫雷棋盘" << endl;
		cout << "   ";
		if(n==1||n==2)
		{
			for (int i = 0; i < lie; i++)
			{
				cout << i << "  ";
			}
			cout << endl;
			for (int i = 0; i < hang; i++)
			{
				cout << i << "  ";
				for (int j = 0; j < lie; j++)
					cout << wanjia[i][j] << "  ";
				cout << endl;
			}
			cout << endl;
		}
		else if(n==3||n==4||n==5)
		{
			for(int i=0;i<=9;++i)cout<<i<<"  ";
			for(int i=10;i<lie;++i)cout<<i<<" ";
			cout<<endl;
			for (int i = 0; i <hang; ++i)
			{
				if(i<10)cout<<i<<"  ";
				else cout<<i<<" ";
				for(int j=0;j<=9;++j)cout<<wanjia[i][j]<<"  ";
				for(int j=10;j<lie;++j)cout<<wanjia[i][j]<<"  ";
				cout<<endl;
			}
		}
		int p, q;
		cout << "请输入要点击的坐标（先行后列）" << endl;
		cout << "如果要标记雷的位置，请输入p=-1,q=-1" << endl;
		cin >> p >> q;
		if (p == -1 && q == -1)
		{
			cout << "请输入要标记的坐标" << endl;
			cin >> p >> q;
			if (p < hang && q < lie && p >= 0 && q >= 0)
				wanjia[p][q] = '@';
			else
				cout << "输入坐标不符合规范，请重新输入" << endl;
		}
		else if (p < 0 || q < 0 || p >= hang || q >= lie)
		{
			cout << "输入坐标不符合规范，请重新输入" << endl;
		}
		else if (p < hang && q < lie && p >= 0 && q >= 0)
		{
			if (blei[p][q] == '*')
			{
				cout << "您已踩雷，游戏失败！" << endl;
				for (int i = 0; i < hang; i++)
					for (int j = 0; j < lie; j++)
					{
						if (blei[i][j] == '*')
							wanjia[i][j] = '*';
					}
					cout<<"   ";
				if (n == 1 || n == 2)
				{
					for (int i = 0; i < lie; i++)
					{
						cout << i << "  ";
					}
					cout << endl;
					for (int i = 0; i < hang; i++)
					{
						cout << i << "  ";
						for (int j = 0; j < lie; j++)
							cout << wanjia[i][j] << "  ";
						cout << endl;
					}
					cout << endl;
				}
				else if (n == 3 || n == 4 || n == 5)
				{
					for (int i = 0; i <= 9; ++i)cout << i << "  ";
					for (int i = 10; i < lie; ++i)cout << i << " ";
					cout << endl;
					for (int i = 0; i < hang; ++i)
					{
						if (i < 10)cout << i << "  ";
						else cout << i << " ";
						for (int j = 0; j <= 9; ++j)cout << wanjia[i][j] << "  ";
						for (int j = 10; j < lie; ++j)cout << wanjia[i][j] << "  ";
						cout << endl;
					}
				}
				
				return s[0];
					break;
			}
			else if (wanjia[p][q] != '#')
			{
				cout << "输入坐标重复，请重新输入" << endl;
			}
			else if (blei[p][q] != '*')
			{
				wanjia[p][q] = blei[p][q];
				flei++;
			}
		}

		if (win == flei)
		{ 
			cout << "恭喜您，所有雷已被找出，游戏胜利" << endl;
			return s[n];
			break;
		}
			
	}
	for (int i = 0; i < hang; i++)
	{
		delete[] blei[i];
		delete[] wanjia[i];
	}
	delete[] blei;
	delete[] wanjia;
	blei = NULL;
	wanjia = NULL;
	return 0;
}

void game1(int& Time ,int f)
{
	
	cout<<"欢迎来到扫雷游戏"<<endl;
	cout<<"本游戏难度分为(1)简单,(2)普通,(3)困难,(4)炼狱,(5)自定义 这五种难度"<<endl;
	cout<<"其中对应棋盘大小为5*5 8*8  15*15 27*27 自定义*自定义(小于100大于10）"<<endl;
	cout<<"对应的布雷数为 5 8 15 27 自定义的开根号"<<endl;
	cout<<"但要注意的是本游戏的分数以通关为标准，但时间越少得分越高"<<endl;
	cout<<"通关分数依次为 10 16 20 24 [自定义的面积/11]"<<endl;
	cout<<"时间依次为 50s  70s 150s 250s 350s 可以得到满分"<<endl;
	cout<<"达不到的依次按百分比时间扣分，最多扣除原来分数的一半"<<endl;
	 cout<<"其中#是未扫雷的区域，*是已经扫出来的雷"<<endl;

	cout<<"现在请输入数字选择相应的难度"<<endl;
	int n;next2: cin>>n;
	int T[6]={0,50,70,150,250,350};
	switch (n)
	{
		case 1:
		{
			time_t beg=time(NULL);
			double sco= game1_enable(1);
			time_t end = time(NULL);
			int t = (int)difftime(end, beg);
			cout<<"您总共用时"<<t<<"秒"<<endl;
			if(sco==0){Time=0; judge_end(Time,f);}
			//记录游玩时间
			if(t>T[n])sco=(1-(t-T[n])/T[n])*sco;//利用时间计算得分
			if(sco!=0){Time=1; e[f] += sco; judge_end(Time, f); }
			break;
			
		}
		case 2:
		{
			time_t beg = time(NULL);
			double sco = game1_enable(2);
			time_t end = time(NULL);
			int t = (int)difftime(end, beg);
			cout << "您总共用时" << t << "秒" << endl;
			if (sco==0) { Time = 0; judge_end(Time,f); }
			//记录游玩时间
			if (t > T[n])sco = (1 - (t - T[n]) / T[n]) * sco;//利用时间计算得分
			if (sco) { Time = 1; e[f] += sco; judge_end(Time, f); }
			break;
		}
		case 3:
		{
			time_t beg = time(NULL);
			double sco = game1_enable(3);
			time_t end = time(NULL);
			int t = (int)difftime(end, beg);
			cout << "您总共用时" << t << "秒" << endl;
			if (sco==0) { Time = 0; judge_end(Time,f); }
			//记录游玩时间
			if (t > T[n])sco = (1 - (t - T[n]) / T[n]) * sco;//利用时间计算得分
			if (sco) { Time = 1;e[f] += sco; judge_end(Time, f); }
			break;
		}
		case 4:
		{
			time_t beg = time(NULL);
			double sco = game1_enable(4);
			time_t end = time(NULL);
			int t = (int)difftime(end, beg);
			cout << "您总共用时" << t << "秒" << endl;
			if (sco==0) { Time = 0; judge_end(Time,f); }
			//记录游玩时间
			if (t > T[n])sco = (1 - (t - T[n]) / T[n]) * sco;//利用时间计算得分
			if (sco) { Time = 1; e[f] += sco; judge_end(Time, f); }
			break;
		}
		case 5:
		{
			time_t beg = time(NULL);
			double sco = game1_enable(5);
			time_t end = time(NULL);
			int t = (int)difftime(end, beg);
			cout << "您总共用时" << t << "秒" << endl;
			if (sco==0) { Time = 0; judge_end(Time,f); }
			//记录游玩时间
			if (t > T[n])sco = (1 - (t - T[n]) / T[n]) * sco;//利用时间计算得分
			if (sco) { Time = 1; e[f] += sco; judge_end(Time, f); }
			break;
		}
		default :{
			cout<<"输入错误，请重新输入"<<endl;
			goto next2;
			break;
		}
	}
}
//游戏2的实现

void game2(int& Time,int f)//重生
{
	
	cout << "************************************************************************************************************************" << endl;
	cout << "************************************************************************************************************************" << endl;
	cout<<"你睁开了昏昏欲睡的双眼，脑袋空空，一无所知"<<endl;
	cout<<"今天是什么日子？今天是什么日子？高考后的第一天啊！！！！"<<endl;
	cout<<"昨天，哦，是今天凌晨你睡得太晚了，大脑宕机片刻后，你突然想起来了某件重要的事情"<<endl;
	cout << "是什么呢？" << endl;
	cout << "<1>你的王者荣耀还没有上王者 ！！"<<endl;
	cout<<"<2>今天拍毕业照，还不赶紧去啊哇！！" << endl;
	cout<<"<3>父母还没有给你买新手机和电脑！！" << endl;
	cout<<"接下来每当出现选项时，输入对应的数字即可进行接下来的剧情，请按照本心游玩，但不要输入其他错误数字，否则后果自负"<<endl;
	int choice[100];
	cin>>choice[0];
	UINT originalOutputCP = GetConsoleOutputCP();
	// 保存原始输入编码页
	UINT originalInputCP = GetConsoleCP();
	SetConsoleOutputCP(65001);  // 65001 = UTF-8 代码页
	SetConsoleCP(65001);
	system("chcp 65001 > nul"); // 静默切换，避免多余输出
	string g1[100],g2[100],g3[100];
	ifstream out1("new_life1.txt");
	ifstream out2("new_life2.txt");
	ifstream out3("new_life3.txt");
	for(int i=0;i<100;++i)
	{
		out1>>g1[i];out2>>g2[i];out3>>g3[i];
	}
	if (choice[0] == 1)//游戏线
	{
		for(int i=0;i<8;++i)cout<<g1[i]<<endl;
		cin>>choice[1];//对玩游戏过头忘记的选择
		if (choice[1] == 1)
		{
			cout<<g1[21]<<endl;cout<<g1[22]<<endl;
			for(int i=10;i<21;++i)cout<<g1[i]<<endl;
		}
		else if (choice[1] == 2)
		{
			for(int i=23;i<27;++i)cout<<g1[i]<<endl; for (int i = 10; i < 17; ++i)cout << g1[i] << endl;
			for(int i=27;i<33;++i)cout<<g1[i]<<endl;for(int i=17;i<21;++i)cout<<g1[i]<<endl;
		}
		else if (choice[1] == 3)for(int i=8;i<21;++i)cout<<g1[i]<<endl;

			cin>>choice[2];//出分后的抉择
			if(choice[2]==1){cout<<g1[32]<<endl;cout<<g1[33]<<endl;Time=-1;e[f] += 20; }
			else if(choice[2]==3){cout<<g1[34]<<endl;Time=-1;e[f] += 10; }
			else if(choice[2]==2)goto next4;
		//Time=-1; judge_end(Time, f);
	}
	else if (choice[0] == 2)//正常的路线
	{
		for (int i = 0; i < 17; ++i)
		{
			cout<<g2[i]<<endl;
		}
		cin>>choice[3];//选择拍照的顺序
		if (choice[3] == 1)
		{
			for (int i = 23; i < 42; ++i)
			{
				cout<<g2[i]<<endl;
			}
		}
		else if (choice[3] == 2)
		{
			cout<<g2[34]<<endl;cout<<g2[43]<<endl;
			for(int i=35;i<42;++i)cout<<g2[i]<<endl;
			
		}
		else if (choice[3] == 3)
		{
			for(int i=17;i<23;++i)cout<<g2[i]<<endl;cout<<g2[42]<<endl;
			for(int i=34;i<42;++i)cout<<g2[i]<<endl;
		}
		next5:for (int i = 44; i < 60; ++i)cout << g2[i] << endl;
		cin >> choice[4];
		if (choice[4] == 1)
		{
			for (int i = 60; i < 69; ++i)cout << g2[i] << endl;
			for (int i = 69; i < 90; ++i)cout << g2[i] << endl;
			Time=-1;
			e[f] += 20;
		}
		else if (choice[4] == 2)
		{
		next4:for (int i = 69; i < 90; ++i)cout << g2[i] << endl;
			Time = -1;
			e[f] += 20;
		}
	}
	else if (choice[0] == 3)
	{ 
		for(int i=0;i<13;++i)cout<<g3[i]<<endl;
		goto next5;
	}
	else
	{
		Time = 0; 
	}
	SetConsoleOutputCP(originalOutputCP);  // 还原输出编码
	SetConsoleCP(originalInputCP);        // 还原输入编码
	// 可选：将控制台代码页也还原（与原始编码匹配）
	char cmd[64];
	sprintf_s(cmd, "chcp %d > nul", originalOutputCP);
	system(cmd);
	judge_end(Time, f);
}

