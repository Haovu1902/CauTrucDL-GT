#include <iostream>
using namespace std;

template <typename T>
class Array
{
private:
    T *a;
    int n;

public:
    Array(const int &n, const T &value = 0)
    {
        this->n = n;
        if (n > 0)
        {
            a = new T[n];
        }
    }

    ~Array()
    {
        delete[] a;
    }

    T &operator[](const int &pos)
    {
        return a[pos];
    }

    int size()
    {
        return n;
    }

    void input()
    {
        for (int i = 0; i < n; i++)
        {
            cout << "a[" << i << "] = ";
            cin >> a[i];
        }
    }

    void print()
    {
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
        cout << '\n';
    }

    /* QUICK SORT ALGORITHM */

    bool isEqual(T &a, T &b, bool (*cmp)(T &, T &))
    {
        return cmp(a, b) == cmp(b, a);
    }

    bool isDifferent(T &a, T &b, bool (*cmp)(T &, T &))
    {
        return !isEqual(a, b, cmp);
    }

    int partition(const int &i, const int &j, bool (*cmp)(T &, T &))
    {
        int left = i, right = j;
        T pivot = a[i];

        while (left < right)
        {
            while ((cmp(a[left], pivot) || isEqual(a[left], pivot, cmp)) && left < right)
            {
                left++;
            }
            while (cmp(pivot, a[right]) && isDifferent(pivot, a[right], cmp))
            {
                right--;
            }
            if (left < right)
            {
                std::swap(a[left], a[right]);
            }
        }

        if (i != right)
        {
            std::swap(a[i], a[right]);
        }

        return right;
    }

    void __quick__sort__(const int &i, const int &j, bool (*cmp)(T &, T &))
    {
        if (i < j)
        {
            int k = partition(i, j, cmp);
            __quick__sort__(i, k - 1, cmp);
            __quick__sort__(k + 1, j, cmp);
        }
    }

    void quick_sort(bool (*cmp)(T &, T &))
    {
        return __quick__sort__(0, n - 1, cmp);
    }

    /* MERGE SORT ALGORITHM */
    void merge(const int &i, const int &k, const int &j, bool (*cmp)(T &, T &))
    {
        int left = i;
        int right = k + 1;
        T *b = new T[i + j];
        int t = i;

        while (left <= k && right <= j)
        {
            if (cmp(a[left], a[right]))
            {
                b[t] = a[left];
                left++;
                t++;
            }
            else
            {
                b[t] = a[right];
                right++;
                t++;
            }
        }

        if (left > k)
        {
            for (int r = right; r <= j; r++)
            {
                b[t] = a[r];
                t++;
            }
        }
        else
        {
            for (int l = left; l <= k; l++)
            {
                b[t] = a[l];
                t++;
            }
        }

        for (int index = i; index <= j; index++)
        {
            a[index] = b[index];
        }
    }

    void __merge__sort__(const int &i, const int &j, bool (*cmp)(T &, T &))
    {
        if (i < j)
        {
            int k = (i + j) / 2;
            __merge__sort__(i, k, cmp);
            __merge__sort__(k + 1, j, cmp);
            merge(i, k, j, cmp);
        }
    }

    void merge_sort(bool (*cmp)(T &, T &))
    {
        return __merge__sort__(0, n - 1, cmp);
    }

    /* HEAP SORT ALGORITHM */
    void push_down(const int &i, const int &n, bool (*cmp)(T &, T &))
    {
        int pos_cmp;
        int j = i;
        while (j <= n / 2)
        {
            if (2 * j == n)
            {
                pos_cmp = 2 * j;
            }
            else
            {
                if (cmp(a[2 * j], a[2 * j + 1]))
                {
                    pos_cmp = 2 * j + 1;
                }
                else
                {
                    pos_cmp = 2 * j;
                }
            }

            if (cmp(a[j], a[pos_cmp]) && j != pos_cmp)
            {
                swap(a[j], a[pos_cmp]);
                j = pos_cmp;
            }
            else
            {
                break;
            }
        }
    }

    void heap_sort(bool (*cmp)(T &, T &))
    {
        // Biến đổi thành mảng biểu diễn cây Heap
        for (int i = n / 2 - 1; i >= 0; i--)
        {
            push_down(i, n - 1, cmp);
        }

        /*
        - Đẩy phần tử lớn nhất về cuối dãy (với sắp xếp tăng) hoặc phần tử nhỏ nhất về cuối dãy (với sắp xếp giảm)
        - Thực hiện push_down để biểu diễn cây Heap cho i-1 phần từ còn lại (với i = n-1 -> 1)
        */

        for (int i = n - 1; i >= 1; i--)
        {
            swap(a[0], a[i]);
            push_down(0, i - 1, cmp);
        }
    }
};

template <typename T>
void generateRandomValue(Array<T> &a, const T &b_value = 0, const T &e_value = 9)
{
    srand(time(NULL));
    for (int i = 0; i < a.size(); i++)
    {
        a[i] = rand() % (e_value - b_value + 1) + b_value;
    }
}

bool tang_dan(int &a, int &b)
{
    return a < b;
}

bool giam_dan(int &a, int &b)
{
    return a > b;
}

int main()
{
    Array<int> a(100);
    generateRandomValue(a, 1, 100);

    cout << "\nbefore sort:\n";
    a.print();
    a.quick_sort(tang_dan);
    cout << "\nafter sort:\n";
    a.print();
    return 0;
}