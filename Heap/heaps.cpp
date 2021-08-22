#include <bits/stdc++.h>
using namespace std;

class Heap
{
    vector<int> v;
    int capacity;
    bool minheap;

    //methods
    bool compare(int a, int b)
    {
        if (minheap)
            return a < b;
        return a > b;
    }
    void heapify(int idx)
    {
        int left = idx * 2, right = 2 * idx + 1;
        int min_index = idx;
        int last = v.size() - 1;

        if (left <= last && compare(v[left], v[idx]))
            min_index = left;

        if (right <= last && compare(v[right],v[min_index]))
            min_index = right;

        if (min_index != idx)
        {
            swap(v[idx], v[min_index]);
            heapify(min_index);
        }
    }

public:
    Heap(int capacity = 10, bool type = true)
    {
        this->capacity = capacity;
        this->minheap = type;
        v.reserve(capacity);
        v.push_back(-1); //just preverve 1 based index
    }
    void push(int n)
    {
        v.push_back(n);
        int idx = v.size() - 1;
        int parent = idx / 2;

        while (idx > 1 && compare(v[idx], v[parent]))
        {
            swap(v[idx], v[parent]);
            idx = parent;
            parent = idx / 2;
        }
    }
    void print()
    {
        for(auto e:v)
            cout<<e<<" ";
    }

    int top()
    {
        if (v.size() > 1)
            return v[1];
        return -1;
    }

    void pop()
    {
        swap(v[1], v[v.size() - 1]);
        v.pop_back();
        heapify(1);
    }
    bool empty()
    {
        return v.size() == 1;
    }
};

int main()
{

    // Heap h;//minheap
    Heap h(10,false); // maxheap
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        h.push(num);
    }
    // h.print();
    while (!h.empty())
    {
        cout << h.top() << " ";
        h.pop();
    }
    return 0;
}
