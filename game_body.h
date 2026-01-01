#pragma once
#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>
#include<fstream>
#include <windows.h>
#include<cmath>
using namespace std;

 struct player
{
	string name;
	double score=7;

};
void menu();//菜单的打印
void print1();//规则的打印
void print2(int&);//问答的打印
void error();//程序的崩溃
void play_choose(int&,int);//选择游戏
void judge_end(int&,int);//判断可游戏次数以及总游戏分数
void list_in(int n,player s[]);//通过文件的形式传递玩家信息
void list( int n);//实时排名及分数存储到函数体文件方便后续使用,并进行排序
void list_out(int);//实时排名及分数的呈现
void game1(int&Time,int);//扫雷
void game3(int&Time,int);//猜数字
void game2(int&Time,int);//重生
void keep(int);//保存最后的排名
