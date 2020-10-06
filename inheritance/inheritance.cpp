#include<iostream>
using namespace std;
	class student
	{
		public:
			void display()
			{
				cout<<"student class"<<endl;
			}
		
	};
	class marks: public student
	{
		public:
		     void display1()
		{
			cout<<"marks class";
		}
	};
	int main()
	{
		marks obj;
		obj.display();
		obj.display1();
		
	}
