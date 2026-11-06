// https://atcoder.jp/contests/abc184/tasks/abc184_f

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
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
#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,x;
    cin >> n >> x;
    int m=n-n/2;
    n/=2;
    vi a(n),b(m);
    cin >> a >> b;
    vi s(1,0),t(1,0);
    for (int val:a) {
        int l=s.size();
        rep(i,l) s.pb(s[i]+val);
    }
    for (int val:b) {
        int l=t.size();
        rep(i,l) t.pb(t[i]+val);
    }
    sort(all(t)),uniq(t);
    int ans=0;
    for (int val:s) {
        auto it=upper_bound(all(t),x-val);
        if (it==t.begin()) continue;
        chmax(ans,val+*--it);
    }
    print(ans);

    return 0;
}
