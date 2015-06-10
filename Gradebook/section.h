#ifndef SECTION_H
#define SECTION_H
#include "student.h"

class section{
public:
	string name;
	float points;
	float totalWeight;
	int numCats = 0;
	int numStuds = 0;
	category* categories = new category[];
	student* students = new student[];
	//category* headCategory;
	//category* tailCategory;
	//student* headStudent;
	//student* tailStudent;
	section();
	section(string n);
	float getPoints();
	void editCategory(int index);
	void addCategory(string n, float w);
	void removeCategory(int index);
	void editStudent(int index);
	void addStudent(string n);
	void removeStudent(int index);
	void printCategories();
	void printStudents();
};
#endif