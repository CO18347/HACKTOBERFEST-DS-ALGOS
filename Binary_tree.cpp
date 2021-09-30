#include<bits/stdc++.h>
using namespace std;
void fun(void*p);
int i;
void main()
{
void *vptr;
vptr=&i;
fun(vptr);
}
int fun(void*p)
{
int **q;
q=(int**)&p;
printf("%d",**q);
return 0;
}