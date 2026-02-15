#include<bits/stdc++.h>
using namespace std;


void insert(stack<int> &st,int target){
    
    if(st.empty() || st.top()<=target){
        st.push(target);
        return;
    }
    
    int temp = st.top();
    st.pop();
    insert(st,target);
    st.push(temp);
}

void sortt(stack<int> &st){
    
    if(st.size()==1) return;
    
    int temp = st.top();
    st.pop();
    sortt(st);
    insert(st,temp);
}


int main(){
    
    stack<int> st;
    st.push(5);
    st.push(1);
    st.push(0);
    st.push(2);
    
    sortt(st);

    // Create a copy
    stack<int> temp(st);

    while (!temp.empty())
    {
        cout << temp.top() << " ";
        temp.pop();
    }
}