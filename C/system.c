#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<stdlib.h>
struct MNT_ELE {
	int MNTC;
	char Name[10];
	int Index;
	struct MNT_ELE *next;
};
struct MDT_ELE {
	int MDTC;
	char Def[50];
	struct MDT_ELE *next;
};
struct ALA_ELE {
	char i[32];
	char Arg[32];
	struct ALA_ELE *next;
};
typedef struct _MNT{
	struct MNT_ELE *head, *tail;
}MNT;
typedef struct _MDT{
	struct MDT_ELE *head, *tail;
}MDT;
typedef struct _ALA{
	struct ALA_ELE *head, *tail;
}ALA;
MNT mnt;
MDT mdt;
ALA mc, md;
FILE *in, *out, *tm;
FILE *fMnt, *fMdt, *fMc, *fMd;
void Construct_MNT(char *name);
void Construct_MDT();
void Construct_ALA(ALA *x, char arg[], int i, int flag);
void PASS1(char buff[]);
void PASS2(char buff[]);
int search_MNT(char *id);
void Expand(int i);
char *Replace(char buf[], struct ALA_ELE *p);
int main(int argc, char *argv[])
{
	char buf[40];
	if (argc < 3)
	{
		printf("Usage : M4 source_file {output_file} [ENTER]\n");
		exit(1);
	}
	fopen_s(&in, "c:\\in.txt", "rt");
	if (!in)printf("er\n");
	fopen_s(&tm, "c:\\temp.TXT", "wt");
	if (!tm)printf("er\n");
	fopen_s(&out, "c:\\out.TXT", "wt");
	if (!out)printf("er\n");
	fopen_s(&fMc, "c:\\fMc.txt", "wt");
	if (!fMc)printf("er\n");
	fprintf(fMc, "!형식 인수표\n");
	fopen_s(&fMd, "c:\\fMd.txt", "wt");
	if (!fMd)printf("er\n");
	fprintf(fMd, "!실 인수표\n");
	fopen_s(&fMnt, "c:\\fMnt.txt", "wt");
	if (!fMnt)printf("er\n");
	fprintf(fMnt, "!매크로 이름표\n");
	while (!feof(in))
	{
		printf(fgets(buf, 40, in));
		PASS1(buf);
	}
	while (fgets(buf, 40, in))
	{
		PASS1(buf);
	}
	rewind(tm);
	while (!feof(tm))
	{
		fgets(buf, 40, tm);
		PASS2(buf);
	}
	fclose(in);
	fclose(tm);
	fclose(out);
	fclose(fMd);
	fclose(fMc);
	fclose(fMnt);
	printf("\n");
	return 0;
}
void Construct_MNT(char *name)
{
	struct MNT_ELE *ele;
	ele = (struct MNT_ELE*)malloc(sizeof(struct MNT_ELE));
	if (mnt.head == NULL)
	{
		mnt.head = ele;
		mnt.head->MNTC = 1;
	}
	if (mnt.tail != NULL)
	{
		mnt.tail->next = ele;
		ele->MNTC = mnt.tail->MNTC + 1;
	}
	mnt.tail = ele;
	strcpy_s(ele->Name, strlen(name) + 1, name);
	if (mdt.tail == NULL)ele->Index = 1;
	else	ele->Index = mdt.tail->MDTC + 1;
	ele->next = NULL;
	fprintf(fMnt, "%d	%s	  %d\n", ele->Index, ele->Name, ele->MNTC);

}
void Construct_MDT()
{
	char buf[40];
	struct MDT_ELE *ele;
	do
	{
		ele = (struct MDT_ELE *)malloc(sizeof(struct MDT_ELE));
		if (mdt.head == NULL)
		{
			mdt.head = ele;
			mdt.head->MDTC = 1;
		}
		if (mdt.tail != NULL)
		{
			mdt.tail->next = ele;
			ele->MDTC = mdt.tail->MDTC + 1;
		}
		mdt.tail = ele;
		fgets(buf, 40, in);
		strcpy_s(ele->Def, strlen(Replace(buf, mc.head)) + 1, Replace(buf, mc.head));
		ele->next = NULL;
	} while (!strstr(buf, "ENDM"));
}
void Construct_ALA(ALA *x, char arg[], int i, int flag)
{
	struct ALA_ELE *ele;
	ele = (struct ALA_ELE *)malloc(sizeof(struct ALA_ELE));
	if (x->head == NULL) x->head = ele;
	if (x->tail != NULL) x->tail->next = ele;
	x->tail = ele;
	if (flag == 0)
	{
		sprintf(ele->i, "#%d", i);
		strcpy_s(ele->Arg, strlen(arg) + 1, arg);
		fprintf(fMc, "%#d\t%s\n", i, ele->Arg);
	}
	else
	{
		sprintf(ele->Arg, "#%d", i);
		strcpy_s(ele->i, strlen(arg) + 1, arg);
		fprintf(fMd, "%s\t%d\n", ele->Arg, i);
	}
	ele->next = NULL;
}
char *Replace(char buf[], struct ALA_ELE *p)
{
	int bp, t_bp;
	char temp[40];
	struct ALA_ELE *t;
	bp = 0;
	t = p;
	while (buf[bp] != '\n')
	{
		while (buf[bp] == ' ' || buf[bp] == ',' || buf[bp] == '\t')bp++;
		while (p != NULL)
		{
			if (!strncmp(buf + bp, p->Arg, strlen(p->Arg)))
			{
				t_bp = bp;
				while (buf[bp] != ' '&&buf[bp] != ','&&buf[bp] != '\t'&&buf[bp] != '\n')bp++;
				strcpy_s(temp, strlen(buf + bp) + 1, buf + bp);
				strcpy(buf + t_bp, p->i);
				bp = t_bp + strlen(p->i);
				strcat(buf, temp);
				break;
			}
			p = p->next;
		}
		p = t;
		while (buf[bp] != ' '&&buf[bp] != ','&&buf[bp] != '\t'&&buf[bp] != '\n')bp++;
	}
	return(buf);
}
void PASS1(char buff[])
{
	int i, j, bp;
	char word[5][10];
	for (i = 0; i < 5; i++)word[i][0] = '\0';
	bp = 0; i = 0; j = 0;
	while (buff[bp] != '\n')
	{
		while (buff[bp] == ' ' || buff[bp] == ',' || buff[bp] == '\t')bp++;
		while (buff[bp + i] != ' '&&buff[bp + i] != ','&&buff[bp + i] != '\t'&&buff[bp + i] != '\n')
		{
			*(word[j] + i) = buff[bp + i];
			i++;
		}
		bp = bp + i;
		*(word[j] + i) = '\0';
		i = 0;
		j++;
	}
	if (!strcmp(word[1], "MACRO"))
	{
		Construct_MNT(word[0]);
		for (i = 2; i < j; i++)Construct_ALA(&mc, word[i], i - 1, 0);
		Construct_MDT();
	}
	else
		fprintf(tm, "%s", buff);
}
void PASS2(char buff[])
{
	int jp, i, j, k, bp;
	char word[5][10];
	for (i = 0; i < 5; i++) word[i][0] = '\0';
	bp = 0; i = 0; j = 0;
	while (buff[bp] != '\n')
	{
		while (buff[bp] == ' ' || buff[bp] == ',' || buff[bp] == '\t')bp++;
		while (buff[bp + i] != ' '&&buff[bp + i] != ','&&buff[bp + i] != '\t'&&buff[bp + i] != '\n')
		{
			*(word[j] + i) = buff[bp + i];
			i++;
		}
		bp = bp + i;
		*(word[j] + i) = '\0';
		i = 0;
		j++;
	}
	jp = search_MNT(word[0]);
	if (jp)
	{
		for (k = 1; k < j; k++) Construct_ALA(&md, word[k], k, 1);
		Expand(jp);
	}
	else
		fprintf(out, "%s", buff);
}
int search_MNT(char *id)
{
	struct MNT_ELE *p=mnt.head;
	while (p != NULL)
		if (!strcmp(p->Name, id)) return p->Index;
		else p = p->next;
		return 0;
}
void Expand(int i)
{
	struct MDT_ELE *p = mdt.head;
	while (i != p->MDTC) p = p->next;
	while (!strstr(p->Def, "ENDM"))
	{
		strcpy_s(p->Def, strlen(Replace(p->Def, md.head)) + 1, Replace(p->Def, md.head));
		fprintf(out, "%s", p->Def);
		p = p->next;
	}
}