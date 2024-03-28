/*
 * @lc app=leetcode.cn id=1997 lang=cpp
 *
 * [1997] 访问完所有房间的第一天
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    static const int N = 100000 + 5;
    static const int P = 1e9 + 7;
    int sum[N];
    inline int add(const int a, const int b) {
        return a + b >= P? a + b - P: a + b;
    }
    inline int sub(const int a, const int b) {
        return add(a - b, P);
    }
    inline int getsum(int begin, int end) {
        // i == nextVisit[i]
        if (end < begin) return 0;
        // nextVisit[i] == 0
        int bsum = begin > 0 ? sum[begin - 1] : 0;
        return sub(sum[end], bsum);
    }
    // 动态规划
    int firstDayBeenInAllRooms(vector<int>& nextVisit) {
        int answer = 0, n = nextVisit.size();
        sum[0] = 2;
        for (int i = 1; i < n; ++i) {
            int count = getsum(nextVisit[i], i - 1) + 2;
            sum[i] = add(sum[i - 1], count);
        }
        return sum[n - 2];
    }
};
// @lc code=end

