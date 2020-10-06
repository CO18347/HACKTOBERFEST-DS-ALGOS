#include <iostream>
using namespace std;
template <class T>
class mypair{T a, b;
  public:
    mypair (T first, T second)
      {a=first; b=second;}
    T getmax ();
    T getadd ();
};

template <class T>
T mypair<T>::getmax ()
{
  return (a>b)? a : b;
}
template <class T>
T mypair<T>::getadd ()
{
  return a+b;
}
int main () {
  mypair <int>object(100, 75);
  mypair <float>ob (10.0, 7.5);
  cout << object.getmax()<<endl;
  cout << object.getadd()<<endl;
  cout << ob.getmax();
  return 0;
}
