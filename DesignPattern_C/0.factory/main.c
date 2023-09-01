#include <stdio.h>
#include "factory.h"

int main(int argc, char **argv)
{
    FRUIT_T* ptFruit = NULL;
    
    /* create apple */
    ptFruit = FactoryCreateFruit(APPLE);
    ptFruit->Eat(NULL);
    ptFruit->Show(NULL);

    /* create banana */
    ptFruit = FactoryCreateFruit(BANANA);
    ptFruit->Eat(NULL);
    ptFruit->Show(NULL);

    return 0;
}

