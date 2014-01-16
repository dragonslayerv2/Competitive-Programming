#include <stdio.h>
 
#define P 1000000007L
 
typedef unsigned long long int uint64;
typedef unsigned long int uint32;
 
typedef struct{
uint64 numerator;
uint64 denominator;
} fraction;
 
uint32 factorial[800001] = {1};
int maxFactorial = 0;
void initFactorials(int max){
uint64 i;
if (max <= maxFactorial)
return;
 
for (i = maxFactorial+1; i <= max; i++)
factorial[i] = (i*factorial[i-1]) % P;
 
maxFactorial = max;
}
 
 
uint64 inverse(uint64 a){ // Calculates a^(P-2) mod P
uint64 result = 1;
uint64 exp = P-2;
 
while (exp){
if (exp%2)
result = (result*a)%P;
exp /= 2;
a = (a*a)%P;
}
 
return result;
}
 
 
fraction mchoosen(uint64 m, uint64 n){
uint64 fm = factorial[m];
uint64 fn = factorial[n];
uint64 fn_m = factorial[m-n];
 
fraction result;
result.numerator = fm;
result.denominator = (fn * fn_m) % P;
 
return result;
}
 
fraction sum(fraction a, fraction b){
fraction result;
 
result.denominator = (a.denominator * b.denominator) % P;
result.numerator = (a.numerator*b.denominator + a.denominator*b.numerator) % P;
 
return result;
}
 
fraction diff(fraction a, fraction b){
fraction result;
 
result.denominator = (a.denominator * b.denominator) % P;
result.numerator = (a.numerator*b.denominator%P + P - a.denominator*b.numerator%P) % P;
 
return result;
}
 
fraction mult(fraction a, fraction b){
fraction result;
 
result.numerator = (a.numerator * b.numerator) % P;
result.denominator = (a.denominator * b.denominator) % P;
 
return result;
}
 
 
int min(int a, int b){
return a < b ? a : b;
}
 
int max(int a, int b){
return a > b ? a : b;
}
 
 
int main(void){
int r;
scanf("%d", &r);
 
while (r--){
int n, m, a, b;
scanf("%d %d %d %d", &n, &m, &a, &b);
int i, j;
fraction result;
result.numerator = 0;
result.denominator = 1;
 
int sum1 = n-a+b;
int sum2 = m-b+a;
 
if (min(n-a, m-b) < min(a, b)){
initFactorials(max(sum1, sum2));
for (i=n-a, j=m-b; (i >= 0) && (j >= 0); i--, j--){
fraction n1 = mchoosen(sum1, i);
fraction n2 = mchoosen(sum2, j);
result = sum(result, mult(n1, n2));
}
}
else{
initFactorials(m+n);
for (i=n-a+1, j=m-b+1; (i <= n) && (j <= m); i++, j++){
fraction n1 = mchoosen(sum1, i);
fraction n2 = mchoosen(sum2, j);
result = sum(result, mult(n1, n2));
}
result = diff(mchoosen(m+n, n), result);
}
printf("%llu\n", result.numerator*inverse(result.denominator) % P);
}
 
return 0;
}
