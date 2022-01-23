#ifndef ____STACK__ARRAY__CPP____
#define ____STACK__ARRAY__CPP____

template <typename T>
class StackArr
{
private:
    T *stack;
    int topPosition;
    int capacity;

public:
    StackArr()
    {
        capacity = 1;
        topPosition = -1;
        stack = new T[capacity];
    }

    ~StackArr()
    {
        delete[] stack;
    }

    int size()
    {
        return topPosition + 1;
    }

    bool empty()
    {
        return topPosition == -1;
    }

    T &top()
    {
        return stack[topPosition];
    }

    void push(const T &o)
    {
        if (topPosition == capacity - 1)
        {
            capacity *= 2;
            T *tmp = new T[capacity];
            for (int i = 0; i <= topPosition; i++)
            {
                tmp[i] = stack[i];
            }

            delete[] stack;
            stack = tmp;
        }

        topPosition++;
        stack[topPosition] = o;
    }

    void pop()
    {
        topPosition--;
    }
};

#endif