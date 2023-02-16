
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100
#define MAX_NUM_LINES 1000



int main(void) {
  char*months[] = {"January", "Febuary", "March" , "April",  "May", "June", "July", "August", "September", "October", "November", "December"};
  char input_file_name[100];
  printf("Enter the input file name: ");
  scanf("%s", input_file_name);

  FILE* input_file = fopen(input_file_name, "r");
  if (input_file == NULL) {
    printf("Error: Could not open file %s\n", input_file_name);
    return 1;
  }

  char lines[MAX_NUM_LINES][MAX_LINE_LENGTH];
  int num_lines = 0;
  while (fgets(lines[num_lines], MAX_LINE_LENGTH, input_file) != NULL) {
    num_lines++;
  }

  printf("\nMonthly sales report for 2022:\n");
  printf("\n Month       Sales\n ");
  printf("\n");
  for (int i = 0; i < num_lines; i++) {
    printf(" %-10s  %s",months[i],lines[i]);
  }


  for (int i = 0; i < 6; i++) {
    printf("\n");
    }
  printf(" Sales summary: \n");
  
  float float_lines[MAX_NUM_LINES];

  for (int i = 0; i < num_lines; i++) {
    float_lines[i] = atof(lines[i]);
  }
  
  float smallest = float_lines[0];
  char * smallest_month = months[0];
  for (int i = 1; i < num_lines; i++) {
    if (float_lines[i] < smallest) {
      smallest = float_lines[i];
      smallest_month =  months[i];
      
     
    }
    
  }
   printf("\n The minimum sales is:    $%.2f  (%s) \n", smallest, smallest_month); 
  



  float largest = float_lines[0];
  char * largest_month = months[0];
  for (int i = 1; i < num_lines; i++) {
    if (float_lines[i] > largest) {
      largest = float_lines[i];
      largest_month =  months[i];
    }
  
  
  }

  printf(" The maximum sales is:    $%.2f  (%s)\n", largest, largest_month);
  
  float average;
  float calc_average;
  average = 0.0;
  for (int i = 0; i < num_lines; i++) {
    average = average + float_lines[i];
}
  calc_average=average/num_lines;
  printf(" The average sale is:     $%.2f\n", calc_average);

  for (int i = 0; i < 6; i++) { 
    printf("\n");
    }

  printf("\nSix-Month Moving Average Report:\n");
  printf("\n");
   float calc_averages[7];
   float sum1;
    for (int i = 0; i < 7; i++) {
        for (int j=0; j<6; j++){
           sum1 += float_lines[j+1];
        }
      calc_averages[i] = (float_lines[i] + float_lines[i+1] + float_lines[i+2] + float_lines[i+3] + float_lines[i+4] + float_lines[i+5]) / 6.0;

      if (i==0){
         printf("January  -  June       ");
      }
      if (i==1){
         printf("Febuary  -  July       ");
      }
      if (i==2){
         printf("March    -  August     ");
      }
      if (i==3){
         printf("April    -  September  ");
      }
      if (i==4){
         printf("May      -  October    ");
      }
      if (i==5){
         printf("June     -  November   ");
      }
      if (i==6){
         printf("July     -  December   ");
      }
      printf("%.2f\n", calc_averages[i]);
    }

    

     for (int i = 0; i < 6; i++) {
    printf("\n");
    }

    printf("\n Sales Report (Highest to Lowest): \n");
  printf("\n Month       Sales\n ");
  printf("\n");

    for (int i = 0; i < 12; i++)
    {
        for (int j = i + 1; j < 12; j++)
        {
            if (float_lines[i] < float_lines[j])
            {
                float temp = float_lines[i];
                char * tempmonth = months[i];
                float_lines[i] = float_lines[j];
                months[i] = months[j];
                float_lines[j] = temp;
                months[j] = tempmonth;
            }
        }
    
}

//sort_array(float_lines);
    
    for (int i = 0; i < 12; i++)
    {
        printf(" %-10s  %.2f \n", months[i], float_lines[i]);
    }
    




  fclose(input_file);
  return 0;
}




