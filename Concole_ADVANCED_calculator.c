#include<stdio.h>
#include<math.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>

#define HISTORY_FILE "calc_history.txt"
#define MAX_LINE 512
#define EPS 1e-12
const double pi = 3.14159265358979323846;

void add_history(const char *text) {
    if (!text) return;
    FILE *f = fopen(HISTORY_FILE, "a");
    if (!f) return;  

    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    char timestr[32];
    strftime(timestr, sizeof(timestr), "%Y-%m-%d %H:%M:%S", tm);

    fprintf(f, "[%s] %s\n", timestr, text);
    fclose(f);
}

void show_history(void) {
    FILE *f = fopen(HISTORY_FILE, "r");
    if (!f) {
        printf("No history saved yet.\n");
        return;
    }
    char line[MAX_LINE];
    printf("\n===== Saved History =====\n");
    while (fgets(line, sizeof(line), f)){
        printf("%s", line);
    }
    printf("===== End of History =====\n\n");
    fclose(f);
}

void arithmetic();
void addition(int size);
void subtraction(int size);
void product(int size);
void division(float dividend, float divisor);
void remainder_calc(int a, int b);
void Matrix();
int addMatrix(int matrix1[10][10], int matrix2[10][10], int r1, int c1);
int subtMatrix(int matrix1[10][10], int matrix2[10][10], int r1, int c1);
int multiMatrix(int matrix1[10][10], int matrix2[10][10], int r1, int c1, int c2);
int determinate(int matrix1[10][10], int r1);
void unitConversion();
float Length_Converator();
float Temperature_Converator();
float scientific();
float trignometric();
float square_root();
float logarthmic();
double Quadratic_Equation_Solver();
double power();

void look(){
    int c;
    printf("\nPress Enter to continue...");
    while ((c = getchar()) != '\n' && c != EOF);
    getchar();
    system("cls");
}

int main(){
    int choice;

    while(1){
        printf("\n=============================================\n\t     Advanced Calculator\n=============================================\n");
        printf("1) Basic Arithmetic Operations.\n2) Scientific Operations\n3) Matrix Operations");
            printf("\n4) Quadratic Equation Solver.\n5) Units Conversion.\n6) Watch Hitory\n7) Exit.\n");
            printf("---------------------------------------------");
            printf("\nEnter choice: ");
            if (scanf(" %d",&choice) != 1) {
                int _c; while ((_c = getchar()) != '\n' && _c != EOF);
                printf("Invalid choice... enter a number.\n");
                continue;
            }

            switch(choice){
                case 1:
                arithmetic(); look(); break;
                case 2:
                scientific(); look(); break;
                case 3:
                Matrix(); look(); break;
                case 4:
                Quadratic_Equation_Solver(); look(); break;
                case 5:
                unitConversion(); look(); break;
                case 6:
                show_history(); look(); break;
                case 7:
                return 0;
                default:
                printf("Wrong Choice.\n"); look();
            }
    }
    return 0;
}

void arithmetic(){
    int choice1, size, div, divs;
    float dividend, divisor;
    char c;
    while(1){
    printf("\n=============================================\n\t     Arithmetic Operations\n=============================================\n");
    printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Remainder\n6)Exit this mode.");
    printf("\n---------------------------------------------\nEnter Choice: ");
    if (scanf(" %d",&choice1) != 1) {
        int _c; while ((_c = getchar()) != '\n' && _c != EOF);
        printf("Invalid input... enter a number 1..6.\n");
        continue;
    }
    if(choice1<1 || choice1>6){printf("Invalid input... enter a number 1..6.\n"); continue;}
    if (choice1 == 6) return;
    else if(choice1 != 4 && choice1 != 5){
    printf("How many numbers will you compute: ");
        if (scanf(" %d",&size) != 1) {
            int _c; while ((_c = getchar()) != '\n' && _c != EOF);
            printf("Invalid number... enter an integer.\n");
            continue;
        }
    }

    switch(choice1){
        case 1:
        if(size>0 && size<=100){
        addition(size); look(); break;}
        else
        printf("Invalid input: try again"); continue;

        case 2:
        if(size>0 && size<=100){
        subtraction(size);look(); break;}
        else
        printf("Invalid input: try again"); continue;

        case 3:
        if(size>0 && size<=100){
        product(size); look(); break;}
        else
        printf("Invalid input: try again\n"); continue;

        case 4:
        printf("Enter Dividend: ");
        if (scanf(" %f",&dividend) != 1) { int _c; while ((_c=getchar())!='\n' && _c!=EOF); printf("\nInvalid number.\n"); continue; }
        printf("\nEnter Divisor: ");
        if (scanf(" %f",&divisor) != 1) { int _c; while ((_c=getchar())!='\n' && _c!=EOF); printf("\nInvalid number.\n"); continue; }
        division(dividend, divisor); look();
        break;
        
        case 5:
        printf("Enter Dividend: ");
        if (scanf(" %d",&div) != 1) { int _c; while ((_c=getchar())!='\n' && _c!=EOF); printf("\nInvalid number.\n"); continue; }
        printf("\nEnter Divisor: ");
        if (scanf(" %d",&divs) != 1) { int _c; while ((_c=getchar())!='\n' && _c!=EOF); printf("\nInvalid number.\n"); continue; }
        remainder_calc(div,divs); look(); break;
        case 6:
        return;
        default:
        printf("\nInvalid input."); look(); break;
    }
    }
}

