#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 1024

int main(){
    //duanluo ��ʾ��������words��ʾĳһ�εĵ�����
    int duanluo = 0, words = 0;
    //min��ʾ��С����ĵ�������max��������ĵ�������sum����������
    int min = 65525, ave = 0, max = 0,sum = 0;
    FILE* fp;  //�ļ�ָ��

    char buffer[MAX_LINE] ; //������
    int len ;//���ַ�����
    int i;
    fp = fopen("D:\\study.clion\\untitled15\\input.txt","r");
    if(fp == NULL){
        printf("cannot open file!");
        exit(0);
    }
    int nums=0;
    //��ȡ�ļ�����
    while(! feof(fp)){
        // fgets() �ڶ��� MAX_LINE ���ַ�֮ǰ������ ���з� �� EOF ���������
        if(fgets(buffer, MAX_LINE, fp) != NULL){
            duanluo ++;
            len = strlen(buffer);
            //������һ���ո�֮ǰ����һ������
            words = 1;
            sum ++;
         //len - 1 ��Ϊ��ȥ�����з���ռλ��
            for(i = 0; i < len - 1; i++){
                if(buffer[i] == ' '){
                    words ++;
                    sum ++;
                } else
                    nums++;
            }
        }

       if(min > words){
            min = words;
       }
       if(max < words){
            max = words;
       }
    }

    fclose(fp);
    //���
    printf("\n\t �ܵ�����Ϊ %d \n \n",sum);
    printf("\t ���ַ���Ϊ %d \n \n",nums);

    return 0;
}