#include <iostream>
using namespace std;

struct Patient {
    int id;
    Patient* previous;
    Patient* next;
    
    Patient(int patientID) {
        id = patientID;
        previous = nullptr;
        next = nullptr;
    }
};

class EmergencyQueue {
private:
    Patient* firstPatient;
    Patient* lastPatient;
    
public:
    EmergencyQueue() {
        firstPatient = nullptr;
        lastPatient = nullptr;
    }
    
    ~EmergencyQueue() {
        Patient* current = firstPatient;
        while (current != nullptr) {
            Patient* nextPatient = current->next;
            delete current;
            current = nextPatient;
        }
    }

    void addCriticalPatient(int patientID) {
        Patient* newPatient = new Patient(patientID);
        
        if (firstPatient == nullptr) {
            firstPatient = newPatient;
            lastPatient = newPatient;
        } else {
            newPatient->next = firstPatient;
            firstPatient->previous = newPatient;
            firstPatient = newPatient;
        }
        cout << " Critical patient " << patientID << " added to front" << endl;
    }
    
    void addNormalPatient(int patientID) {
        Patient* newPatient = new Patient(patientID);
        
        if (lastPatient == nullptr) {
            firstPatient = newPatient;
            lastPatient = newPatient;
        } else {
            lastPatient->next = newPatient;
            newPatient->previous = lastPatient;
            lastPatient = newPatient;
        }
        cout << "  Patient " << patientID << " added to end" << endl;
    }
    
    void addPatientAtPosition(int patientID, int position) {
        if (position < 1) {
            cout << "  Invalid position  Must be 1 or higher" << endl;
            return;
        }
        
        if (position == 1) {
            addCriticalPatient(patientID);
            return;
        }
        
        Patient* newPatient = new Patient(patientID);
        Patient* current = firstPatient;
        int currentPosition = 1;
        
        while (current != nullptr && currentPosition < position - 1) {
            current = current->next;
            currentPosition++;
        }
        
        if (current == nullptr) {
            cout << "  Position " << position << " is beyond queue, adding to end" << endl;
            addNormalPatient(patientID);
            delete newPatient;
        } else if (current == lastPatient) {
            lastPatient->next = newPatient;
            newPatient->previous = lastPatient;
            lastPatient = newPatient;
            cout << "  Patient " << patientID << " inserted at position " << position << endl;
        } else {
            newPatient->next = current->next;
            newPatient->previous = current;
            current->next->previous = newPatient;
            current->next = newPatient;
            cout << "  Patient " << patientID << " inserted at position " << position << endl;
        }
    }
    
    void treatFirstPatient() {
        if (firstPatient == nullptr) {
            cout << "  Queue is empty - no patients to treat" << endl;
            return;
        }
        
        Patient* treated = firstPatient;
        int patientID = treated->id;
        
        if (firstPatient == lastPatient) {
            firstPatient = nullptr;
            lastPatient = nullptr;
        } else {
            firstPatient = firstPatient->next;
            firstPatient->previous = nullptr;
        }
        
        delete treated;
        cout << "  Patient " << patientID << " is treated and discharged" << endl;
    }
    
    // Display queue from first to last
    void showQueue() {
        Patient* current = firstPatient;
        cout << "Current queue: ";
        while (current != nullptr) {
            cout << "[" << current->id << "]";
            if (current->next != nullptr) cout << " -> ";
            current = current->next;
        }
        cout << endl;
    }
    
    void showQueueReverse() {
        Patient* current = lastPatient;
        cout << "Reverse view: ";
        while (current != nullptr) {
            cout << "[" << current->id << "]";
            if (current->previous != nullptr) cout << " -> ";
            current = current->previous;
        }
        cout << endl;
    }
    
    void showQueueStatus() {
        cout << "Queue: ";
        if (firstPatient == nullptr) {
            cout << "Empty";
        } else {
            Patient* current = firstPatient;
            while (current != nullptr) {
                cout << current->id;
                if (current->next != nullptr) cout << " -> ";
                current = current->next;
            }
        }
        cout << endl;
        
        if (firstPatient != nullptr) {
            cout << "First: " << firstPatient->id << "  Last: " << lastPatient->id << endl;
        }
    }
    
    
    int getFirstPatient() {
        if (firstPatient == nullptr) {
            return -1; 
        }
        return firstPatient->id;
    }
    
    int getLastPatient() {
        if (lastPatient == nullptr) {
            return -1; 
        }
        return lastPatient->id;
    }
};

int main() {
    cout << " HOSPITAL EMERGENCY ROOM QUEUE SYSTEM" << endl;
    cout << "---------------------------------------" << endl << endl;
    
    EmergencyQueue queue;
    
    cout << "Starting with empty queue:" << endl;
    queue.showQueueStatus();
    cout << endl;
    
   
    cout << "Step 1 Adding 1ST Node: ";
    queue.addNormalPatient(101);
    queue.showQueueStatus();
    cout << endl;
    
    
    cout << " Adding 2nd Node for Normal Patient: ";
    queue.addNormalPatient(102);
    queue.showQueueStatus();
    cout << endl;
    
    
    cout << " Adding 3rd Nodefor Critical patient: ";
    queue.addCriticalPatient(200);
    queue.showQueueStatus();
    cout << endl;
    
    
    cout << " Adding 4th Node for patient at position: ";
    queue.addPatientAtPosition(150, 2);
    queue.showQueueStatus();
    cout << endl;
    
  
    cout << " Treat 1st Patient: ";
    queue.treatFirstPatient();
    queue.showQueueStatus();
    cout << endl;
    
    
    cout << "Adding Normal Patient ";
    queue.addNormalPatient(300);
    queue.showQueueStatus();
    cout << endl;
    
  
    cout << " FINAL RESULTS:" << endl;
    cout << "-----------------" << endl;
    cout << "First patient: " << queue.getFirstPatient() << endl;
    cout << "Last patient: " << queue.getLastPatient() << endl;
    
    cout << "Queue order in Farward: ";
    queue.showQueue();
    
    cout << "Queue in Reverse order: ";
    queue.showQueueReverse();
    
    return 0;
}