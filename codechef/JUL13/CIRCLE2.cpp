#include<iostream>
#include<utility>
#include<algorithm>
#include<vector>
using namespace std;

ostream & operator <<(ostream &stream,pair<int,int> a)
{
	cout<<"("<<a.first<<", "<<a.second<<")";
	return stream;
}
//------------------------------------------------------------------------------
const int MAXSIZE=3;
int det(int a[][MAXSIZE],int n)
{
	int ans=0;
	
	int row=0,col=0;
	
	for(int k=0;k<n;k++)
	{
		int i=row;
		int j=col;
		int product=1;

		while(i<n)
		{

			product*=a[i][j];
			i++;
			j++;
			j%=n;
		}
		ans+=product;	

		col++;
	}
	
	row=col=0;
	
	for(int k=0;k<n;k++)
	{
		int i=row;
		int j=col;
		int product=1;

		while(i<n)
		{

			product*=a[i][j];
			i++;
			j--;
			j=(j+n)%n;
		}
		ans-=product;	
		col++;
	}
	
	return ans;
}
//------------------------------------------------------------------------------

typedef pair<int,int> point;
#define COL 0
#define NEG -1
#define POS +1
int check(point p1,point p2,point p3)
{
	int area=p1.first*(p2.second-p3.second)+p2.first*(p3.second-p1.second)+p3.first*(p1.second-p2.second);
	if(area==0) return COL;
	else if(area<0) return NEG;
	else return POS;
}
//------------------------------------------------------------------------------

bool inside(point c1,point c2,point c3, point d)
{
	int val=check(c1,c2,c3);
	
	/*int mat[4][4]={{d.first*d.first+d.second*d.second    ,  d.first,  d.second,1},
				   {c1.first*c1.first+c1.second*c1.second,  c1.first,c1.second,1},
				   {c2.first*c2.first+c2.second*c2.second,  c2.first,c2.second,1},
				   {c3.first*c3.first+c3.second*c3.second,  c3.first,c3.second,1}};*/
	
	
	int mat[3][3]={{d.first*d.first+d.second*d.second-c1.first*c1.first-c1.second*c1.second   ,  d.first-c1.first,  d.second-c1.second},
				   {c1.first*c1.first+c1.second*c1.second-c2.first*c2.first-c2.second*c2.second,  c1.first-c2.first,c1.second-c2.second},
				   {c2.first*c2.first+c2.second*c2.second-c3.first*c3.first-c3.second*c3.second,  c2.first-c3.first,c2.second-c3.second},
				 };
	
	
	
	int deter=det(mat,3);
	if((val<0&&deter>=0)||(val>0&&deter<=0))
	{
		/*for(int i=0;i<4;i++)
		{
			for(int j=0;j<4;j++)
			{
				cout<<mat[i][j]<<"\t";
			}
			cout<<endl;
		}
		*/
		
		//cout<<c1<<c2<<c3<<d<<"\t"<<val<<"\t"<<deter<<"\t";
		return true;
	}
		
	else return false;
}
//------------------------------------------------------------------------------
int C(int n,int r)
{
	int c=1;
	for(int i=r+1;i<=n;i++)
		c*=i;
	
	for(int i=1;i<=n-r;i++)
		c/=i;
	return c;
}

int main()
{

	int t;
	cin>>t;
	vector<point > points;
	while(t--)
	{
		points.clear();
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			int x,y;
			cin>>x>>y;
			points.push_back(make_pair(x,y));
		}
		
		int in_count=0;
		int tot_count=0;
		for(int i=0;i<n-2;i++)
		{
			for(int j=i+1;j<n-1;j++)
			{
				for(int k=j+1;k<n;k++)
				{
					for(int l=0;l<n;l++)
					{
						if(l!=i&&l!=j&&l!=k)
						{tot_count++;
							if(check(points[i],points[j],points[k])!=COL)
							{
								
								//cout<<endl<<points[i]<<" "<<points[j]<<" "<<points[k]<<" "<<points[l];
								if(inside(points[i],points[j],points[k],points[l]))
								{
									//cout<<"S\n";
									in_count++;
									
								}
							}
						}
					}
				}
			}
		}
		//cout<<in_count<<endl;
		//cout<<C(n,3)*(n-3)<<endl;
		
		//cout<<((double)in_count)/(C(n,3)*(n-3))<<endl;		
		cout<<((double)in_count)/tot_count<<endl;		
	}
	return 0;
}