void addition(int size){
    float arr[size]; float sum=0.0;
    int i;
    for(i=0; i<size; i++){
        printf("Enter number %d: ",i+1);
        if (scanf(" %f",&arr[i]) != 1) { int _c; while ((_c = getchar()) != '\n' && _c != EOF); printf("\nInvalid number... try that element again.\n"); --i; continue; }
        sum+=arr[i];
    }
    printf("Sum of numbers is: %.4f",sum);
    char h[128];
    snprintf(h, sizeof(h), "Addition: sum = %.4f", sum);
    add_history(h);
}

void subtraction(int size){
    int i=0;
    float arr[size]; float subt;
        printf("Enter number %d:",i+1);
        scanf(" %f",&arr[0]);
        subt=arr[0];
        for (i=1; i<size; ++i) {
            printf("Enter number %d:",i+1);
            if (scanf(" %f",&arr[i]) != 1) { int _c; while ((_c = getchar()) != '\n' && _c != EOF); printf("\nInvalid number... try that element again.\n"); --i; continue; }
            subt -= arr[i];
        }
        
    printf("\nSubtraction of numbers is: %.4f",subt);
    char h[128];
    snprintf(h, sizeof(h), "Subtraction result = %.4f", subt);
    add_history(h);
}

void product(int size){
	  int i ;
    float arr[size]; float prod=1.0;
    for( i=0; i<size; i++){
        printf("Enter number %d:",i+1);
        if (scanf(" %f",&arr[i]) != 1) { int _c; while ((_c = getchar()) != '\n' && _c != EOF); printf("\nInvalid number... try that element again.\n"); --i; continue; }
        prod*=arr[i];
    }
    printf("Product of numbers is: %.4f",prod);
    char h[128];
    snprintf(h, sizeof(h), "Product = %.4f", prod);
    add_history(h);
}

void division(float a,float b){
    if ( b == 0){
        printf("Undefined (Math Error)");
        add_history("Division: error... division by zero");
    }
    else {
        float divi =  a / b ;
        printf("Division of numbers is: %.4f", divi );
        char h[128];
        snprintf(h, sizeof(h), "Division: %.4f / %.4f = %.4f", a, b, a / b);
        add_history(h);
  }
}

void remainder_calc(int a, int b){
    int rem;
    if (b == 0){
        printf("Undefined (Math Error)");
        add_history("Remainder: error... division by zero");
    }
    else {
        rem = a%b ;
        printf("Remainder is: %d", rem);
        char h[128];
        snprintf(h, sizeof(h), "Remainder: %d %% %d = %d", a, b, rem);
        add_history(h);
    }
}

