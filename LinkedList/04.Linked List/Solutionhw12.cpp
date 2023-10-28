inglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position) {
        if(position==0){
         SinglyLinkedListNode* newOne=new SinglyLinkedListNode(data);
        llist=newOne;
            }
    else{
        SinglyLinkedListNode*current=llist;
        SinglyLinkedListNode*previous=nullptr;
        
        for(int i=0;i<position;++i)
        {
            if(current!=nullptr)
            {
                previous=current;
                current=current->next;
            }
            else{
                return llist;
            }
        }
        previous->next=new SinglyLinkedListNode(data);
        previous->next->next=current;
        
    }
    return llist;

}
