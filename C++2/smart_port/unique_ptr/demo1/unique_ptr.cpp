#include <iostream>
#include <memory>
#include "cat .h"
using namespace std;

int main1s(int argc,char *argv[])
{
    //Cat c1("ok");
    // c1.cat_info();
    // {
    //     Cat c2("11");
    //     c1.cat_info();
    // }

    //row porinter 原始指针,
    //下面得调用delete手动的去调用析构函数
    // Cat *c_p1 = new Cat("yy");
    // c_p1->cat_info();
    // {
    //     Cat *c_p1 = new Cat("yy_scope");
    //     c_p1->cat_info();
    //     delete c_p1;
    // }
    // delete c_p1;


//unique_pointer 创建的三种方式
    //方式一
    Cat *c_p2 = new Cat("yz");
    std::unique_ptr<Cat> u_c_p2{c_p2};//这个时候c_p2还是可以用的
    //这种情况建议销毁c_p2,否则就会出现如下情况
    // c_p2->cat_info() ;//c_p2还是可以使用的
    // u_c_p2->cat_info();

    // c_p2->set_cat_name("ok");
    // u_c_p2->cat_info();//也会被改变。
    //     u_c_p2->cat_info();
    //    // delete c_p2;
    //     cout << "exit" << endl;
    //     c_p2 = nullptr;
    //     cout << "exit2" << endl;
    //     u_c_p2->cat_info();

    //第二种方式new
    std::unique_ptr<Cat> u_c_p3{new Cat("dd")};
    
    u_c_p3->cat_info();

    std::unique_ptr<int> u_i_p3{new int(100)};
    cout << "int address:" << u_i_p3.get() << endl; //打印地址
    cout << *u_i_p3<< endl;//解引用




    //第三种创建方式（推荐）：std::make_unique
    std::unique_ptr<Cat> u_c_p4 = make_unique<Cat>("cc");

    std::unique_ptr<int> u_i_p4 = make_unique<int>(200);
    cout << "int address:" << u_i_p4.get() << endl; //打印地址
    cout << *u_i_p4<< endl;//解引用

    cout << "feng.hao" << endl;

    return 0;

    std::unique_ptr<Cat> u_c_p5 {new Cat("dd")};

    std::unique_ptr<Cat>u_c_p6{new Cat("fh")};

    std::unique_ptr<Cat> u_c_p7 = make_unique<Cat>("jj");


    //unique_ptr 是不可以被copy的，只可以Move
    //在做函数参数或是返回值中一定要注意所有权

    /**
     * Passing by value 传值
     * 需要用std::move来转移内存拥有权
     * 如果参数直接传入std::make_unique语句 自动转换未move
     * 
     */

    /**
     * Pashing by value
     * 传引用
     * 如果设置参数未const则不能改变指向
     * 比方说reset()
     * reset()方法未智能指针清空方法
     * 
     */

    /**
     * return by value
     * 指向一个local object
     * 可以用链式函数
     * 
     */
}