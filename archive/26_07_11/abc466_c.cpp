// https://atcoder.jp/contests/abc466/tasks/abc466_c

#include<bits/stdc++.h>
using namespace std;

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cout<<fixed<<setprecision(16);

    int n;
    cin >> n;
    int l=1,r=2;
    int ans=0;
    while (r<=n) {
        print('?',l,r);
        string s;
        cin >> s;
        bool b=s=="Yes";
        if (b) {
            ++ans;
            ++r;
        } else {
            ++l;
            if (l==r) ++r;
            ans+=r-l-1;
        }
    }
    ans+=(n-l)*(n-l-1)/2;
    print('!',ans);

    return 0;
}
