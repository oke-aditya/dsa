// There is one meeting room in a firm. There are N meetings in the form of (S[i], F[i])
// where S[i] is start time of meeting i and F[i] is finish time of meeting i.
// What is the maximum number of meetings that can be accommodated in
// the meeting room when only one meeting can be held in the meeting room at a particular time?
// Also note start time of one chosen meeting can't be equal to the end time of the other chosen meeting.

// N = 6
// S[] = {1,3,0,5,8,5}
// F[] = {2,4,6,7,9,9}

// Output: 
// 4
// Explanation:
// Four meetings can be held with
// given start and end timings.

// N = 8
// S[] = {75250, 50074, 43659, 8931, 11273,
// 27545, 50879, 77924}
// F[] = {112960, 114515, 81825, 93424, 54316,
// 35533, 73383, 160252}

// Output: 
// 3
// Explanation:
// Only three meetings can be held
// with given start and end timings.

#include<bits/stdc++.h>

using namespace std;

int select_meetings(vector<int> start_times, vector<int> finish_times)
{
    return 0;

}

int main(int argc, char const *argv[])
{
    vector <int> start_times = {1, 3, 0, 5, 8, 5};
    vector <int> finish_times = {2, 4, 6, 7, 9, 9};
    
    auto res = select_meetings(start_times, finish_times);
    cout<<res<<endl;

    return 0;
}

