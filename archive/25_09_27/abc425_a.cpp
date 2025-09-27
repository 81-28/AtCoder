// https://atcoder.jp/contests/abc425/tasks/abc425_a

#include<bits/stdc++.h>
using namespace std;

#define rep1(i,n) for(int i=1;i<=(int)(n);++i)

int int_pow(int a,int b) {
    int r=1;
    while(b){if(b&1)r*=a;a*=a;b>>=1;}
    return r;
}

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    int ans=0;
    rep1(i,n) {
        int add=int_pow(i,3);
        if (i%2) add*=-1;
        ans+=add;
    }
    print(ans);

    return 0;
}
