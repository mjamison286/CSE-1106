#include <stdio.h>
#include <unistd.h>
#include <pigpio.h>

#define PIN 17
#define FILENAME "./readings.txt"

struct Node
{
 double reading;
 struct Node* next;
}

int addReading(struct Node*);
void displayAll(struct Node*);
double calculateAverage(struct Node*);
void changeRange(int*, int*);
double saveToFile(struct Node*, FILE*);

int main(int argc, char* argv[])
{
 int lowest = 68;
 int highest = 76;

 FILE* fptr;

 gpioInitialise();
 gpioSetMode(PIN, PI_OUTPUT);

 while(1)
 {
  int choice;

  printf("-- Temperature Controller --\n");
  printf("1 - Add a temperature reading\n");
  printf("2 - Display all current readings\n");
  printf("3 - Calculate average temperature\n");
  printf("4 - Change the acceptable reading range\n");
  printf("5 - Save readings to file\n");
  printf("6 - Exit\n\n");

  scanf("%d", &choice);
  while(getchar() != '\n');
  switch (choice)
  {
   case 1:
    if(addReading(fptr) != 0)
    {
     printf("Failed to add reading.");
    }
    break;
   case 2:
    displayAll(fptr);
    break;
   case 3:
    calculateAverage(fptr);
    break;
   case 4:
    changeRange(&lowest, &highest);
    break;
   case 5:
    saveToFile(fptr);
    break;
   case 6:
    fclose(fptr);
    free(fptr);
    return 0;
   default:
    printf("Invalid choice. Try again.\n");
    break;
  }
 return 0;
}

Node* addReading(struct Node* head)
{
 Node* node = malloc(sizeof(struct Node));

 if(node == NULL)
 {
  printf("Failed to allocate memory for the new node.\n");
  return NULL;
 }

 double reading;

 printf("Enter the temperature reading. ");
 scanf("%lf", &reading);
 while(getchar() != NULL);

 node->reading = reading;
 node->next = NULL;

 if(head != NULL)
 {
  
 }
}

int displayAll(FILE* file)
{
 file = fopen(FILENAME, "r");

}

