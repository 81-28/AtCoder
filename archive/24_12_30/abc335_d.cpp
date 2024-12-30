// https://atcoder.jp/contests/abc335/tasks/abc335_d

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;

template<typename T>
ostream &operator<<(ostream &os,const vector<T> &v){for(int i=0;i<(int)v.size();i++)os<<(i?" ":"")<<v[i];return os;}
void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    vvi ans(n,vi(n,0));
    int m=1;
    int d=0;
    for (int i=n; 1<i; i-=2) {
        rep(j,i-1) {
            ans[d][d+j] = m+j;
            ans[d+j][n-1-d] = m+(i-1)+j;
            ans[n-1-d][n-1-d-j] = m+2*(i-1)+j;
            ans[n-1-d-j][d] = m+3*(i-1)+j;
        }
        m+=4*(i-1);
        d++;
    }
    rep(i,n) {
        if (i==n/2) {
            rep(j,n) {
                if (j==n/2) cout<<'T';
                else cout<<ans[i][j];
                cout<<' ';
            }
            cout<<'\n';
        } else print(ans[i]);
    }

    return 0;
}
