// https://leetcode.com/problems/design-twitter/description/

// Design a simplified version of Twitter where users can post tweets, follow/unfollow another user, 
// and is able to see the 10 most recent tweets in the user's news feed.

// Implement the Twitter class:

//     Twitter() Initializes your twitter object.
//     void postTweet(int userId, int tweetId) Composes a new tweet with ID tweetId by the user userId. 
//     Each call to this function will be made with a unique tweetId.
//     List<Integer> getNewsFeed(int userId) Retrieves the 10 most recent tweet IDs in the user's news feed. 
//     Each item in the news feed must be posted by users who the user followed or by the user themself. 
//     Tweets must be ordered from most recent to least recent.
//     void follow(int followerId, int followeeId) The user with ID followerId started following the user with ID followeeId.
//     void unfollow(int followerId, int followeeId) The user with ID followerId started unfollowing the user with ID followeeId.

// Example 1:

// Input
// ["Twitter", "postTweet", "getNewsFeed", "follow", "postTweet", "getNewsFeed", "unfollow", "getNewsFeed"]
// [[], [1, 5], [1], [1, 2], [2, 6], [1], [1, 2], [1]]
// Output
// [null, null, [5], null, null, [6, 5], null, [5]]

// Solution:

// we cannot mantain and keep appending tweets whom user follows to user
// That is too much memory
// a table denoting {user, who_user_is_following} can act as pointer to get the tweets.

// Keep the following in a map of <user_id, set<who_user_is_follwing>>
// This makes following and unfollowing very simple
// Remember to keep a global timer for user tweet history. This is needed to order tweets correctly.
// Use this to map<user_id, <timetamp, tweetId>> tweetId is not a unique global timestamp.
// tweetid is just a unique id, not timestamp based (unlike actual Twitter)
// Getting a news fed is bit tricky
// Accumulate all the user tweets
// push them in order of <history, tweetId> to a maxh;
// Push all followee tweets
// Now get top 10 tweets and return them in result vector


#include<unordered_set>
#include<unordered_map>
#include<vector>
#include<queue>


using namespace std;


class Twitter {
    private:
        int history=0;
        unordered_map<int, unordered_set<int>> following;
        unordered_map<int, vector<pair<int, int>>> tweets;
        //            user           history   tweetID
        
    public:
        Twitter() {}
        
        void postTweet(int userId, int tweetId) {
            tweets[userId].push_back({history,tweetId});
            history++;
        }
        
        vector<int> getNewsFeed(int userId) {
            vector<int> ans;
            priority_queue<pair<int,int>> pq;
            for(auto tweet : tweets[userId]){
                pq.push(tweet);
            }
            for(auto followee : following[userId]){
                for(auto tweet: tweets[followee]){
                    pq.push(tweet);
                }
            }
            int sz = pq.size();
            int n = min(10,sz);
            for(int i=0; i<n;i++){
                int a = pq.top().second; pq.pop();
                ans.push_back(a);
            }
            return ans;
        }
        
        void follow(int followerId, int followeeId) {
            following[followerId].insert(followeeId);
        }
        
        void unfollow(int followerId, int followeeId) {
            following[followerId].erase(followeeId);
        }
    };
    
    /**
     * Your Twitter object will be instantiated and called as such:
     * Twitter* obj = new Twitter();
     * obj->postTweet(userId,tweetId);
     * vector<int> param_2 = obj->getNewsFeed(userId);
     * obj->follow(followerId,followeeId);
     * obj->unfollow(followerId,followeeId);
     */
