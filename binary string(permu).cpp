/*
  Name: Permutations of 0 and 1 (binary string).
  Copyright: 
  Author: Shobhit Saxena
  Date: 12/11/12 20:34
  Description: This is about binary strings and its relation with fibonicci numbers.
*/



/* Few things to keep in mind.........

Let Fr is a function tht returns the number of binary strings with r and only r 1s together...
Then Fr is simply Fr(n)=Fr(n-1)+Fr(n-r-1) With Fr(1)....Fr(r) to be defined manually....:P :P

Prove using recurse formula u can get it..


Let Gr(n) is a function tht returns the number of binary strings with r and or more 1s together...

Then Gr(n)=Gr(n-1)+Gr(n-r)...



Many of these functions can be solved using fibonicci series.. Hence takes only log(n) time.. Take care of tht..
*/
