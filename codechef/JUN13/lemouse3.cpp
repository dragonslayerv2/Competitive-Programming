#include<iostream>
#include<climits>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;


bool ispossible(int path,int n,int m)
{
	int count=0;
	while(path)
	{
		if(path&1)
			count++;
		path=path>>1;
	}
	if(count==n-1) return true;
	else return false;
}

int brute(char a[200][200],int n,int m)
{
	int maxpath=1<<((n-1)+(m-1));
	
	
	
	//cout<<"Max paths = "<<maxpath<<endl;
	
	int minmouse=INT_MAX;
	for(int i=0;i<maxpath;i++)
	{
		map<int,bool> mouses;
		if(ispossible(i,n,m))
		{
		//	cout<<"Got a possible path = "<<i<<endl;
			
			int path=i;
			int posi=0;
			int posj=0;
			
			if((posi-1>=0)&&(a[posi-1][posj]=='1'))
				mouses[(posi-1)*1000+posj]=true;
			if((posi+1<n)&&(a[posi+1][posj]=='1'))
				mouses[(posi+1)*1000+posj]=true;
			
			if((posj-1>=0)&&(a[posi][posj-1]=='1'))
				mouses[(posi)*1000+posj-1]=true;
			if((posj+1<m)&&(a[posi][posj+1]=='1'))
				mouses[(posi)*1000+posj+1]=true;	
			if(a[posi][posj]=='1')
				mouses[(posi)*1000+posj]=true;
		//		cout<<"At pos "<<posi<<","<<posj<<endl;
			
			while((posi!=n-1)||(posj!=m-1))
			{
				
					if(a[posi][posj]=='1')
				mouses[(posi)*1000+posj]=true;
				if(path&1)
					posi++;
				else
					posj++;
				if((posi-1>=0)&&(a[posi-1][posj]=='1'))
					mouses[(posi-1)*1000+posj]=true;
				if((posi+1<n)&&(a[posi+1][posj]=='1'))
					mouses[(posi+1)*1000+posj]=true;
			
				if((posj-1>=0)&&(a[posi][posj-1]=='1'))
					mouses[(posi)*1000+posj-1]=true;
				if((posj+1<m)&&(a[posi][posj+1]=='1'))
					mouses[(posi)*1000+posj+1]=true;
				if(a[posi][posj]=='1')
					mouses[(posi)*1000+posj]=true;
				path=path>>1;	
		//		cout<<"At pos "<<posi<<","<<posj<<endl;
			}
		//	cout<<"Mouses = "<<mouses.size()<<endl;
		
			minmouse=min((int)mouses.size(),minmouse);
		}	
		
	}
	return minmouse;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		char a[200][200];
		
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				cin>>a[i][j];
		
		cout<<brute(a,n,m)<<endl;
			
	}	
}
