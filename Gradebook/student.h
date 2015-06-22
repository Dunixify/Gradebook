#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include "category.h"

class student{
private:
	float grade;

public:
	category* categories = new category[];
	string name;
	int numCats = 0;
	student();
	student(string n);
	void addCategory(category c);
	void removeCategory(int index);
	float getWeightedPointsForCategory(int ci);
	float getPoints(int ci);
	float getPoints(int ci, int ai);
	void printCategories();
};
#endif