void Matrix(){
    int choice;
    int r1, r2, c1, c2, i, j;
    int matrix1[10][10], matrix2[10][10];
    while(1){
        printf("\n=============================================\n\t\tMatrices\n=============================================\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Determinant\n");
        printf("5. Exit Matrix Mode\n");
        printf("---------------------------------------------");
        printf("\nEnter Choice : ");
        if (scanf("%d", &choice) != 1) { int _c; while((_c=getchar())!='\n' && _c!=EOF); printf("\nInvalid choice\n"); continue; }
        if( choice >= 1 && choice <= 4){        
             printf("Enter rows: ");
             if (scanf("%d", &r1) != 1) { int _c; while((_c=getchar())!='\n' && _c!=EOF); printf("\nInvalid rows\n"); continue; }
             printf("Enter columns: ");
             if (scanf("%d", &c1) != 1) { int _c; while((_c=getchar())!='\n' && _c!=EOF); printf("\nInvalid columns\n"); continue; }
        }
        if(choice == 4){
            if(r1 == c1 && (r1 == 2  || r1 == 3)){
            printf("\n\nEnter Matrix: \n");
            for (i = 0; i < r1; i++){
                printf("\nEnter Row %d elements:\n",i+1);
                for(j = 0; j < c1; j++){
                    printf("Enter [%d][%d] element: ",i+1,j+1);
                    if (scanf(" %d", &matrix1[i][j]) != 1) { int _c; while((_c=getchar())!='\n' && _c!=EOF); printf("\nInvalid element... re-enter.\n"); --j; continue; }
                }
            }
        }
        else{
            printf("\nError: Wrong Matrices Dimensions\n");
                continue;
        }
    }
        else if (choice == 1 || choice == 2 || choice == 3){
            printf("\nEnter Matrix 1: \n");
            for ( i = 0; i < r1; i++){
                printf("\nEnter Row %d elements: \n",i+1);
                for(j = 0; j < c1; j++){
                    printf("Enter [%d][%d] element: ",i+1,j+1);
                    if (scanf(" %d", &matrix1[i][j]) != 1) { int _c; while((_c=getchar())!='\n' && _c!=EOF); printf("\nInvalid element... re-enter.\n"); --j; continue; }
                }
            }
            printf("\nEnter rows of other Matrix : ");
            if (scanf(" %d", &r2) != 1) { int _c; while((_c=getchar())!='\n' && _c!=EOF); printf("\nInvalid rows\n"); continue; }
            printf("Enter columns of other Matrix: ");
            if (scanf("%d", &c2) != 1) { int _c; while((_c=getchar())!='\n' && _c!=EOF); printf("\nInvalid columns\n"); continue; }
            if ((choice != 3 && (r1 != r2 || c1 != c2))  ||  (choice == 3  && c1 != r2)){                    
                printf("\nError: Wrong Matrices Dimensions\n");
                continue;
            }
            printf("\nEnter Matrix 2: \n");
                for ( i = 0; i < r2; i++){
                    printf("\nEnter Row %d elements: \n",i+1);
                    for( j = 0; j < c2; j++){
                        printf("Enter [%d][%d] element: ",i+1,j+1);
                        if (scanf(" %d", &matrix2[i][j]) != 1) { int _c; while((_c=getchar())!='\n' && _c!=EOF); printf("\nInvalid element... re-enter.\n"); --j; continue; }
            }
            }
        }
        switch(choice){
        case 1:
           addMatrix(matrix1, matrix2, r1, c1); look();
            break;

        case 2:
           subtMatrix(matrix1, matrix2, r1, c1); look();
            break;

        case 3:
           multiMatrix(matrix1, matrix2, r1, c1, c2); look();
            break;

        case 4:
           determinate(matrix1, r1); look();
            break;
        
            case 5:
              printf("Matrix Mode Exited\n"); look();
            return;

        default: 
            printf("Invalid Input Try Again!\n"); look();
            continue;
        }
    }
}
int addMatrix(int matrix1[10][10], int matrix2[10][10], int r1, int c1){
    int matrix3[10][10];
    int i, j ;
    printf("\nMatrices Additon = \n");
    for( i = 0; i < r1 ; i++){
        for( j = 0; j < c1; j++){
            matrix3[i][j] = matrix1[i][j] + matrix2[i][j];
            printf("%d ", matrix3[i][j]);
        }
        printf("\n");
    }
    char header[200];
    snprintf(header, sizeof(header), "MATRIX: A + B (%dx%d) result:", r1, c1);
    add_history(header);

    for ( i = 0; i < r1; ++i) {
    char rowbuf[200] = "";
    for ( j = 0; j < c1; ++j) {
        char cell[16];
        snprintf(cell, sizeof(cell), "%d ", matrix3[i][j]);
        strncat(rowbuf, cell, sizeof(rowbuf) - strlen(rowbuf) - 1);
    }
    add_history(rowbuf);
}

    return 0;
}

