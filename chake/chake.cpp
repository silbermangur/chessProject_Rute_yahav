#include <iostream>
#include "manager.h"

//in order to make it work put the queen obj in manager as "//" and remove the virtual from the piece in the bishop and rook header files
int main() 
{
    manager* gameManager = new manager(); 
    gameManager->play();    
    delete gameManager;
    return 0;
}
