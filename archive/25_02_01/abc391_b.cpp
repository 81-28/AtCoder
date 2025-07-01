// https://atcoder.jp/contests/abc391/tasks/abc391_b

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m;
    cin >> n >> m;
    vvi s(n,vi(n,0)), t(m,vi(m,0));
    char c;
    rep(i,n)rep(j,n) {
        cin >> c;
        if (c=='#')s[i][j]=1;
    }
    rep(i,m)rep(j,m) {
        cin >> c;
        if (c=='#')t[i][j]=1;
    }
    bool ok=1;
    rep(i,n-m+1)rep(j,n-m+1) {
        ok=1;
        rep(k,m)rep(l,m) {
            if (ok && s[i+k][j+l] != t[k][l]) {
                ok=0;
                break;
            }
        }
        if (ok) {
            print(i+1,j+1);
            return 0;
        }
    }

    return 0;
}
