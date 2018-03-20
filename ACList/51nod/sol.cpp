#include <stdio.h>
#include <algorithm>
using namespace std;

const int MAXN = (int)1e5 + 5;

int res[MAXN];

void init() {
    res[1] = 1;
    for(int i = 2; i < MAXN; ++i) {
        if(i & 1) res[i] = res[i / 2] + res[i / 2 + 1];
        else res[i] = res[i / 2];
    }
    for(int i = 1; i < MAXN; ++i) {
        res[i] = max(res[i], res[i - 1]);
    }
}

int main() {
    init();
    int T, n;
    scanf("%d", &T);
    for(int t = 0; t < T; ++t) {
        scanf("%d", &n);
        printf("%d\n", res[n]);
    }
    return 0;
}
