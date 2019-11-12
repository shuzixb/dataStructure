#include "bintree.h"
template<typename T> class BST:public BinTree<T>
{
public:
    virtual BinNodePosi(T) &search(const T &);  //查找
    virtual BinNodePosi(T) insert(const T &);   //插入
    virtual bool remove(const T &);             //删除
protected:
    BinNodePosi(T) _hot;  //命中节点的父亲
    BinNodePosi(T) connect34(    //3+4重构
            BinNodePosi(T),BinNodePosi(T),BinNodePosi(T),
            BinNodePosi(T),BinNodePosi(T),BinNodePosi(T),BinNodePosi(T));
    BinNodePosi(T) rotateAt(BinNodePosi(T));  //旋转调整

public:
    virtual BinNodePosi(T) & search(const T& e);
    virtual BinNOdePosi(T) insert(const T& e);
    virtual bool remove (const T& e);
};


static BinNodePosi(T) & searchIn(BinNodePosi(T) & v,const T & e,BinNodePosi(T) & hot )
{
    if(!v||(e==v->data)) 
        return v;
    hot=v;
    return searchIn((e<v->data)?v->lChild:v->rChild),e,hot);
}
template<typename T> 
BinNodePosi(T) &BST<T>::search(const T & e)
{
    return searchIn(_root,e,_hot=nullptr);
}

template <typename T>
BinNodePosi(T) BST<T>::insert(const T&e)
{
    BinNodePosi(T) & x=search(e);
    if(x)
        return x;

    x=new BinNode<T>(e,_hot);
    _size++;
    updateHeightAbove(x);
    return x;
}

template<typename T>
static BinNodePosi(T) removeAt(BinNodePosi(T) &x,BinNodePosi(T) & hot)
{
    BinNodePosi(T) w=x;
    BinNodePosi(T) succ=nullptr;
    if(!HasLChild(*x))
        succ=x=x->rc;
    else if(!HasRChild(*x))
        succ=x=x->lc;
    else
    {
        w=w->succ();
        swap(x->data,w->data);
        BinNodePosi(T) u=w->parent;
        ((u==x)?u->rc:u->lc)=succ=w->rc;
    }
    hot=w->parent;
    if(succ)
        succ->parent=hot;
    release(w->data);
    release(w);
    return succ;
}

template<typename T>
bool BST<T>::remove(const T&e)
{
    BinNodePosi(T) &x=search(e);
    if(!x)
        return false;
    removeAt(x,_hot);
    _size--;
    updateHeightAbove(_hot);
    return true;
}


