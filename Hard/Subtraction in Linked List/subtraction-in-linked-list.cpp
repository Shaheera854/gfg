//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Node Class
class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(NULL) {}
};

// Linked List Class
class LinkedList {
public:
    Node* head;
    Node* tail;

    LinkedList() : head(NULL), tail(NULL) {}

    // creates a new node with given value and appends it at the end of the linked list
    void insert(int val) {
        if (head == NULL) {
            head = new Node(val);
            tail = head;
        } else {
            tail->next = new Node(val);
            tail = tail->next;
        }
    }
};


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    struct Node* reverseList(struct Node *head)
    {
        // code here
        // return head of reversed list
        if(head->next==NULL)
        return head;
        Node* temp=head->next;
        head->next=NULL;
        Node* temp1=head;
        Node* temp2=NULL;
        while(temp->next){
            temp2=temp->next;
            temp->next=temp1;
            temp1=temp;
            temp=temp2;
        }
        temp->next=temp1;
        head=temp;
        return head;
    }
    Node* subLinkedList(Node* head1, Node* head2) {
        // Your implementation of subLinkedList goes here
        // Make sure to return the head of the resulting linked list
        while(head1 and head1->data==0){
            head1=head1->next;
        }
        while(head2 and head2->data==0 )
        head2=head2->next;
        if(head1==NULL and head2==NULL)
        {
            Node* x=new Node(0);
            return x;
        }
        if(head1==NULL)
        return head2;
        if(head2==NULL)
        return head1;
        Node* temp1=head1;
        Node* temp2=head2;
        int c1=0,c2=0;
        while(temp1 and temp2){
            temp1=temp1->next;
            temp2=temp2->next;
        }
        Node* maxi;
        Node* mini;
        if(temp1){
            maxi=head1;
            mini=head2;
        }
        else if(temp2){
            maxi=head2;
            mini=head1;
        }
        else{
            temp1=head1;
            temp2=head2;
            while(temp1 and temp2 and temp1->data==temp2->data){
                temp1=temp1->next;
                temp2=temp2->next;
            }
            if(temp1 and temp2 and temp1->data>temp2->data){
                maxi=head1;
                mini=head2;
            }
            else if(temp1 and temp2){
                maxi=head2;
                mini=head1;
            }
            else{
                Node* x=new Node(0);
                return x;
            }
        }
        head1=reverseList(maxi);
        head2=reverseList(mini);
        temp1=head1;
        temp2=head2;
        Node* head=NULL;
        Node* temp=NULL;
        while(temp1 and temp2){
            if(temp1->data<temp2->data){
                temp1->data+=10;
                temp1->next->data=temp1->next->data-1;
            }
            int x=temp1->data-temp2->data;
            Node* y=new Node(x);
            if(head==NULL){
                head=y;
                temp=head;
            }
            else{
                temp->next=y;
                temp=temp->next;
            }
            temp1=temp1->next;
            temp2=temp2->next;
        }
        while(temp1){
            if(temp1->data==0 and temp1->next==NULL){
                break;
            }
            if(temp1->data<0){
                temp1->data+=10;
                temp1->next->data--;
            }
            temp->next=temp1;
            temp1=temp1->next;
            temp=temp->next;
        }
        head=reverseList(head);
        while(head->data==0)
        head=head->next;
        return head;
    }
};

//{ Driver Code Starts.

// prints the elements of linked list starting with head
void printList(Node* n) {
    while (n) {
        cout << n->data;
        n = n->next;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        LinkedList LL1;
        string l1,l2;
        cin>>l1;
        for (int j = 0; j < n; ++j) {
            int x=(l1[j]-'0');
            LL1.insert(x);
        }

        int m;
        cin >> m;
        LinkedList LL2;
        cin>>l2;
        for (int j = 0; j < m; ++j) {
            int x=(l2[j]-'0');
            LL2.insert(x);
        }

        Solution ob;
        Node* res = ob.subLinkedList(LL1.head, LL2.head);
        printList(res);
    }

    return 0;
}

// } Driver Code Ends