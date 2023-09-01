#ifndef __FACTORY_H
#define __FACTORY_H

/* 水果类型 */
typedef enum FruitType {
    APPLE = 0,
    BANANA,
    PEAR,
}FRUIT_TYPE_E;

/* 水果接口 */
typedef struct Fruit {
    void (*Show)(void *pObj);
    void (*Eat)(void *pObj);
    void *pObj;
}FRUIT_T;

FRUIT_T *FactoryCreateFruit(FRUIT_TYPE_E eFruitType);


#endif  /* __FACTORY_H */

