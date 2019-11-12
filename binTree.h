#ifndef _BINTREE_H_
#define _BINTREE_H_
#include<cstdlib>
#include"binNode.h"
template <typename T> class BinTree
{
protected:
    int _size;
    int max(int a,int b){return (a>b?a:b);}
    BinNodePosi(T) _root;
    virtual int updateHeight(BinNodePosi(T) x);    //更新节点高度
    void updateHeightAbove (BinNodePosi(T) x);    //更新节点X及其袓先的高度

public:
    BinTree():_size(0),_root(nullptr){}        //构造函数 
    ~BinTree(){if(0<_size) remove(_root);}     //析构函数
    int size() const{return _size;}            //规模
    bool empty() const{return !_root;}         //判空
    BinNodePosi(T) root() const{return _root;}        //树根
    BinNodePosi(T) insertAsRoot(T const& e);          //插入根节点
    BinNodePosi(T) insertAsLC(BinNodePosi(T) x,T const& e);      //e作为x的左孩子(原无)插入
    BinNodePosi(T) insertAsRC(BinNodePosi(T) x,T const& e);      //e作为x的右孩子(原无)插入
    BinNodePosi(T) attachAsLC(BinNodePosi(T) x,BinTree<T>* &t);  //T作为x左子树接入
    BinNodePosi(T) attachAsRC(BinNodePosi(T) x,BinTree<T>* &t);  //T作为x右子树接入
    int remove(BinNodePosi(T) x);       //删除以位置x处节点为根的子树，返回该子树原先的规模
    BinTree<T>* secede(BinNodePosi(T) x);  //将子树x从当前树中摘除，并将其转换为一棵独立子树
    template <typename VST>  //操作器
        void travlevel(VST& visit){if(_root) _root->travLevel(visit);}  //层次遍历
    template <typename VST>
        void travPre(VST& visit){if(_root) _root->travPre(visit); }     //先序遍历
    
    template <typename VST>
        void travIn(VST& visit){if(_root) _root->travIn(visit); }     //中序遍历
    
    template <typename VST>
        void travPost(VST& visit){if(_root) _root->travPost(visit); }     //先序遍历

    bool operator<(BinTree<T> const& t){return _root&&t._root&&lt(_root,t.root);}
    bool operator==(BinTree<T> const& t){return _root&&t._root&&(_root==t.root);}
    
};

template<typename T>
int BinTree<T>::updateHeight(BinNodePosi(T) x)
{
    return x->height=1+max(stature(x->lc),stature(x->rc));
}

template<typename T> void BinTree<T>::updateHeightAbove(BinNodePosi(T) x)
{
    while(x)
    {
        updateHeight(x);
        x=x->parent;
    }
}

template<typename T> BinNodePosi(T) BinTree<T>::insertAsRoot(T const& e)
{
    _size=1;
    return _root=new BinNode<T>(e);
}

template<typename T> BinNodePosi(T) BinTree<T>::insertAsLC(BinNodePosi(T) x,T const& e)
{
    _size++;
    x->insertAsLC(e);
    updateHeightAbove(x);
    return x->lc;
}

template<typename T> BinNodePosi(T) BinTree<T>::insertAsRC(BinNodePosi(T) x,T const& e)
{
    _size++;
    x->insertAsRC(e);
    updateHeightAbove(x);
    return x->rc;
}

template <typename T>
BinNodePosi(T) BinTree<T>::attachAsRC(BinNodePosi(T) x,BinTree<T>* & s)
{
    if(x->lc=s->_root)
        x->lc->parent=x;
    _size+=s->_size;
    updateHeightAbove(x);
    s->_root=nullptr;
    s->_size=0;
    release(s);
    s=nullptr;
    return x;
}

#endif  //_BINTREE_H_
