#define MAX 2
#define LEN 255
char	fcontent[MAX][LEN]	= { "" };

void createContent(char content[MAX][LEN], char* fpointer, char* fend)
{
	char student[]	= { "student_" };
	char numberChar[3];

	for (int i = 0; i < MAX; i++) {
		
		sprintf(numberChar, "%d", i);
		strcat(content[i], student);
		strcat(content[i], numberChar);

		if ((i + 1) != MAX) {
			strcat(content[i], fpointer);
			continue;
		}

		strcat(content[i], fend);
	}
	
}

void getArr(char fbuffer[MAX][LEN], char* fpointer, char* fend)
{
	char*	ptr				= strtok(fbuffer, fpointer);
	int		counter			= 0;

	while (ptr != NULL)
	{
		strcat(fcontent[counter], ptr);
		ptr = strtok(NULL, fpointer);
		
		if (ptr != NULL) {
			counter++;
			continue;
		}

		strtok(fcontent[counter], fend);
	}
}

void outContent(char content[MAX][LEN])
{
	system("cls");
	printf("Outputting all student with their is personal data:\n");

	for (int i = 0; i < MAX; i++) {
		printf("%s\n",content[i]);
	}

}

void save(char* path, char content[MAX][LEN])
{
	FILE *fp = fopen(path, "w");

	if (fp != NULL) {
		for (int i = 0; i < MAX; i++) {
			fprintf(fp, content[i]);
		}
		fclose(fp);
	}

}

void open(char* path, char fbuffer[MAX][LEN])
{

	FILE* fp = fopen(path, "r");

	if (fp != NULL) {
		// find out the file size to create a buffer of the required size
		fseek(fp, 0L, SEEK_END);
		long size = ftell(fp);
		fseek(fp, 0L, SEEK_SET);
		// allocate memory for the buffer
		char* buf = (char*)malloc(sizeof(char) * size);
		// read file
		fread(buf, 1, size, fp);
		strcat(fbuffer, buf);
		free(buf);
		fclose(fp);
		
	}
}

void file()
{
	char*	pathToFile			= "../document/students.txt";
	char*	fpointer			= { ", " };
	char*	fend				= { "." };
	char	content[MAX][LEN]	= { "" };
	char	fbuffer[MAX][LEN] = { "" };
	
	createContent(content, fpointer, fend);
	save(pathToFile, content);
	open(pathToFile, fbuffer);
	getArr(fbuffer, fpointer, fend);
}