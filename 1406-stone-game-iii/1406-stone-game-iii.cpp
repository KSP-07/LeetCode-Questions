class Solution {
public:
    vector<int> dp;  // Dynamic programming table for storing the score difference

    // Recursive function to play the stone game
    int play(int i, vector<int>& stoneValue, int n) {
        if (dp[i] != INT_MIN) return dp[i];  // If the result is already calculated, return it

        int result = stoneValue[i] - play(i + 1, stoneValue, n);  
        // score difference if she takes the stone at position i

        if (i + 2 <= n) {
            result = max(result, stoneValue[i] + stoneValue[i + 1] - play(i + 2, stoneValue, n));
        // score difference if she takes the stones at positions i and i+1
        }

        if (i + 3 <= n) {
            result = max(result, stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] - play(i + 3, stoneValue, n));
        //score difference if she takes the stones at positions i, i+1, and i+2
        }

        return dp[i] = result;  // Memoize the result and return it
    }

    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        dp.assign(n + 1, INT_MIN);  // Initialize the dynamic programming table with INT_MIN
        dp[n] = 0;  // Base case: If no stones are left, score difference is 0

        int win = play(0, stoneValue, n);  // Calculate the score difference between Alice and Bob
        if (win > 0) return "Alice";  // Alice wins
        if (win < 0) return "Bob";  // Bob wins
        return "Tie";  // It's a tie
    }
};