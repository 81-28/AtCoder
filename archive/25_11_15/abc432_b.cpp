// https://atcoder.jp/contests/abc432/tasks/abc432_b

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define all(v) v.begin(),v.end()

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    string x;
    cin >> x;
    sort(all(x));
    int n=x.size();
    rep(i,n) {
        if (x[i]!='0') {
            char tmp=x[0];
            x[0]=x[i];
            x[i]=tmp;
            break;
        }
    }
    print(x);

    return 0;
}
