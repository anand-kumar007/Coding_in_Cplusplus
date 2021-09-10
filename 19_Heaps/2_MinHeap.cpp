

/* implementing the Minheap */

#include <bits/stdc++.h>
using namespace std;

class MinHeap
{
private:
    int size{0};
    vector<int> vect = {-1};

    int parent(int i) const { return i >> 1; }      //i/2
    int left(int i) const { return i << 1; }        //i*2
    int right(int i) const { return (i << 1) + 1; } //i*2+1

public:
    bool isEmpty() { return size == 0; }
    int getMin() { return vect[1]; }

    //insertion
    void InsertItem(int val);
    void shiftUp(int i);

    //deletion
    int extractMin();
    void shiftDown(int i);
};

//insertion
void MinHeap::shiftUp(int i)
{
    if (i > size)
        return; //trying to shift index which doesn't exist
    if (i == 1)
        return;

    if (vect[i] < vect[parent(i)])
        swap(vect[i], vect[parent(i)]);

    //recurse for parent idx
    shiftUp(parent(i));
}

void MinHeap::InsertItem(int val)
{
    if ((size + 1 >= vect.size()))
        vect.push_back(0);

    vect[++size] = val;
    shiftUp(size);
}

// deletion
void MinHeap::shiftDown(int i)
{
    if (i > size)
        return;

    // 100
    //170   180

    // then we first check with left and if left is again
    //samller that right then we swap with right not the left

    int swapid = i;
    if (left(i) <= size && vect[left(i)] < vect[i])
        swapid = left(i);

    if (right(i) <= size && vect[right(i)] < vect[swapid])
        swapid = right(i);

    //recuse until it has left and right child
    if (swapid != i)
    {
        swap(vect[swapid], vect[i]);
        shiftDown(swapid);
    }
}

int MinHeap::extractMin()
{
    if (size == 0)
        return -1;
    int ans = vect[1];
    swap(vect[1], vect[size--]);
    shiftDown(1);

    return ans;
}

int main()
{
    MinHeap *min_pq = new MinHeap();

    if (min_pq->isEmpty())
        cout << "yes intially heap is empty" << endl;
    else
        cout << "something is wrong with your code" << endl;

    min_pq->InsertItem(10);
    min_pq->InsertItem(120);
    min_pq->InsertItem(34);
    min_pq->InsertItem(41);
    min_pq->InsertItem(5);

    cout << min_pq->extractMin() << endl; //120
    cout << min_pq->extractMin() << endl; //41
    cout << min_pq->extractMin() << endl; //34
    cout << min_pq->extractMin() << endl; //10
    cout << min_pq->extractMin() << endl; //5
    cout << min_pq->extractMin() << endl; //-1
    cout << min_pq->extractMin() << endl; //-1

    return 0;
}