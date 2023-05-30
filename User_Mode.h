#ifndef USER_MODE_H_INCLUDED
#define USER_MODE_H_INCLUDED

typedef enum{
view_record=1,
view_reservation,
Exit_user
}USER_OPTIONS;

Edit_Status User_view_record(record_node* head ,int ID);
//
//User_view_reservations();


#endif // USER_MODE_H_INCLUDED
