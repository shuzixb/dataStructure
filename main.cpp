#include"binTree.h"
#include<iostream>
using namespace std;

int main(void)
{
    BinNodePosi(int) p=new BinNode<int>(10);
    BinTree<int>* t=new BinTree<int>;
    t->insertAsRoot(5);
    cout<<p->data<<endl;
    cout<<HasRChild(*p)<<endl;
    cout<<t->size()<<endl;
    Stack<int> st;
    Queue<int> qu;

    for(int i=0;i<10;i++)
    {
      st.push(i);
      qu.enqueue(i);
    }

    for(int i=0;i<10;i++)
        cout<<st.pop()<<"   "<<qu.dequeue()<<endl;
    
    return 0;
}
I am a student!