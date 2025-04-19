// https://leetcode.com/problems/best-team-with-no-conflicts/

// You are the manager of a basketball team. For the upcoming tournament, 
// you want to choose the team with the highest overall score. 
// The score of the team is the sum of scores of all the players in the team.

// However, the basketball team is not allowed to have conflicts. 
// A conflict exists if a younger player has a strictly higher score than an older player. 
// A conflict does not occur between players of the same age.

// Given two lists, scores and ages, where each scores[i] 
// and ages[i] represents the score and age of the ith player, 
// respectively, return the highest overall score of all possible basketball teams.

// Example 1:

// Input: scores = [1,3,5,10,15], ages = [1,2,3,4,5]
// Output: 34
// Explanation: You can choose all the players.

// Example 2:

// Input: scores = [4,5,6,5], ages = [2,1,2,1]
// Output: 16
// Explanation: It is best to choose the last 3 players. Notice that you are allowed to choose multiple people of the same age.

// Example 3:

// Input: scores = [1,2,3,5], ages = [8,9,10,1]
// Output: 6
// Explanation: It is best to choose the first 3 players. 

// Solution: 
// The main idea here is to create sorted pair by age of AGE + Scores
//  [{Age, Score}]
//  [{1, 1}, {2,3}, {3, 5}, {4, 10}, {5, 15}]
//  LIS 35
//  
//  [{1, 5}, {1, 5}, {2, 4}, {2, 6}]
//  LIS 16
//
//  [{1, 5}, {8, 1}, {9, 2}, {10, 3}]
//  LIS          6 
//
//  Now if we take LIS on the scores Consider the condition as >= not strictly >
//  The LIS Will ensure that is the answer.
//  Reason being, it takes care increasing the scores across ages, if scores fall and age is > we don't pick it
//  Note how to initialize the dp array, we want solve it like maximum *Sum* Of Inreasing subsequence
//  The worse we can do in picking maximum sum is the number itself.
//  Then follow the max sum increasing subsequence logic


#include <algorithm>
#include <vector>
using namespace std;

class Solution {
    public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int, int>> v_age_scores;
        int n = scores.size();
        vector<int> dp(n, 1);

        for(int i=0; i<n; i++) {
            v_age_scores.push_back({ages[i], scores[i]});
        }
        sort(v_age_scores.begin(), v_age_scores.end());

        // the worst we can do is pick the member itself
        // so initial state of dp should the score itself.
        // score should be in order of age scores
        for(int i=0; i<n; i++) {
            dp[i] = v_age_scores[i].second;
        }
        
        for(int i=n-1; i>=0; i--) {
            for(int j=n-1; j>i; j--) {
                
                // less than or equal is fine
                if(v_age_scores[i].second <= v_age_scores[j].second) {
                    // we don't want length of lis, we want the sum
                    dp[i] = max(dp[i], dp[j] + v_age_scores[i].second);
                }
            }
        }

        return *max_element(dp.begin(), dp.end());
    }   
};



