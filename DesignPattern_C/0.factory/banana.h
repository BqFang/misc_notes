#ifndef __BANANA_H
#define __BANANA_H

typedef struct Banana {
    void (*Show)(void* pObj);
    void (*Eat)(void* pObj);
    void* pObj;
}BANANA_T;


BANANA_T* ConstructorBanana(void);


#endif  /* __BANANA_H */
