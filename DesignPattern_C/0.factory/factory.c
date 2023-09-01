#include <stdio.h>
#include "factory.h"
#include "banana.h"
#include "apple.h"

FRUIT_T *FactoryCreateFruit(FRUIT_TYPE_E eFruitType)
{
    FRUIT_T *pFruit = NULL;

    switch(eFruitType)
    {
        case APPLE: {
            pFruit = (FRUIT_T *)ConstructorApple();
            printf("factory: create apple success!\n\r");
            break;
        }
        case BANANA: {
            pFruit = (FRUIT_T*)ConstructorBanana();
            printf("factory: create banana success!\n\r");
            break;
        }
        default: {
            break;
        }
    }

    return pFruit;
}



