#include<stdio.h>
#include<stdlib.h> // for rand and srand
#include<time.h>
float train[][2] = {
    {0,0},
    {2, .2}, 
    {4,0.4}, 
    {6, 0.6}, 
    {8, 0.8},
    {10, 1},
    };
 //y=x*w

 #define train_count (sizeof(train)/sizeof(train[0]))

float rand_float(void) {
    return (float)rand()/(float)RAND_MAX; // [0.0, 1.0)
}

float cost(float w){
    float result=0.0f;
    for(int i=0;i<train_count;i++){
        float x=train[i][0];
        float y=x*w;
      //  printf("actual=%f,expected=%f\n",y,train[i][1]);
        float error=y-train[i][1];
        result+=error*error;
        
    }
    result/=train_count;
    return result;
}


int main() {
    srand(time(0));
    float w=rand_float()*10.0f;  
    printf("w=%f\n",w);
   // printf("average error=%f\n",cost(w));
    float eps=1e-3;
   // printf("%f\n",cost(w));
    //printf("%f\n",cost(w-eps));
    //printf("%f\n",cost(w-eps*2));
    float learning_rate=1e-3;
    for(int i=0;i<5000 ;i++){
    float dcost=(cost(w+eps)-cost(w))/eps; //finit difference methode // will force the value to 0
    //printf("dcost=%f\n",dcost);
    //printf("%f\n",cost(w)); //without defferebtiated value
    w-=learning_rate*dcost;
   // printf("cost=%f,w=%f\n",cost(w),w); // updated value
    }
    //printf("-------------------------------\n");
    printf("final w=%f\n",w);
    for(int i=0;i<train_count;i++){
        float x=train[i][0];
        float y=x*w;
        printf("actual=%f,expected=%f\n",y,train[i][1]);
    }
    /* printf("---------------user input----------------\n");
    for(int i=0;i<10;i++){
        float x;
        scanf("%f",&x);
        float y=x*w;
        printf("ans=%f\n",y);
        
    } */

    
    
return 0;
}