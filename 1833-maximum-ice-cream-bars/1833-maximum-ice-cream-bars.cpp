class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int max_cost = *max_element(costs.begin(), costs.end());
        vector<int> freq(max_cost + 1, 0);
        
        // Count the frequency of each ice cream bar price
        for (int cost : costs) {
            freq[cost]++;
        }
        
        int bars = 0;
        // Greedily buy from the lowest price to the highest
        for (int cost = 1; cost <= max_cost; ++cost) {
            if (freq[cost] == 0) continue;
            if (coins < cost) break;
            
            int count = min(freq[cost], coins / cost);
            bars += count;
            coins -= count * cost;
        }
        
        return bars;
    }
};