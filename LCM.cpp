// FUnctions to find nLCM and GCD using Euclids Division Lemma


int GCD(int a, int b)
{
   if (b==0) return a;
   return GCD(b,a%b);
}

int LCM(int a, int b)
{
   return b*a/GCD(a,b);
}

