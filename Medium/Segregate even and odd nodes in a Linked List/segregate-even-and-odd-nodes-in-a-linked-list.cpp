//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/*
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution{
public:
    Node* divide(int N, Node *head){
        // code here
        Node* prfo=nullptr;
        Node* temp=head;
        Node* fo=nullptr;
        while(temp){
            if(temp->data%2){
                fo=temp;
                break;
            }
            prfo=temp;
            temp=temp->next;
        } 
        temp=head;
        Node* fe=nullptr;
        Node* prfe=nullptr;
        while(temp){
            if(temp->data%2==0){
                fe=temp;
                break;
            }
            prfe=temp;
            temp=temp->next;
        }
        if(fe==nullptr or fo==nullptr)
        return head;
        Node* t1=fo;
        Node* p1=fe;
        Node* t2=fe->next;
        if(t2==nullptr){
            prfe->next=nullptr;
            fe->next=head;
            head=fe;
            return head;
        }
        //cout<<fo->data<<" "<<fe->data<<" "<<prfe->data<<" "<<endl;
        while(t2->next){
            if(t2->data%2==0){
                if(p1->next==t2){
                    p1=p1->next;
                }
                else{
                    p1->next=t2;
                    p1=p1->next;
                }
            }
            else{
                if(prfe){
                    prfe->next=t2;
                    prfe=prfe->next;
                }
                else{
                    prfe=t2;
                }
            }
            t2=t2->next;
        }
        if(t2->data%2==0){
            if(p1 and p1->next!=t2){
                p1->next=t2;
            }
            p1=t2;
        }
        else{
            if(prfe and prfe->next!=t2){
                prfe->next=t2;
            }
            prfe=t2;
        }
        prfe->next=nullptr;
        p1->next=fo;
        return fe;
    }
};

//{ Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}

// } Driver Code Ends