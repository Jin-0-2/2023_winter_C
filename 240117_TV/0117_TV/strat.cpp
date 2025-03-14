// start.cpp
#include <iostream>
using namespace std;
#include <conio.h> // _getch()

#include "tv.h"

tv my_tv;

void tv_onoff()
{
	cout << "전원버튼을 클릭합니다." << endl;
	my_tv.onoff();
}

void tv_channel_up()
{	
	my_tv.channel_up();
}

void tv_channel_down()
{
	my_tv.channel_down();
}

void tv_channel_input()
{
	if (my_tv.get_onoff() == false)
	{
		cout << "전원이 OFF입니다. 전원을 ON해주십시오." << endl;
		return;
	}

	int num;

	cout << "채널 입력 : "; cin >> num;

	bool go = my_tv.channel_input(num);
	if (go == true)
		cout << "채널을 이동합니다." << endl;
	else
		cout << "잘못된 채널입니다." << endl;
}

void tv_volume_up()
{
	my_tv.volume_up();
}

void tv_volume_down()
{
	my_tv.volume_down();
}

void run()
{
	while (true)
	{
		system("cls");
		my_tv.print();
		cout << "---------------------------------------------" << endl;
		cout << "[1]onoff     [2]채널up     [3]채널down [4]채널이동" << endl;
		cout << "[5]볼륨up [6]볼륨down [7]프로그램종료" << endl;
		cout << "---------------------------------------------" << endl;

		char sel = _getch();
		switch (sel)
		{
		case '1': tv_onoff();		break;
		case '2': 
		{
				tv_channel_up();	break;
		}
		case '3': tv_channel_down();	break;
		case '4': tv_channel_input();	break;
		case '5': tv_volume_up();	break;
		case '6': tv_volume_down();	break;
		case '7':	return;
		}
		system("pause");
	}
}
int main()
{
	run();

	return 0;
}
