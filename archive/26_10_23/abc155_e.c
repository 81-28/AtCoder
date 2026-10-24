#include <stdio.h>
#include <string.h>
#include <unistd.h>

static unsigned char buf[1<<16];
static unsigned char table[3][4096];

static inline int mn(int a,int b) {
    return a<b?a:b;
}

#define STEP() do { \
    int key=(buf[i]&15)|((buf[i+1]&15)<<4)|((buf[i+2]&15)<<8); \
    int v=table[state][key]; \
    ans+=v>>2; \
    state=v&3; \
    i+=3; \
} while(0)

int main() {
    // 3桁分のDP遷移を事前計算
    for(int s=0;s<3;++s) {
        for(int x=0;x<10;++x) {
            for(int y=0;y<10;++y) {
                for(int z=0;z<10;++z) {
                    int digits[3]={x,y,z};
                    int key=x|(y<<4)|(z<<8);
                    int delta=s-1,cost=0;

                    for(int k=0;k<3;++k) {
                        int d=digits[k];
                        int a=mn(d,delta+10-d);
                        int b=mn(d+1,delta+9-d);
                        cost+=a;
                        delta=b-a;
                    }

                    table[s][key]=(cost<<2)|(delta+1);
                }
            }
        }
    }

    int ans=0,state=2;
    ssize_t n;

    while((n=read(0,buf,sizeof(buf)))>0) {
        unsigned char* e=memchr(buf,'\n',n);
        if(e) n=e-buf;

        ssize_t i=0;

        // 24桁ずつ処理
        for(;i+24<=n;) {
            STEP(); STEP(); STEP(); STEP();
            STEP(); STEP(); STEP(); STEP();
        }

        // 残りを3桁ずつ処理
        for(;i+3<=n;) STEP();

        // 余った1〜2桁
        for(;i<n;++i) {
            int x=buf[i]-'0';
            int d=state-1;
            int a=mn(x,d+10-x);
            int b=mn(x+1,d+9-x);
            ans+=a;
            state=b-a+1;
        }

        if(e) break;
    }

    printf("%d\n",ans);
}
