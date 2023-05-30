#include <stdio.h>
#include <stdlib.h>

/************************************************** Self Files Inclusions **********************************************/


#include "RRECORD.h"
#include "Admin_Mode.h"
#include "User_Mode.h"

/***************************************************** Global Variables *************************************************/

ClinicSystemMode mode;
USER_OPTIONS user_options;
ADMIN_OPTIONS admin_options;

void init_Interface(void)
{
    printf("|**************************************** Clinic System ****************************************|\n\
			  \r|Please Enter (1) For Admin Mode				                                |\n\
			  \r|Please Enter (2) For User Mode					                                |\n\
			  \r|***********************************************************************************************|\n");

    /*Scaning from the user the system mode*/
    scanf("%d",&mode);
    if (mode==admin_mode)
    {
        //case admin_mode:
        if(Admin_check()==0)
        {
            return 0;
        }

        /*Printing an interface to the Admin to Choose An Option*/
        printf("|************************************ Welcome In Admin Mode **************************************|\n\
							   \r|Please Enter (1) To Add new patient record.                                                      |\n\
							   \r|Please Enter (2) To Edit patient record.                                                         |\n\
							   \r|Please Enter (3) To Reserve a slot with the doctor.                                              |\n\
							   \r|Please Enter (4) To Cancel reservation.                                                          |\n\
                               \r|Please Enter (5) To Exit from Admin Mode.                                                       |\n\
							   \r|*************************************************************************************************|\n");
        scanf("%d",&admin_options);
        switch (admin_options)
        {
        case Add_record:
            printf("Add_record\n");
//            Admin_add_record(L1,1);
            break;
        case Edit_record:
            printf("Edit_record\n");
            break;
        case Make_reservation:
            printf("Make_reservation\n");
            break;
        case Cancel_reservation:
            printf("Cancel_reservation\n");
            break;
        case Exit_admin:
            printf("Exit_admin\n");
            init_Interface();
            //break;
        }
    }
    //break;
    else if (mode==user_mode)
    {
        printf("|*********************************** Welcome In User Mode **************************************|\n\
							   \r|Please Enter (1) To View patient record.                                                       |\n\
							   \r|Please Enter (2) To View today\'s reservations.                                                |\n\
							   \r|Please Enter (3) To Exit from User Mode.                                                       |\n\
							   \r|***********************************************************************************************|\n");

        scanf("%d",&user_options);
        switch (user_options)
        {
        case view_record:
            printf("view_record\n");
            break;
        case view_reservation:
            printf("view_reservation\n");
            break;
        case Exit_user:
            printf("Exit_user\n");
            init_Interface();
            // break;
        }
        //break;
    }
    else
    {
        printf("Wrong Mode\n");
    }

}
typedef enum
{
    sat=0,
    sun,
    mon,
    tue,
    wed,
    thur,
    fri,
    availble_days=7
} day_t;
typedef enum
{
    slot_1=0,
    slot_2,
    slot_3,
    slot_4,
    slot_5,
    total_slots=5
} slot_t;

static int arr[7][5]= {  {1,0,0,0,11},

    {0,2,0,12,0},

    {0,13,3,0,0},

    {0,0,0,14,4},

    {0,0,15,5,0},

    {16,0,6,0,0},

    {0,7,0,0,0}
};

void print_2d_array(int arr[][5],int row,int col)
{
    int i,j;
    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            printf("%3d",arr[i][j]);
        }
        printf("\n");
    }
}
void User_view_today_reservation(int arr[][5],day_t day)
{
    int j;

    for(j=0; j<5; j++)
    {
        if(arr[day][j] == 0)
        {
           printf("%3d",arr[day][j]);
        }
    }
}
int main()
{


    print_2d_array(arr,7,5);
    User_view_today_reservation(arr,wed);


    return 0;
}
