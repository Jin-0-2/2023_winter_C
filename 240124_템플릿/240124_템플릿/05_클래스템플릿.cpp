// 05_클래스템플릿.cpp
/*
클래스템플릿 : 주로 데이터 저장 용도의 클래스에 사용
 -> 클래스명이 변경됨
	 wbarray -> wbarray<T>
-> 반드시 명시적으로 사용

* 템플릿은 설계도이기 때문에 반드시 .h에 있어야 함(선언부, 구현부 모두)
*/
#include <iostream>
using namespace std;

template<typename T>
class wbarray
{
private:
	T *arr;				// 동적배열을 이용 -> T를 저장
	int size;			// 저장 개수 == 저장 위치 
	int max;			 // 저장할 최대 개수 

public:
	wbarray(int _max = 10);
	~wbarray();

public:
	int get_size() const;
	int get_max() const;

public:
	T get_data(int idx);		// 인덱스 전달 > 주소
	T operator[](int idx);
	bool pushback(T value);		// 주소전달 > 저장 > return 성공실패
	bool erase(int idx);				// 인덱스 > 삭제 > return 성공실패
};

template<typename T>
wbarray<T>::wbarray(int _max /*= 10*/)
	: size(0), max(_max)
{
	arr = new T[_max];
}

template<typename T>
wbarray<T>::~wbarray()
{
	delete[] arr;
	arr = NULL;
}

template<typename T>
int wbarray<T>::get_size() const
{
	return size;
}

template<typename T>
int wbarray<T>::get_max() const
{
	return max;
}

template<typename T>
T wbarray<T>::get_data(int idx)
{
	if (idx < 0 || idx >= size)
		return NULL;

	return arr[idx];
}

template<typename T>
T wbarray<T>::operator[](int idx)
{
	if (idx < 0 || idx >= size)
		return NULL;

	return arr[idx];
}

template<typename T>
bool wbarray<T>::pushback(T value)
{
	if (max <= size)
	{
		cout << "Overflow" << endl;
		return false;
	}

	arr[size] = value;
	size++;
	return true;

}

template<typename T>
bool wbarray<T>::erase(int idx)
{
	if (idx < 0 || idx >= size)
		return NULL;

	for (int i = idx; i <= size - 1; i++)
	{
		arr[i] = arr[i + 1];
	}
	size--;
	return true;
}

void exam1()
{
	wbarray<int>arr(5); //int를 5개 저장

	arr.pushback(10);
	arr.pushback(20);
	arr.pushback(30);
	arr.pushback(40);

	for (int i = 0; i < arr.get_size(); i++)
	{
		int value = arr[i];
		cout << value << "\t";
	}
	cout << endl;

	arr.erase(2);

	for (int i = 0; i < arr.get_size(); i++)
	{
		int value = arr[i];
		cout << value << "\t";
	}
	cout << endl;
}

void exam2()
{
	wbarray<string> arr(5); // string를 5개 저장

	arr.pushback("aaa");
	arr.pushback("bbb");
	arr.pushback("ccc");
	arr.pushback("ddd");

	for (int i = 0; i < arr.get_size(); i++)
	{
		string value = arr[i];
		cout << value << "\t";
	}
	cout << endl;

	arr.erase(2);

	for (int i = 0; i < arr.get_size(); i++)
	{
		string value = arr[i];
		cout << value << "\t";
	}
	cout << endl;
}

void exam3()
{
	wbarray<int*> arr(5); //int를 5개 저장

	arr.pushback(new int(10));
	arr.pushback(new int(20));
	arr.pushback(new int(30));
	arr.pushback(new int(40));

	for (int i = 0; i < arr.get_size(); i++)
	{
		int* value = arr[i];
		cout << *value << "\t";
	}
	cout << endl;

	arr.erase(2);

	for (int i = 0; i < arr.get_size(); i++)
	{
		int* value = arr[i];
		cout << *value << "\t";
	}
	cout << endl;
}


int main()
{
	exam3();
}