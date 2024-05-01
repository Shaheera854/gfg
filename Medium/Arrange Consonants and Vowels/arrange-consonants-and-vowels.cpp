//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    char data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printlist(Node *head) {
    if (head == NULL)
        return;
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void append(struct Node **headRef, char data) {
    struct Node *new_node = new Node(data);
    struct Node *last = *headRef;

    if (*headRef == NULL) {
        *headRef = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    return;
}


// } Driver Code Ends
/*
Structure of the node of the linked list is as
struct Node
{
    char data;
    struct Node *next;

    Node(char x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
  public:
    // task is to complete this function
    // function should return head to the list after making
    // necessary arrangements
    struct Node* arrangeCV(Node* head) {
    Node* vowels = new Node('@'); // Dummy node for vowels
    Node* vt = vowels; // Pointer to the beginning of the vowels list
    Node* consonants = new Node('$'); // Dummy node for consonants
    Node* ct = consonants; // Pointer to the beginning of the consonants list
    Node* temp = head; // Temporary pointer to traverse the original list

    while (temp != NULL) {
        Node* newNode = new Node(temp->data); // Create a new node with the same data
        if (temp->data == 'a' || temp->data == 'e' || temp->data == 'i' || temp->data == 'o' || temp->data == 'u') {
            vowels->next = newNode; // Append to the vowels list
            vowels = vowels->next; // Move the vowels pointer forward
        } else {
            consonants->next = newNode; // Append to the consonants list
            consonants = consonants->next; // Move the consonants pointer forward
        }
        temp = temp->next; // Move to the next node in the original list
    }

    vowels->next = ct->next; // Connect the end of vowels list to the beginning of consonants list
    ct->next = NULL; // Terminate the consonants list
    Node* result = vt->next; // Result is the list of vowels followed by consonants
    delete vt; // Delete the dummy node for vowels
    delete ct; // Delete the dummy node for consonants
    return result; // Return the arranged list
}
};


//{ Driver Code Starts.

// task is to complete this function
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        char tmp;
        struct Node *head = NULL;
        cin >> n;
        while (n--) {
            cin >> tmp;
            append(&head, tmp);
        }
        Solution obj;
        head = obj.arrangeCV(head);
        printlist(head);
    }
    return 0;
}

// } Driver Code Ends