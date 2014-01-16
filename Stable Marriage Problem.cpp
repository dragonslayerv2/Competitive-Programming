/*
	Name: Stable Marriagle Problem. 
	Copyright: 
	Author: Shobhit Saxena
	Date: 28/12/13 09:43
	Description: This is designed in a way asked in question 
					http://www.codechef.com/STABLEMP
*/

#include<iostream>
#include<vector>
using namespace std;


class person
{
	private:
		int engaged; // 0 means unengaged
		vector<int> preferenceList; // what is preference number i..??
		vector<int> choice; // which choice is person number i..??
	public:
		person()
		{ engaged=0;}
		person(int n)
		{
			engaged=0;
			resize(n);
		}
		void resize(int n)
		{
			preferenceList.resize(n);
			choice.resize(n);
		}
		
		int engagedTo()
		{
			return engaged;
		}
		
		int choicenumber(int person)
		{
			return choice[person];
		}
		
		int preference(int ch)
		{
			return preferenceList[ch];
		}
		
		void makepreference(int per,int ch)
		{
			preferenceList[ch]=per;
			choice[per]=ch;
		}
		void engageWith(int per)
		{
			engaged=per;
		}
};

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		vector<person> man(n+1,person(n+1));
		vector<person> woman(n+1,person(n+1));
		
		//woman preference list 
		for(int i=1;i<=n;i++)
		{
			int x;
			cin>>x;
			for(int j=1;j<=n;j++)
			{
				int number;
				cin>>number;
				woman[x].makepreference(number,j);
			}
		}
		
		//man preference list 
		for(int i=1;i<=n;i++)
		{
			int x;
			cin>>x;
			for(int j=1;j<=n;j++)
			{
				int number;
				cin>>number;
				man[x].makepreference(number,j);
			}
		}
		
		vector<int> lastproposed(n+1);
		int unengaged=n;
		while(unengaged)
		{
			for(int i=1;i<=n;i++)
			{
				if(!man[i].engagedTo())
				{	
					person &currentman=man[i];		
					int choice=currentman.preference(++lastproposed[i]);
					person &selectedwoman=woman[choice];
					
				//	cout<<"Man number "<<i<<"Proposing to "<<choice<<". ";
					if(!selectedwoman.engagedTo())
					{
						//cout<<" Woman Unengaged. Engaging"<<endl;
						currentman.engageWith(choice);
						selectedwoman.engageWith(i);
						unengaged--;
					}
					else
					{
						//cout<<" Woman engaged";
						if(selectedwoman.choicenumber(i)<selectedwoman.choicenumber(selectedwoman.engagedTo()))
						{
						//	cout<<"Got a better choice. Engaging"<<endl;
							man[selectedwoman.engagedTo()].engageWith(0);
							currentman.engageWith(choice);
							selectedwoman.engageWith(i);
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			cout<<i<<" "<<man[i].engagedTo()<<endl;
		}
		
	}
}
