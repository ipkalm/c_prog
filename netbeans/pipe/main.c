/* 
 * File:   main.c
 * Author: astronaut
 *
 * Created on 8 апреля 2015 г., 17:00
 */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/*
 * 
 */

void open_url(char * url);
void error(char * msg);

int main(int argc, char *argv[])
{
    char *phrase = argv[1];
    char *vars[] = {"RSS_FEED=http://citforum.ru/news/rss/news.xml", NULL};
    int fd[2];

    if (pipe(fd) == -1) {
        error("не могу создать канал\n");
    }

    pid_t pid = fork();
    if (pid == -1) {
        error("не могу клонировать процесс\n");
    }

    if (!pid) {
        dup2(fd[1], 1);
        close(fd[0]);
        if (execle("/usr/bin/python2", "/usr/bin/python2", "rssgossip.py", "-u", phrase, NULL, vars) == -1) {
            error("не огу запустить скрипт\n");
        }
    }

    dup2(fd[0], 0);
    close(fd[1]);

    char line[255];
    while (fgets(line, 255, stdin)) {
        if (line[0] == '\t') {
            open_url(line + 1);
        }
    }

    return(EXIT_SUCCESS);
}


// функция вывода ошибок

void error(char * msg)
{
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(1);
}


// функция запуска браузера

void open_url(char * url)
{
    pid_t pid = fork();

    if (pid == 0) {
        if (execl("/usr/bin/xdg-open", "/usr/bin/xdg-open", url, NULL) < 0) {
            error("не удалось запустить браузер\n");
        } else {
            printf("процесс запущен pid=%d\n", pid);
        }
    }
}