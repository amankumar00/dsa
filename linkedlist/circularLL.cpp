#include <bits/stdc++.h>
using namespace std;

template <typename T>
class circularLLNode
{
public:
    T data;
    circularLLNode *next;
    circularLLNode(int data)
    {
        this->data = data;
        this->next = NULL; // should be intialised with NULL
    }
};

circularLLNode<int> *getData(vector<int> &v)
{
    circularLLNode<int> *head = NULL;
    circularLLNode<int> *temp;
    int i = 0;
    while (i < v.size())
    {

        circularLLNode<int> *newNode = new circularLLNode<int>(v[i]);
        if (head == NULL)
        {
            head = newNode;
            temp = head;
        }
        else
        {
            circularLLNode<int> *t2 = temp;
            temp = newNode;
            t2->next = temp;
            temp->next = head;
        }
        i++;
    }

    return head;
}

void printData(circularLLNode<int> *head)
{

    // if (head == NULL)
    // {
    //     cout << endl;
    //     return;
    // }

    // cout << head->data << ' ';
    // printData(head->next);

    circularLLNode<int> *temp = head;

    do
    {
        cout << temp->data << " ";
        temp = temp->next;
        if (temp == NULL)
        {
            return;
        }
    } while (temp != head);
    cout << endl;
}

circularLLNode<int> *insertNode(circularLLNode<int> *head, int pos, int data)
{
    circularLLNode<int> *temp = head;
    circularLLNode<int> *node = new circularLLNode<int>(data);
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
        circularLLNode<int> *temp2 = temp->next;
        temp->next = node;
        node->next = temp2;
    }
    return head;
}

circularLLNode<int> *deleteNode(circularLLNode<int> *head, int pos)
{
    if (pos == 0 && head->next != NULL && head != NULL)
    {
        head = head->next;
        return head;
    }
    circularLLNode<int> *temp = head;
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
    vector<int> v;
    int a;
    while (cin >> a)
    {
        v.push_back(a);
    }
    circularLLNode<int> *head = getData(v);
    printData(head);
    // cout<<head->next->next->data;
    head = insertNode(head, 3, 4);
    printData(head);
    head = deleteNode(head, 3);
    printData(head);
    return 0;
}