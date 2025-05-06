// https://atcoder.jp/contests/abc303/tasks/abc303_b

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;

template<typename T>
istream &operator>>(istream &is,vector<T> &v){for(T &in:v)is>>in;return is;}
void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m;
    cin >> n >> m;
    vvi a(m,vi(n));
    cin >> a;
    v<unordered_set<int>> s(n);
    rep(i,m)rep(j,n) {
        if (j) s[a[i][j]-1].insert(a[i][j-1]-1);
        if (j+1<n) s[a[i][j]-1].insert(a[i][j+1]-1);
    }
    int ans=0;
    for(int i=0;i<n-1;i++)for(int j=i+1;j<n;j++) {
        if (s[i].find(j)==s[i].end()) ans++;
    }
    print(ans);

    return 0;
}
