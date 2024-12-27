// https://atcoder.jp/contests/abc335/tasks/abc335_b

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define pb push_back
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

    int n,m=0;
    cin >> n;
    vvi ans;
    vi vec;
    for (int i=0; i<=n; i++) {
        for (int j=0; j<=n-i; j++) {
            for (int k=0; k<=n-i-j; k++) {
                vec = vi(3);
                vec[0]=i;
                vec[1]=j;
                vec[2]=k;
                ans.pb(vec);
                m++;
            }
        }
    }
    rep(i,m) print(ans[i]);

    return 0;
}
