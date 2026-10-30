#include <stdio.h>
#include <stdlib.h>
typedef struct polynode{
    int coeff;
    int exp;
    struct polynode *next;
}polynode;

polynode* getnode(){
    struct polynode *newnode; 
    newnode = (struct polynode*)malloc(sizeof(struct polynode));  
    printf("Enter Coefficient: ");    
    scanf("%d", &newnode->coeff);
    printf("Enter Exponent: ");
    scanf("%d", &newnode->exp);
    newnode->next = newnode;
    return newnode ; 
}
struct polynode* createHead() {
    struct polynode *head = (struct polynode*)malloc(sizeof(struct polynode));
    head->coeff = 0;
    head->exp = 999;
    head->next = head;
    return head;
}
void insert(polynode *head, polynode *newnode) { 
    polynode *p, *prev; 
    p = head->next; 
    prev = head;
    while(p != head && p->exp > newnode->exp) { 
        prev = p;
        p = p->next;      
    }
    if(p->exp == newnode->exp) {     
        p->coeff = p->coeff + newnode->coeff;
        if(p->coeff == 0) {  
            prev->next = p->next; 
            p->next = NULL;    
            free(p);  
        }         
        free(newnode);
    }
    else{
        newnode->next = p;   
        prev->next = newnode;
    }
}
polynode* create(polynode *head){
    polynode *newnode;
    int i , n ;
    printf("\nEnter the number of terms in the polynomial: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("\nTerm %d:\n", i);
        newnode = getnode();
        insert(head,newnode);
    }
    head->exp=-1;
    return head;
}

polynode* add(polynode *head1 , polynode *head2){
      struct polynode *t1,*t2,*t3;
      struct polynode *head3 = (struct polynode*)malloc(sizeof(struct polynode));
      head3->exp = -1;
      head3->coeff = 0 ;
      head3->next = head3;
      t3 = head3;
      t1= head1->next;
      t2 = head2->next;
      while(t1->exp!=-1 || t2->exp!=-1){
        struct polynode *temp = (struct polynode*)malloc(sizeof(struct polynode));
        if(t1->exp==t2->exp){
           temp->coeff = t1->coeff + t2->coeff;
           temp->exp = t1->exp;
           t1= t1->next;
           t2= t2->next;
           if(temp->coeff==0){
              free(temp);
              continue;
           }
          }
           
        else if(t1->exp<t2->exp){
          temp->coeff = t2->coeff;
          temp->exp = t2->exp;
          t2 = t2->next;
        }
        else{
          temp->coeff = t1->coeff;
          temp->exp = t1->exp;
          t1 = t1->next;
        }
        temp->next = head3;
        t3->next = temp ;
        t3=temp;
       }
       return head3;
}
       


void display(polynode* head){
    polynode *p;
    p = head->next;
    while(1){
        printf("%dx^%d ",p->coeff,p->exp);
        p = p->next;
        if(p==head){
            break;
        }
        if(p->coeff>0){
            printf(" + ");
        }
    }
    printf("\n");
}

int main()
{
    struct polynode *head1=NULL,*head2=NULL,*head3=NULL;
    int x ; 
    do{
      printf("Enter the first polynomial:\n");
      head1 = createHead();
      create(head1);
      printf("first polynomial = \n");
      display(head1);
      
      printf("Enter the second polynomial:\n");
      head2 = createHead();
      create(head2);
      printf("2nd polynomial = \n");
      display(head2);
      //head3 = creatHead();
      head3 = add(head1,head2);
      printf("result polynomial = \n");
      display(head3);
      printf("Enter 1 to continue and 0 to stop:\n");
      scanf("%d",&x);
      }while(x!=0);
      return 0;
  }