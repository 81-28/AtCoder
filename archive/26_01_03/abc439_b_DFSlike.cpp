// https://atcoder.jp/contests/abc439/tasks/abc439_b

#include<bits/stdc++.h>
using namespace std;

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}
#define YesNo(x) print(x?"Yes":"No")


int f(int n) {
    int res=0;
    while (n>0) {
        int l=n%10;
        res+=l*l;
        n/=10;
    }
    return res;
}

map<int,bool> m;
bool h(int n) {
    if (m.find(n)!=m.end()) return m[n];
    m[n]=0;
    return m[n]=h(f(n));
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    m[1]=1;
    YesNo(h(n));

    return 0;
}
