// https://atcoder.jp/contests/abc454/tasks/abc454_d

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}
#define YesNo(x) print(x?"Yes":"No")


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        string a,b;
        cin >> a >> b;
        int n=a.size(),m=b.size();
        int cnta=0,cntb=0;
        rep(i,n) cnta+=(a[i]=='x');
        rep(i,m) cntb+=(b[i]=='x');
        if (cnta!=cntb) {
            YesNo(0);
            continue;
        }
        string aa="",bb="";
        rep(i,n) {
            int l=aa.size();
            if (a[i]==')' && l>2 && aa[l-3]=='(' && aa[l-2]=='x' && aa[l-1]=='x') {
                aa[l-3]='x';
                aa.pop_back();
            } else {
                aa.pb(a[i]);
            }
        }
        rep(i,m) {
            int l=bb.size();
            if (b[i]==')' && l>2 && bb[l-3]=='(' && bb[l-2]=='x' && bb[l-1]=='x') {
                bb[l-3]='x';
                bb.pop_back();
            } else {
                bb.pb(b[i]);
            }
        }
        if (aa.size()!=bb.size()) {
            YesNo(0);
            continue;
        }
        bool ok=1;
        rep(i,aa.size()) {
            if (aa[i]!=bb[i]) {
                ok=0;
                break;
            }
        }
        YesNo(ok);
    }

    return 0;
}
