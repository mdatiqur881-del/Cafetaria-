#include "Caferatia.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


// Function definitions for food item operations

void addfooditem(struct fooditem** head , char *name,int id ,float price){
    struct fooditem* newItem = (struct fooditem*)malloc(sizeof(struct fooditem));
    newItem->name = name;
    newItem->id = id;
    newItem->price = price;
    newItem->next = *head;
    *head = newItem;
}
void removefooditem(struct fooditem** head,int id){
    struct fooditem* current = *head;
    struct fooditem* previous = NULL;
    while(current != NULL && current->id != id){
        previous = current;
        current = current->next;
    }
    if(current == NULL){
        printf("Food item with ID %d not found.\n",id);
        return;
    }
    if(previous == NULL){
        *head = current->next;
    }else{
        previous->next = current->next;
    }
    free(current);
}

void updatefooditem(struct fooditem* head,int id ,char* name,float price){
    struct fooditem* current = head;
    while(current != NULL && current->id != id){
        current = current->next;
    }
    if(current == NULL){
        printf("Food item with ID %d not found.\n",id);
        return;
    }
    current->name = name;
    current->price = price;
}

void displayfooditems(struct fooditem* head){
    struct fooditem* current = head;
    if(current == NULL){
        printf("No food items available.\n");
        return;
    }
    printf("Food Items:\n");
    while(current != NULL){
        printf("ID: %d, Name: %s, Price: %.2f\n",current->id,current->name,current->price);
        current = current->next;
    }
}
void freefooditems(struct fooditem* head){
    struct fooditem* current = head;
    struct fooditem* next;
    while(current != NULL){
        next = current->next;
        free(current);
        current = next;
    }
}
void sortfooditemsbyname(struct fooditem* head ,int size){
    if(head == NULL || head->next == NULL){
        return;
    }
    struct fooditem* i;
    struct fooditem* j;
    char* tempName;
    int tempId;
    float tempPrice;
    for(i = head; i != NULL; i = i->next){
        for(j = i->next; j != NULL; j = j->next){
            if(strcmp(i->name, j->name) > 0){
                // Swap names
                tempName = i->name;
                i->name = j->name;
                j->name = tempName;
                // Swap IDs
                tempId = i->id;
                i->id = j->id;
                j->id = tempId;
                // Swap prices
                tempPrice = i->price;
                i->price = j->price;
                j->price = tempPrice;
            }
        }
    }
}
void sortfooditemsbyprice(struct fooditem* head ,int size){
    if(head == NULL || head->next == NULL){
        return;
    }
    struct fooditem* i;
    struct fooditem* j;
    char* tempName;
    int tempId;
    float tempPrice;
    for(i = head; i != NULL; i = i->next){
        for(j = i->next; j != NULL; j = j->next){
            if(i->price > j->price){
                // Swap names
                tempName = i->name;
                i->name = j->name;
                j->name = tempName;
                // Swap IDs
                tempId = i->id;
                i->id = j->id;
                j->id = tempId;
                // Swap prices
                tempPrice = i->price;
                i->price = j->price;
                j->price = tempPrice;
            }
        }
    }
}

// Function definitions for cart item operations

void searchCartItem(struct cartItem* head,char* name){
    struct cartItem* current = head;
    while(current != NULL){
        if(strcmp(current->name, name) == 0){
            printf("Cart Item Found - ID: %d, Name: %s, Price: %.2f, Quantity: %d\n",
                   current->id, current->name, current->price, current->quantity);
            return;
        }
        current = current->next;
    }
    printf("Cart item with name %s not found.\n", name);
}


void addItemToCart(struct cartItem** cart, struct foodItem item, int quantity) {
    struct cartItem* newItem = (struct cartItem*)malloc(sizeof(struct cartItem));
    newItem->name = item.name;
    newItem->id = item.id;
    newItem->price = item.price;
    newItem->item = item;
    newItem->quantity = quantity;
    newItem->next = *cart;
    *cart = newItem;
}

