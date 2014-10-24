#include<iostream>
#include<vector>
using namespace std;

class GreaterGameDiv2{
	int calc(vector <int> snuke, vector <int> sothe){
		int count=0;
		for(int i=0;i<snuke.size();i++)
			count+=(snuke[i]>sothe[i]);
		return count;
	}
};
int main(){
	
	
}
