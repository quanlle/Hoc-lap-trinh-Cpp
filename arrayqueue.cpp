#include<iostream>
using namespace std;
int a[10];
int s = sizeof(a)/sizeof(int);
int fron = -1;
int rear = -1;
bool isEmpty()
{
    if(fron == -1 && rear == -1)
        return true;
    else
        return false;
}
void enqueue(int x)
{
    if((rear+1)%s == fron)
        return;
    else if (isEmpty())
        fron = rear = 0;
    else
        rear = (rear+1)%s;
    a[rear] = x;
}
void dequeue()
{
    if(isEmpty())
        return;
    else if(fron == rear) //chi co 1 phan tu
        fron = rear = -1;
    else
    {
        fron = (fron+1)%s;
    }
}
void print()
{
    if(isEmpty())
        return;
    else
    {
        int i = fron;
        while(i!=rear)
        {
            cout << a[i] << " ";
            i = (i+1)%s;
        }
        cout << a[rear];
    }
}
int main()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    enqueue(6);
    enqueue(7);
    enqueue(8);
    enqueue(9);
    enqueue(10);
    dequeue();
    print();
}
