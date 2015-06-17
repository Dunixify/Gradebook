#include "category.h"
#include <iostream>
category::category(){
	name = "";
	points = 0.0;
	weight = 0.0;
	numAssignments = 0;
	//head = NULL;
	//tail = NULL;
	//next = NULL;
}
category::category(string n, float w){
	name = n;
	points = 0.0;
	weight = w;
	numAssignments = 0;
	//head = NULL;
	//tail = NULL;
	//next = NULL;
}
//category::category(category *c){
//	name = c->name;
//	points = c->getPoints();
//	weight = c->weight;
//	assignments = c->assignments;
//	//head = c->head;s
//	//tail = c->tail;
//	//next = c->next;
//	numAssignments = c->numAssignments;
//}
//category::category(category& c){
//	name = c.name;
//	points = c.getPoints();
//	weight = c.weight;
//	assignments = c.assignments;
//	numAssignments = c.numAssignments;
//}
float category::getPoints(){
	float totalPoints = 0;
	for (int i = 0; i < numAssignments; i++){
		totalPoints += assignments[i].getPoints();
	}
	return totalPoints;
}
void category::editAssignmentUnit(int index){
	int option;
	while (assignments){//single assignment edit menu
		cout << "1. " << "Edit assignment name" << endl;
		cout << "2. " << "Edit assignment points" << endl;
		cout << "3. " << "Delete assignment" << endl;
		cout << "4. " << "Previous menu" << endl;
		cout << "Menu option number: ";
		cin >> option;
		if (option == 1){
			string name;
			cout << "Assignment name: " << assignments[index].name << endl;
			cout << "New name: ";
			cin >> name;
			assignments[index].name = name;
		}
		else if (option == 2){
			float points;
			cout << "Current points: " << assignments[index].getPoints() << endl;
			cout << "New points: ";
			cin >> points;
			assignments[index].setPoints(points);
		}
		else if (option == 3){
			removeAssignmentUnit(index);
			cout << "Assignment deleted." << endl << endl;
			return;
		}
		else if (option == 4){
			return;
		}
	}
}
void category::addAssignmentUnit(float pts, string n){
	if (numAssignments == 0){
		//		delete[] assignments;
		assignments = new assignmentUnit[1];
		assignments[0] = assignmentUnit(n, pts);
	}
	else{
		assignmentUnit* newAssignments = new assignmentUnit[numAssignments + 1];
		for (int i = 0; i < numAssignments; i++){
			newAssignments[i] = assignmentUnit(assignments[i].name, assignments[i].getPoints());
		}
		newAssignments[numAssignments] = assignmentUnit(n, pts);
		delete[] assignments;
		assignments = newAssignments;
	}
	points += pts;
	numAssignments++;
}
void category::removeAssignmentUnit(int index){
	assignmentUnit* temp = new assignmentUnit[numAssignments - 1];
	if (index == 0){
		for (int i = 1; i < numAssignments; i++){
			temp[i - 1] = assignments[i];
		}
	}
	else if (index == numAssignments - 1){
		for (int i = 0; i < numAssignments - 1; i++){
			temp[i] = assignments[i];
		}
	}
	else{
		for (int i = 0; i < index; i++){
			temp[i] = assignments[i];
		}
		for (int i = index + 1; i < numAssignments; i++){
			temp[i - 1] = assignments[i];
		}
	}
	delete[] assignments;
	assignments = temp;
	numAssignments--;
}
void category::printAssignments(){
	cout << "Category: " << name << "  Weight: " << weight << "%" << endl;
	cout << "Assignments:" << endl;
	for (int i = 0; i<numAssignments; i++){
		cout << i + 1 << ". " << assignments[i].name << " : " << assignments[i].getPoints() << " Points" << endl;
	}
}