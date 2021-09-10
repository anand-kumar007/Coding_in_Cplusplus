

/* implementing the maxheap */

#include <bits/stdc++.h>
using namespace std;

class MaxHeap
{
private:
    int size{0};
    vector<int> vect = {-1};

    int parent(int i) const { return i >> 1; }      //i/2
    int left(int i) const { return i << 1; }        //i*2
    int right(int i) const { return (i << 1) + 1; } //i*2+1

public:
    bool isEmpty() { return size == 0; }
    int getMax() { return vect[1]; }

    //insertion
    void InsertItem(int val);
    void shiftUp(int i);

    //deletion
    int extractMax();
    void shiftDown(int i);
};

//insertion
void MaxHeap::shiftUp(int i)
{
    if (i > size)
        return; //trying to shift index which doesn't exist
    if (i == 1)
        return;

    if (vect[i] > vect[parent(i)])
        swap(vect[i], vect[parent(i)]);

    //recurse for parent idx
    shiftUp(parent(i));
}

void MaxHeap::InsertItem(int val)
{
    if ((size + 1 >= vect.size()))
        vect.push_back(0);

    vect[++size] = val;
    shiftUp(size);
}

// deletion
void MaxHeap::shiftDown(int i)
{
    if (i > size)
        return;

    // 100
    //170   180

    // then we first check with left and if left is again
    //samller that right then we swap with right not the left

    int swapid = i;
    if (left(i) <= size && vect[left(i)] > vect[i])
        swapid = left(i);

    if (right(i) <= size && vect[right(i)] > vect[swapid])
        swapid = right(i);

    //recuse until it has left and right child
    if (swapid != i)
    {
        swap(vect[swapid], vect[i]);
        shiftDown(swapid);
    }
}

int MaxHeap::extractMax()
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
    MaxHeap *priority_queue = new MaxHeap();

    if (priority_queue->isEmpty())
        cout << "yes intially heap is empty" << endl;
    else
        cout << "something is wrong with your code" << endl;

    priority_queue->InsertItem(10);
    priority_queue->InsertItem(120);
    priority_queue->InsertItem(34);
    priority_queue->InsertItem(41);
    priority_queue->InsertItem(5);

    cout << priority_queue->extractMax() << endl; //120
    cout << priority_queue->extractMax() << endl; //41
    cout << priority_queue->extractMax() << endl; //34
    cout << priority_queue->extractMax() << endl; //10
    cout << priority_queue->extractMax() << endl; //5
    cout << priority_queue->extractMax() << endl; //-1
    cout << priority_queue->extractMax() << endl; //-1

    return 0;
}