#ifndef _BINNODE_H_
#define _BINNODE_H_

#define BinNodePosi(T) BinNode<T>*
#define stature(p) ((p)?(p)->height:-1)
#define IsRoot(x) (!(x).parent)
#define IsLChild(x) (!IsRoot(x)&&(&(x)==(x).parent->lc))
#define IsRChild(x) (!IsRoot(x)&&(&(x)==(x).parent->rc))
#define HasParent(x) (!IsRoot(x))
#define HasLChild(x) ((x).lc)
#define HasRChild(x) ((x).rc)                             
#define HasChild(x) (HasLChild(x)||HasRChild(x))          //至少拥有一个孩子
#define HasBothChild(x) (HasLChild(x)&&HasRChild(x))      //同时拥有两个孩子
#define IsLeaf(x) (!HasChild(x))
#define sibling(p) (IsLChild(*(p))?(p)->parent->rc:(p)->parent->lc)     //兄弟
#define uncle(x) (IsLChild(*((x)->parent))?(x)->parent->parent->rc:(x)->parent->parent->lc)  //叔叔
#define FromParentTo(x) (IsRoot(x)?_root:(IsLChild(x)?(x).parent->lc:(x).parent->rc))   //来自父亲的引用

#include"queue.h"
#include"stack.h"

typedef enum{RB_RED,RB_BLACK}RBColor;

template <typename T> struct BinNode
{
    T data;
    BinNodePosi(T) parent;
    BinNodePosi(T) lc;
    BinNodePosi(T) rc;
    int height;
    int npl;
    RBColor color;

public:
    BinNode():parent(nullptr),lc(nullptr),rc(nullptr),height(0),npl(1),color(RB_RED){}
    BinNode(T e,BinNodePosi(T) p=nullptr,BinNodePosi(T) lc=nullptr,BinNodePosi(T) rc=nullptr,int h=0,int l=1,RBColor c=RB_RED):data(e),parent(p),lc(lc),rc(rc),height(h),npl(l),color(c){}

    int size();
    BinNodePosi(T) insertAsLC(T const&);
    BinNodePosi(T) insertAsRC(T const&);
    BinNodePosi(T) succ();
    template <typename VST> void travLevel(VST&);
    template <typename VST> void travPre(VST&);
    template <typename VST> void travIn(VST&);
    template <typename VST> void travPost(VST&);

    bool operator<(BinNode const& bn){return data<bn.data;}
    bool operator=(BinNode const& bn){return data==bn.data;}
};

template<typename T> BinNodePosi(T) BinNode<T>::insertAsLC(T const& e)
{
    return lc=new BinNode(e,this);
}

template<typename T> BinNodePosi(T) BinNode<T>::insertAsRC(T const& e)
{
    return rc=new BinNode(e,this);
}


template <typename T> template<typename VST>
void BinNode<T>::travPre(VST & visit)
{
    Stack <BinNodePosi(T)> s;
    BinNodePosi(T) x=this;
    if(x)
        s.push(x);
    while(!s.empty())
    {
        x=s.pop();
        visit(x->data);
        if(HasRChild(*x))
            s.push(x->rChild);
        if(HasLChild(*x))
            s.push(x->lChild);
    }
}

template<typename T> template<typename VST>
void BinNode<T>::travIn(VST & visit)
{
    Stack<BinNodePosi(T)> s;
    BinNodePosi(T) x=this;
    while(true)
    {
        while(x)
        {
            s.push(x);
            x=x->lChild;
        }
        if(s.empty())
            break;
        x=s.pop();
        visit(x->data);
        x=x->rChild;
    }    
}

template<typename T> template<typename VST>
void BinNode<T>::travLevel(VST & visit)
{
    Queue<BinNodePosi(T)> q;
    BinNodePosi(T) x=this;
    q.enqueue(x);
    while(!q.empty())
    {
        x=q.dequeue();
        visit(x->data);
        if(HasLChild(*x))
            q.enqueue(x->lChild);
        if(HasRChild(*x))
            q.enqueue(x->rChild);
    }
}
#endif //_BINNODE_H_
