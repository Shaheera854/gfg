//{ Driver Code Starts
// Program to check if linked list is empty or not
#include<iostream>
using namespace std;
const long long unsigned int MOD = 1000000007;

/* Link list Node */
struct Node
{
    bool data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};


// } Driver Code Ends
/* Below global variable is declared in code for modulo arithmetic
const long long unsigned int MOD = 1000000007; */

/* Link list Node/
struct Node
{
    bool data;   // NOTE data is bool
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
}; */

class Solution
{
    public:
        // Should return decimal equivalent modulo 1000000007 of binary linked list 
        const long long int mod=1e9+7;
        long long int power(int a,int b)
        {
            int res=1;
            while(b)
            {
                if(b&1)
                {
                    b=b-1;
                    res=((res%mod)*(a%mod))%mod;
                }
                else
                {
                    b=b/2;
                    a=(a%mod*a%mod)%mod;
                }
            }
            return res%mod;
        }
        long long unsigned int decimalValue(Node *head)
        {
            Node* temp=head;
            int c=-1;
            long long unsigned int ans=0;
            while(temp!=NULL)
            {
                c++;
                temp=temp->next;
            }
            temp=head;
            while(temp!=NULL)
            {
                long long num=temp->data;
                long long p=power(2,c)%mod;
                long long res=(num*p)%mod;
                ans+=(res%mod);
                c--;
                temp=temp->next;
            }
            return (ans%mod)%mod;
        }
};




//{ Driver Code Starts.

void append(struct Node** head_ref, struct Node **tail_ref, bool new_data)
{

    struct Node* new_node = new Node(new_data);
    
    if (*head_ref == NULL)
       *head_ref = new_node;
    else
       (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}


bool isEmpty(struct Node *head);

/* Driver program to test above function*/
int main()
{
    bool l;
    int i, n, T;

    cin>>T;

    while(T--){
    struct Node *head = NULL,  *tail = NULL;

        cin>>n;
        for(i=1;i<=n;i++)
        {
            cin>>l;
            append(&head, &tail, l);
        }
        Solution obj;
        cout << obj.decimalValue(head) << endl;
    }
    return 0;
}
// } Driver Code Ends