// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        long long l = 1;
        long long r = n;
        while (l!=r) 
        {
            long long mid = (l + r + 1) / 2;
            int t = guess(mid);
            if (t==0) return mid;
            if (t<0) r = mid - 1;
            else l = mid + 1;
        }
        
        return l;
    }
};
