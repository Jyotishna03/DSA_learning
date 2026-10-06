class Solution {
public:
    void backtrack(int start, int target, vector<int>& candidates, vector<int>& current, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(current);
            return;
        }

        for (int i = start; i < candidates.size(); ++i) {
            // Prune the search tree if candidate exceeds target
            if (candidates[i] > target) break;

            // Skip duplicates in the same depth level
            if (i > start && candidates[i] == candidates[i - 1]) continue;

            current.push_back(candidates[i]);
            // i + 1 because each element can only be used once
            backtrack(i + 1, target - candidates[i], candidates, current, result);
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;

        // Step 1: Sort candidates
        sort(candidates.begin(), candidates.end());

        // Step 2: Backtrack
        backtrack(0, target, candidates, current, result);

        return result;
    }
};