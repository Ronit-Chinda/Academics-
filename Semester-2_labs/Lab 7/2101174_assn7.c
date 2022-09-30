#include <stdio.h>
#include <stdlib.h>

struct student
{
    int Rollno;
    int defenceAgainstTheDarkArts;
    int Charms;
    int Potion;
};
struct PDE
{
    int Rollno;
    int defenceAgainstTheDarkArts;
    int Charms;
};
struct student Createstudentdata(int rollNo, int defenceAgainstTheDarkArts, int Charms, int Potion)
{
    struct student newStudent;
    newStudent.Rollno = rollNo;
    newStudent.defenceAgainstTheDarkArts = defenceAgainstTheDarkArts;
    newStudent.Charms = Charms;
    newStudent.Potion = Potion;
    return newStudent;
}
struct PDE generatePDEData(struct student student)
{
    struct PDE newPDEStudent;
    newPDEStudent.Rollno = student.Rollno;
    newPDEStudent.defenceAgainstTheDarkArts = student.defenceAgainstTheDarkArts;
    newPDEStudent.Charms = student.Charms;
    return newPDEStudent;
}

//              Utilities
int checkPDE(struct student student)
{
    if (student.defenceAgainstTheDarkArts < 40 && student.Charms > 70)
    {

        return 1;
    }
    return 0;
}
int CheckRollno(int rollno)
{
    int validRoll[] = {10, 11, 12, 13};
    int flag = 0;
    for (int i = 0; i < 4; i++)
    {
        if (validRoll[i] == rollno)
        {
            flag = 1;
            break;
        }
    }
    return flag;
}
int getSize(FILE *records)
{
    if (records == NULL)
    {
        printf("File doesn't exist\n");
        return 0;
    }
    else
    {
        char ch;
        char number[100];
        int c = 0;
        fscanf(records, "%s", number);
        return atoi(number);
    }
}
char *getHouse(int houseCode)
{
    char *house;
    if (houseCode == 10)
    {
        house = "Gryffindor";
    }
    else if (houseCode == 11)
    {
        house = "HufflePuff";
    }
    else if (houseCode == 12)
    {
        house = "Ravenclaw";
    }
    else if (houseCode == 13)
    {
        house = "Slytherine";
    }
    return house;
}
//              Printing
void printStudent(struct student student)
{
    char *house = getHouse((student.Rollno) / 10000);
    printf("%d %s %d(001) %d(002) %d(003)\n", student.Rollno, house, student.defenceAgainstTheDarkArts, student.Charms, student.Potion);
}
void printPDE(struct PDE student)
{
    char *house = getHouse((student.Rollno) / 10000);
    printf("PDE  %d %s %d(001) %d(002)\n", student.Rollno, house, student.defenceAgainstTheDarkArts, student.Charms);
}
void printrecord(struct student studentRecord[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printStudent(studentRecord[i]);
    }
}
void printPDERecord(struct PDE PDERecord[], int size)
{
    for (int i = 0; i < size; i++)
    {
        char *house = getHouse((PDERecord[i].Rollno) / 10000);
        printf("PDE  %d %s %d(001) %d(002)\n", PDERecord[i].Rollno, house, PDERecord[i].defenceAgainstTheDarkArts, PDERecord[i].Charms);
    }
}
void print(struct student studentRecord[], int studentCount, struct PDE PDERecord[], int PDECount)
{

    printf("1 - PrintStudentDatabase()\n");
    printf("2 - PrintPDEDatabase()\n");
    printf("3 - ExitToMain-Menu()\n");

    int Choice;
    scanf("%d", &Choice);
    if (Choice == 1)
    {
        printrecord(studentRecord, studentCount);
    }
    else if (Choice == 2)
    {
        printPDERecord(PDERecord, PDECount);
    }
    else if (Choice == 3)
    {
    }
    else
    {
        printf("Invalid Choice!\n");
    }
}
//          Sorting
//          Swapping

void studentSwap(struct student studentRecord[], int first, int second)
{
    struct student temp = studentRecord[first];
    studentRecord[first] = studentRecord[second];
    studentRecord[second] = temp;
}
void PDESwap(struct PDE studentRecord[], int first, int second)
{
    struct PDE temp = studentRecord[first];
    studentRecord[first] = studentRecord[second];
    studentRecord[second] = temp;
}

//          Choice1uickSort
int partition(struct student studentRecord[], int lowerBound, int upperBound)
{
    int pivot = studentRecord[lowerBound].Rollno;
    int left = lowerBound + 1;
    int right = upperBound;
    while (left < right)
    {
        while (studentRecord[right].Rollno > pivot)
        {
            right--;
        }
        while (studentRecord[left].Rollno <= pivot)
        {
            left++;
        }
        if (left < right)
        {
            studentSwap(studentRecord, left, right);
        }
    }
    studentSwap(studentRecord, lowerBound, right);
    return right;
}

void Choice1uickSort(struct student studentRecord[], int lowerBound, int upperBound)
{
    if (lowerBound < upperBound)
    {
        int pivot = partition(studentRecord, lowerBound, upperBound);
        Choice1uickSort(studentRecord, lowerBound, pivot - 1);
        Choice1uickSort(studentRecord, pivot + 1, upperBound);
    }
}

