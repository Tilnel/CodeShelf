/*  Author: NogiNonoka
    Date: 2021.1.13     */

const int MOD = 1e9 + 7;
inline int GetPow(int a, int b) {
    int ret = 1;
    for ( ; b; b >>= 1, a = a * a % MOD)
        if (b & 1) ret = ret * a % MOD;
    return ret;
}