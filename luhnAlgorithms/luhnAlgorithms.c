#include <stdio.h>
#include <stdlib.h>

void LuhnAlgorithms(int*, int);

int main()
{
    FILE* file = fopen ("file.txt", "r");
    int array_length = 0;
    int *array = (int*)malloc(sizeof(int) * array_length);
    int i = 0;

    fscanf (file, "%d", &i);    
    while (!feof(file))
    {  
        array[array_length] = i;
        fscanf (file, "%d", &i);
        array_length++;     
    }

    fclose (file);

    for (int i = 0; i < array_length; i++) // txt dosyasından çekilen veriler
        printf("%d ", array[i]); 

    printf(" -> Txt dosyasindan cekilen veriler");
    printf("\n\n");   

     

    LuhnAlgorithms(array, array_length);  // Luhn algoritması uygulanması

    
    return 0;
}

void LuhnAlgorithms(int *array, int array_length)
{
    for (int i = array_length-2; i >= 0; i -= 2)  // 1. adım -> Değerleri 2 ile çarp
        array[i] *= 2;
        
    for (int i = 0; i < array_length; i++)
        printf("%d ", array[i]);     

    printf(" -> Cift sirada bulunanlarin 2 ile carpilmis hali");    

    int i = 0;
    while (1==1)    // 2. adım -> Değerleri 9 dan büyük olanların(yani rakam olmayanları) sayı değerlerini topla
    {
        if (array[i] > 9)
        {
            int temp = array[i];
            int sum = (temp % 10) + 1;
            array[i] = sum;
            sum = 0;
            temp = 0;
        }

        if(i == 15)
            break;

        i++;
    }
   
    printf("\n\n");

    for (int i = 0; i < array_length; i++)
        printf("%d ", array[i]); 
    
    printf(" -> Degerleri 9'dan buyuk olanlarin rakamlarini topladik simdi de tum degerleri topla");
    printf("\n\n");

    i = 0;
    int sum = 0;
    for (int i = 0; i < array_length; i++)  // 3. adım -> Tüm değerleri topla
        sum += array[i];
    
    printf("Sum value: %d\n", sum);

    int mod = (sum % 10) == 0 ? printf("Kart numarasi gecerli...") : printf("Kart numarasi gecersiz..."); // 4. adım -> sum değerinin 10'a göre modu alınır. 0'a eşitse kart no geçerli, yoksa geçersizdir.
}
