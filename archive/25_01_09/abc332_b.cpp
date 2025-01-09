// https://atcoder.jp/contests/abc332/tasks/abc332_b

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int k,g,m;
    cin >> k >> g >> m;
    int gl=0,mg=0;
    int s;
    rep(i,k) {
        if (gl==g) gl=0;
        else if (mg==0) mg=m;
        else {
            s=gl+mg;
            if (s <= g) {
                gl=s;
                mg=0;
            } else {
                gl=g;
                mg=s-g;
            }
        }
    }
    print(gl,mg);

    return 0;
}
