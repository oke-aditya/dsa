// Given an array A of N positive numbers. 
// The task is to find the position where equilibrium first occurs in the array.
// Equilibrium position in an array is a position such that the sum of elements before it 
// is equal to the sum of elements after it.


#include<iostream>
#include<vector>

using namespace std;

void eq_point(vector <int> v, int n)
{
    int left_sum = 0;
    int right_sum = 0;
    int left_ptr = 0;
    int right_ptr = n-1;
    int fg=0;

    if(n == 1)
    {
        cout<<"1"<<endl;
    }
    else
    {
        while(left_ptr < right_ptr)
        {
            left_sum += v[left_ptr];
            right_sum += v[right_ptr];
            left_ptr += 1;
            right_ptr -= 1;

            if(left_sum == right_sum)
            {
                fg = 1;
                break;
            }
        }
        if(fg == 1)
        {
            cout<<(left_ptr + 1)<<endl;
        }
        else
        {
            cout<<"-1"<<endl;
        }
    }
}

int main(int argc, char const *argv[])
{
    vector <int> v1 = {1};
    int n1 = 1;
    // ans = 1

    vector <int> v2 = {1, 3, 5, 2, 2};
    int n2 = 5;
    // ans = 3

    eq_point(v1, n1);
    eq_point(v2, n2);

    return 0;
}

