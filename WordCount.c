#include <stdio.h>
#include <string.h>
int main (int argc, char **argv)
{
    FILE *pfile;
    
    int count = 0;
    
    
    if ((pfile=fopen(argv[2], "r")) == NULL)
    {
        puts("error!\n");
        return 0;
    }
    
    if (argv[1][1] == 'w') /*ͳ�Ƶ��ʸ���*/
    {
        char s[1024];
        while (fscanf(pfile, "%s", s) != EOF)/*%s����ʱΪ�ո�ֱ�Ӽ���*/
        {
            count ++;
            int i;
            for (i = 1; i < strlen(s) - 1; i ++)
            {
            	if (s[i] == ',' && s[i - 1] != ',' && s[i + 1] != ',') 
            	{
            		count ++;
				}
			}
        }
        printf("������:%d\n", count);
    }
    
    else if (argv[1][1] == 'c') /*ͳ���ַ�����*/ 
    {
        char c;
        while ((c = fgetc(pfile)) != EOF) 
			count ++;
        printf("�ַ���:%d", count);
    }
    
    
    fclose(pfile);/*����ر��ļ�*/ 
    
    return 0;
}
