#include "RRECORD.h"
#include "Admin_Mode.h"
#include "Strings.h"

int Admin_check(void)
{
    int input_password;
    printf("\n**************************************** Clinic System ****************************************\n\
			  \r|Please Enter Your Password: 				                  \n "   );
    int counter=0;
    int i;
    for(i=0; i < NUM_OF_TRAILS; i++)
    {
        scanf("%d",&input_password);
        if( input_password == password )
        {
            printf("\n SECURITY CHECK PASSED \n");
            return 1;
        }
        else
        {
            counter++;
            printf("\n WRONG PASSWORD \n");
            if(counter==3)
            {

                printf("\n THREE WRONG PASSWORDS \n");
                return 0;
            }
        }
    }
}



void Admin_add_record(record_node* head) //adding record from the end side of the list
{
    record_node* new_record_node=create_node();
    record_scan(new_record_node);
    record_node* current=head;
    while(current->pnext!=0)
    {
        current=current->pnext;
    }
    current->pnext=new_record_node;
}

void Admin_record_list_print(record_node* head)
{
    record_node* current=head;
    printf("|************************************ Patient's INFOs **************************************|\n");
    while(current!=0)
    {
        record_print(current);
        current=current->pnext;

    }
    printf("\n========================================================================================\n\n");
    printf("\n");

}

Edit_Status Admin_edit_record(record_node* head,int ID)
{
    record_node* current=head;
    if(head==0)
    {
        return EMPTY;
    }
    while(current!=0)
    {
        if(current->ID == ID)
        {
            record_edit(current);
            return DONE;
        }
        current=current->pnext;

    }
    return NOT_FOUND;

}
