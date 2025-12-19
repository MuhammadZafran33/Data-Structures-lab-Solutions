#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

// --- Student Structure ---
struct Student {
    int id;
    string name;
    string dept;
    int semester;
    double cgpa;
    int credits;
    int year;
    Student* next;

    Student(int i, string n, string d, int s, double c, int cr, int y) 
        : id(i), name(n), dept(d), semester(s), cgpa(c), credits(cr), year(y), next(nullptr) {}
};

class EduTrackSystem {
private:
    Student* head;
    int totalCount;

    // Utility: Swap data between two nodes (Used for Bubble/Selection Sort)
    void swapData(Student* a, Student* b) {
        swap(a->id, b->id);
        swap(a->name, b->name);
        swap(a->dept, b->dept);
        swap(a->semester, b->semester);
        swap(a->cgpa, b->cgpa);
        swap(a->credits, b->credits);
        swap(a->year, b->year);
    }

    // ALGORITHM 1: Selection Sort (Used for Task 1 & 3)
    // Efficiency: O(n^2) - Minimal swaps, but many comparisons
    void selectionSort(int taskType) {
        if (!head) return;
        for (Student* i = head; i->next != nullptr; i = i->next) {
            Student* target = i;
            for (Student* j = i->next; j != nullptr; j = j->next) {
                if (taskType == 1) { // Rank: DESC CGPA, then DESC Credits
                    if (j->cgpa > target->cgpa || (j->cgpa == target->cgpa && j->credits > target->credits))
                        target = j;
                }
                else if (taskType == 3) { // Dept: Alphabetical, then Sem ASC, then CGPA DESC
                    if (j->dept < target->dept || 
                       (j->dept == target->dept && j->semester < target->semester) ||
                       (j->dept == target->dept && j->semester == target->semester && j->cgpa > target->cgpa))
                        target = j;
                }
            }
            if (target != i) swapData(i, target);
        }
    }

    // ALGORITHM 2: Bubble Sort (Used for Task 2 & 4)
    // Efficiency: O(n^2) - Good for detecting partially sorted data
    void bubbleSort(int taskType) {
        if (!head) return;
        bool swapped;
        Student* ptr1;
        Student* lptr = nullptr;
        do {
            swapped = false;
            ptr1 = head;
            while (ptr1->next != lptr) {
                bool shouldSwap = false;
                if (taskType == 2) { // Enrollment: Year ASC, then ID ASC
                    if (ptr1->year > ptr1->next->year || (ptr1->year == ptr1->next->year && ptr1->id > ptr1->next->id))
                        shouldSwap = true;
                }
                else if (taskType == 4) { // Name: Alphabetical
                    if (ptr1->name > ptr1->next->name)
                        shouldSwap = true;
                }

                if (shouldSwap) {
                    swapData(ptr1, ptr1->next);
                    swapped = true;
                }
                ptr1 = ptr1->next;
            }
            lptr = ptr1;
        } while (swapped);
    }

public:
    EduTrackSystem() : head(nullptr), totalCount(0) {}

