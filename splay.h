#include "bst.h"

template <typename T> class Splay:public BST<T>
{
protected:
    BinNodePosi(T) splay(BinNodePosi(T) v);
public:
    BinNodePosi(T) & search(const T & e);
    BinNodePosi(T) insert(const T& e);
    bool remove(const T & e);
}

template <typename NodePosi> inline
void attachAsLChild(NodePosi p,NodePosi lc)
{
    p->lc=lc;
    if(lc)
        lc->parent=p;
}

template<typename NodePosi> inline
void attachAsRChild(NodePosi p,NodePosi rc)
{
    p->rc=rc;
    if(rc)
        rc->parent=p;
}

template<typename T>
BinNodePosi(T) Splay<T>::splay(BinNodePosi(T) v)
{
    if(!v)
        return nullptr;
    BinNodePosi(T) p;
    BinNodePosi(T) g;
    while((p=v->parent)&&(g=p->parent))
    {
        BinNodePosi(T) gg=g->parent;
        if(IsLChild(*v))
            if(IsLChild(*p))
            {
                attachAs
            }
    }
}
