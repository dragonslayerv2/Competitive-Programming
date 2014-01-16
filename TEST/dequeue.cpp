#include<stdlib.h>

class MyQueue//Our data structure
{
    deque D;//We need 2 deque objects
    deque Min;

    push(element)//pushing element to MyQueue
    {
        D.push_back(element);
        while(Min.is_not_empty() and Min.back()>element)
             Min.pop_back();
        Min.push_back(element);
    }
    pop()//poping MyQueue
    {
         if(Min.front()==D.front() )
            Min.pop_front();
         D.pop_front();
    }

    min()
    {
         return Min.front();
    }
}
