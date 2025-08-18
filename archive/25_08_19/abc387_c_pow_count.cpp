// https://atcoder.jp/contests/abc387/tasks/abc387_c

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


int int_pow(const int& a,const int& t) {
    int res=1;
    rep1(i,t) res*=a;
    return res;
}

// {st以下の最大ヘビ数,stがヘビ数かどうか}
pair<string,bool> below(string st) {
    int n=st.size();
    rep1(i,n-1) {
        if (st[i]>=st[0]) {
            for (int j=i; j<n; ++j) st[j]=st[0]-1;
            return {st,0};
        }
    }
    return {st,1};
}
// 同じ頭を持ち同じ長さの、st(ヘビ数)以下のヘビ数の個数
int cnt(const string& st) {
    int h=st[0]-'0',e=st.size()-1;
    int d=1,res=1;
    for (int i=e; i; --i,d*=h) res+=d*(st[i]-'0');
    return res;
}

// 次p.fEp.s
pii nxt(pii p) {
    ++p.f;
    if (p.f==10) {
        p.f=1;
        ++p.s;
    }
    return p;
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int l,r;
    cin >> l >> r;
    string sl=to_string(l),sr=to_string(r);
    int dl=sl[0]-'0',dr=sr[0]-'0';
    int el=sl.size()-1,er=sr.size()-1;
    pair<string,bool> pl=below(sl),pr=below(sr);
    int cl=cnt(pl.f)-pl.s,cr=cnt(pr.f);
    int ans=cr-cl;
    pii bg={dl,el},ed={dr,er};
    // 同じ頭を持ち同じ長さのヘビ数の個数をカウント
    for (pii p=bg; p!=ed; p=nxt(p)) ans+=int_pow(p.f,p.s);
    print(ans);

    return 0;
}
