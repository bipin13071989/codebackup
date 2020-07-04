#include<iostream>
#include<string>
using namespace std;
class Stack
{
private:
    int top,n;
    int *arr;
public:
    Stack()
    {
        arr=new int[n];
        top=-1;
        for(int i=0;i<n;i++)
        {
            arr[i]=0;
        }
    }
    bool isEmpty()
    {
        if(top==-1)
            return true;
        else
            return false;
    }
    bool isFull()
    {
        if(top==(n-1))
            return true;
        else
            return false;
    }
    void push(int val)
    {
        if(isFull())
            cout<<"STACK OVERFLOW"<<endl;
        else
            {
                top++;
                arr[top]=val;
            }
    }
    int pop()
    {
        if(isEmpty())
            {
                cout<<"STACK UNDERFLOW"<<endl;

            }
        else
        {
            int temp=arr[top];
            arr[top]=0;
            top--;
            return temp;
        }

    }
    int peek(int post)
    {
        if(isEmpty())
            cout<<"underflow ";
        else
           return arr[post];
    }

    int Count()
    {
        return (top+1);
    }
    void change(int pos,int val)
    {
        arr[pos]=val;
        cout<<"Changed value is: "<<arr[pos]<<"at pos"<<pos<<endl;

    }
    void display(int n)
    {
        cout<<"ALL VALUE AR: "<<endl;
        for(int i=n-1;i>=0;i--)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};
int main()
{
    Stack o;
    int n,opt,val,pos,post;
    cout<<"Enter the size: "<<endl;
    cin>>n;
    do
    {
        cout<<"1. pushing the values in the stack: "<<endl;
        cout<<"2. poping the value from the stack: "<<endl;
        cout<<"3. change the value from any place: "<<endl;
        cout<<"4. Display the values of the stack: "<<endl;
        cout<<"5. stack is empty or not: "<<endl;
        cout<<"6. stack is full or not: "<<endl;
        cout<<"7. counting the elements in the stack: "<<endl;
        cout<<"8. peek the value at any position: "<<endl;
        cout<<"clear screen: "<<endl;
        cin>>opt;
        switch(opt)
        {
        case 1:

                cout<<"enter the value to be fill in the stack:"<<endl;
                cin>>val;
                o.push(val);
                break;

        case 2:

                cout<<o.pop()<<endl;
                break;

        case 3:

                cout<<"enter the pos and value:"<<endl;
                cin>>pos>>val;
                o.change(pos,val);
                break;

        case 4:

                o.display(n);
                break;

        case 5:

                if(o.isEmpty())
                    cout<<o.isEmpty();
                else
                    cout<<"not empty ";
                break;


        case 6:

                if(o.isFull())

                    cout<<o.isFull();


                else
                    cout<<"not fulL ";
                break;

        case 7:
            cout<<o.Count();
            break;

        case 8:

                cout<<"enter the position to find: "<<endl;
               cin>>post;
              cout<<o.peek(post);
                break;

        case 9:

                system("cls");
                break;

        default :
            break;
        }

    }while(opt!=0);

}
