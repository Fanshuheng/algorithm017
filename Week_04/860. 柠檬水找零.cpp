class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;
        for (auto& b : bills) {
            if (b == 5) five++;
            else if (b == 10) {
                five--;
                ten++;
            } else if (ten > 0) {
                ten--;
                five--;
            } else {
                five -= 3;
            }
            if (ten < 0 || five < 0) return false;
        }
        return true;
    }
};
