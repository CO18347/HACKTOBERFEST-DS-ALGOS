#include<iostream>
using namespace std;
template<class T>
void MYswap(T&a , T&b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
	
}
int main()
{
int a = 10, b = 20;
	double p = 10.1, q = 20.1;
	MYswap(a, b) ;
	MYswap(p, q);
	cout << a << " " << b << " " << p << " " << q << endl;
 return 0;

}
