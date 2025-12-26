// https://atcoder.jp/contests/joi2008ho/tasks/joi2008ho_c

#include<bits/stdc++.h>
using namespace std;

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


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m;
    cin >> n >> m;
    vi p(n);
    cin >> p;
    p.pb(0);
    sort(all(p));
    uniq(p);
    // p(0を追加)の内2個を選んで獲得できる点数全パターン
    vi a;
    n=p.size();
    rep(i,n)for(int j=i; j<n; ++j) a.pb(p[i]+p[j]);
    sort(all(a));
    uniq(a);
    n=a.size();
    int ans=0;
    // 2+2個で合計点がm以下の最大値
    rep(i,n) {
        auto it=upper_bound(all(a),m-a[i]);
        if (it==a.begin()) break;
        --it;
        chmax(ans,a[i]+*it);
    }
    print(ans);

    return 0;
}
