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

class LinkedList
{
private:
    Node* head;

public:
    LinkedList()
    {
        head = NULL;
    }

    void insertEnd(int value)
    {
        Node* newNode = new Node(value);

        if (head == NULL)
        {
            head = newNode;
            return;
        }

        Node* temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    void display()
    {
        Node* temp = head;

        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }

        cout << "NULL" << endl;
    }

    void evenBeforeOdd()
    {
        Node* evenHead = NULL;
        Node* evenTail = NULL;

        Node* oddHead = NULL;
        Node* oddTail = NULL;

        Node* current = head;

        while (current != NULL)
        {
            Node* nextNode = current->next;

            current->next = NULL;

            if (current->data % 2 == 0)
            {
                if (evenHead == NULL)
                {
                    evenHead = current;
                    evenTail = current;
                }
                else
                {
                    evenTail->next = current;
                    evenTail = current;
                }
            }
            else
            {
                if (oddHead == NULL)
                {
                    oddHead = current;
                    oddTail = current;
                }
                else
                {
                    oddTail->next = current;
                    oddTail = current;
                }
            }

            current = nextNode;
        }

        if (evenHead == NULL)
        {
            head = oddHead;
        }
        else
        {
            head = evenHead;
            evenTail->next = oddHead;
        }
    }
};

int main()
{
    LinkedList list;

    int n, value;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter elements: ";

    for (int i = 0; i < n; i++)
    {
        cin >> value;
        list.insertEnd(value);
    }

    cout << "\nOriginal List: ";
    list.display();

    list.evenBeforeOdd();

    cout << "Modified List: ";
    list.display();

    return 0;
}

