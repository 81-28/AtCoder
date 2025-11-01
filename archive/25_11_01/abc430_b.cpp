// https://atcoder.jp/contests/abc430/tasks/abc430_b

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m;
    cin >> n >> m;
    v<string> s(n);
    cin >> s;
    set<v<v<bool>>> st;
    rep(i,n+1-m)rep(j,n+1-m) {
        v<v<bool>> b(m,v<bool>(m));
        rep(x,m)rep(y,m) b[x][y]=(s[i+x][j+y]=='#');
        st.insert(b);
    }
    print(st.size());

    return 0;
}
