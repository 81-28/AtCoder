// https://atcoder.jp/contests/abc421/tasks/abc421_f

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
using pii=pair<int,int>;
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)

#define f first
#define s second

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    // m[i]:{前の数,後の数}
    unordered_map<int,pii> m;
    m[0]={-1,-1};
    int q;
    cin >> q;
    rep1(i,q){
        int n;
        cin >> n;
        if (n==1) {
            int x;
            cin >> x;
            int nxt=m[x].s;
            m[i]={x,nxt};
            m[x].s=i;
            if (nxt!=-1) m[nxt].f=i;
        }
        if (n==2) {
            int x,y;
            cin >> x >> y;
            int prev=m[x].f;
            int nxt=m[x].s;
            int smp=0,smn=0;
            bool okp=1,okn=1;
            while (1) {
                if (okp && prev==y) {
                    print(smp);
                    m[x].f=y;
                    m[y].s=x;
                    break;
                }
                if (okn && nxt==y) {
                    print(smn);
                    m[x].s=y;
                    m[y].f=x;
                    break;
                }
                if (prev==-1) okp=0;
                if (nxt==-1) okn=0;
                if (okp) {
                    smp+=prev;
                    prev=m[prev].f;
                }
                if (okn) {
                    smn+=nxt;
                    nxt=m[nxt].s;
                }
            }
        }
    }


    return 0;
}
