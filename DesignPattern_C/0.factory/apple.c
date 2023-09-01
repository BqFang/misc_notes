#include <stdlib.h>
#include <stdio.h>
#include "apple.h"

static void AppleShow(void *pObj)
{
	printf("apple show!\n\r");
}

static void AppleEat(void* pObj)
{
	printf("appple eat!\n\r");
}

APPLE_T* ConstructorApple(void)
{
	APPLE_T * pObj = (APPLE_T*)malloc(sizeof(APPLE_T));

	pObj->Show = AppleShow;
	pObj->Eat = AppleEat;
	pObj->pObj = pObj;

	return pObj;
}
