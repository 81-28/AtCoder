// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_do

#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int N,f,s;
    cin>>N;
    long long p=0,n=0,l=0,r=0;
    for(int i=0;i<N;i++){
        cin>>f>>s;
        if(f+s>0)p+=f+s;
        else n-=f+s;
        if(f-s>0)l+=f-s;
        else r-=f-s;
    }
    cout<<max({p,n,l,r})<<'\n';

    return 0;
}
