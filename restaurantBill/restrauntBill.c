//include
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//need include time to get rand variables

//create a pointer

typedef struct {
    char *item;
    double price;
}Item, *pointerToItem

//define the food items n prices
Item itemTable[] = {
    {"Salad", 9.95}
    {"Soup", 4.55}
    {"Sandwhich", 13.25}
    {"Pizza", 22.35}
};

//create a getcost function
double getCost(pointerToItem food, int num){
    return food[num].price;
}
//create a getitem function
char* getName(pointerToItem food, int num){
    return food[num].item;
}

//main function
int main(int argC, char *argV[]){
    if (argC != 3){
        printf("Error, invalid arguments. First argument should be tax, the other should be tip")
    }
}

//create a error cache

