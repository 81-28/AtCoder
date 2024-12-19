// https://atcoder.jp/contests/abc337/tasks/abc337_a

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    int s = 0,t = 0;
    int x,y;
    rep(i,n) {
        cin >> x >> y;
        s += x;
        t += y;
    }
    if (s == t) print("Draw");
    else if(s>t) print("Takahashi");
    else print("Aoki");

    return 0;
}
