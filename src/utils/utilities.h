// Checks if the provided character is a capital-case character
// value. Returns true if capital-case, false otherwise.
bool isCapitalAlphabetChar(char c);

// Checks if the provided character is a lower-case character
// value. Returns true if lower-case, false otherwise.
bool isLowerAlphabetChar(char c);

// Capitalizes the provided lower-case character.
char capatilizeChar(char c);

// Reads a character array from the provided file name. The provided
// array pointer and count pointer are updated to point to the
// created array and counter values.
int readCharArrayFromFile(const char* fileName, char ** arrPtr, int * countPtr);