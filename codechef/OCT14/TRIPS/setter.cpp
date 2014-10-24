#include <bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define RS(X) scanf("%s", (X))
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define F first
#define S second
typedef long long LL;
using namespace std;
const int MOD = 1e9+7;
const int SIZE = 2e5+1;
const int TRAD = 400;
vector<int>e[SIZE];
int jump[18][SIZE],an[SIZE],lv[SIZE],N,step[2][SIZE];
int super[18][SIZE];
void init(int x,int lt){
    jump[0][x]=lt;
    REP(i,SZ(e[x])){
        int y=e[x][i];
        if(y!=lt){
            lv[y]=lv[x]+1;
            init(y,x);
        }
    }
}
struct data{
    int st,ed,id;
    data(int _st=0,int _ed=0,int _id=0):st(_st),ed(_ed),id(_id){}
};
vector<data>qq[TRAD];
int adv(int x,int v){
    for(int i=0;(1<<i)<=v;i++){
        if((v>>i)&1)x=jump[i][x];
    }
    return x;
}
int lca(int x,int y){
    if(lv[x]>lv[y])x=adv(x,lv[x]-lv[y]);
    else y=adv(y,lv[y]-lv[x]);
    if(x==y)return x;
    for(int i=17;i>=0;i--)
        if(jump[i][x]!=jump[i][y]){x=jump[i][x];y=jump[i][y];}
    return jump[0][x];
}
void get(int x,int mm,int P,int& t,int& r){
    t=0;
    while(lv[x]-lv[mm]>=P){
        x=adv(x,P-1);
        t++;
        if(jump[0][x]<=N)x=jump[0][x];
    }
    r=lv[x]-lv[mm];
}
int main(){
    RI(N);
    int id=N+1;
    REPP(i,1,N){
        DRIII(x,y,v);
        if(v==1){
            e[x].PB(y);
            e[y].PB(x);
        }
        else{
            e[x].PB(id);
            e[y].PB(id);
            e[id].PB(x);
            e[id].PB(y);
            id++;
        }
    }
    init(1,1);
    REPP(i,1,18){
        REPP(x,1,id)
            jump[i][x]=jump[i-1][jump[i-1][x]];
    }
    DRI(M);
    REP(i,M){
        DRIII(S,F,P);
        if(P>=TRAD){
            int mm=lca(S,F);
            int t1,r1,t2,r2;
            get(S,mm,P,t1,r1);
            get(F,mm,P,t2,r2);
            an[i]=t1+t2+(r1+r2+P-1)/P;
        }
        else{
            qq[P].PB(data(S,F,i));
        }
    }
    REPP(i,1,N+1){
        step[0][i]=i;
        step[1][i]=jump[0][i];
    }
    REPP(i,2,TRAD){
        REPP(j,1,N+1){
            step[0][j]=step[1][j];
            step[1][j]=jump[0][step[1][j]];
        }
        if(SZ(qq[i])<20){
            REP(j,SZ(qq[i])){
                int S=qq[i][j].st;
                int F=qq[i][j].ed;
                int mm=lca(S,F);
                int t1,r1,t2,r2;
                get(S,mm,i,t1,r1);
                get(F,mm,i,t2,r2);
                an[qq[i][j].id]=t1+t2+(r1+r2+i-1)/i;
            }
        }
        else{
            REPP(j,1,N+1){
                if(step[1][j]<=N)super[0][j]=step[1][j];
                else super[0][j]=step[0][j];
            }
            REPP(j,1,18){
                REPP(x,1,N+1)super[j][x]=super[j-1][super[j-1][x]];
            }
            REP(j,SZ(qq[i])){
                int S=qq[i][j].st;
                int F=qq[i][j].ed;
                int mm=lca(S,F);
                int t1=0,r1,t2=0,r2;
                for(int k=17;k>=0;k--){
                    if(lv[super[k][S]]>lv[mm]){
                        S=super[k][S];
                        t1+=1<<k;
                    }
                }
                r1=lv[S]-lv[mm];
                for(int k=17;k>=0;k--){
                    if(lv[super[k][F]]>lv[mm]){
                        F=super[k][F];
                        t2+=1<<k;
                    }
                }
                r2=lv[F]-lv[mm];
                an[qq[i][j].id]=t1+t2+(r1+r2+i-1)/i;
            }
        }
    }
    REP(i,M)printf("%d\n",an[i]);
    return 0;
}
