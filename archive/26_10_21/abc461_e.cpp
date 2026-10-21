// https://atcoder.jp/contests/abc461/tasks/abc461_e

#include<bits/stdc++.h>
using namespace std;
#include<atcoder/all>
using namespace atcoder;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


using S=int;
S op(S a,S b){return S(a+b);}
S e(){return S();}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,q;
    cin >> n >> q;
    // 各時刻を最終操作時刻とする行・列の個数
    // 区間和で、期間内に操作された行・列の種類数を求める
    vector t(2,segtree<S,op,e>(v<S>(q+1,0)));
    // 全て白にする
    t[1].set(0,n);
    // 最終操作時刻
    vvi l={vi(n,-1),vi(n,0)};
    int ans=0;
    rep1(i,q) {
        int m,x;
        cin >> m >> x;
        int& j=l[--m][--x];
        int cnt=t[!m].prod(j+1,i);
        ans+=m?-cnt:cnt;
        if (j>=0) t[m].set(j,t[m].get(j)-1);
        t[m].set(j=i,1);
        print(ans);
    }

    return 0;
}
