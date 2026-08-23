#include <stdio.h>


typedef struct studentgrade
{
	char name[21];
	char course[20];
	double grade;

}Studentgrades;



int main(void) {

	Studentgrades coursename[5] = {
	{"Josh","MATH1910",0},{ "Josh","PROG1926", 0 },{ "Josh","PROG2112", 0 },{ "Josh","INFO1380", 0 },{ "Josh","PROG1246", 0 }
	};



	for (int i = 0; i < 5; i++) {
		printf("Name:%s\n, Course:%s\n, Grade:%f\n", coursename[i].name, coursename[i].course, coursename[i].grade);
	}




	return 0;
}




