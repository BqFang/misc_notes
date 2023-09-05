#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/* 定义一个接口 */
typedef struct ReadObjectPort {
	void (*DoOperation)(void *pvObject);
}REAL_OBJECT_PORT_T;

/* 创建真实对象结构体 */
typedef struct ReadObject {
	REAL_OBJECT_PORT_T tInterface;
}REAL_OBJECT_T;

/* 创建代理对象结构体 */
typedef struct Proxy {
	REAL_OBJECT_PORT_T tInterface;
	REAL_OBJECT_T tRealObject;
}PROXY_T;

/* 实现真实对象的操作方法 */
void RealOperation(void *pvObject)
{
	assert(pvObject);

	printf("opertion in RealObject\n\r");
}

/* 实现代理对象的操作方法 */
void ProxyOperation(void *pvObject)
{
	assert(pvObject);
	PROXY_T *ptProxy = (PROXY_T *)pvObject;

	if (NULL == ptProxy)
	{
		return;
	}

	printf("operation in ProxyObject\n\r");

	ptProxy->tRealObject.tInterface.DoOperation = RealOperation;

	ptProxy->tRealObject.tInterface.DoOperation(ptProxy);
}

/* 创建代理对象 */
REAL_OBJECT_PORT_T* CreateProxy(void)
{
	PROXY_T *ptProxy = calloc(1, sizeof(PROXY_T));

	if (NULL == ptProxy)
	{
		return NULL;
	}

	ptProxy->tInterface.DoOperation = ProxyOperation;

	return &(ptProxy->tInterface);
}

/* 销毁代理对象 */
void DestoryProxy(void *pvObject)
{
	assert(pvObject);

	REAL_OBJECT_PORT_T *ptProxy = (REAL_OBJECT_PORT_T *)pvObject;

	if (ptProxy)
	{
		free(ptProxy);
	}
}


int main()
{
	REAL_OBJECT_PORT_T *ptInterface = NULL;

	ptInterface = CreateProxy();

	ptInterface->DoOperation(ptInterface);

	DestoryProxy(ptInterface);

	return 0;
}

