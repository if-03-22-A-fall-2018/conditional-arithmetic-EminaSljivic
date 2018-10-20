/*----------------------------------------------------------
 *				HTBLA-Leonding / Class: 2AHIF
 * ---------------------------------------------------------
 * Exercise Number:     04
 * Title:			          Conditional Arithmetics
 * Author:			        Emina Sljivic
 * ----------------------------------------------------------
 * Description:
 * First the user has to select what operator he want (+ / *)
 * and then he has to choose a number between 1 and 100.
 * After that every number between 1 and the number the
 * user entered will be added or multiplied but only if they
 * are divisible by 3 or 5.
 * If there is a overflow it should be printed out.
 * ----------------------------------------------------------
 */
 #include <stdio.h>

void read_operator(int* operator,int* number){
  //Read operator
  do {
    printf("Select Add (1) or Multiply (2): ");
    scanf("%d",operator);
  } while(*operator!=1 && *operator!=2);
  //Read number
  do {
    printf("Select a number in the range (1-100): ");
    scanf("%d",number);
  } while(*number<1||*number>100);
}

int calculate_Arithmetic(int number, int operator,int* calculable){
    int result=0;

    //Add
    if(operator==1)
    {
      result=0;
      for (int i = 3; i <= number; i++) {

          if(i%3==0 || i%5==0){
            result=result+i;
          }
      }
      if(result < 0){
        *calculable=-1;
        printf("Overflow!\n");
      }
    }

    //Multiply
    else if(operator==2)
    {
      result=1;
      for (int i = 3; i <= number; i++) {
          if(i%3==0 || i%5==0){
            result=result*i;
          }
      }
      if(result<0){
        *calculable=-1;
        printf("Overflow!\n");
      }
    }

    return result;
}

int main(int argc, char const *argv[]) {
  int operator;
  int number;
  int result;
  int calculable=0;

  //User chooses between Add or Multiply and selctes a number between 1 and 100
  read_operator(&operator, &number);
  //Result is getting calculated
  result=calculate_Arithmetic(number,operator,&calculable);

  //Print result except overflow occurred
  if(calculable!=-1){
    printf("The result is: %d\n",result);
  }
  return 0;
}
