//Merge Sort implmentation has been taken from GeeksforGeeks
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cmath>
#include <climits>
#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <queue>
#include <algorithm>
#include <limits>
#include <bitset>
using namespace std;

//Shorthands
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef long long ll;
#define sd(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define For(i, j, k) for (int i = j; i <= k; i++)
#define Ford(i, j, k) for (int i = j; i >= k; i--)
#define sz(a) int((a).size())
#define rsz resize
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(auto i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define abs(x) (((x) > 0) ? (x) : (-(x)))

//DEBUG
#define trace1(x) cerr << #x << ": " << x << endl;
#define trace2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z) cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;

void input()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE
}

void output()
{
    #ifndef ONLINE_JUDGE
        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
}

#define MOD 1000000007

void cpy(int A[], int B[], int l, int u)
{
	for (int i = l; i <= u; i++)
		A[i] = B[i];
	return;
}

ll mergesort(int A[], int B[], int l, int u)
{
	if (l == u)
		return 0;
	int mid = (l + u)/2;
	ll invlft = mergesort(A, B, l, mid);
	ll invrght = mergesort(A, B, mid + 1 , u);

	int lft = l,  rght =  mid + 1;

	ll invmerge = 0;

	for(int i = l; i <= u; i++)
		if (lft <= mid && (rght > u  || A[lft] <= A[rght]))
			B[i] = A[lft++];
		else {
			B[i] = A[rght++];
		invmerge += ((mid - lft) + 1);
	}
	cpy(A, B, l, u);
	return invlft + invrght + invmerge;
}

template <typename value_type> class SegTree {
    vector<vector<value_type> > segtree;
    int range;
    value_type def;

    bool IN(int i, int j, int x, int y)
    {
        return (i >= x && j <= y)? 1: 0;
    }
    bool OUT(int i, int j, int x, int y)
    {
        return (j < x || i > y)? 1: 0;
    }
    void merge_sorted(int current, int left, int right)
    {
        int left_size = segtree[left].size();
        int right_size = segtree[right].size();
        int i = 0, j = 0;
        while (i < left_size || j < right_size) {
            if (j >= right_size || (i < left_size && segtree[left][i] < segtree[right][j])) {
                segtree[current].push_back(segtree[left][i]);
                i++;
            } else {
                segtree[current].push_back(segtree[right][j]);
                j++;
            }
        }
    }

    void _construct(int node, int ll, int ul, vector<value_type> &array)
    {
        if (ll == ul) {// demarc that this is a leaf node
            segtree[node].push_back(array[ll]);
            return;
        } else {
            _construct(node*2+1, ll, (ll + ul) / 2, array);
            _construct(node*2+2, (ll + ul) / 2 + 1, ul, array);
            merge_sorted(node, node * 2 + 1, node * 2 + 2);
        }
    }

    ll _query_greater(int node, int ll, int ul, int i, int j, value_type k)
    {
            if (OUT(ll, ul, i, j))
               return def;
            if (IN(ll, ul, i, j))
               return segtree[node].end() - upper_bound(segtree[node].begin(), segtree[node].end(), k);
            value_type left = _query_greater(2*node+1, ll, (ll+ul)/2, i, j, k);
            value_type right = _query_greater(2*node+2, (ll+ul)/2 + 1, ul, i, j, k);
            return left + right;
    }

    ll _query_lesser(int node, int ll, int ul, int i, int j, value_type k)
    {
            if (OUT(ll, ul, i, j))
               return def;
            if (IN(ll, ul, i, j))
               return lower_bound(segtree[node].begin(), segtree[node].end(), k) - segtree[node].begin();
            value_type left = _query_lesser(2*node+1, ll, (ll+ul)/2, i, j, k);
            value_type right = _query_lesser(2*node+2, (ll+ul)/2 + 1, ul, i, j, k);
            return left + right;
    }

    public:
     SegTree(vector<value_type> &array)
     {
        range = array.size();
        def = 0;
        segtree.resize(4*array.size());
        _construct(0, 0, range - 1, array);
     }

     value_type query_greater(int i, int j, value_type k)
     {
            return _query_greater(0, 0, range - 1, i, j, k);
     }

     value_type query_lesser(int i, int j, value_type k)
     {
            return _query_lesser(0, 0, range - 1, i, j, k);
     }

};

#define MAX 200005

int b[MAX], temp[MAX];

int main()
{
    ios::sync_with_stdio(false);

//    freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);

    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        b[i] = a[i];
    }
    ll inv =  mergesort(b, temp, 0, n-1);
    //ll inv = 0;
    SegTree<int> S(a);
    while (m--) {
        //cerr << m << endl;
        int x, y;
        scanf("%d%d", &x, &y);
        if (x == y) { cout << inv << endl; continue;}
        if (x > y)
            swap(x, y);
        x--, y--;
        ll ga = S.query_greater(x + 1, y - 1, a[x]);
        ll la = S.query_lesser(x + 1, y - 1, a[x]);
        ll gb = S.query_greater(x + 1, y - 1, a[y]);
        ll lb = S.query_lesser(x + 1, y - 1, a[y]);
        //trace4(ga, la, gb, lb);
        ll invm =  inv + (ga - la) + (lb - gb);
        //trace1(invm);
        if (a[x] < a[y]) invm++;
        else if (a[x] > a[y]) invm--;
        printf("%lld\n", invm);
    }
}
