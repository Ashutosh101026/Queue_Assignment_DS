#include<iostream>
using namespace std;

class Queue
{
int *arr;
int front,rear;
int size;

public:
Queue(int n)
{
  arr=new int[n];
size=n;
front=rear=-1;
}
bool IsEmpty()
{
  return front == -1;
}
bool IsFull()
{
  return (rear+1)%size == front;
}
void Enqueue(int x)
{
  if(IsEmpty())
  {
    front=rear=0;
    arr[0]=x;
    return;
  }
  else if(IsFull())
  {
    cout<<"queue is full"<<endl;
    return;
  }
  else
  {
    rear=(rear+1)%size;
    arr[rear]=x;
  }
}
void Dequeue()
{
  if(IsEmpty())
  {
    cout<<"queue underflow"<<endl;
    return;
  }
  else
  {
    if(front==rear)
    {
      front=rear=-1;
    }
    else
    {
    front=(front+1)%size;
  }
}
}
int Front()
{
  if(IsEmpty())
  {
    cout<<"Queue is empty"<<endl;
    return -1;
  }
  else
   return arr[front];
}
};

int main()
{
Queue q(3);
q.Enqueue(5);
q.Enqueue(10);
q.Enqueue(12);
q.Dequeue();
q.Enqueue(13);
q.Dequeue();
q.Dequeue();
cout<<q.Front();

  return 0;
}
