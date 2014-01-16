#include <stdio.h>
#include<conio.h>

void swap(char arr[], int a, int b)
{
char temp;
temp=arr[a];
arr[a] = arr[b];
arr[b] = temp;
}

void printAll(char arr[], int j, int n)
{
int i;
if(j==n)
{
printf("\n%s", arr);
return;}
for(i=j; i<n; i++)
{
swap(arr, i, j);
printAll(arr, j+1, n);
swap(arr, i, j);
}
}

int main()
{
char arr[] = {'A', 'B', 'C', 'D',0};
printAll(arr, 0, 4);
getch();
}

