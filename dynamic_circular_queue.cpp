#include<iostream>
using namespace std;
class CircularQueue
{
private:
    int *arr;
    int fro,rear;
    int countNum,n;
public:
    CircularQueue()
    {
        arr=new int[n];
        countNum=0;
        fro=-1;
        rear=-1;
        for(int i=0;i<5;i++)
        {
            arr[i]=0;
        }
    }
    bool isEmpty()
    {
        if(fro==-1 && rear==-1)
            return true;
        else
            return false;
    }
    bool isFull(int n)
    {
        if((rear+1)%n==fro)
            return true;
        else
            return false;
    }
    void enqueue(int val,int n)
    {
        if(isFull(n))
        {
            cout<<"queue is full"<<endl;
            return ;
        }

        else if(isEmpty())
        {
            fro=rear=0;
            arr[rear]=val;
            countNum++;
        }
        else
        {
            rear=(rear+1)%n;
            countNum++;
            arr[rear]=val;

        }
    }
    int dequeue(int n)
    {
        int x;
        if(isEmpty())
            return 0;
        else if (fro==rear)
        {
            x=arr[fro];
            arr[fro]=0;
            fro=rear=-1;
            countNum--;

        }
        else
        {
            x=arr[fro];
            arr[fro]=0;
            fro=(fro+1)%n;
            countNum--;
        }
        return x;
    }
    int Count()
    {
        return (countNum);
    }
    int Display(int n)
    {
        for(int i=0;i<n;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;

    }
};
int main()
{
    CircularQueue o;
    int opt,val,n;
    cout<<"enter the dynamic size: "<<endl;
    cin>>n;
    do
    {
    cout<<"1 Enqueue: "<<endl;
    cout<<"2 Dequeue: "<<endl;
    cout<<"3 isEmpty: "<<endl;
    cout<<"4 isFull: "<<endl;
    cout<<"5 count: "<<endl;
    cout<<"6 Display: "<<endl;
    cout<<"7 clear screen: "<<endl;
    cin>>opt;
    switch(opt)
    {

    case 1:
        cout<<"enter the value: "<<endl;
        cin>>val;
        o.enqueue(val,n);
                break;
    case 2:
        cout<<"DEQUEUED NUMBER "<<o.dequeue(n)<<endl;

        break;
    case 3:
        if(o.isEmpty())
            cout<<"empty"<<endl;
        else
            cout<<"filled"<<endl;


        break;
    case 4:
        if(o.isFull(n))
            cout<<"full"<<endl;
        else
            cout<<"not"<<endl;

        break;
    case 5:
        cout<<"number of element is :"<<o.Count()<<endl;
        break;
    case 6:
        o.Display(n);
        break;
    case 7:
        system("cls");
        break;

    default:
        cout<<"enter the proper number"<<endl;
        break;
    }
    }
    while(opt!=0);
}

