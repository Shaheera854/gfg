//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};

/* Function to print linked list */
void printList(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}




// } Driver Code Ends
//User function Template for C++

/*Link list node
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};*/

class Solution
{
    public:
    Node* insertionSort(struct Node* head)
    {
        //code here
        struct Node* temp=head->next;
        struct Node* prev=head;
        while(temp){
            struct Node* temp1=temp->next;
            if(temp->data<prev->data){
                if(temp->data<=head->data){
                    temp->next=head;
                    if(head->next==temp)
                    head->next=temp1;
                    head=temp;
                }
                else{
                    struct Node* temp2=head;
                    struct Node* temp3=head->next;
                    while(temp->data>temp3->data){
                        temp2=temp2->next;
                        temp3=temp3->next;
                    }
                    temp2->next=temp;
                    temp->next=temp3;
                }
                prev->next=temp1;
            }
            else
            prev=temp;
            temp=temp1;
        }
        return head;
    }
    
};

//{ Driver Code Starts.
int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int n;
		cin >> n;

		Node *head = NULL;
		Node *temp = head;

		for (int i = 0; i < n; i++) {
			int data;
			cin >> data;
			if (head == NULL)
				head = temp = new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}

        Solution ob;

		head = ob.insertionSort(head);
		printList(head);

		cout << "\n";



	}
	return 0;
}
// } Driver Code Ends