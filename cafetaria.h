/**
 * @file cafetaria.h
 * @brief Header file for Cafetaria Management System
 *       define all stucture and function pototypes 
 * @date 2024-06
 * @author Atik,jawad,razu,,bisty
 * 
 */

#ifndef Cafetaria_h
#define Cafetaria_h
#include <stdio.h>
#include <stdlib.h>
#include <time.h>







//food item structure definition

/**
 * @file struct foodItem
 * @brief use structure to store food item information easyly and accessable
 *      char *name : food item name 
 *      int id : food item unique id
 *      float price : food item price in currency
 *      struct foodItem* next : pointer to next food item in linked list
 */


struct fooditem {
    char *name;
    int id;
    int item;
    float price;
    struct fooditem* next;

};
          /**
         * @file function prototypes for food item operations
         * @brief function prototypes for adding
         * @param head Pointer to the head of the food item linked list
         * @param name Name of the food item
         * @param id Unique identifier for the food item
         * @param price Price of the food item
         * @return void
         */
    void addfooditem(struct fooditem** head , char *name,int id ,float price);
        /**
         * @file function prototypes for food item operations
         * @brief function prototypes for removing
         * @param head Pointer to the head of the food item linked list
         * @param id Unique identifier for the food item
         * @return void
         */
    void removefooditem(struct fooditem** head,int id);
        /**
         * @file function prototypes for food item operations
         * @brief function prototypes for updating
         * @param head Pointer to the head of the food item linked list
         * @param id Unique identifier for the food item
         * @param name New name of the food item
         * @param price New price of the food item
         * @return void
         */
    void updatefooditem(struct fooditem* head,int id ,char* name,float price);
        
        /**
         * @file function prototypes for food item operations
         * @brief function prototypes for displaying food items
         * @param head Pointer to the head of the food item linked list
         * @return void
         */
    void displayfooditems(struct fooditem* head);
        
        /**
         * @file function prototypes for food item operations
         * @brief function prototypes for sorting iteams by name
         *  @param head Pointer to the head of the food item linked list
         * @param size Size of the food item list
         * @return void
         */
    void sortfooditemsbyname(struct fooditem* head ,int size);
        
        /**
         * @file function prototypes for food item operations
         * @brief function prototypes for sorting iteams by price
         *  @param head Pointer to the head of the food item linked list
         * @param size Size of the food item list
         * @return void
         */
    void sortfooditemsbyprice(struct fooditem* head ,int size);
        
    
        



/**
 * @file struct cartItem
 * @brief use structure to store cart item information easyly and accessable
 *      char *name : cart item name 
 *      int id : cart item unique id
 *      float price : cart item price in currency
 *      struct foodItem item : food item associated with the cart item
 *      int quantity : quantity of the cart item
 *      struct cartItem* next : pointer to next cart item in linked list
 */


struct cartItem {
    char *name;
    int id;
    float price;
    struct foodItem item;
    int quantity;
    struct cartItem* next;
};

        /**
         * @file function prototypes for cart item creation
         * @brief function prototypes for creating cart item
         * @param head Pointer to the head of the cart item linked list
         * @param name Name of the cart item
         * @param id Unique identifier for the cart item
         * @param price Price of the cart item
         * @param item Food item associated with the cart item
         * @param quantity Quantity of the cart item
         * @return void
         */

    void searchCartItem(struct cartItem* head,char* name);
        /**
         * @file function prototypes for cart item addition
         * @brief function prototypes for adding item to cart
         * @param cart Pointer to the head of the cart item linked list
         * @param item Food item to be added to the cart
         * @param quantity Quantity of the food item to be added
         * @return void
         */


    void addItemToCart(struct cartItem** cart, struct foodItem item, int quantity);
    /**
     * @file function prototypes for cart item removal
     * @brief function prototypes for removing item from cart
     * @param cart Pointer to the head of the cart item linked list
     * @param id Unique identifier for the cart item to be removed
     * @return void
     */
    void removeItemFromCart(struct cartItem** cart, int id);
    /**
     * @file function prototypes for cart item quantity update
     * @brief function prototypes for updating cart item quantity
     * @param cart Pointer to the head of the cart item linked list
     * @param id Unique identifier for the cart item
     * @param newQuantity New quantity for the cart item
     * @return void
     */
    void updateCartItemQuantity(struct cartItem* cart, int id, int newQuantity);
    /**
     * @file function prototypes for cart item display
     * @brief function prototypes for displaying cart items
     * @param cart Pointer to the head of the cart item linked list
     * @return void
     */
    void displayCart(struct cartItem* cart);
    /**
     * @file function prototypes for cart total calculation
     * @brief function prototypes for calculating total amount of cart
     * @param cart Pointer to the head of the cart item linked list
     * @return float Total amount of the cart
     */
    float calculateTotal(struct cartItem* cart);


    
    


