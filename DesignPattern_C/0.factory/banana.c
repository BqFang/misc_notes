#include <stdlib.h>
#include <stdio.h>
#include "banana.h"

static void BananaShow(void* pObj)
{
	printf("Banana show!\n\r");
}

static void BananaEat(void* pObj)
{
	printf("Banana eat!\n\r");
}

BANANA_T* ConstructorBanana(void)
{
	BANANA_T* pObj = (BANANA_T*)malloc(sizeof(BANANA_T));

	pObj->Show = BananaShow;
	pObj->Eat = BananaEat;
	pObj->pObj = pObj;

	return pObj;
}
