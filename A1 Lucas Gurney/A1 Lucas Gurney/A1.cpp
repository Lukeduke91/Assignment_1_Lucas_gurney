#include <iostream>
#include <string>
using namespace std;

class Person
{
protected:
	string name;
	int age;
public:
	virtual void List() const = 0;
	void setSurveyList(string N, int A)
	{
		name = N;
		age = A;
	}
};

class Student : public Person
{
public:

	virtual void List() const
	{
		unsigned seed = time(0);
		srand(seed);
		string Colleges[3] = { "George Brown", "Sheridan", "Niagra College" };

		string Program[3] = { "Game Programming", "Fashion", "Computer engineer" };

		cout << "Students name is " << name << " from " << Colleges[rand() % 3] << " currently enrolled in " << Program[rand() % 3] << " on their "
			<< 8 << " semester at the age of " << age << endl;
	}
};

class NonGamingStudent : public Student 
{
public:
	virtual void List() const
	{
		cout << "these students prefer to stream on " << name << " and said they watch it for " << age << " hour in total."<< endl;
	}
};

class GamingStudent : public Student
{
public:
	virtual void List() const
	{
		cout << "these students prefer to play games on " << name << " and said they watch it for " << age << " hour in total." << endl;
	}
};

class Survey
{
private:
	int averageAge;
	string preferredService;
	int averageHours;
public:
	Survey(int A, string S, int H)
	{
		averageAge = A;
		preferredService = S;
		averageHours = H;
	}

	Survey()
	{
		averageAge = 0;
		preferredService = "none";
		averageHours = 0;
	}

	void setAge(int A)
	{
		averageAge = A;
	}

	void setStream(string S)
	{
		preferredService = S;
	}

	void setHour(int H)
	{
		averageHours = H;
	}

	int getAge()
	{
		return averageAge;
	}

	string getStream()
	{
		return preferredService;
	}

	int getHour()
	{
		return averageHours;
	}

	string getCollectedSurvey()
	{
		string CollectedSurvey = "\nThe average age=======>" + to_string(averageAge);
		CollectedSurvey += "\nPrefered service========>" + preferredService;
		CollectedSurvey += "\nAverage Hours used========>" + to_string(averageHours);
		return CollectedSurvey;
	}
};

