#include <iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int value) : val(value), next(nullptr) {}
};

int findTheWinner(int n, int k) {
    ListNode* head = new ListNode(1);
    ListNode* curr = head;
    for (int i = 2; i <= n; i++) {
        curr->next = new ListNode(i);
        curr = curr->next;
    }
    curr->next = head;  

    while (curr->next != curr) {
        for (int i = 0; i < k - 1; i++) {
            curr = curr->next;
        }

        ListNode* temp = curr->next;
        curr->next = curr->next->next;
        delete temp;
    }

    return curr->val;
}

int main() {
    int n = 5;
    int k = 2;
    int winner = findTheWinner(n, k);
    cout << "The winner is friend: " << winner << endl;

    return 0;
}
