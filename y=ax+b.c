#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

float train[][2]= {
    {2,6},
    {3,8},
    {4,10},
    {5,12},
    {6,14},
    {7,16},
    {8,18}
};

int train_count=sizeof(train)/sizeof(train[0]);
float rand_float(void) {
    return (float)rand()/(float)RAND_MAX;
}

float cost(float a,float b){
    float t_cost=0;
    for(int i=0;i<train_count;i++){
        float er=train[i][1]-(a*train[i][0]+b);
        t_cost=t_cost+er*er;
    }
    return t_cost;
}

int main(){
    srand(time(0));
    float a=rand_float()*10.0f; 
    float b=rand_float()*10.0f; 
    printf("random a=%f, random b=%f\n",a,b);
    float learning_rate=0.001;
    float h=0.001;
    for(int i=0;i<5000;i++){
        float dcost_a=(cost(a+h,b)-cost(a,b))/h;
        float dcost_b=(cost(a,b+h)-cost(a,b))/h;
        a=a-dcost_a*learning_rate;
        b=b-dcost_b*learning_rate;
    }
    printf("trin_cout=%d\n",train_count);
    printf("predicted_a=%f    predicted_b=%f \n",a,b);
    /* for(int i=0;i<train_count;i++){
        printf("intput=%f, actual_output=%f, predicted_output=%f\n",train[i][0],train[i][1],(w*train[i][0]+b)); 
    } */

    printf("enter number of query=");
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        float input;
        printf("enter input=");
        scanf("%f",&input);
        printf("input=%f,  output=%f\n",input,a*input+b);
    }

    return 0;
}
