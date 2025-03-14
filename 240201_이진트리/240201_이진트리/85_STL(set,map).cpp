//85_STL(set, map).cpp

#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

/*
* ------------------ ����Ž��Ʈ�� ���� (VALUE == KEY)------------------------
* [set] ����Ž��Ʈ�� ����(��� ������ ���� �����̳�)
*       �������� Ȥ�� �������� ������ ���� ����
*       KEY : �ߺ��� ���� ����.
* 
* [multiset] �ߺ������� �����ϴ�.
*            �����ϴ� ���� ���ؼ� ���ϴ� ���� ��ȯ..
* 
* * ------------------ ����Ž��Ʈ�� ���� (KEY, VALUE)------------------------
* [map] ��������Ž��Ʈ��(��� ������ ���� �����̳�)
*       pair<key, value> : key�� ������� �˻�(uniq)
*       ��������.
*       ����1) ��� �������.
*       ����2) �迭 �������( [ ]  ���� )
* 
* [multimap] �ߺ�����(key)�� �����ϴ�.
*             [] ��� �Ұ�
*/


//set
//[��ȸ]
void exam1_print(const set<int>& data)
{
	cout << "[���尳��] " << data.size() << endl;

	//����
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
	
	//[����]
	for (int i = 1; i <= 10; i++)
	{		
		data.insert(rand());
	}

	exam1_print(data);

	//�ߺ�KEY ���� �Ұ�
	data.insert(1);
	exam1_print(data);

	//��� ���� ������ ����
	data.clear();
	exam1_print(data);
}

//multiset
void exam2_print(const multiset<int>& data)
{
	cout << "[���尳��] " << data.size() << endl;

	//����
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

	//[����]
	for (int i = 1; i <= 10; i++)
	{
		data.insert(rand()%20);
	}
	exam2_print(data);

	//�ߺ�KEY ���� �Ұ�
	data.insert(1);
	exam2_print(data);

	//�ڽŰ� ���ų� �������� ū ��.
	multiset<int>::iterator itr = data.lower_bound(5);
	cout << "5�� ���� : " << *itr << endl; 

	//�������� ū ��
	itr = data.upper_bound(5);
	cout << "5�� ���� : " << *itr << endl;

	//��� ���� ������ ����
	data.clear();
	exam2_print(data);
}

//map
void exam3_print(map<string, int>& data)
{
	cout << "[���尳��] " << data.size() << endl;

	//����
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

	//����
	mdata.insert(make_pair("ȫ�浿", 20));
	mdata.insert(make_pair("�̱浿", 30));
	mdata.insert(make_pair("��浿", 40));
	mdata.insert(make_pair("��浿", 40));	//����KEY (X)
	mdata.insert(make_pair("�ֱ浿", 40));	//����value (0)
	exam3_print(mdata);

	//����(Ư�� ������, ���������� �̿��� ����)
	mdata.erase(mdata.begin());  //ù��° ������ ����
	exam3_print(mdata);

	//����[����(����)~��(���Ծȵ�)
	mdata.erase(mdata.begin(), ++++mdata.begin());
	exam3_print(mdata);

	//��ü ����
	mdata.clear();
	exam3_print(mdata);
}

void exam3_2()
{
	map<string, int> mdata;

	//���� & ����
	//���ο� Ű ��� --> ����
	//���� Ű ��� --> ����
	mdata["ȫ�浿"] = 20;
	mdata["�̱浿"] = 30;
	mdata["��浿"] = 40;
	mdata["��浿"] = 50;	//����KEY (���� ���� ����(����))
	mdata["�ֱ浿"] = 60;	
	exam3_print(mdata);

	//�˻�
	int value = mdata["�ֱ浿"];
	cout << "�ֱ浿 -> " << value << endl; 

	//����???-------------------------------------------------------------
	value = mdata["�ֱ浿1"];
	cout << "�ֱ浿1 -> " << value << endl;
	exam3_print(mdata);


	//����(Ư�� ������, ���������� �̿��� ����)
	mdata.erase("�ֱ浿");  //Ű ����
	exam3_print(mdata);
	

	//��ü ����
	mdata.clear();
	exam3_print(mdata);
}

//multimap
void exam4_print(multimap<string, int>& data)
{
	cout << "[���尳��] " << data.size() << endl;

	//����
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

	//����
	mdata.insert(make_pair("ȫ�浿", 20));
	mdata.insert(make_pair("�̱浿", 30));
	mdata.insert(make_pair("��浿", 40));
	mdata.insert(make_pair("��浿", 50));		//����(0)
	mdata.insert(make_pair("�ֱ浿", 60));	
	exam4_print(mdata);

	//����(Ư�� ������, ���������� �̿��� ����)
	mdata.erase(mdata.begin());  //ù��° ������ ����
	exam4_print(mdata);

	//����[����(����)~��(���Ծȵ�)
	mdata.erase(mdata.begin(), ++++mdata.begin());
	exam4_print(mdata);

	//��ü ����
	mdata.clear();
	exam4_print(mdata);
}

void exam4_2()
{
	multimap<string, int> mdata;

	//����
	mdata.insert(make_pair("ȫ�浿", 20));
	mdata.insert(make_pair("�̱浿", 30));
	mdata.insert(make_pair("��浿", 40));
	mdata.insert(make_pair("��浿", 50));		//����(0)
	mdata.insert(make_pair("�ֱ浿", 60));
	exam4_print(mdata);

	//����(���ϴ� Ű ����)
	//ù��° ��浿�� ����
//	multimap<string, int>::iterator itr = mdata.find("��浿");
//	mdata.erase(itr);
//	exam4_print(mdata);

	//��浿 ��ü�� ����(����)
	/*map<string, int>::iterator head = mdata.begin();
	map<string, int>::iterator tail = mdata.end();
	for (head; head != tail; head++)
	{
		if ("��浿" == head->first)
			mdata.erase(head);		
	}*/
	//�����ڵ�)
	multimap<string, int>::iterator itr = mdata.begin();
	while (itr != mdata.end())
	{
		if ("��浿" == itr->first)
		{
			mdata.erase(itr);
			itr = mdata.begin();
		}
		else
			itr++;
	}
	exam4_print(mdata);
	
}

//iterator(�ݺ���) ��ȿȭ
//�����̳� �� �����Ͱ� ����(����/����) �ݵ�� �ݺ��ڸ� �ٽ� ���� �Ѵ�.
void exam5()
{
	vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);

	vector<int>::iterator itr = vec.begin();
	cout << *itr << endl;  // 1

	//������ �Ǿ��ٸ� itr�� �ٽ� ȹ��
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