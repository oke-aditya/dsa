// https://cses.fi/problemset/task/1623

#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin>>n;

    vector<int> v(n);

    for(int i=0; i<n; i++) {
        cin>>v[i];
    }

    int group1 = 0, group2 = 0;

    // sort(begin(v), end(v), greater<int>());

    // for(int i=0; i<n; i++) {
    //     if(group1 < group2) {
    //         group1 += v[i];
    //     }
    //     else {
    //         group2 += v[i];
    //     }
    // }

    // cout<< abs(group1 - group2) << endl;
    // return 0;

}
