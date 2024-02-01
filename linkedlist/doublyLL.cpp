#include <bits/stdc++.h>
using namespace std;
template <typename T>
class doublyLLNode
{

public:
    T data;
    doublyLLNode *next;
    doublyLLNode *prev;
    doublyLLNode(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    };
};

doublyLLNode<int> *getData()
{
    int data;
    cin >> data;
    doublyLLNode<int> *head = NULL;
    doublyLLNode<int> *temp;

    while (data != -1)
    {
        doublyLLNode<int> *n = new doublyLLNode<int>(data);
        if (head == NULL)
        {
            head = n;
            temp = head;
        }
        else
        {
            temp->next = n;
            n->prev = temp;
            temp = temp->next;
        }
        cin >> data;
    }
    return head;
}

void printData(doublyLLNode<int> *head)
{

    if (head == NULL)
    {
        cout << endl;
        return;
    }

    cout << head->data << ' ';
    printData(head->next);

    // singleLLNode<int> *temp = head;

    // while (temp != NULL)
    // {
    //     cout << temp->data << " ";
    //     temp = temp->next;
    //     if (temp == NULL)
    //     {
    //         return;
    //     }
    // }
    // cout << endl;
}

doublyLLNode<int> *insertNode(doublyLLNode<int> *head, int pos, int data)
{
    doublyLLNode<int> *temp = head;
    doublyLLNode<int> *node = new doublyLLNode<int>(data);
    if (pos == 0)
    {
        node->next = head;
        head = node;
        return head;
    }

    while (pos > 1 && temp != NULL)
    {
        temp = temp->next;
        pos--;
        if (temp == NULL)
        {
            return head;
        }
    }
    // cout << temp->data << ' ' << n << ' ' << pos << endl;

    if (temp->next == NULL && temp != NULL)
    {
        temp->next = node;
    }
    else
    {
        doublyLLNode<int> *temp2 = temp->next;
        temp->next = node;
        node->next = temp2;
    }
    return head;
}

doublyLLNode<int> *deleteNode(doublyLLNode<int> *head, int pos)
{
    if (pos == 0 && head->next != NULL && head != NULL)
    {
        head = head->next;
        return head;
    }
    doublyLLNode<int> *temp = head;
    while (pos > 1 && temp != NULL)
    {
        pos--;
        temp = temp->next;
        if (temp == NULL)
        {
            return head;
        }
    }
    temp->next->prev = temp->prev;
    temp->next = temp->next->next;

    return head;
}

int main()
{

    doublyLLNode<int> *head = getData();
    printData(head);
    head = insertNode(head, 3, 6);
    printData(head);
    head = deleteNode(head, 3);
    printData(head);

    // cout << head->next->next->next->prev->data;
    return 0;
}
