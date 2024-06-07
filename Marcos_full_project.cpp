#include <stdio.h>
#include <time.h>
#include <conio.h>	 //use for delay(), getch() etc.
#include <ctype.h>	 //use for toupper(), tolower() etc.
#include <string.h>	 //use for strcmp(),strcpy(),strlen() etc.
#include <stdlib.h>	 //use for malloc() etc.
#include <windows.h> //use for gotoxy() etc.
#include<stdlib.h>
#include<conio.h>
// function declaration
void WelcomeScreen();
void Title();
void registe();
void login();
void MainMenu();
void soilanalysis();
void cropRotation();
void detectDiseases();
void mainmain();
void FertilizerAndWaterManagement();
void cornFertilizerSchedule();
void riceFertilizerSchedule();
void juteFertilizerSchedule();
void runWeatherForecastProgram();
void displayMainMenuWeather();
void displayCurrentWeather();
void display7DayForecast();

// Structure to hold soil analysis data
struct SoilAnalysis
{
	char crop[50];
	float minPH;
	float maxPH;
	float minMoisture;
	float maxMoisture;
};

struct login
{
	char username[50];
	char password[50];
};
struct login l;

// Structure to hold fertilizer management data
struct FertilizerManagement
{
	char crop[50];
	char fertilizerType[50];
	float minFertilizerRequirement;
	float maxFertilizerRequirement;
};

// Structure to hold water management data
struct WaterManagement
{
	char crop[50];
	float minWaterRequirement;
	float maxWaterRequirement;
};

FILE *user_file;
FILE *pass_file;

int main()
{
	WelcomeScreen();
	Title();
	int cho;
	printf("\n\n\n\n\n\t\t\t\t1. Register\n\n\t\t\t\t2. Login\n");

a:
	printf("Enter your choice : ");
	scanf("%d", &cho);
	switch (cho)
	{
	case 1:
		system("cls");
		registe();
		break;
	case 2:
		system("cls");
		login();
		break;
	default:
		printf("Invalid Choice.......\n\n");
		goto a;
		break;
	}
}

/* ****************** Welcome Screen ****************** */
void WelcomeScreen()
{
	printf("\n\n\n\n\n\n\n\t\t\t\t#########################################");
	printf("\n\t\t\t\t#\t\t Welcome to\t\t#");
	printf("\n\t\t\t\t#     Agricultural Crop Adviser    \t#");
	printf("\n\t\t\t\t#########################################");
	printf("\n\n\n\n\n Press any key to  continue......\n");
	getch();	   // hold the screen
	system("cls"); // use to clear screen
}

/* ****************** Title Screen ******************* */
void Title()
{
	printf("\n\n\t\t-------------------------------------------------------------------------------------");
	printf("\n\t\t\t\t        Agricultural Crop Adviser");
	printf("\n\n\t\t-------------------------------------------------------------------------------------");
}

/* ****************** Registration Screen ****************** */
void registe()
{
	system("cls");

	user_file = fopen("username.txt", "a"); // Open file for usernames
	pass_file = fopen("password.txt", "a"); // Open file for passwords

	Title(); // calling title function

	// Generate a random 4-digit ID

	printf("\n\n\t\t\t\tEnter Username : ");
	scanf("%s", l.username);
	printf("\n\t\t\t\tEnter password : ");
	scanf("%s", l.password);

	// Write username to username file
	fputs(l.username, user_file);
	fputs("\n", user_file); // Move to the next line

	// Write password to password file
	fputs(l.password, pass_file);
	fputs("\n", pass_file); // Move to the next line

	fclose(user_file);
	fclose(pass_file);

	printf("\n\n\t\t\t-------------- Registraion Done --------------");
	printf("\n\n\t\t\tNow login with Username and Password\n");
	printf("\n\nPress any key to continue.........");
	getch();
	system("cls");

	login(); // calling login function
}

/* ****************** Login Screen ****************** */
void login()
{
	system("cls");
	char username[50], password[50];

	// Open username and password files for reading
	FILE *user_file = fopen("username.txt", "r");
	FILE *pass_file = fopen("password.txt", "r");

	Title(); // calling title function

	printf("\n\n\t\t\t!!!!!!!!!!!!!! Login Screen !!!!!!!!!!!!!!");

	printf("\n\n\n\n\n\t\t\tUsername : ");
	scanf("%s", username);
	printf("\n\t\t\tPassword : ");
	scanf("%s", password);

	int loggedIn = 0; // Flag to track login status

	// Read each line from the username and password files and compare with input
	while (fscanf(user_file, "%s", l.username) == 1 && fscanf(pass_file, "%s", l.password) != EOF)
	{
		printf("Comparing: %s - %s\n", l.username, l.password); // traceing output

		if (strcmp(username, l.username) == 0 && strcmp(password, l.password) == 0)
		{
			loggedIn = 1; // Set login status to true
			break;
		}
	}

	fclose(user_file);
	fclose(pass_file);

	if (loggedIn == 1)
	{
		printf("Login Successful...\n");
		printf("\nPress any key to continue......");
		getch();
		system("cls");
		MainMenu(); // calling MainMenu function
	}
	else
	{
		printf("Please Enter correct username and password\n");
		printf("\nPress any key to continue.....");
		getch();
		system("cls");
		login(); // Retry login if credentials don't match
	}
}

/* ****************** Main Menue ******************* */
void MainMenu()
{
	system("cls");
	Title(); // Again calling Title function
	int choose;
	printf("\n\n\t\t\t!!!!!!!!!!!!!! Main Menue !!!!!!!!!!!!!!");

	printf("\n\n\n\n\n\t\t\t\t1. Soil and Climate Analysis\n");
	printf("\n\t\t\t\t2. Crop Rotation Suggestions\n");
	printf("\n\t\t\t\t3. Diseases Detection\n");
	printf("\n\t\t\t\t4. Tips for Choosing Rice\n");
	printf("\n\t\t\t\t5. Market Trends Information\n");
	printf("\n\t\t\t\t6. Fertilizer and Water Management\n");
	printf("\n\t\t\t\t7. Exit\n");
	printf("Your program stopped");
	

M:
	printf("\nEnter your choice : ");
	getch();
	scanf("%d", &choose);
	switch (choose)
	{
	case 1:
		soilanalysis();
		break;
	case 2:
		cropRotation();
		break;
	case 3:
		detectDiseases();
		break;
	case 4:
		mainmain();
		break;
	case 5:
		// Add functionality for Requirement No.6
		printf("\n\t\t\t\tWorking on this !!!");
		break;
	case 6:
		FertilizerAndWaterManagement();
		break;
	case 7:
		printf("\n\n\t\t\tExiting the program......\n");
		return;
		break;
	default:
		printf("\n\n\n\n\n\t\t\tInvalid Choice !!!");
		goto M;
	}
}

