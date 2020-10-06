#include<iostream>
using namespace std;
template <class T>
T max1( T a ,T b )
{
	return (a>b)?a:b;
	
}
int main()
{
	cout<<"the max is="<<max1(20,30);
}
