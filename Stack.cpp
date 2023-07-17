// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;

class Stack{
    public:
        int stackSize;
        vector<int> stack;
    Stack(int _stackSize){
        this->stackSize = _stackSize;
        this->stack = {};
    }
    
    void push(int value){
        if(this->stack.size() < this->stackSize){
            this->stack.push_back(value);
            cout << value << " Added!" << endl;
        }
        else{
            cout << "Stack Limit Reached!" << endl;
        }
    }
    
    void pop(){
        if(this->stack.size() > 0){
            cout << this->stack.back() << " Popped!" << endl;
            this->stack.pop_back();
        }
        else{
            cout << "Stack Empty" << endl;
        }
    }
    
    void show(){
        cout << "-------------Stack Contents-------------" << endl;
        for(int i = this->stack.size() - 1; i > -1; i--){
            cout << i+1 << ".) " << this->stack[i] << endl;
        }
        cout << "----------------------------------------" << endl;
    }
};

int main() {
   Stack myStack = Stack(3);
   myStack.push(10);
   myStack.push(20);
   myStack.pop();
   myStack.show();
   myStack.push(20);
   myStack.push(100);
   myStack.show();
   
    return 0;
}
