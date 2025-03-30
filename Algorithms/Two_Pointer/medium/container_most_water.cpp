// https://leetcode.com/problems/container-with-most-water/description/

// brute force solution
// simply for every combo of i and j
// calculate the area of container
// return the max area

#include<vector>
#include<climits>

using namespace std;

// this will give TLE O(n^2)
int maxAreaBrute(vector<int>& arr) {
    // we can try brute force.
    // compute all water areas

    int max_area = INT_MIN, i=0, j=0, n=arr.size(), calc_area = 0;

    for(i=0; i<n-1; i++) {
        for(j=i+1; j<n; j++) {

            // caclulate the area
            // length is the number of indices gone front
            // breadth is smaller of the two
            calc_area = (j - i) * min(arr[i], arr[j]);
            max_area = max(max_area, calc_area);
        }
    }

    return max_area;
}

// optimized to O(n)

int maxArea(vector<int> &arr) {
    int n = arr.size();
    int max_area = INT_MIN, left=0, right=n-1, calc_area = 0;

    while(left < right) {
            
        calc_area = (right - left) * min(arr[left], arr[right]);
        max_area = max(max_area, calc_area);

        // move pointer based on which side of number if smaller
        // if they are same, move either
        if(arr[left] <= arr[right]) {
            left += 1;
        }

        else {
            right -= 1;
        }

    }

    return max_area;
}


