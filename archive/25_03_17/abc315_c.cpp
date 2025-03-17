// https://atcoder.jp/contests/abc315/tasks/abc315_c

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rall(v) v.rbegin(),v.rend()
template<typename T>
using v=vector<T>;
using pii=pair<int,int>;

void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    v<pii> p(n);
    rep(i,n)cin>>p[i].second>>p[i].first;
    sort(rall(p));
    int ans=p[0].first;
    int f=p[0].second;
    int add=0;
    for (int i=1; i<n; i++) {
        if (p[i].second != f) {
            add = max(add,p[i].first);
            break;
        } else if(i==1) {
            add = p[i].first/2;
        }
    }
    print(ans+add);

    return 0;
}
