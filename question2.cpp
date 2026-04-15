#include <iostream>
using namespace std;

class QNode {
public:
    int info;
    QNode* nextPtr;

    QNode(int x) {
        info = x;
        nextPtr = NULL;
    }
};

class LinkedQueue {
    QNode* start;
    QNode* end;

public:
    LinkedQueue() {
        start = end = NULL;
    }

    // Insert at end
    void insertItem(int x) {
        QNode* freshNode = new QNode(x);

        if (start == NULL) {
            start = end = freshNode;
        }
        else {
            end->nextPtr = freshNode;
            end = freshNode;
        }

        cout << "Inserted into Queue!\n";
        showQueue();
    }

    // Remove from start
    void removeItem() {
        if (start == NULL) {
            cout << "Underflow! Queue is empty.\n";
            return;
        }

        QNode* temp = start;
        start = start->nextPtr;

        if (start == NULL) {
            end = NULL;
        }

        cout << "Removed value: " << temp->info << endl;
        delete temp;

        showQueue();
    }

    // Return first element
    int firstElement() {
        if (start == NULL) {
            cout << "Queue is empty.\n";
            return -1;
        }
        return start->info;
    }

    // Check empty
    bool emptyCheck() {
        return start == NULL;
    }

    // Print queue
    void showQueue() {
        if (start == NULL) {
            cout << "Queue is empty.\n";
            return;
        }

        QNode* ptr = start;
        cout << "Queue Data: ";
        while (ptr != NULL) {
            cout << ptr->info << " ";
            ptr = ptr->nextPtr;
        }
        cout << endl;
    }
};

int main() {
    LinkedQueue myQueue;
    int option, num;

    while (true) {
        cout << "\n======= QUEUE OPERATIONS =======\n";
        cout << "1. Insert (Enqueue)\n";
        cout << "2. Delete (Dequeue)\n";
        cout << "3. Peek Front\n";
        cout << "4. Check Empty\n";
        cout << "5. Display Queue\n";
        cout << "6. Exit\n";
        cout << "Select option: ";
        cin >> option;

        switch (option) {

        case 1:
            cout << "Enter number: ";
            cin >> num;
            myQueue.insertItem(num);
            break;

        case 2:
            myQueue.removeItem();
            break;

        case 3:
            num = myQueue.firstElement();
            if (num != -1)
                cout << "Front Value: " << num << endl;
            break;

        case 4:
            if (myQueue.emptyCheck())
                cout << "Queue is Empty\n";
            else
                cout << "Queue is NOT Empty\n";
            break;

        case 5:
            myQueue.showQueue();
            break;

        case 6:
            cout << "Program Finished.\n";
            return 0;

        default:
            cout << "Wrong Option!\n";
        }
    }
}