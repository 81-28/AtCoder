// https://atcoder.jp/contests/abc331/tasks/abc331_f

#include<bits/stdc++.h>
using namespace std;
#include<atcoder/all>
using namespace atcoder;

template<typename T>
using v=vector<T>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}
#define YesNo(x) print(x?"Yes":"No")


// 5つのMODでハッシュを管理
constexpr int B = 5;
constexpr int mods[B] = {998244353, 1000000007, 1000000009, 1000000021, 1000000033};
int bases[B];

struct Node {
    array<long long, B> fw; // 順方向のハッシュ (forward)
    array<long long, B> bw; // 逆方向のハッシュ (backward)
    array<long long, B> pw; // base の文字列長乗
};

// 2つの区間を結合する関数
Node op(Node left, Node right) {
    Node res;
    for (int i=0; i<B; ++i) {
        res.fw[i] = (left.fw[i] * right.pw[i] + right.fw[i]) % mods[i];
        res.bw[i] = (right.bw[i] * left.pw[i] + left.bw[i]) % mods[i];
        res.pw[i] = (left.pw[i] * right.pw[i]) % mods[i];
    }
    return res;
}

// 単位元（空文字列に相当する状態）
Node e() {
    Node res;
    for (int i=0; i<B; ++i) {
        res.fw[i] = 0;
        res.bw[i] = 0;
        res.pw[i] = 1;
    }
    return res;
}

// 1文字からNodeを生成する関数
Node make_node(char c) {
    Node res;
    for (int i=0; i<B; ++i) {
        res.fw[i] = c;
        res.bw[i] = c;
        res.pw[i] = bases[i];
    }
    return res;
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cout<<fixed<<setprecision(16);

    // 実行時に一度だけ基数をランダムに初期化
    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    for (int i=0; i<B; ++i) {
        bases[i] = rng() % (mods[i] - 2) + 2;
    }

    int n,q;
    string s;
    cin >> n >> q >> s;

    v<Node> init(n);
    rep(i,n) init[i]=make_node(s[i]);
    segtree<Node,op,e> t(init);

    while (q--) {
        int m;
        cin >> m;
        if (m&1) {
            int x;
            char c;
            cin >> x >> c;
            t.set(--x,make_node(c));
        } else {
            int l,r;
            cin >> l >> r;
            Node res=t.prod(--l,r);
            YesNo(res.fw==res.bw);
        }
    }

    return 0;
}
