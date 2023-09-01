#ifndef __APPLE_H
#define __APPLE_H

typedef struct Apple {
    void (*Show)(void* pObj);
    void (*Eat)(void* pObj);
    void* pObj;
}APPLE_T;


APPLE_T* ConstructorApple(void);


#endif  /* __APPLE_H */
