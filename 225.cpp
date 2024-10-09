//Implement Queue using Stack
#include<bits/stdc++.h>
using namespace std;


class MyStack {
    queue<int> kion;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        int s = kion.size();
        kion.push(x);
        //Just reverses current order of Queue, instead the last pushed element
        //to make that elem to be the top one!
        for(int i = 0; i < s; i++)
        {
            kion.push(kion.front());
            kion.pop();
        }
    }
    
    int pop() {
        int num = kion.front();
        kion.pop();
        return num;
    }
    
    int top() {
        return kion.front();
    }

     bool empty() {
        return kion.empty();
    }
};

int main()
{
    //LIFO
    MyStack st;
    st.push(1);
    st.push(2);
    st.push(3);
    cout<<st.empty()<<endl<<endl;
    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top()<<endl;
    cout<<st.empty()<<st.empty()<<endl<<endl;
    st.pop();
    cout<<st.top();
    st.pop();
    cout<<st.top();

}