//result:맞았습니다!!
#include <stdio.h>

int main()

{

    int i,j,k,n,udspace;

    scanf("%d", &n);

    udspace=(2*(n-1))-1;

    for(i=0; i<n; i++) printf("*");

    for(i=0; i<udspace; i++) printf(" ");

    for(i=0; i<n; i++) printf("*");

    udspace-=2;

    printf("\n");

    for(i=0; i<n-1; i++) {

        for(j=0; j<=i; j++) printf(" ");

        printf("*");

        for(k=0; k<n-2; k++) printf(" ");

        printf("*");

        for(k=0; k<udspace; k++) printf(" ");

        udspace-=2;

        if(i!=n-2)printf("*");

        for(k=0; k<n-2; k++) printf(" ");

        printf("*\n");

    }

    udspace=1;

    for(i=n-2; i>0; i--) {

        for(j=i; j>0; j--) printf(" ");

        printf("*");

        for(k=n-2; k>0; k--) printf(" ");

        printf("*");

        for(k=udspace; k>0; k--) printf(" ");

        udspace+=2;

        printf("*");

        for(k=n-2; k>0; k--) printf(" ");

        printf("*\n");

    }

    for(i=0; i<n; i++) printf("*");

    for(i=0; i<udspace; i++) printf(" ");

    for(i=0; i<n; i++) printf("*");

    return 0;

}