int subtMatrix(int matrix1[10][10], int matrix2[10][10], int r1, int c1){
    int matrix3[10][10] ;
    int i , j;
    printf("\nMatrices Subtraction = \n");
    for( i = 0; i < r1 ; i++){
        for(j = 0; j < c1; j++){
            matrix3[i][j] = matrix1[i][j] - matrix2[i][j];
            printf("%d ", matrix3[i][j]);
        }
        printf("\n");
    }
    char header[200];
    snprintf(header, sizeof(header), "MATRIX: A - B (%dx%d) result:", r1, c1);
    add_history(header);

    for ( i = 0; i < r1; ++i) {
    char rowbuf[200] = "";
    for (j = 0; j < c1; ++j) {
        char cell[16];
        snprintf(cell, sizeof(cell), "%d ", matrix3[i][j]);
        strncat(rowbuf, cell, sizeof(rowbuf) - strlen(rowbuf) - 1);
    }
    add_history(rowbuf);
  }
  return 0;
}

int multiMatrix(int matrix1[10][10], int matrix2[10][10], int r1, int c1, int c2){
    int matrix3[10][10] ;
    int i, j , k;
    printf("\nMatrices Multiplication = \n");
    for(i = 0; i < r1 ; i++){
        for( j = 0; j < c2; j++){
             matrix3[i][j] = 0;
            for( k = 0; k < c1; k++){       
            matrix3[i][j] += matrix1[i][k]*matrix2[k][j];
        }
        printf("%d ", matrix3[i][j]);
    }
     printf("\n");
}
    char header[200];
    snprintf(header, sizeof(header), "MATRIX: A x B (%dx%d) result:", r1, c2);
    add_history(header);

    for ( i = 0; i < r1; ++i) {
    char rowbuf[200] = "";
    for ( j = 0; j < c2; ++j) {
        char cell[16];
        snprintf(cell, sizeof(cell), "%d ", matrix3[i][j]);
        strncat(rowbuf, cell, sizeof(rowbuf) - strlen(rowbuf) - 1);
    }
    add_history(rowbuf);
    }
 return 0;
}

int determinate(int matrix1[10][10], int r1){
    int determ = 0;
    if (r1 == 2){
        determ = matrix1[0][0]*matrix1[1][1] - matrix1[0][1]*matrix1[1][0];
    }
    else if (r1 == 3){
        determ =  (matrix1[0][0]*matrix1[1][1]*matrix1[2][2]) +  (matrix1[0][1]*matrix1[1][2]*matrix1[2][0]) +  (matrix1[0][2]*matrix1[1][0]*matrix1[2][1]);
        determ -= ( (matrix1[0][2]*matrix1[1][1]*matrix1[2][0]) +  (matrix1[0][0]*matrix1[1][2]*matrix1[2][1]) +  (matrix1[0][1]*matrix1[1][0]*matrix1[2][2]));
    }
    printf("Determinant = %d\n", determ);
    char h[100];
    snprintf(h, sizeof(h), "Determinant (%dx%d) = %d", r1, r1, determ);
    add_history(h);
    return 0;
}                   

void unitConversion(){
    int choice;
     while(1){
        printf("\n=============================================\n\t     Unit Conversion\n=============================================\n");
        printf("\n1. Length Conversion\n");
        printf("2. Temperature Conversion\n");
        printf("3. Exit Unit Conversion Mode\n");
        printf("---------------------------------------------");
        printf("\nChoice : ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
            Length_Converator(); look();
            break;

            case 2:
             Temperature_Converator(); look();
            break;

            case 3:
            printf("Unit Conversion Mode Exited\n"); look();
            return;

            default:
            printf("Wrong Choice Try Again\n"); look();
            continue;
        }
     }
}

