/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
    //     unordered_map<Node*,Node*> m;
    //     for(Node *curr=head;curr!=NULL;curr=curr->next)
    //     {
    //         m[curr]=new Node(curr->val);
    //     }
    //     for(Node *curr=head;curr!=NULL;curr=curr->next)
    //     {
    //         m[curr]->next=m[curr->next];
    //         m[curr]->random=m[curr->random];
    //     }
    //     return m[head];

    // }
    if (head == NULL) return NULL;
        Node *curr=head;
        while(curr!=NULL)
        {
            Node *next=curr->next;
            curr->next=new Node(curr->val);
            curr->next->next=next;
            curr=next;
        }
        for(Node *curr=head;curr!=NULL;curr=curr->next->next)
        {
            curr->next->random=(curr->random==NULL)?NULL:curr->random->next;
        }
        Node *head2=head->next;
        Node *clone=head2;
        for(Node *curr=head;curr!=NULL;curr=curr->next)
        {
            curr->next=curr->next->next;
            clone->next=clone->next?clone->next->next:NULL;
            clone=clone->next;
        }
        return head2;
    }
};