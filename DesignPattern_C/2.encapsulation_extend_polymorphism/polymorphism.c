#include <stdio.h>
#include <assert.h>


typedef struct Shape {
	void (*Draw)(void *pvShape);
}SHAPE_T;

typedef struct Circle {
	SHAPE_T tBase;
	int lX;
	int lY;
	int lRadius;
}CIRCLE_T;

typedef struct Line {
	SHAPE_T tBase;
	int lX1;
	int lX2;
	int lY1;
	int lY2;
}LINE_T;

void DrawCircle(const void *const pvShape)
{
	assert(pvShape);

	CIRCLE_T *ptCircle = (CIRCLE_T *)pvShape;

	printf("Circle at (%d, %d) with radius %d\n\r", \
		ptCircle->lX, ptCircle->lY, ptCircle->lRadius);
}

void DrawLine(const void * const pvShape)
{
	assert(pvShape);

	LINE_T *ptLine = (LINE_T *)pvShape;

	printf("Line from (%d, %d) to (%d, %d)\n\r", \
			ptLine->lX1, ptLine->lY1, ptLine->lX2, ptLine->lY2);
}


int main()
{
	CIRCLE_T tCircle = {
		.lX = 10,
		.lY = 10,
		.lRadius = 5,
		.tBase = { .Draw = DrawCircle }
	};

	LINE_T tLine = {
		.lX1 = 5,
		.lX2 = 5,
		.lY1 = 20,
		.lY2 = 20,
		.tBase = {.Draw = DrawLine }
	};

	SHAPE_T *ptShape[2];
	int i = 0;

	ptShape[0] = (SHAPE_T *)&tCircle;
	ptShape[1] = (SHAPE_T *)&tLine;

	for (i = 0; i < 2; i++)
	{
		ptShape[i]->Draw(ptShape[i]);
	}

	return 0;
}


