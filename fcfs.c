#include <stdio.h>

struct process{
    int arrival_tym,burst_tym,tat,wt;
};

int main() {
    int n;
    printf("Enter the number of process:");
    scanf("%d",&n);
    struct process p[10];
    for(int i=0;i<n;i++){
        printf("\n Enter the arrival time of process:%d",i+1);
        scanf("%d",&p[i].arrival_tym);
        printf("\n Enter the burst time of process:%d",i+1);
        scanf("%d",&p[i].burst_tym);

    }
    int current_tym=0;


    for(int i=0;i<n;i++){
        if(current_tym<p[i].arrival_tym)
            current_tym=p[i].arrival_tym;
        int completion=current_tym+p[i].burst_tym;
        p[i].tat=completion-p[i].arrival_tym;
        p[i].wt=p[i].tat-p[i].burst_tym;
        current_tym+=p[i].burst_tym;

    }
    float avg_tt=0;
    float avg_wt=0;
    for (int i = 0; i < n; i++) {
        printf("\nprocess : %d\tburst time:%d\t\tarrival time:%d\t\ttat:%d\t\twaiting time:%d",i+1,p[i].burst_tym,p[i].arrival_tym,p[i].tat,p[i].wt);
        avg_tt+=p[i].tat;
        avg_wt+=p[i].wt;
    }
    avg_tt/=n;
    avg_wt/=n;
    printf("\nAverage tt:%f\n Average wt:%f",avg_tt,avg_wt);

}
