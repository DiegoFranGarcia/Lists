#include "lab6.h"
/*This function is passed a list makes it empty with a dummy node in front of it*/
int makeList(Node **list)
{
    *list=NULL;
    //dummy is created and put in front of list
    Node *dummy;
    dummy=malloc(sizeof(Node));
    //list=malloc(sizeof(Node));
    if(dummy)
    {
        dummy->next=*list;   
    }
    else
    {
        return 1;
    }

    return 0;
}

/*This function gets the size of a list that was passed*/
int getSize(Node *list)
{
    //count is set to -1 instead of 0 because of there being dummy nodes
    int count=-1;
    Node * p=list;
    while(p)
    {
        count++;
        p=p->next;
    }
    //A list could have one NULL variable making the while loop not work, this if statement catches that and makes count 0
    if(count==-1)
    {
        count=0;
    }
    //the count of the list is returned
    return count;
}

/*This function is passed a list and returns the element at the index that was passed*/
void * getAtIndex(Node *list, int index)
{
    Node *p=list;
    //checks to see if index is valid
    if(index<0 || index>getSize(list))
    {
        return NULL;
    }
    //this for loop goes up to the node of index and the data is then returned
    int i;
    for(i=0;i<index;i++)
    {
        p=p->next;
    }
    return p->data;

}

/*This function is passed a list and puts data that was passed to the tail*/
int insertAtTail(Node *list, void *data)
{
    //copy of list goes to the last node
    Node *p=list;
    while(p)
    {
        p=p->next;
    }
    //this newnode is created and data is put into it and is inserted at the tail
    Node *newnode=malloc(sizeof(Node));
    if(newnode)
    {
        newnode->data=data;
        newnode->next=NULL;
        p->next=newnode;
        return 0;
    }
    else
    {
        return 1;
    }

}

/*This function removes a node from the head of the list that was passed*/
void * removeFromHead(Node *list)
{
    //checks to see if list is empty
    if(getSize(list)==0)
    {
        return NULL;
    }
    //this p node is later used to free the old head
    Node *p=list;
    //this sets the dummy to the new node
    list->next=list->next->next;
    //old head is then freed and returned
    void *temp=p->next;
    free(p->next);
    return temp;

}
//This function frees a list that was passed and then sets it to NULL
void freeList(Node **list)
{
    //while loop that will go through each node in list
    while (*list!=NULL)
    {
        Node *temp=*list;
        *list=(*list)->next;
        free(temp);
    }
    *list=NULL;
}
