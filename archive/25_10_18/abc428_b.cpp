// https://atcoder.jp/contests/abc428/tasks/abc428_b

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back
#define all(v) v.begin(),v.end()
template<typename T>inline bool chmax(T& a,const T& b){if(a<b){a=b;return 1;}return 0;}

template<typename T>
ostream &operator<<(ostream &os,const v<T> &v){for(int i=0;i<(int)v.size();++i)os<<(i?" ":"")<<v[i];return os;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,k;
    string s;
    cin >> n >> k >> s;
    map<string,int> m;
    rep(i,n-k+1) ++m[s.substr(i,k)];
    int ans=0;
    for (auto[str,cnt]:m) chmax(ans,cnt);
    v<string> vec;
    for (auto[str,cnt]:m) {
        if (cnt==ans) vec.pb(str);
    }
    sort(all(vec));
    print(ans);
    print(vec);

    return 0;
}
