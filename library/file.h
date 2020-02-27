#define MAX 8
#define LEN 255

void createContent(char content[MAX][LEN], char* fpointer, char* fend)
{
	char student[]			= { "student_" };
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

void getArr(char *fcontent[MAX][LEN], char* fpointer, char* fend)
{
	char*	ptr				= strtok(fcontent, fpointer);
	int		counter			= 0;
	char	buf[MAX][LEN]	= { "" };

	while (ptr != NULL)
	{
		strcat(buf[counter], ptr);
		ptr = strtok(NULL, fpointer);
		
		if (ptr != NULL) {
			counter++;
			continue;
		}

		strtok(buf[counter], fend);
	}
}

void outContent(char content[MAX][LEN])
{
	
	for (int i = 0; i < MAX; i++) {
		printf(content[i]);
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

void open(char* path, char fcontent[MAX][LEN])
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
		strcat(fcontent, buf);
		free(buf);
		fclose(fp);
		
	}
}

void file()
{
	char*	pathToFile			=	"../document/students.txt";
	char*	fpointer			= { ", " };
	char*	fend				= { "." };
	char	content[MAX][LEN]	= { "" };
	char	fcontent[MAX][LEN]	= { "" };
	
	createContent(content, fpointer, fend);
	save(pathToFile, content);
	open(pathToFile, fcontent);
	getArr(fcontent, fpointer, fend);
	printf(fcontent[1]);
}