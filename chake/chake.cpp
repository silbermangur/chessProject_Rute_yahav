#include <iostream>
#include "manager.h"

int main() {
    manager* gameManager = new manager(); // Create a heap-allocated object
    gameManager->play();                 // Use the arrow operator for method calls
    delete gameManager;                  // Free the dynamically allocated memory
    return 0;
}
