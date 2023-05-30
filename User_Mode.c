#include "RRECORD.h"
#include "User_Mode.h"

 Edit_Status User_view_record(record_node* head ,int ID)
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
            record_print(current);
            return DONE;
        }
        current=current->pnext;

    }
    return NOT_FOUND;

}
