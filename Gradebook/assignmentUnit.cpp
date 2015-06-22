#include<iostream>
#include"assignmentUnit.h"

assignmentUnit::assignmentUnit(){
	points = 0.0;
	name = "";
}
assignmentUnit::assignmentUnit(string n, float p){
	name = n;
	points = p;
}
assignmentUnit::assignmentUnit(assignmentUnit* a){
	name = a->name;
	points = 0.0;
}
void assignmentUnit::setPoints(float pts){
	points = pts;
}
float assignmentUnit::getPoints(){
	return points;
}
void assignmentUnit::print(){
	cout << "Assignment name: " << name << endl;
	cout << "Points: " << points << endl;
	cout << endl;
}