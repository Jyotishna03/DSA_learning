class Solution {
public:
    int countPrimes(int n) {

        if (n <= 2)
            return 0;

        vector<char> prime(n, 1);

        prime[0] = prime[1] = 0;

        int count = n - 2;

        for (int i = 2; i * i < n; i++) {

            if (prime[i]) {

                for (int j = i * i; j < n; j += i) {

                    if (prime[j]) {
                        prime[j] = 0;
                        count--;
                    }
                }
            }
        }

        return count;
    }
};