//          InsertionSort
void studentInsertionSort(struct student studentRecord[], int size)
{
    for (int m = 1; m < size; m++)
    {
        int j = m;
        int i = m - 1;
        while (i >= 0 && studentRecord[i].Rollno > studentRecord[j].Rollno)
        {
            studentSwap(studentRecord, i--, j--);
        }
    }
}
void PDEInsertionSort(struct PDE studentRecord[], int size)
{
    for (int m = 1; m < size; m++)
    {
        int j = m;
        int i = m - 1;
        while (i >= 0 && studentRecord[i].Rollno > studentRecord[j].Rollno)
        {
            PDESwap(studentRecord, i--, j--);
        }
    }
}

//          BinarySearch
struct student binarySearch(struct student studentRecord[], int left, int right, int keyRollno)
{
    if (right < left)
    {
        struct student empty;
        return empty;
    }

    int mid = left + (right - left) / 2;

    if (studentRecord[mid].Rollno == keyRollno)
    {
        return studentRecord[mid];
    }

    if (studentRecord[mid].Rollno < keyRollno)
    {
        return binarySearch(studentRecord, mid + 1, right, keyRollno);
    }

    return binarySearch(studentRecord, left, mid - 1, keyRollno);
}

//          Adding New Students
struct student addRecord(struct student studentRecord[], int size, int *flag)
{
    int rollNo, datda, Potion, Charms;
    printf("\nEnter Roll No.(Enter -1 to exit and go back to main menu) :");
    scanf("%d", &rollNo);
    if (rollNo == -1)
    {
        *flag = 1;
        struct student empty;
        return empty;
    }
    if (CheckRollno(rollNo / 10000) == 0)
    {
        printf("Invalid Roll No.\n");
        struct student empty;
        return empty;
    }
    struct student found = binarySearch(studentRecord, 0, size - 1, rollNo);

    if (found.Rollno != 0)
    {
        printf("Roll no. already present in database!\n");
        struct student empty;
        return empty;
    }
    printf("\nMarks in Defence againt the Dark Arts :");
    scanf("%d", &datda);
    printf("\nMarks in Potion :");
    scanf("%d", &Potion);
    printf("\nMarks in Charms:");
    scanf("%d", &Charms);
    struct student newStudent = Createstudentdata(rollNo, datda, Charms, Potion);
    return newStudent;
}

int main()
{
    FILE *records = fopen("records.txt", "r");
    int studentCount = getSize(records);
    if (studentCount)
    {
        struct student studentRecord[100];
        struct PDE PDERecord[100];

        int count = 0;
        int PDECount = 0;

        while (count < studentCount)
        {
            char rollChar[6], datda[3], CharmsStr[3], PotionStr[3];
            fscanf(records, "%s %s %s %s", rollChar, datda, CharmsStr, PotionStr);
            int rollNo = atoi(rollChar);
            if (CheckRollno(rollNo / 10000))
            {
                struct student newStudent = Createstudentdata(rollNo, atoi(datda), atoi(CharmsStr), atoi(PotionStr));
                if (checkPDE(newStudent))
                {
                    struct PDE newPDEStudent = generatePDEData(newStudent);
                    PDERecord[PDECount++] = newPDEStudent;
                }
                studentRecord[count++] = newStudent;
            }
            else
            {
                printf("Invalid Roll no. %d\n", rollNo);
                studentCount--;
            }
        }

        Choice1uickSort(studentRecord, 0, studentCount - 1);
        PDEInsertionSort(PDERecord, PDECount);
        printrecord(studentRecord, studentCount);

        while (1)
        {
            printf("1 - Sort()\n");
            printf("2 - Add-three-Students()\n");
            printf("3 - SearchBy-RollNo()\n");
            printf("4 - Print()\n");
            printf("5 - Exit()\n");

            int Choice1;
            scanf("%d", &Choice1);
            if (Choice1 == 1)
            {
                Choice1uickSort(studentRecord, 0, studentCount - 1);
            }
            else if (Choice1 == 2)
            {
                int flag = 0;
                for (int i = 1; i <= 3; i++)
                {
                    struct student newStudent = addRecord(studentRecord, studentCount, &flag);
                    if (flag)
                    {
                        break;
                    }
                    if (newStudent.Rollno != 0)
                    {
                        if (checkPDE(newStudent))
                        {
                            struct PDE newPDEStudent = generatePDEData(newStudent);
                            PDERecord[PDECount++] = newPDEStudent;
                            printf("Potential Death Eater detected... adding to PDERecord\n");
                        }
                        studentRecord[studentCount++] = newStudent;
                    }
                    else
                    {
                        i--;
                    }
                }
                studentInsertionSort(studentRecord, studentCount);
                PDEInsertionSort(PDERecord, PDECount);
            }
            else if (Choice1 == 3)
            {
                int roll;
                printf("Enter Roll-Number:\n");
                scanf("%d", &roll);

                struct student QueriedStudent = binarySearch(studentRecord, 0, studentCount - 1, roll);

                if (QueriedStudent.Rollno != 0)
                {
                    printStudent(QueriedStudent);
                }
                else
                {
                    printf("No such student in database!\n");
                }
            }

            else if (Choice1 == 4)
            {
                print(studentRecord, studentCount, PDERecord, PDECount);
            }

            else if (Choice1 == 5)
            {
                break;
            }

            else
            {
                printf("Invalid choice!\n");
            }
        }
    }
}
