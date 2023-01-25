#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data {
    char nama[100];
    int nim;
    struct data *next;
} *current, *head, *tail;

void menambah(char nama[100], int nim);

void menghapusdata();

void mencetak();

int main() {
    int menu;
    char nama[100];
    int nim;

    printf("Program Data Mahasiswa\n");
    do {
        printf("Menu :\n");
        printf("1.\tTambah Data\n");
        printf("2.\tProses Data\n");
        printf("3.\tLihat Data\n");
        printf("4.\tKeluar Program\n");
        printf("Masukkan pilihan :");
        scanf("%i", &menu);
        getchar();
        switch (menu) {
            case 1:
                printf("Nama :");
                gets(nama);
                printf("NIM :");
                scanf("%i", &nim);
                menambah(nama, nim);
                break;
            case 2:
                menghapusdata();
                break;
            case 3:
                mencetak();
                break;
            case 4:
                break;
            default:
                printf("Masukkan Pilihan yang Benar !!\n");
        }
    } while (menu!= 4);
}

void mencetak() {
    printf("Data Mahasiswa :\n");
    struct data *temp;
    temp = head;
    while (temp != NULL){
        printf("Nama : %s\n", temp->nama);
        printf("NIM : %i\n", temp->nim);
        temp = temp ->next;
    }
}

void menghapusdata() {
    if (head == NULL){
        printf("No data");
    } else if (head == tail){
        free(head);
        head = tail =NULL;
    } else {
        struct data *temp;
        temp = head;
        while (temp->next != tail){
            temp = temp->next;
        }
        free(tail);
        tail = temp;
        tail->next = NULL;
    }
}

void menambah(char nama[100], int nim) {
    current = malloc (sizeof (struct data));
    strcpy(current->nama, nama);
    current->nim = nim;

    if (head == NULL){
        head = tail = current;
    }else{
        tail -> next = current;
        tail = current;
    }
    tail -> next = NULL;

}