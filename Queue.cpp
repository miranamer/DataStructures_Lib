#include <iostream>
#include <vector>
using namespace std;

class Queue{
    public:
        int queueSize;
        vector<int> queue;
    Queue(int _queueSize){
        this->queueSize = _queueSize;
        this->queue = {};
    }
    
    void enqueue(int value){
        if(this->queue.size() < this->queueSize){
            //this->queue.insert(this->queue.begin() + 0, value);
            this->queue.push_back(value);
            cout << value << " Added!" << endl;
        }
        else{
            cout << "Queue Limit Reached!" << endl;
        }
    }
    
    void dequeue(){
        if(this->queue.size() > 0){
            cout << this->queue.front() << " Dequeued!" << endl;
            this->queue.erase(this->queue.begin() + 0);
        }
        else{
            cout << "Queue Empty" << endl;
        }
    }
    
    void show(){
        cout << "-------------Queue Contents-------------" << endl;
        for(int i = 0; i < this->queue.size(); i++){
            cout << " " << i << ".[" << this->queue[i] << "]";
        }
        cout << "" << endl;
        cout << "----------------------------------------" << endl;
    }
};

int main() {
   Queue myQueue = Queue(3);
   myQueue.enqueue(1);
   myQueue.enqueue(2);
   myQueue.show();
   myQueue.dequeue();
   myQueue.show();
   
   
    return 0;
}
