#define MAX 8
#define LEN 255

void createContent(char content[MAX][LEN])
{
	char student[]			= { "student_" };
	char pointer[]			= { ", " };
	char numberChar[3];

	for (int i = 0; i < MAX; i++) {
		
		sprintf(numberChar, "%d", i);
		strcat(content[i], student);
		strcat(content[i], numberChar);

		if ((i + 1) != MAX) {
			strcat(content[i], pointer);
		}
		
	}
	
}

void outContent(char content[MAX][LEN])
{
	
	for (int i = 0; i < MAX; i++) {
		printf(content[i]);
	}

}

void save(char path[], char content[MAX][LEN])
{
	FILE *fp = fopen(path, "w");

	if (fp != NULL) {
		for (int i = 0; i < MAX; i++) {
			fprintf(fp, content[i]);
		}
		fclose(fp);
	}

}

void open(char path[])
{

	FILE* fp = fopen(path, "r");

	if (fp != NULL) {
		// ������ ������ ����� ��� �������� ������ ������� �������
		fseek(fp, 0L, SEEK_END);
		long size = ftell(fp);
		fseek(fp, 0L, SEEK_SET);

		// �������� ������ ��� �����
		char* fcontent = (char*)malloc(sizeof(char) * size);
		// ������ ��������� ���� ���� � �����   
		fread(fcontent, 1, size, fp);
		// ������� ���������� ������ � ����������� �����
		printf(fcontent);
		// � ����������� ����������� ������ ���������� ��� �����
		free(fcontent);
		// ��������� ����
		fclose(fp);

	}
}

void file()
{
	char pathToFile[]	=	"../document/students.txt";
	char content[MAX][LEN] = { "" };
	
	createContent(content);
	save(pathToFile, content);
	open(pathToFile);
}