//智能指针与函数调用

  //unique_ptr 是不可以被copy的，只可以Move
    //在做函数参数或是返回值中一定要注意所有权

/**
 * Passing by value 传值
 * 需要用std::move来转移内存拥有权
 * 如果参数直接传入std::make_unique语句 自动转换未move
 * 
 */

/**
 * Pashing by refrence
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

#include <iostream>
#include <memory>
#include "cat .h"
using namespace std;

void do_with_cat_pass_value(std::unique_ptr<Cat>c)
{
    c->cat_info();
}

void do_with_cat_pass_ref(std::unique_ptr<Cat> &c)
{
    c->set_cat_name("oo");
    c->cat_info();
    //c.reset();
}


//尽量用下面这种形式
void do_with_cat_pass_const_ref(const std::unique_ptr<Cat> &c)
{
    c->set_cat_name("oo");
    c->cat_info();
    //c.reset();
}

std::unique_ptr<Cat> get_unique_ptr()
{
    std::unique_ptr<Cat> p_dog = std::make_unique<Cat>("dog");
    return p_dog;
}


int main(int arg,char *argv[])
{
    //pass value
    std::unique_ptr<Cat>c32 = make_unique<Cat>("ff");
    c32->cat_info();//这里会正常打印
    do_with_cat_pass_value(std::move(c32)); //不加move是不行的。而且运行结束之后也就析构了
   // c32->cat_info();  //这里就崩溃了
    cout << "--------FH-------" << endl;
   do_with_cat_pass_value(make_unique<Cat>());//打印完了也就析构了。
    

    //pass ref
    //不加const
    std::unique_ptr<Cat>c2 = make_unique<Cat>("2");
    do_with_cat_pass_ref(c2);
    //c2->cat_info();  //因为上面的函数会有一个清空。所以这一步会core dumped
    cout << c2.get() <<endl;

    //加了const
    std::unique_ptr<Cat>c3 = make_unique<Cat>("2");
    do_with_cat_pass_const_ref(c3);
    c3->cat_info();
    cout << c3.get() <<endl;




    get_unique_ptr()->cat_info();

    cout << "--------yz-------" << endl;

    
}