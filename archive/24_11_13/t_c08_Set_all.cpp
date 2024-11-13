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
    set<int> ans,nans;
    rep(i,10000)ans.insert(i);
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
                        if(ans.find(num)!=ans.end()) nans.insert(num);
                    }
                }
                ten*=10;
            }
            ans = nans;
            if(ans.size()==1)break;
        }
        if(t==3) {
            ten=1;
            rep(i,4) {
                d = (s/ten%10);
                rep(j,10) {
                    num = s+(j-d)*ten;
                    if(ans.find(num)!=ans.end()) ans.erase(num);
                }
                ten*=10;
            }
            if(ans.size()==1)break;
        }
    }
    if(ans.size()==1) printf("%04d\n",*ans.begin());
    else print("Can't Solve");

    return 0;
}