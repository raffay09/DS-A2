#include <iostream>
using namespace std;

class StackNode {
public:
    int value;
    StackNode* link;

    StackNode(int x) {
        value = x;
        link = NULL;
    }
};

class LinkedStack {
    StackNode* topNode;
    StackNode* lastNode;
    int currentSize;
    int limitSize;

public:
    LinkedStack(int lim) {
        topNode = lastNode = NULL;
        currentSize = 0;
        limitSize = lim;
    }

    void pushElement(int x) {
        if (currentSize == limitSize) {
            cout << "Overflow! Stack limit reached.\n";
            return;
        }

        StackNode* fresh = new StackNode(x);

        if (topNode == NULL) {
            topNode = lastNode = fresh;
        } else {
            fresh->link = topNode;
            topNode = fresh;
        }

        currentSize++;
    }

    void removeTop() {
        if (topNode == NULL) {
            cout << "Stack Underflow! No element to pop.\n";
            return;
        }

        StackNode* hold = topNode;
        topNode = topNode->link;
        hold->link = NULL;
        delete hold;

        currentSize--;

        if (topNode == NULL) {
            lastNode = NULL;
        }
    }

    void printStack() {
        if (topNode == NULL) {
            cout << "Stack is empty.\n";
            return;
        }

        StackNode* ptr = topNode;
        while (ptr != NULL) {
            cout << ptr->value << " ";
            ptr = ptr->link;
        }
        cout << endl;
    }

    int getTop() {
        if (topNode == NULL) {
            cout << "Stack is empty.\n";
            return -1;
        }
        return topNode->value;
    }

    bool checkEmpty() {
        return topNode == NULL;
    }
};

int main() {
    int maxLimit;
    cout << "Enter maximum stack size: ";
    cin >> maxLimit;

    LinkedStack st(maxLimit);

    int option, number;

    while (true) {
        cout << "\n====== STACK MENU ======\n";
        cout << "1. Push Element\n";
        cout << "2. Pop Element\n";
        cout << "3. Show Top\n";
        cout << "4. Check Empty\n";
        cout << "5. Print Stack\n";
        cout << "6. Exit\n";
        cout << "Choose option: ";
        cin >> option;

        switch (option) {
        case 1:
            cout << "Enter number: ";
            cin >> number;
            st.pushElement(number);
            cout << "Inserted Successfully!\n";
            st.printStack();
            break;

        case 2:
            st.removeTop();
            st.printStack();
            break;

        case 3:
            number = st.getTop();
            if (number != -1)
                cout << "Top Value: " << number << endl;
            break;

        case 4:
            if (st.checkEmpty())
                cout << "Stack is Empty.\n";
            else
                cout << "Stack is NOT Empty.\n";
            break;

        case 5:
            st.printStack();
            break;

        case 6:
            cout << "Exiting Program...\n";
            return 0;

        default:
            cout << "Invalid Option!\n";
        }
    }
}