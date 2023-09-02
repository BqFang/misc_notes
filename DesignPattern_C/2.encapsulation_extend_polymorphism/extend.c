#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct human {
	int lAge;
	char cSex;
}HUMAN_T;

typedef struct person {
	HUMAN_T tHuman;
	char *name;
}PERSON_T;

PERSON_T *
CreatePerson(const int lAge, const char cSex, const char *const name)
{
	assert(name);

	PERSON_T *ptPerson = (PERSON_T *)malloc(sizeof(PERSON_T));

	if (NULL == ptPerson)
	{
		return NULL;
	}

	ptPerson->tHuman.lAge = lAge;
	ptPerson->tHuman.cSex = cSex;
	ptPerson->name = name;

	return ptPerson;
}

void DestoryPerson(PERSON_T *ptPerson)
{
	free(ptPerson);
}


int main()
{
	PERSON_T *ptPerson = CreatePerson(18, 'W', "zhangsan");

	printf("age is %d, sex is %c, name is %s\n\r", \
			ptPerson->tHuman.lAge, ptPerson->tHuman.cSex, \
			ptPerson->name);

	DestoryPerson(ptPerson);

	return 0;
}

