// https://atcoder.jp/contests/sumitrust2019/tasks/sumitb2019_d

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back
#define all(v) v.begin(),v.end()
template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    string s;
    cin >> n >> s;
    vvi idx(10);
    rep(i,n) idx[s[i]-'0'].pb(i);
    int ans=1000;
    vi ten(3);
    rep(i,3) ten[i]=pow(10,i);
    rep(i,1000) {
        int pos=-1;
        rep(j,3) {
            int d=i/ten[2-j]%10;
            auto it=upper_bound(all(idx[d]),pos);
            if (it==idx[d].end()) {
                --ans;
                break;
            }
            pos=*it;
        }
    }
    print(ans);

    return 0;
}
