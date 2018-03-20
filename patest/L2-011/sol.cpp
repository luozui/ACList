#include <stdio.h>
#include <algorithm>
using namespace std;

const int MAXN = 35;
int pre[MAXN], ino[MAXN], stk[MAXN][MAXN], cnt[MAXN], SZ, n;

struct node {
    int key;
    node *lson, *rson;
    node() {}
    node(int _key, node *_lson, node *_rson) {
        key = _key;
        lson = _lson;
        rson = _rson;
    }
} *root;

node *build(int *s1, int *e1, int *s2, int *e2) {
    if(e1 < s1) return NULL;
    int t = 0;
    while(*s2 != s1[t]) ++t;
    return new node(*s2,
                    build(s1, s1 + t - 1, s2 + 1, s2 + t), 
                    build(s1 + t + 1, e1, s2 + t + 1, e2));
}

void print(node *v, int sz) {
    if(v == NULL) return ;
    stk[sz][cnt[sz]++] = v->key;
    SZ = max(SZ, sz);
    print(v->rson, sz + 1);
    print(v->lson, sz + 1);
}

int main()
{
    while(scanf("%d", &n) != EOF) {
        for(int i = 0; i < n; ++i) scanf("%d", pre + i);
        for(int i = 0; i < n; ++i) scanf("%d", ino + i);
        root = build(pre, pre + n - 1, ino, ino + n - 1);
        print(root, 0);
        bool flag = false;
        for(int i = 0; i <= SZ; ++i) {
            for(int j = 0; j < cnt[i]; ++j) {
                printf(flag ? " %d" : "%d", stk[i][j]);
                flag = true;
            }
        }
        puts("");
    }
    return 0;
}
