#include <iostream>

using namespace std;

const int MAX_SIZE = 100;

class Stack{
    int v[100];
    int dim;
public:
    Stack(){dim = 0;};
    Stack(const Stack *const st)
    {
        dim = (*st).dim;
        for(int i = 0; i < dim; i++) v[i] = (*st).v[i];
    }
    void push(int a)
    {
        if(dim == 100)
        {
            cout << "Stack is full\n";
            return;
        }
        v[dim++] = a;
        return;
    }
    int pop()
    {
        if(dim > 0)
        {
            dim--;
            return v[dim];
        }
        else
        {
            cout << "Stack is empty\n";
            return -1;
        }
    }
    void printStack()
    {
        for(int i = 0; i < dim; i++) cout << v[i] << " ";
    }
    operator =(const Stack& st)
    {
        cout << "Copying stacks\n";
        dim = st.dim;
        for(int i = 0; i < dim; i++)
            v[i] = st.v[i];
    }
};
int main()
{
    Stack mystack;
    mystack.push(100);
    mystack.push(10);
    Stack copystack(mystack);
    copystack.printStack();
    copystack.pop();
    cout << endl;
    mystack.printStack();
    cout << "<--mystack" << endl;
    copystack.printStack();
    cout << "<--copystack" << endl;
    mystack = copystack;
    mystack.printStack();
    cout << "<--mystack" << endl;
    return 0;
}
