 #include<stdio.h>
 #include<algorithm>
 #include<cmath>
  
 int main(){
 	printf("可达是不是最爱皮卡啦");
	int x=rand()%100 + 1;//不能随机出整数吗1-100 
	printf("%d",x);//你连随机数都不会 
	if (x%2==0)
	printf("yes");
	else
	printf("pika"); 
 	return 0;
 	
 }
