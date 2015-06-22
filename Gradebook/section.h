#ifndef SECTION_H
#define SECTION_H
#include "student.h"
#include <sstream>
#include <fstream>
class section{
public:
	string name;
	float points;
	float totalWeight;
	int numCats = 0;
	int numStuds = 0;
	category* categories = new category[];
	student* students = new student[];
	section();
	section(string n);
	float getPoints();
	void editCategory(int index);
	void addCategory(string n, float w);
	void removeCategory(int index);
	void editStudent(int index);
	void addStudent(string n);
	void removeStudent(int index);
	float fetchGrade(int si);
	float fetchGrade(int si, int ci);
	float averageGrades(int ci);
	float averageGrades(int ci, int ai);
	float averageGrades();
	void printCategories();
	void printStudents();
	void save(int ci);
	void save();
};
#endif