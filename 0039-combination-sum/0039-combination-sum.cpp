class Solution {
public:
    void backtrack(int start, int target, vector<int>& candidates, vector<int>& current, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(current);
            return;
        }

        for (int i = start; i < candidates.size(); ++i) {
            // Prune search path if candidate exceeds remaining target
            if (candidates[i] > target) continue;

            current.push_back(candidates[i]);
            // Pass `i` (not `i + 1`) because elements can be reused
            backtrack(i, target - candidates[i], candidates, current, result);
            current.pop_back(); // Backtrack
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;

        backtrack(0, target, candidates, current, result);

        return result;
    }
};