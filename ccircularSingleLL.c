#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node* createNode(int);
void printList();
void createList();

struct node *head=NULL;
struct node *tail=NULL;                     
struct node *temp;
struct node *newnode;
struct node *dnode;

void insert_at_beg(int);
void insert_at_end(int);
void insert_at_pos(int, int);

void delete_at_beg();
void delete_at_end();
void delete_at_pos(int);

int readData();

void search(int);

int main(){
    int data, choice, pos, ch;
	createList();

	do{
		printf("\n1.insert at beg\n2.insert at end\n3.insert at pos\n4.delete at beg\n5.delete at end\n6.delete at pos\n7.search\n");
		
		printf("enter your choice: ");
		scanf("%d", &choice);
		
		switch(choice){
			case 1:data=readData();
			       insert_at_beg(data);
			       break;

			case 2: data=readData();
					insert_at_end(data);
			        break;

			case 3:data=readData();
			       printf("enter position to insert(starts from 1): ");
			       scanf("%d", &pos);
				   insert_at_pos(pos, data);
				   break;

			case 4:delete_at_beg();
			       break;
				   
			case 5:delete_at_end();
			       break;
				   
			case 6:printf("enter position to delete(starts from 1): ");
			       scanf("%d", &pos);
				   delete_at_pos(pos);
				   break;

			case 7: data=readData();
				    search(data);
					break;  

			default:printf("invalid choice\n");
		}	   
        printList();
		printf("do you want to continue(0 to exit)");
		scanf("%d", &ch);
		if(ch==0){
			break;
		}
	}while(1);
	return 0;
}
	
int readData(){
	int data;
	printf("enter element to insert: ");
	scanf("%d", &data);
	return data;
}	

struct node* createNode(int data){
    temp =(struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->next = NULL;
	return temp;
}

void createList(){
	int choice, data;

	do{
		printf("Enter an element: ");
		scanf("%d", &data);

		newnode = createNode(data);

		if(head == NULL){
			head = tail = newnode;
            tail->next=head;
		}
		else{
			tail->next = newnode;
			tail = newnode;
            tail->next=head;
		}

		printList();
		printf("Enter you choice(0 to continue & 1 to exit): ");
		scanf("%d", &choice);

	}while(choice != 1);
}

void insert_at_beg(int ele){
    newnode=createNode(ele);
    temp=head;
    do{
        temp=temp->next;
    }while(temp->next !=head);

    newnode->next=head;
    head=newnode;
    temp->next=head;
}

void insert_at_end(int ele){
    newnode=createNode(ele);
    temp=head;
    do{
        temp=temp->next;
    }while(temp->next !=head);

    temp->next=newnode;
    newnode->next=head;
}

void insert_at_pos(int pos, int ele){
    newnode=createNode(ele);
    temp=head;
    int i=1;
    while(i<pos-1){
        temp=temp->next;
        i++;
    }
    newnode->next=temp->next;
    temp->next=newnode;
}

void delete_at_beg(){
    dnode=head;
    temp=head;
    do{
        temp=temp->next;
    }while(temp->next !=head);

    head=head->next;
    temp->next=head;
    free(dnode);
}

void delete_at_end(){
    temp=head;
    do{
        temp=temp->next;
    }while(temp->next !=head);

    dnode=temp->next;
    temp->next=head;
    free(dnode);
}

void delete_at_pos(int pos){
	temp=head;
	int i=1;
	while(i<pos-1){
		temp=temp->next;
		i++;
	}
	dnode=temp->next;
	temp->next=temp->next->next;
	free(dnode);
}

void search(int x){
	temp=head;
	int flag=0;
	while(temp!=NULL){
		if(temp->data==x){
			flag=1;
			break;
		}
		temp=temp->next;
	}
	if(flag==1){
		printf("search is successful\n");
	}
	else{
		printf("search is not successful\n");
	}
}

void printList(){
    temp=head;
    do{
        printf("%d->", temp->data);
        temp = temp->next;
    }while(temp !=head);
    printf("\n");
}
