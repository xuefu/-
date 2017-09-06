#include <iostream>

using namespace std;

struct Node {
    int val;
    Node* next;
    Node() : val(0), next(NULL) { }
};

Node* reverse_list(Node* head)
{
    Node* new_head = NULL;
    Node* cur = head;
    Node* prev = NULL;

    while (cur != NULL)
    {
        Node* cur_next = cur->next;

        if (cur_next == NULL)
            new_head = cur;

        cur->next = prev;
        prev = cur;
        cur = cur_next;
    }

    return new_head;
}

void destroy_list(Node* node)
{
    Node* tmp = node->next;
    if (tmp != NULL)
    {
        destroy_list(tmp);
    }
    delete node;
}

void print_list(Node* head)
{
    Node* tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

int main() 
{
    Node* head = new Node();

    int len;
    cin >> len;

    Node* tmp = head;
    for (int i = 0; i < len; ++i)
    {
        cin >> tmp->val;
        if (i < len-1)
            tmp->next = new Node();
        tmp = tmp->next;
    }
    print_list(reverse_list(head));

    destroy_list(head);
    head = NULL;
}