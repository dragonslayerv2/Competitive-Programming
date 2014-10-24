#include<bits/stdc++.h>
using namespace std;

vector<int> lookup(1000001,-1);
int  a[1000001]={0};
int prime[1000005];
int p=1;
vector<vector<int> > factors(1000001);
void generate(int y)
    {int i,j;
     prime[0]=2;
	 for(i=3;i*i<=y;i+=2)
        {if(a[i])
          continue;
         prime[p++]=i;
		for(j=i*i;j<=y;j+=2*i)
           {a[j]=1;
            factors[j].push_back(i);
           }
        }
        for(i;i<=y;i+=2)
          if(!a[i])
            {
            prime[p++]=i;
            
            }
    }
    

	
int main()
 {//freopen("in.txt","r",stdin);
 //cout<<"ok";
 	generate(1000000);
 //	 cout<<"ok";
 	vector<int> a(100005);
 	
 	int t,n,i,j;
 	scanf("%d",&t);
 	while(t--)
		 {scanf("%d",&n);
		 
		 	for(i=0;i<p;i++)
		 	  lookup[prime[i]]=-1;
		 	
		 	for(i=0;i<n;i++)
		 	  scanf("%d",&a[i]);
		     
		     if(a[0]%2==0)
		       {
		       	lookup[2]=0;
		       	while(a[0]%2==0)
		       	  a[0]/=2;
		       }
		    if(factors[a[0]].empty())
		      {
		      	if(a[0]!=1)
		      	  lookup[a[0]]=0;
		      }
		    else
		     {int copy=a[0];
		     
		    for(vector<int>::iterator it=factors[a[0]].begin();it!=factors[a[0]].end();it++)
		      {
		      	while(copy%(*it)==0)
		      	  copy/=(*it);
		      	lookup[*it]=0;
		      	 
		      }
		     
		  	  if(copy!=1)
		 	    lookup[copy]=0;
		 	}
		 	  
		 	int ans=1;
		 	int last=0;
		 	for(j=1;j<n;j++)
		 	 {  
		 	 	ans=max(ans,j-last);
		 	 //divide by 2
		 	 		if(a[j]%2==0)
		 	 		  {if(lookup[2]!=-1)
		      			    		last=max(last,lookup[2]+1);
		      			    lookup[2]=j;
		 	 		  	while(a[j]%2==0)
		 	 		  	  a[j]/=2;
		 	 		  }
		 	 	if(factors[a[j]].empty())
		     		 {
		      			if(a[j]!=1)
		      			  { if(lookup[a[j]]!=-1)
		      			    		last=max(last,lookup[a[j]]+1);
		      			    lookup[a[j]]=j;
		      			  }
		      	 		 
		      		}
		    	else
		     		{int copy=a[j];
		             
		    		for(vector<int>::iterator it=factors[a[j]].begin();it!=factors[a[j]].end();it++)
		    			  {
		    			  	while(copy%(*it)==0)
		      	 			 		copy/=(*it);
		      	 			if(lookup[*it]!=-1)
		      			    		last=max(last,lookup[*it]+1);
		      				lookup[*it]=j;
		      	 
		      			}
		     
		  	  		if(copy!=1)
		 	   			 {if(lookup[copy]!=-1)
		 	  	  			   {
									last=max(last,lookup[copy]+1);
		 	  	  			   }
		 	  	  		 lookup[copy]=j;
		 	  			
		 	  	  		}
		 			}	
		 	 	
		 	
		 	        
		 	      
		 	  	  		
		 	            
		 	    
		 	    	
		    }
		    	ans=max(ans,j-last);
		 	 if(ans>1)
		 	 	printf("%d\n",ans);
		 	 else puts("-1");
	     }
 	
 }
