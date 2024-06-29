// ICPC_pre_c

// #include <atcoder/all>
// using namespace atcoder;
// #define rep(i, n) for (int i = 0; i < (int)(n); i++)
// using ll = long long;
// using P = pair<int,int>;

#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> ans;
    while(true){
        int N,c=0,vx1,vy1,vz1,vx2,vy2,vz2;
        cin>>N;
        if(N==0){
            break;
        }else{
            vector<int> x(N);
            vector<int> y(N);
            vector<int> z(N);
            for(int i=0;i<N;i++){
                cin>>x.at(i)>>y.at(i)>>z.at(i);
            }

            for(int i=0;i<N-2;i++){
                for(int j=i+1;j<N-1;j++){
                    for(int k=j+1;k<N;k++){
                        vx1=x.at(j)-x.at(i);
                        vy1=y.at(j)-y.at(i);
                        vz1=z.at(j)-z.at(i);
                        vx2=x.at(k)-x.at(i);
                        vy2=y.at(k)-y.at(i);
                        vz2=z.at(k)-z.at(i);
                        if(vx1*vx2+vy1*vy2+vz1*vz2==0){
                            for(int l=0;l<N;l++){
                                if(x.at(l)==x.at(i)+vx1+vx2&&y.at(l)==y.at(i)+vy1+vy2&&z.at(l)==z.at(i)+vz1+vz2){
                                    c++;
                                    break;
                                }
                            }
                        }
                        vx1=x.at(i)-x.at(j);
                        vy1=y.at(i)-y.at(j);
                        vz1=z.at(i)-z.at(j);
                        vx2=x.at(k)-x.at(j);
                        vy2=y.at(k)-y.at(j);
                        vz2=z.at(k)-z.at(j);
                        if(vx1*vx2+vy1*vy2+vz1*vz2==0){
                            for(int l=0;l<N;l++){
                                if(x.at(l)==x.at(j)+vx1+vx2&&y.at(l)==y.at(j)+vy1+vy2&&z.at(l)==z.at(j)+vz1+vz2){
                                    c++;
                                    break;
                                }
                            }
                        }
                        vx1=x.at(j)-x.at(k);
                        vy1=y.at(j)-y.at(k);
                        vz1=z.at(j)-z.at(k);
                        vx2=x.at(i)-x.at(k);
                        vy2=y.at(i)-y.at(k);
                        vz2=z.at(i)-z.at(k);
                        if(vx1*vx2+vy1*vy2+vz1*vz2==0){
                            for(int l=0;l<N;l++){
                                if(x.at(l)==x.at(k)+vx1+vx2&&y.at(l)==y.at(k)+vy1+vy2&&z.at(l)==z.at(k)+vz1+vz2){
                                    c++;
                                    break;
                                }
                            }
                        }
                    }
                }
            }
            ans.push_back(c/4);
        }
    }
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
}