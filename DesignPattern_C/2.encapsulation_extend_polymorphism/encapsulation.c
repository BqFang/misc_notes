#include <stdio.h>

typedef struct human {
	int age;
	char sex;
	void (*SetAge)(struct human *ptHuman, int lAge);
	int (*GetAge)(struct human *ptHuman);
	void (*SetSex)(struct human *ptHuman, char cSex);
	char (*GetSex)(struct human *ptHuman);
}HUMAN_T;

void SetAge(HUMAN_T *const ptHuman, const int lAge)
{
	ptHuman->age = lAge;
}

int GetAge(HUMAN_T *const ptHuman)
{
	printf("get age is %d!\n\r", ptHuman->age);

	return ptHuman->age;
}

void SetSex(HUMAN_T *const ptHuman, char cSex)
{
	ptHuman->sex = cSex;
}

char GetSex(HUMAN_T *const ptHuman)
{
	printf("get sex is %c!\n\r", ptHuman->sex);

	return ptHuman->sex;
}

void HumanInit(HUMAN_T *const ptHuman)
{
	ptHuman->SetAge = SetAge;
	ptHuman->GetAge = GetAge;
	ptHuman->SetSex = SetSex;
	ptHuman->GetSex = GetSex;
}

int main()
{
	HUMAN_T tHuman;

	HumanInit(&tHuman);

	tHuman.SetAge(&tHuman, 18);
	tHuman.SetSex(&tHuman, 'M');

	tHuman.GetAge(&tHuman);
	tHuman.GetSex(&tHuman);

	return 0;
}

