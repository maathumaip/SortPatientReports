#include <iostream>
#include <cstring> // required for string manipulation
#include <iomanip> // required for tabular output

using namespace std; 

int main()
{
    // Provided arrays and constants
    const int NUM_PATIENTS = 10; // 10 patients will be included, this value cannot be modified
    const int MAX_NAME_LENGTH = 10; // no names longer than 10 characters, this value cannot be modified
    const int ID_LENGTH = 8;
    unsigned int age[NUM_PATIENTS] = {50, 22, 22, 89, 15, 16, 22, 32, 15, 66}; // 1D int array age of each patient
    char id[NUM_PATIENTS][ID_LENGTH + 1] = {"10854893", "10983922", "98333894", "57290888", "14899822", "79278282", "44293822", "62911023", "28399020", "33212322"}; // 1D int array identification #
    char firstName[NUM_PATIENTS][MAX_NAME_LENGTH] = {"allison", "michael", "michael", "johnny", "sabrina", "helen", "ignacio", "melissa", "hassan", "melody"}; // 2D char array: first names for patients
    char lastName[NUM_PATIENTS][MAX_NAME_LENGTH] = {"pratt","xiao", "barkley", "wu", "sappal", "mcdonald", "garza", "tran", "nahas", "baker"}; // 2D char array: last names for patients
    char sex[NUM_PATIENTS] = {'f','m','m','m','f','f','m','f','m','f'}; // 1D char array sex of the patient


    // PART 1: Select a primary sorting category from user input
  char categories[5][6] = {"Age", "ID", "Sex", "Last", "First"}; //2D array with possible categories to sort from and their respective values for each patient
  char catChosen[6]; //array for category chosen 
  cout << "Please enter the sorting category (Age, ID, First, Last, Sex): " << endl;
  cin >> catChosen;
  int x = 0;
  int y = 0;

  while(x==0){ // repeats while there has not been a valid input for category chosen

    for (int i = 0; i<5; i++){
      if (strcasecmp(catChosen,categories[i])==0){ // if the category inputed matches one of the options, then
        cout << "Case " << i+1 << ", sorting by " << categories[i] << "." << endl; // prints the case number and which category it is sorting by
        x++; // allows for while loop to be exited
        y++; // allows for incorrect message if statement to be skipped
        }
    }
    if (y==0){ // only occurs if the category inputed doesnt match one of the 5 categories in the list
      cout << "Unexpected input. Please input either Age, ID, First, Last, or Sex: " << endl; // gets new input for sorting category
      cin >> catChosen; //asigns that new input to catChosen
    }
  }

    // PART 3/4: Sorting patient records

//sorting by age
if (strcasecmp(catChosen,categories[0])==0){ // occurs if the age category is chosen
  for (int i = 0; i < NUM_PATIENTS -1; i++){ // these 2 for loops send the code to the corresponding patient's files. It allows for each patient's records to be compared so that at the end, they get sorted correctly.
    for (int j = 0; j < NUM_PATIENTS -1 -i; j++){
      if (age[j]>age[j+1]){ // if the  age is greater than the next age, then swap both of the patients' values so that they end up in the correct order
        swap(age[j], age[j+1]); //swapping age
        swap(id[j], id[j+1]); //swapping id
        swap(firstName[j], firstName[j+1]); //swapping first name
        swap(lastName[j], lastName[j+1]); //swapping last name
        swap(sex[j], sex[j+1]); // swapping sex
      }
       else if (age[j] == age[j+1]){ // if the ages are equal, then...
         if (strcasecmp(firstName[j],firstName[j+1])>0){ // if the  name is alphabetically later than the next name, then swap all their values so that they are sorted by first name.
         swap(age[j], age[j+1]);
         swap(id[j], id[j+1]);
         swap(firstName[j], firstName[j+1]);
         swap(lastName[j], lastName[j+1]);
         swap(sex[j], sex[j+1]);
         }
       }
    }
  }
  }
  //sorting by id number
if (strcasecmp(catChosen,categories[1])==0){ // occurs if the id category is chosen
  for (int i = 0; i < NUM_PATIENTS -1; i++){ // these 2 for loops send the code to the corresponding patient's files. It allows for each patient's records to be compared so that at the end, they get sorted correctly.
    for (int j = 0; j < NUM_PATIENTS-1-i; j++){
      if (strcmp(id[j],id[j+1])>0){ //if the  ID number is greater than the next, then swap their values
        swap(age[j], age[j+1]);
        swap(id[j], id[j+1]);
        swap(firstName[j], firstName[j+1]);
        swap(lastName[j], lastName[j+1]);
        swap(sex[j], sex[j+1]);
      }
      
    }
 }
}
// sorting by first name
  if (strcasecmp(catChosen,categories[4])==0){ // occurs if the first name category is chosen
  for (int i = 0; i < NUM_PATIENTS -1; i++){ // these 2 for loops send the code to the corresponding patient's files. It allows for each patient's records to be compared so that at the end, they get sorted correctly.
    for (int j = 0; j < NUM_PATIENTS-1-i; j++){
      if (strcasecmp(firstName[j],firstName[j+1])>0){ // if the first name is alphatically later than the next, then swap their values
        swap(age[j], age[j+1]);
        swap(id[j], id[j+1]);
        swap(firstName[j], firstName[j+1]);
        swap(lastName[j], lastName[j+1]);
        swap(sex[j], sex[j+1]);
      }
    }
 }
}
//sorting by last name
  if (strcasecmp(catChosen,categories[3])==0){ // occurs if the last name category is chosen
  for (int i = 0; i < NUM_PATIENTS -1; i++){ // these 2 for loops send the code to the corresponding patient's files. It allows for each patient's records to be compared so that at the end, they get sorted correctly.
    for (int j = 0; j < NUM_PATIENTS-1-i; j++){
      if (strcasecmp(lastName[j],lastName[j+1])>0){ // if the last name is alphatically later than the next, then swap their values
        swap(age[j], age[j+1]);
        swap(id[j], id[j+1]);
        swap(firstName[j], firstName[j+1]);
        swap(lastName[j], lastName[j+1]);
        swap(sex[j], sex[j+1]);
      }
    }
 }
 }
//sorting by sex and first name if it's the same sex
  if (strcasecmp(catChosen,categories[2])==0){ // occurs if the sex category is chosen
  for (int i = 0; i < NUM_PATIENTS -1; i++){// these 2 for loops send the code to the corresponding patient's files. It allows for each patient's records to be compared so that at the end, they get sorted correctly.
    for (int j = 0; j < NUM_PATIENTS-1-i; j++){
      if (sex[j]>sex[j+1]){ // if the sex of the first is alphabetically later than the second's, then swap these patients' values. Essentially pushes males to the end
        swap(age[j], age[j+1]);
        swap(id[j], id[j+1]);
        swap(firstName[j], firstName[j+1]);
        swap(lastName[j], lastName[j+1]);
        swap(sex[j], sex[j+1]);
      }
       else if (sex[j] == sex[j+1]){ // if the sexes are the same, then...
         if (strcasecmp(firstName[j],firstName[j+1])>0){ // if the first name is alphabetically later than the next, then swap all their values
           swap(age[j], age[j+1]);
           swap(id[j], id[j+1]);
           swap(firstName[j], firstName[j+1]);
           swap(lastName[j], lastName[j+1]);
           swap(sex[j], sex[j+1]);
         }
       }
    }
 }
 }




    // PART 2: Outputting patient records to terminal in tabular form
 //prints the ages 
  cout << " " << endl; 
  cout << setw(11) << "Age:"; 
  for (int i = 0; i <10; i++){ // repeats for every age value
    cout << setw(11) << age[i]; // 11 was a width that worked for me (related to spacing). this line prints the age at spot i
  }
  //prints the ID numbers
  cout << " " << endl; // there's an enter between each line that separates each category
  cout << setw(11) << "ID:"; // prints id in new order
  for (int i = 0; i <10; i++){
    cout << setw(11) << id[i];
  }
  //prints the first names
  cout << " " << endl;
  cout << setw(11) << "First Name:"; //prints first names in new order
  for (int i = 0; i <10; i++){
    cout << setw(11) << firstName[i];
  }
//prints the last names
  cout << " " << endl;
  cout << setw(11) << "Last Name:"; //prints last names in new order
  for (int i = 0; i <10; i++){
    cout << setw(11) << lastName[i];
  }
// prints the sexes
  cout << " " << endl;
  cout << setw(11) << "Sex:"; //prints sex in new order
  for (int i = 0; i <10; i++){
    cout << setw(11) << sex[i];
  }
  cout << " " << endl;
  return 0; // needs to be a return value

  }
