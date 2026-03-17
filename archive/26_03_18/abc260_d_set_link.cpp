// https://atcoder.jp/contests/abc260/tasks/abc260_d

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using pii=pair<int,int>;
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)

#define f first
#define s second

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,k;
    cin >> n >> k;
    // {数,枚数}
    set<pii> st;
    // {val,参照idx}
    v<pii> res(n+1,{-1,-1});
    rep1(i,n) {
        int p;
        cin >> p;
        auto it=st.lower_bound({p,0});
        if (it!=st.end()) {
            auto[num,cnt]=*it;
            st.erase(it);
            res[num].s=p;
            st.insert({p,cnt+1});
        } else {
            st.insert({p,1});
        }
        it=st.lower_bound({p,0});
        auto[num,cnt]=*it;
        if (cnt==k) {
            res[num].f=i;
            st.erase(it);
        }
    }
    vi ans(n+1);
    rep1(i,n) print(ans[i]=res[i].s==-1?res[i].f:ans[res[i].s]);

    return 0;
}
