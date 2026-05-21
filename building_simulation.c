#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>

#define KAT_SAYISI 10
#define DAIRE_SAYISI 4
#define SEM_VINC "/vinc"

void* daire_islemi(void* arg) {
    int daire_no = *((int*)arg);
    free(arg);

    sem_t* vinc = sem_open(SEM_VINC, 0);
    if (vinc == SEM_FAILED) {
        perror("[HATA] Vinc semaforu acilamadi");
        pthread_exit(NULL);
    }

    printf("[DAIRE %02d] Siva ve tesisat icin vinc bekleniyor...\n", daire_no);

    sem_wait(vinc);

    printf("[DAIRE %02d] Vinci kullaniyor...\n", daire_no);
    sleep(1);

    printf("[DAIRE %02d] Vinci kullanmayi bitirdi.\n", daire_no);
    sem_post(vinc);

    sem_close(vinc);

    pthread_exit(NULL);
}

void kat_insa_et(int kat_no) {
    pthread_t threads[DAIRE_SAYISI];

    printf("\n[KAT %d] Insaat basladi.\n", kat_no);

    for (int i = 0; i < DAIRE_SAYISI; i++) {
        int* daire_no = malloc(sizeof(int));
        if (daire_no == NULL) {
            perror("[HATA] malloc basarisiz");
            exit(1);
        }

        *daire_no = kat_no * 10 + (i + 1);

        if (pthread_create(&threads[i], NULL, daire_islemi, daire_no) != 0) {
            perror("[HATA] Thread olusturulamadi");
            free(daire_no);
            exit(1);
        }
    }

    for (int i = 0; i < DAIRE_SAYISI; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("[KAT %d] Tum daireler tamamlandi.\n", kat_no);

    exit(0);
}

int main() {
    sem_unlink(SEM_VINC);

    sem_t* vinc = sem_open(SEM_VINC, O_CREAT | O_EXCL, 0644, 1);
    if (vinc == SEM_FAILED) {
        perror("[HATA] Vinc semaforu olusturulamadi");
        exit(1);
    }

    printf("Apartman insaati basliyor...\n");

    for (int kat = 1; kat <= KAT_SAYISI; kat++) {
        pid_t pid = fork();

        if (pid < 0) {
            perror("[HATA] fork hatasi");
            exit(1);
        }

        if (pid == 0) {
            kat_insa_et(kat);
        } else {
            wait(NULL);
        }
    }

    sem_close(vinc);
    sem_unlink(SEM_VINC);

    printf("\nApartman insaati basariyla tamamlandi.\n");
    return 0;
}
