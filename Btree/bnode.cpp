#ifndef _____bnode_____
#define _____bnode_____

template <class T>
class BNode
{
private:
    T elem;
    BNode<T> *parent;
    BNode<T> *left;
    BNode<T> *right;

public:
    BNode<T>()
    {
        parent = 0;
        left = 0;
        right = 0;
    }
    BNode<T> *getParent()
    {
        return parent;
    }
    BNode<T> *getLeft()
    {
        return left;
    }
    BNode<T> *getRight()
    {
        return right;
    }
    void setLeft(BNode<T> *p)
    {
        left = p;
    }
    void setRight(BNode<T> *p)
    {
        right = p;
    }
    void setParent(BNode<T> *p)
    {
        parent = p;
    }
    bool hasLeft()
    {
        return left != nullptr;
    }
    bool hasRight()
    {
        return right != nullptr;
    }
    T getElem()
    {
        return elem;
    }
    void setElem(T e)
    {
        elem = e;
    }
};

#endif