    ~EduTrackSystem() {
        while (head) {
            Student* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void loadData(string filename) {
        ifstream file(filename.c_str());
        if (!file.is_open()) {
            cout << "ERROR: File " << filename << " not found!" << endl;
            return;
        }
        file >> totalCount;
        for (int i = 0; i < totalCount; i++) {
            int id, sem, cr, yr; double c;
            string fn, ln, d;
            if (!(file >> id >> fn >> ln >> d >> sem >> c >> cr >> yr)) break;
            Student* newNode = new Student(id, fn + " " + ln, d, sem, c, cr, yr);
            newNode->next = head;
            head = newNode;
        }
        file.close();
        cout << "Loaded " << totalCount << " records into Linked List." << endl;
    }

    void task1_Ranked() {
        cout << "Running Selection Sort for Task 1..." << endl;
        selectionSort(1);
        ofstream out("ranked_by_cgpa.txt");
        out << "Rank | ID     | Name                 | Dept | Sem | CGPA | Credits | Year\n";
        out << "-----------------------------------------------------------------------\n";
        Student* curr = head; int r = 1;
        while (curr) {
            out << left << setw(5) << r++ << "| " << setw(7) << curr->id << "| " << setw(21) << curr->name 
                << "| " << setw(5) << curr->dept << "| " << setw(4) << curr->semester << "| " 
                << fixed << setprecision(2) << setw(5) << curr->cgpa << "| " << setw(8) << curr->credits << "| " << curr->year << endl;
            curr = curr->next;
        }
        out.close();
    }

    void task2_Enrollment() {
        cout << "Running Bubble Sort for Task 2..." << endl;
        bubbleSort(2);
        ofstream out("sorted_by_enrollment.txt");
        Student* curr = head; int curYr = -1; double sum = 0; int cnt = 0;
        while (curr) {
            if (curr->year != curYr) {
                if (curYr != -1) out << "\nAverage CGPA: " << (sum/cnt) << "\n\n";
                curYr = curr->year; sum = 0; cnt = 0;
                out << "=== YEAR: " << curYr << " ===\n";
            }
            out << curr->id << " | " << curr->name << " | CGPA: " << curr->cgpa << endl;
            sum += curr->cgpa; cnt++;
            curr = curr->next;
        }
        out << "\nAverage CGPA: " << (sum/cnt) << endl;
        out.close();
    }

    void task3_Dept() {
        cout << "Running Selection Sort for Task 3..." << endl;
        selectionSort(3);
        ofstream out("department_analysis.txt");
        Student* curr = head; string curDept = "";
        double sumC = 0; int cnt = 0; double hi = -1, lo = 5;
        while (curr) {
            if (curr->dept != curDept) {
                if (curDept != "") out << "Dept Stats: Avg " << (sumC/cnt) << " | High " << hi << " | Low " << lo << "\n";
                curDept = curr->dept; sumC = 0; cnt = 0; hi = -1; lo = 5;
                out << "\n--- DEPT: " << curDept << " ---\n";
            }
            out << "Sem " << curr->semester << " | " << curr->name << " | CGPA: " << curr->cgpa << endl;
            sumC += curr->cgpa; cnt++;
            if (curr->cgpa > hi) hi = curr->cgpa; if (curr->cgpa < lo) lo = curr->cgpa;
            curr = curr->next;
        }
        out << "Dept Stats: Avg " << (sumC/cnt) << " | High " << hi << " | Low " << lo << endl;
        out.close();
    }

    void task4_Tiers() {
        cout << "Running Bubble Sort for Task 4..." << endl;
        bubbleSort(4); // Sort names alphabetically first
        ofstream out("performance_tiers.txt");
        string labels[] = {"Elite Tier", "High Achievers", "Good Standing", "Satisfactory", "Needs Improvement"};
        for (int i = 0; i < 5; i++) {
            out << "--- " << labels[i] << " ---\n";
            Student* curr = head;
            while (curr) {
                bool inTier = false;
                if (i == 0 && curr->cgpa >= 3.70) inTier = true;
                else if (i == 1 && curr->cgpa >= 3.30 && curr->cgpa < 3.70) inTier = true;
                else if (i == 2 && curr->cgpa >= 3.00 && curr->cgpa < 3.30) inTier = true;
                else if (i == 3 && curr->cgpa >= 2.50 && curr->cgpa < 3.00) inTier = true;
                else if (i == 4 && curr->cgpa < 2.50) inTier = true;
                
                if (inTier) out << curr->name << " (" << curr->cgpa << ")\n";
                curr = curr->next;
            }
            out << endl;
        }
        out.close();
    }
};

int main() {
    EduTrackSystem sys;
    sys.loadData("students_data.txt");
    
    sys.task1_Ranked();
    sys.task2_Enrollment();
    sys.task3_Dept();
    sys.task4_Tiers();

    cout << "\nAll tasks finished. Check your folder for the 4 txt files." << endl;
    return 0;
}