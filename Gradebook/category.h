#ifndef CATEGORY_H
#define CATEGORY_H
#include "assignmentUnit.h"

class category{
private:
	float points;
public:
	assignmentUnit* assignments = new assignmentUnit[];
	string name;
	float weight;
	int numAssignments;
	//	assignmentUnit* head;
	//	assignmentUnit* tail;
	//	category* next;
	category();
	category(string n, float w);
	//	category(category *c);
	float getPoints();
	void editAssignmentUnit(int index);
	void addAssignmentUnit(float pts, string n);
	void removeAssignmentUnit(int index);
	void printAssignments();
};
#endif