 #include<iostream>
 #include<cmath>
 using namespace std;
 
 int main()
 {
 	long long a,b,w,x,c;
 	cin>>a>>b>>w>>x>>c;
 	long long p=0;
 	if(a<c)
 		p=ceil((double(a-c)*w+b)/(x-w));
 	cout<<p;
 }

