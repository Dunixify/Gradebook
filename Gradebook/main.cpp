#include "section.h"

int numSects = 0;
section* sections = new section[];

void addSection(section &cs){
	if (numSects == 0){
		//		delete[] assignments;
		sections = new section[1];
		sections[0] = cs;
	}
	else{
		section* newSects = new section[numSects + 1];
		for (int i = 0; i < numSects; i++){
			newSects[i] = sections[i].name;
		}
		newSects[numSects] = cs;
		delete[] sections;
		sections = newSects;
	}
	numSects++;
}
void removeSection(int index){
	section* temp = new section[numSects - 1];
	if (index == 0){
		for (int i = 1; i < numSects; i++){
			temp[i - 1] = sections[i];
		}
	}
	else if (index == numSects - 1){
		for (int i = 0; i < numSects - 1; i++){
			temp[i] = sections[i];
		}
	}
	else{
		for (int i = 0; i < index; i++){
			temp[i] = sections[i];
		}
		for (int i = index + 1; i < numSects; i++){
			temp[i - 1] = sections[i];
		}
	}
	delete[] sections;
	sections = temp;
	numSects--;
}
void saveAll(){
	ofstream sectionList;
	sectionList.open(".\\Saves\\sectionList.txt");
	for (int i = 0; i < numSects; i++){
		for (int j = 0; j < sections[i].numCats; j++){
			sections[i].save(j);
		}
		sections[i].save();
		sectionList << sections[i].name << endl;
	}
	sectionList.close();
	cout << "Saved files contained in program directory.";
}
void loadFiles(){
	ifstream sectionList;
	sectionList.open(".\\Saves\\sectionList.txt");
	while (sectionList.is_open()){
		string tempName;
		getline(sectionList, tempName);
		addSection(section(tempName));
	}
	
}
int main(){
	int currentSectIndex = 0;
	section* currSect;
	cout << "/tPersonal Gradebook" << endl << endl;
	cout << "Enter corresponding integer values to navigate menus" << endl << endl;
//	loadFiles();

	/*if (numSects==0){

	}
	else{*/
		int option = 1;
		while (option){
			for (int i = 0; i < numSects; i++){
				cout << i + 1 << ". " << sections[i].name << endl;
			}
			cout << numSects + 1 << ". " << "New section" << endl;
			cout << numSects + 2 << ". " << "Save all" << endl;
			cout << numSects + 3 << ". " << "Exit" << endl;
			cout << "Menu option number: ";
			cin >> option;
			if (option<1 || option>numSects + 3){
				cout << "Invalid choice. Please try again." << endl;
				continue;
			}
			else if (option == numSects + 1){
				string sectionName;
				cout << "Please enter section name: ";
				cin.clear();
				cin.sync();
				getline(cin, sectionName);
				currSect = new section(sectionName);
				addSection(*currSect);
			}
			else if (option == numSects + 2){
				saveAll();
			}
			else if (option == numSects + 3){
				break;
			}
			else{
				currentSectIndex = option - 1;
				currSect = &sections[option - 1];
				//single section code
				int option = 1;
				while (option){//main menu
					cout << endl << "Main Menu:" << endl;
					cout << "1. " << "Add assignment category" << endl;
					cout << "2. " << "Add student" << endl;
					cout << "3. " << "Edit categories / assignments" << endl;//submenu
					cout << "4. " << "Edit students / scores" << endl;//submenu
					cout << "5. " << "View grades" << endl;//submenu
					//cout << "6. " << "Save section" << endl;
					cout << "6. Delete Section" << endl;
					cout << "7. " << "Previous Menu" << endl << endl;
					cout << "Menu option number: ";
					cin >> option;
					//cout << endl;

					if (option == 1){
						string name;
						float weight;
						int numCatsBefore = currSect->numCats;
						cout << "Category name: ";
						cin.clear();
						cin.sync();
						getline(cin, name);
						cout << "Category weight (as a percentage): ";
						cin >> weight;
						currSect->addCategory(name, weight);
						if (currSect->numCats>numCatsBefore){
							cout << endl << "Category " << "\"" << name << "\" added with weight: " << weight << "%" << endl;
						}
					}
					else if (option == 2){
						string name;
						cout << "Student name: ";
						cin.clear();
						cin.sync();
						getline(cin, name);
						cout << endl;
						currSect->addStudent(name);
						cout << "Student " << "\"" << name << "\" added to section \"" << currSect->name << ".\"" << endl;
					}
					else if (option == 3){
						if (currSect->numCats == 0){
							cout << "There are currently no categories of assignments in this section." << endl;
							break;
						}
						int catNum = 1;
						while (catNum){//category list menu
							currSect->printCategories();
							cout << currSect->numCats + 1 << ". " << "Previous menu" << endl << endl;
							cout << "Edit category number: ";
							cin >> catNum;
							cout << endl;
							if (catNum == currSect->numCats + 1){
								break;
							}
							else if (catNum<1 || catNum>currSect->numCats + 1){
								cout << "Invalid choice. Please try again." << endl << endl;
								continue;
							}
							else{
								currSect->editCategory(catNum - 1);
							}
						}
					}
					else if (option == 4){//edit student info /scores
						int studNum = 1;
						while (studNum){//category list menu
							cout << endl;
							currSect->printStudents();
							cout << currSect->numStuds + 1 << ". " << "Previous menu" << endl;
							cout << endl << "Edit student number: ";
							cin >> studNum;
							cout << endl;

							if (currSect->numStuds == 0){
								cout << "There are currently no students in this section." << endl;
								break;
							}
							else if (studNum<1 || studNum>currSect->numStuds + 1){
								cout << "Invalid choice. Please try again." << endl << endl;
								continue;
							}
							else if (studNum == currSect->numStuds + 1){
								break;
							}
							else{
								currSect->editStudent(studNum - 1);
							}
						}
					}
					else if (option == 5){
						int studNum = 1;
						while (studNum){
							currSect->printStudents();
							cout << currSect->numStuds + 1 << ". " << "Section averages" << endl;
							cout << currSect->numStuds + 2 << ". " << "Previous Menu" << endl;

							cout << "Student grade to view: ";
							cin >> studNum;
							cout << endl;

							if (currSect->numStuds == 0){
								cout << "There are currently no students in this section." << endl;
								break;
							}
							else if (studNum<1 || studNum>currSect->numStuds + 2){
								cout << "Invalid choice. Please try again." << endl << endl;
								continue;
							}
							else if (studNum == currSect->numStuds + 1){
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
											for (int i = 0; i < currSect->numCats; i++){
												cout << i + 1 << ". " << currSect->categories[i].name << " : " << currSect->averageGrades(i) << " %" << endl;
											}
											cout << currSect->numCats + 1 << ". " << "Overall : " << currSect->averageGrades() << " %" << endl;
											cout << currSect->numCats + 2 << ". " << "Previous Menu" << endl;
											cout << "Menu option number: ";
											cin >> catNum;
											if (catNum == currSect->numCats + 2){
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
											for (int i = 0; i < currSect->numCats; i++){
												cout << i + 1 << ". " << currSect->categories[i].name << endl;
											}
											cout << currSect->numCats + 1 << ". " << "Previous Menu" << endl;
											cout << "Category containing assignment: ";
											cin >> catNum;
											if (catNum<1 || catNum>currSect->numCats + 1){
												cout << "Invalid choice. Please try again." << endl;
												continue;
											}
											else if (catNum == currSect->numCats + 1){
												break;
											}
											else{
												for (int i = 0; i < currSect->categories[catNum - 1].numAssignments; i++){
													cout << i + 1 << ". " << currSect->categories[catNum - 1].assignments[i].name << ": " <<
														currSect->averageGrades(catNum - 1, i) << " %" << endl;
												}
												cout << currSect->categories[catNum - 1].numAssignments + 1 << ". " << "Previous Menu" << endl;
												int option = 1;
												while (option){
													cout << "Menu option number: ";
													cin >> option;
													if (option == currSect->categories[catNum - 1].numAssignments + 1){
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
							else if (studNum == currSect->numStuds + 2){
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
										int catNum = 1;
										while (catNum){
											for (int i = 0; i < currSect->numCats; i++){
												cout << i + 1 << ". " << currSect->categories[i].name << endl;
											}
											cout << currSect->numCats + 1 << ". " << "Previous Menu" << endl;
											cout << "Category containing assignment: ";
											cin >> catNum;
											if (catNum<1 || catNum>currSect->numCats + 1){
												cout << "Invalid choice. Please try again." << endl;
												continue;
											}
											else if (catNum == currSect->numCats + 1){
												break;
											}
											else{
												for (int i = 0; i < currSect->categories[catNum - 1].numAssignments; i++){
													cout << i + 1 << ". " << currSect->categories[catNum - 1].assignments[i].name << ": " <<
														currSect->students[studNum - 1].categories[catNum - 1].assignments[i].getPoints() <<
														" / " << currSect->categories[catNum - 1].assignments[i].getPoints() << " points" << endl;
												}
												cout << currSect->categories[catNum - 1].numAssignments + 1 << ". " << "Previous Menu" << endl;
												int option = 1;
												while (option){
													cout << "Menu option number: ";
													cin >> option;
													if (option == currSect->categories[catNum - 1].numAssignments + 1){
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
										cout << currSect->students[studNum - 1].name << endl;
										cout << "Category grades:" << endl;
										for (int i = 0; i < currSect->numCats; i++){
											cout << i + 1 << ". " << currSect->categories[i].name << ": " << currSect->students[studNum - 1].getPoints(i)
												<< " / " << currSect->categories[i].getPoints() << " (" << currSect->students[studNum - 1].getPoints(i) / currSect->categories[i].getPoints() * 100 << " %)" << endl;
											totalGrade += currSect->students[studNum - 1].getPoints(i) / currSect->categories[i].getPoints() * currSect->categories[i].weight;
										}
										cout << "Overall: " << totalGrade << " %" << endl;
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
					/*else if (option == 6){
						for (int i = 0; i < currSect->numCats; i++){
							currSect->save(i);
						}
						currSect->save();
						cout << "Saved files contained in program directory.";
						continue;
					}*/
					else if (option == 6){
						removeSection(currentSectIndex);
						break;
					}
					else if (option == 7){
						break;
					}
					else{
						cout << "Invalid choice. Try again." << endl;
						continue;
					}
				}
			}
		}
//	}
	//end single section code
	cout << "Thank you for using personal gradebook." << endl;
}