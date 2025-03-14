// control.cpp
#include "std.h"
control::control()
{
	wbfile::load(&array);
}

control::~control()
{
	wbfile::save(&array);
}

void control::printall()
{
	printf("[max : %d] \t [size : %d]\n", array.get_max(), array.get_size());
	for (int i = 0; i < array.get_size(); i++)
	{
		drink* drink = array.get_drink(i);
		printf("[%2d] ", i);
		drink->print();
	}
	printf("\n");
}

void control::insert()
{
	printf("[제품명 저장]\n");

	string title = wblib::input_string("제품명");
	int price   = wblib::input_integer("가  격");
	int count   = wblib::input_integer("수  량");
	
	drink* pdrink = new drink(title, price, count);

	if (array.pushback(pdrink) == true)
		printf("저장되었습니다\n");
	else
		printf("저장 실패\n");
}

void control::select()
{
	cout << "[제품명 검색]" << endl;

	string title = wblib::input_string("제품명");

	drink* pdrink = name_to_drink(title);

	if (pdrink != NULL)		
		pdrink->println();
	else					
		printf("없는 제품 입니다\n");
}

void control::update()
{
	printf("[제품정보 변경]\n");

	string title = wblib::input_string("제품명");
	int price    = wblib::input_integer("가  격");

	drink* pdrink = name_to_drink(title);
	if (pdrink != NULL)
	{
		pdrink->set_price(price);
		printf("변경되었습니다\n");
	}
	else
		printf("없는 제품 입니다\n");
}

void control::remove()
{
	printf("[제품정보 삭제]\n");

	string title = wblib::input_string("제품명");

	int idx = name_to_idx(title);
	if (idx != -1)
	{
		array.erase(idx);
		printf("삭제되었습니다\n");
	}
	else
		printf("없는 제품 입니다\n");

}

int  control::name_to_idx(string title)
{
	for (int i = 0; i < array.get_size(); i++)
	{
		drink* drink = array.get_drink(i);
		if (drink->get_title() == title)
		{
			return i;
		}
	}
	return -1;
}

drink* control::name_to_drink(string title)
{
	for (int i = 0; i < array.get_size(); i++)
	{
		drink* drink = array.get_drink(i);
		if (drink->get_title() == title)
		{
			return drink;
		}
	}
	return NULL;
}