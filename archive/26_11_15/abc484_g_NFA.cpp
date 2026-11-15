// https://atcoder.jp/contests/abc484/tasks/abc484_g

#include<bits/stdc++.h>
using namespace std;
#include<atcoder/all>
using namespace atcoder;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using mint=modint998244353;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back
#define all(v) v.begin(),v.end()

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    string s,x,y;
    cin >> s >> x >> y;
    string t=x+y;
    int m=x.size(),n=t.size();

    // NFA: 各状態から0,1を読んだときの遷移先集合（ビット集合）
    // 状態i: 次にt[i]を読む位置
    // 状態0: Yの終了 / Xの開始
    // 状態m: Xの終了 / Yの開始
    v<array<int,2>> nfa(n);
    rep(i,n)rep(c,2) {
        if(t[i]=='?' || t[i]=='0'+c) {
            nfa[i][c] |= 1<<((i+1)%n);
        }
    }
    // Xの終了後はYだけでなく、再びXを読んでもよい
    // 状態mからX[0]を読んで、状態1へ進む遷移を追加
    rep(c,2) {
        if(x[0]=='?' || x[0]=='0'+c) {
            nfa[m][c] |= 2;
        }
    }

    // NFAの状態集合maskから文字cを読んだ後の状態集合
    auto next_mask=[&](int mask,int c) {
        int res=0;
        while(mask) {
            int i=__builtin_ctzll(mask); // 最下位の1の位置
            res |= nfa[i][c];              // 遷移先をORで統合
            mask&=mask-1;                // 最下位の1を削除
        }
        return res;
    };

    // DFA: 到達可能な状態集合だけを列挙
    // id[mask]: 状態集合maskに割り当てた番号（未登録なら-1）
    // states[i]: 番号iに対応する状態集合
    // to[i][c]: 番号iから文字cを読んだ後の状態番号
    vi id(1<<n,-1),states;
    v<array<int,2>> to;

    auto add_state=[&](int mask) {
        if(id[mask]!=-1) return id[mask];
        int i=states.size();
        id[mask]=i;
        states.pb(mask);
        to.pb({-1,-1});
        return i;
    };

    // 初期状態: X,Yのどちらからでも開始できる
    add_state(1<<m);
    // 新しく発見した状態を順に処理してDFAを構築
    rep(i,states.size()) {
        rep(c,2) {
            int nxt=next_mask(states[i],c);
            if(nxt==0) continue; // 遷移できない場合は除外
            int j=add_state(nxt);
            to[i][c]=j;
        }
    }

    // dp[i]: 状態iに到達する異なる文字列の個数
    v<mint> dp(states.size()),ndp=dp;
    dp[0]=1;
    for(char ch:s) {
        fill(all(ndp),mint(0));
        rep(i,states.size()) {
            if(dp[i]==0) continue;
            rep(c,2) {
                if(ch!='?' && ch!='0'+c) continue;
                int j=to[i][c];
                if(j==-1) continue;
                ndp[j]+=dp[i];
            }
        }
        dp.swap(ndp);
    }

    // XまたはYをちょうど読み終えた状態を含めば受理
    // X終了: 状態m、Y終了: 状態0
    mint ans=0;
    int accept=(1<<m)|1;
    rep(i,states.size()) {
        if(states[i]&accept) ans+=dp[i];
    }
    print(ans.val());

    return 0;
}
