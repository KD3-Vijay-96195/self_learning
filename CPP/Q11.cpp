#include <iostream>
using namespace std;

class Node
{
private:
    int data;
    Node* next;

    Node(int val)
    {
        data = val;
        next = nullptr;
    }

    friend class SinglyLinkedList; 
};

class SinglyLinkedList
{
private:
    Node* head;

public:
    SinglyLinkedList()
    {
        head = nullptr;
    }

    void add_first(int val)
    {
        Node* newNode = new Node(val);
        newNode->next = head; 
        head = newNode;
    }

    void add_last(int val)
    {
        Node* newNode = new Node(val);
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node* temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode; 
        }
    }

    void display()
    {
        Node* temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " -> "; 
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    SinglyLinkedList list;

    list.add_first(10);
    list.add_first(5);
    list.add_last(20);
    list.add_last(30);

    cout << "Linked List elements:" << endl;
    list.display();

    return 0;
}


