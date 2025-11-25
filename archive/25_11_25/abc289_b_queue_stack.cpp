// https://atcoder.jp/contests/abc289/tasks/abc289_b

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define pb push_back

template<typename T>
ostream &operator<<(ostream &os,const v<T> &v){for(int i=0;i<(int)v.size();++i)os<<(i?" ":"")<<v[i];return os;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m;
    cin >> n >> m;
    vi b(n+1,0);
    while(m--) {
        int a;
        cin >> a;
        b[a]=1;
    }
    queue<int> q;
    rep1(i,n) q.push(i);
    vi ans;
    while(!q.empty()) {
        stack<int> t;
        while(!q.empty()) {
            int val=q.front();
            q.pop();
            t.push(val);
            if(!b[val]) break;
        }
        while(!t.empty()) {
            int val=t.top();
            t.pop();
            ans.pb(val);
        }
    }
    print(ans);

    return 0;
}
