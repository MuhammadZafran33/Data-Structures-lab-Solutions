#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

class Node{
	public:
		string data;
		Node* prev;
		Node* next;
		
		Node(string data){
			this->data=data;
			this->next=nullptr;
			this->prev=nullptr;
			
		}
};
class DoublyLL{
	public:
		Node* head;
		Node* Tail;
		DoublyLL(){
			head = nullptr;
			Tail = nullptr;
		}
			
	void insertAtBeginning(string value){
			Node* newnode= new Node(value);
			
			if(head == nullptr){
			head =newnode;
			Tail = newnode;
			}
			else
			{
				newnode->next=head;
				head->prev=newnode;
				head=newnode;
			}
		}
	        
	void displayFront()
	{
		Node* temp=head;
		if(temp == nullptr){
			cout<<"the list is Empty";
			return;
		}
	
		while(temp != nullptr){
			cout<<temp->data<<"  ";  
			temp=temp->next;
		}
		cout<<endl;
	}
	        
	void displayBack()
	{
		Node* temp=Tail;
		
		if(temp == nullptr){
			cout<<"the list is Empty";
			return;
		}
		
	  
		while(temp!= nullptr){
			cout<<temp->data<<"   ";  
			temp=temp->prev;
		}
		cout<<endl;
	}
	
	void freeList() {
		Node* current = head;
		while (current != nullptr) {
			Node* nodeToDelete = current; 
			current = current->next;      
			delete nodeToDelete;          
		}
		head = nullptr;  
		Tail = nullptr;  
		cout << "\nMemory freed successfully!" << endl;
	}
};

int main(int argc, char** argv) {
	DoublyLL ll;

	ifstream ip_file("ips.txt");

	if (!ip_file.is_open()) {
		cerr << "Error: Could not open the file 'ips.txt'. Make sure it's in the same directory." << endl;
		return 1;
	}

	string line;
	getline(ip_file, line);
	ip_file.close();

	stringstream ss(line);
	string ip;

	while (getline(ss, ip, ',')) {
		ll.insertAtBeginning(ip);  
	}
	
	cout<<endl;
	
	cout << "Forward traversal: \n"<<endl;
	ll.displayFront();
	
	cout<<endl;
	cout << "Backward traversal: \n"<<endl;
	ll.displayBack();
	
	
	ll.freeList();
	
	return 0;
}
