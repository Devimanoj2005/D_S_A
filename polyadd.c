#include <stdio.h>

struct term {
    int coeff;
    int expo;
};

int main() {
    struct term poly1[100], poly2[100], result[200];
    int n1, n2, i = 0, j = 0, k = 0;

    printf("Enter number of terms for first polynomial: ");
    scanf("%d", &n1);

    printf("Enter coefficient and exponent for first polynomial term:\n");
    for (i = 0; i < n1; i++) {
        scanf("%d%d", &poly1[i].coeff, &poly1[i].expo);
    }

    printf("Enter number of terms for second polynomial: ");
    scanf("%d", &n2);

    printf("Enter coefficient and exponent for second polynomial terms \n");
    for (i = 0; i < n2; i++) {
        scanf("%d%d", &poly2[i].coeff, &poly2[i].expo);
    }

    i = 0; j = 0; k = 0;

    while (i < n1 && j < n2) {
        if(poly1[i].expo == poly2[j].expo)
        {
            result[k].poly1[i].coeff+ poly2[j].coeff;
            result[k].expo=poly1[i].expo;
            i++;
            j++;
            k++;
        }
        if(poly1[i].expo > poly2[j].expo)
        {
            result[k].coeff=poly1[i].coeff;
            result[k].expo=poly1[i].expo;
            i++;
            k++;
        }
        if(poly1[i].expo < poly2[j].expo)
        {
          result[k].coeff=poly2[j].coeff;
           result[k].expo=poly2[j].expo;
           i++;
           j++;
        }


        }
        while (i<n1)
        {
            result[k].coeff = poly1[i].coeff;
            result[k].expo = poly1[i].expo;
            i++;
            k++; 
            
        }
        while (j<=n2)
        {
            result[k].coeff= poly1[i].coeff;
            result[k].expo= poly1[i].expo;
            i++;
            j++;
        }
        
            for(i=1;i<k;i++)
            {

                if(i<k-1)
                {
                    printf("%dX^%d",result[i].coeff,result[j].expo);
                }
                else{

                
                    printf("%dX^%d",result[i].coeff,result[j].expo);
                    

                }
            }
        
    }
    