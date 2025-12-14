#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "cafetaria.h"


//function definations for Admin panel

int main(){


printf("Welcome to the Ewu Cafetaria\n ");
printf("Please login to continue\n ");

do{
    printf("Enter your choice to login as:\n ");
    printf("1.As a Admin\n ");
    printf("2.As a Customer\n ");
    printf("As a Manager\n ");
    printf("As a Facility Staff\n ");
    int choice;
    scanf("%d",&choice);
    switch(choice){


        case 1:
            {
                char *username;
                char *password;
                username = (char*)malloc(50*sizeof(char));
                password = (char*)malloc(50*sizeof(char));
                printf("Enter admin username: ");
                scanf("%s",username);

                printf("Enter admin password: ");
                scanf("%s",password);
                if(AdminLogin (username,password)){
                    printf("Login successful!\n");
                    // Admin functionalities can be called here
                    Adminmenu( employeeHead,reviewHead);
                }else{
                    printf("Invalid username or password. Please try again.\n");

                }
                free(username);
                free(password);
                break;

            }
//functionality for coustomer panel

        case 2:

            {
                char *username;
                char *password;
                username = (char*)malloc(50*sizeof(char));
                password = (char*)malloc(50*sizeof(char));
                printf("Enter customer username: ");
                scanf("%s",username);

                printf("Enter customer password: ");
                scanf("%s",password);
                if(coustomerLogin (username,password)){
                    printf("Login successful!\n");
                    // Customer functionalities can be called here
                   coustomermenu(menu,cart,order,review,table,discount,watingtime);   
                }else{
                    printf("Invalid username or password. Please try again.\n");
                }
                free(username);
                free(password);
                break;
            }
        default:
            
            printf("Invalid choice. Please try again.\n");
            break;

        }
    }while(1);
    return 0;

//functionality for manager panel

    case 3:
            {
                char *username;
                char *password;
                username = (char*)malloc(50*sizeof(char));
                password = (char*)malloc(50*sizeof(char));
                printf("Enter manager username: ");
                scanf("%s",username);

                printf("Enter manager password: ");
                scanf("%s",password);
                if(managerLogin (username,password)){
                    printf("Login successful!\n");
                    // Manager functionalities can be called here
                     managermenu(foodHead,menu,tableHead,order,discountHead,watingtimeHead);
                }else{
                    printf("Invalid username or password. Please try again.\n");

                    free(username);
                    free(password);
                    break;
                }

            

}
while (1);
return 0;










}

case 4:
            {
                char *username;
                char *password;
                username = (char*)malloc(50*sizeof(char));
                password = (char*)malloc(50*sizeof(char));
                printf("Enter faculty/staff username: ");
                scanf("%s",username);

                printf("Enter faculty/staff password: ");
                scanf("%s",password);
                if(facultyAndStaffLogin (username,password)){
                    printf("Login successful!\n");
                    // Faculty and Staff functionalities can be called here
                     facultyAndStaffMenu( menu, cart,  order,review,table,discount,watingtime);
                }else{
                    printf("Invalid username or password. Please try again.\n");

                    free(username);
                    free(password);
                    break;
                }

            

}   

while (1);
return 0;

}









