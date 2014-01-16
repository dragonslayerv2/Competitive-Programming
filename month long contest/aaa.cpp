    #include <iostream>
    #include <string>
    #include<list>
    #include<stdio.h>
    using namespace std;
    string a1[] = {"124578", "0124578", "1245789", "00124578", "01245789", "12345678", "12457899", "000124578", "001245789", "012345678", "012457899", "123456789"};
    string a2[] = {"124578999","0000124578", "0012345678", "0123456789", "1233456678", "1245789999", "0001245789", "0012457899", "0124578999", "1234567899", "1122245568", "1344577788"};
    vector<long long> result;
    int size, c1[15], c2[15], par[15];
    void bktk(int present_Scenario, int carry)
    {
    if(present_Scenario == size - 1)
    {
    for(int i = 1;i < 5;i++)
    {
    if(c1[i] > 0)
    {
    if(c2[i * 2 + carry] != 0)
    {
    long long answer = i;
    for(int j = present_Scenario - 1; j >= 0; j--)
    {
    answer = answer * 10 + par[j];
    }
    result.push_back(answer);
    }
    }
    }
    }
    else if(c1[1] + c1[2] + c1[3] + c1[4] > 0)
    {
    for(int i = 0; i < 10; i++)
    {
    int crry = i >= 5 ? 1 : 0;
    int digit = i * 2 + carry;
    if(digit >= 10)
    {
    digit -= 10;
    }
    if(c1[i] > 0 && c2[digit] > 0)
    {
    c2[digit]--;
    c1[i]--;
    par[present_Scenario] = i;
    bktk(present_Scenario+1,crry);
    c2[digit]++;
    c1[i]++;
    }
    }
    }
    }
    void permute()
    {
    for(int i = 0; i < 12; i++)
    {
    size = a1[i].size();
    memset(c1, 0, sizeof c1);
    memset(c2, 0, sizeof c2);
    for(int j = 0; j < size; j++)
    {
    c1[a1[i][j]-'0']++;
    c2[a1[i][j]-'0']++;
    }
    bktk(0,0);
    }
    for(int i = 0; i < 12; i++)
    {
    size = a2[i].size();
    memset(c1, 0, sizeof c1);
    memset(c2, 0, sizeof c2);
    for(int j = 0; j < size; j++)
    {
    c1[a2[i][j]-'0']++;
    c2[a2[i][j]-'0']++;
    }
    bktk(0,0);
    }
    }
    int main()
    {
    int testRuns;
    permute();
    sort(result.begin(),result.end());
    scanf("%d",&testRuns);
    for(int testRun = 1; testRun <= testRuns; testRun++)
    {
    long long T,H;
    scanf("%lld%lld",&T,&H);
    long long answer = lower_bound(result.begin(),result.end(),H+1) - result.begin();
    answer -= lower_bound(result.begin(),result.end(),T) - result.begin();
    printf("%d\n",answer);
    }
    return 0;
    }
