#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* prev;
    ListNode* next;

    ListNode(int x) : val(x), prev(nullptr), next(nullptr) {}
};

class FrontMiddleBack {
public:
    FrontMiddleBack() : head(nullptr), tail(nullptr), size(0) {}

    void pushFront(int val) {
        ListNode* newNode = new ListNode(val);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }

    void pushMiddle(int val) {
        ListNode* newNode = new ListNode(val);
        if (size == 0) {
            head = newNode;
            tail = newNode;
        } else if (size % 2 == 0) {
            ListNode* middle = head;
            for (int i = 0; i < size / 2 - 1; i++) {
                middle = middle->next;
            }
            newNode->prev = middle;
            newNode->next = middle->next;
            middle->next->prev = newNode;
            middle->next = newNode;
        } else {
            ListNode* middle = head;
            for (int i = 0; i < size / 2; i++) {
                middle = middle->next;
            }
            newNode->prev = middle->prev;
            newNode->next = middle;
            middle->prev->next = newNode;
            middle->prev = newNode;
        }
        size++;
    }

    void pushBack(int val) {
        ListNode* newNode = new ListNode(val);
        if (tail == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    int popFront() {
        if (size == 0) {
            return -1;
        }
        int frontVal = head->val;
        if (size == 1) {
            delete head;
            head = nullptr;
            tail = nullptr;
        } else {
            ListNode* nextNode = head->next;
            delete head;
            head = nextNode;
            head->prev = nullptr;
        }
        size--;
        return frontVal;
    }

    int popMiddle() {
        if (size == 0) {
            return -1;
        }
        int middleVal;
        if (size % 2 == 0) {
            ListNode* middle = head;
            for (int i = 0; i < size / 2 - 1; i++) {
                middle = middle->next;
            }
            middleVal = middle->next->val;
            ListNode* nextNode = middle->next->next;
            delete middle->next;
            middle->next = nextNode;
            if (nextNode != nullptr) {
                nextNode->prev = middle;
            }
        } else {
            ListNode* middle = head;
            for (int i = 0; i < size / 2; i++) {
                middle = middle->next;
            }
            middleVal = middle->val;
            ListNode* prevNode = middle->prev;
            ListNode* nextNode = middle->next;
            delete middle;
            if (prevNode != nullptr) {
                prevNode->next = nextNode;
            }
            if (nextNode != nullptr) {
                nextNode->prev = prevNode;
            }
            if (size == 1) {
                head = nullptr;
                tail = nullptr;
            }
        }
        size--;
        return middleVal;
    }

    int popBack() {
        if (size == 0) {
            return -1;
        }
        int backVal = tail->val;
        if (size == 1) {
            delete tail;
            head = nullptr;
            tail = nullptr;
        } else {
            ListNode* prevNode = tail->prev;
            delete tail;
            tail = prevNode;
            tail->next = nullptr;
        }
        size--;
        return backVal;
    }

private:
    ListNode* head;
    ListNode* tail;
    int size;
};

int main() {
    FrontMiddleBack q;

    q.pushFront(1);
    q.pushBack(2);
    q.pushMiddle(3);
    q.pushMiddle(4);

    cout << q.popFront() << endl;  
    cout << q.popMiddle() << endl; 
    cout << q.popMiddle() << endl; 
    cout << q.popFront() << endl;  

    return 0;
}
