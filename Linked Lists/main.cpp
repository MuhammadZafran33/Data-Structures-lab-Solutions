#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(nullptr) {}
};

// LinkedList class
class LinkedList {
private:
    Node* head;
public:
    LinkedList() : head(nullptr) {}
    
    ~LinkedList() {
        Node* cur = head;
        while (cur) {
            Node* nxt = cur->next;
            delete cur;
            cur = nxt;
        }
    }

    void insertAtBeginning(int value) {
        Node* node = new Node(value);
        node->next = head;
        head = node;  // Fixed: was node = head;
    }
    
    void insertAtEnd(int value) {
        Node* node = new Node(value);
        if (head == nullptr) {
            head = node;  // Fixed: was node = head;
            return;
        }
        Node* cur = head;
        while (cur->next != nullptr) {
            cur = cur->next;
        }
        cur->next = node;
    }
    
    void insertAtPosition(int value, int position) {
        Node* node = new Node(value);
        if (position == 0) {
            node->next = head;
            head = node;  // Fixed: was node = head;
            return;
        }
        Node* cur = head;
        for (int i = 0; cur != nullptr && i < position - 1; i++) {
            cur = cur->next;
        }
        if (cur == nullptr) {
            cout << "Position out of range, inserting at end.\n";
            insertAtEnd(value);
            return;
        }
        node->next = cur->next;
        cur->next = node;
    }
    
    bool deleteFromBeginning(int* removedValue = nullptr) {
        if (head == nullptr) {
            return false;
        }
        Node* temp = head;
        if (removedValue) {
            *removedValue = temp->data;
        }
        head = head->next;
        delete temp;
        return true;
    }
    
    void display() const {
        Node* cur = head;
        while (cur) {
            cout << cur->data;
            if (cur->next) cout << " -> ";
            cur = cur->next;
        }
        cout << "\n";
    }
};

int main() {
    LinkedList list;

    // Step 1: Add 3 passengers at the end
    list.insertAtEnd(101);
    list.insertAtEnd(102);
    list.insertAtEnd(103);
    cout << "Initial Queue after adding passengers:\n";
    list.display();

    // Step 2: Emergency passenger at beginning
    list.insertAtBeginning(999);
    cout << "After adding an emergency passenger at beginning:\n";
    list.display();

    // Step 3: Special booking passenger at position 2
    list.insertAtPosition(555, 2);
    cout << "After inserting special booking passenger at position 2:\n";
    list.display();

    // Step 4: First passenger boards (delete from beginning)
    int removed;
    list.deleteFromBeginning(&removed);
    cout << "After first passenger boards (deletion):\n";
    list.display();

    return 0;
}