// https://atcoder.jp/contests/abc299/tasks/abc299_d

#include<bits/stdc++.h>
using namespace std;

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    int l=1,r=n;
    while (1) {
        if (r-l==1) {
            print('!',l);
            return 0;
        }
        int m=(l+r)/2;
        print('?',m);
        int a;
        cin >> a;
        if (a) r=m;
        else l=m;
    }

    return 0;
}
