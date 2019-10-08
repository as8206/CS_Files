int checkForMatch(char *str, int pos, char *key);
void removeIfMatch(char *str, int pos, FILE *keyFile, int numOfKey);
char* removeMatch(char *str, int pos, char *key);
int reduceString(char *string, FILE *keyFile, int numOfKey);