float Length_Converator(){
    int choice ;
    float result, value = 0;
    char h[120];
    while(1){
        printf("\n=============================================\n\t     Length Convertor\n=============================================\n");
        printf("1. Meters to Kilometers\n");
        printf("2. Kilometers to Meters\n"); printf("3. Centimeters to Meters\n");
        printf("4. Meters to Centimeters\n"); printf("5. Inches to Centimeters\n");
        printf("6. Centimeters to Inches\n"); printf("7. Feet to Meters\n");
        printf("8. Meters to Feet\n"); printf("9. Miles to Kilometers\n");
        printf("10. Kilometers to Miles\n"); printf("11. Exit form Length mode\n");
        printf("---------------------------------------------");
        printf("\nChoice = ");
        scanf("%d", &choice);

        if (choice > 0 && choice <=10){
        printf("Enter the number = "); 
        if (scanf("%f", &value) != 1) { int _c; while((_c=getchar())!='\n' && _c!=EOF); printf("\nInvalid number... try again.\n"); continue; }
        }
        
        else if(choice == 11){
            printf("\n---Length Mode Exited---\n");
            return 0;
        }
        else{
            printf("Wrong Choice Try Again\n");
            continue;
        }
        
    switch(choice){
        case 1: result = value / 1000.0;
        printf("%.2fm = %.3fkm\n",value, result); snprintf(h, sizeof(h), "Unit: %.4f m = %.4f km", value, result); add_history(h); look();
        break;

        case 2: result = value * 1000.0;
        printf("%.2fkm = %.3fm\n",value, result); snprintf(h, sizeof(h), "Unit: %.4f km = %.4f m", value, result); add_history(h); look();
        break; 

        case 3: result = value / 100.0; 
        printf("%.2fcm = %.3fm\n",value, result); snprintf(h, sizeof(h), "Unit: %.4f cm = %.4f m", value, result); add_history(h); look();
        break; 

        case 4: result = value * 100.0; 
        printf("%.2fm = %.3fcm\n",value, result); snprintf(h, sizeof(h), "Unit: %.4f m = %.4f cm", value, result); add_history(h); look();
        break;

        case 5: result = value * 2.54;  
        printf("%.2fin = %.3fcm\n",value, result); snprintf(h, sizeof(h), "Unit: %.4f in = %.4f cm", value, result); add_history(h); look();
        break; 

        case 6: result = value / 2.54; 
        printf("%.2fcm = %.3fin\n",value, result); snprintf(h, sizeof(h), "Unit: %.4f cm = %.4f in", value, result); add_history(h); look();
        break; 

        case 7: result = value * 0.3048; 
        printf("%.2fft = %.3fm\n",value, result); snprintf(h, sizeof(h), "Unit: %.4f f = %.4f m", value, result); add_history(h); look();
        break;  

        case 8: result = value / 0.3048; 
        printf("%.2fm = %.3fft\n",value, result); snprintf(h, sizeof(h), "Unit: %.4f m = %.4f ft", value, result); add_history(h); look();
        break; 

        case 9: result = value * 1.60934; 
        printf("%.2fmi = %.3fkm\n",value, result); snprintf(h, sizeof(h), "Unit: %.4f mi = %.4f km", value, result); add_history(h); look();
        break;  

        case 10: result = value / 1.60934;
        printf("%.2fkm = %.3fmi\n",value, result); snprintf(h, sizeof(h), "Unit: %.4f km = %.4f mi", value, result); add_history(h); look();
        break;

        case 11:
        return 0;
    }
}
}

float Temperature_Converator(){
    int choice;
    float temp = 0.0;
    float result ;
    char h[120];
    while(1){
        printf("\n=============================================\n\t     Temperature Convertor\n=============================================\n");
        printf("\n1. Celsius to Fahrenheit");
        printf("\n2. Fahrenheit to Celsius");
        printf("\n3. Celsius to Kelvin ");
        printf("\n4. Kelvin to Celsius");
        printf("\n5. Fahrenheit to Kelvin");
        printf("\n6. Kelvin to Fahrenheit");
        printf("\n7. Exit The Temperature Mode\n");
        printf("---------------------------------------------");
        printf("\nChoice : ");
        scanf("%d", &choice);
        if( choice > 0 && choice <=6 ){
             printf("Enter Temperature : ");
            if (scanf("%f", &temp) != 1) { int _c; while((_c=getchar())!='\n' && _c!=EOF); printf("\nInvalid number... try again.\n"); continue; }
        } 

        else if( choice == 7 ){
            printf("\n---Temperature Mode Exited---\n"); look();
            return 0;
        }

        else{
            printf("\nWrong Choice Try Again!\n"); look();
            continue;
        }
        
        switch(choice){
            case 1: result = (temp * 9.0/5.0  + 32.0) ;
            printf("Celsius to Fahrenheit = %.3f\n" , result); snprintf(h, sizeof(h), "Unit: %.4f m = %.4f km", temp, result); add_history(h); look();
            break;

            case 2: result = (temp -32.0)*5.0/9.0 ;
            printf("Fahrenheit to Celsius = %.3f\n", result); snprintf(h, sizeof(h), "Unit: %.4f m = %.4f km", temp, result); add_history(h); look();
            break;

            case 3: result = (temp + 273.15);
            printf("Celsius to Kelvin  = %.3f\n", result); snprintf(h, sizeof(h), "Unit: %.4f m = %.4f km", temp, result); add_history(h); look();
            break;

            case 4: result = (temp - 273.15);
            printf(" Kelvin to Celsius  = %.3f\n", result); snprintf(h, sizeof(h), "Unit: %.4f m = %.4f km", temp, result); add_history(h); look();
            break;

            case 5: result = (temp - 32) * 5.0/9.0 + 273.15 ;
            printf("Fahrenheit to Kelvin  = %.3f\n", result); snprintf(h, sizeof(h), "Unit: %.4f m = %.4f km", temp, result); add_history(h); look();
            break;

            case 6: result =  (temp-273.15)*(9.0/5.0)+32.0;
            printf("Kelvin to Fahrenheit  = %.3f\n", result); snprintf(h, sizeof(h), "Unit: %.4f m = %.4f km", temp, result); add_history(h); look();
            break;
        }
    }
}

