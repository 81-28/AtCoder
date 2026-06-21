// https://atcoder.jp/contests/abc217/tasks/abc217_e

#include<bits/stdc++.h>
using namespace std;

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cout<<fixed<<setprecision(16);

    int t;
    cin >> t;
    queue<int> q;
    multiset<int> s;
    while (t--) {
        int n;
        cin >> n;
        if (n==1) {
            int x;
            cin >> x;
            q.push(x);
        }
        if (n==2) {
            if (s.size()) {
                print(*s.begin());
                s.erase(s.begin());
            } else {
                print(q.front());
                q.pop();
            }
        }
        if (n==3) {
            while (!q.empty()) {
                s.insert(q.front());
                q.pop();
            }
        }
    }

    return 0;
}
