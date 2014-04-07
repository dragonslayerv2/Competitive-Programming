#include<iostream>
#include<set>
#include<time.h>
#include<stdlib.h>
using namespace std;

#define OUTPUTFILENAME "test5.txt"
#define KMAX 100
#define SMAX 100
#define SIMAX 1000
#define KIMAX 1000
#define QMAX 10000
#define NMAX 100000
int main()
{
	freopen(OUTPUTFILENAME,"w",stdout);
	srand(time(NULL));
	int Ksize=1+rand()%KMAX;
	int Ssize=1+rand()%SMAX;
	cout<<Ksize<<" "<<Ssize<<endl;
	set<int> K,S;
	while(K.size()!=Ksize)
		K.insert(1+rand()%KIMAX);
	for(set<int>::iterator i=K.begin();i!=K.end();i++)
		cout<<*i<<" ";
	cout<<endl;
	
	while(S.size()!=Ssize)
		S.insert(1+rand()%SIMAX);
	for(set<int>::iterator i=S.begin();i!=S.end();i++)
		cout<<*i<<" ";
	cout<<endl;
	
	int q=QMAX;
	cout<<q<<endl;
	while(q--)
		cout<<1+rand()%NMAX<<" "<<((rand()%2)?"K":"S")<<endl;
	
}
