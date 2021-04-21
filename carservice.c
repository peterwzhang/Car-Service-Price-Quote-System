/* 
    Peter Zhang
    9/20/2019
    Car Service Price Quote System
    This program takes in the type of car and its' mileage, then prompts the user 
    for which services they need and adds the cost to the price if they want the service,
    the program then adds tax and prints out the total cost of all services. 
    */
#include <stdio.h>
#include <string.h>

int main(){
    // arrays for services and prices
    const char serviceTextCar[8][50] = {"Oil Change $89.95?", "Tire alignment $50.00?", "Windshield wiper blades? $45.95", "Engine air filter? $30.50", "Brake fluid? $73.00", "Timing belt? $245.00", "Transmission fluid? $75.00"};
    const char serviceTextTruck[8][50] = {"Oil Change $119.95?", "Tire alignment $100.00?", "Windshield wiper blades? $45.95", "Engine air filter? $40.50", "Brake fluid? $104.00", "Timing belt? $345.00", "Transmission fluid? $85.00"};
    const double carPrices[] = {89.95, 50.00, 45.95, 30.50, 73.00, 245.00, 75.00};
    const double truckPrices[] = {119.95, 100.00, 45.95, 40.50, 104.00, 345.00, 85.00};

    int vehicleChoice = 0, userMileage = 0;
    double totalCost = 0;
    char userChoice = 'n';
    int servicesNeeded[] = {0,0,0,0,0,0,0,0};
    // oil, tire, windshield, engine, brake, timing, transmission
    printf("Enter 1-2 for vehicle type\n1. Car\n2. Truck\nWhat is your choice?\n");
    scanf("%d", &vehicleChoice);
    if (vehicleChoice != 1 && vehicleChoice != 2){
        printf("Invalid choice entered.\n");
        printf("Goodbye.\n");
        return 1;
    }

    printf("Enter your current mileage:\n");
    scanf("%d", &userMileage);
    if (!(userMileage >= 0 && userMileage <= 500000))
    {
        printf("Invalid choice entered.\n");
        printf("Goodbye.\n");
        return 2;
    }
    if (userMileage < 20000)
    {
        servicesNeeded[0] = 1;
    }
    else if (userMileage <= 34999)
    {
        servicesNeeded[0] = 1;
        servicesNeeded[1] = 1;
    }
    else if (userMileage <= 49999)
    {
        servicesNeeded[0] = 1;
        servicesNeeded[1] = 1;
        servicesNeeded[2] = 1;
    }
    else if (userMileage <= 64999)
    {
        servicesNeeded[0] = 1;
        servicesNeeded[1] = 1;
    }
    else if (userMileage <= 79999)
    {
        servicesNeeded[0] = 1;
        servicesNeeded[1] = 1;
        servicesNeeded[2] = 1;
        servicesNeeded[3] = 1;
        servicesNeeded[4] = 1;
    }
    else if (userMileage <= 99999)
    {
        servicesNeeded[0] = 1;
        servicesNeeded[1] = 1;
        servicesNeeded[5] = 1;
        servicesNeeded[6] = 1;
    }
    else if (userMileage <= 114999)
    {
        servicesNeeded[0] = 1;
        servicesNeeded[1] = 1;
        servicesNeeded[3] = 1;
        servicesNeeded[4] = 1;
    }
    else if (userMileage <= 500000)
    {
        servicesNeeded[0] = 1;
        servicesNeeded[1] = 1;
        servicesNeeded[2] = 1;
        servicesNeeded[5] = 1;
    }
printf("Which services should be performed today?\nPlease enter Y/y or N/n\n");
for (int i = 0; i < 8; i++)
{
    //printf("%d", i); debug remove
    if (servicesNeeded[i] == 1)
    {
        if (vehicleChoice == 1)
        {
            printf("%s\n", serviceTextCar[i]);
            }
            else if (vehicleChoice == 2){
            printf("%s\n", serviceTextTruck[i]);
            }
            scanf(" %c", &userChoice);
            if (userChoice != 'y' && userChoice != 'Y' && userChoice != 'n' && userChoice != 'N'){
                printf("Invalid choice entered.\n");
                printf("Goodbye.\n");
                return 3;
            }
            else if (userChoice == 'y' || userChoice == 'Y'){
                if (vehicleChoice == 1){
                    totalCost += carPrices[i];
                }
                else if (vehicleChoice == 2){
                    totalCost += truckPrices[i];
                }
            }else if (userChoice == 'n' || userChoice == 'N'){
                continue;
            }
        }
    }
    printf("The total for your services today is $%.2lf.\n", totalCost * 1.05);
    printf("Goodbye.\n");
    return 0;
}