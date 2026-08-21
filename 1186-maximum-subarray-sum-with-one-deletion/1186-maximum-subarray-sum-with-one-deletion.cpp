class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int noDelete = arr[0];
        int oneDelete = 0;
        int res = arr[0];

        for (int i = 1; i < arr.size(); i++) {
            int prevNoDelete = noDelete;
            int prevOneDelete = oneDelete;

            // No element deleted
            noDelete = max(prevNoDelete + arr[i], arr[i]);

            // Either:
            // 1. Delete current element
            // 2. Already deleted an element before
            oneDelete = max(prevNoDelete,
                            prevOneDelete + arr[i]);

            res = max(res, max(noDelete, oneDelete));
        }

        return res;
    }
};