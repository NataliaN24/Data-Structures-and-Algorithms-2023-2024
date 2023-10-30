SinglyLinkedListNode* removeDuplicates(SinglyLinkedListNode* list) {

   SinglyLinkedListNode*current=list;

    while(current!=nullptr){

        SinglyLinkedListNode*iterator=current;

        while(iterator->next!=nullptr){

            if(current->data != iterator->next->data){
                iterator=iterator->next;
            }
            else{
                iterator->next=iterator->next->next;

            }

        }
         current=current->next;
    }

    return list;


}
