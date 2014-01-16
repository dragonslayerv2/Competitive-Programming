#include<iostream>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<string>
 
using namespace std;
//FastIO begin
#define BUFFERSIZE 3000000
char *ipos, *opos, InpFile[BUFFERSIZE], OutFile[BUFFERSIZE], DIP[20];
char * inputEnd;
 
inline bool eof()
{
while( ipos < inputEnd && *ipos <= 32) ipos++;
return ipos >= inputEnd;
}
inline char nc() {
while(*ipos <= 32) ++ipos;
return *ipos++;
}
inline int ni(int flag=0) {
while(*ipos <= 32) ++ipos;
if(flag) return (*ipos++ - '0'); /* For getting single digit/binary digit */
int x=0, neg = 0;char c;
while( true ) {
c=*ipos++; if(c == '-') neg = 1;
else {
if (c<=32) return neg?-x:x;
x=(x<<1)+(x<<3)+c-'0';
}
}
}
inline long long nll() {
while(*ipos <= 32) ++ipos;
long long x=0, neg = 0;char c;
while( true ) {
c=*ipos++; if(c == '-') neg = 1;
else {
if (c<=32) return neg?-x:x;
x=(x<<1)+(x<<3)+c-'0';
}
}
}
inline void pi(int x,int flag = 1){
int y,dig=0;
if(x<0) { *opos++ = '-'; x=-x;};
while (x||!dig) { y=x/10;DIP[dig++]=x-((y << 3) + (y << 1))+'0';x=y;}
while (dig--) *opos++=DIP[dig];
*opos++= ' ';
}
inline void pll(long long x,int flag = 1) {
long long y,dig=0;
if(x<0) { *opos++ = '-'; x=-x;};
while (x||!dig) { y=x/10;DIP[dig++]=x-((y << 3) + (y << 1))+'0';x=y;}
while (dig--) *opos++=DIP[dig];
*opos++= flag ? '\n' : ' ';
}
inline void ps(string str,int flag = 1) {
int len=str.length();
for(int i=0;i<len;i++)	*opos++=str[i];
*opos++= flag ? '\n' : ' ';
}
inline void pws(int flag = 1) {
*opos++= flag ? '\n' : ' ';
}
inline void InitFASTIO() {
ipos = InpFile; opos = OutFile;
inputEnd = InpFile + fread(InpFile,1,BUFFERSIZE,stdin);
}
inline void FlushFASTIO() {
fwrite(OutFile,opos-OutFile,1,stdout);
}
//FastIO end
 
#include"stdio.h"
#include"vector"
#include"assert.h"
#include"string.h"
using namespace std;
typedef unsigned int ui;
typedef const int& ci;
typedef const unsigned int& cui;
typedef unsigned long long ull;
#define REP(i,n) for(unsigned int i=0;i<n;i++)
#define LOOP(i,x,n) for(int i=x;i<n;i++)
#define i(x) scanf("%d",&x)
#define u(x) scanf("%u",&x)
struct subArray{	ui start,len; };
ui ans[250000],inp[100001],k;
void print(const vector<subArray>& a,const vector<subArray>& b,cui sofar){
bool same=(sofar==0)?1:0;
for(typeof(a.begin()) it1=a.begin(),it2=b.begin();it1 != a.end();it1++,it2++)
for(ui first=it1->start,upper=it1->len+first,upper2=it2->len+it2->start;first<upper;first++)
for(ui second=same?(first+1):it2->start;second<upper2;second++)
ans[--k]=inp[first]^inp[second] /*,printf("%u^%u = %u \n",first,second,ans[k])*/;
}
ui search(const subArray& a,ci pos){
ui upper=a.start+a.len,lower=a.start;
while(upper>lower){
const ui mid= (upper+lower)>>1;
if((inp[mid]>>pos)&1)upper=mid; else lower=mid+1;
}
return lower;
}
void solve(ci pos,const vector<subArray>& a,const vector<subArray>& b,cui sofar){
if(pos<0){
while(k)ans[--k]=sofar;
return;
}
vector<subArray> _0a,_0b,_1a,_1b;
ull ct=0;
for(typeof(a.begin()) it1=a.begin(),it2=b.begin();it1!=a.end();it1++,it2++){
int i=search(*it1,pos),j=i;
if(sofar)j=search(*it2,pos);
// printf("partition [%u,%u) = [%u,%d) U [%d,%u)\n",it1->start,it1->len+it1->start,it1->start,i,i,it1->len+it1->start);
// printf("partition [%u,%u) = [%u,%d) U [%d,%u)\n",it2->start,it2->len+it2->start,it2->start,j,j,it2->len+it2->start);
subArray __0,__1,_1_,_0_;
_0_.start=it1->start, _0_.len=i- _0_.start;
_1_.start=i, _1_.len=it1->len- _0_.len;
__0.start=it2->start, __0.len=j- __0.start,
__1.start=j, __1.len=it2->len- __0.len;
if(_0_.len&&__0.len)	_0a.push_back(_0_), _0b.push_back(__0);
if(_1_.len&&__1.len)	_0a.push_back(_1_), _0b.push_back(__1);
if(_0_.len&&__1.len)	_1a.push_back(_0_), _1b.push_back(__1);
if(sofar){
if(_1_.len&&__0.len)	_1a.push_back(_1_), _1b.push_back(__0);
ct+=_0_.len*(ull)(__0.len)+_1_.len*(ull)(__1.len);
}
else ct+=(_0_.len*(_0_.len-1ULL)+_1_.len*(_1_.len-1ULL))>>1;
}
// printf("pos=%d sofar=%u ct=%Lu k=%u\n",pos,sofar,ct,k);
if(ct<=k){
print(_0a,_0b,sofar);
if(k)	solve(pos-1,_1a,_1b,sofar|(1<<pos));
}
else solve(pos-1,_0a,_0b,sofar);
}
ui ct[65536],intermediate[250000];
void sort(ui arr[],cui n){
memset(ct,0,65536*sizeof(ui));
REP(i,n)ct[arr[i]&65535]++;
ui sum=n;
for(ui i=65535;i;i--)	sum=(ct[i]=sum-ct[i]);
ct[0]=0;
REP(i,n)
intermediate[ct[arr[i]&65535]++]=arr[i];
 
memset(ct,0,32768*sizeof(ui));
REP(i,n)ct[intermediate[i]>>16]++;
sum=n;
for(ui i=32767;i;i--)	sum=(ct[i]=sum-ct[i]);
ct[0]=0;
REP(i,n)
arr[ct[intermediate[i]>>16]++]=intermediate[i];
}
int main(){
InitFASTIO();
 
ui n,k0;
n=ni(),k=ni();
k0=k;
REP(i,n)inp[i]=ni();
sort(inp,n);
inp[n]=-1;
vector<subArray> a,b;
subArray x;
x.start=0,x.len=n;
a.push_back(x),b.push_back(x);
solve(31,a,b,0);
sort(ans,k0);
REP(i,k0)pi(ans[i]);
FlushFASTIO();
} 
