#include <stdio.h>

struct Student {
    char name[100];
    float math;
    float physics;
    float chemistry;
};

int main() {
    int N;
    printf("Enter the number of students: ");
    scanf("%d", &N);
    
    struct Student students[N];
    
    // Input student records
    for (int i = 0; i < N; i++) {
        printf("Enter name and marks for student %d: ", i + 1);
        scanf("%s %f %f %f", students[i].name, &students[i].math, &students[i].physics, &students[i].chemistry);
    }
    
    char studentName[100];
    printf("Enter the name of the student to find average marks: ");
    scanf("%s", studentName);
    
    float averageMarks = -1;
    // Calculate average marks
    for (int i = 0; i < N; i++) {
        int j = 0;
        int found = 1;
        while (studentName[j] != '\0' && students[i].name[j] != '\0') {
            if (studentName[j] != students[i].name[j]) {
                found = 0;
                break;
            }
            j++;
        }
        if (found && studentName[j] == '\0' && students[i].name[j] == '\0') {
            averageMarks = (students[i].math + students[i].physics + students[i].chemistry) / 3;
            break;
        }
    }
    
    if (averageMarks != -1) {
        printf("Average marks for %s: %.2f\n", studentName, averageMarks);
    } else {
        printf("Student not found!\n");
    }
    
    return 0;
}
