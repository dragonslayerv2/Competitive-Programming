+/*
+	Name: Sliding Window Maximum
+	Copyright: 
+	Author: Shobhit Saxena
+	Date: 19/01/14 21:09
+	Description: This code stores the maximum value of the sliding window.
+				Uses double ended queue so the overall runtime is O(n) in worst case
+*/
 
 #include<iostream>
 #include<queue>
 using namespace std;
 
 void sliding_window(vector<int> &A,size_t w, vector<int> &B)
 {
 	deque<int> Q;
 	for(int i=0;i<min(A.size(),w);i++)
 	{
 		while(!Q.empty()&&A[Q.back()]<=A[i])
 			Q.pop_back();
 		Q.push_back(i);
 	}
 	for(int i=w;i<A.size();i++)
 	{
 		B.push_back(A[Q.front()]);
 		while(!Q.empty()&&Q.front()<=i-w)
 			Q.pop_front();
 		while(!Q.empty()&&A[Q.back()]<=A[i])
 			Q.pop_back();	
 		Q.push_back(i);
 	}
 	B.push_back(A[Q.front()]);
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

