class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<long long> prefixTop(n + 1, 0), prefixBottom(n + 1, 0);

        // Compute prefix sums for the top and bottom rows
        for (int i = 0; i < n; ++i) {
            prefixTop[i + 1] = prefixTop[i] + grid[0][i];
            prefixBottom[i + 1] = prefixBottom[i] + grid[1][i];
        }

        long long minPointsForSecond = LLONG_MAX;

        // First robot minimizes the maximum points for the second robot
        for (int i = 0; i < n; ++i) {
            long long pointsTop = prefixTop[n] - prefixTop[i + 1];
            long long pointsBottom = prefixBottom[i];
            long long pointsForSecond = max(pointsTop, pointsBottom);
            minPointsForSecond = min(minPointsForSecond, pointsForSecond);
        }

        return minPointsForSecond;
    }
};
