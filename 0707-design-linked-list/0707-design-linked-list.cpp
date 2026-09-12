class Node {
public:
    int value;
    Node* next;

    Node(int v) {
        value = v;
        next = nullptr;
    }
};

class MyLinkedList {
private:
    Node* head;
    int size;

public:

    MyLinkedList() {
        head = new Node(0);   // dummy node
        size = 0;
    }

    int get(int index) {

        if (index < 0 || index >= size) {
            return -1;
        }

        Node* current = head->next;

        for (int i = 0; i < index; i++) {
            current = current->next;
        }

        return current->value;
    }

    void addAtHead(int val) {

        Node* newNode = new Node(val);

        newNode->next = head->next;
        head->next = newNode;

        size++;
    }

    void addAtTail(int val) {

        Node* newNode = new Node(val);

        Node* current = head;

        while (current->next != nullptr) {
            current = current->next;
        }

        current->next = newNode;

        size++;
    }

    void addAtIndex(int index, int val) {

        if (index < 0 || index > size) {
            return;
        }

        Node* current = head;

        // Move to node just before index
        for (int i = 0; i < index; i++) {
            current = current->next;
        }

        Node* newNode = new Node(val);

        newNode->next = current->next;
        current->next = newNode;

        size++;
    }

    void deleteAtIndex(int index) {

        if (index < 0 || index >= size) {
            return;
        }

        Node* current = head;

        // Move to node just before index
        for (int i = 0; i < index; i++) {
            current = current->next;
        }

        Node* nodeToDelete = current->next;

        current->next = nodeToDelete->next;

        delete nodeToDelete;

        size--;
    }
};