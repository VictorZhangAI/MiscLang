class MyCircularDeque {
public:
    vector<int> dq;
    int k, front, back, len;
    MyCircularDeque(int k) {
        this->k = k;
        this->front = 0;
        this->back = k - 1;
        this->len = 0;
        this->dq.resize(k);
    }
    
    bool insertFront(int value) {
        if(len == k)
            return false;
        front = (front == 0) ? k - 1 : front - 1;
        dq[front] = value;
        len++;
        return true;
    }
    
    bool insertLast(int value) {
        if(len == k)
            return false;
        back = (back == k - 1) ? 0 : back + 1;
        dq[back] = value;
        len++;
        return 1;
    }
    
    bool deleteFront() {
        if(len == 0)
            return false;
        front = (front == k - 1) ? 0 : front + 1;
        len--;
        return true;
    }
    
    bool deleteLast() {
        if(len == 0)
            return false;
        back = (back == 0) ? k - 1 : back - 1;
        len--;
        return true;
    }
    
    int getFront() {
        return (len == 0) ? -1 : dq[front];
    }
    
    int getRear() {
        return (len == 0) ? -1 : dq[back];
    }
    
    bool isEmpty() {
        return len == 0;
    }
    
    bool isFull() {
        return len == k;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
