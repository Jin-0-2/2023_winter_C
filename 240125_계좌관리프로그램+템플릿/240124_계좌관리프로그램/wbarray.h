// wbarray.h
#pragma once

template<typename T>		// Acount* -> T
class wbarray
{
private:
	T*  base;	// 동적배열을 이용 -> T 저장
	int size;	// 저장 개수 == 저장 위치 
	int max;	// 저장할 최대 개수 

public:
	wbarray(int _max = 10);
	~wbarray();

public:
	int get_size() const;
	int get_max() const;

public:
	T get_data(int idx);		// 인덱스 전달 > 주소
	T operator[](int idx);
	bool pushback(T drink);		// 주소전달 > 저장 > return 성공실패
	bool erase(int idx);				// 인덱스 > 삭제 > return 성공실패
};

template<typename T>
wbarray<T>::wbarray(int _max /*= 10*/)
	: size(0), max(_max)
{
	base = new T[_max];
}

template<typename T>
wbarray<T>::~wbarray()
{
	delete[] base;
	base = NULL;
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

	return base[idx];
}

template<typename T>
T wbarray<T>::operator[](int idx)
{
	if (idx < 0 || idx >= size)
		return NULL;

	return base[idx];
}

template<typename T>
bool wbarray<T>::pushback(T data)
{
	if (max <= size)
	{
		cout << "Overflow" << endl;
		return false;
	}

	base[size] = data;
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
		base[i] = base[i + 1];
	}
	size--;
	return true;
}