//menu structure definition

/**
 *@file struct menu
 * @brief in menu structuree we store all menu relatd information
 *   struct foodItem* items : pointer to fooditem structure to store all food iteam
       in the menu
*   int size : size of the menu
 */


struct menu {
    struct foodItem* items;
    int size;
};
        /**
         * @file function prototypes for menu operations
         * @brief function prototypes for displaying menu
         *  @param menu Pointer to the menu structure
         * @return void
         */
    void displayMenu(struct menu* menu);

        /**
         * @file function prototypes for menu operations
         * @brief function prototypes for freeing menu
         *  @param menu Pointer to the menu structure
         * @return void
         */
    void freeMenu(struct menu* menu);
    
         /**
          * @file function prototypes for menu operations
          * @brief function prototypes for updating menu with new items 
          *     @param menu Pointer to the menu structure
          *     @param newItems Pointer to the array of new food items
          *     @param newSize Size of the new food items array 
          * @return void
          */
    void udateMenu(struct menu* menu, struct foodItem* newItems, int newSize);




/**
 *@file struct order
    * @brief in order structure we store all order related information
    * int orderId : unique id for each order
    * struct cartItem* items : pointer to cartitem structure to store all iteam in the order
    * float totalAmount : total amount for the order in currency    
    * struct order* next : pointer to next order in linked list

 */

struct order {
    int orderId;
    struct cartItem* items;
    float totalAmount;
    struct order* next;
};
        /**
         * @file function prototypes for order operations
         * @brief function prototypes for ordering food
         * @param cart Pointer to the cart item linked list
         * @param orders Pointer to the head of the order linked list
         * @param nextOrderId Pointer to the next order ID
         * @return void
         */
    void orderFood(struct cartItem* cart, struct order** orders, int* nextOrderId);

        /**
         * @file function prototypes for order operations
         * @brief function prototypes for canceling order
         * @param head Pointer to the head of the order linked list
         * @param orderId Unique identifier for the order to be canceled
         * @param totalAmount Pointer to store the total amount of the canceled order
         * @return void
         */
    void placeOrder(struct cartItem* cart, struct order** orders, int* nextOrderId);


        /**
         * @file function prototypes for order operations
         * @brief function prototypes for displaying all orders
         * @param orders Pointer to the head of the order linked list
         * @return void
         */
    void displayAllOrders(struct order* orders);

        /**
         * @file function prototypes for order operations
         * @brief function prototypes for displaying orders
         * @param head Pointer to the head of the order linked list
         * @return void
         */
    void displayOrders(struct order* head);
        /**
         * @file function prototypes for order operations
         * @brief function prototypes for adding orders
         * @param head Pointer to the head of the order linked list
         * @param orderId Unique identifier for the order
         * @param items Pointer to the cart item linked list
         * @param totalAmount Total amount for the order
         * @return void
         */
    void addOrder(struct order** head, int orderId, struct cartItem* items, float totalAmount);

        /**
         * @file function prototypes for order operations
         * @brief function prototypes for updating orders
         * @param head Pointer to the head of the order linked list
         * @param orderId Unique identifier for the order
         * @param items Pointer to the cart item linked list
         * @param totalAmount Total amount for the order
         * @return void
         */
    void cencleOrder(struct order** head, int orderId,float*totalAmount);
    



