#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/times.h>
#include <unistd.h>



int main (){
        struct tms start, end;
        long clocks_per_sec=sysconf(_SC_CLK_TCK);
        long clocks;
        int N;
        printf("Enter the amount of numbers: ");
        scanf("%d",&N);
        srand(time(NULL));
        int i=0,k,an,z,zi,min,max;
        char t[5];
        int *a = malloc (sizeof(int)*N);
        while(i!=N-1)
        {
                a[i]=rand()%100;
                i++;
        }
        i=0;
        printf("Sort by:\n1.Selection sort\n2.Insertion sort\n");
        scanf("%d",&an);
        switch(an)
        {
                case 1:
                        k=0;
                        times(&start);
                        while(k!=N)
                        {
                                i=k;
                                min=a[i];
                                while(i!=N)
                                        {
                                        if (a[i]<=min)
                                        {
                                                min=a[i];
                                                zi=i;
                                        }                 
                                        i++;
                                }
                                z=a[k];
                                a[k]=min;
                                a[zi]=z;
                                k++;
                        }
                        times(&end);
                        clocks=end.tms_utime-start.tms_utime;
                        printf("Time taken:%lf sec.\n",(double)clocks / clocks_per_sec);
                        break;  
                case 2:
                       i=0;
                       k=0;
                       times(&start);
                       while(i+1!=N)
                                {
                                if(a[i+1]<a[i])
                                {
                                        k=i;
                                        t[0]=a[k+1];
                                        while(a[k+1]<a[k])
                                        {
                                                a[k+1]=a[k];
                                                a[k]=t[0];
                                                k--;
                                        }
                                        i++;
                                }
                                else
                                {
                                        i++;
                                }
                                }
                        times(&end);
                        clocks=end.tms_utime-start.tms_utime;
                        printf("Time taken:%lf sec.\n",(double)clocks / clocks_per_sec);
                        break;
                default:
                        printf("Wrong input, please try again!\n");
                        return 1;       
        }
        i=0;
        printf("Put a search number: ");
        scanf("%d",&k);
        i=0;
        for(i=0;i<=N;i++)
        {
                if(k==a[i])
                {
                        break;
                        i=N+1;
                }
        }
        if (i==N+1)
        {
                printf("Error, number not found!\n");
                return 1;
        }
        i=N/2;
        max=N;
        min=0;
        while(k!=a[i])
        {
                if(k>a[i])
                {
                        min=i;
                        i=(max+min)/2;
                }
                if(k<a[i])
                {
                        max=i;
                        i=(max+min)/2;
                } 
        }
        printf("index %d in mass is %d\n",k,i);
        return 0;
}
