// https://atcoder.jp/contests/abc416/tasks/abc416_c

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back
#define all(v) v.begin(),v.end()

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,k,x;
    cin >> n >> k >> x;
    v<string> s(n);
    cin >> s;
    v<string> ans;
    rep(i,pow(n,k)) {
        int d=i;
        string t="";
        rep(j,k) {
            t+=s[d%n];
            d/=n;
        }
        ans.pb(t);
    }
    sort(all(ans));
    print(ans[x-1]);

    return 0;
}
