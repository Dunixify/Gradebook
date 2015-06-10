#include "student.h"
student::student(){
	name = "";
	grade = 0.0;
	//headCategory = NULL; 
	//tailCategory = NULL;
	//next = NULL;
}
student::student(string n){
	name = n;
	grade = 0.0;
	//headCategory = NULL;s
	//tailCategory = NULL;
	//next = NULL;
}
void student::addCategory(category c){
	if (numCats == 0){
		//		delete[] categories;
		categories = new category{ c };
	}
	else{
		category* temp = new category[numCats + 1];
		for (int i = 0; i < numCats; i++){
			temp[i] = categories[i];
		}
		temp[numCats] = category(c);
		delete[] categories;
		categories = temp;
	}
	numCats++;
}
void student::removeCategory(int index){
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
float student::getWeightedPointsForCategory(int ci){
	return categories[ci].getPoints() * categories[ci].weight;
}
void student::printCategories(){
	for (int i = 0; i < numCats; i++){
		cout << i + 1 << ". " << categories[i].name << endl;
	}
	cout << endl;
}