#include<bits/stdc++.h>
using namespace std;
int main(){
	srand(time(NULL));
	int n = 1+rand()%100;
 	cout<<n<<endl;
 	int i,j;
  	for(i=0;i<n;i++)
   	{
	   	for(j=0;j<n;j++)
     	{
		 	int k=rand()%2;
      		if(k)
       	 		cout<<"x";
    		else 
				cout<<"o";
     	}
     	cout<<endl;
   }
 }
