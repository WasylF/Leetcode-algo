class Solution {
public:
    int getSum(int a, int b) {
        int c = a & b;
        int d = a ^ c;
        int e = b ^ c;
        d |= e;
        c <<= 1;
        if ((int)(c&d) == 0) return c | d;
        return getSum(c,d);
    }
};
