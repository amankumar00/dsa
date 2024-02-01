#include <bits/stdc++.h>
using namespace std;

template <typename T>
class arr
{
public:
    T *a;
    int capacity;
    int current;

    arr()
    {
        a = new T[1];
        capacity = 1;
        current = 0;
    }
    void push(T data)
    {
        if (current == capacity)
        {
            T *temp = new T[2 * capacity];
            for (int i = 0; i < capacity; i++)
            {
                temp[i] = a[i];
            }
            delete[] a;
            capacity *= 2;
            a = temp;
        }
        a[current] = data;
        current++;
    }

    T get(int index)
    {
        if (index < current)
            return a[index];

        return -1;
    }

    void pop()
    {
        current--;
    }
    int size()
    {
        return current;
    }
};

int main()
{
    // int a;
    // cin >> a;
    // cout << a;

    arr<int> a;
    int p;

    while (cin >> p)
    {
        a.push(p);
    }
    // cout<<a[p];

    for (int i = 0; i < a.size(); i++)
    {
        cout << a.get(i);
    }

    return 0;
}