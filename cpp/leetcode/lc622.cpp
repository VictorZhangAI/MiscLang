class MyCircularQueue {
public:
    vector<int> q;
    int front;
    int rear;
    int n;
    MyCircularQueue(int k) {
        n = k;
        q.resize(n);
        front = rear = -1;
    }
    
    bool enQueue(int value) {
        if((rear + 1) % n == front)
        {
            return false;
        }

        if(rear == -1)
        {
            front = 0;
            rear = 0;
        }
        else
        {
            rear = (rear + 1) % n;
        }
        q[rear] = value;
        return true;
    }
    
    bool deQueue() {
        if(front == -1)
        {
            return false;
        }
        if(front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % n;
        }
        return true;
    }
    
    int Front() {
        if(front == -1)
        {
            return -1;
        }
        return q[front];
    }
    
    int Rear() {
        if(rear == -1)
        {
            return -1;
        }
        return q[rear];
    }
    
    bool isEmpty() {
        return front == -1;
    }
    
    bool isFull() {
        return (rear + 1) % n == front;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