float scientific(){
    int ch;
    while(1){
    printf("\n=============================================\n\t     Scientific Operations\n=============================================\n");
    printf("1) Trignometric Operations(sin, cos, tan).");
    printf("\n2) Logarithmic Operations(log, log10).");
    printf("\n3) power");
    printf("\n4) Square root functions");
    printf("\n5) Exit this mode.\n");
    printf("---------------------------------------------");
    printf("\nEnter your choice: ");
    if (scanf(" %d",&ch) != 1) { int _c; while((_c=getchar())!='\n' && _c!=EOF); printf("\nInvalid input.\n"); continue; }
    switch(ch){
        case 1:
        trignometric(); look(); break;
        case 2:
        logarthmic(); look(); break;
        case 3:
        power(); look(); break;
        case 4:
        square_root(); look(); break;
        case 5:
        return 0;
    }
  }
}
float trignometric(){
    int chh, type;
    double angle, radian, ans;
    const double pi = 3.14159265358979323846;
    char h[160];
    while(1){
    printf("\n=============================================\n\t     Trignometric Operations\n=============================================\n");
    printf("1: sin\n2: cos\n3: tan\n4: sec\n5: cosec\n6: cot\n7: Exit trignometric mode..\n");
    printf("---------------------------------------------\n");
    printf("Enter choice: ");
    if (scanf(" %d", &chh) != 1){ printf("\nInvalid choice... choose 1..7.\n"); continue; }
    if (chh == 7) return 0.0;
        if (chh < 1 || chh > 7) {
            printf("\nInvalid choice... choose 1..7.\n");
            continue;
        }
    printf("\n1... for degrees\n2... for radians\nchoose 1 or 2: ");
    scanf(" %d",&type);
    if (type != 1 && type != 2) {
        printf("\nInvalid type... choose 1 (degrees) or 2 (radians).\n");
        continue;
    }
    printf("\nEnter angle: ");
    if (scanf(" %lf", &angle) != 1) {
        printf("\nInvalid angle... enter a numeric value.\n");
        continue;
    }

    if(type==1){
        radian=angle*(pi/180.0);
    }
    else{
        radian=angle;
    }

    double s = sin(radian);
    double c = cos(radian);

    switch(chh){
        case 1:
        ans = s;
        printf("sin(%.2lf) is %.2lf",angle,ans);
        snprintf(h, sizeof(h), "Trigonometric: sin(%.2lf %s) = %.6lf", angle, (type==1?"deg":"rad"), ans);
        add_history(h); look(); break;

        case 2:
        ans = c;
        printf("cos(%.2lf) is %.2lf",angle,ans);
        snprintf(h, sizeof(h), "Trigonometric: cos(%.2lf %s) = %.6lf", angle, (type==1?"deg":"rad"), ans);
        add_history(h); look(); break;

        case 3:
        ans = s/c;
        if(fabs(c) < EPS){
        printf("tan(%.2lf) is IFINITY",angle);
        snprintf(h, sizeof(h), "Trigonometric: tan(%.2lf %s) = INFINITY", angle, (type==1?"deg":"rad")); add_history(h); look();
        }
        else{
        printf("tan(%.2lf) is %.2lf",angle,ans);
        snprintf(h, sizeof(h), "Trigonometric: tan(%.2lf %s) = %.6lf", angle, (type==1?"deg":"rad"), ans); 
        add_history(h); look();
        } break;

        case 4: {
        ans = 1.0 / c;
        if(fabs(c) < EPS){
        printf("sec(%.2lf) is IFINITY",angle);
        snprintf(h, sizeof(h), "Trigonometric: sec(%.2lf %s) = INFINITY", angle, (type==1?"deg":"rad")); add_history(h); look();
        }
        else
        printf("sec(%.2lf) is %.2lf",angle,ans);
        snprintf(h, sizeof(h), "Trigonometric: sec(%.2lf %s) = %.6lf", angle, (type==1?"deg":"rad"), ans);
        add_history(h);
        look();
        } break;

        case 5:{
        ans = 1.0 / s;
        if(fabs(s) < EPS){
        printf("cosec(%.2lf) is IFINITY",angle);
        snprintf(h, sizeof(h), "Trigonometric: cosec(%.2lf %s) = INFINITY", angle, (type==1?"deg":"rad")); add_history(h); look();
        }
        else
        printf("cosec(%.2lf) is %.2lf", angle, ans);
        snprintf(h, sizeof(h), "Trigonometric: cosec(%.2lf %s) = %.6lf", angle, (type==1?"deg":"rad"), ans);
        add_history(h); look(); break;
        } break;

        case 6:{
        ans = c/s;
        if(fabs(s) < EPS){
        printf("cot(%.2lf) is IFINITY",angle);
        snprintf(h, sizeof(h), "Trigonometric: cot(%.2lf %s) = INFINITY", angle, (type==1?"deg":"rad")); add_history(h); look();
        }
        else
        printf("cot(%.2lf) is %.2lf", angle, ans);
        snprintf(h, sizeof(h), "Trigonometric: cot(%.2lf %s) = %.6lf", angle, (type==1?"deg":"rad"), ans);
        add_history(h); look();
        } break;
        case 7:
        return 0.0;
    }
  }
}

