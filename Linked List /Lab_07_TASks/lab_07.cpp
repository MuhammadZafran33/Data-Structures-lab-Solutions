#include<iostream>
#include<conio.h>
#include<iomanip>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int value)
    {
        this->data = value;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class DLL
{
public:
    Node* head;
    Node* tail;

    DLL()
    {
        head = nullptr;
        tail = nullptr;
    }

    ~DLL()
    {
        Node* current = head;
        while (current != nullptr)
        {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
        tail = nullptr;
        cout<<"Destructor succesfully works...";
    }

    void display()
    {
        Node* current = head;

        if (current == nullptr)
        {
            cout << "List is Empty" << endl;
            return;
        }

        while (current != nullptr)
        {
            cout << current->data << endl;
            current = current->next;
        }
    }

    void Display()
    {
        Node* temp = head;
        cout << "\n------------------------------------------------------\n";
        cout << "     Prev Address        |   Data   |     Next Address |   Node Address\n";
        cout << "------------------------------------------------------\n";

        while (temp != nullptr) {
            cout << setw(20) << temp->prev
                << " | " << setw(7) << temp->data
                << " | " << setw(18) << temp->next
                << " | " << setw(20) << temp
                << endl;
            temp = temp->next;
        }
        cout << endl << "Tail: " << tail << endl;
        cout << "------------------------------------------------------\n";
    }

    void DisplayNode(Node* node) {
        if (node == nullptr) {
            cout << "Node is null!" << endl;
            return;
        }
        
        cout << "\n------------------------------------------------------\n";
        cout << "     Prev Address        |   Data   |     Next Address |   Node Address\n";
        cout << "------------------------------------------------------\n";

        cout << setw(20) << node->prev
            << " | " << setw(7) << node->data
            << " | " << setw(18) << node->next
            << " | " << setw(20) << node
            << endl;
        
        cout << "------------------------------------------------------\n";
    }

    void insertAtBegin(int value)
    {
        Node* newNode = new Node(value);

        newNode->next = head;

        if (head != nullptr)
        {
            head->prev = newNode;
        }
        head = newNode;

        if (head->next == nullptr)
        {
            tail = newNode;
        }
    }

    void insertAtPos(int position, int value)
    {
        if (head == nullptr)
        {
            if (position == 1)
            {
                insertAtBegin(value);
            }
            else
            {
                cout << "Invalid Index..!!" << endl;
            }
            return;
        }

        if (position == 1)
        {
            insertAtBegin(value);
            return;
        }

        Node* current = head;
        Node* newNode = new Node(value);

        for (int i = 1; i < position - 1 && current != nullptr; i++)
        {
            current = current->next;
        }

        if (current == nullptr)
        {
            cout << "Invalid position..!!" << endl;
            return;
        }

        cout << "Traversed: " << current << endl;

        newNode->prev = current;
        newNode->next = current->next;
        
        if (current->next != nullptr) {
            current->next->prev = newNode;
        }
        
        current->next = newNode;

        if (newNode->next == nullptr) {
            tail = newNode;
        }
    }

    void deleteFB() {
        if (head == nullptr)
        {
            cout << "List is Empty" << endl;
            return;
        }
        else if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            Node* temp = head;
            head = head->next;
            head->prev = nullptr;
            delete temp;
        }
    }

    void search(int value)
    {
        Node* current = head;

        while (current != nullptr)
        {
            if (current->data == value)
            {
                cout << "Node found...";
                DisplayNode(current);
                return;
            }
            current = current->next;
        }
        cout << "Value not found in the list." << endl;
    }

    void insertAtEnd(int value)
    {
        if (tail == nullptr)
        {
            insertAtBegin(value);
        }
        else
        {
            Node* current = tail;
            Node* newNode = new Node(value);

            current->next = newNode;
            newNode->prev = current;
            newNode->next = nullptr;
            tail = newNode;
        }
    }
};

int main()
{
    DLL list;
    
    list.insertAtBegin(40);
    list.insertAtBegin(30);
    list.insertAtBegin(20);
    list.insertAtBegin(10);
    
    cout << "After adding 4 to the Linked List elements:";
    list.Display();
    
    list.insertAtPos(5, 50);
    cout << "\nAfter adding 5th element at position 5:";
    list.Display();
    
    list.deleteFB();
    cout << "\nAfter deleting the First elemest on linked lixt :";
    list.Display();
    
    cout << "\nSearching for value 30:";
    list.search(30);

    return 0;
}