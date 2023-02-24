#include <stdio.h>
#include <iostream>

namespace NAME_1
{

    namespace NAME_1_1
    {
        int num = 8;
    }

    int num = 10;
    float val;
    void func_1()
    {
        printf("func_1\n");
    }

    void func_2();
}//这里的括号是一个作用域，不用加;  相对应的定义域像struct，就要加;

namespace NAME_1  //此处的命名空间NAME_1和上面的NAME_1其实都属于是同一个命名空间
{
    char ch;
}

namespace N = NAME_1;//给命名空间取别名

void NAME_1::func_2()
{
    printf("func_2\n");
}

int main()
{
    int num = 9;
    printf("num:%d\n",num);
    printf("NAME_1:num:%d\n",NAME_1::num);
    printf("NAME_1::NAME_1_1::num:%d\n",NAME_1::NAME_1_1::num);
}