/* ****************** Soil analysis ******************* */
void soilanalysis()
{
	system("cls");
	Title(); // Again calling Title function
	// Initialize crop data directly
	struct SoilAnalysis crops[] = {
		{"Rice", 5.0, 6.5, 30, 70},
		{"Corn", 6.0, 7.5, 40, 80},
		{"Jute", 5.5, 7.0, 50, 90}};
	int size = sizeof(crops) / sizeof(crops[0]);

	float pH, moisture;
	printf("\nEnter pH of the soil: ");
	scanf("%f", &pH);
	printf("Enter moisture content of the soil (percentage): ");
	scanf("%f", &moisture);

	printf("\nCrops suitable for your land based on soil analysis:\n");
	printf("---------------------------------------------------------------------------------------------------------\n");
	printf("Crop\t\tMinimum pH\tMaximum pH\tMinimum Moisture\tMaximum Moisture\n");
	printf("---------------------------------------------------------------------------------------------------------\n\n");
	int found = 0;
	for (int i = 0; i < size; i++)	{
		if (pH >= crops[i].minPH && pH <= crops[i].maxPH &&
			moisture >= crops[i].minMoisture && moisture <= crops[i].maxMoisture)
		{
			printf("%s\t\t%.1f\t\t%.1f\t\t%.0f%%\t\t\t%.0f%%\n",
				   crops[i].crop, crops[i].minPH, crops[i].maxPH, crops[i].minMoisture, crops[i].maxMoisture);
			found = 1;
		}
	}
	if (!found)
	{
		printf("No suitable crops found for the specified pH and moisture levels.\n");
	}

	printf("\n\n\nReturning to main menue........");
	getch();
	MainMenu();
}

/* ****** Crop Rotation Suggestions ******* */
void cropRotation()
{
	system("cls");
	printf("\n\n\t\t\t!!!!!!!!!!!!!! Crop Rotation Suggestions !!!!!!!!!!!!!!\n\n");
	printf("\t\t\tChoose the planting season:\n");
	printf("\t\t\t1. June to November\n");
	printf("\t\t\t2. December to May\n");
	printf("\t\t\t3. April to August\n");

	int season;
	printf("\nEnter your choice : ");
	scanf("%d", &season);

	switch (season)
	{
	case 1:
		printf("\nSuggestion: Cultivate Rice\n");
		break;
	case 2:
		printf("\nSuggestion: Cultivate Corn\n");
		break;
	case 3:
		printf("\nSuggestion: Cultivate Jute\n");
		break;
	default:
		printf("\nInvalid Choice !!!\n");
		break;
	}

	printf("\nPress any key to return to the main menu...");
	getch();
	MainMenu(); // Return to the main menu
}


//detect disease                                                ----------Mathir part start------
            
void detectDiseases(){
// Function prototypes
void displayMainMenu();
void displayDiseaseMenu(int disease);
void displaySymptoms(int disease);
void displayPrevention(int disease);


    int choice;
    do {
        displayMainMenu();
        scanf("%d", &choice);

        if (choice >= 1 && choice <=7) {
            int subChoice;
            do {
                displayDiseaseMenu(choice);
                scanf("%d", &subChoice);

                if (subChoice == 1) {
                    displaySymptoms(choice); }
                
				else if (subChoice == 2) {
                    displayPrevention(choice); }
                
				else{
                   displayMainMenu(); }
                
                
                } while (subChoice!=3);
       
	    } else if(choice==8){
        	MainMenu();
		}
        
		
		}while(1);
   
}

    


void displayMainMenu() {
    printf("\n\n");
    printf("\t\t----------------------------Rice Diseases Menu-------------------------\n\n");
    printf("1. Blast Disease\n");
    printf("2. Bacterial Leaf Blight\n");
    printf("3. Brown Spot\n");
    printf("4. Sheath Blight\n");
    printf("5. Rice Tungro Disease\n");
    printf("6. Rice Yellow Mottle Virus (RYMV)\n");
    printf("7. Rice Streak Virus\n");
    printf("8.Exit Disease Menu\n");
    printf("\n Select a disease (1-7) or 8 to exit:");
}

void displayDiseaseMenu(int disease) {
    printf("\n\n");
    printf("\t\t----------------------------Options for disease %d------------------------\n", disease);
    printf("1. Symptoms\n");
    printf("2. Prevention\n");
    printf("3. Back\n");
    printf("Please select an option (1-3): ");
}

void displaySymptoms(int disease) {
    printf("\n\n");
    printf("\t\t----------------------------Symptoms of disease %d------------------------\n", disease);
    switch (disease) {
        case 1:
            printf("\nBlast Disease Symptoms:\nWhite lesions on leaves necks, and grains.\n");
            break;
        case 2:
            printf("\nBacterial Leaf Blight Symptoms:\nYellowing leaves, wilting, and white streaks on stems.\n");
            break;
        case 3:
            printf("\nBrown Spot Symptoms:\nSmall, brown spots on leaves and grains.\n");
            break;
        case 4:
            printf("\nSheath Blight Symptoms:\nGray lesions on leaf sheaths and necks.\n");
            break;
        case 5:
            printf("\nRice Tungro Disease Symptoms:\nStunted growth, yellowing, and necrosis of leaves.\n");
            break;
        case 6:
            printf("\nRice Yellow Mottle Virus (RYMV) Symptoms:\nYellowing of leaves, stunted growth, and reduced yields.\n");
            break;
        case 7:
            printf("\nRice Streak Virus Symptoms:\nStreaking and yellowing of leaves.\n");
            break;
        default:
            printf("Invalid disease selection.\n");
            break;
    }
}

void displayPrevention(int disease) {
    printf("\n\n");
    printf("\t\t----------------------Prevention methods for disease %d------------------\n", disease);
    switch (disease) {
        case 1:
            printf("\nBlast Disease Prevention:\nUse resistant rice varieties, balanced fertilization, and proper water management.\n");
            break;
        case 2:
            printf("\nBacterial Leaf Blight Prevention:\nUse disease-free seeds, copper-based fungicides, and crop rotation.\n");
            break;
        case 3:
            printf("\nBrown Spot Prevention:\nBalanced fertilization, crop rotation with non-rice crops, and proper weed control.\n");
            break;
        case 4:
            printf("\nSheath Blight Prevention:\nResistant rice varieties, balanced fertilization, and proper field drainage.\n");
            break;
        case 5:
            printf("\nRice Tungro Disease Prevention:\nUse resistant rice varieties, control vector insects, rotate crops, monitor and remove infected plants, and educate farmers.\n");
            break;
        case 6:
            printf("\nRice Yellow Mottle Virus (RYMV) Prevention:\nPlant resistant varieties, control insect vectors, practice crop rotation, remove infected plants, and educate farmers.\n");
            break;
        case 7:
            printf("\nRice Streak Virus Prevention:\nPlant resistant varieties, control vector insects, maintain clean fields, rotate crops, monitor symptoms and insect populations, ensure seed health, and implement Integrated Pest Management (IPM).\n");
            break;
        default:
            printf("Invalid disease selection.\n");
         break;

}
}                                                                              // ----- mathi part end -----


