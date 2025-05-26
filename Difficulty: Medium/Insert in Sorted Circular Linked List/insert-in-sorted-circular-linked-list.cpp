/* structure for a node
class Node {
 public:
  int data;
  Node *next;

  Node(int x){
      data = x;
      next = NULL;
  }
}; */

class Solution {
  public:
    Node* sortedInsert(Node* head, int data) {
        // code here
        Node* temp = head->next;
        Node* prev = head;
        Node* new_Node = new Node(data);
        if(head->data > data){
            new_Node->next = head;
            while(temp->next != head){
                temp = temp->next;
            }
            temp->next = new_Node;
            return new_Node;
        }
        while(temp->data <= data and prev->data <= temp->data){
            prev = temp;
            temp = temp->next;
        }
        prev->next = new_Node;
        new_Node->next = temp;
        return head;
    }
};