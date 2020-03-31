#include<stdio.h>
struct Stu
{
	bool pen paper,question_paper,all_resources;
}p1,p2,s3;					
void student_one()
{
	p1.all_resources=1;		
	p1.paper=1;			
	p1.question_paper=1;
	printf("/nFirst Student Process has Completed the Assignment\n\n");
}	
void student_two()
{
	p2.all_resources=1;
	p2.pen=1;
	p2.question_paper=1;
	printf("/nSecond Student Process has Completed the Assignment \n\n");
}
void student_three()
{
	p3.all_resources=1;
	p3.pen=1;
	p3.paper=1;
	printf("/nThird Student Process has Completed the Assignment \n\n");
}
int main()
{
	p1.all_resources=0;p1.paper=0;p1.pen=0;p1.question_paper=0;	
	p2.all_resources=0;p2.paper=0;p2.pen=0;p2.question_paper=0;
	p3.all_resources=0;p3.paper=0;p3.pen=0;p3.question_paper=0;			
	do
	{
		int a,b;
		printf("1.Pen\n");			
		printf("2.Paper\n");
		printf("3.Question Paper\n");
		printf("Select any two items to be placed on the shared table:\n");
		scanf("%d %d",&a,&b);	
		if((a==1 && b==2) || (a==2 && b==1) && p3.all_resources==0) student_three();	
		if((a==2 && b==3) || (a==3 && b==2) && p1.all_resources==0) student_one();
		if((a==1 && b==3) || (a==3 && b==1) && p2.all_resources==0) student_two();
	}while(p1.all_resources==0||p2.all_resources==0||p3.all_resources==0);
	printf("All Students have Completed the Assignments");
}

