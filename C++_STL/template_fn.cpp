#include<bits/stdc++.h>

using namespace std;

template <typename T>
T area_rect(T a, T b)
{
    T result = a * b;
    return result;
}


int main(int argc, char const *argv[])
{
    int a1 = area_rect<int>(10, 5);
    int a2 = area_rect<float>(10.5, 2);
    cout<<a1<<endl;
    cout<<a2<<endl;
    return 0;
}
