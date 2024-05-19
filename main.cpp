#include <stdio.h>
#include <string.h>
#include <ctype.h>

// 函数原型
bool is_delimiter(char c);
int count_words(FILE *file);
int count_characters(FILE *file);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: WordCount [-c|-w] <file_name>\n");
        return 1;
    }

    FILE *file = fopen(argv[2], "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    int count = 0;
    if (strcmp(argv[1], "-w") == 0) {
        count = count_words(file);
        printf("单词数：%d\n", count);
    } else if (strcmp(argv[1], "-c") == 0) {
        count = count_characters(file);
        printf("字符数：%d\n", count);
    } else {
        printf("Invalid parameter. Use '-c' for characters or '-w' for words.\n");
    }

    fclose(file);
    return 0;
}

// 判断是否是分隔符
bool is_delimiter(char c) {
    return isspace(c) || c == ',';
}

// 计算单词数
int count_words(FILE *file) {
    int count = 0;
    bool in_word = false;
    char c;
    while ((c = fgetc(file)) != EOF) {
        if (is_delimiter(c)) {
            if (in_word) {
                count++;
                in_word = false;
            }
        } else {
            in_word = true;
        }
    }
    if (in_word) {
        count++; // 文件末尾的单词
    }
    return count;
}

// 计算字符数
int count_characters(FILE *file) {
    int count = 0;
    char c;
    while ((c = fgetc(file)) != EOF) {
        count++;
    }
    return count;
}
