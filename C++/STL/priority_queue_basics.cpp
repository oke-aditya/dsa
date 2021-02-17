#include<iostream>
#include<queue>

using namespace std;

void printpq(priority_queue <int> pq)
{
    while(!pq.empty())
    {
        cout<<pq.top()<<" ";
        pq.pop();
    }
    cout<<endl;
}

int main(int argc, char const *argv[])
{
    priority_queue <int> p1;
    p1.push(10);
    p1.push(20);
    p1.push(5);
    p1.push(2);
    p1.push(1);

    cout<<"Priority queue: ";
    printpq(p1);

    cout<<endl<<"p1.size() : " << p1.size(); 
    cout<<endl<<"p1.top() : " << p1.top(); 

    return 0;
}

