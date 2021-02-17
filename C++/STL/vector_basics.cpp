#include<bits/stdc++.h>

using namespace std;

void print_vec(vector <int> vec)
{
    for(auto x : vec)
    {
        cout<<x<<" ";
    }
    cout<<endl;
}

int main(int argc, char const *argv[])
{
    int arr[] = {10, 20, 2, 3, -10, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    vector <int> vec(arr, arr+n);
    print_vec(vec);

    sort(vec.begin(), vec.end());

    print_vec(vec);

    int max = *max_element(vec.begin(), vec.end());
    int min = *min_element(vec.begin(), vec.end());

    cout<<endl<<"Maximum value: "<<max<<endl;
    cout<<"Minimum value: "<<min<<endl;

    reverse(vec.begin(), vec.end());
    print_vec(vec);

    // Sum till from xth element.
    cout<<endl<<"Summation of vector elements is: "<<endl;
    // Starts summation from 0.
    cout<<accumulate(vec.begin(), vec.end(), 0);

    // Count occurences of x in vector.
    cout<<"Occurence of 20 in vector"<<endl;
    cout<<count(vec.begin(), vec.end(), 20)<<endl;

    // find() returns iterator to address or end if it is not found
    auto itr = find(vec.begin(), vec.end(), -1);
    
    if(itr == vec.end())
    {
        cout<<"Could not find required element"<<endl;
    }
    else
    {
        cout<<itr - vec.begin() << "Found at Counting from zero"<<endl;
    }

    // Erase a value from position in vector.
    vec.erase(vec.begin()+1);

    print_vec(vec);

    // Delete the duplicate occurences of vector.
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    print_vec(vec);

    // Find distance between desired position from first iterator.
    cout<<distance(vec.begin(), min_element(vec.begin(), vec.end()));

    return 0;
}


