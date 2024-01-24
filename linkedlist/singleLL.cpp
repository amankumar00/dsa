#include <bits/stdc++.h>
using namespace std;
template <typename T>
class singleLLNode
{
public:
    T data;
    singleLLNode *next;
    singleLLNode(int data)
    {
        this->data = data;
        this->next = NULL; // should be intialised with NULL
    }
};
// elimination condition for data is -1
singleLLNode<int> *getData()
{
    int data;
    cin >> data;
    singleLLNode<int> *head = NULL;
    singleLLNode<int> *temp;
    while (data != -1)
    {
        singleLLNode<int> *n = new singleLLNode<int>(data);
        if (head == NULL)
        {
            head = n;
            temp = head;
        }
        else
        {
            temp->next = n;
            temp = temp->next;
        }
        cin >> data;
    }

    return head;
}

// traversal iterative and recursive

void printData(singleLLNode<int> *head)
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

// insertion into ll
singleLLNode<int> *insertNode(singleLLNode<int> *head, int pos, int data)
{
    singleLLNode<int> *temp = head;
    singleLLNode<int> *node = new singleLLNode<int>(data);
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
        singleLLNode<int> *temp2 = temp->next;
        temp->next = node;
        node->next = temp2;
    }
    return head;
}

// deletion from LL
singleLLNode<int> *deleteNode(singleLLNode<int> *head, int pos)
{
    if (pos == 0 && head->next != NULL && head != NULL)
    {
        head = head->next;
        return head;
    }
    singleLLNode<int> *temp = head;
    while (pos > 1 && temp != NULL)
    {
        pos--;
        temp = temp->next;
        if (temp == NULL)
        {
            return head;
        }
    }
    temp->next = temp->next->next;

    return head;
}

int main()
{
    singleLLNode<int> *head = getData();
    printData(head);
    // head = insertNode(head, 1, 7);
    head = deleteNode(head, 9);
    printData(head);

    return 0;
}