float logarthmic(){
    int chhh;
    double num;
    char h[128];
    while(1){
    printf("\n=============================================\n\t     Logarthmic Operations\n=============================================\n");
    printf("\n1) log\n2) log10\n3) Exit logarthmic mode.\n");
    printf("---------------------------------------------");
    printf("\nChoose Log function type(1 or 2 or 3): ");
    if (scanf(" %d", &chhh) != 1){ int _c; while ((_c = getchar()) != '\n' && _c != EOF); printf("\nInvalid choice... enter 1, 2 or 3.\n"); continue; }
    if(chhh==3)
    return 0;
    else if(chhh!=1 && chhh!=2){
        printf("\nInvalid choice!");
        continue;
    }
    printf("\nEnter the number: ");
    if (scanf(" %lf", &num) != 1) { int _c; while ((_c = getchar()) != '\n' && _c != EOF); printf("\nInvalid number... enter a numeric value.\n"); continue; }
    if (num <= 0.0) {
        printf("\nInvalid input: logarithm defined for numbers > 0 only.\n");
        continue;
    }

    switch(chhh){
        case 1:
        {
            double res=log(num);
            printf("\nNatural log ---> log(%.2lf) is= %.2lf", num, res);
            snprintf(h, sizeof(h), "Log: input=%.6lf result=%.6lf", num, res);
            add_history(h); look(); break;
        }
        case 2:
        {
            double res=log10(num);
            printf("\nCommon log ---> log(%.2lf) is= %.2lf", num, res);
            snprintf(h, sizeof(h), "Log: input=%.6lf result=%.6lf", num, res);
            add_history(h); look(); break;
        }
        default:
           printf("\nWrong Choice.\n"); look();
    }
  }
}

