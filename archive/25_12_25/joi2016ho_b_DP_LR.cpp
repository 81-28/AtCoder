// https://atcoder.jp/contests/joi2016ho/tasks/joi2016ho_b

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
template<typename T>inline bool chmax(T& a,const T& b){if(a<b){a=b;return 1;}return 0;}

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    string s;
    cin >> n >> s;
    // l[i][j]:左からi個の店でスタンプをj個押せるパターン数
    // rは逆順で押す
    vvi l(n+1,vi(4,0)),r=l;
    l[0][0]=1;
    rep1(i,n) {
        l[i][0]+=l[i-1][0];
        l[i][1]+=l[i-1][1];
        l[i][2]+=l[i-1][2];
        l[i][3]+=l[i-1][3];
        if (s[i-1]=='J') l[i][1]+=l[i-1][0];
        if (s[i-1]=='O') l[i][2]+=l[i-1][1];
        if (s[i-1]=='I') l[i][3]+=l[i-1][2];
    }
    r[n][0]=1;
    for(int i=n-1; i>=0; --i) {
        r[i][0]+=r[i+1][0];
        r[i][1]+=r[i+1][1];
        r[i][2]+=r[i+1][2];
        if (s[i]=='I') r[i][1]+=r[i+1][0];
        if (s[i]=='O') r[i][2]+=r[i+1][1];
    }
    // 全ての位置で、3種類の文字への書き換えを試す
    int add=0;
    rep(i,n+1) {
        chmax(add,l[i][0]*r[i][2]);
        chmax(add,l[i][1]*r[i][1]);
        chmax(add,l[i][2]*r[i][0]);
    }
    // l[n][3]:書き換えない
    print(l[n][3]+add);

    return 0;
}
