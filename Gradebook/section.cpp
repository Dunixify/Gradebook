#include "section.h"
#include<string>
#include<iostream>
using namespace std;
section::section(){
	name = "";
	points = 0.0;
	totalWeight = 0.0;
	numCats = 0;
	numStuds = 0;
	//headCategory = NULL;
	//tailCategory = NULL;
	//headStudent = NULL;
	//tailStudent = NULL;
}
section::section(string n){
	name = n;
	points = 0.0;
	totalWeight = 0.0;
	numCats = 0;
	numStuds = 0;
	//headCategory = NULL;
	//tailCategory = NULL;
	//headStudent = NULL;
	//tailStudent = NULL;
}

//void copyCategoryForStudent(category *c, student *s){
//	assignmentUnit *current = h;
//	category *copy = new category();
//	copy->addAssignmentUnit(0.0, h->name);
//	current = current->next;
//	while (current != NULL){
//		copy->addAssignmentUnit(0.0, current->name);
//		current = current->next;
//	}
//	s->addCategory(copy);
//}
float section::getPoints(){
	float totalPoints = 0;
	for (int i = 0; i < numCats; i++){
		totalPoints += categories[i].getPoints();
	}
	return totalPoints;
}
void section::editCategory(int index){
	int option = 1;
	while (option){//single assignment edit menu
		cout << endl;
		cout << "1. " << "Edit category name" << endl;
		cout << "2. " << "Edit category weight" << endl;
		cout << "3. " << "Edit assignment in category" << endl;
		cout << "4. " << "Add assignment" << endl;
		cout << "5. " << "Delete category" << endl;
		cout << "6. " << "Previous menu" << endl << endl;
		cout << "Menu option number: ";
		cin >> option;

		if (option == 1){
			string name;
			cout << "category name: " << categories[index].name << endl;
			cout << "New name: ";
			cin >> name;
			categories[index].name = name;
		}
		else if (option == 2){
			float weight;
			cout << "Current weight: " << categories[index].getPoints() << endl;
			cout << "New weight: ";
			cin >> weight;
			categories[index].weight = weight;
		}
		else if (option == 3){
			int assNum = 1;
			while (assNum){
				categories[index].printAssignments();
				cout << categories[index].numAssignments + 1 << ". " << "Previous menu" << endl;
				cout << "Edit assignment number: ";
				cin >> assNum;
				if (assNum == categories[index].numAssignments + 1){
					break;
				}
				else if (assNum<1 || assNum>categories[index].numAssignments + 1){
					cout << "Invalid choice. Please try again." << endl;
					continue;
				}
				else{
					int numAss = categories[index].numAssignments;
					categories[index].editAssignmentUnit(assNum - 1);
					if (categories[index].numAssignments < numAss){
						for (int i = 0; i < numStuds; i++){
							students[i].categories[index].removeAssignmentUnit(assNum - 1);
						}
					}
				}
			}
		}
		else if (option == 4){
			string name;
			float points;
			cout << "Assignment name: ";
			cin >> name;
			cout << "Points: ";
			cin >> points;
			categories[index].addAssignmentUnit(points, name);
			for (int i = 0; i < numStuds; i++){
				students[i].categories[index].addAssignmentUnit(0, name);
			}
			cout << endl << "Assignment \"" << name << "\" added to category \"" << categories[index].name << ".\"" << endl;
		}
		else if (option == 5){
			removeCategory(index);
			cout << "Category deleted." << endl << endl;
			return;
		}
		else if (option == 6){
			return;
		}
	}
}
void section::addCategory(string n, float w){
	if (totalWeight + w > 100){
		cout << "Category exceeds maximum weight by " << totalWeight + w - 100 << " %." << endl << endl;
		return;
	}
	//else{
	//	if (numCats == 0){
	//		delete[] categories;
	//		categories = new category[1];
	//		categories[0] = category(n, w);
	//	}
	else{
		if (numCats == 0){
			categories = new category[1];
			categories[0] = category(n, w);
			for (int i = 0; i < numStuds; i++){
				students[i].addCategory(categories[0]);
			}
		}
		else{
			category *temp = new category[numCats + 1];
			for (int i = 0; i < numCats; i++){
				if (categories[i].name == n){
					cout << "Category name is already in use." << endl;
					delete[] temp;
					return;
				}
				temp[i] = categories[i];
			}
			temp[numCats] = category(n, w);
			//if (numCats == 1){
			//	delete categories;
			//}
			//else{
				delete[] categories;
			//}
			categories = temp;
			for (int i = 0; i < numStuds; i++){
				students[i].addCategory(categories[numCats]);
			}
		}
		totalWeight += w;
		numCats++;
	}

	//	}
}
void section::removeCategory(int index){
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
	totalWeight -= categories[index].weight;
	for (int i = 0; i < numStuds; i++){
		students[i].removeCategory(index);
	}
	numCats--;
}
void section::editStudent(int index){
	int option;
	while (students){//single student edit menu
		cout << "1. " << "Edit student name" << endl;
		cout << "2. " << "Edit scores" << endl;
		cout << "3. " << "Delete student" << endl;
		cout << "4. " << "Previous menu" << endl;
		cout << endl << "Menu option number: ";
		cin >> option;
		if (option == 1){
			string name;
			cout << "Current name: " << students[index].name << endl;
			cout << "New name: ";
			cin >> name;
			students[index].name = name;
		}
		else if (option == 2){
			int catNum = 1;
			while (catNum){
				printCategories();
				cout << numCats + 1 << ". " << "Previous menu" << endl;

				cout << "Category containing asignment: ";
				cin >> catNum;
				int catIndex = catNum - 1;
				cout << endl << endl;
				if (catNum == numCats + 1){
					break;
				}
				int assNum = 1;
				while (assNum){
					students[index].categories[catIndex].printAssignments();
					cout << categories[catIndex].numAssignments + 1 << ". " << "Previous menu" << endl;


					cout << "Edit score on assignment number: ";
					cin >> assNum;
					if (assNum == students[index].categories[catIndex].numAssignments + 1){
						break;
					}
					float score;
					cout << "Assignment: " << students[index].categories[catIndex].assignments[assNum - 1].name << endl;
					cout << "Current score: " << students[index].categories[catIndex].assignments[assNum - 1].getPoints() << "/" << categories[catIndex].assignments[assNum - 1].getPoints() << " points" << endl;
					cout << "New score: ";
					cin >> score;
					students[index].categories[catIndex].assignments[assNum - 1].setPoints(score);
					cout << endl << "Score: " << students[index].categories[catIndex].assignments[assNum - 1].getPoints() << "/" << categories[catIndex].assignments[assNum - 1].getPoints() << "points";
				}
			}
		}
		else if (option == 3){
			removeStudent(index);
			cout << endl << "Student deleted." << endl;
			break;
		}

		else if (option == 4){
			break;
		}
		else{
			cout << "Invalid choice. Try again." << endl;
			continue;
		}
	}
}
void section::addStudent(string n){
	if (numStuds == 0){
		//		delete[] students;
		students = new student{ n };
		for (int i = 0; i < numCats; i++){
			students[0].addCategory(categories[i]);
		}
	}
	else{
		student* temp = new student[numStuds + 1];
		for (int i = 0; i < numStuds; i++){
			temp[i] = students[i];
		}
		temp[numStuds] = student(n);
		for (int i = 0; i < numCats; i++){
			temp[numStuds].addCategory(categories[i]);
		}
		if (numStuds == 1){
			delete students;
		}
		else{
			delete[] students;
		}
		students = temp;
	}
	numStuds++;
}
void section::removeStudent(int index){
	student* temp = new student[numStuds - 1];
	if (index == 0){
		for (int i = 1; i < numStuds; i++){
			temp[i - 1] = students[i];
		}
	}
	else if (index == numStuds - 1){
		for (int i = 0; i < numStuds - 1; i++){
			temp[i] = students[i];
		}
	}
	else{
		for (int i = 0; i < index; i++){
			temp[i] = students[i];
		}
		for (int i = index + 1; i < numStuds; i++){
			temp[i - 1] = students[i];
		}
	}
	delete[] students;
	students = temp;
	numStuds--;
}

void section::printCategories(){
	/*if (numCats == 1){
		cout << 1 << ". " << categories << endl;
	}
	else{*/
		for (int i = 0; i < numCats; i++){
			cout << i + 1 << ". " << categories[i].name /*<< ": " << categories[i].weight << "%" */ << endl;
		}
//	}
	
}
void section::printStudents(){
	for (int i = 0; i < numStuds; i++){
		cout << i + 1 << ". " << students[i].name << endl;
	}
}