void removeItemFromCart(struct cartItem** cart, int id) {
    struct cartItem* current = *cart;
    struct cartItem* previous = NULL;
    while (current != NULL && current->id != id) {
        previous = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("Cart item with ID %d not found.\n", id);
        return;
    }
    if (previous == NULL) {
        *cart = current->next;
    } else {
        previous->next = current->next;
    }
    free(current);
}

void updateCartItemQuantity(struct cartItem* cart, int id, int newQuantity) {
    struct cartItem* current = cart;
    while (current != NULL && current->id != id) {
        current = current->next;
    }
    if (current == NULL) {
        printf("Cart item with ID %d not found.\n", id);
        return;
    }
    current->quantity = newQuantity;
}   

void displayCart(struct cartItem* cart) {
    struct cartItem* current = cart;
    if (current == NULL) {
        printf("Cart is empty.\n");
        return;
    }
    printf("Cart Items:\n");
    while (current != NULL) {
        printf("ID: %d, Name: %s, Price: %.2f, Quantity: %d\n",
               current->id, current->name, current->price, current->quantity);
        current = current->next;
    }
}

void  calculateTotal(struct cartItem* cart) {
    struct cartItem* current = cart;
    float total = 0.0f;
    while (current != NULL) {
        total += current->price * current->quantity;
        current = current->next;
    }
    return total;
}



