#include <stdio.h>
#include <math.h>

long int get_card_number ();
int num_count (long int num);
int checksum (long int num);
char* card_type (int count, int sum, long int num);

int main(void)
{
    long int num = get_card_number();
    char* type_card = card_type(num_count(num), checksum(num), num);
    
    printf("%s\n", type_card);

}

long int get_card_number (){
    int validInput = 0;
    long int num = 0;

    do{
        printf("Number: ");
        (scanf("%ld", &num) == 1 && num >= 0)? validInput = 1 : scanf("%*[^\n]");
    }
    while(!validInput);

    return num;
}

int num_count (long int num){
    int numCtr = 0;
    while(num>0){
        num /= 10.0;
        numCtr++;
    }

    return numCtr;
}

int checksum (long int num){
    int numCtr = 0, total = 0, digit = 0;
    while(num>0){
        digit = num % 10;
        num /= 10.0;
        numCtr++;

        if(numCtr % 2 == 0){
            digit *= 2;

            if(digit > 9)
                digit-=9;
        }

        total += digit;
    }

    return total;
}

char* card_type (int count, int sum, long int num){
    int AMEX = num/pow(10,13);
    int MASTERCARD = num/pow(10,14);
    int VISA1 = num/pow(10,12);
    int VISA2 = num/pow(10,15);

    if(sum % 10 == 0){
        if(count == 15 && (AMEX == 34 || AMEX == 37)){
            return "AMEX";
        }
        else if(VISA1 == 4 || VISA2 == 4){
            return "VISA";
        }
        else if(count == 16 && (MASTERCARD == 51 || MASTERCARD == 52 || MASTERCARD == 53 || MASTERCARD == 54 || MASTERCARD == 55)){
            return "MASTERCARD";
        }
        else{
            return "INVALID";
        }
    }
    else{
        return "INVALID";
    }
}