/**
 * @file struct emoloyee
 * @brief in employee structure we store all employee related information 
 * char *name : employee name
 * int id : employee unique id
 * float salary : employee salary in currency
 * struct employee* next : pointer to next employee in linked list
 * int entryTime : employee entry time stote as local time integer
 * 
 */

struct employee {
    char *name;
    int id;
    float salary;
    int entryTime;
    struct employee* next;
};
        /**
         * @file function prototypes for employee operations
         * @brief function prototypes for displaying employees
         * @param head Pointer to the head of the employee linked list
         * @return void
         */
    void displayEmployees(struct employee* head);
        /**
         * @file function prototypes for employee operations
         * @brief function prototypes for adding employee
         * @param head Pointer to the head of the employee linked list
         * @param name Name of the employee
         * @param id Unique identifier for the employee
         * @param salary Salary of the employee
         * @return void
         */


        /**
         * @file function prototypes for employee operations
         * @brief function prototypes for updating employee
         * @param head Pointer to the head of the employee linked list
         * @param name New name of the employee
         * @param id Unique identifier for the employee
         * @param salary New salary of the employee
         * @return void
         */
    void addEmployee(struct employee** head, char* name, int id, float salary);

        /**
         * @file function prototypes for employee operations
         * @brief function prototypes for updating employee
         * @param head Pointer to the head of the employee linked list
         * @param id Unique identifier for the employee
         * @param name New name of the employee
         * @return void
         */
    void updateEmployee(struct employee* head, int id, char* name);

        /**
         * @file function prototypes for employee operations
         * @brief function prototypes for removing employee
         * @param head Pointer to the head of the employee linked list
         * @param id Unique identifier for the employee to be removed
         * @return void
         */
    void removeEmployee(struct employee** head, int id);

        /**
         * @file function prototypes for employee operations
         * @brief function prototypes for searching employee
         * @param head Pointer to the head of the employee linked list
         * @param id Unique identifier for the employee to be searched
         * @return void
         */
    void searchEmployee(struct employee* head, int id);

    /**
         * @file function prototypes for employee operations
         * @brief function prototypes for freeing employees
         * @param head Pointer to the head of the employee linked list
         * @return void
         */
    void scanEmployeeEntryTime(struct employee* head, int id, int entryTime);
        


    //table structure definition
/**
 * @file struct table
    * @brief in table structure we store all table related information
    * int tableNumber : unique number for each table
    * int isOccupied : status of the table (0 for available, 1 for occupied)
    * struct table* next : pointer to next table in linked list
    
 */

struct Table {
    int tableNumber;
    int isOccupied;
    struct Table* next;
};
        /**
         * @file function prototypes for table operations
         * @brief function prototypes for displaying tables
         * @param head Pointer to the head of the table linked list
         * @return void
         */
    void displayTables(struct Table* head);
        /**
         * @file function prototypes for table operations
         * @brief function prototypes for adding table
         * @param head Pointer to the head of the table linked list
         * @param tableNumber Unique number for the table
         * @return void
         */
    void addTable(struct Table** head, int tableNumber);
        /**
         * @file function prototypes for table operations
         * @brief function prototypes for removing table
         * @param head Pointer to the head of the table linked list
         * @param tableNumber Unique number for the table to be removed
         * @return void
         */
    void removeTable(struct Table** head, int tableNumber);
      
        /**
         * @file function prototypes for table operations
         * @brief function prototypes for reserving table
         * @param head Pointer to the head of the table linked list
         * @param tableNumber Unique number for the table to be reserved
         * @return void
         */
    void reserveTable(struct Table* head, int tableNumber);
    
    
    //payment structure definition
