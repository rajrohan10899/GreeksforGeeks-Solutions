//{ Driver Code Starts
#include <bits/stdc++.h>

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

using namespace std;

void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}

Node* flatten (Node* root);

int main(void) {

	int t;
	cin>>t;
	while(t--){
    int n,m,flag=1,flag1=1;
    struct Node * temp=NULL;
	struct Node * head=NULL;
	struct Node * pre=NULL;
	struct Node * tempB=NULL;
	struct Node * preB=NULL;
		cin>>n;
        int work[n];
		for(int i=0;i<n;i++)
            cin>>work[i];
		for(int i=0;i<n;i++){
			m=work[i];
			--m;
			int data;
			scanf("%d",&data);
			temp = new Node(data);
			temp->next = NULL;
			temp->bottom = NULL;
			
			if(flag){
				head = temp;
				pre = temp;
				flag = 0;
				flag1 = 1;
			}
			else{
				pre->next = temp;
				pre = temp;
				flag1 = 1;
			}
			for(int j=0;j<m;j++){
				
				int temp_data;
				scanf("%d",&temp_data);
				tempB = new Node(temp_data);

				if(flag1){
					temp->bottom=tempB;
					preB=tempB;
					flag1=0;
				}
				else{
					preB->bottom=tempB;
					preB=tempB;
				}
			}
		}
		   Node *fun = head;
		   Node *fun2=head;

            Node* root = flatten(head);
            printList(root);
            cout<<endl;

	}
	return 0;
}

// } Driver Code Ends


/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

/*  Function which returns the  root of 
    the flattened linked list. */
    
Node* mergeTwoLists(Node* a, Node* b)
{   //temp and res is dummy node:
    Node* temp = new Node(0);
    Node* res = temp;
    
    //Two pointer a and b a is pointing to first LL head && b is pointing to second LL head:
    while(a != NULL && b != NULL)
    {   
        //comparing a and b data whichever is smaller we take that node:
        if(a->data <= b->data)
        {
            temp->bottom = a; // pointing temp->bottom to that node which a here.
            temp = temp->bottom; // move the temp pointer to bottom node.
            a = a->bottom; // so we consider a is smaller so we move a to the next node (a->bottom).
        }
        // this else is same as 'a' above.
        else{
            temp->bottom = b;
            temp = temp->bottom;
            b = b->bottom;
        }
    }
    //This is for cases "where either of element a is left or element of b is left."
    if(a) temp->bottom = a; // This is for incase "a-element is left whe simply take all the rest element"
    else temp->bottom = b; // This is for incase "b-element is left whe simply take all the rest element"
    
    //In this way linkedlist got flatten || afterwards we return res->bottom because "temp is assign to res"
    return res->bottom;
}
Node *flatten(Node *root)
{
   // Your code here
   if(root == NULL || root->next == NULL) return root;
   
   //recur for list on right.
   root->next = flatten(root->next);
   
   //Now merge the are two guy like L1 and L2(root and root->next). and after merge we assign them into root.
   root = mergeTwoLists(root, root->next);
   
   //After merge of two LL ut becomes one LL (root) simply return it.
   return root;
}
