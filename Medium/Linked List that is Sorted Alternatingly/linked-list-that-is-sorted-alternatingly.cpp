//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data =x;
	    next = NULL;
	}
};
/* Function to print linked list */


void append(struct Node** headRef, struct Node** tailRef, int newData)
{
	struct Node* new_node = new Node(newData);
	struct Node *last = *headRef;
	if (*headRef == NULL)
	{
	    *headRef = new_node;
	    *tailRef = *headRef;
	    return;
	}
	
	(*tailRef) -> next = new_node;
	*tailRef = (*tailRef) -> next;
}

// A utility function to print a linked list
void printList(Node *head)
{
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}



// } Driver Code Ends

/*
struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data =x;
	    next = NULL;
	}
};
*/

class Solution
{
    public:
    // your task is to complete this function
    void sort(Node **head)
    { vector<int>data;
      vector<int>chi;
      vector<int>final;
      int size=0;
      int i=0;
      Node* c=*head;
         while(c!=0){
             if(i%2==0) data.push_back(c->data);
         
             else{
                 chi.push_back(c->data);
             }
             i++;
             c=c->next;
         }
         for(int i=0,j=chi.size()-1;i<j;i++,j--){
             int temp=chi[i];
             chi[i]=chi[j];
             chi[j]=temp;
         }
    for(int it : data){
             final.push_back(it);
         }
         for(int i=0;i<chi.size();i++){
             final.push_back(chi[i]);
         }
         size=data.size()+chi.size();
         c=*head;
       std::sort(final.begin(), final.end());
        for(int i=0;i<size;i++){
            c->data=final[i];
            c=c->next;
        }
}

};

//{ Driver Code Starts.
int main()
{
	int test;
	cin>>test;
	while(test--)
	{
	    struct Node* head = NULL;
	    struct Node* tail = NULL;
	    int n, k;
	    cin>>n;
	    for(int i=0; i<n ;i++){
	        cin>>k;
	        append(&head, &tail, k);
	    }
	    Solution ob;
	    ob.sort(&head);
	    printList(head);
	}
	return 0;
}

// } Driver Code Ends