#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        // If the list is empty or has one element
        if (!head || !head->next) {
            return nullptr;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;
        
        // Move fast pointer twice as fast and slow pointer once
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // Now slow points to the middle node
        // Remove it by changing the previous node's next
        prev->next = slow->next;

        delete slow;  // Free the memory of the middle node
        return head;
    }
};

// Helper functions to create and print the linked list
ListNode* createList(std::vector<int> values) {
    if (values.empty()) return nullptr;
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    for (int i = 1; i < values.size(); i++) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}

void printList(ListNode* head) {
    while (head) {
        std::cout << head->val <<" ";
        head = head->next;
    }
    //std::cout << "nullptr" << std::endl;
}

int main() {
    Solution solution;

    // Example: Create a linked list 1 -> 2 -> 3 -> 4 -> 5
    vector<int> v;
    int input;
    while (std::cin >> input) {
        v.push_back(input);
    }
    ListNode* head = createList(v);
    
    // std::cout << "Original list: ";
    // printList(head);
    
    head = solution.deleteMiddle(head);
    
    // std::cout << "List after deleting the middle node: ";
    printList(head);
    
    // Cleanup the remaining nodes
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp; // Free memory
    }

    return 0;
}
