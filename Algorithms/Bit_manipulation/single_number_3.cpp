// Given a non-empty array of integers, every element appears three times except for one, 
// which appears exactly once. Find that single one.

// Input: [2,2,3,2]
// Output: 3

// Solution strategy: -
// Let our solution be X.
// Let F[i] number of elements with ith bit = 1

// Claim: - If ith bit is 1 in X. Then F[i] would be of the form 3n + 1


int singleNumber(vector<int>& arr) 
    {
        int n = arr.size();
        vector <int> f(32, 0);
        
        for(auto e: arr)
        {
            for(int i=0;i<32;i++)
            {
                if(e & (1<<i))
                {
                    f[i] += 1;
                }
            }
        }
        
        int res = 0;
        for(int i=0;i<32;i++)
        {
            if(f[i] % 3 == 1)
            {
//                 ith bit is set;
                res += (1 << i);
            }
        }
        return res;
        
    }