/**
 * @file struct payment 
 * @brief in payment structure we store all payment related information
 * int orderId : unique id for each order
 *  float amount : amount paid in currency
 *  char *paymentMethod : method of payment (e.g., cash, card)
 * struct payment* next : pointer to next payment in linked list
 
 */
struct payment {
    int orderId;
    float amount;
    char *paymentMethod;
    struct payment* next;
};

        /**
         * @file function prototypes for payment operations
         * @brief function prototypes for processing payment
         * @param payments Pointer to the head of the payment linked list
         * @param orderId Unique identifier for the order
         * @param amount Amount paid
         * @param paymentMethod Method of payment
         * @return void
         */
    void processPayment(struct payment** payments, int orderId,
        float amount, char* paymentMethod);

        /**
         * @file function prototypes for payment operations
         * @brief function prototypes for displaying payments
         * @param head Pointer to the head of the payment linked list
         * @return void
         */
    void displayPayments(struct payment* head);

        /**
         * @file function prototypes for payment operations
         * @brief function prototypes for printing payment receipt
         * @param orderId Unique identifier for the order
         * @param amount Amount paid
         * @param paymentMethod Method of payment
         * @return void
         */
    void perintPaymentReceipt(int orderId, float amount, char* paymentMethod);
        

/**
 * @file struct watingtime
 * @brief in watingtime structure we store all waiting time related information
 * int tableNumber : unique number for each table
 * int waitingTime : waiting time in minutes
 * struct watingtime* next : pointer to next waiting time in linked list
 * 
 */
struct watingtime{

    int tableNumber;
    int waitingTime; 
    struct watingtime* next;
}
;
        /**
         * @file function prototypes for waiting time operations
         * @brief function prototypes for displaying waiting times
         * @param head Pointer to the head of the waiting time linked list
         * @return void
         */
    void displayWaitingTimes(struct watingtime* head);

        /**
         * @file function prototypes for waiting time operations
         * @brief function prototypes for adding waiting time
         * @param head Pointer to the head of the waiting time linked list
         * @param tableNumber Unique number for the table
         * @param waitingTime Waiting time in minutes
         * @return void
         */
    void addWaitingTime(struct watingtime** head, int tableNumber,
        int waitingTime); 

        /**
         * @file function prototypes for waiting time operations
         * @brief function prototypes for removing waiting time
         * @param head Pointer to the head of the waiting time linked list
         * @param tableNumber Unique number for the table to be removed
         * @return void
         */
    void removeWaitingTime(struct watingtime** head, int tableNumber);
      
/**
 * @file struct Discount
 * @brief in Discount structure we store all discount related information
 * int id : unique id for each discount
 * float percentage : discount percentage
 * struct Discount* next : pointer to next discount in linked list
 */


struct Discount {
    char *name;
    int id;
    float percentage;
    struct Discount* next;
};
        /**
         * @file function prototypes for discount operations
         * @brief function prototypes for adding discount
         * @param head Pointer to the head of the discount linked list
         * @param id Unique identifier for the discount
         * @param percentage Discount percentage
         * @return void
         */
    void addDiscount(struct Discount** head, int id, float percentage);

        /**
         * @file function prototypes for discount operations
         * @brief function prototypes for removing discount
         * @param head Pointer to the head of the discount linked list
         * @param id Unique identifier for the discount to be removed
         * @return void
         */
    void removeDiscount(struct Discount** head, int id);
        /**
         * @file function prototypes for discount operations
         * @brief function prototypes for updating discount
         * @param head Pointer to the head of the discount linked list
         * @param id Unique identifier for the discount
         * @param newPercentage New discount percentage
         * @return void
         */
    void updateDiscount(struct Discount* head, int id, float newPercentage);
        /**
         * @file function prototypes for discount operations
         * @brief function prototypes for displaying discounts
         * @param head Pointer to the head of the discount linked list
         * @return void
         */

    void displayDiscounts(struct Discount* head);
        

    //food revew structure definition


