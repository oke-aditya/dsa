#include <iostream>
#include <vector>

using namespace std;

void print_vector(vector <int> v1)
{
    for(auto x: v1)
    {
        cout<<x<<" ";
    }
    cout<<endl;
}

vector<int> rotLeft(vector<int> &a, int d) 
{
    vector <int> result;
    for(int i=d; i<a.size(); i++)
    {
        result.push_back(a[i]);
    }
    for(int i=0; i<d; i++)
    {
        result.push_back(a[i]);
    }
    return result;
}

int main(int argc, char const *argv[])
{
    vector <int> v1 = {1, 2, 3, 4, 5};
    int n = 5;
    int d = 4;
    auto result = rotLeft(v1, d);
    print_vector(result);

    return 0;
}

