#include<bits/stdc++.h>
using namespace std;

class MyQueue {
    stack<int> prim, sec;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        prim.push(x);
    }
    
    int pop() {
        if(sec.empty())
        {
            while(prim.size())
            {
                sec.push(prim.top());
                prim.pop();
            }
        }

        int num = sec.top();
        sec.pop();
        return num;
        
        
    }
    
    int peek() {
        if(sec.empty())
        {
            while(prim.size())
            {
                sec.push(prim.top());
                prim.pop();
            }
        }

        return sec.top();
        

    }
    
    bool empty() {
         return prim.empty() && sec.empty();
    }
};

int main()
{
    
/*
 * Your MyQueue object will be instantiated and called as such:
*/

 MyQueue* obj = new MyQueue();
 obj->push(1);
 int param_2 = obj->pop();
 int param_3 = obj->peek();
 bool param_4 = obj->empty();

 cout << param_2 << " " <<  param_3 << " " << param_4 << endl;

}