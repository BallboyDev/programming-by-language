#include <windows.h>
#include <stdio.h>
#include <string.h>

void Error(){
	MessageBox(0, "Error!!!", "Warning", MB_OK);
	printf("Operation Failed!!!\n");
	exit(1);
}

int main(){
	char Name[20] = {0};
	char fName[30] = {0};
	DWORD dw;
	HANDLE hFile;
	
	printf("input Create File name : ");
	gets(Name);
	
	hFile = CreateFile(Name, GENERIC_READ | GENERIC_WRITE, 0, 0, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);
	
	if(hFile == NULL) Error();
	printf("Create Complete!\n");
	
	printf("input Program Name or Path : ");
	gets(fName);
	
	if(!WriteFile(hFile, fName, strlen(fName), &dw, 0)) Error();
	printf("input Complete!\n");
	
	CloseHandle(hFile);
	return 0;
}