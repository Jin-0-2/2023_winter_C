//85_STL(set, map).cpp

#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

/*
* ------------------ 이진탐색트리 구조 (VALUE == KEY)------------------------
* [set] 이진탐색트리 구조(노드 형태의 연관 컨테이너)
*       오름차순 혹은 내림차순 형태의 정렬 구조
*       KEY : 중복값 저장 없다.
* 
* [multiset] 중복저장이 가능하다.
*            전달하는 값과 비교해서 원하는 값을 반환..
* 
* * ------------------ 이진탐색트리 구조 (KEY, VALUE)------------------------
* [map] 균형이진탐색트리(노드 형태의 연관 컨테이너)
*       pair<key, value> : key를 기반으로 검색(uniq)
*       오름차순.
*       패턴1) 노드 기반으로.
*       패턴2) 배열 기반으로( [ ]  지원 )
* 
* [multimap] 중복저장(key)이 가능하다.
*             [] 사용 불가
*/


//set
//[순회]
void exam1_print(const set<int>& data)
{
	cout << "[저장개수] " << data.size() << endl;

	//구간
	set<int>::iterator head = data.begin();
	set<int>::iterator tail = data.end();
	for (head; head != tail; head++)
	{
		int value = *head;
		cout << value << " ";
	}
	cout << endl;
	cout << "----------------------------------------------" << endl;
}

void exam1()
{
	set<int> data;
	
	//[저장]
	for (int i = 1; i <= 10; i++)
	{		
		data.insert(rand());
	}

	exam1_print(data);

	//중복KEY 저장 불가
	data.insert(1);
	exam1_print(data);

	//모든 저장 정보를 제거
	data.clear();
	exam1_print(data);
}

//multiset
void exam2_print(const multiset<int>& data)
{
	cout << "[저장개수] " << data.size() << endl;

	//구간
	set<int>::iterator head = data.begin();
	set<int>::iterator tail = data.end();
	for (head; head != tail; head++)
	{
		int value = *head;
		cout << value << " ";
	}
	cout << endl;
	cout << "----------------------------------------------" << endl;
}

void exam2()
{
	multiset<int> data;

	//[저장]
	for (int i = 1; i <= 10; i++)
	{
		data.insert(rand()%20);
	}
	exam2_print(data);

	//중복KEY 저장 불가
	data.insert(1);
	exam2_print(data);

	//자신과 같거나 다음으로 큰 값.
	multiset<int>::iterator itr = data.lower_bound(5);
	cout << "5을 전달 : " << *itr << endl; 

	//다음으로 큰 값
	itr = data.upper_bound(5);
	cout << "5를 전달 : " << *itr << endl;

	//모든 저장 정보를 제거
	data.clear();
	exam2_print(data);
}

//map
void exam3_print(map<string, int>& data)
{
	cout << "[저장개수] " << data.size() << endl;

	//구간
	map<string,int>::iterator head = data.begin();
	map<string,int>::iterator tail = data.end();
	for (head; head != tail; head++)
	{
		string key = head->first;
		int value = head->second;
		printf("[%s : %d] ", key.c_str(), value);
	}
	cout << endl;
	cout << "----------------------------------------------" << endl;
}

void exam3_1()
{
	map<string, int> mdata;

	//저장
	mdata.insert(make_pair("홍길동", 20));
	mdata.insert(make_pair("이길동", 30));
	mdata.insert(make_pair("고길동", 40));
	mdata.insert(make_pair("고길동", 40));	//동일KEY (X)
	mdata.insert(make_pair("최길동", 40));	//동일value (0)
	exam3_print(mdata);

	//삭제(특정 노드삭제, 구간정보를 이용해 삭제)
	mdata.erase(mdata.begin());  //첫번째 데이터 삭제
	exam3_print(mdata);

	//구간[시작(포함)~끝(포함안됨)
	mdata.erase(mdata.begin(), ++++mdata.begin());
	exam3_print(mdata);

	//전체 삭제
	mdata.clear();
	exam3_print(mdata);
}

