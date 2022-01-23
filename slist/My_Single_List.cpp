#ifndef ______MY__SINGLE__LIST__CPP______
#define ______MY__SINGLE__LIST__CPP______

template <typename T>
class Node
{
private:
    T element;
    Node<T> *pNext;

public:
    Node<T>()
    {
        pNext = nullptr;
    }

    Node<T>(const T &_element, Node<T> *_pNext = nullptr)
    {
        element = _element;
        pNext = _pNext;
    }

    Node<T> *get_next()
    {
        return pNext;
    }

    T &get_element()
    {
        return element;
    }

    void set_next(Node<T> *_pNext)
    {
        pNext = _pNext;
    }

    void set_element(const T &_element)
    {
        element = _element;
    }
};

template <typename T>
class single_list_iterator
{
private:
    Node<T> *pCurrent;

public:
    single_list_iterator(Node<T> *_pCurrent = nullptr)
    {
        pCurrent = _pCurrent;
    }

    Node<T> *get_current()
    {
        return pCurrent;
    }

    single_list_iterator<T> &operator=(single_list_iterator<T> it)
    {
        this->pCurrent = it.get_current();
        return *this;
    }

    bool operator!=(single_list_iterator<T> it)
    {
        return (this->pCurrent != it.get_current());
    }

    single_list_iterator<T> &operator++()
    {
        this->pCurrent = this->pCurrent->get_next();
        return *this;
    }

    single_list_iterator<T> &operator++(int)
    {
        ++(*this);
        return *this;
    }

    T &operator*()
    {
        return pCurrent->get_element();
    }
};

template <typename T>
class SLIST
{
private:
    Node<T> *pHead;
    Node<T> *pTrail;
    int number;

public:
    SLIST<T>()
    {
        pHead = pTrail = nullptr;
        number = 0;
    }

    SLIST<T>(int _number, const T &element_value = 0)
    {
        pHead = pTrail = nullptr;
        number = 0;

        while (_number--)
        {
            push_back(element_value);
        }
    }

    int size()
    {
        return number;
    }

    bool empty()
    {
        return number == 0;
    }

    T &front()
    {
        return pHead->get_element();
    }

    T &back()
    {
        return pTrail->get_element();
    }

    void push_front(const T &element_value)
    {
        Node<T> *New_Node = new Node<T>(element_value);
        if (New_Node == nullptr)
        {
            return;
        }

        if (empty())
        {
            pHead = pTrail = New_Node;
        }
        else
        {
            New_Node->set_next(pHead);
            pHead = New_Node;
        }

        number++;
    }

    void push_back(const T &element_value)
    {
        Node<T> *New_Node = new Node<T>(element_value);
        if (New_Node == nullptr)
        {
            return;
        }

        if (empty())
        {
            pHead = pTrail = New_Node;
        }
        else
        {
            pTrail->set_next(New_Node);
            pTrail = New_Node;
        }

        number++;
    }

    void pop_front()
    {
        if (number == 1)
        {
            delete pHead;
            pHead = pTrail = nullptr;
        }
        else
        {
            Node<T> *tmp = pHead;
            pHead = pHead->get_next();
            delete tmp;
        }

        number--;
    }

    void pop_back()
    {
        if (number == 1)
        {
            delete pTrail;
            pHead = pTrail = nullptr;
        }
        else
        {
            Node<T> *tmp = pHead;
            while (tmp->get_next() != pTrail)
            {
                tmp = tmp->get_next();
            }

            delete pTrail;
            pTrail = tmp;
            pTrail->set_next(nullptr);
        }

        number--;
    }

    typedef single_list_iterator<T> iterator;

    iterator begin()
    {
        return iterator(pHead);
    }

    iterator end()
    {
        return iterator(nullptr);
    }

    void insert(iterator it, const T &element_value)
    {
        if (it.get_current() == pTrail)
        {
            return push_back(element_value);
        }
        else
        {
            Node<T> *New_Node = new Node<T>(element_value);
            New_Node->set_next(it.get_current()->get_next());
            it.get_current()->set_next(New_Node);
            number++;
        }
    }

    void erase(iterator it)
    {
        if (it.get_current() == pHead)
        {
            return pop_front();
        }
        else if (it.get_current() == pTrail)
        {
            return pop_back();
        }
        else
        {
            Node<T> *tmp = pHead;
            while (tmp->get_next() != it.get_current())
            {
                tmp = tmp->get_next();
            }

            tmp->set_next(it.get_current()->get_next());
            delete it.get_current();
            number--;
        }
    }
};

#endif