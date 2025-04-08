#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_RESTAURANTS 5
#define MAX_MENU_ITEMS 10
#define MAX_ORDERS 100

// User structure
typedef struct {
    char username[50];
    char password[50];
} User;

// MenuItem structure
typedef struct {
    char itemName[50];
    float price;
} MenuItem;

// Restaurant structure
typedef struct {
    char name[50];
    MenuItem menu[MAX_MENU_ITEMS];
    int menuSize;
} Restaurant;

// Order structure
typedef struct {
    char username[50];
    char restaurantName[50];
    MenuItem items[MAX_MENU_ITEMS];
    int itemCount;
    float totalAmount;
    char status[20]; // e.g., "Placed", "Processing", "Delivered"
} Order;

// Global variables
User users[MAX_USERS];
int userCount = 0;
Restaurant restaurants[MAX_RESTAURANTS];
int restaurantCount = 0;
Order orders[MAX_ORDERS];
int orderCount = 0;

// Function prototypes
void registerUser();
int loginUser();
void displayRestaurants();
void displayMenu(int restaurantIndex);
void placeOrder(int userIndex);
void processPayment(float amount);
void trackOrder(int userIndex);
int findUserIndex(char *username);

int main() {
    int choice, userIndex;
    char continueChoice;

    // Sample data initialization
    strcpy(restaurants[0].name, "Pizza Palace");
    restaurants[0].menuSize = 2;
    strcpy(restaurants[0].menu[0].itemName, "Pepperoni Pizza");
    restaurants[0].menu[0].price = 8.99;
    strcpy(restaurants[0].menu[1].itemName, "Margherita Pizza");
    restaurants[0].menu[1].price = 7.99;

    strcpy(restaurants[1].name, "Burger Barn");
    restaurants[1].menuSize = 2;
    strcpy(restaurants[1].menu[0].itemName, "Cheeseburger");
    restaurants[1].menu[0].price = 5.49;
    strcpy(restaurants[1].menu[1].itemName, "Veggie Burger");
    restaurants[1].menu[1].price = 4.99;

    restaurantCount = 2;

    do {
        printf("\nOnline Food Delivery Application\n");
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                userIndex = loginUser();
                if (userIndex != -1) {
                    int userChoice;
                    do {
                        printf("\n1. Browse Restaurants\n");
                        printf("2. Place Order\n");
                        printf("3. Track Order\n");
                        printf("4. Logout\n");
                        printf("Enter your choice: ");
                        scanf("%d", &userChoice);
                        getchar(); // Consume newline character

                        switch (userChoice) {
                            case 1:
                                displayRestaurants();
                                break;
                            case 2:
                                placeOrder(userIndex);
                                break;
                            case 3:
                                trackOrder(userIndex);
                                break;
                            case 4:
                                printf("Logging out...\n");
                                break;
                            default:
                                printf("Invalid choice. Please try again.\n");
                        }
                    } while (userChoice != 4);
                }
                break;
            case 3:
                printf("Exiting application. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }

        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &continueChoice);
        getchar(); // Consume newline character
    } while (continueChoice == 'y' || continueChoice == 'Y');

    return 0;
}

void registerUser() {
    if (userCount >= MAX_USERS) {
        printf("User registration limit reached.\n");
        return;
    }

    User newUser;
    printf("Enter username: ");
    fgets(newUser.username, sizeof(newUser.username), stdin);
    newUser.username[strcspn(newUser.username, "\n")] = '\0'; // Remove newline character

    printf("Enter password: ");
    fgets(newUser.password, sizeof(newUser.password), stdin);
    newUser.password[strcspn(newUser.password, "\n")] = '\0'; // Remove newline character

    // Check if username already exists
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, newUser.username) == 0) {
            printf("Username already exists. Please choose a different username.\n");
            return;
        }
    }

    users[userCount++] = newUser;
    printf("User registered successfully.\n");
}

int loginUser() {
    char username[50], password[50];
    printf("Enter username: ");
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\n")] = '\0'; // Remove newline character

    printf("Enter password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = '\0'; // Remove newline character

    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            printf("Login successful.\n");
            return i;
        }
    }

    printf("Invalid username or password.\n");
    return -1;
}

void displayRestaurants() {
    printf("\nAvailable Restaurants:\n");
    for (int i = 0; i < restaurantCount; i++) {
        printf("%d. %s\n", i + 1, restaurants[i].name);
    }
}

void displayMenu(int restaurantIndex) {
    if (restaurantIndex < 0 || restaurantIndex >= restaurantCount) {
        printf("Invalid restaurant selection.\n");
        return;
    }

    printf("\nMenu for %s:\n", restaurants[restaurantIndex].name);
    for (int i = 0
::contentReference[oaicite:10]{index=10}
 
