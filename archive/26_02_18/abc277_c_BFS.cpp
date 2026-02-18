// https://atcoder.jp/contests/abc277/tasks/abc277_c

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
#define pb push_back
template<typename T>inline bool chmax(T& a,const T& b){if(a<b){a=b;return 1;}return 0;}

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    map<int,vi> m;
    while (n--) {
        int a,b;
        cin >> a >> b;
        m[a].pb(b);
        m[b].pb(a);
    }
    queue<int> q;
    map<int,bool> d;
    q.push(1);
    d[1]=1;
    int ans=1;
    while (!q.empty()) {
        int pos=q.front();
        q.pop();
        chmax(ans,pos);
        for (int nxt:m[pos]) {
            if (!d[nxt]) {
                d[nxt]=1;
                q.push(nxt);
            }
        }
    }
    print(ans);

    return 0;
}
