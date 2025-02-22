class Node
{
public:
    int key;
    int value;
    Node* next;
    Node* prev;

    Node(int key, int value)
    {
        this->key = key;
        this->value = value;
        this->next = NULL;
        this->prev = NULL;
    }
};

class LRUCache {
public:
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    unordered_map<int, Node*> mpp;
    int size;
    LRUCache(int capacity) {
        this->head->next = tail;
        this->tail->prev = head;
        this->size = capacity;
    }
    
    int get(int key) {
        if(mpp.find(key) == mpp.end()) return -1;
        Node* temp = mpp[key];
        Node* p = temp->prev;
        Node* N = temp->next;
        p->next = N;
        N->prev = p;
        temp->next = head->next;
        head->next = temp;
        temp->prev = head;
        temp->next->prev = temp;
        return temp->value;
    }
    
    void put(int key, int value) {
        Node* temp;
        if(mpp.find(key) != mpp.end())
        {
            temp = mpp[key];
            temp->value = value;
            Node* p = temp->prev;
            Node* N = temp->next;
            p->next = N;
            N->prev = p;
        }
        else
        {
            if(mpp.size() >= size)
            {
                temp = new Node(key, value);
                mpp.erase(tail->prev->key);
                mpp[key] = temp;
                Node* p = tail->prev->prev;
                Node* N = tail;
                p->next = N;
                N->prev = p;
            }
            else
            {
                temp = new Node(key, value);
                mpp[key] = temp;
            }
        }
        temp->next = head->next;
        head->next = temp;
        temp->prev = head;
        temp->next->prev = temp;
        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
