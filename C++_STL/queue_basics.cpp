#include <iostream> 
#include <queue> 
  
using namespace std;

// Queues, stacks and priority Queues do not have iterators.
void print_q(queue <int> q1)
{
    while (!q1.empty())
    {
        cout<<" "<<q1.front();
        q1.pop();
    }
    cout<<endl;
}

int main(int argc, char const *argv[])
{
    queue <int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);

    print_q(q);

    cout<<"Size of queue "<<q.size()<<endl;
    cout<<"Front of queue "<<q.front()<<endl;
    cout<<"Back of queue "<<q.back()<<endl;


    return 0;
}

