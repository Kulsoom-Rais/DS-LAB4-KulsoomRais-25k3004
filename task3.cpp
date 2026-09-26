#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
    Node* prev;

    Node(int value)
    {
        data = value;
        next = NULL;
        prev = NULL;
    }
};

class CircularDoublyList
{
private:
    Node* head;

public:
    CircularDoublyList()
    {
        head = NULL;
    }

    
    void insertEnd(int value)
    {
        Node* newNode = new Node(value);

        if (head == NULL)
        {
            head = newNode;

            newNode->next = head;
            newNode->prev = head;

            return;
        }

        Node* last = head->prev;

        newNode->next = head;
        newNode->prev = last;

        last->next = newNode;
        head->prev = newNode;
    }

    
    void insertBeginning(int value)
    {
        Node* newNode = new Node(value);

        if (head == NULL)
        {
            head = newNode;

            newNode->next = head;
            newNode->prev = head;

            return;
        }

        Node* last = head->prev;

        newNode->next = head;
        newNode->prev = last;

        last->next = newNode;
        head->prev = newNode;

        head = newNode;
    }

    
    void insertAtPosition(int value, int position)
    {
        if (position <= 0)
        {
            cout << "Invalid position!" << endl;
            return;
        }

        if (position == 1)
        {
            insertBeginning(value);
            return;
        }

        if (head == NULL)
        {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head;

        for (int i = 1; i < position - 1; i++)
        {
            temp = temp->next;

            if (temp == head)
            {
                cout << "Position out of range!" << endl;
                return;
            }
        }

        Node* newNode = new Node(value);

        newNode->next = temp->next;
        newNode->prev = temp;

        temp->next->prev = newNode;
        temp->next = newNode;
    }

    
    void deleteNode(int value)
    {
        if (head == NULL)
        {
            cout << "List is empty!" << endl;
            return;
        }

        Node* current = head;

        do
        {
            if (current->data == value)
            {
                
                if (current->next == current)
                {
                    delete current;
                    head = NULL;
                    return;
                }

                
                if (current == head)
                {
                    Node* last = head->prev;
                    Node* newHead = head->next;

                    last->next = newHead;
                    newHead->prev = last;

                    head = newHead;

                    delete current;
                    return;
                }

                
                current->prev->next = current->next;
                current->next->prev = current->prev;

                delete current;
                return;
            }

            current = current->next;

        }
        while (current != head);

        cout << "Node not found!" << endl;
    }

    void display()
{
    if (head == NULL)
    {
        cout << "List is empty!" << endl;
        return;
    }

    Node* temp = head;

    do
    {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    while (temp != head);

    cout << "(back to head)" << endl;
}



    
   
};

int main()
{
    CircularDoublyList list;

    int choice, value, position;

    do
    {
        cout << "\n===== CIRCULAR DOUBLY LINKED LIST =====" << endl;
        cout << "1. Insert at End" << endl;
        cout << "2. Insert at Beginning" << endl;
        cout << "3. Insert at Position" << endl;
        cout << "4. Delete Node" << endl;
        cout << "5. Print " << endl;
        cout << "6. Exit" << endl;

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            list.insertEnd(value);
            break;

        case 2:
            cout << "Enter value: ";
            cin >> value;
            list.insertBeginning(value);
            break;

        case 3:
            cout << "Enter value: ";
            cin >> value;

            cout << "Enter position: ";
            cin >> position;

            list.insertAtPosition(value, position);
            break;

        case 4:
            cout << "Enter value to delete: ";
            cin >> value;
            list.deleteNode(value);
            break;

        case 5:
        	list.display();
        	break;
        	
        case 6:
            cout << "Program ended." << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
        }

    }
    while (choice != 6);

    return 0;
}

