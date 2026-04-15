#include <iostream>
using namespace std;

class CircularQueue {
    int startIndex, endIndex, totalItems;
    int maxCap;
    int* dataArr;

public:
    CircularQueue(int cap) {
        maxCap = cap;
        dataArr = new int[maxCap];
        startIndex = 0;
        totalItems = 0;
        endIndex = -1;
    }

    ~CircularQueue() {
        delete[] dataArr;
    }

    bool fullCheck() {
        return totalItems == maxCap;
    }

    bool emptyCheck() {
        return totalItems == 0;
    }

    void insertValue(int x) {
        if (fullCheck()) {
            cout << "Queue Overflow! Cannot insert.\n";
            return;
        }

        endIndex = (endIndex + 1) % maxCap;
        dataArr[endIndex] = x;
        totalItems++;

        cout << x << " inserted successfully.\n";
    }

    void deleteValue() {
        if (emptyCheck()) {
            cout << "Queue Underflow! Nothing to delete.\n";
            return;
        }

        cout << dataArr[startIndex] << " removed successfully.\n";
        startIndex = (startIndex + 1) % maxCap;
        totalItems--;
    }

    int peekFront() {
        if (emptyCheck()) {
            cout << "Queue is empty!\n";
            return -1;
        }
        return dataArr[startIndex];
    }

    int peekRear() {
        if (emptyCheck()) {
            cout << "Queue is empty!\n";
            return -1;
        }
        return dataArr[endIndex];
    }

    void printQueue() {
        if (emptyCheck()) {
            cout << "Queue is empty!\n";
            return;
        }

        cout << "Queue Elements: ";
        int idx = startIndex;

        for (int i = 0; i < totalItems; i++) {
            cout << dataArr[idx] << " ";
            idx = (idx + 1) % maxCap;
        }
        cout << endl;
    }
};

int main() {
    int capacity;
    cout << "Enter size of Circular Queue: ";
    cin >> capacity;

    CircularQueue cq(capacity);

    int option, num;

    while (true) {
        cout << "\n===== CIRCULAR QUEUE OPERATIONS =====\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Front Element\n";
        cout << "4. Rear Element\n";
        cout << "5. Check Empty\n";
        cout << "6. Check Full\n";
        cout << "7. Display\n";
        cout << "8. Exit\n";
        cout << "Enter option: ";
        cin >> option;

        switch (option) {

        case 1:
            cout << "Enter value: ";
            cin >> num;
            cq.insertValue(num);
            cq.printQueue();
            break;

        case 2:
            cq.deleteValue();
            cq.printQueue();
            break;

        case 3:
            num = cq.peekFront();
            if (num != -1)
                cout << "Front Value: " << num << endl;
            break;

        case 4:
            num = cq.peekRear();
            if (num != -1)
                cout << "Rear Value: " << num << endl;
            break;

        case 5:
            if (cq.emptyCheck())
                cout << "Queue is Empty\n";
            else
                cout << "Queue is NOT Empty\n";
            break;

        case 6:
            if (cq.fullCheck())
                cout << "Queue is Full\n";
            else
                cout << "Queue is NOT Full\n";
            break;

        case 7:
            cq.printQueue();
            break;

        case 8:
            cout << "Program Terminated.\n";
            return 0;

        default:
            cout << "Invalid Option!\n";
        }
    }
}