class Solution {
public:
    int* fact;
    
    void calcFact(int n)
    {
        fact = new int[n+1];
        fact[0] = 1;
        
        for (int i = 1; i <= n; i++)
            fact[i] = fact[i-1] * i;
    }
    
    int cnk(int n, int k)
    {
        if (k>n) return 0;
        int res = fact[n];
        res /= fact[k];
        res /= fact[n-k];
        return res;
    }
    
    int countNumbersWithUniqueDigits(int n) {
        if (n<1) return 1;
        if (n>10) n = 10;
        calcFact(10);
        
        int res = 1;
        for (int i = 1; i <= n; i++)
        {
            int tmp = cnk(9,i) * fact[i] + cnk(9,i-1) * fact[i-1] * (i-1);
            res += tmp;
        }
        
        return res;
    }
};
