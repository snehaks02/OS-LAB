#include <stdio.h>

struct process{
    int arrival_tym,burst_tym,tat,wt,id;
    int complete;
};


void swap(struct process *p1,struct process *p2){
 struct  process temp;
    printf("\n swapping %d and %d",p1->id,p2->id);
    temp=*p1;
    *p1=*p2;
    *p2=temp;
}

int main() {
    int n;
    printf("Enter the number of process:");
    scanf("%d",&n);
    struct process p[n];
    for(int i=0;i<n;i++){
        printf("\n Enter the burst time of process:%d",i+1);
        scanf("%d",&p[i].burst_tym);
        p[i].id=i+1;


    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(p[j].burst_tym>p[j].burst_tym) {
                swap(&p[j], &p[j + 1]);
            }
        }
    }
    int current_tym=0;


    for(int i=0;i<n;i++){
       int completed=current_tym+p[i].burst_tym;
        p[i].tat=completed;
        p[i].wt=p[i].tat-p[i].burst_tym;
        current_tym+=p[i].tat;

    }
    float avg_tt=0;
    float avg_wt=0;
    for (int i = 0; i < n; i++) {
        printf("\nprocess : %d\tburst time:%d\t\ttat:%d\t\twaiting time:%d",i+1,p[i].burst_tym,p[i].tat,p[i].wt);
        avg_tt+=p[i].tat;
        avg_wt+=p[i].wt;
    }
    avg_tt/=n;
    avg_wt/=n;
    printf("\nAverage tt:%f\n Average wt:%f",avg_tt,avg_wt);

}
