#include<iostream>
#include<vector>
using namespace std;

int rows[]={0,0,3,3};
void config()
{
	cout<<rows[0]<<" "<<rows[1]<<" "<<rows[2]<<" "<<rows[3]<<endl;
}
bool recurse(int turn,int count)
{
	//cout<<"Player "<<turn<<" turn" << "Remaining = "<<count<<endl;
	if(count==1)
	{//	cout<<"I lose";
		return false;
	}
		
	else
	{
	//	cout<<"trying... "<<endl;
		//cout<<"Got config"<<endl;
		//config();
		for(int i=0;i<4;i++)
		{
			
			for(int j=1;j<=rows[i];j++)
			{
				rows[i]-=j;
				
				if(count-j>0)
				{
				//	cout<<"Making a move"<< i<<" "<<j<<endl;
				//	cout<<"Config"<<" ";config();
					if(recurse(turn*-1,count-j)==false)	
					{
					//	cout<<"I won";
						if(turn==1)
						{
		//					cout<<i+1<<" "<<j<<endl;
		//					cin.get();
						}
							
							
						rows[i]+=j;
						return true;
					}
				}
		//		cout<<"Resetting ";
				rows[i]+=j;
			//	config();
				
			}
		}
	//	cout<<"I lose";
		return false;
	}
}/*
int init(int number)
{
	rows.clear();
	int sum=0;
	for(int i=1;i<=number;i++)
	{
		rows.push_back(2*i-1);
		sum+=2*i-1;
	}
	return sum;
}*/
int main()
{
	for(int i=0;i<=1;i++)
	{
		for(int j=0;j<=3;j++)
		{
			for(int k=0;k<=5;k++)
			{
				for(int l=0;l<=7;l++)
				{
					rows[0]=i;
					rows[1]=j;
					rows[2]=k;
					rows[3]=l;
					if(recurse(1,rows[0]+rows[1]+rows[2]+rows[3]))
					{
						cout<<i<<j<<k<<l<<endl;
					}
				}
			}
		}
	}
	
	
}
