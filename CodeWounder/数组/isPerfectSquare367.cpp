class Solution {
   public:
    bool isPerfectSquare(int x) {
        int left = 0, right = x;
        while (left <= right) {
            double mid = (left + right) >> 1;
            if (mid * mid == x)
                return true;
            else if (mid * mid > x)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return false;
    }
};