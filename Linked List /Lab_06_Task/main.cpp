#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

class Node {
public:
    string data;
    Node* prev;
    Node* next;
    
    Node(string d) {
        data = d;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLL {
public:
    Node* head;
    Node* tail;  
    
    DoublyLL() {
        head = nullptr;
        tail = nullptr;
    }
    
    void insertAtStart(string value) {  
        Node* newNode = new Node(value);
        
        if(head == NULL) {  
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            if(head != NULL) {  
                head->prev = newNode;
            }
            head = newNode;
        }
    }
    
    void showForward() {  
        Node* temp = head;
        if(!temp) {
            cout << "List is empty!" << endl;  
            return;
        }
        
        while(temp != NULL) {  
            cout << temp->data;
            if(temp->next) cout << " -> ";  
            temp = temp->next;
        }
        cout << endl;
    }
    
    void showBackward() {
        if(tail == nullptr) {
            cout << "Nothing to show" << endl;  
            return;
        }
        
        Node* current = tail;
        while(current) {
            cout << current->data;
            if(current->prev) cout << " <- ";
            current = current->prev;
        }
        cout << endl;
    }
    
    void cleanup() {
        Node* current = head;
        while(current) {
            Node* toDelete = current;
            current = current->next;
            delete toDelete;
        }
        head = tail = nullptr;
    }
};

int main() {
    DoublyLL list;  
    
    ifstream file("ips.txt");
    if(!file) {  
        cout << "Can't open file!" << endl;
        return 1;
    }
    
    string line;
    getline(file, line);
    file.close();
    
    stringstream ss(line);
    string ip;
    
    
    while(getline(ss, ip, ',')) {
        list.insertAtStart(ip);
    }
    
    cout << "Forward: " << endl;
    list.showForward();
    
    cout << "\nBackward: " << endl;  
    list.showBackward();
    
    list.cleanup();
    
    return 0;
}
