#include <stdio.h>
#include <algorithm>
using namespace std;

const int MAXN = 35;
int suc[MAXN], ino[MAXN], n;
int stk[MAXN][MAXN], cnt[MAXN], SZ;

struct node {
    int key;
    node *lson, *rson;
    node() {}
    node(const int &_key, node *_lson, node *_rson){
        key = _key;
        lson = _lson;
        rson = _rson;
    }
} *root;
typedef struct node node;

node *build(int p1[], int p2[], int size) {
    if(size < 0) return NULL;
    int t = 0;
    while(p1[size] != p2[t]) ++t;
    node *l = build(p1, p2, t - 1);
    node *r = build(p1 + t, p2 + t + 1, size - t - 1);
    return new node(p2[t], l, r);
}

void print(node *v, int sz) {
    if(v == NULL) return ;
    stk[sz][cnt[sz]++] = v->key;
    SZ = max(SZ, sz);
    print(v->lson, sz + 1);
    print(v->rson, sz + 1);
}

int main()
{
    int n;
    while(scanf("%d", &n) != EOF) {
        for(int i = 0; i < n; ++i) scanf("%d", suc + i);
        for(int i = 0; i < n; ++i) scanf("%d", ino + i);
        root = build(suc, ino, n - 1);
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
