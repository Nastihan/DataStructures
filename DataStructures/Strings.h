#pragma once

class Strings {
private:
	char *S;
public:
	// Length method for finding the length of a string
	int Length() {
		int i{};
		for (i; S[i]!='\0'; i++) {}
		return i;
	}
	// HigherCase method for changing the case of a string
	void HigherCase() {
		for (int i{}; S[i] != '\0'; i++)
			S[i] -= 32;
	}

	// LowerCase method for changing the case of a string
	void LowerCase() {
		for (int i{}; S[i] != '\0'; i++)
			S[i] += 32;
	}
	// Toggle method for toggling the cases in a string
	void Toggle() {
		for (int i{}; S[i] != '\0';i++) {
			if (S[i] >= 65 && S[i] <= 90)
				S[i] += 32;
			else if (S[i] >= 97 && S[i] <= 122)
				S[i] -= 32;
		}
	}
	// WordCount method for counting the number of words in a string
	int WordCount() {
		int wcount{ 1 };
		for (int i{}; S[i] != '\0';i++) {
			if (S[i] == ' ' && S[i - 1] != ' ')
				wcount++;
		}
		return wcount;
	}
	// VowelCount method for counting the number of vowels in a string 
	int VowelCount() {
		int vcount{};
		for (int i{}; S[i] != '\0'; i++) {
			if (S[i] == 'A' || S[i] == 'E' || S[i] == 'I' || S[i] == 'O' || S[i] == 'U' || S[i] == 'a' || S[i] == 'e' || S[i] == 'i' || S[i] == 'o' || S[i] == 'u')
				vcount++;
		}
		return vcount;
	}
	// ConsonantCount method for counting the number of consonants in a string
	int ConsonantCounter() {
		int ccount{};
		for (int i{}; S[i] != '\0';i++) {
			if ((S[i] != 'A' && S[i] != 'E' && S[i] != 'I' && S[i] != 'O' && S[i] != 'U' && S[i] != 'a' && S[i] != 'e' && S[i] != 'i' && S[i] != 'o' && S[i] != 'u')&&((S[i] >= 65 && S[i] <=90)||(S[i]>=97 && S[i]<=122)))
				ccount++;
		}
		return ccount;
	}

};
