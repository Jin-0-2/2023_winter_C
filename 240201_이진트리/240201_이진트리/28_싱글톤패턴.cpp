//28_�̱�������.cpp
/*
* GOF�� ������ ����(� ���/������ ���� Ŭ������ ����� �ʹ�?)
*  �̱��� ���� : �ϳ��� ��ü�� ������ �Ǵ� Ŭ������ ����.
*               - �����ڰ� public���� �����Ǿ� �ִ� -> �ܺο��� �����Ӱ� ��ü ������ ����!
*                  => �����ڸ� private ����       --> (X)
*                  => ��ü�� Ŭ���� ���ο��� ����� �ܺο� ����!(static)
*/

#include <iostream>
using namespace std;

class Singleton
{
private:
    Singleton() {}
    static Singleton* inst;  //�����ϰ� ������ ��ü ����!

public:
    static Singleton* getInstance()
    {
        if (inst == NULL)
            inst = new Singleton();
        return inst;
    }
    void showMessage()
    {        
        cout << this << ", Hello" << endl;
    }
};

Singleton* Singleton::inst = NULL;

int main()
{
    //Singleton s1; //�ܺ� ��ü ���� �Ұ�!

    Singleton *p = Singleton::getInstance();
    p->showMessage();

    Singleton* p1 = Singleton::getInstance();
    p1->showMessage();

    return 0;
}

