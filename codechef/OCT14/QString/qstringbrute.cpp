//PROBLEM : QSTRING (BRUTE SOLUTION)
#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("in.txt","r",stdin);
    string S;
    cin>>S;
    vector<pair<string,int> > substrings;
    substrings.push_back(make_pair("",-1));
    for(int i=0;i<S.length();i++){
        for(int j=0;j<=S.length()-i;j++){
            string temp=S.substr(i,j);
            if(temp.length()!=0)
            substrings.push_back(make_pair(S.substr(i,j),i));
        }
    }
    sort(substrings.begin(),substrings.end());
    
    /*for(vector<pair<string,int> >::iterator i=substrings.begin();i!=substrings.end();i++){
        cout<<i->first<<" "<<i->second<<"\n";
    }*/
    
    
    int queries;
    cin>>queries;
    while(queries--){
        string type;
        cin>>type;
    
        if(type=="Select"){
            int k1,k2;
            cin>>k1>>k2;
                set<pair<int,int> > stringsK1;
                set<pair<int,int> > stringsK2;
                set<string> distincts;
            for(int i=0;i<S.length();i++){
                for(int j=i;j<S.length();j++){
                    distincts.clear();
                    string str=S.substr(i,j-i+1);
                    //cout<<"LOOKING FOR STRING "<<str<<" = > "<<i<<" "<<j<<"\n";
                    int count=0;
                    for(vector<pair<string,int> >::iterator ii=substrings.begin();ii!=substrings.end();ii++){
                    
                        if(ii->first==str)
                        break;
                        if(distincts.find(ii->first)==distincts.end()){
                            //cout<<"FINDING "<<ii->first<<"\n";
                            distincts.insert(ii->first);
                            count++;
                        }
                    
                        
                    }
                    //cout<<"CALACULATE K1 FOR STRING = "<<count<<"\n";
                    if(count==k1)
                    stringsK1.insert(make_pair(i,j));
                    
                    
                    int count2=0;
                    for(vector<pair<string,int> >::iterator ii=substrings.begin();ii!=substrings.end();ii++){
                        if(ii->first==str && ii->second<i)
                        count2++;
                    }
                    //cout<<"CALCULATING K2 FOR STRING = "<<count2<<"\n";
                    if((count2+1)==k2){
                        stringsK2.insert(make_pair(i,j));
                    }
                    
                }
                
            }
            vector<pair<int,int> > ans;
            for(set<pair<int,int> >::iterator ii=stringsK1.begin();ii!=stringsK1.end();ii++){
                for(set<pair<int,int> >::iterator jj=stringsK2.begin();jj!=stringsK2.end();jj++){
                    if(ii->first==jj->first && ii->second == jj->second)
                    ans.push_back(make_pair(ii->first+1,ii->second+1));
                }    
            }
            
            for(vector<pair<int,int> >::iterator ii=ans.begin();ii!=ans.end();ii++){
                cout<<ii->first<<" "<<ii->second<<"\n";
            }
            
            
        }
        else if(type=="Rank"){
            int L,R;
            cin>>L>>R;
            L--;
            R--;
            string str=S.substr(L,R-L+1);
            //cout<<str;
            int count=0;
            int count2=0;
            set<string> distincts;
            for(vector<pair<string,int> >::iterator i=substrings.begin();i!=substrings.end();i++){
				if(i->first==str)
                break;
                if(distincts.find(i->first)==distincts.end()){
                    //cout<<"FINDING "<<i->first<<"\n";
                    distincts.insert(i->first);
                    count++;
                }
            }
            cout<<count<<" ";//ADD 1 FOR NULL STRING
            
            for(vector<pair<string,int> >::iterator i=substrings.begin();i!=substrings.end();i++){
                if(i->first==str && i->second<=L)
                count2++;
            }
            cout<<count2<<"\n";
            
            
        }
    }
}

