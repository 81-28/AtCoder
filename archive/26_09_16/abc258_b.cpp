// https://atcoder.jp/contests/abc258/tasks/abc258_b

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using pii=pair<int,int>;
const pii dir[8]={{-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1}};
#define rep(i,n) for(int i=0;i<(int)(n);++i)
template<typename T>inline bool chmax(T& a,const T& b){if(a<b){a=b;return 1;}return 0;}

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    v<string> a(n);
    cin >> a;
    int ans=0;
    rep(i,n)rep(j,n) {
        for (auto[dx,dy]:dir) {
            string s;
            rep(k,n) {
                int x=(i+dx*k+n)%n;
                int y=(j+dy*k+n)%n;
                s+=a[x][y];
            }
            chmax(ans,stoll(s));
        }
    }
    print(ans);

    return 0;
}