int main()
{
	unsigned seed = time(0);
	srand(seed);

	const int MAX_PEOPLE = 3;
	const int maxParticipants = 250;
	string info[maxParticipants];
	string streamingService[maxParticipants];
	string gameconsole[maxParticipants];
	string Name;
	int ageNumber[maxParticipants];
	int hourNumberS[maxParticipants];
	int hourNumberG[maxParticipants];
	int agelimit;
	int finalAge;
	int age = 0, hoursS = 0, hoursG = 0;
	int PCount = 0, XCount = 0, SCount = 0;
	int DCount = 0, NCount = 0, HCount = 0;
	int choice = 0;
	int participants = 0;
	Survey list[2];
	list[0] = Survey();
	list[1] = Survey();

	string firstname[20] = { "Thea ", "aida ", "katie ", "Lieselotte ", "Talitha ", "Lynda ", "Jule ", "Leida ", "Leia ", "Padme "
		"Werner ", "Elden ", "Bobbie ", "Chance ", "Edward ", "Genaro ", "Erich ", "Adbul ", "Luke ", "Anakin " };
	string lastname[25] = { "Washington", "Fox", "Sutton", "Park", "Little", "Patton", "Rojas", "Barlow", "Duncan", "Fitzgerald",
			"Cruz", "Craig", "Connor", "Townsend", "Mac", "Moss", "Webb", "Snyder", "Bell", "Acosta", "Coleman", "Solo", "Skywalker",
			"Amidala", "Kenobi" };
	string streaming[3] = { "Disney+", "Netflix", "Hulu" };
	string consoles[3] = { "PS5", "Xbox series X", "Nintendo Switch" };

	Person* PersonArray[MAX_PEOPLE]
	{ 
		new Student(),
		new NonGamingStudent(),
		new GamingStudent()
	};

	cout << "Welcome to the survey application!!!\n=====================================" << endl;
	cout << "How many will be participating today?(Max 250): ";
	cin >> participants;

	for (int i = 0; i < participants; i++)
	{
		ageNumber[i] = 17+rand() % 11;
		info[i] = firstname[rand() % 19] + lastname[rand() % 24];
	}

	for (int i = 0; i < participants; i++)
	{
		PersonArray[0]->setSurveyList(info[i], ageNumber[i]);
	}
	
	for (int i = 0; i < participants; i++)
	{
		hourNumberS[i] = rand() % 500;
		streamingService[i] = streaming[rand() % 3];
		if (streamingService[i] == "Disney+")
		{
			DCount++;
		}

		else if (streamingService[i] == "Netflix")
		{
			NCount++;
		}

		else if (streamingService[i] == "Hulu")
		{
			HCount++;
		}
	}

	for (int i = 0; i < participants; i++)
	{
		PersonArray[1]->setSurveyList(streamingService[i], hourNumberS[i]);
	}

	for (int i = 0; i < participants; i++)
	{
		hourNumberG[i] = rand() % 500;
		gameconsole[i] = consoles[rand() % 3];
		if (gameconsole[i] == "PS5")
		{
			PCount++;
		}

		else if (gameconsole[i] == "Xbox series X")
		{
			XCount++;
		}

		else if (gameconsole[i] == "Nintendo Switch")
		{
			SCount++;
		}
	}

	for (int i = 0; i < participants; i++)
	{
		PersonArray[2]->setSurveyList(gameconsole[i], hourNumberG[i]);
	}

	for (int i = 0; i < participants; i++)
	{
		age += ageNumber[i];
		hoursG += hourNumberG[i];
		hoursS += hourNumberS[i];
	}

	finalAge = age / participants;

	//Gaming Students
	if (PCount > XCount && SCount)
	{
		list[0] = Survey(finalAge,"PS5",hoursG/participants);
	}

	else if (XCount > PCount && SCount)
	{
		list[0] = Survey(finalAge, "Xbox Series X", hoursG / participants);
	}

	else if (SCount > XCount && PCount)
	{
		list[0] = Survey(finalAge, "Nintendo Switch", hoursG / participants);
	}

	else if (XCount && PCount > SCount)
	{
		list[0] = Survey(finalAge, "Xbox Series X & PS5", hoursG / participants);
	}

	else if (XCount && SCount > PCount)
	{
		list[0] = Survey(finalAge, "Xbox Series X & Nintendo Switch", hoursG / participants);
	}

	else if (SCount && PCount > XCount)
	{
		list[0] = Survey(finalAge, "Nintendo Switch & PS5", hoursG / participants);
	}

	//Non-Gaming Students
	if (DCount > NCount && HCount)
	{
		list[1] = Survey(finalAge, "Disney+", hoursS / participants);
	}

	else if (NCount > DCount && HCount)
	{
		list[1] = Survey(finalAge, "Netflix", hoursS / participants);
	}

	else if (HCount > NCount && DCount)
	{
		list[1] = Survey(finalAge, "Hulu", hoursS / participants);
	}

	else if (DCount && NCount > HCount)
	{
		list[1] = Survey(finalAge, "Disney+ & Netflix", hoursS / participants);
	}

	else if (DCount && HCount > NCount)
	{
		list[1] = Survey(finalAge, "Disney+ & Hulu", hoursS / participants);
	}

	else if (NCount && HCount > DCount)
	{
		list[1] = Survey(finalAge, "Netflix & Hulu", hoursS / participants);
	}

	cout << "Would you like to see the survey?:\n1. Yes\n2. No" << endl;
	cin >> choice;
	if (choice == 1)
	{
		cout << list[0].getCollectedSurvey() << endl;
		cout << list[1].getCollectedSurvey() << endl;
	}

	if (choice == 2)
	{
		cout << "Have a good day.";
	}
	return 0;
}