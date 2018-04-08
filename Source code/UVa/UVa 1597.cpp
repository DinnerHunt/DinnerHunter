//UVa 1597 在Web中搜索 Searching the Web 
#include <bits/stdc++.h>
using namespace std;

char lines[32767];
map<string, set<int> > wordInLine;      //储存单词存于哪行
vector<string> doc;                     //存储所有文章
int articleLine[32767];                 //记录每篇文章的开始行数

void storeInfo(char s[], int lid) {
    static char word[32767];
    int n = (int) strlen(s);
    for (int i = 0; i < n; i++) {
        if (isalpha(s[i])) {
            int p = 0;
            while (isalpha(s[i]))
                word[p++] = tolower(s[i]), i++;
            i--;
            word[p] = '\0';     //尾部加/0 变成字符串
            wordInLine[word].insert(lid);   // 如果当前行数有该单词，则将行数存入集合
        }
    }
}
vector<string> transArgs(char s[]) {        //将字符串变成vector返回
    static char word[32767];
    vector<string> ret;
    int n = (int) strlen(s);
    for (int i = 0; i < n; i++) {
        if (isalpha(s[i])) {
            int p = 0;
            while (isalpha(s[i]))
                word[p++] = tolower(s[i]), i++;
            i--;
            word[p] = '\0';
            ret.push_back(word);
        }
    }
    return ret;
}

int main() {
    int N, M, lid = 0;                              //N记录文章篇数，M操作数量，lid记录行数
    scanf("%d", &N);
    while (getchar() != '\n');
    for (int i = 0; i < N; i++) {
        articleLine[i] = lid;
        for (int j = 0; gets(lines); j++) {
            if (!strcmp(lines, "**********"))
                break;
            doc.push_back(lines);               
            storeInfo(lines, lid), lid++;       
        }
    }
    articleLine[N] = lid;                           //记录文章行号
    scanf("%d", &M);                                   
    while (getchar() != '\n');                      //消除空行
    for (int i = 0; i < M; i++) {
        gets(lines);                                
        vector<string> args = transArgs(lines);     //操作命令转为vector args;
        int hasOutput = 0;                          //判断是不是第一行
        if (args.size() == 1) { // [word]           // 如果操作命令只有一个 
            set<int> &t = wordInLine[args[0]];      // t则为包含该字符串的
            set<int>::iterator it = t.begin();        //设置迭代器
            for (int j = 0; j < N; j++) {              
                while (it != t.end() && *it < articleLine[j])   //迭代器不到最后，并且不超过本段的最后一句
                    it++;                                       
                if (it != t.end() && *it < articleLine[j+1]){      
                    if (hasOutput)
                        puts("----------");
                    hasOutput = 1;
                    while (it != t.end() && *it < articleLine[j+1])
                        puts(doc[*it].c_str()), it++;           //输出doc[*it] 的文本，迭代器it++；
                }
            }
        } else if (args.size() == 2) { // not [word]
            set<int> &t = wordInLine[args[1]];
            set<int>::iterator it = t.begin();          
            for (int j = 0; j < N; j++) {
                while (it != t.end() && *it < articleLine[j])
                    it++;
                if (it == t.end() || *it >= articleLine[j+1]) {
                    if (hasOutput)
                        puts("----------");
                    hasOutput = 1;
                    for (int k = articleLine[j]; k < articleLine[j+1]; k++)
                        puts(doc[k].c_str());
                }
            }
        } else if (args.size() == 3) { // [word] and/or [word]
            set<int> &s1 = wordInLine[args[0]];
            set<int> &s2 = wordInLine[args[2]];
            set<int>::iterator it = s1.begin();
            set<int>::iterator jt = s2.begin();
            for (int j = 0; j < N; j++) {
                while (it != s1.end() && *it < articleLine[j])
                    it++;
                while (jt != s2.end() && *jt < articleLine[j])
                    jt++;
                int ok = 1;
                if (args[1] == "and") {
                    ok = 1;
                    ok &= it != s1.end() && *it < articleLine[j+1];
                    ok &= jt != s2.end() && *jt < articleLine[j+1];
                } else {
                    ok = 0;
                    ok |= it != s1.end() && *it < articleLine[j+1];
                    ok |= jt != s2.end() && *jt < articleLine[j+1];
                }
                if (!ok)
                    continue;
                if (hasOutput)
                    puts("----------");
                hasOutput = 1;
                while (true) {
                    int a = 0x3f3f3f3f, b = 0x3f3f3f3f;
                    if (it != s1.end() && *it < articleLine[j+1])
                        a = *it;
                    if (jt != s2.end() && *jt < articleLine[j+1])
                        b = *jt;
                    if (a == b && a == 0x3f3f3f3f)
                        break;
                    if (a < b) {
                        it++;
                    } else if (a > b) {
                        jt++, a = b;
                    } else {
                        it++, jt++;
                    }
                    puts(doc[a].c_str());
                }
            }
        }
        if (!hasOutput)
            puts("Sorry, I found nothing.");
        puts("==========");
    }
    return 0;
}
/*
 
 */