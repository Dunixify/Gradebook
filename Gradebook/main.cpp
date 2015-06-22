#include "section.h"

int main(){
	string sectionName;
	cout << "Personal Gradebook" << endl << endl;
	cout << "Enter the name of your class section to begin: " << endl;
	getline(cin, sectionName);
	section *section1 = new section(sectionName);
	int option = 1;
	cout << endl;
	cout << "Enter corresponding integer values for menu options" << endl << endl;

	while (option){//main menu
		cout << endl << "Main Menu:" << endl;
		cout << "1. " << "Add assignment category" << endl;
		cout << "2. " << "Add student" << endl;
		cout << "3. " << "Edit categories / assignments" << endl;//submenu
		cout << "4. " << "Edit students / scores" << endl;//submenu
		cout << "5. " << "View grades" << endl;//submenu
		cout << "6. " << "Save" << endl;
		cout << "7. " << "Exit" << endl << endl;
		cout << "Menu option number: ";
		cin >> option;
		//cout << endl;

		if (option == 1){
			string name;
			float weight;
			int numCatsBefore = section1->numCats;
			cout << "Category name: ";
			cin >> name;
			cout << "Category weight (as a percentage): ";
			cin >> weight;
			section1->addCategory(name, weight);
			if (section1->numCats>numCatsBefore){
				cout << endl << "Category " << "\"" << name << "\" added with weight: " << weight << "%" << endl;
			}
		}
		else if (option == 2){
			string name;
			cout << "Student name: ";
			cin >> name;
			cout << endl;
			section1->addStudent(name);
			cout << "Student " << "\"" << name << "\" added to section \"" << section1->name << ".\"" << endl;
		}
		else if (option == 3){
			if (section1->numCats == 0){
				cout << "There are currently no categories of assignments in this section." << endl;
				break;
			}
			int catNum = 1;
			while (catNum){//category list menu
				section1->printCategories();
				cout << section1->numCats + 1 << ". " << "Previous menu" << endl << endl;
					cout << "Edit category number: ";
					cin >> catNum;
					cout << endl;
					if (catNum == section1->numCats + 1){
						break;
					}
					else if (catNum<1 || catNum>section1->numCats + 1){
						cout << "Invalid choice. Please try again." << endl << endl;
						continue;
					}
					else{
						section1->editCategory(catNum - 1);
					}
			}
		}
		else if (option == 4){//edit student info /scores
			int studNum = 1;
			while (studNum){//category list menu
				cout << endl;
				section1->printStudents();
				cout << section1->numStuds + 1 << ". " << "Previous menu" << endl;
				cout << endl << "Edit student number: ";
				cin >> studNum;
				cout << endl;

				if (section1->numStuds == 0){
					cout << "There are currently no students in this section." << endl;
					break;
				}
				else if (studNum<1 || studNum>section1->numStuds + 1){
					cout << "Invalid choice. Please try again." << endl << endl;
					continue;
				}
				else if (studNum == section1->numStuds + 1){
					break;
				}
				else{
					section1->editStudent(studNum - 1);
				}
			}
		}
		else if (option == 5){
			int studNum = 1;
			while (studNum){
				section1->printStudents();
				cout << section1->numStuds + 1 << ". " << "Section averages" << endl;
				cout << section1->numStuds + 2 << ". " << "Previous Menu" << endl;

				cout << "Student grade to view: ";
				cin >> studNum;
				cout << endl;

				if (section1->numStuds == 0){
					cout << "There are currently no students in this section." << endl;
					break;
				}
				else if (studNum<1 || studNum>section1->numStuds + 2){
					cout << "Invalid choice. Please try again." << endl << endl;
					continue;
				}
				else if (studNum == section1->numStuds + 1){
					int subOption = 1;
					while (subOption){
						cout << "1. " << "View overall averages (section and category averages)" << endl;
						cout << "2. " << "View assignment averages" << endl;
						cout << "3. " << "Previous Menu" << endl;
						cout << "Menu option number:";
						cin >> subOption;
						cout << endl;

						if (subOption == 3){
							break;
						}
						else if (subOption == 1){
							int catNum = 1;
							while (catNum){
								for (int i = 0; i < section1->numCats; i++){
									cout << i + 1 << ". " << section1->categories[i].name << " : " << section1->averageGrades(i) << " %" << endl;
								}
								cout << section1->numCats + 1 << ". " << "Overall : " << section1->averageGrades() << " %" << endl;
								cout << section1->numCats + 2 << ". " << "Previous Menu" << endl;
								cout << "Menu option number: ";
								cin >> catNum;
								if (catNum == section1->numCats + 2){
									break;
								}
								else{
									cout << "Invalid choice. Grades may be edited in this menu. Please try again." << endl;
									continue;
								}
							}
						}
						else if (subOption == 2){
							int catNum = 1;
							while (catNum){
								for (int i = 0; i < section1->numCats; i++){
									cout << i + 1 << ". " << section1->categories[i].name << endl;
								}
								cout << section1->numCats + 1 << ". " << "Previous Menu" << endl;
								cout << "Category containing assignment: ";
								cin >> catNum;
								if (catNum<1 || catNum>section1->numCats + 1){
									cout << "Invalid choice. Please try again." << endl;
									continue;
								}
								else if (catNum == section1->numCats + 1){
									break;
								}
								else{
									for (int i = 0; i < section1->categories[catNum - 1].numAssignments; i++){
										cout << i + 1 << ". " << section1->categories[catNum - 1].assignments[i].name << ": " << 
											section1->averageGrades(catNum-1,i) << " %" << endl;
									}
									cout << section1->categories[catNum - 1].numAssignments + 1 << ". " << "Previous Menu" << endl;
									int option = 1;
									while (option){
										cout << "Menu option number: ";
										cin >> option;
										if (option == section1->categories[catNum - 1].numAssignments + 1){
											break;
										}
										else{
											cout << "Invalid choice. Please try again. Assignment scores may not be viewed or edited individually through this menu." << endl;
											continue;
										}
									}
								}
							}
						}
						else{
							cout << "Invalid choice. Please try again." << endl;
							continue;
						}
					}
				}
				else if (studNum == section1->numStuds + 2){
					break;
				}
				else{
					int option = 1;
					while (option){
						float totalGrade = 0;
						cout << "1. " << "View individual assignment score" << endl;
						cout << "2. " << "View overall / category grades" << endl;
						cout << "3. " << "Previous menu" << endl;
						cout << "Menu option number: ";
						cin >> option;
						cout << endl;

						if (option == 1){
							int catNum=1;
							while (catNum){
								for (int i = 0; i < section1->numCats; i++){
									cout << i + 1 << ". " << section1->categories[i].name << endl;
								}
								cout << section1->numCats + 1 << ". " << "Previous Menu" << endl;
								cout << "Category containing assignment: ";
								cin >> catNum;
								if (catNum<1 || catNum>section1->numCats+1){
									cout << "Invalid choice. Please try again." << endl;
									continue;
								}
								else if(catNum==section1->numCats+1){
									break;
								}
								else{
									for (int i = 0; i < section1->categories[catNum - 1].numAssignments; i++){
										cout << i + 1 << ". " << section1->categories[catNum - 1].assignments[i].name << ": " << 
											section1->students[studNum - 1].categories[catNum - 1].assignments[i].getPoints() << 
											" / " << section1->categories[catNum - 1].assignments[i].getPoints() << " points" << endl;
									}
									cout << section1->categories[catNum - 1].numAssignments + 1 << ". " << "Previous Menu" << endl;
									int option=1;
									while (option){
										cout << "Menu option number: ";
										cin >> option;
										if (option == section1->categories[catNum - 1].numAssignments + 1){
											break;
										}
										else{
											cout << "Invalid choice. Please try again. Assignment scores may not be viewed or edited individually through this menu." << endl;
											continue;
										}
									}
								}
							}
						}
						else if (option == 2){
							cout << section1->students[studNum - 1].name << endl;
							cout << "Category grades:" << endl;
							for (int i = 0; i < section1->numCats; i++){
								cout << i + 1 << ". " << section1->categories[i].name << ": " << section1->students[studNum - 1].getPoints(i)
									<< " / " << section1->categories[i].getPoints() << " (" << section1->students[studNum - 1].getPoints(i) / section1->categories[i].getPoints() * 100 << " %)" << endl;
								totalGrade += section1->students[studNum - 1].getPoints(i) / section1->categories[i].getPoints() * section1->categories[i].weight;
							}
							cout << "Overall: " << totalGrade <<" %" << endl;
							continue;
						}
						else if (option == 3){
							break;
						}
						else{
							cout << "Invalid choice. Please try again." << endl;
							continue;
						}
					}
				}
			}
		}
		else if (option == 6){
			for (int i = 0; i < section1->numCats; i++){
				section1->save(i);
			}
			section1->save();
			continue;
		}
		else if (option == 7){
			break;
		}
		else{
			cout << "Invalid choice. Try again." << endl;
			continue;
		}
	}

	cout << "Thank you for using personal gradebook." << endl;
}