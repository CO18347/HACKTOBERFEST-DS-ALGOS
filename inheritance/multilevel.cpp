#include <iostream>
using namespace std;
class A {
public:
  A1(){
     cout<<"Constructor of A class"<<endl;
  }
};
class B: public A {
public:
  B1(){
     cout<<"Constructor of B class"<<endl;
  }
};
class C: public B {
public:
  C1(){
     cout<<"Constructor of C class"<<endl;
  }
};
int main() {
  //Creating object of class C
  C obj;
  obj.C1();
  obj.B1();
  obj.A1();
  
  return 0;
}