void freeCart(struct cartItem* cart) {
    struct cartItem* current = cart;
    struct cartItem* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

// Function definitions for menu operations

void displayMenu(struct menu* menu) {
    if (menu == NULL) {
        printf("Menu is empty.\n");
        return;
    }
    printf("Menu Name: %s\n", menu->name);
    printf("Food Items:\n");
    displayfooditems(menu->items);
}


void freeMenu(struct menu* menu) {
    if (menu != NULL) {
        freefooditems(menu->items);
        free(menu);
    }
}

void udateMenu(struct menu* menu, struct foodItem* newItems, int newSize) {
    if (menu == NULL) {
        printf("Menu is not initialized.\n");
        return;
    }
    freefooditems(menu->items);
    menu->items = newItems;
    menu->size = newSize;
}   

// Function definitions for order operations

void OrderFood(struct cartItem* cart, struct order** orders, int* nextOrderId) {
    if (cart == NULL) {
        printf("Cart is empty. Cannot place order.\n");
        return;
    }
    float totalAmount = calculateTotal(cart);
    addorder(orders, (*nextOrderId)++, cart, totalAmount);
    printf("Order placed successfully with Order ID: %d, Total Amount: %.2f\n", (*nextOrderId) - 1, totalAmount);
}

void addorder(struct order** head, int orderId, struct cartItem* items, float totalAmount) {
    struct order* newOrder = (struct order*)malloc(sizeof(struct order));
    newOrder->orderId = orderId;
    newOrder->items = items;
    newOrder->totalAmount = totalAmount;
    newOrder->next = *head;
    *head = newOrder;
}
void cencleOrder(struct order** head, int orderId,float*totalAmount){
    struct order* current = *head;
    struct order* previous = NULL;
    while (current != NULL && current->orderId != orderId) {
        previous = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("Order with ID %d not found.\n", orderId);
        return;
    }
    if (previous == NULL) {
        *head = current->next;
    } else {
        previous->next = current->next;
    }
    *totalAmount=current->totalAmount;
    freeCart(current->items);
    free(current);
    printf("Order with ID %d has been canceled.\n", orderId);
}

void Updateorder(struct order* head, int orderId, struct cartItem* items, float totalAmount) {
    struct order* current = head;
    while (current != NULL && current->orderId != orderId) {
        current = current->next;
    }
    if (current == NULL) {
        printf("Order with ID %d not found.\n", orderId);
        return;
    }
    current->items = items;
    current->totalAmount = totalAmount;
}

void displayOrders(struct order* head) {
    struct order* current = head;
    if (current == NULL) {
        printf("No orders available.\n");
        return;
    }
    printf("Orders:\n");
    while (current != NULL) {
        printf("Order ID: %d, Total Amount: %.2f\n", current->orderId, current->totalAmount);
        printf("Items in Order:\n");
        displayCart(current->items);
        current = current->next;
    }
}

void placeOrder(struct cartItem* cart, struct order** orders, int* nextOrderId) {
    if (cart == NULL) {
        printf("Cart is empty. Cannot place order.\n");
        return;
    }
    float totalAmount = calculateTotal(cart);
    addorder(orders, (*nextOrderId)++, cart, totalAmount);
    printf("Order placed successfully with Order ID: %d, Total Amount: %.2f\n", (*nextOrderId) - 1, totalAmount);
}



// Function definitions for employee operations

void displayEmployees(struct employee* head) {
    struct employee* current = head;
    if (current == NULL) {
        printf("No employees available.\n");
        return;
    }
    printf("Employees:\n");
    while (current != NULL) {
        printf("ID: %d, Name: %s, Salary: %.2f\n", current->id, current->name, current->salary);
        current = current->next;
    }
}

void addEmployee(struct employee** head, char* name, int id, float salary) {
    struct employee* newEmployee = (struct employee*)malloc(sizeof(struct employee));
    newEmployee->name = name;
    newEmployee->id = id;
    newEmployee->salary = salary;
    newEmployee->next = *head;
    *head = newEmployee;
}

void updateEmployee(struct employee* head, int id, char* name) {
    struct employee* current = head;
    while (current != NULL && current->id != id) {
        current = current->next;
    }
    if (current == NULL) {
        printf("Employee with ID %d not found.\n", id);
        return;
    }
    current->name = name;
}

void removeEmployee(struct employee** head, int id) {
    struct employee* current = *head;
    struct employee* previous = NULL;
    while (current != NULL && current->id != id) {
        previous = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("Employee with ID %d not found.\n", id);
        return;
    }
    if (previous == NULL) {
        *head = current->next;
    } else {
        previous->next = current->next;
    }
    free(current);
}

void searchEmployee(struct employee* head, int id) {
    struct employee* current = head;
    while (current != NULL && current->id != id) {
        current = current->next;
    }
    if (current == NULL) {
        printf("Employee with ID %d not found.\n", id);
        return;
    }
    printf("Employee Found - ID: %d, Name: %s, Salary: %.2f\n", current->id, current->name, current->salary);
}

void freeEmployees(struct employee* head) {
    struct employee* current = head;
    struct employee* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}
void scanEmployeeEntryTime(struct employee* head, int id, int entryTime) {
    struct employee* current = head;
    while (current != NULL && current->id != id) {
        current = current->next;
    }
    if (current == NULL) {
        printf("Employee with ID %d not found.\n", id);
        return;
    }
    current->entryTime = entryTime;
}


// Function definitions for table operations
void displayTables(struct Table* head) {
    struct Table* current = head;
    if (current == NULL) {
        printf("No tables available.\n");
        return;
    }
    printf("Tables:\n");
    while (current != NULL) {
        printf("Table Number: %d, Occupied: %s\n", current->tableNumber,
               current->isOccupied ? "Yes" : "No");
        current = current->next;
    }
}
void addTable(struct Table** head, int tableNumber) {
    struct Table* newTable = (struct Table*)malloc(sizeof(struct Table));
    newTable->tableNumber = tableNumber;
    newTable->isOccupied = 0; // Initially available
    newTable->next = *head;
    *head = newTable;
}
void removeTable(struct Table** head, int tableNumber) {
    struct Table* current = *head;
    struct Table* previous = NULL;
    while (current != NULL && current->tableNumber != tableNumber) {
        previous = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("Table with Number %d not found.\n", tableNumber);
        return;
    }
    if (previous == NULL) {
        *head = current->next;
    } else {
        previous->next = current->next;
    }
    free(current);
}

// Function definitions for payment operations

void paymentProcessing(struct payment** payments, int orderId, float amount, char* paymentMethod) {
    struct payment* newPayment = (struct payment*)malloc(sizeof(struct payment));
    newPayment->orderId = orderId;
    newPayment->amount = amount;
    newPayment->paymentMethod = paymentMethod;
    newPayment->next = *payments;
    *payments = newPayment;
    printf("Payment processed for Order ID: %d, Amount: %.2f, Method: %s\n",
           orderId, amount, paymentMethod);
}

void perintPaymentReceipt(int orderId, float amount, char* paymentMethod) {
    printf("Payment Receipt:\n");
    printf("Order ID: %d\n", orderId);
    printf("Amount Paid: %.2f\n", amount);
    printf("Payment Method: %s\n", paymentMethod);
    printf("Thank you for your payment!\n");
}

void displayPayments(struct payment* head) {
    struct payment* current = head;
    if (current == NULL) {
        printf("No payments available.\n");
        return;
    }
    printf("Payments:\n");
    while (current != NULL) {
        printf("Order ID: %d, Amount: %.2f, Method: %s\n",
               current->orderId, current->amount, current->paymentMethod);
        current = current->next;
    }
}



// Function definitions for review operations

void addReview(struct Review** head, int rating, char* comment) {
    struct Review* newReview = (struct Review*)malloc(sizeof(struct Review));
    newReview->rating = rating;
    newReview->comment = comment;
    newReview->next = *head;
    *head = newReview;
}
void displayReviews(struct Review* head) {
    struct Review* current = head;
    if (current == NULL) {
        printf("No reviews available.\n");
        return;
    }
    printf("Reviews:\n");
    while (current != NULL) {
        printf("Rating: %d, Comment: %s\n", current->rating, current->comment);
        current = current->next;
    }
}

// Function definitions for waiting time operations

void displayWaitingTimes(struct watingtime* head) {
    struct watingtime* current = head;
    if (current == NULL) {
        printf("No waiting times available.\n");
        return;
    }
    printf("Waiting Times:\n");
    while (current != NULL) {
        printf("Table Number: %d, Waiting Time: %d minutes\n",
               current->tableNumber, current->waitingTime);
        current = current->next;
    }
}
void addWaitingTime(struct watingtime** head, int tableNumber,
    int waitingTime) {
    struct watingtime* newWaitingTime = (struct watingtime*)malloc(sizeof(struct watingtime));
    newWaitingTime->tableNumber = tableNumber;
    newWaitingTime->waitingTime = waitingTime;
    newWaitingTime->next = *head;
    *head = newWaitingTime;
}
void removeWaitingTime(struct watingtime** head, int tableNumber) {
    struct watingtime* current = *head;
    struct watingtime* previous = NULL;
    while (current != NULL && current->tableNumber != tableNumber) {
        previous = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("Waiting time for Table Number %d not found.\n", tableNumber);
        return;
    }
    if (previous == NULL) {
        *head = current->next;
    } else {
        previous->next = current->next;
    }
    free(current);
}
void freeWaitingTimes(struct watingtime* head) {
    struct watingtime* current = head;
    struct watingtime* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

// Function definitions for discount operations

void addDiscount(struct Discount** head, int id, float percentage) {
    struct Discount* newDiscount = (struct Discount*)malloc(sizeof(struct Discount));
    newDiscount->id = id;
    newDiscount->percentage = percentage;
    newDiscount->next = *head;
    *head = newDiscount;
}

void removeDiscount(struct Discount** head, int id) {
    struct Discount* current = *head;
    struct Discount* previous = NULL;
    while (current != NULL && current->id != id) {
        previous = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("Discount with ID %d not found.\n", id);
        return;
    }
    if (previous == NULL) {
        *head = current->next;
    } else {
        previous->next = current->next;
    }
    free(current);
}

void freeDiscounts(struct Discount* head) {
    struct Discount* current = head;
    struct Discount* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

void displayDiscounts(struct Discount* head) {
    struct Discount* current = head;
    if (current == NULL) {
        printf("No discounts available.\n");
        return;
    }
    printf("Discounts:\n");
    while (current != NULL) {
        printf("ID: %d, Percentage: %.2f%%\n", current->id, current->percentage);
        current = current->next;
    }
}   

void updateDiscount(struct Discount* head, int id, float newPercentage) {
    struct Discount* current = head;
    while (current != NULL && current->id != id) {
        current = current->next;
    }
    if (current == NULL) {
        printf("Discount with ID %d not found.\n", id);
        return;
    }
    current->percentage = newPercentage;
}   


//food review function definitions

void addFoodReview(struct foodReview** head, int rating, char* comment) {
    struct foodReview* newReview = (struct foodReview*)malloc(sizeof(struct foodReview));
    newReview->rating = rating;
    newReview->comment = comment;
    newReview->next = *head;
    *head = newReview;
}

void displayFoodReviews(struct foodReview* head) {
    struct foodReview* current = head;
    if (current == NULL) {
        printf("No food reviews available.\n");
        return;
    }
    printf("Food Reviews:\n");
    while (current != NULL) {
        printf("Rating: %d, Comment: %s\n", current->rating, current->comment);
        current = current->next;
    }
}

void freeFoodReviews(struct foodReview* head) {
    struct foodReview* current = head;
    struct foodReview* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

int AdminLogin(const char* username, const char* password) {
    
    const char* adminPassword = "password123";

    if (strcmp(username, adminUsername) == 0 && strcmp(password, adminPassword) == 0) {
        return 1; // Login successful
    } else {
        return 0; // Login failed
    }
}
int AddAdmin(const char* username, const char* password) {
    
    printf("New admin added:\nUsername: %s\nPassword: %s\n", username, password);
    return 1; // Indicate success
}

void Adminmenu(struct employee** employeeHead, struct FoodReview** reviewHead) {
    int choice;
    char *username
    char *password

    do {
        printf("Admin Menu:\n");
        printf("Enter your choice:\n");
        printf("1. Add Employee\n");
        printf("2.Delete Employee\n");
        printf("3. View Employees\n");
        printf("4. View Food Reviews\n");
        printf("5. Logout\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployee(*employeeHead);
                break;

            case 2: 
                removeEmployee(*employeeHead);
                break;

            case 3:
                displayEmployees(*employeeHead);
                break;
            case 4:
                displayFoodReviews(*reviewHead);
                break;
            case 5:
                printf("Logging out...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);


        *username = (char*)malloc(50 * sizeof(char));
        *password = (char*)malloc(50 * sizeof(char));
        printf("Enter new admin username: ");
        scanf("%s", username);
        printf("Enter new admin password: ");
        scanf("%s", password);


        AddAdmin(username, password);
        free(username);
        free(password);

}

//coustomer function definitions

   int coustomerLogin(const char* username, const char* password) {
    // For demonstration purposes, we use hardcoded credentials.
    const char* customerUsername = "customer";
    const char* customerPassword = "cust123";
    if (strcmp(username, customerUsername) == 0 && strcmp(password, customerPassword) == 0) {
        return 1; // Login successful
    } else {
        return 0; // Login failed
    }
}


void customerMenu(struct Menu* menu, struct table** table,struct discount** discount, struct Cart** cart,struct Order** order,  struct Review** review) {
    int choice;
    do {
        printf("Customer Menu:\n");
        printf("Enter your choice: ");
        printf("1. View Menu\n");
        printf("2. Add Item to Cart\n");
        printf("3.Remove Item from Cart\n");
        printf("4. View Cart\n");
        printf("5. Place Order\n");
        printf("6. view payslip\n");
        printf("7.See review\n");
        printf("8.Write a review\n");
        printf("9.view Available Discounts\n");
        printf("10.view Waiting Time\n");
        printf("11.view Available Tables\n");
        printf("12.Logout\n");
        printf("13.Exit\n");
        
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayMenu(*menu);
                break;
            case 2:
                ddItemToCart(*cart);
                break;
            case 3:
                removeItemFromCart(*cart);
                break;
            case 4:
                displayCart(*cart);
                break;
            case 5:
                placeOrder(*cart, *order);
                break;
            case 6:
                printPaymentReceipt(*order, *payment, *cart, *discoun);
                break;
            case 7:
                displayFoodReviews(*review);
                break;
            case 8:
                addFoodReview(*review);
                break;
            case 9:
                displayDiscounts(*Discount);
                break;
            case 10:
                displayWaitingTimes(*watingtime);
                break;
            case 11:
               displayTables(*Table);
                break;
            case 12:
                printf("Logging out...\n");
                break;
            case 13:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 12);
}

//manager function definitions

   int managerLogin(const char* username, const char* password) {
    // For demonstration purposes, we use hardcoded credentials.
    const char* managerUsername = "manager";
    const char* managerPassword = "mgr123";
    if (strcmp(username, managerUsername) == 0 && strcmp(password, managerPassword) == 0) {
        return 1; // Login successful
    } else {
        return 0; // Login failed
    }
}  
    
    
   void managermenu(struct foodItem** foodHead,struct Menu* menu,struct Table** tableHead,struct Order** order, struct Discount** discountHead, struct watingtime** watingtimeHead) {
    int choice;
    do {
        printf("Manager Menu:\n");
        printf("Enter your choice:\n");
        printf("1. Manage Food Items\n");
        printf("2. Manage Menu\n");
        printf("3. Manage Tables\n");
        printf("4. View Orders\n");
        printf("5. Manage Discounts\n");
        printf("6. Manage Waiting Times\n");
        printf("7. Logout\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addfooditem(*foodHead);
                removefooditem(*foodHead);
                updatefooditem(*foodHead);
                displayfooditems(*foodHead);
                break;
            case 2:
                addMenu(*menu);
                updateMenu(*menu);
                displayMenu(*menu);
                removeMenu(*menu);
                break;
            case 3:
                addTable(*tableHead);
                removeTable(*tableHead);
                displayTables(*tableHead);
                updateTableStatus(*tableHead);
                break;
            case 4:
                displayOrders(*order);
                cancleOrder(*order);
                break;
            case 5:
                addDiscount(*discountHead);
                removeDiscount(*discountHead);
                displayDiscounts(*discountHead);
                updateDiscount(*discountHead);
                break;
            case 6:
                addWaitingTime(*watingtimeHead);
                removeWaitingTime(*watingtimeHead);
                displayWaitingTimes(*watingtimeHead);
                updatewaitingTime(*watingtimeHead);
                break;
            case 7:
                printf("Logging out...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 7);
}


//function for facultay and staff login

   int facultyLogin(const char* username, const char* password) {
    // For demonstration purposes, we use hardcoded credentials.
    const char* facultyUsername = "faculty";
    const char* facultyPassword = "fac123";
    if (strcmp(username, facultyUsername) == 0 && strcmp(password, facultyPassword) == 0) {
        return 1; // Login successful
    } else {
        return 0; // Login failed
    }
}

void facultyMenu(struct foodReview** review) {
    int choice;
    do {
        printf("Faculty/Staff Menu:\n");
        printf("Enter your choice:\n");
        printf("1. View Menu\n");
        printf("2. Add Item to Cart\n");
        printf("3.Remove Item from Cart\n");
        printf("4. View Cart\n");
        printf("5. Place Order\n");
        printf("6. view payslip\n");
        printf("7.See review\n");
        printf("8.Write a review\n");
        printf("9.view Available Discounts\n");
        printf("10.view Waiting Time\n");
        printf("11.view Available Tables\n");
        printf("12.Logout\n");
        printf("13.Exit\n");

        scanf("%d", &choice);
        switch (choice) {
            case 1:
                displayMenu(*menu);
                break;
            case 2:
                ddItemToCart(*cart);
                break;
            case 3:
                removeItemFromCart(*cart);
                break;
            case 4:
                displayCart(*cart);
                break;
            case 5:
                placeOrder(*cart, *order);
                break;
            case 6:
                printPaymentReceipt(*order, *payment, *cart, *discoun);
                break;
            case 7:
                displayFoodReviews(*review);
                break;
            case 8:
                addFoodReview(*review);
                break;  
            case 9:
                displayDiscounts(*Discount);
                break;
            case 10:
                displayWaitingTimes(*watingtime);
                break;
            case 11:
                displayTables(*Table);
                 break;

            case 12:
                printf("Logging out...\n");
                break;
            case 13:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");  
        }
    } while (choice != 12);


}
    
