// https://atcoder.jp/contests/abc212/tasks/abc212_d

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cout<<fixed<<setprecision(16);

    int q;
    cin >> q;
    int b=0;
    multiset<int> s;
    while (q--) {
        int n,x;
        cin >> n;
        if (n!=3) {
            cin >> x;
            if (n==1) s.insert(x-b);
            else b+=x;
        } else {
            auto it=s.begin();
            print(*it+b);
            s.erase(it);
        }
    }

    return 0;
}
