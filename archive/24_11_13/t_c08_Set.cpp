// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_ff

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    set<int> ans,nans,e;
    bool init=1;
    int ten=1;
    int d,num;
    int s,t;
    rep(k,n) {
        cin >> s >> t;
        if(t==1) {
            printf("%04d\n",s);
            return 0;
        }
        if(t==2) {
            nans = set<int>();
            ten=1;
            rep(i,4) {
                d = (s/ten%10);
                rep(j,10) {
                    if(j!=d) {
                        num = s+(j-d)*ten;
                        if(init || ans.find(num)!=ans.end()) nans.insert(num);
                    }
                }
                ten*=10;
            }
            ans = nans;
            init = 0;
            if(ans.size()==1)break;
        }
        if(t==3) {
            ten=1;
            rep(i,4) {
                d = (s/ten%10);
                rep(j,10) {
                    num = s+(j-d)*ten;
                    e.insert(num);
                }
                ten*=10;
            }
            if(ans.size()==1)break;
        }
    }
    for(int val:e)if(ans.find(val)!=ans.end()) ans.erase(val);
    if(ans.size()==1) printf("%04d\n",*ans.begin());
    else print("Can't Solve");

    return 0;
}
