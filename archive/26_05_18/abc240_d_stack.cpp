// https://atcoder.jp/contests/abc240/tasks/abc240_d

#include<bits/stdc++.h>
using namespace std;

using pii=pair<int,int>;

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    // {数,個数}
    stack<pii> t;
    int ans=0;
    while (n--) {
        int a;
        cin >> a;
        if (t.empty()) {
            t.push({a,1});
            print(++ans);
            continue;
        }
        auto&[num,cnt]=t.top();
        if (num==a) {
            ++cnt;
            if (num==cnt) {
                ans-=cnt;
                t.pop();
            }
        } else t.push({a,1});
        print(++ans);
    }

    return 0;
}
