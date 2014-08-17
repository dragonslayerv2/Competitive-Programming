#include<stdio.h>
#include<assert.h>
#include<vector>
#include<map>
#include<list>
#include<algorithm>
using namespace std;

class splayNode
{
	public:
		
		splayNode *left,*right,*parent;
		
		int id;
		
		long long lazyValue;
		int childCount;
		long long childSum;
		long long myValue;
		
		splayNode(int ID=-1,long long MYVALUE=0)
		{
			left=right=parent=NULL;
			id=ID;
			childCount=1;
			lazyValue=childSum=0;	
			myValue=MYVALUE;
		}
		
		void acceptLazy(long long lazy)
		{
			myValue+=lazy;
			childSum+=lazy*(childCount);
			lazyValue+=lazy;
		}
		void pushLazy()
		{
			if(left)
				left->acceptLazy(lazyValue);
			if(right)
				right->acceptLazy(lazyValue);
			update();
			
			lazyValue=0;
		}
		
		void update()
		{
			childCount=1;
			childSum=myValue;
			if(left)
			{
				childCount+=left->childCount;
				childSum+=left->childSum;
			}
			if(right)
			{
				childCount+=right->childCount;
				childSum+=right->childSum;
			}
		}
		
		void rotateLeft()
		{
			splayNode *x=this;
			
			x->pushLazy();
			if(x->left)
				x->left->pushLazy();
			if(x->right)
				x->right->pushLazy();
			
			splayNode *y=x->right;
			x->right=y->left;
			
			if(y->left)
				y->left->parent=x;
			
			y->parent=x->parent;
			if(y->parent)
			{	
				 if(x==x->parent->left)
					x->parent->left=y;
			 	 else
					x->parent->right=y;
			}
			y->left=x;	
			x->parent=y;
			
			x->update();
			y->update();
			
		}
		
		void rotateRight()
		{
			splayNode *x=this;
			
			x->pushLazy();
			if(x->left)
				x->left->pushLazy();
			if(x->right)
				x->right->pushLazy();
				
			splayNode *y=x->left;
			x->left=y->right;
			if(y->right)
				y->right->parent=x;
			y->parent=x->parent;
			if(y->parent)
			{	
				if(x==x->parent->left)
					x->parent->left=y;
				else
					x->parent->right=y;
			}
			y->right=x;	
			x->parent=y;	
			
			x->update();
			y->update();
		}
		void splay()
		{
			splayNode *current=this;
			while(1)
			{
				splayNode *parent=current->parent;
				if(!parent) break;
				
				splayNode *grandparent=parent->parent;
			
				if(!grandparent) 
				{
					if(current==parent->left)	parent->rotateRight();
					else if(current==parent->right)	parent->rotateLeft();
				}
				
				else if(parent==grandparent->left && current==parent->left)
				{
					grandparent->rotateRight();
					parent->rotateRight();	
				}

				else if( parent==grandparent->right && current==parent->right)
				{	
					grandparent->rotateLeft();
					parent->rotateLeft();	
				}
				
				else if(parent==grandparent->left && current==parent->right) 
				{
					parent->rotateLeft();
					grandparent->rotateRight();
				}
				else if(parent==grandparent->right && current==parent->left) 
				{
					parent->rotateRight();
					grandparent->rotateLeft();
				}
			}
		}
		void splayDown()
		{
			while(1)
			{
				if(left)
					rotateRight();
				else if(right)
					rotateLeft();
				else
					break;	
			}
		}
		
		void remove()
		{
			splayDown();

			splayNode *P=parent;
			long long pathLazy=0;
			while(P)
			{
				pathLazy+=P->lazyValue;
				P->childCount--;
				P->childSum-=myValue+pathLazy;
				P=P->parent;
			}
			
			if(this==this->parent->left)
				this->parent->left=NULL;
			else
				this->parent->right=NULL;
		}
		bool isRoot() const
		{
			return (parent==NULL);
		}
		
