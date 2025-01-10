#include <iostream>
#include "manager.h"

int main() 
{
    manager* gameManager = new manager(); 
    gameManager->play();    
    delete gameManager;
    return 0;
}
