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

void deletefunc(AA* a){
    cout << "自定义删除器（全局函数）。\n" << endl;
    delete a;
}

auto deletelamb = [](AA* a){ //删除器，Lambda表达式
    cout << "自定义删除器lambda。\n";
    delete a;
};

struct deleteclass  
{
    void operator()(AA*a){
        cout << "自定义删除器（仿函数）。\n" << endl;
        delete a;
    }
}; 

int main()
{
    AA* p = new AA("西施");
    shared_ptr<AA>p0(p); //没有指定删除器，使用缺省的删除器，将原始指针delete掉

    shared_ptr<AA>pa1(new AA("西施a"),deletefunc);//删除器普通函数。
    shared_ptr<AA>pa2(new AA("西施b"),deleteclass());//删除器仿函数。
    shared_ptr<AA>pa2(new AA("西施c"),deletelamb);//删除器lambda表达式。

    unique_ptr<AA,decltype(deletefunc)*>pu1(new AA("西施1"),deletefunc);
    unique_ptr<AA,void(*)(AA*)>pu0(new AA("西施1"),deletefunc);

    unique_ptr<AA,decltype(deletefunc)*>pu1(new AA("fjdi"),deletefunc);
    //unique_ptr<AA,void(*)(AA*)>pu5()




    cout << "引用计数："<< p0.use_count()<< endl;

    unique_ptr<AA[]>ptarr(new AA[2]{string("hf"),string("9jf")});
}