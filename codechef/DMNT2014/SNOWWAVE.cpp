#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<cstdio>
#include<cstring>

using namespace std;


#define MAXN 1000000

set<int> s;
map<int,int> m;
bool valid[MAXN] = {false};
int BIT[MAXN] = {0}, a[MAXN] = {0};


int query(int i){
    int ret = 0;
    while(i > 0){
        ret = max(ret, BIT[i]);
        i -= (i & (-i));
    }
    return ret;
}

void update(int i, int v){
    while(i < MAXN){
        BIT[i] = max(BIT[i], v);
        i += (i & (-i));
    }
}

int main()
{
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        a[i] -= i;
        if(a[i] >= 0){
            valid[i] = true;
            s.insert(a[i]);
        }
        else{
            valid[i] = false;
        }
    }
    int i = 1;
    for(set<int>::iterator it = s.begin(); it != s.end(); it++){
        m[*it] = i;
        i++;
    }
    for(i = 1; i <= n; i++){
        if(valid[i] == true){
            a[i] = m[a[i]];
        }
    }
    for(i = 1; i <= n; i++){
        if(valid[i] == true){
            update(a[i], query(a[i]) + 1);
        }
    }
    cout<<n - query(MAXN - 1)<<endl;
  
}

