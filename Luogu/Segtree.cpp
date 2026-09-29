#include<bits/stdc++.h>
using namespace std;
using ll = long long;

// 线段树节点：记录自己管的区间 [l, r]、区间和、懒标记
struct Node {
    int l, r;       // 区间左右端点
    ll sum, lazy;   // 区间和、懒标记
};

// 线段树：区间加 + 区间求和（带懒标记）
struct Segtree {
    vector<Node> tree;   // 大小 4n

    Segtree(int n){
        tree.resize(4 * n);
    }

    // 建树：初始化节点 p 的区间为 [l, r]，并递归建左右儿子
    void build(int p, int l, int r, const vector<ll>& a){
        tree[p].l = l;
        tree[p].r = r;
        if (l == r) {
            tree[p].sum = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(p << 1, l, mid, a);
        build(p << 1 | 1, mid + 1, r, a);
        pushup(p);
    }

    // 用两个儿子更新父节点的区间和
    void pushup(int p){
        tree[p].sum = tree[p << 1].sum + tree[p << 1 | 1].sum;
    }

    // 下推节点 p 的懒标记到两个儿子
    void pushdown(int p){
        if (!tree[p].lazy) return;
        int lc = p << 1, rc = p << 1 | 1;

        tree[lc].sum += tree[p].lazy * (tree[lc].r - tree[lc].l + 1);
        tree[rc].sum += tree[p].lazy * (tree[rc].r - tree[rc].l + 1);
        tree[lc].lazy += tree[p].lazy;
        tree[rc].lazy += tree[p].lazy;

        tree[p].lazy = 0;
    }

    // 区间加：对 [l, r] 每个数加 v（从节点 p 出发，区间范围取自节点自身）
    void add(int p, int l, int r, ll v){
        if (l <= tree[p].l && tree[p].r <= r) {          // 当前节点区间被 [l,r] 完全覆盖
            tree[p].sum += v * (tree[p].r - tree[p].l + 1);
            tree[p].lazy += v;
            return;
        }
        pushdown(p);                                     // 部分覆盖，先下推
        int mid = (tree[p].l + tree[p].r) >> 1;
        if (l <= mid) add(p << 1, l, r, v);              // 左儿子有交集
        if (r > mid)  add(p << 1 | 1, l, r, v);          // 右儿子有交集
        pushup(p);                                       // 回溯更新自己
    }

    // 区间查询：求 [l, r] 的和（从节点 p 出发）
    ll query(int p, int l, int r){
        if (l <= tree[p].l && tree[p].r <= r)            // 当前节点区间被 [l,r] 完全覆盖
            return tree[p].sum;
        pushdown(p);                                     // 访问儿子前先下推
        int mid = (tree[p].l + tree[p].r) >> 1;
        ll res = 0;
        if (l <= mid) res += query(p << 1, l, r);
        if (r > mid)  res += query(p << 1 | 1, l, r);
        return res;
    }
};

int main(){
    int n, m;
    cin >> n >> m;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    Segtree sg(n);
    sg.build(1, 1, n, a);

    while (m--) {
        int op, l, r;
        cin >> op >> l >> r;
        if (op == 1) {           // 区间加
            ll v; cin >> v;
            sg.add(1, l, r, v);
        } else {                 // 区间查询
            cout << sg.query(1, l, r) << "\n";
        }
    }
    return 0;
}
