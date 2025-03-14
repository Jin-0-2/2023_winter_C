//28_싱글톤패턴.cpp
/*
* GOF의 디자인 패턴(어떤 기능/성질을 갖는 클래스를 만들고 싶다?)
*  싱글톤 패턴 : 하나의 객체만 생성이 되는 클래스를 설계.
*               - 생성자가 public으로 공개되어 있다 -> 외부에서 자유롭게 객체 생성이 가능!
*                  => 생성자를 private 설정       --> (X)
*                  => 객체를 클래스 내부에서 만들어 외부에 공개!(static)
*/

#include <iostream>
using namespace std;

class Singleton
{
private:
    Singleton() {}
    static Singleton* inst;  //유일하게 생성된 객체 저장!

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
    //Singleton s1; //외부 객체 생성 불가!

    Singleton *p = Singleton::getInstance();
    p->showMessage();

    Singleton* p1 = Singleton::getInstance();
    p1->showMessage();

    return 0;
}