/** * @file struct foodReview
 * @brief in foodReview structure we store all food review related  
 * int rating : rating out of 5
 * char* comment : comment for the review
 * struct foodReview* next : pointer to next food review in linked list
 */

struct foodReview {


        int rating; 
        char* comment;
        struct foodReview* next;
};
        /**
         * @file function prototypes for food review operations
         * @brief function prototypes for adding food review
         * @param head Pointer to the head of the food review linked list
         * @param rating Rating out of 5
         * @param comment Comment for the review
         * @return void
         */
    void addFoodReview(struct foodReview** head, int rating, char* comment);

        /**
         * @file function prototypes for food review operations
         * @brief function prototypes for displaying food reviews
         * @param head Pointer to the head of the food review linked list
         * @return void
         */
    void displayFoodReviews(struct foodReview* head);





    //Admin function prototypes


    /**
     * @file function prototypes for admin operations
     * @brief function prototypes for admin login   
     * @param username Admin username
     * @param password Admin password
     * @return int 1 if login is successful, 0 otherwise
     */
    int AdminLogin(const char* username, const char* password);

        /**
         * @file function prototypes for admin operations
         * @brief function prototypes for adding new admin
         * @param username New admin username
         * @param password New admin password
         * @return int 1 if admin is added successfully, 0 otherwise
         */
    int AddAdmin(const char* username, const char* password);

        /**
         * @file function prototypes for admin operations
         * @brief function prototypes for admin menu
         * @param employeeHead Pointer to the head of the employee linked list
         * @param reviewHead Pointer to the head of the food review linked list
         * @return void
         */
    void Adminmenu(struct employee** employeeHead, struct FoodReview** reviewHead);

    //Customer function properties
        /**
         * @file Function prototype for Customer opration
         * @brief function pototypes for coustomer login
         * @param username for new coustomer username
         * @param password for new coustomer password
         */
    int coustomerLogin(const char* username,const char* password);

        /**
         * @file Function prototype for coustomer opration 
         * @brief function peototyype for coustomer menu 
         * @param menu Pointer to the menu structure
         * @param cart Pointer to the head of the cart item linked list
         * @param order Pointer to the head of the order linked list
         * @param review Pointer to the head of the food review linked list
         * @return void
         */
    void customerMenu(struct Menu* menu, struct Cart** cart,struct Order** order,  struct Review** review);

//Manager function prototypes

        /**
         * @file function prototypes for manager operations
         * @brief function prototypes for manager login   
         * @param username Manager username
         * @param password Manager password
         * @return int 1 if login is successful, 0 otherwise
         */
    int managerLogin(const char* username, const char* password);  
    
    
        /**
         * @file function prototypes for manager operations
         * @brief function prototypes for manager menu
         * @param foodHead Pointer to the head of the food item linked list
         * @param menu Pointer to the menu structure
         * @param tableHead Pointer to the head of the table linked list
         * @param order Pointer to the head of the order linked list
         * @param discountHead Pointer to the head of the discount linked list
         * @param watingtimeHead Pointer to the head of the waiting time linked list
         * @return void
         */
    void managermenu(struct foodItem** foodHead,struct Menu* menu,struct Table** tableHead,struct Order** order, struct Discount** discountHead, struct watingtime** watingtimeHead);


    //Faculty and Staff function prototypes

        /**
         * @file function prototypes for faculty and staff operations
         * @brief function prototypes for faculty and staff login   
         * @param username Faculty and staff username
         * @param password Faculty and staff password
         * @return int 1 if login is successful, 0 otherwise
         */
    int facultyAndStaffLogin(const char* username, const char* password);

        /**
         * @file function prototypes for faculty and staff operations
         * @brief function prototypes for faculty and staff menu
         * @param menu Pointer to the menu structure
         * @param cart Pointer to the head of the cart item linked list
         * @param order Pointer to the head of the order linked list
         * @param review Pointer to the head of the food review linked list
         * @return void
         */
    void facultyAndStaffMenu(struct Menu* menu, struct Cart** cart, struct Order** order, struct Review** review);



#endif
