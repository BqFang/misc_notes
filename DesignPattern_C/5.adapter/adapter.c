#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/* define adaptee port */
typedef struct Adaptee {
	void (*SpecificRequest)(void);
}ADAPTEE_T;

/* adaptee operation */
void AdapterSpecificRequest(void)
{
	printf("adaptee specifig request\n\r");
}

/* adapter init */
ADAPTEE_T* AdapteeCreate(void)
{
	ADAPTEE_T *ptAdaptee = (ADAPTEE_T *)malloc(sizeof(ADAPTEE_T));

	if (NULL == ptAdaptee)
	{
		return NULL;
	}
	ptAdaptee->SpecificRequest = AdapterSpecificRequest;

	return ptAdaptee;
}

typedef struct Adapter ADAPTER_T;

/* define target port */
typedef struct Target {
	void (*Request)(ADAPTER_T *ptThis);
}TARGET_T;

/* define adapter */
struct Adapter {
	ADAPTEE_T *ptAdaptee;
	TARGET_T tTarget;
};

/* adapter operation */
void AdapterRequest(ADAPTER_T *ptThis)
{
	assert(ptThis);
	printf("adapter request\n\r");

	ptThis->ptAdaptee->SpecificRequest();
}

/* adapter init */
ADAPTER_T* AdapterCreate(ADAPTEE_T *ptAdaptee)
{
	assert(ptAdaptee);
	ADAPTER_T *ptAdapter = (ADAPTER_T *)malloc(sizeof(ADAPTER_T));

	if (NULL == ptAdapter)
	{
		return NULL;
	}
	ptAdapter->tTarget.Request = AdapterRequest;
	ptAdapter->ptAdaptee = ptAdaptee;

	return ptAdapter;
}

/* destory adaptee */
void DestoryAdaptee(ADAPTEE_T *ptAdaptee)
{
	assert(ptAdaptee);
	free(ptAdaptee);
}

/* destory adapter */
void DestoryAdapter(ADAPTER_T *ptAdapter)
{
	assert(ptAdapter);
	free(ptAdapter);
}

int main()
{
	/* create adaptee */
	ADAPTEE_T *ptAdaptee = AdapteeCreate();

	/* create adapter and init with adaptee */
	ADAPTER_T *ptAdapter = AdapterCreate(ptAdaptee);

	/* call adaptee request */
	ptAdapter->tTarget.Request(ptAdapter);

	/* free memory */
	DestoryAdaptee(ptAdaptee);
	DestoryAdapter(ptAdapter);

	return 0;
}

