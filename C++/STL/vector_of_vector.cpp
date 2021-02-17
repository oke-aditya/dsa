#include<iostream>
#include<vector>

using namespace std;

void print_vec(vector<vector<int>> v)
{
    for(int i=0;i<v.size();i++)
    {
        for(int j=0;j<v[i].size();j++)
        {
            cout<<v[i][j]<<" ";
        }
    cout<<endl;
    }
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> v1 = {{1, 2, 3}, {4, 5, 6}};
    cout<<"Number of rows: "<<v1.size()<<endl;
    cout<<"Number of columns: "<<v1[0].size()<<endl;

    print_vec(v1);
    
    cout<<endl;
    vector<int> v2 = {1, 1, 1};
    v1.push_back(v2);
    print_vec(v1);
    
    // Remove a complete row from matrix
    v1[0].pop_back();
    
    cout<<endl;
    print_vec(v1);

    cout<<endl;
    return 0;
}

