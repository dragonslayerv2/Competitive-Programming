+/*
+	Name: Sliding Window Maximum
+	Copyright: 
+	Author: Shobhit Saxena
+	Date: 19/01/14 21:09
+	Description: This code stores the maximum value of the sliding window.
+				Uses heaps so the overall runtime is O(nlog w) in worst case
+*/
 
 #include<iostream>
 #include<queue>
 using namespace std;
 
 void sliding_window(vector<int> &A,size_t w, vector<int> &B)
 {
 	priority_queue<pair<int,int> > Q;
 	for(int i=0;i<min(A.size(),w);i++)
 		Q.push(make_pair(A[i],i));
 	for(int i=w;i<A.size();i++)
	  {
  		B.push_back(Q.top().first);
  		while(Q.top().second<=i-w)
 			Q.pop();
 		Q.push(make_pair(A[i],i));
 	}
 	B.push_back(Q.top().first); // for the last element
 }
 int main()
 {
 	int n,w;
 	cin>>n>>w;
  
 	vector<int> array(n);
 	for(int i=0;i<n;i++)
 		cin>>array[i];
 	
 	vector<int> solution;
 	sliding_window(array,w,solution);
	for(int i=0;i<solution.size();i++)
		cout<<solution[i]<<" ";
		
}

