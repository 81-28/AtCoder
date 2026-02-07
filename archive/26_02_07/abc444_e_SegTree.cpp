// https://atcoder.jp/contests/abc444/tasks/abc444_e

#include<bits/stdc++.h>
using namespace std;
#include<atcoder/all>
using namespace atcoder;

constexpr int INF=numeric_limits<int>::max();
template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back
#define all(v) v.begin(),v.end()
#define uniq(v) v.erase(unique(v.begin(),v.end()),v.end()) // sort後に使用する
template<typename T>inline bool chmax(T& a,const T& b){if(a<b){a=b;return 1;}return 0;}

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


using S=int;
S op(S a,S b){return max(a,b);}
S e(){return -1;}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,d;
    cin >> n >> d;
    vi a(n);
    cin >> a;

    vi aa=a;
    aa.pb(INF);
    sort(all(aa));
    uniq(aa);
    int m=aa.size();
    map<int,int> idx;
    rep(i,m) idx[aa[i]]=i;

    // t[i]:値がiである最大インデックス
    segtree<S,op,e> t(m);
    int ans=0;
    // これより右の数のみを使ってよい
    int mx=-1;
    rep(i,n) {
        auto itl=upper_bound(all(aa),a[i]-d);
        auto itr=lower_bound(all(aa),a[i]+d);
        // iと一緒に使用できない最大インデックスに更新
        chmax(mx,t.prod(idx[*itl],idx[*itr]));
        ans+=i-mx;
        t.set(idx[a[i]],i);
    }
    print(ans);

    return 0;
}
