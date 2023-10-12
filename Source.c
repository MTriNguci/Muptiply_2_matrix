#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// #include <windows.h>
int main() {
    FILE* file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Không thể mở file input.txt\n");
        return 1;
    }
   
    int m, n, p;
    fscanf(file, "%d %d %d", &n, &m, &p);

    int** a = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++)
        a[i] = (int*)malloc(m * sizeof(int));

    int** b = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++)
        b[i] = (int*)malloc(p * sizeof(int));

    int** ans = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++)
        ans[i] = (int*)malloc(p * sizeof(int));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            fscanf(file, "%d", &a[i][j]);

    for (int i = 0; i < m; i++)
        for (int j = 0; j < p; j++)
            fscanf(file, "%d", &b[i][j]);

    fclose(file);



struct timespec start, end;
clock_gettime(CLOCK_MONOTONIC_RAW, &start);
    
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            ans[i][j] = 0;
            for (int k = 0; k < m; k++)
                ans[i][j] += a[i][k] * b[k][j];
        }
    }

//     QueryPerformanceCounter(&end);
//     interval = ((double)end.QuadPart - start.QuadPart) / frequency.QuadPart;
 clock_gettime(CLOCK_MONOTONIC_RAW, &end);
 double interval = (float)end.tv_sec - (float)start.tv_sec + 1e-9*(end.tv_nsec - start.tv_nsec);

//     printf("time use : %.2f micro sec\n", interval * 1000000);
 printf("%.10f\n", interval); 

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < p; j++)
//         {
//             printf("%d ", ans[i][j]);
//         }
//         printf("\n");
//     }


    // Giải phóng bộ nhớ
    for (int i = 0; i < n; i++) {
        free(a[i]);
        free(ans[i]);
    }
    free(a);
    free(ans);

    for (int i = 0; i < m; i++)
        free(b[i]);
    free(b);

    return 0;
}
