// https://atcoder.jp/contests/arc213/tasks/arc213_a

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
template<typename T>inline bool chmax(T& a,const T& b){if(a<b){a=b;return 1;}return 0;}

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


int l;

// 順列を、各要素の組の前後関係を表すbit列に変換する
// 各要素の組(x,y) (x<y) に対して、xがyより前にあれば0、後ろにあれば1を割り当てる
int enc(const vi& p) {
    vi pos(l);
    rep(i,l) pos[p[i]-1]=i;
    int res=0;
    int k=0;
    rep(x,l)for(int y=x+1; y<l; ++y) {
        // 小さい方の要素xが後ろにあれば、k番目のbitを1にする
        if (pos[x]>pos[y]) res|=(1LL<<k);
        ++k;
    }
    return res;
}

// 2つの順列で前後関係が異なる要素ペア数を数える
// これは一方の順列を基準にしたときの、もう一方の順列の転倒数に等しい
// 隣接swapでは1回につき1組の前後関係だけが変化するため、この数が隣接swapの最小回数となる
// encで各ペアの前後関係をbitにしてあるので、XORで異なるペアを取り出し、popcountで数える
int dist(const int& a,const int& b) {
    return __builtin_popcountll(a^b);
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n >> l;

    // 任意の順列から任意の順列に変換するために
    // 必要な隣接swap回数の上限
    // l=1のときも遷移元がi未満になるように1以上とする
    const int D=max(1LL,l*(l-1)/2);

    // bit[i]: 順列Piの各要素の前後関係
    v<int> bit(n+1,0);
    // dp[i]: i回目の操作後にA=Piとなっている場合の所持金の最大値
    vi dp(n+1,-1);
    // mx[i]: dp[0]～dp[i]の最大値
    vi mx(n+1,0);
    // 初期状態 A=(1,2,...,L)
    // すべての要素が昇順なのでbit[0]=0
    dp[0]=0;

    rep1(i,n) {
        int c;
        vi p(l);
        cin >> c >> p;
        bit[i]=enc(p);

        // best: P_iに移動可能な過去の状態の所持金の最大値
        int best=-1;
        // 遷移元jについて、i-j>=Dなら
        // どのような順列からでもPiに変換できる
        // よって、dp[0]～dp[i-D]の最大値を取得するだけでよい
        if (i>=D) best=mx[i-D];
        // i-j<Dの場合は、個別に遷移可能か判定する
        for(int j=max(0LL,i-D+1);j<i;++j) {
            // 時刻jから時刻iまでに最大i-j回swapできる
            if (dist(bit[j],bit[i])<=i-j) {
                chmax(best,dp[j]);
            }
        }
        // Piに到達可能なら報酬cを獲得する
        if (best>=0) dp[i]=best+c;

        // 累積最大値を更新する
        mx[i]=max(mx[i-1],dp[i]);
    }
    // すべてのdpの最大値が答え
    print(mx[n]);

    return 0;
}
