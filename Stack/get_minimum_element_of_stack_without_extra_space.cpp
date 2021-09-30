#include <iostream>

using namespace std;

int stack[50], minimum, top=-1,x;

void push(int x)
{
    if (top==-1)
    {
        top++;
        stack[top]=x;
        minimum = x;
    }
    else
    {
        if (x<minimum)
        {
            top++;
            stack[top]=2*x-minimum;
            minimum = x;
        }

        else
        {
            top++;
            stack[top]=x;
        }

    }
}

void pop()
{
    if (top ==-1)
        cout << "Stack is Empty\n";
    int d=stack[top];
    top--;
    if (d < minimum)
        {
            cout<<minimum<<" is deleted"<<endl;
            minimum = 2*minimum- d;
        }
    else
        cout<<d<<" is deleted"<<endl;
}

int getmin()
{
    if (top ==-1)
        cout << "Stack is Empty\n";
    cout <<"Minimum Element in the stack is: "<< minimum<< "\n";
    return minimum;
}


int main()
{
    int choice,n;
    cout<<"Enter size of the array: ";
    cin>>n;

    cout<<"1) Push"<<endl;
    cout<<"2) Pop"<<endl;
    cout<<"3) Minimum Element: "<<endl;
    cout<<"4) Exit"<<endl;
    do {
      cout<<"Enter your choice: ";
      cin>>choice;
      switch(choice) {
         case 1: {
            cout<<"Enter the value to be entered in the stack: "<<endl;
            cin>>x;
            push(x);
            break;
         }
         case 2: {
            pop();
            break;
         }
         case 3: {
            int minimum=getmin();
            break;
         }
         case 4: {
            cout<<"Exit"<<endl;
            break;
         }
         default: {
            cout<<"Wrong Choice"<<endl;
         }
      }
   }while(choice!=4);
   return 0;
}
