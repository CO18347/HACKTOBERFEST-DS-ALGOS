#include<iostream>
using namespace std;
template <class T,class X>
T max1(T a, X b)
{
	
	return(a>b)?a:b;

}
int main()
{
	cout<<"max="<<max1(30,40)<<endl;
	cout<<"max="<<max1(3.5,4.5)<<endl;
	cout<<"max="<<max1(30,4.9)<<endl;
	return 0;
}
