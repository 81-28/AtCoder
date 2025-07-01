// https://atcoder.jp/contests/abc387/tasks/abc387_b

#include<bits/stdc++.h>
using namespace std;

#define rep1(i,n) for(int i=1;i<(int)(n+1);i++)
void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int x;
    cin >> x;
    int ans = 0;
    rep1(i,9)rep1(j,9) if (i*j!=x) ans += i*j;
    print(ans);

    return 0;
}
