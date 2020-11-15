class Solution {
public:
    int climbStairs(int n) {
        int step_count = 0;
        Recursion(n, 0, step_count);
        return step_count;

    }
    void Recursion(int n, int cur,int& step_count) {
        if (cur == n) {
            step_count++;
            return;
        }
        if (cur + 1 <= n) Recursion(n , cur + 1, step_count);
        if (cur + 2 <= n) Recursion(n , cur + 2, step_count);
    }
};
