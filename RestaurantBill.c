/*
Gravino, Andrew
CS2600, First In-Class Coding Assignment
9/24/21

1. Declare variables that will be assigned to the inputs provided by the user and off a "random" element to choose a food item
2. Create a pseudorandom number generator
3. Establish if statements that split 0-32767 evenly in 4
4. When condition is met, update menu price
5. Because it's prices, we make all the variables support decimal point
6. Ask the user how much they want their tax is and how much they should tip
7. Calculate the separate amounts for tax and tip upon being applied to the menu price
8. Calculate the overall price
9. Print them all out on one line and format accordingly for normal looking prices
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    double tax;
    double tip;
    double menuPrice;
    double appliedTax;
    double appliedTip;
    double overallPrice;

    time_t t;

    srand((unsigned) time(&t));
    if(rand() < 8192){
        menuPrice = 9.95; //salad
    }
    else if(rand() >= 8192 && rand() < 16384){
        menuPrice = 4.55; //soup
    }
    else if(rand() >= 16384 && rand() < 24576){
        menuPrice = 13.25; //sandwich
    }
    else{
        menuPrice = 22.35; //pizza
    }

    printf("Please enter a tax percentage amount: ");
    scanf("%lf", &tax);
    
    printf("Now, enter a tip percentage amount: ");
    scanf("%lf", &tip);

    appliedTax = menuPrice * (tax/100);
    appliedTip = menuPrice * (tip/100);
    overallPrice = menuPrice + appliedTax + appliedTip;

    printf("\nYour meal costs: $%0.2lf, your tax costs: $%0.2lf, your tip amount costs: $%0.2lf, and your total bill costs: $%0.2lf.", menuPrice, appliedTax, appliedTip, overallPrice);
    
    return 0;
}