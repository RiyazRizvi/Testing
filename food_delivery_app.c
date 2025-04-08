
#include <stdio.h>
#include <string.h>

// User structure
typedef struct {
    char username[50];
    char password[50];
} User;

// Sample function to register user
void registerUser(User *user, const char *username, const char *password) {
    strcpy(user->username, username);
    strcpy(user->password, password);
    printf("User registered: %s\n", user->username);
}

// Sample function to place an order
void placeOrder(const char *restaurant, const char *item) {
    printf("Order placed at %s for %s\n", restaurant, item);
}

// Function to simulate payment processing
int processPayment(float amount, const char *method) {
    printf("Processing payment of %.2f using %s\n", amount, method);
    return 1; // 1 means success
}

// Function to notify delivery agent
void notifyDeliveryAgent(const char *orderId) {
    printf("Delivery agent notified for order ID: %s\n", orderId);
}

int main() {
    User user;
    registerUser(&user, "john_doe", "password123");

    placeOrder("Pizza Palace", "Pepperoni Pizza");

    if (processPayment(499.99, "Credit Card")) {
        notifyDeliveryAgent("ORD12345");
    }

    return 0;
}
