#ifndef __btree__
#define __btree__
#include"bnode.cpp"



template <typename T>
class BTree
{
private:
    BNode<T> *root;
    int n;

public:
    BTree<T>()
    {
        root = nullptr;
        n = 0;
    }
    BNode<T> *getRoot()
    {
        return root;
    }
    int size()
    {
        return n;
    }
    bool isEmpty()
    {
        return root == nullptr;
    }
    bool isInternal(BNode<T> *p)
    {
        return p->hasLeft() || p->hasRight();
    }
    bool isExternal(BNode<T> *p)
    {
        return !(p->hasLeft() || p->hasRight());
    }
    bool isRoot(BNode<T> *p)
    {
        return p->getParent() == nullptr;
    }
    void preOrder(BNode<T> *p, void (*visit)(BNode<T> *))
    {
        if (p != nullptr)
        {
            visit(p);
            preOrder(p->getLeft(), visit);
            preOrder(p->getRight(), visit);
        }
    }
    void inOrder(BNode<T> *p, void (*visit)(BNode<T> *))
    {
        if (p != nullptr)
        {
            inOrder(p->getLeft(), visit);
            visit(p);
            inOrder(p->getRight(), visit);
        }
    }
    void postOrder(BNode<T> *p, void (*visit)(BNode<T> *))
    {
        if (p != nullptr)
        {
            postOrder(p->getLeft(), visit);
            postOrder(p->getRight(), visit);
            visit(p);
        }
    }
    BNode<T> *insert(BNode<T> *parent, T e)
    {
        BNode<T> *new_node = new BNode<T>();
        new_node->setElem(e);
        if (parent == nullptr)
        {
            root = new_node;
            n++;
        }
        else
        {
            new_node->setParent(parent);
            if (parent->getLeft() == nullptr)
            {
                parent->setLeft(new_node);
                n++;
                return new_node;
            }
            else if (parent->getRight() == nullptr)
            {
                parent->setRight(new_node);
                n++;
                return new_node;
            }
            else
            {
                delete new_node;
            }
        }
    }

    void remove(BNode<T> *p)
    {
        if (p != nullptr)
        {
            if (p->getLeft() != nullptr)
            {
                remove(p->getLeft());
            }
            if (p->getRight() != nullptr)
            {
                remove(p->getRight());
            }
            if (p->getParent() != nullptr)
            {
                if (p == p->getParent()->getLeft())
                {
                    p->getParent()->setLeft(nullptr);
                }
                else
                {
                    p->getParent()->setRight(nullptr);
                }
            }
            else
            {
                root = nullptr;
            }

            delete p;
            n--;
        }
    }
};






#endif 

