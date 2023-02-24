#include <iostream>
#include<stdio.h>
#include<string>
using namespace std;

#pragma pack(4) //可以用于更改编译器预设的对齐数
struct Test
{
    char a;    //1字节
    double b; //8字节
};

#pragma pack()//取消更改
//第一个成员与结构体变量的偏移量为0
int main()
{


    string str;
    str = "123";
    str.length();
    str.clear();
    str.empty();//判断是否为空
    str ==str;

    char ch = str[2];
    ch = str.at(1);






    //第一个成员与结构体变量的偏移量为0
    Test test;
    /*1.下面两个打印相同可以证明 第一个成员与结构体变量的偏移量为0*/
    printf("&test:%x\n",&test);
    printf("&(test.a):%x\n",&(test.a));
    /*2.其他成员要对齐到某个数字（对齐数）的整数倍的地址*/
        //对齐数取编译其预设的一个对齐整数（2、4、8、16）与该成员大小的最小值的最小公倍数。现在我们的设备上8
        //如果改成4  那对齐后大小就是12.
        //结构体的大小为最大对齐数的整数倍。
    cout << sizeof(Test)<<endl; //16字节
}