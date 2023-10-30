SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
 SinglyLinkedListNode*headMerged=new SinglyLinkedListNode(-1);
    SinglyLinkedListNode* mergedOne=headMerged;

    while(head1!=nullptr&&head2!=nullptr){
        if(head1->data<=head2->data){
            mergedOne->next=head1;
           head1= head1->next;
        }
        else{
            mergedOne->next=head2;
            head2=head2->next;
        }
        mergedOne=mergedOne->next;
    }
    if(head1!=nullptr){
        mergedOne->next=head1;
    }
    if(head2!=nullptr){
        mergedOne->next=head2;
    }
    SinglyLinkedListNode*result=headMerged->next;
    delete headMerged;
    return result;


}
