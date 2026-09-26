#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

class CircularList
{
private:
    Node* head;

public:
    CircularList()
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
            return;
        }

        Node* temp = head;

        while (temp->next != head)
        {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->next = head;
    }

    
    void insertBeginning(int value)
    {
        Node* newNode = new Node(value);

        if (head == NULL)
        {
            head = newNode;
            newNode->next = head;
            return;
        }

        Node* temp = head;

        while (temp->next != head)
        {
            temp = temp->next;
        }

        newNode->next = head;
        temp->next = newNode;
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
        temp->next = newNode;
    }

    
    void deleteNode(int value)
    {
        if (head == NULL)
        {
            cout << "List is empty!" << endl;
            return;
        }

       
        if (head->data == value && head->next == head)
        {
            delete head;
            head = NULL;
            return;
        }

      
        if (head->data == value)
        {
            Node* last = head;

            while (last->next != head)
            {
                last = last->next;
            }

            Node* temp = head;

            head = head->next;
            last->next = head;

            delete temp;
            return;
        }

        Node* previous = head;
        Node* current = head->next;

        while (current != head)
        {
            if (current->data == value)
            {
                previous->next = current->next;
                delete current;
                return;
            }

            previous = current;
            current = current->next;
        }

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
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        while (temp != head);

        cout << "(back to head)" << endl;
    }
};

int main()
{
    CircularList list;

    int choice, value, position;

    do
    {
        cout << "\n CIRCULAR LINKED LIST " << endl;
        cout << "1. Insert at End" << endl;
        cout << "2. Insert at Beginning" << endl;
        cout << "3. Insert at Position" << endl;
        cout << "4. Delete Node" << endl;
        cout << "5. Print List" << endl;
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

