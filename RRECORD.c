#include "RRECORD.h"
#include <stdio.h>
#include "Strings.h"

static arr[7][5];


void record_scan(record_node* new_record_node)
{
    printf("|************************************ Enter Patient's INFOs **************************************|\n\
							   \r|Please Enter patient's First_Name:                   |\n\ ");
    string_scan(new_record_node->First_Name);
    printf("                  \r|Please Enter patient's Last_Name:                     |\n\ ");
    string_scan(new_record_node->Last_Name);
    printf("                  \r|Please Enter patient's Age:                           |\n\ ");
    fflush(stdin);
    scanf("%d",&new_record_node->age);
    printf("                  \r|Please Enter patient's ID:                            |\n\ ");
    fflush(stdin);
    scanf("%d",&new_record_node->ID);
    printf("                  \r|Please Enter patient's Gender ( M or F ):             |\n\ ");
    fflush(stdin);
    scanf("%c",&new_record_node->gender);
}

void record_print(record_node* current)
{
    printf("\n\n");
    printf("|******* ID = %d **********|\n",current->ID);
    printf("|******* First Name *******|\n");
    string_print(current->First_Name);
    printf("|******* Last Name ********|\n");
    string_print(current->Last_Name);
    printf("|******* Age = %d *********|\n",current->age);
    printf("|******* Gender = %c ******|\n",current->gender);
    printf("*******************************\n");

}

record_node* create_node(void)
{
    record_node* new_record_node=malloc(sizeof(record_node));
    new_record_node->pnext=0;
    return new_record_node;
}
volatile record_node* HEAD;
void init_list_of_records(record_node**head)
{
    (*head)=create_node();
    (*head)->age=0;
    *((*head)->First_Name)=0;
    (*head)->gender=0;
    (*head)->ID=0;
    *((*head)->Last_Name)=0;

}
void record_edit(record_node* current)
{
    printf("|************************************ Edit Options **************************************|\n");
    printf("\r|Please Enter (1) To Edit_First_Name \n\
            \r|Please Enter (2) To Edit_Last_Name  \n\
            \r|Please Enter (3) To Edit_Age        \n\
            \r|Please Enter (4) To Edit_Gender     \n\
            \r|Please Enter (5) To Edit_ID         \n\ ");
     Edit_options Edit;

    scanf(" %d",&Edit);

    switch (Edit)
    {
    case Edit_First_Name:
        string_scan(current->First_Name);
        break;
    case Edit_Last_Name:
        string_scan(current->Last_Name);
        break;
    case Edit_Age:
        scanf(" %d",&current->age);
        break;
    case Edit_Gender:
        scanf(" %c",&current->gender);
        break;
    case Edit_ID:
        scanf(" %c",&current->ID);
        break;
    }
}
//Edit_Status record_edit(node_t*head,int old_data,int new_data)
//{
//    node_t* current=head;
//    if(head==0)
//    {
//        return EMPTY;
//    }
//    while(current!=0)
//    {
//        if(current->data==old_data)
//        {
//            current->data=new_data;
//            return DONE;
//        }
//        current=current->pnext;
//
//    }
//    return NOT_FOUND;
//}
//void record_addNodeToFirst(node_t**head,int data)
//{
//    node_t* newnode_t=create_node(data);
//    newnode_t->pnext=*head;
//    *head=newnode_t;
//}
//Edit_Status record_insertNode(node_t* head,int prev_data,int new_data)
//{
//    if(head==0)
//    {
//        return EMPTY;
//    }
//    node_t* newnode_t=create_node(new_data);
//    node_t* current=head;
//    while(current!=0)
//    {
//        if(current->data==prev_data)
//        {
//            newnode_t->pnext=current->pnext;
//            current->pnext=newnode_t;
//            return DONE;
//        }
//        current=current->pnext;
//    }
//    return NOT_FOUND;
//}
///***************************************************************/
//void record_DeleteNode(node_t** head,int s16Input)
//{
//	/*Initialize current and previous pointers*/
//	node_t * Deletedptr = (node_t*)malloc(sizeof(node_t));
//	node_t * PreviousDeletedptr = (node_t*)malloc(sizeof(node_t));
//    Deletedptr = *head;
//	PreviousDeletedptr = *head;
//
//	/*chack if the list is empty or not*/
//	if(*head == 0)
//	{
//		printf("List is Empty \n");
//	}
//
//	/*check if the Data wanted to delete in the first node_t*/
//	else if(((*head) -> data) == s16Input)
//	{
//		/*Making the head pointing on the second node_t and delete the first one*/
//		*head = Deletedptr -> pnext;
//		free(Deletedptr);
//		Deletedptr=0;
//		return;
//	}
//
//	else if(Deletedptr != 0)
//	{
//		while((Deletedptr != 0)&&((Deletedptr -> data) != s16Input))
//		{
//			/*Searching about the data in which node_t to delete it*/
//			PreviousDeletedptr = Deletedptr;
//			Deletedptr = Deletedptr -> pnext;
//		}
//
//		if( 0 == Deletedptr)
//		{
//			/*Printing that the data not in the list*/
//			printf("Sorry The data You Entered Not Included \n");
//
//		}
//		else
//		{
//			/*Making the previous node_t pointing on the node_t after the deleted one*/
//			PreviousDeletedptr -> pnext = Deletedptr -> pnext;
//			free(Deletedptr);
//			Deletedptr=0;
//		}
//	}
//}
