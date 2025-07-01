// https://atcoder.jp/contests/abc388/tasks/abc388_b

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<(int)(n+1);i++)
template<typename T>
using v=vector<T>;
using vi=v<int>;

void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,d;
    cin >> n >> d;
    vi t(n),l(n);
    rep(i,n) {
        cin >> t[i] >> l[i];
    }
    int ans;
    rep1(k,d) {
        ans=0;
        rep(i,n) {
            ans = max(ans,t[i]*(l[i]+k));
        }
        print(ans);
    }

    return 0;
}