double power(){
    double base, exp;
    int choicee=1;
    while(1){
        printf("\n=============================================\n\t     Power Operation\n=============================================\n");
        printf("Enter the base number: ");
        if (scanf(" %lf",&base) != 1) { int _c; while((_c=getchar())!='\n' && _c!=EOF); printf("\nInvalid base.\n"); continue; }
        printf("\nEnter the exponent number: ");
        if (scanf(" %lf",&exp) != 1) { int _c; while((_c=getchar())!='\n' && _c!=EOF); printf("\nInvalid exponent.\n"); continue; }
        double r= pow(base,exp);
        printf("\nAnswer is ---> %.2lf", r);
        char h[128];
        snprintf(h, sizeof(h), "Power: %.4lf ^ %.4lf = %.4lf", base, exp, r);
        add_history(h);
        printf("\n---> Click 1 to continue.\n---> Click 2 to exit.\n");
        printf("---------------------------------------------");
        printf("\nChoose 1 or 2: ");
        scanf(" %d",&choicee);
        switch(choicee){
            case 1: look(); continue;
            case 2: return 0;
            default: printf("\nWrong choice... Go again"); look();continue;
        }
    }
}
float square_root(){
    int choi; double num;
    while(1){
        printf("\n=============================================\n\t     Square Root\n=============================================\n");
        printf("\n1) Compute\n2)Exit\n");
        printf("---------------------------------------------");
        printf("\nEnter Choice: ");
        if (scanf("%d", &choi) != 1) { int _c; while((_c=getchar())!='\n' && _c!=EOF); printf("\nInvalid input.\n"); continue; }
        if(choi == 2) return 0;
        if(choi ==1){
        printf("\nEnter the number: ");
        if (scanf("%lf", &num) != 1) { int _c; while((_c=getchar())!='\n' && _c!=EOF); printf("\nInvalid input.\n"); continue; }
        if(num<0){
            printf("\nNumber is negative So square root is not possible.");
            add_history("Sqrt: error negative input"); look();
            continue;
        }
        else{
            double r = sqrt(num);
            printf("Square root is %.2lf",r);
            char h[128];
            snprintf(h, sizeof(h), "Sqrt: sqrt(%.6lf) = %.6lf", num, r);
            add_history(h); look();
        }
    }
    else{
            printf("\nInvalid option.\n"); look(); continue;
    }
  }
}


double Quadratic_Equation_Solver(){
    double a, b, c;
    double root1, root2, realPart, imgPart;
    int choice ;
    while(1){
    printf("\n=============================================\n\t   Quadratic Equation Solver\n=============================================\n");
    printf("1. Quadratic Equation\n");
    printf("2. Exit Quadratic Equation Mode\n");
    printf("---------------------------------------------");
    printf("\nChoice = ");
    scanf("%d", &choice);

    switch (choice){
        case 1 : 
        {
            printf("\nEnter Co-efficients\n");
            printf("a = ");
            if (scanf("%lf", &a) != 1) { int _c; while((_c=getchar())!='\n' && _c!=EOF); printf("\nInvalid input.\n"); continue; }
            printf("b = ");
            if (scanf("%lf", &b) != 1) { int _c; while((_c=getchar())!='\n' && _c!=EOF); printf("\nInvalid input.\n"); continue; }
            printf("c = ");
            if (scanf("%lf", &c) != 1) { int _c; while((_c=getchar())!='\n' && _c!=EOF); printf("\nInvalid input.\n"); continue; }
            if (a == 0) { printf("a must be non-zero\n"); continue; }
            double D =  b*b - 4.0 * a * c ; 
            if (D > 0){
             printf("\nTwo real and distinct roots\n");
             root1 = (-b + sqrt(D)) / (2.0*a);
             root2 = (-b - sqrt(D)) /  (2.0*a);
            printf("Root 1 = %.2lf\n", root1);
            printf("Root 2 = %.2lf\n", root2);
    }

           else if (D == 0){
           printf("One Real and Equal Root\n");
           root1 =(-b)/ (2.0*a);
           printf("Root = %.2lf\n", root1);
    }

         else {
        printf("\nComplex Roots\n");
        realPart = -b/(2.0*a);
        imgPart = sqrt(-D)/ (2.0*a);
        printf("Root 1 = %.2lf + %.2lfi\n", realPart, imgPart);
        printf("Root 2 = %.2lf - %.2lfi\n", realPart, imgPart);
    }
    char h[220];
    if (D > 0) {
    snprintf(h, sizeof(h), "Quadratic: a=%.4lf b=%.4lf c=%.4lf => roots %.6lf , %.6lf", a,b,c,root1,root2);
    } else if (D == 0) {
    snprintf(h, sizeof(h), "Quadratic: a=%.4lf b=%.4lf c=%.4lf => root %.6lf", a,b,c,root1);
    } else {
    snprintf(h, sizeof(h), "Quadratic: a=%.4lf b=%.4lf c=%.4lf => complex %.6lf +/- %.6lfi", a,b,c, realPart, imgPart);
    }
        add_history(h);
        look();
    break;
}
    case 2:
    printf("\nQuadratic Equation Solver Mode Exited\n"); look();
    return 0;

    default:
    printf("\nWrong Choice Try Again\n"); look();
    }
    }
}
