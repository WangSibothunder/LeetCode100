#include <iostream>
using namespace std;
int a=0;
void add(void)
{
    a++;
}

int main()
{
    printf("before:%d\n", a);
    add();
    printf("after:%d\n", a);
}
