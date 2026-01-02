// https://atcoder.jp/contests/abc287/tasks/abc287_d

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vb=v<bool>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}
#define YesNo(x) print(x?"Yes":"No")


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    string s,t;
    cin >> s >> t;
    int n=s.size(),m=t.size();
    // l[i]:左からi文字が一致するかどうか
    vb l(m+1,0),r=l;
    l[0]=1;
    rep1(i,m) {
        if (s[i-1]=='?' || t[i-1]=='?' || s[i-1]==t[i-1]) l[i]=1;
        else break;
    }
    r[0]=1;
    rep1(i,m) {
        int j=n-i,k=m-i;
        if (s[j]=='?' || t[k]=='?' || s[j]==t[k]) r[i]=1;
        else break;
    }
    rep(i,m+1) YesNo(l[i]&&r[m-i]);

    return 0;
}
