#include <iostream>
#include "head.h"

int main()
{
    PriorityCustomer2 pc1;
    PriorityCustomer2 pc2(pc1);

    PriorityCustomer2 pc3;
    pc3 = pc1;
    
    return 0;
}
