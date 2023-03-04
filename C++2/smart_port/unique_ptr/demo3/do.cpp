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
void func1(const AA *a)
{
    cout << "func1" << endl;
}

void func2(AA *a)
{
    cout << "func2" << endl;
    delete a;
}

void func3(const unique_ptr<AA> &a)
{
    cout << "func3" << endl;
}

void func4(unique_ptr<AA> &a)
{
    cout << "func4" << endl;
}


int main()
{
    unique_ptr<AA>a_ptr = make_unique<AA>();
    func1(a_ptr.get());
    //func2(a_ptr.release());
    func3(a_ptr);

}