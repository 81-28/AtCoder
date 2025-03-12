// https://atcoder.jp/contests/abc317/tasks/abc317_c

#include<bits/stdc++.h>
using namespace std;

#define rep1(i,n) for(int i=1;i<(int)(n+1);i++)
#define pb push_back
#define all(v) v.begin(),v.end()
using ll=long long;
template<typename T>
using v=vector<T>;
using vi=v<int>;

template<typename T>
istream &operator>>(istream &is,vector<T> &v){for(T &in:v)is>>in;return is;}
void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}

int n;
v<set<int>> g;
v<map<int,ll>> c;
ll ans,nans;
int p;

void f(const vi& r) {
    nans=0;
    p=r[0];
    for (int i=1; i<n; i++) {
        if (g[p].find(r[i]) != g[p].end()) {
            nans += c[p][r[i]];
            p=r[i];
            ans = max(ans,nans);
        } else break;
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int m;
    cin >> n >> m;
    g=v<set<int>>(n+1);
    c=v<map<int,ll>>(n+1);
    vi a(3);
    rep1(i,m) {
        cin >> a;
        g[a[0]].insert(a[1]);
        g[a[1]].insert(a[0]);
        c[a[0]][a[1]]=a[2];
        c[a[1]][a[0]]=a[2];
    }

    ans=0;
    vi r;
    rep1(i,n)r.pb(i);
    do f(r);while(next_permutation(all(r)));
    print(ans);

    return 0;
}
