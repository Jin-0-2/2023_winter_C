//84_1_List �����̳�

/*
* STL���� �����ϴ� List �����̳� : ���߿��Ḯ��Ʈ�� ���ø� Ŭ����ȭ
*/

/*
*           [vector�����̳�      list �����̳�]
*
* ������ :    vec.capacity()          X
* ������ :    vec[0]                  X
*            vec.begin()+1           X
==============================================================
*/
#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

void print_info(list<int>& vec)
{
    cout << "max_size : " << vec.max_size() << endl;    //���ǽ�ũ��
    cout << "size: " << vec.size() << endl;             //�л���

    //---------------------------------------------------------
   /* list<int>::iterator head = vec.begin();
    list<int>::iterator tail = vec.end();
    while( head != tail)
    {
        int value = *head;
        cout << value << " ";
        head++;
    }
    cout << endl;*/

    list<int>::iterator head = vec.begin();
    list<int>::iterator tail = vec.end();
    for (head; head != tail; head++)
    {
        int value = *head;
        cout << value << " ";
    }
    cout << endl;
    cout << "----------------------------------------------" << endl;
}

//push_back[����](0)
void exam1()
{
    list<int> vec;    //�迭, �ִ�ũ��(0), ���尳��(0)
    print_info(vec);

    for (int i = 1; i <= 10; i++)
        vec.push_back(i);   //�����Լ�
    print_info(vec);    //�迭, �ִ�ũ��(1066), ���尳��(1000)
}

void exam2()
{
    list<int> vec;    //�迭, �ִ�ũ��(0), ���尳��(0)
    print_info(vec);

    for (int i = 1; i <= 10; i++)
        vec.push_front(i);  //�迭���� ������
    print_info(vec);    //�迭, �ִ�ũ��(1066), ���尳��(1000)
}

//insert : ������ �ε��� �ȿ��� ��� ����(max : 10, 0~10)
void exam3()
{
    list<int> vec(10);    //��ü������ 10�� ����  max : 10, size : 10
    print_info(vec);

    vec.insert(vec.begin()++, 1);     //���ϴ� ��ġ�� ���� ����(max����, size����)
    print_info(vec);                //max :15   size : 11 
}

//erase[����](0)
void exam4()
{
    list<int> vec;

    for (int i = 1; i <= 10; i++)
        vec.push_back(i);
    print_info(vec);

    list<int>::iterator cur = vec.begin();
    for (int i = 0; i < 3; i++)
        cur++;     //cur = cur->next;

    vec.erase(cur);  //������ �ּ�    
    print_info(vec);
}

//��ü���(��ȸ) - iterator���
void exam6()
{
    list<int> vec;
    for (int i = 1; i <= 10; i++)
        vec.push_back(i);

    list<int>::iterator begin = vec.begin();
    list<int>::iterator end = vec.end();
    for (; begin != end; begin++)
    {
        int value = *begin;
        cout << value << " ";
    }
    cout << endl;
}

//�˻�(�������)
list<int>::iterator exam7_select(list<int>& vec, int value1)
{
    list<int>::iterator begin = vec.begin();
    list<int>::iterator end = vec.end();
    for (; begin != end; begin++)
    {
        int value = *begin;
        if (value == value1)
            return begin;
    }
    return begin;  //end�� ����!
}

void exam7()
{
    list<int> vec;
    for (int i = 1; i <= 10; i++)
        vec.push_back(i);

    list<int>::iterator itr = exam7_select(vec, 51);
    if (itr == vec.end())
        cout << "����" << endl;
    else
        cout << *itr << endl;
}

//�˻�(find() )
void exam8()
{
    list<int> vec;
    for (int i = 1; i <= 10; i++)
        vec.push_back(i);

    list<int>::iterator itr = find(vec.begin(), vec.end(), 51);
    if (itr == vec.end())
        cout << "����" << endl;
    else
    {
        int value = *itr;
        cout << value << endl;
    }
}

//����( 5�� ã�Ƽ� 55�� ����)
void exam9()
{
    list<int> vec;
    for (int i = 1; i <= 10; i++)
        vec.push_back(i);

    print_info(vec);

    list<int>::iterator itr = find(vec.begin(), vec.end(), 5);
    if (itr == vec.end())
        cout << "����" << endl;
    else
    {
        *itr = 55;      //<--------- ����
    }

    print_info(vec);
}

//���ľ˰���
void exam10()
{
    srand((unsigned int)time(NULL));

    list<int> vec;
    for (int i = 1; i <= 20; i++)
    {
        int value = rand() % 100; //0~99
        vec.push_back(value);
    }
    print_info(vec);

    //�����Լ�
    //sort(vec.begin(), vec.end());

    //����Ʈ�����̳� �ɹ� �Լ�
    vec.sort();

    print_info(vec);
}

int main()
{
    exam10();

    return 0;
}