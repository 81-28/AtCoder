// https://atcoder.jp/contests/abc314/tasks/abc314_b

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define pb push_back
#define all(v) v.begin(),v.end()
template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;

template<typename T>
istream &operator>>(istream &is,vector<T> &v){for(T &in:v)is>>in;return is;}
template<typename T>
ostream &operator<<(ostream &os,const vector<T> &v){for(int i=0;i<(int)v.size();i++)os<<(i?" ":"")<<v[i];return os;}
void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    vvi g(37);
    vi c(n+1);
    vi a;
    rep1(i,n) {
        cin >> c[i];
        a = vi(c[i]);
        cin >> a;
        rep(j,c[i])g[a[j]].pb(i);
    }
    int x;
    cin >> x;
    int mn=37;
    vi ans;
    for(int val:g[x])mn=min(mn,c[val]);
    for(int val:g[x])if(c[val]==mn)ans.pb(val);
    sort(all(ans));
    print(ans.size());
    print(ans);

    return 0;
}
