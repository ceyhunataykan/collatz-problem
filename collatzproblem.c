#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
    int n = 0;
    pid_t c_pid;

    printf("Collatz Sayisi giriniz : \n"); 
    scanf("%d", &n);

    c_pid = fork();

    if (c_pid < 0) {
        printf("Fork Başarısız...");
        return 1;
    }else if (c_pid == 0){

        printf("Child Process Basliyor...\n");
        printf("%d\n",n);

        while(n != 1)
        {
            if (n % 2 == 0)
            {
                n = n / 2;
            }
            else if (n % 2 == 1)
            {
                n = (3 * n) + 1;
            }
            printf("%d\n",n);
        }
        
        printf("Child Process Bitiyor...\n");
    
    }else{

        printf("Parent Process Child Process'i Bekliyor... %d\n", (int)getpid());
        wait(NULL);
        printf("Parent Process Bitiyor... %d\n", (int)getpid());
    
    }

    return 0;
}
