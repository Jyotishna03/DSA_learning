class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        unordered_set<int> st;

        for (int i = 0; i < nums.size(); i++) {

            // If number is already present
            if (st.count(nums[i])) {
                return true;
            }

            // Add number to set
            st.insert(nums[i]);
        }

        return false;
    }
};