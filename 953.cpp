
#include <iostream>
#include <malloc.h>
using namespace std;
 
typedef struct node{
    int data;
    struct node *next;
}LinkList;
 
int main(){
    int n;
    cin>>n;
    LinkList *l,*end,*body;
    l=(LinkList*)malloc(sizeof(LinkList));
    end=l;
    int num;
    for(int i=0;i<n;i++){
        cin>>num;
        body=(LinkList*)malloc(sizeof(LinkList));
        body->data=num;
        end->next=body;
        end=body;
    }
    end->next=NULL;
    int index;
    cin>>index;
    if(index>1&&index<n){
        LinkList *head1=l;
        for(int i=0;i<index-2;i++){
            head1=head1->next;
        }
        LinkList *head2=l;
        for(int i=0;i<index;i++){
            head2=head2->next;
        }
        head1->next=head2;
        LinkList *head3=l->next;
        while(head3->next!=NULL){
            cout<<head3->data<<' ';
            head3=head3->next;
        }
        cout<<head3->data<<' ';
    }else{
        cout<<"error!";
    }
    return 0;
}