/* Define Reg and some functions to make code more readable and clear */ 

#ifndef STANDARD_MACROS_H
#define STANDARD_MARCROS_h

/* define register size */ 
#define REG_SIZE 8; 

/* setting a reg bit to high */
#define SET_BIT (reg, bit) (reg |= (1 << bit))

/* setting a reg bit to low*/ 
#define CLR_BIT (reg, bit) (reg &=~ (1 << bit))

/* toggling a bit */ 
#define TOG_BIT (reg, bit) (reg ^= (1 << bit))

/* reading a bit -! */
#define READ_BIT (red, bit) ((reg & (1 << bit) >> bit))

#define ROR_BIT(reg,num) ((reg>>num)|(reg<<(REG_SIZE-num))
#define ROL_BIT(reg,num) ((reg<<num)|(reg>>(REG_SIZE-num))

#endif