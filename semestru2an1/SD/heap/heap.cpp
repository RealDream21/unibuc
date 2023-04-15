#include <iostream>
#include <vector>
using namespace std;

class Heap {
    vector<int> v_;

    void moveUp(int nod_pos);
    void moveDown(int nod_pos);

public:
    void pop();
    int top();
    void push(int val);
};

void Heap::moveUp(int nod_pos) {
    // Verify with the parent and move up if needed
    while (nod_pos > 0 && v_[nod_pos] < v_[(nod_pos - 1) / 2]) {
        swap(v_[nod_pos], v_[(nod_pos - 1) / 2]);
        nod_pos = (nod_pos - 1) / 2;
    }
}

void Heap::moveDown(int nod_pos) {
    while (nod_pos * 2 + 1 < v_.size()) {
        int fiu_st_pos = nod_pos * 2 + 1;
        int fiu_dr_pos = nod_pos * 2 + 2;
        int min_child_pos = fiu_st_pos;

        if (fiu_dr_pos < v_.size() && v_[fiu_dr_pos] < v_[fiu_st_pos]) {
            min_child_pos = fiu_dr_pos;
        }

        if (v_[nod_pos] > v_[min_child_pos]) {
            swap(v_[nod_pos], v_[min_child_pos]);
            nod_pos = min_child_pos;
        } else {
            break;
        }
    }
}

void Heap::pop() {
    swap(v_[0], v_.back());
    v_.pop_back();
    moveDown(0);
}

int Heap::top() {

    return v_[0];
}

void Heap::push(int val) {
    v_.push_back(val);
    moveUp(v_.size() - 1);
}

int main() {
    Heap heap;
    heap.push(0);
    heap.push(-1);
    heap.push(381);
    heap.push(-120);
    heap.pop();
    heap.pop();
    cout << heap.top() << endl;

    return 0;
}
