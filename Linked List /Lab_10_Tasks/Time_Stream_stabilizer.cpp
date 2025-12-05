#include <iostream>
#include <string>
#include <limits>

using namespace std;

// ================================
// NODE STRUCTURE
// ================================
struct TimeCapsule {
    int year;
    string event;
    TimeCapsule* left;
    TimeCapsule* right;

    TimeCapsule(int y, string e) {
        year = y;
        event = e;
        left = NULL;
        right = NULL;
    }
};

// ================================
// BST CLASS
// ================================
class TimeTree {
private:
    TimeCapsule* root;

    // We Insert Year Node by Comparing with ROOT(Less year Node to ;eft and Greater year Node to the right)......................
    TimeCapsule* insertNode(TimeCapsule* node, int year, string event, bool &inserted) {
        if (node == NULL) {
            inserted = true;
            return new TimeCapsule(year, event);
        }

        if (year < node->year) {
            node->left = insertNode(node->left, year, event, inserted);
        } 
        else if (year > node->year) {
            node->right = insertNode(node->right, year, event, inserted);
        } 
        else {
            inserted = false;   // We check duplicate year and cannot insert it.................
        }

        return node;
    }

    // Find minmum the add to the left of the tree...........................................
    TimeCapsule* findMin(TimeCapsule* node) {
        while (node->left != NULL) {
            node = node->left;
        }
        return node;
    }

    // We Delete a node by checking it location on th eleft and right...............
    TimeCapsule* deleteNode(TimeCapsule* node, int year, bool &deleted) {
        if (node == NULL) return NULL;

        if (year < node->year) {
            node->left = deleteNode(node->left, year, deleted);
        }
        else if (year > node->year) {
            node->right = deleteNode(node->right, year, deleted);
        }
        else {
            deleted = true;

            // CASE 1:
            if (node->left == NULL) {
                TimeCapsule* temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == NULL) {
                TimeCapsule* temp = node->left;
                delete node;
                return temp;
            }

            // CASE 3
            TimeCapsule* temp = findMin(node->right);
            node->year = temp->year;
            node->event = temp->event;
            node->right = deleteNode(node->right, temp->year, deleted);
        }

        return node;
    }

    // Search Helper means search for a node....................................
    TimeCapsule* searchNode(TimeCapsule* node, int year) {
        if (node == NULL) return NULL;

        if (year == node->year)
            return node;
        else if (year < node->year)
            return searchNode(node->left, year);
        else
            return searchNode(node->right, year);
    }

    // Inorder printing of Nodes.......................................
    void printInOrder(TimeCapsule* node) {
        if (node == NULL) return;

        printInOrder(node->left);
        cout << node->year << ": " << node->event << endl;
        printInOrder(node->right);
    }

    // Delete Tree Memory By deleting ................................
    void clearTree(TimeCapsule* node) {
        if (node == NULL) return;

        clearTree(node->left);
        clearTree(node->right);
        delete node;
    }

    // Find Maximum of the given......................................
    TimeCapsule* findMax(TimeCapsule* node) {
        while (node->right != NULL) {
            node = node->right;
        }
        return node;
    }

public:
    TimeTree() {
        root = NULL;
    }

    ~TimeTree() {
        clearTree(root);
    }

    // ================================
    // INSERT
    // ================================
    void inject(int year, string event) {
        cout << "> System: Injecting " << year << "... ";

        bool inserted = false;
        root = insertNode(root, year, event, inserted);

        if (inserted)
            cout << "Timeline stable." << endl;
        else
            cout << "Year already exists. No update." << endl;
    }

    // ================================
    // DELETE
    // ================================
    void resolveParadox(int year) {
        cout << "> Alert: Paradox detected at " << year << "!" << endl;

        bool deleted = false;
        root = deleteNode(root, year, deleted);

        if (deleted)
            cout << "> System: Year " << year << " removed. Timeline stabilized." << endl;
        else
            cout << "> System: Year not found." << endl;
    }

    // ================================
    // SEARCH
    // ================================
    void search(int year) {
        cout << "> Query: Searching for " << year << "..." << endl;

        TimeCapsule* result = searchNode(root, year);

        if (result != NULL)
            cout << "> Result: Event Found! [" << result->year << ": " << result->event << "]" << endl;
        else
            cout << "> Result: Year not found in current timeline." << endl;
    }

    // ================================
    // REPORT
    // ================================
    void report() {
        cout << "> COMMAND: CHRONOLOGICAL REPORT" << endl;
        cout << "-------------------------------" << endl;
        printInOrder(root);
        cout << "-------------------------------" << endl;
    }

    // ================================
    // BONUS: TIMESPAN
    // ================================
    int calculateTimeSpan() {
        if (root == NULL) return 0;

        TimeCapsule* minNode = findMin(root);
        TimeCapsule* maxNode = findMax(root);

        return maxNode->year - minNode->year;
    }
};

// ================================
// MAIN FUNCTION
// ================================
int main() {
    TimeTree chronos;

    string command;
    int year;
    string event;

    cout << "--- CHRONOS TIME STABILIZER V1.0 ---" << endl;
    cout << "Waiting for Time Stream Inputs..." << endl << endl;

    while (cin >> command) {

        if (command == "INJECT") {
            cin >> year;
            getline(cin >> ws, event);
            chronos.inject(year, event);
        }
        else if (command == "PARADOX") {
            cin >> year;
            chronos.resolveParadox(year);
        }
        else if (command == "SEARCH") {
            cin >> year;
            chronos.search(year);
        }
        else if (command == "REPORT") {
            chronos.report();
        }
        else if (command == "TIMESPAN") {
            cout << "> System: Current time span is "
                 << chronos.calculateTimeSpan()
                 << " years." << endl;
        }
        else if (command == "EXIT") {
            break;
        }
        else {
            cout << "> Unknown Command." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << endl;
    }

    return 0;
}