// Weather Forecast Program Functions

void runWeatherForecastProgram() {
    int choice;
    do {
        displayMainMenuWeather();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayCurrentWeather();
                break;
            case 2:
                display7DayForecast();
                break;
            case 3:
                return; // Go back to main menu
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (1);
}

void displayMainMenuWeather() {
    printf("\n\n");
    printf("\t\t----------------------------Weather Forecast Menu-------------------------\n\n");
    printf("1. Current Weather\n");
    printf("2. 7-Day Forecast\n");
    printf("3. Back to Main Menu\n");
    printf("\nPlease select an option (1-3): ");
}

void displayCurrentWeather() {
    printf("\n\nCurrent Weather:\nSunny, 25°C\n");
}

void display7DayForecast() {
    printf("\n\n7-Day Weather Forecast:\n");
    printf("Day 1: Sunny, 25°C\n");
    printf("Day 2: Partly Cloudy, 22°C\n");
    printf("Day 3: Rainy, 18°C\n");
    printf("Day 4: Cloudy, 20°C\n");
    printf("Day 5: Sunny, 26°C\n");
    printf("Day 6: Rainy, 19°C\n");
    printf("Day 7: Partly Cloudy, 23°C\n");
}


void mainmain(){
    system("cls");
	printf("\t\t\t\t\t*********************************************\n");
	printf("\t\t\t\t\t*                                           *\n");
	printf("\t\t\t\t\t*       ----------------------------        *\n");
	printf("\t\t\t\t\t*         Agricultural Crop Adviser         *\n");
	printf("\t\t\t\t\t*       ----------------------------        *\n");
	printf("\t\t\t\t\t*                                           *\n");
	printf("\t\t\t\t\t*                                           *\n");
	printf("\t\t\t\t\t*                                           *\n");
	printf("\t\t\t\t\t*********************************************\n\n\n");

	int month,option;
	char again;
	char pi[10];
	printf("\n");
	printf("\n");
	printf("\t\t\t\t------------------------------Choose your month-----------------------\n");
	printf("1.january\n2.February\n3.March\n4.April\n5.May\n6.June\n7.July\n8.Auguest\n9.September\n10.October\n11.November\n12.December");
	printf("\n");
	printf("\nChoose your Month:");
	scanf("%d",&option);



    switch(option) {
        case 1: {
            int a;
            printf("\t\t\t\t\t---------------------January month-----------------------\n");

	        printf("1.Aman\n");
            printf("2.BR29\n");
            printf("3.View Aman information\n");
            printf("4.View BR29 information\n");
            printf("Choose your Rice: ");
            scanf("%d", &a);

            switch(a) {
                case 1: {
                    char amanInput[100];
                    printf("Enter Aman information: ");
                    scanf(" %[^\n]", amanInput);
                    FILE *amaninfo;
                    amaninfo = fopen("aman.txt", "a");
                    if(amaninfo == NULL) {
                        printf("File does not exist");
                    } else {
                        fprintf(amaninfo, "%s\n", amanInput);
                        printf("\nSuccessfully added your information\n");
                        fclose(amaninfo);
                        printf("Press any key to Homepage....");
                    	getch();
                    	system("CLS");
                    	mainmain();
                    }

                    break;
                }

                case 2: {
                    char br29Input[100];
                    printf("Enter BR29 information: ");
                    scanf(" %[^\n]", br29Input);
                    FILE *br29info;
                    br29info = fopen("BR29.txt", "a");
                    if (br29info == NULL) {
                        printf("File does not exist");
                    } else {
                        fprintf(br29info, "%s\n", br29Input);
                        printf("\nSuccessfully added your information\n");
                        fclose(br29info);
                        printf("Press any key to Homepage....");
                    	getch();
                    	system("CLS");
                    	mainmain();
                    }
                    break;
                }

                case 3: {
                    FILE *amaninfo;
                    char oc;
                    amaninfo = fopen("aman.txt", "r");
                    if (amaninfo == NULL) {
                        printf("File does not exist");
                    } else {
                        printf("-------------*View Aman Information*-------------\n");
                        while ((oc = fgetc(amaninfo)) != EOF) {
                            printf("%c", oc);
                        }
                        fclose(amaninfo);
                        printf("Press any key to Homepage....");
                    	getch();
                    	system("CLS");
                    	mainmain();
                    }
                    break;
                }

                case 4: {
                    FILE *br29info;
                    char oc;
                    br29info = fopen("BR29.txt", "r");
                    if (br29info == NULL) {
                        printf("File does not exist");
                    } else {
                        printf("-------------*View BR29 Information*-------------\n");
                        while ((oc = fgetc(br29info)) != EOF) {
                            printf("%c", oc);
                        }
                        fclose(br29info);
                        printf("Press any key to Homepage....");
                    	getch();
                    	system("CLS");
                    	mainmain();
                    }
                    break;
                }
            }
            break;
        }

        case 2:
           {
				int b;
				printf("\t\t\t\t\t---------------------February month-----------------------\n");
                printf("BR1\n");
				printf("BR19\n");
				printf("3.View BR1 information\n");
                printf("4.View BR19 information\n");
				printf("Choose you Rice:");
				scanf("%d",&b);
				switch(b)
				{

					 case 1: {
                    char br1Input[100];
                    printf("Enter BR1 information: ");
                    scanf(" %[^\n]", br1Input);
                    FILE *br1info;
                    br1info = fopen("br1.txt", "a");
                    if(br1info == NULL) {
                        printf("File does not exist");
                    } else {
                        fprintf(br1info, "%s\n", br1Input);
                        printf("\nSuccessfully added your information\n");
                        fclose(br1info);
                        printf("Press any key to Homepage....");
                    	getch();
                    	system("CLS");
                    	mainmain();
                    }
                    break;
                }

                case 2: {
                    char br19Input[100];
                    printf("Enter BR19 information: ");
                    scanf(" %[^\n]", br19Input);
                    FILE *br19info;
                    br19info = fopen("BR19.txt", "a");
                    if (br19info == NULL) {
                        printf("File does not exist");
                        //add a system delay of 3 sec
                    } else {
                        fprintf(br19info, "%s\n", br19Input);
                        printf("\nSuccessfully added your information\n");
                        fclose(br19info);
                        printf("Press any key to Homepage....");
                    	getch();
                    	system("CLS");
                    	mainmain();
                    }
                    break;
                }

                case 3: {
                    FILE *br1info;
                    char oc;
                    br1info = fopen("br1.txt", "r");
                    if (br1info == NULL) {
                        printf("File does not exist");
                    } else {
                        printf("-------------*View BR1 Information*------------\n");
                        while ((oc = fgetc(br1info)) != EOF) {
                            printf("%c", oc);
                        }
                        fclose(br1info);
                        printf("Press any key to Homepage....");
                    	getch();
                    	system("CLS");
                    	mainmain();
                    }
                    break;
                }

                case 4: {
                    FILE *br19info;
                    char oc;
                    br19info = fopen("BR19.txt", "r");
                    if (br19info == NULL) {
                        printf("File does not exist");
                    } else {
                        printf("-------------*View BR19 Information*-------------\n");
                        while ((oc = fgetc(br19info)) != EOF) {
                            printf("%c", oc);
                        }
                        fclose(br19info);
                        printf("Press any key to Homepage....");
                    	getch();
                    	system("CLS");
                    	mainmain();
                    }
                    break;
                }
            }
            break;
        }

        case 3:
			{
				int c;
				printf("\t\t\t\t\t---------------------March month-----------------------\n");
				printf("Basmoti\n");
				printf("BR1\n");
				printf("3.View Basmoti information\n");
                printf("4.View BR1 information\n");
				printf("Choose you Rice:");
				scanf("%d",&c);
				switch(c)
				{
					 case 1: {
                    char basmotiInput[100];
                    printf("Enter Basmoti information: ");
                    scanf(" %[^\n]", basmotiInput);
                    FILE *basmotiinfo;
                    basmotiinfo = fopen("basmoti.txt", "a");
                    if(basmotiinfo == NULL) {
                        printf("File does not exist");
                    } else {
                        fprintf(basmotiinfo, "%s\n", basmotiInput);
                        printf("\nSuccessfully added your information\n");
                        fclose(basmotiinfo);
                        printf("Press any key to Homepage....");
                    	getch();
                    	system("CLS");
                    	mainmain();
                    }
                    break;
                }

                case 2: {
                    char br1Input[100];
                    printf("Enter BR1 information: ");
                    scanf(" %[^\n]", br1Input);
                    FILE *br1info;
                    br1info = fopen("BR1.txt", "a");
                    if (br1info == NULL) {
                        printf("File does not exist");
                    } else {
                        fprintf(br1info, "%s\n", br1Input);
                        printf("\nSuccessfully added your information\n");
                        fclose(br1info);
                        printf("Press any key to Homepage....");
                    	getch();
                    	system("CLS");
                    	mainmain();
                    }
                    break;
                }

                case 3: {
                    FILE *basmotiinfo;
                    char oc;
                    basmotiinfo = fopen("basmoti.txt", "r");
                    if (basmotiinfo == NULL) {
                        printf("File does not exist");
                    } else {
                        printf("-------------*View Basmoti Information*------------\n");
                        while ((oc = fgetc(basmotiinfo)) != EOF) {
                            printf("%c", oc);
                        }
                        fclose(basmotiinfo);
                        printf("Press any key to Homepage....");
                    	getch();
                    	system("CLS");
                    	mainmain();
                    }
                    break;
                }

                case 4: {
                    FILE *br1info;
                    char oc;
                    br1info = fopen("BR1.txt", "r");
                    if (br1info == NULL) {
                        printf("File does not exist");
                    } else {
                        printf("-------------*View BR1 Information*-------------\n");
                        while ((oc = fgetc(br1info)) != EOF) {
                            printf("%c", oc);
                        }
                        fclose(br1info);
                        printf("Press any key to Homepage....");
                    	getch();
                    	system("CLS");
                    	mainmain();
                    }
                    break;
                }
            }
            break;
        }


        case 4:
			{
				int d;
				printf("\t\t\t\t\t---------------------April month-----------------------\n");
				printf("Basmoti\n");
				printf("BR2\n");
				printf("3.View Basmoti information\n");
                printf("4.View BR2 information\n");
				printf("Choose you Rice:");
				scanf("%d",&d);
				switch(d)
				{
					 case 1: {
                    char basmotiInput[100];
                    printf("Enter Basmoti information: ");
                    scanf(" %[^\n]", basmotiInput);
                    FILE *basmotiinfo;
                    basmotiinfo = fopen("basmoti.txt", "a");
                    if(basmotiinfo == NULL) {
                        printf("File does not exist");
                    } else {
                        fprintf(basmotiinfo, "%s\n", basmotiInput);
                        printf("\nSuccessfully added your information\n");
                        fclose(basmotiinfo);
                        printf("Press any key to Homepage....");
                    	getch();
                    	system("CLS");
                    	mainmain();
                    }
                    break;
                }

                case 2: {
                    char br2Input[100];
                    printf("Enter BR2 information: ");
                    scanf(" %[^\n]", br2Input);
                    FILE *br2info;
                    br2info = fopen("BR2.txt", "a");
                    if (br2info == NULL) {
                        printf("File does not exist");
                    } else {
                        fprintf(br2info, "%s\n", br2Input);
                        printf("\nSuccessfully added your information\n");
                        fclose(br2info);
                        printf("Press any key to Homepage....");
                    	getch();
                    	system("CLS");
                    	mainmain();
                    }
                    break;
                }

                case 3: {
                    FILE *basmotiinfo;
                    char oc;
                    basmotiinfo = fopen("Basmoti.txt", "r");
                    if (basmotiinfo == NULL) {
                        printf("File does not exist");
                    } else {
                        printf("-------------*View Basmoti Information*-------------\n");
                        while ((oc = fgetc(basmotiinfo)) != EOF) {
                            printf("%c", oc);
                        }
                        fclose(basmotiinfo);
                        printf("Press any key to Homepage....");
                    	getch();
                    	system("CLS");
                    	mainmain();
                    }
                    break;
                }

                case 4: {
                    FILE *br2info;
                    char oc;
                    br2info = fopen("BR2.txt", "r");
                    if (br2info == NULL) {
                        printf("File does not exist");
                    } else {
                        printf("-------------*View BR2 Information*-------------\n");
                        while ((oc = fgetc(br2info)) != EOF) {
                            printf("%c", oc);
                        }
                        fclose(br2info);
                        printf("Press any key to Homepage....");
                    	getch();
                    	system("CLS");
                    	mainmain();
                    }
                    break;
                }
            }
            break;
        }


        case 5:
			{
				int e;
				printf("\t\t\t\t\t---------------------May month-----------------------\n");
				printf("BR18\n");
				printf("BR19\n");
				printf("3.View BR18 information\n");
                printf("4.View BR19 information\n");
				printf("Choose you Rice:");
				scanf("%d",&e);
				switch(e)
				{
					 case 1: {
                    char br18Input[100];
                    printf("Enter Br18 information: ");
                    scanf(" %[^\n]", br18Input);
                    FILE *br18info;
                    br18info = fopen("br18.txt", "a");
                    if(br18info == NULL) {
                        printf("File does not exist");
                    } else {
                        fprintf(br18info, "%s\n", br18Input);
                        printf("\nSuccessfully added your information\n");
                        fclose(br18info);
                        printf("Press any key to Homepage....");
                    	getch();
                    	system("CLS");
                    	mainmain();
                    }
                    break;
                }

                case 2: {
                    char br19Input[100];
                    printf("Enter BR19 information: ");
                    scanf(" %[^\n]", br19Input);
                    FILE *br19info;
                    br19info = fopen("BR19.txt", "a");
                    if (br19info == NULL) {
                        printf("File does not exist");
                    } else {
                        fprintf(br19info, "%s\n", br19Input);
                        printf("\nSuccessfully added your information\n");
                        fclose(br19info);
                        printf("Press any key to Homepage....");
                    	getch();
                    	system("CLS");
                    	mainmain();
                    }
                    break;
                }

                case 3: {
                    FILE *br18info;
                    char oc;
                    br18info = fopen("br18.txt", "r");
                    if (br18info == NULL) {
                        printf("File does not exist");
                    } else {
                        printf("-------------*View BR18 Information*-------------\n");
                        while ((oc = fgetc(br18info)) != EOF) {
                            printf("%c", oc);
                        }
                        fclose(br18info);
                        printf("Press any key to Homepage....");
                    	getch();
                    	system("CLS");
                    	mainmain();

                    }
                    break;
                }

                case 4: {
                    FILE *br19info;
                    char oc;
                    br19info = fopen("BR19.txt", "r");
                    if (br19info == NULL) {
                        printf("File does not exist");
                    } else {
                        printf("-------------*View BR19 Information*-------------\n");
                        while ((oc = fgetc(br19info)) != EOF) {
                            printf("%c", oc);
                        }
                        fclose(br19info);
                        printf("Press any key to Homepage....");
                    	getch();
                    	system("CLS");
                    	mainmain();
                    }
                    break;
                }
            }
            break;
        }


        case 6:
			{
				int f;
				printf("\t\t\t\t\t---------------------June month-----------------------\n");
				printf("BR18\n");
				printf("Akia Beruin White\n");
				printf("3.View BR18 information\n");
                printf("4.View Akia Beruin White information\n");
				printf("Choose you Rice:");
				scanf("%d",&f);
				switch(f)
				{
					 case 1: {
                    char br18Input[100];
                    printf("Enter BR18 information: ");
                    scanf(" %[^\n]", br18Input);
                    FILE *br18info;
                    br18info = fopen("br18.txt", "a");
                    if(br18info == NULL) {
                        printf("File does not exist");
                    } else {
                        fprintf(br18info, "%s\n", br18Input);
                        printf("\nSuccessfully added your information\n");
                        fclose(br18info);
                        printf("Press any key to Homepage....");
                    	getch();
                    	system("CLS");
                    	mainmain();
                    }
                    break;
                }

                case 2: {
                    char AkiaBeruinWhiteInput[100];
                    printf("Enter  Akia Beruin White information: ");
                    scanf(" %[^\n]", AkiaBeruinWhiteInput);
                    FILE *AkiaBeruinWhiteinfo;
                    AkiaBeruinWhiteinfo = fopen("AkiaBeruinWhite.txt", "a");
                    if (AkiaBeruinWhiteinfo == NULL) {
                        printf("File does not exist");
                    } else {
                        fprintf(AkiaBeruinWhiteinfo, "%s\n", AkiaBeruinWhiteInput);
                        printf("\nSuccessfully added your information\n");
                        fclose(AkiaBeruinWhiteinfo);
                        printf("Press any key to Homepage....");
                    	getch();
                    	system("CLS");
                    	mainmain();
                    }
                    break;
                }

                case 3: {
                    FILE *br18info;
                    char oc;
                    br18info = fopen("br18.txt", "r");
                    if (br18info == NULL) {
                        printf("File does not exist");
                    } else {
                        printf("-------------*View BR18 Information*------------\n");
                        while ((oc = fgetc(br18info)) != EOF) {
                            printf("%c", oc);
                        }
                        fclose(br18info);
                        printf("Press any key to Homepage....");
                    	getch();
                    	system("CLS");
                    	mainmain();
                    }
                    break;
                }

                case 4: {
                    FILE *AkiaBeruinWhiteinfo;
                    char oc;
                    AkiaBeruinWhiteinfo = fopen("AkiaBeruinWhite.txt", "r");
                    if (AkiaBeruinWhiteinfo == NULL) {
                        printf("File does not exist");
                    } else {
                        printf("-------------*View Akia Beruin White Information*-------------\n");
                        while ((oc = fgetc(AkiaBeruinWhiteinfo)) != EOF) {
                            printf("%c", oc);
                        }
                        fclose(AkiaBeruinWhiteinfo);
                        printf("Press any key to Homepage....");
                    	getch();
                    	system("CLS");
                    	mainmain();
                    }
                    break;
                }
            }
            break;
        }

        case 7:
			{
				int g;
				printf("\t\t\t\t\t---------------------July month-----------------------\n");
				printf("Akia Beruin White\n");
				printf("BR32\n");
				printf("3.View Akia Beriun White information\n");
                printf("4.View BR32 information\n");
				printf("Choose you rice:");
				scanf("%d",&g);
				switch(g)
				{
					case 1: {
                    char AkiaBeruinWhiteInput[100];
                    printf("Enter  Akia Beruin White information: ");
                    scanf(" %[^\n]", AkiaBeruinWhiteInput);
                    FILE *AkiaBeruinWhiteinfo;
                    AkiaBeruinWhiteinfo = fopen("AkiaBeruinWhite.txt", "a");
                    if (AkiaBeruinWhiteinfo == NULL) {
                        printf("File does not exist");
                    } else {
                        fprintf(AkiaBeruinWhiteinfo, "%s\n", AkiaBeruinWhiteInput);
                        printf("\nSuccessfully added your information\n");
                        fclose(AkiaBeruinWhiteinfo);
                        printf("Press any key to Homepage....");
                    	getch();
                    	system("CLS");
                    	mainmain();
                    }
                    break;
                }

                case 2: {
                    char br32Input[100];
                    printf("Enter BR32 information: ");
                    scanf(" %[^\n]", br32Input);
                    FILE *br32info;
                    br32info = fopen("br32.txt", "a");
                    if (br32info == NULL) {
                        printf("File does not exist");
                    } else {
                        fprintf(br32info, "%s\n", br32Input);
                        printf("\nSuccessfully added your information\n");
                        fclose(br32info);
                        printf("Press any key to Homepage....");
                    	getch();
                    	system("CLS");
                    	mainmain();
                    }
                    break;
                }

                case 3: {
                     FILE *AkiaBeruinWhiteinfo;
                    char oc;
                    AkiaBeruinWhiteinfo = fopen("AkiaBeruinWhite.txt", "r");
                    if (AkiaBeruinWhiteinfo == NULL) {
                        printf("File does not exist");
                    } else {
                        printf("--------------*View Akia Beruin White Information*--------------\n");
                        while ((oc = fgetc(AkiaBeruinWhiteinfo)) != EOF) {
                            printf("%c", oc);
                        }
                        fclose(AkiaBeruinWhiteinfo);
                        printf("Press any key to Homepage....");
                    	getch();
                    	system("CLS");
                    	mainmain();
                    }
                    break;
                }


                case 4: {
                    FILE *br32info;
                    char oc;
                    br32info = fopen("br32.txt", "r");
                    if (br32info == NULL) {
                        printf("File does not exist");
                    } else {
                        printf("-------------*View BR32 Information*------------\n");
                        while ((oc = fgetc(br32info)) != EOF) {
                            printf("%c", oc);
                        }
                        fclose(br32info);
                        printf("Press any key to Homepage....");
                    	getch();
                    	system("CLS");
                    	mainmain();
                    }
                    break;
                }
            }
            break;
        }
        case 8:
			{
				int h;
				printf("\t\t\t\t\t---------------------August month-----------------------\n");
				printf("Akia Beruin White\n");
				printf("BR32\n");
				printf("3.View Akia beruin white information\n");
                printf("4.View BR32 information\n");
				printf("Choose you Rice:");
				scanf("%d",&h);
				switch(h)
				{

            case 1: {
                    char AkiaBeruinWhiteInput[100];
                    printf("Enter  Akia Beruin White information: ");
                    scanf(" %[^\n]", AkiaBeruinWhiteInput);
                    FILE *AkiaBeruinWhiteinfo;
                    AkiaBeruinWhiteinfo = fopen("AkiaBeruinWhite.txt", "a");
                    if (AkiaBeruinWhiteinfo == NULL) {
                        printf("File does not exist");
                    } else {
                        fprintf(AkiaBeruinWhiteinfo, "%s\n", AkiaBeruinWhiteInput);
                        printf("\nSuccessfully added your information\n");
                        fclose(AkiaBeruinWhiteinfo);
                        printf("Press any key to Homepage....");
                    	getch();
                    	system("CLS");
                    	mainmain();
                    }
                    break;
                }

                case 2: {
                    char br32Input[100];
                    printf("Enter BR32 information: ");
                    scanf(" %[^\n]", br32Input);
                    FILE *br32info;
                    br32info = fopen("br32.txt", "a");
                    if (br32info == NULL) {
                        printf("File does not exist");
                    } else {
                        fprintf(br32info, "%s\n", br32Input);
                        printf("\nSuccessfully added your information\n");
                        fclose(br32info);
                        printf("Press any key to Homepage....");
                    	getch();
                    	system("CLS");
                    	mainmain();
                    }
                    break;
                }

                case 3: {
                     FILE *AkiaBeruinWhiteinfo;
                    char oc;
                    AkiaBeruinWhiteinfo = fopen("AkiaBeruinWhite.txt", "r");
                    if (AkiaBeruinWhiteinfo == NULL) {
                        printf("File does not exist");
                    } else {
                        printf("-------------*View Akia Beruin White Information*------------\n");
                        while ((oc = fgetc(AkiaBeruinWhiteinfo)) != EOF) {
                            printf("%c", oc);
                        }
                        fclose(AkiaBeruinWhiteinfo);
                        printf("Press any key to Homepage....");
                    	getch();
                    	system("CLS");
                    	mainmain();
                    }
                    break;
                }


                case 4: {
                    FILE *br32info;
                    char oc;
                    br32info = fopen("br32.txt", "r");
                    if (br32info == NULL) {
                        printf("File does not exist");
                    } else {
                        printf("-------------*View BR32 Information*------------\n");
                        while ((oc = fgetc(br32info)) != EOF) {
                            printf("%c", oc);
                        }
                        fclose(br32info);
                        printf("Press any key to Homepage....");
                    	getch();
                    	system("CLS");
                    	mainmain();
                    }
                    break;
                }

            break;
        }


        case 9:
			{
				int i;
				printf("\t\t\t\t\t---------------------September month-----------------------\n");
				printf("Bina\n");
				printf("Miniket\n");
				printf("3.View Bina information\n");
                printf("4.View Miniket information\n");
				printf("Choose you Rice:");
				scanf("%d",&i);
				switch(i)
				{
					case 1: {
                    char binaInput[100];
                    printf("Enter  Bina information: ");
                    scanf(" %[^\n]", binaInput);
                    FILE *binainfo;
                    binainfo = fopen("bina.txt", "a");
                    if (binainfo == NULL) {
                        printf("File does not exist");
                    } else {
                        fprintf(binainfo, "%s\n", binaInput);
                        printf("\nSuccessfully added your information\n");
                        fclose(binainfo);
                        printf("Press any key to Homepage....");
                    	getch();
                    	system("CLS");
                    	mainmain();
                    }
                    break;
                }

                case 2: {
                    char miniketInput[100];
                    printf("Enter Miniket information: ");
                    scanf(" %[^\n]", miniketInput);
                    FILE *miniketinfo;
                    miniketinfo = fopen("miniket.txt", "a");
                    if (miniketinfo == NULL) {
                        printf("File does not exist");
                    } else {
                        fprintf(miniketinfo, "%s\n", miniketInput);
                        printf("\nSuccessfully added your information\n");
                        fclose(miniketinfo);
                        printf("Press any key to Homepage....");
                    	getch();
                    	system("CLS");
                    	mainmain();
                    }
                    break;
                }

                case 3: {
                     FILE *binainfo;
                    char oc;
                    binainfo = fopen("bina.txt", "r");
                    if (binainfo == NULL) {
                        printf("File does not exist");
                    } else {
                        printf("-------------*View Bina Information*------------\n");
                        while ((oc = fgetc(binainfo)) != EOF) {
                            printf("%c", oc);
                        }
                        fclose(binainfo);
                        printf("Press any key to Homepage....");
                    	getch();
                    	system("CLS");
                    	mainmain();
                    }
                    break;
                }


                case 4: {
                    FILE *miniketinfo;
                    char oc;
                    miniketinfo = fopen("miniket.txt", "r");
                    if (miniketinfo == NULL) {
                        printf("File does not exist");
                    } else {
                        printf("-------------*View Miniket Information*-----------\n");
                        while ((oc = fgetc(miniketinfo)) != EOF) {
                            printf("%c", oc);
                        }
                        fclose(miniketinfo);
                        printf("Press any key to Homepage....");
                    	getch();
                    	system("CLS");
                    	mainmain();
                    }
                    break;
                }
            }
            break;
        }

        case 10:
			{
				int j;
				printf("\t\t\t\t\t---------------------October month-----------------------\n");
				printf("Bina\n");
				printf("Miniket\n");
				printf("3.View Bina information\n");
                printf("4.View Miniket information\n");
				printf("Choose you Rice:");
				scanf("%d",&j);
				switch(j)
				{
					case 1: {
                    char binaInput[100];
                    printf("Enter  Bina information: ");
                    scanf(" %[^\n]", binaInput);
                    FILE *binainfo;
                    binainfo = fopen("bina.txt", "a");
                    if (binainfo == NULL) {
                        printf("File does not exist");
                    } else {
                        fprintf(binainfo, "%s\n", binaInput);
                        printf("\nSuccessfully added your information\n");
                        fclose(binainfo);
                        printf("Press any key to Homepage....");
                    	getch();
                    	system("CLS");
                    	mainmain();
                    }
                    break;
                }

                case 2: {
                    char miniketInput[100];
                    printf("Enter Miniket information: ");
                    scanf(" %[^\n]", miniketInput);
                    FILE *miniketinfo;
                    miniketinfo = fopen("miniket.txt", "a");
                    if (miniketinfo == NULL) {
                        printf("File does not exist");
                    } else {
                        fprintf(miniketinfo, "%s\n", miniketInput);
                        printf("\nSuccessfully added your information\n");
                        fclose(miniketinfo);
                        printf("Press any key to Homepage....");
                    	getch();
                    	system("CLS");
                    	mainmain();
                    }
                    break;
                }

                case 3: {
                     FILE *binainfo;
                    char oc;
                    binainfo = fopen("bina.txt", "r");
                    if (binainfo == NULL) {
                        printf("File does not exist");
                    } else {
                        printf("-------------*View Bina Information*------------\n");
                        while ((oc = fgetc(binainfo)) != EOF) {
                            printf("%c", oc);
                        }
                        fclose(binainfo);
                        printf("Press any key to Homepage....");
                    	getch();
                    	system("CLS");
                    	mainmain();
                    }
                    break;
                }


                case 4: {
                    FILE *miniketinfo;
                    char oc;
                    miniketinfo = fopen("miniket.txt", "r");
                    if (miniketinfo == NULL) {
                        printf("File does not exist");
                    } else {
                        printf("-------------*View Miniket Information*-----------\n");
                        while ((oc = fgetc(miniketinfo)) != EOF) {
                            printf("%c", oc);
                        }
                        fclose(miniketinfo);
                        printf("Press any key to Homepage....");
                    	getch();
                    	system("CLS");
                    	mainmain();
                    }
                    break;
                }
            }
            break;
        }


			case 11:
			{
				int k;
				printf("\t\t\t\t\t---------------------November month-----------------------\n");
				printf("BR18\n");
				printf("BR2\n");
				printf("3.View BR18 information\n");
                printf("4.View BR2 information\n");
				printf("Choose you rice:");
				scanf("%d",&k);
				switch(k)
				{
					case 1: {
                    char br18Input[100];
                    printf("Enter  BR18 information: ");
                    scanf(" %[^\n]", br18Input);
                    FILE *br18info;
                    br18info = fopen("br18.txt", "a");
                    if (br18info == NULL) {
                        printf("File does not exist");
                    } else {
                        fprintf(br18info, "%s\n", br18Input);
                        printf("\nSuccessfully added your information\n");
                        fclose(br18info);
                        printf("Press any key to Homepage....");
                    	getch();
                    	system("CLS");
                    	mainmain();
                    }
                    break;
                }

                case 2: {
                    char br2Input[100];
                    printf("Enter BR2 information: ");
                    scanf(" %[^\n]", br2Input);
                    FILE *br2info;
                    br2info = fopen("BR2.txt", "a");
                    if (br2info == NULL) {
                        printf("File does not exist");
                    } else {
                        fprintf(br2info, "%s\n", br2Input);
                        printf("\nSuccessfully added your information\n");
                        fclose(br2info);
                        printf("Press any key to Homepage....");
                    	getch();
                    	system("CLS");
                    	mainmain();
                    }
                    break;
                }

                case 3: {
                     FILE *br18info;
                    char oc;
                    br18info = fopen("br18.txt", "r");
                    if (br18info == NULL) {
                        printf("File does not exist");
                    } else {
                        printf("-------------*View BR18 Information*-----------\n");
                        while ((oc = fgetc(br18info)) != EOF) {
                            printf("%c", oc);
                        }
                        fclose(br18info);
                        printf("Press any key to Homepage....");
                    	getch();
                    	system("CLS");
                    	mainmain();
                    }
                    break;
                }


                case 4: {
                    FILE *br2info;
                    char oc;
                    br2info = fopen("BR2.txt", "r");
                    if (br2info == NULL) {
                        printf("File does not exist");
                    } else {
                        printf("-------------*View BR2 Information*------------\n");
                        while ((oc = fgetc(br2info)) != EOF) {
                            printf("%c", oc);
                        }
                        fclose(br2info);
                        printf("Press any key to Homepage....");
                    	getch();
                    	system("CLS");
                    	mainmain();
                    }
                    break;
                }
            }
            break;
        }


			case 12:
			{
				int l;
				printf("\t\t\t\t\t---------------------December month-----------------------\n");
				printf("Aman\n");
				printf("BR29\n");
				printf("3.View Aman information\n");
                printf("4.View BR29 information\n");
				printf("Choose you Rice:");
				scanf("%d",&l);
				switch(l)
				{
                case 1:
                    {
                    char amanInput[100];
                    printf("Enter Aman information: ");
                    scanf(" %[^\n]", amanInput);
                    FILE *amaninfo;
                    amaninfo = fopen("aman.txt", "a");
                    if(amaninfo == NULL) {
                        printf("File does not exist");
                    } else {
                        fprintf(amaninfo, "%s\n", amanInput);
                        printf("\nSuccessfully added your information\n");
                        fclose(amaninfo);
                        printf("Press any key to Homepage....");
                    	getch();
                    	system("CLS");
                    	mainmain();
                    }
                    break;
                }

        case 2:
            {
                    char br29Input[100];
                    printf("Enter BR29 information: ");
                    scanf(" %[^\n]", br29Input);
                    FILE *br29info;
                    br29info = fopen("BR29.txt", "a");
                    if (br29info == NULL) {
                        printf("File does not exist");
                    } else {
                        fprintf(br29info, "%s\n", br29Input);
                        printf("\nSuccessfully added your information\n");
                        fclose(br29info);
                        printf("Press any key to Homepage....");
                    	getch();
                    	system("CLS");
                    	mainmain();
                    }
                    break;
                }

                case 3: {
                    FILE *amaninfo;
                    char oc;
                    amaninfo = fopen("aman.txt", "r");
                    if (amaninfo == NULL) {
                        printf("File does not exist");
                    } else {
                        printf("-------------*View Aman Information*------------\n");
                        while ((oc = fgetc(amaninfo)) != EOF) {
                            printf("%c", oc);
                        }
                        fclose(amaninfo);
                        printf("Press any key to Homepage....");
                    	getch();
                    	system("CLS");
                    	mainmain();
                    }
                    break;
                }

                case 4: {
                    FILE *br29info;
                    char oc;
                    br29info = fopen("BR29.txt", "r");
                    if (br29info == NULL) {
                        printf("File does not exist");
                    } else {
                        printf("-------------*View BR29 Information*------------\n");
                        while ((oc = fgetc(br29info)) != EOF) {
                            printf("%c", oc);
                        }
                        fclose(br29info);
                        printf("Press any key to Homepage....");
                    	getch();
                    	system("CLS");
                    	mainmain();
                    }
                    break;
                  }

               break;
              }
            }
          }
        }

mainmain();

	getch();
}

// Function to manage fertilizer and water for different crops
void FertilizerAndWaterManagement()
{
	system("cls");
	Title();
	printf("\n\n\t\t\t\tFertilizer and Water Management\n");

	// Get user input for crop
	char crop[50];
	printf("\nEnter the crop for which you want recommendations (Rice, Corn, Jute): ");
	scanf("%s", crop);

	// Check the crop and provide fertilizer recommendations accordingly
	if (strcmp(crop, "Rice") == 0)
	{
		// Call the function to calculate and print the rice fertilizer schedule
		riceFertilizerSchedule();
	}
	else if (strcmp(crop, "Corn") == 0)
	{
		// Call the function to calculate and print the corn fertilizer schedule
		cornFertilizerSchedule();
	}
	else if (strcmp(crop, "Jute") == 0)
	{
		// Call the fun. to calc. and print jute fertilization schedule
		juteFertilizerSchedule();
	}
	else
	{
		printf("Fertilizer and water management recommendations not available for the chosen crop.\n");
	}
	printf("\nPress any key to return to the main menu...");
	getch();
	MainMenu(); // Return to the main menu
}
// Function to calculate and print the fertilizer schedule for corn
void cornFertilizerSchedule()
{
	double totalUrea, otherFertilizers;
	double initialUrea, remainingUrea, installmentUrea;

	// Input the total amount of urea and other fertilizers
	printf("Enter the total amount of urea (kg): ");
	scanf("%lf", &totalUrea);

	printf("Enter the total amount of other fertilizers (kg): ");
	scanf("%lf", &otherFertilizers);

	// Calculate the amounts of urea for each stage
	initialUrea = totalUrea / 3;
	remainingUrea = totalUrea - initialUrea;
	installmentUrea = remainingUrea / 2;

	// Print the fertilizer application schedule for corn
	printf("\nFertilizer Application Schedule for Corn:\n");
	printf("1. At the last stage of land preparation:\n");
	printf("   - Urea: %.2f kg\n", initialUrea);
	printf("   - Other fertilizers: %.2f kg\n", otherFertilizers);

	printf("2. After 25-30 days of seed germination:\n");
	printf("   - Urea: %.2f kg\n", installmentUrea);

	printf("3. After 40-50 days of seed germination:\n");
	printf("   - Urea: %.2f kg\n", installmentUrea);

	// Print the water management schedule for corn
	printf("\nWater Management Schedule for Corn:\n");
	printf("1. First irrigation: 15 to 20 days after sowing\n");
	printf("2. Second irrigation: 30 to 35 days after sowing\n");
	printf("3. Third irrigation: 60 to 70 days after sowing\n");
	printf("4. Fourth irrigation: 85 to 89 days after sowing\n");
}

// Function to calculate and print the fertilizer schedule for rice
void riceFertilizerSchedule()
{
	double totalScrapie, totalOSOP, totalJesus, totalKick;
	double boron, granularInsecticide;
	double firstApplication, secondApplication, thirdApplication;

	// Fixed amounts for rice
	totalScrapie = 25;
	totalOSOP = 20;
	totalJesus = 20;
	totalKick = 2;
	boron = 1;
	granularInsecticide = 1;

	// Calculate the amounts of fertilizer for each stage
	firstApplication = totalScrapie / 3;
	secondApplication = firstApplication;
	thirdApplication = firstApplication;

	// Print the fertilizer application schedule for rice
	printf("\nFertilizer Application Schedule for Rice:\n");
	printf("1. At the last stage of land preparation:\n");
	printf("   - Scrapie: %.2f kg\n", totalScrapie);
	printf("   - OSOP: %.2f kg\n", totalOSOP);
	printf("   - Jesus: %.2f kg\n", totalJesus);
	printf("   - Kick: %.2f kg\n", totalKick);
	printf("   - Boron: %.2f kg\n", boron);
	printf("   - Granular insecticide: %.2f kg\n", granularInsecticide);

	printf("2. After 8-12 days:\n");
	printf("   - Scrapie: %.2f kg\n", firstApplication);

	printf("3. After 25-30 days:\n");
	printf("   - Scrapie: %.2f kg\n", secondApplication);

	printf("4. After 40-45 days:\n");
	printf("   - Scrapie: %.2f kg\n", thirdApplication);

	// Print the water management schedule for rice
	printf("\nWater Management Schedule for Rice:\n");
	printf("1. One and a half to two inches for the first 20 days from planting.\n");
	printf("2. One to one and a half inches from 11 days after planting till emergence.\n");
	printf("3. Periodic water release 20-22 days before harvesting when the grains are hard.\n");
}

// Function to calculate and print the fertilizer and water schedule for jute
void juteFertilizerSchedule()
{
	double cowdungManure, ureaDaySowing, tspDaySowing, mopDaySowing, ureaAfterWeeding;

	// Fixed amounts for jute
	cowdungManure = 3.5 * 1000; // converting tonnes to kg
	ureaDaySowing = 15;
	tspDaySowing = 17;
	mopDaySowing = 22;
	ureaAfterWeeding = 100;

	// Print the fertilizer application schedule for jute
	printf("\nFertilizer Application Schedule for Jute:\n");
	printf("1. 2-3 weeks before sowing on well-prepared land:\n");
	printf("   - Cowdung manure: %.2f kg per hectare\n", cowdungManure);

	printf("2. On the day of sowing:\n");
	printf("   - Urea: %.2f kg\n", ureaDaySowing);
	printf("   - TSP: %.2f kg\n", tspDaySowing);
	printf("   - MOP: %.2f kg\n", mopDaySowing);

	printf("3. After 6-7 weeks of sowing, during weeding and thinning:\n");
	printf("   - Urea: %.2f kg\n", ureaAfterWeeding);

	// Print the water management schedule for jute
	printf("\nWater Management Schedule for Jute:\n");
	printf("1. First irrigation: 15 to 20 days after sowing\n");
	printf("2. Second irrigation: 30 to 35 days after sowing\n");
	printf("3. Third irrigation: 60 to 70 days after sowing\n");
	printf("4. Fourth irrigation: 85 to 89 days after sowing\n");
}


