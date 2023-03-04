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

unique_ptr<AA>func(){
    unique_ptr<AA>pp(new AA("西施3"));
    return pp;
}
//函数func1需要一个指针，但不对这个指针负责。
void func1(const AA* a){
    cout << a->m_name << endl;
}

//函数func2()需要一个指针，并且会对这个指针负责
void func2(AA *a){
    cout << a->m_name << endl;
    delete a;
}

//函数func3()需要一个unique_ptr，不会对这个unique_ptr负责
void func3(const unique_ptr<AA> &a){
    cout << a->m_name << endl;
}

//func4()需要一个unique_ptr,并且会对这个unique_ptr负责
void func4(unique_ptr<AA>p){
    cout << p->m_name << endl;
}

unique_ptr<AA>p100(new AA("全局"));

int main()
{
//     AA* P = new AA("lj");
//     unique_ptr<AA>pu1(P);

//     unique_ptr<AA>pu2(new AA("hc"));//常用这种方式。

//     AA* p2 = new AA("西施");
//     // unique_ptr<AA> pu3 = p2;   //错误，不能把普通指针直接赋值给智能指针。
//     // unique_ptr<AA> pu4 = new AA("GX");//错误，不能把普通指针直接赋值给智能指针。

//     //unique_ptr<AA> pu3 = pu2; //错误不能用其它拷贝构造函数。

//     unique_ptr<AA>pu4;
//    // pu4 = pu1;


//     unique_ptr<AA> aa = make_unique<AA>("fh");
//     //智能指针是对原始指针的封装，其优点是会自动分配内存，不用担心潜在的内存泄漏。
//     /**
//      * 某一时刻只能由一个unique_ptr指向一个动态分配的资源对象，它所管理的资源只能在
//      * unique_ptr之间移动，不能拷贝，一旦这个unique_ptr对象被销毁或者变成空对象，或者
//      * 拥有另一个资源对象，它所管理的资源对象同时一并销毁。资源对象要么随同unique_ptr对象一起销毁，要么在离开unique_ptr
//      * 对象一起销毁。
//      * 
//      */

//     int *p = new int[100];
//     delete []p;



    //技巧
    /**
     * 1，将一个unique_ptr赋值给另一个时，如果源unique_ptr是一个临时的右值，编译器允许这样做；如果
     * 源unique_ptr将存在一段时间，编译器禁止这样做。一般用于函数的返回值。
     * 
     */

    unique_ptr<AA>pu1(new AA("西施1"));
    unique_ptr<AA>pu2;
    //pu2=pu1;//错误
    pu2 = unique_ptr<AA>(new AA("西施2"));//用匿名对象赋值
    pu2.swap(pu1);//交换两个unique_ptr的控制权。
    cout << "调用func()之前"<<endl;
    pu2 = func();//用函数返回值赋值。
    cout << "调用func()之后"<<endl;

    /**
     * 2.用nullptr给unique_ptr赋值将释放对象，空的unique_ptr == nullptr.
     * 
     */

    unique_ptr<AA>pu3(new AA("fddf"));
    cout <<"赋值前"<< endl;
    if (pu3 != nullptr) cout << "pu3不是空"<<endl;
    pu3 = nullptr;
    if (pu3 ==nullptr) cout << "pu3是空"<< endl;


    /**
     * 3.release()释放对原始指针的控制权。将unique_ptr置为空，返回裸指针。（可用于把unique_ptr传递给子函数
     * ，子函数将负责释放对象）
     * 4.std::move()可以转移对原始指针的控制权。（可用于把unique_ptr传递给子函数，子函数形参也是unique_ptr）
     * 
     * 
     * 
     */

    unique_ptr<AA>pu5(new AA("fhfh"));
    //func1(pu5.get()); //调用func1()需要一个指针，但不对这个指针负责。

    /**
     *  调用unique_ptr的release()方法，把原始指针交给func2函数，失去了对
     * 原始指针的控制权之后它自己就成了空指针
     * 
     */
    // func2(pu5.release());//调用func1()需要一个指针，并且会对这个指针负责。
    // if (pu5 == nullptr) cout << "pu5是空"<<endl;


    // func3(pu5);


    // func4(std::move(pu5));

    //pu5.swap(pu3);

    pu5.release();

    //pu5->m_name = "fhddd";

    

    unique_ptr<AA[]>ptr2(new AA[2]);
    unique_ptr<AA[]>ptr3(new AA[2]{string("fhfh"),string("fjweifw")});
    ptr2[0].m_name = "jian";












    unique_ptr<AA>ptr5(new AA("fhh"));
    unique_ptr<AA>ptr6;
    ptr6 = unique_ptr<AA>(new AA("koko"));
    //ptr6.reset(new AA("fhfh"));
    ptr6.release();//释放对原始指针的控制权并返回原始指针




    cout << "-----------------------------" <<endl;

    int* jjdf =new int(198); 
    unique_ptr<int>pt78(jjdf);
    
    cout << jjdf << endl;
    

    
}