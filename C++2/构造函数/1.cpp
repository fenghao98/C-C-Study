#include <iostream>

using namespace std;

class Line
{
public:
    void setLength(double len);
    double getLength(void);
    Line();
    Line(double len);
private:
    double lenth;
};

//成员函数定义
Line::Line(void)
{
    cout << "Object is being created" << endl;
}

// Line::Line(double len)
// {
//     cout << "Object is being created Lenth" << endl;
// }

Line::Line(double len):lenth(len)
{
    cout << "Object is being created Lenth" << endl;
}

void Line::setLength(double len)
{
    this->lenth = len;    
}

double Line::getLength(void)
{
    return lenth;
}

//程序的主函数
int main()
{
    Line line;

    line.setLength(6.0);
    cout << "Length of line" << line.getLength() << endl;

    //const int a; 常量必须初始化
    const int a = 100;
   // a = 1; //常量不能重新被赋值

    int b =22;
   //const 在*左边，表示*p为常量，定义了一个指针变量p，
   //指针变量p所指向的内容是一个常量，经由*p不能更改指针所指向的内容
   const int *p;

   p = &a; //因为a是一个常量，正确
   p = &b; //&b是一个地址是一个常量。
  // *p = 300; 错误，常量不能重新被赋值。


     //表示的是const修饰的是p2变量本身，
    //表示p2是一个常量，必须初始化常量对象
    int * const p2 = &b;//const出现在*号的右边
    int c = 100;
    //p2 = &c; //p2不能重新指向，不能改变
    *p2 = 500;

    const int *p3;
    p3 = &a;

    int * const p4 = &b;
    //p4 = &a;//错误，
    *p4 = 500;

    return 0;
}

//https://blog.csdn.net/acktomas/article/details/115550704