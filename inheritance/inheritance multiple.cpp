#include<iostream>
using namespace std;
class A 
{
public:
int sum;
public : void getsum()
{
int a,b;
cout<<"enter 2 numbers:"<<endl;
cin>>a>>b;
sum=a+b;
cout<<"sum:"<<sum<<endl;	
}
};
class B
{
	public:
		int product;
	public:	void getproduct()
		{
			int c,d;
			cout<<"enter 2 numbers:";
			cin>>c>>d;
			product =c*d;
			cout<<"product:"<<product<<endl;
		}
	};
	class C:
		public A,public B
		{
			public:void getresult()
			{
				int res;
				res=sum*product;
				cout <<"result:"<<res;
			}
		};
	int main()
		{
			C obj;
			obj.getsum();
			obj.getproduct();
			obj.getresult();
			
		}


