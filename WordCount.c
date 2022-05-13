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
    
    if (argv[1][1] == 'w') /*统计单词个数*/
    {
        char s[1024];
        while (fscanf(pfile, "%s", s) != EOF)/*%s读入时为空格直接计数*/
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
        printf("单词数:%d\n", count);
    }
    
    else if (argv[1][1] == 'c') /*统计字符个数*/ 
    {
        char c;
        while ((c = fgetc(pfile)) != EOF) 
			count ++;
        printf("字符数:%d", count);
    }
    
    
    fclose(pfile);/*必须关闭文件*/ 
    
    return 0;
}
