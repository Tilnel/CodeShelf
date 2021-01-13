inline int Read() {
    int X = 0, p = 1; char c = getchar();
    for (; c > '9' || c < '0'; c = getchar()) if (c == '-') p = -1;
    for (; c <= '9' && c >= '0'; c = getchar()) X = X * 10 + c - '0';
    return X * p;
}