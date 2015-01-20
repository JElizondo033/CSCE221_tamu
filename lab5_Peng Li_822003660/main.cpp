#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>

using namespace std;

int main(int argc, char * argv[]) {
    pid_t childpid;
    if ((childpid=fork()) < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if(childpid == 0 ){
        execv("./PQList",argv);
    }
    else if(childpid > 0){
        sleep(1);
        execv("./PQHeap",argv);
    }
}
