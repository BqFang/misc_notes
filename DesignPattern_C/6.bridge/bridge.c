#include <stdio.h>
#include <assert.h>

/* implement port */
typedef struct Implement{
	void (*Implement)(void);
}IMPLEMENT_T;

/* implement method A */
void ImplementA(void)
{
	printf("implement A methon\n\r");
}

/* implement method B */
void ImplementB(void)
{
	printf("implement B methon\n\r");
}

/* abstract port */
typedef struct Abstruct {
	void (*AbstractOperation)(const struct Abstruct *const tAbstruct);
	IMPLEMENT_T *ptImplement;
}ABSTRUCT_T;

/* abstract implement method A */
void AbstractImplementMethodA(const ABSTRUCT_T *const ptAbstruct)
{
	assert(ptAbstruct);
	printf("abstruct method A\n\r");
	ptAbstruct->ptImplement->Implement();
}

/* abstract implement method B */
void AbstractImplementMethodB(const ABSTRUCT_T *const ptAbstruct)
{
	assert(ptAbstruct);
	printf("abstruct method B\n\r");
	ptAbstruct->ptImplement->Implement();
}


int main()
{
	IMPLEMENT_T tImplementA = { ImplementA };
	IMPLEMENT_T tImplementB = { ImplementB };

	ABSTRUCT_T tAbstructA = {
		.AbstractOperation = AbstractImplementMethodA ,
		.ptImplement       = &tImplementA 
	};

	ABSTRUCT_T tAbstructB = {
		.AbstractOperation = AbstractImplementMethodB ,
		.ptImplement = &tImplementB
	};

	tAbstructA.AbstractOperation(&tAbstructA);
	tAbstructB.AbstractOperation(&tAbstructB);

	return 0;
}


