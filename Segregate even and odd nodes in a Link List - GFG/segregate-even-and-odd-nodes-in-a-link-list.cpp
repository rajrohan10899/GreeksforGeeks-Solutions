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
        
        if(head == NULL || head->next == NULL){
            return head;
        }
        
        Node* even = new Node(0);
        Node* odd = new Node(0);
        Node* evenPtr = even;
        Node* oddPtr = odd;
        
        Node* current = head;
        
        while (current != NULL) {
            
            if((current -> data )% 2 == 0) {
                
                evenPtr->next = current;
                evenPtr = evenPtr->next;
            }
            else {
                
                oddPtr->next = current;
                oddPtr = oddPtr->next;
            }
            current = current->next;
        }
        
        if(even->next != NULL) {
            
            evenPtr->next = odd->next;
            oddPtr->next = NULL;
            return even->next;
        }
        return odd->next;
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