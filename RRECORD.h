#ifndef RRECORD_H_INCLUDED
#define RRECORD_H_INCLUDED

#define NULL ((void *)0)
typedef struct record{
    char First_Name[20];
    char Last_Name[20];
    char age;
    char gender;
    int ID; //ID
    struct record* pnext;

}record_node;

typedef enum
{
    admin_mode=1,
    user_mode
}ClinicSystemMode;

typedef enum
{
    Edit_First_Name=1,
    Edit_Last_Name,
    Edit_Age,
    Edit_Gender,
    Edit_ID
}Edit_options;

typedef enum {
DONE=0,
NOT_FOUND=1,
EMPTY=2,
}Edit_Status;

record_node* create_node(void);
volatile record_node* HEAD;
void init_list_of_records(record_node**head);

void record_scan(record_node* new_record_node);

void record_print(record_node* current);
//Edit_Status List_editNode(record_node*head,int old_data,int new_data);
//
//Edit_Status List_insertNode(record_node* head,int prev_ID,int new_ID); // to insert depending on the data
//
//void List_DeleteNode(record_node** head,int s16Input);




#endif // RRECORD_H_INCLUDED
