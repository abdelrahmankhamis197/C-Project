

#ifndef ADMIN_MODE_H_INCLUDED
#define ADMIN_MODE_H_INCLUDED

#define NUM_OF_TRAILS 3


static const int password = 1234;

typedef enum{
Add_record=1,
Edit_record,
Make_reservation,
Cancel_reservation,
Exit_admin
}ADMIN_OPTIONS;

int Admin_check(void);

void Admin_add_record(record_node* L1);

void Admin_record_list_print(record_node* head);

Edit_Status Admin_edit_record(record_node* head,int ID);
//
//Admin_reserve_slot();
//
//Admin_cancel_slot();

#endif // ADMIN_MODE_H_INCLUDED
