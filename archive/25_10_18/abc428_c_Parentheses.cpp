// https://atcoder.jp/contests/abc428/tasks/abc428_c

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}
#define YesNo(x) print(x?"Yes":"No")


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int q;
    cin >> q;
    stack<char> t;
    int sm=0;
    // a[i]:iより前で、和がマイナスとなる最大idx
    vi a(q,-1);
    while (q--) {
        int n;
        cin >> n;
        if (n==1) {
            char c;
            cin >> c;
            int i=t.size();
            if (c=='(') ++sm;
            if (c==')') --sm;
            if (sm<0) a[i]=i;
            else a[i]=-1;
            if (i && a[i-1]!=-1) a[i]=a[i-1];
            t.push(c);
        }
        if (n==2) {
            char c=t.top();
            t.pop();
            if (c=='(') --sm;
            if (c==')') ++sm;
        }
        int j=t.size();
        YesNo(!j || (a[j-1]==-1 && sm==0));
    }


    return 0;
}
