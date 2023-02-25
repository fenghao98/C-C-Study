#include <iostream>
#include <vector>
#include <memory>
using namespace std;

class AA 
{
public:
    string m_name;
    AA(){cout << m_name << "调用构造函数AA()." << endl;};
    AA(const string &name):m_name(name){cout << "调用构造函数AA(" <<m_name<< ").\n";}
    ~AA(){cout << "调用析构函数~AA("<<m_name<<").\n";}
};

int main()
{
    AA* P = new AA("lj");
    unique_ptr<AA>pu1(P);

    unique_ptr<AA>pu2(new AA("hc"));//常用这种方式。

    AA* p2 = new AA("西施");
    // unique_ptr<AA> pu3 = p2;   //错误，不能把普通指针直接赋值给智能指针。
    // unique_ptr<AA> pu4 = new AA("GX");//错误，不能把普通指针直接赋值给智能指针。

    unique_ptr<AA> pu3 = pu2; //错误不能用其它拷贝构造函数。

    unique_ptr<AA>pu4;
    pu4 = pu1;
}