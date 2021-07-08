// Hi my name is Brandon  and I developed this program to calculate a bowling league's average bowling scores.

#include<iostream>
#include<string>
#include<fstream>

using namespace std;

// Declared playerCount globally to Count number of players
int playerCount = 0;

// Function to store data from file to array.
void GetBowlingData(string filename, string name[100], int score[5][100]) {

	fstream file;
	// File open
	file.open("BowlingScores.txt", ios::in);

	// If file not present then exit 
	if (!file) {
		cout << "File not present";
		exit(0);
	}

	// Run loop to scan file data in arrays
	while (!file.eof()) {
		file >> name[playerCount];
		// If name is blank, it means a new line is present at the end of file, so we don't have to store it.
		if (name[playerCount] == "")     break;
		for (int i = 0;i < 5;i++) {
			file >> score[i][playerCount];
		}
		playerCount++;
	}
	// File closed.
	file.close();
}


// Function to store average of scores.
float* GetAverageScore(int score[5][100]) {
	static float average[100];
	for (int i = 0; i < playerCount; i++) {
		int sum = 0;
		for (int j = 0; j < 5; j++) {
			sum += score[j][i];
		}
		// Sum is converted to float and then average is calculated by dividing it by 4.
		average[i] = float(sum) / 5;
	}
	//Average array is returned
	return average;
}

// Function to print the details
void PrettyPrintResults(string name[], int score[][100], float average[]) {
	// Heading for output
	cout << "Name\t\t" << "Score1\t\tScore2\t\tScore3\t\tScore4\t\tScore5\t\tAverage" << endl;

	for (int i = 0; i < playerCount; i++) {
		// If length of name is more than 7, then difference of tab will be created.
		// To remove the difference we used this condition.
		if (name[i].length() > 8)
			cout << name[i] << "\t" << score[0][i] << "\t\t" << score[1][i] << "\t\t" << score[2][i] << "\t\t" << score[3][i] << "\t\t" << score[4][i] << "\t\t" << average[i] << endl;
		else
			cout << name[i] << "\t\t" << score[0][i] << "\t\t" << score[1][i] << "\t\t" << score[2][i] << "\t\t" << score[3][i] << "\t\t" << score[4][i] << "\t\t" << average[i] << endl;
	}

}

// Main Function
int main() {

	// Arrays Declared
	string name[100];
	int score[5][100];
	float* average;

	// Functions called

	GetBowlingData("BowlingScores.txt", name, score);

	average = GetAverageScore(score);

	PrettyPrintResults(name, score, average);

	return 0;
}