void exam3_2()
{
	map<string, int> mdata;

	//저장 & 수정
	//새로운 키 사용 --> 저장
	//기존 키 사용 --> 수정
	mdata["홍길동"] = 20;
	mdata["이길동"] = 30;
	mdata["고길동"] = 40;
	mdata["고길동"] = 50;	//동일KEY (기존 값을 변경(수정))
	mdata["최길동"] = 60;	
	exam3_print(mdata);

	//검색
	int value = mdata["최길동"];
	cout << "최길동 -> " << value << endl; 

	//저장???-------------------------------------------------------------
	value = mdata["최길동1"];
	cout << "최길동1 -> " << value << endl;
	exam3_print(mdata);


	//삭제(특정 노드삭제, 구간정보를 이용해 삭제)
	mdata.erase("최길동");  //키 전달
	exam3_print(mdata);
	

	//전체 삭제
	mdata.clear();
	exam3_print(mdata);
}

//multimap
void exam4_print(multimap<string, int>& data)
{
	cout << "[저장개수] " << data.size() << endl;

	//구간
	map<string, int>::iterator head = data.begin();
	map<string, int>::iterator tail = data.end();
	for (head; head != tail; head++)
	{
		string key = head->first;
		int value = head->second;
		printf("[%s : %d] ", key.c_str(), value);
	}
	cout << endl;
	cout << "----------------------------------------------" << endl;
}

void exam4_1()
{
	multimap<string, int> mdata;

	//저장
	mdata.insert(make_pair("홍길동", 20));
	mdata.insert(make_pair("이길동", 30));
	mdata.insert(make_pair("고길동", 40));
	mdata.insert(make_pair("고길동", 50));		//저장(0)
	mdata.insert(make_pair("최길동", 60));	
	exam4_print(mdata);

	//삭제(특정 노드삭제, 구간정보를 이용해 삭제)
	mdata.erase(mdata.begin());  //첫번째 데이터 삭제
	exam4_print(mdata);

	//구간[시작(포함)~끝(포함안됨)
	mdata.erase(mdata.begin(), ++++mdata.begin());
	exam4_print(mdata);

	//전체 삭제
	mdata.clear();
	exam4_print(mdata);
}

void exam4_2()
{
	multimap<string, int> mdata;

	//저장
	mdata.insert(make_pair("홍길동", 20));
	mdata.insert(make_pair("이길동", 30));
	mdata.insert(make_pair("고길동", 40));
	mdata.insert(make_pair("고길동", 50));		//저장(0)
	mdata.insert(make_pair("최길동", 60));
	exam4_print(mdata);

	//삭제(원하는 키 삭제)
	//첫번째 고길동만 삭제
//	multimap<string, int>::iterator itr = mdata.find("고길동");
//	mdata.erase(itr);
//	exam4_print(mdata);

	//고길동 전체를 삭제(오류)
	/*map<string, int>::iterator head = mdata.begin();
	map<string, int>::iterator tail = mdata.end();
	for (head; head != tail; head++)
	{
		if ("고길동" == head->first)
			mdata.erase(head);		
	}*/
	//개선코드)
	multimap<string, int>::iterator itr = mdata.begin();
	while (itr != mdata.end())
	{
		if ("고길동" == itr->first)
		{
			mdata.erase(itr);
			itr = mdata.begin();
		}
		else
			itr++;
	}
	exam4_print(mdata);
	
}

//iterator(반복자) 무효화
//컨테이너 내 데이터가 변경(삽입/삭제) 반드시 반복자를 다시 얻어야 한다.
void exam5()
{
	vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);

	vector<int>::iterator itr = vec.begin();
	cout << *itr << endl;  // 1

	//변경이 되었다면 itr는 다시 획득
	vec.push_back(4);
	vec.erase(vec.begin());
	vector<int>::iterator itr1 = vec.begin();
	cout << *itr1 << endl;
}

int main()
{
	exam5();

	return 0;
}