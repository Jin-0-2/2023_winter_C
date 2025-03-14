// app.cpp
#include "std.h"

void app::init()
{
	wbprint::logo();
}

void app::run()
{
	while (true)
	{
		system("cls");
		con.printall();
		wbprint::menuprint();
		char ch = _getch();	//문자 입력(출력X, 즉각반응)
		switch (ch)
		{
		case '1':	con.insert();		  break;
		case '2':	con.select();		  break;
		case '3':	con.update1();		  break;
		case '4':	con.update2();		  break;
		case '5':	con.remove();		  break;
		case '6':   return;
		}
		system("pause");
	}
}

void app::exit()
{
	wbprint::ending();
}
