#include<iostream>
using namespace std;

class ChristmasTreeDecorationDiv2{
	int solve(vector <int> col, vector <int> x, vector <int> y){
		int beautiful=0;
		for(int i=0;i<x.size();i++){
			if(col[x[i]-1]!=col[y[i]-1])
				beautiful++;
		}
		return beautiful;
	}
};
int main(){

}
