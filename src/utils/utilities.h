// Reads an array of doubles from the provided file name.
// Sets arrPtr to the start of the array and countPtr to the number of elements.
// Returns 0 if successful and -1 if error encountered.
int readArrayFromFile(const char* fileName, double ** arrPtr, int * countPtr);

int readCharArrayFromFile(const char* fileName, char ** arrPtr, int * countPtr);

int readLimitedCharArrayFromFile(const char* fileName, char ** arrPtr, int * countPtr, char minVal, char maxVal);

// Prints the provided array of double elements as a
// contiguous array.
void printDoubleArray(double * array, int numElements);

// Prints the provided array of int elements as a
// contiguous array.
void printIntArray(int * array, int numElements);