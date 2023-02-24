#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;


class test
{
public:
    int _data;
    int *p;
    test()
    {
        p = new int[10];
        cout << "test()"<< endl;
    }

    ~test()
    {
        delete []p;
        cout << "~test()" << endl;
    }
};

int main()
{
   
  char str[] = "HelloWord";
  char ch = 'W';
  printf("strchr(): %d\n",strchr(str,ch));
  printf("strchr(): %d\n",strchr(str,ch)-str);
    printf("strchr(): %d\n",strchr(str,ch)-str+1);
    


}