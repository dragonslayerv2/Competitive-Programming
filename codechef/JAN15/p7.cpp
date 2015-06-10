#include<cstdio>
using namespace std;


struct query{
	int id,type,l,r,x;
	query(int id,int type,int l,int r,int x){
		
	}
};


int a[1000000];
query ansQueries[1000000];
query insertionQueries[1000000];
int main(){
	int t;
	scanf("%d",&t);
	int aQCount=0,iQCount=0;
	for(int i=0;i<t;i++){
		int type;
		cin>>type;
		switch(type){
			case 0:{
					int x;
					cin>>x;
					insertionQueries[iQCount]=query(i,type,0,0,x);
					break;
				}
			case 1:
					break;
			case 2:
					break;
			case 3:
					break;
			case 4:
					break;
				
		}
	}
}
