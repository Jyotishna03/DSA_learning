class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int size = nums.size();
        vector<int>neg;
        vector<int>pos;
        //int i initalise two array one postive one negative
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] < 0 )
            neg.push_back(nums[i]);
            else
            pos.push_back(nums[i]);
        }
        if(neg.size() == 0) //no neg
        {
            for(int i = 0; i < pos.size(); i++)
            pos[i] = pos[i] * pos[i];
            return pos;
        }
        if(pos.size() == 0) //no pos
        {
            for(int i = 0; i <neg.size(); i++)
            neg[i] = neg[i] * neg[i];

            reverse(neg.begin(), neg.end());
            return neg;
        }
        // merge and sort the two array
        int i = 0; 
        int j = 0;
        int id = 0; //result k liye id initalise kiya
        int n = neg.size();
        int m = pos.size();
        vector<int>res(n+m);
        for(int i = 0; i < n; i++ )
        neg[i] = neg[i] * neg[i];

        reverse(neg.begin(), neg.end());
        for(int i = 0; i < m; i++)
        pos[i] = pos[i] * pos[i];
        while(i < n and j < m ){
            if(neg[i] <= pos[j]) {
                res[id] = neg[i];
                id++;
                i++;
            }
            else{
                res[id] = pos[j];
                id++;
                j++;
            }
        }
        while(i < n) // kuch bacha ho neg array m
        {
            res[id] = neg[i];
            id++;
            i++;
        }
        while(j < m) //kuch bacha ho pos array m
        {
            res[id] = pos[j];
            id++;
            j++;
        }
        return res;

        }

    };