		void addSuccessor(splayNode *S)
		{
			S->splay();
			splay();
	
			pushLazy(); // only for exception cases, if any
			
			if(!right)
			{
				right=S;
				S->parent=this;
			}
			else
			{
				splayNode *current=right;
				while(current->left)
				{
					current->pushLazy();
					current=current->left;
				}
				current->pushLazy();
				current->left=S;
				S->parent=current;
				
			}

			splayNode *current=S;
			while(current)
			{
				current->update();
				current=current->parent;
			}
			S->splay();
		}	
};

vector<splayNode *> sNode;
vector<splayNode *> eNode;
vector<bool> alreadyDeleted;
vector<list<int> > tree;

void removeAll(int key)
{
	if(alreadyDeleted[key])
		return;
	for(list<int>::iterator i=tree[key].begin();i!=tree[key].end();i++)
		removeAll(*i);
	sNode[key]->remove();
	eNode[key]->remove();
	delete sNode[key];
	delete eNode[key];
	alreadyDeleted[key]=true;
	tree[key]=list<int>();
}

int main()
{
//	freopen("in_sigsev.txt","r",stdin);
	int n;
	scanf("%d",&n);
	
	sNode.resize(n);
	eNode.resize(n);
	alreadyDeleted.resize(n,false);
	tree.resize(200500);
	
	for(int i=0;i<n;i++)
	{
		int value;
		scanf("%d",&value);
		sNode[i]=new splayNode(i,value);
		eNode[i]=new splayNode(i,value);
		sNode[i]->addSuccessor(eNode[i]);
	}

	for(int i=0;i<n-1;i++)
	{
		int parent,child;
		scanf("%d %d",&parent,&child);
		
		tree[parent].push_back(child);
		
		sNode[parent]->addSuccessor(sNode[child]);
	}

	int m;
	scanf("%d",&m);
	
	long long SPECIAL=0;
	
	while(m--)
	{
		int type;
		scanf("%d",&type);
		
		
		long long key;
		scanf("%lld",&key);
		//cout<<"Type = "<<type<<" Key = "<<key;
	//	cout<<endl;
		key=SPECIAL+key;
		
		
		if(type==1||type==2)
		{
			long long value;
			scanf("%lld",&value);
	//		if(alreadyDeleted[key]) continue;
	//		cout<<"Value = "<<value<<endl;
			if(type==1)
			{
				
				int childKey=sNode.size();
				
				tree[key].push_back(childKey);
				alreadyDeleted.push_back(false);
				
				sNode.push_back(new splayNode(childKey,value));
				eNode.push_back(new splayNode(childKey,value));
				sNode.back()->addSuccessor(eNode.back());
				sNode[key]->addSuccessor(sNode.back());	
			}
			if(type==2)
			{
				eNode[key]->splay();
				sNode[key]->splay();
				if(eNode[key]->parent!=sNode[key])
				{
					if(eNode[key]->parent->right)
						eNode[key]->parent->rotateLeft();
					else
						eNode[key]->parent->rotateRight();
				}
				assert(eNode[key]->parent==sNode[key]);
				
				eNode[key]->myValue+=value;
				if(eNode[key]->left)
					eNode[key]->left->acceptLazy(value);
				eNode[key]->update();
				sNode[key]->myValue+=value;
				sNode[key]->update();
			}
		}
		else
		{
			if(alreadyDeleted[key]) continue;
			if(type==3)
				removeAll(key);
				
			else if(type==4)
			{
				eNode[key]->splay();
				sNode[key]->splay();
				if(eNode[key]->parent!=sNode[key])
				{
					if(eNode[key]->parent->right)
						eNode[key]->parent->rotateLeft();
					else
						eNode[key]->parent->rotateRight();
				}
				assert(eNode[key]->parent==sNode[key]);
				sNode[key]->pushLazy();
				eNode[key]->pushLazy();
				long long summation=sNode[key]->myValue+eNode[key]->myValue;
				if(eNode[key]->left)
					summation+=eNode[key]->left->childSum;
				summation/=2;	
				
				SPECIAL=summation;
//				cout<<"Solution = "<<summation<<endl;
				printf("%lld\n",summation);
			}
		}
		
	}
}
