#include <iostream>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) {
            return NULL;
        }

        Node* temp = head;
        while (temp != NULL) {
            Node* next = temp->next;
            Node* newNode = new Node(temp->val);
            newNode->next = temp->next;
            temp->next = newNode;
            temp = next;
        }

        temp = head;
        while (temp != NULL) {
            Node* rand = temp->random;
            if (rand == NULL) {
                temp->next->random = NULL;
            } else {
                temp->next->random = rand->next;
            }
            temp = temp->next->next;
        }

        Node* ans = head->next;
        temp = head;
        Node* n = NULL;
        while (temp != NULL) {
            n = temp->next;
            if (n != NULL) {
                temp->next = temp->next->next;
            } else {
                temp->next = NULL;
            }
            temp = n;
        }
        return ans;
    }
};

// Function to print the list with the random pointers
void printList(Node* head) {
    while (head != NULL) {
        cout << "Node value: " << head->val;
        if (head->random != NULL) {
            cout << ", Random points to: " << head->random->val << endl;
        } else {
            cout << ", Random points to: NULL" << endl;
        }
        head = head->next;
    }
}

int main() {
    // Create the linked list
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);

    // Linking the nodes together
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    // Setting random pointers
    node1->random = node3;  // 1 -> random points to 3
    node2->random = node1;  // 2 -> random points to 1
    node3->random = node2;  // 3 -> random points to 2
    node4->random = node4;  // 4 -> random points to 4

    // Print original list
    cout << "Original List:\n";
    printList(node1);

    // Create solution object
    Solution sol;
    Node* copiedHead = sol.copyRandomList(node1);

    // Print copied list
    cout << "\nCopied List:\n";
    printList(copiedHead);

    return 0;
}
