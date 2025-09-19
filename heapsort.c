/*
 * Objetivo: Completar las funciones Max-Heapify, Build-Max-Heap y Heap-Sort.
 * Entradas (stdin):
 *   n

 *   a1 a2 ... an

 * Salida (stdout):
 *   a1 a2 ... an  // en orden ascendente
 */

#include <stdio.h>
#include <stdlib.h>

/* PROTOTIPOS: NO CAMBIAR LAS FIRMAS */
void max_heapify(int a[], int n, int i);
void build_max_heap(int a[], int n);
void heap_sort(int a[], int n);

/* MAIN de prueba mínima */
int main(void) {
    int n; if (scanf("%d", &n) != 1 || n <= 0) return 0;
    int *a = (int*)malloc(sizeof(int) * n);
    if (!a) return 0;
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

    heap_sort(a, n);

    for (int i = 0; i < n; ++i) {
        if (i) putchar(' ');
        printf("%d", a[i]);
    }
    putchar(' ');

    free(a);
    return 0;
}

/* IMPLEMENTAR AQUÍ */
void max_heapify(int a[], int n, int i) {
    /* TODO */
    int mayor = i;
    int izq = 2 * i + 1; //Rama izquierda
    int der = 2 * i + 2;//Rama derecha
    
    if(izq < n && a[izq] > a[mayor]){
        mayor = izq;
    }
    if(der < n && a[der] > a[mayor]){
        mayor = der;
    }
    
    if(mayor != i){
        int temp = a[i];
        a[i] = a[mayor];
        a[mayor] = temp;
        max_heapify(a, n, mayor);
    }
}

void build_max_heap(int a[], int n) {
    /* TODO */
    //Consttruccion del heap
    for(int i = n /2 - 1; i >= 0; i--){
        max_heapify(a, n, i);
    }
}

void heap_sort(int a[], int n) {
    /* TODO */
    //Construimos el heap
    build_max_heap(a, n);
    
    for (int i = n-1; i > 0 ; i--) {
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        
        max_heapify(a, i, 0);
    }
            
}
