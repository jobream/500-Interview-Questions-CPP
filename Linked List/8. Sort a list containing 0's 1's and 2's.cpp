/*
Date: 22-06-2020
Author: Aman Jain

Problem : Sort a list containing 0's 1's and 2's
Question Link :  https://practice.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1
(Solution to Geeks for geeks)

*/

Method 1 (Two traversals - Count the number of zeros, ones, and twos) O(n)

Node* segregate(Node *head) {
    
     int count1=0,count2=0,count0=0;
     Node * temp=head;
     while(temp){
     
         if(temp->data==0)
         count0++;
         
         if(temp->data==1)
         count1++;
         
         if(temp->data==2)
         count2++;
         temp=temp->next;
         
      }
      
      temp=head;
      while(count0 --){
          temp->data=0;
          temp=temp->next;
      }
      
      while(count1 --){
          temp->data=1;
          temp=temp->next;
      }
      
      while(count2 --){
          temp->data=2;
          temp=temp->next;
      }
      
      return head;
      
}


Method 2- (Changing Links)

Node* segregate(Node *head) {
    Node *one=NULL,*two=NULL,*zero=NULL,*oned=NULL,*twod=NULL,*zerod=NULL,*temp=head;
    while(temp){
    if(temp->data==0){    
        if(zerod==NULL){
            zerod=temp;
            zero=temp;
        }else{
            zero->next=temp;
            zero=temp;
            zero->next=NULL;
        }
    }
    if(temp->data==1){    
     if(oned==NULL){
        oned=temp;
        one=temp;
       }else{
          one->next=temp;
          one=temp;
          one->next=NULL;
        }
    }
    if(temp->data==2){    
         if(twod==NULL){
          twod=temp;
          two=temp;
        }else{
        two->next=temp;
           two=temp;
           two->next=NULL;
        }
    }
    temp=temp->next;
}
   head=NULL;
if(!zerod){
    if(!oned){
        head=twod;
    }else{
        head=oned;
        if(twod)
        one->next=twod;
    }
}else{
    head=zerod;
    if(oned && twod){
        zero->next=oned;
        one->next=twod;
    }else if(twod){
        zero->next=twod;
    }else if(oned){
        zero->next=oned;
    }else{
        zero->next=NULL;
    }
}
return head;
  

}