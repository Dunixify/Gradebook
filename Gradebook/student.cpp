#include "student.h"
student::student(){
	name = "";
	grade = 0.0;
	numCats = 0;
}
student::student(string n){
	name = n;
	grade = 0.0;
	numCats = 0;
}
void student::addCategory(category c){
	if (numCats == 0){
		//		delete[] categories;
		categories = new category[1];
		categories[0].name = c.name;
		categories[0].numAssignments = 0;
		categories[0].weight = c.weight;
		for (int i = 0; i < c.numAssignments; i++){
			categories[0].addAssignmentUnit(0.0, c.assignments[i].name);
		}
	}
	else{
		category* temp = new category[numCats + 1];
		for (int i = 0; i < numCats; i++){
			temp[i] = categories[i];
		}
		temp[numCats].name = c.name;
		temp[numCats].numAssignments = 0;
		temp[numCats].weight = c.weight;
		for (int i = 0; i < c.numAssignments; i++){
			temp[numCats].addAssignmentUnit(0.0, c.assignments[i].name);
		}
		/*if (numCats == 1){
			delete categories;
		}
		else{*/
			delete[] categories;
		//}
		categories = temp;
	}
	numCats++;
}
void student::removeCategory(int index){
	if (numCats == 1){
		delete categories;
	}
	else if (numCats == 2){
		if (index == 0){
			category* temp = new category{ categories[1] };
			delete[] categories;
			categories = temp;
		}
		else{
			category* temp = new category{ categories[0] };
			delete[] categories;
			categories = temp;
		}
	}
	else{
		category* temp = new category[numCats - 1];
		if (index == 0){
			for (int i = 1; i < numCats; i++){
				temp[i - 1] = categories[i];
			}
		}
		else if (index == numCats - 1){
			for (int i = 0; i < numCats - 1; i++){
				temp[i] = categories[i];
			}
		}
		else{
			for (int i = 0; i < index; i++){
				temp[i] = categories[i];
			}
			for (int i = index + 1; i < numCats; i++){
				temp[i - 1] = categories[i];
			}
		}
		delete[] categories;
		categories = temp;
	}
	numCats--;
}
float student::getPoints(int ci, int ai){
	//get points for specific assignment
	return categories[ci].assignments[ai].getPoints();
}
float student::getPoints(int ci){
	//get points for specific category
	return categories[ci].getPoints();
}
void student::printCategories(){
	for (int i = 0; i < numCats; i++){
		cout << i + 1 << ". " << categories[i].name << endl;
	}
	cout << endl;
}