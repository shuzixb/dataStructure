template<typename T> struct BTNode
{
    BTNodePosi(T) parent;
    Vector<T> key;
    Vector<BTNodePosi(T)> child;
    BTNode() {parent=nullptr;child.insert(0,nullptr)} 
    BTNode(T e,BTNodePosi(T) lc=nullptr,BTNodePosi(T) rc=nullptr)
    {
        parent=nullptr;
        key.insert(0,e);
        child.insert(0,lc);
        child.insert(1,rc);
        if(lc)
            lc->parent=this;
        if(rc)
            rc->parent=this;
    }
}
