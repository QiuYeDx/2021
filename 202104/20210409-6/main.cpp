//用数组实现简单的队列
int queue[MAXN];    //开辟队列需要的数组空间，其中MAXN是队列的最大能入队元素的次数
int head=0; //队首指针
int tail=0; //队尾指针，如果有新的元素插入，就会插入到这个位置
void push(int x){   //进队，需要判断队伍是否溢出
    if(tail >= MAXN)
        printf("Queue overflow.");
    else{
        queue[tail]=x;
        tail+=1;
    }
}
void pop(){ //弹出队首元素，需要判断是否队列为空
    if(head == tail)
        printf("Queue is empty.");
    else
        head+=1;
}
int front(){    //查询队首元素，需要判断是否队列为空
    if(head == tail){
        printf("Queue is empty.");
        return -1;
    }
    else
        return queue[head];
}