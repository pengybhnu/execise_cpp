#include <stdio.h>
#include <pthread.h>

// Function to be executed by the new thread
void* thread_function(void* arg) {
    int thread_arg = *((int*)arg);
    printf("Hello from the thread! Argument: %d\n", thread_arg);
    pthread_exit(NULL);
}
int m;
char f;
int main() {
    printf("m default value: %d\n", m);
    printf("f default value: %d\n", f);
    char ff = 'i';
    printf("ff default value: %d\n", ff);
    pthread_t thread_id;
    int arg = 42;

    // Create a new thread
    int result = pthread_create(&thread_id, NULL, thread_function, &arg);
    if (result != 0) {
        printf("Error creating thread. Code: %d\n", result);
        return 1;
    }

    // Wait for the thread to finish
    result = pthread_join(thread_id, NULL);
    if (result != 0) {
        printf("Error joining thread. Code: %d\n", result);
        return 1;
    }

    printf("Thread finished execution\n");
    return 0;
}