#ifndef ASSIGNMENTUNIT_H
#define ASSIGNMENTUNIT_H
#include <string>
using namespace std;

class assignmentUnit{
private:
	float points;
public:
	//	assignmentUnit *next;
	string name;
	assignmentUnit(assignmentUnit*a);
	float getPoints();
	void setPoints(float pts);
	void print();
	assignmentUnit();
	assignmentUnit(string n, float p);
};
#endif