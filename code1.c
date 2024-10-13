#include <stdio.h>
#include <stdlib.h>



void monthlyReport(double salesFigures[], char monthList[12][10], int MONTH);
void monthlySummary(double salesFigures[], char monthList[12][10], int MONTH);
void movingAverage(double salesFigures[], char monthList[12][10], int MONTH);
void highToLow(double salesFigures[], char monthList[12][10], int MONTH);



int main(){
    const char monthList[12][10] = {"January", 
        "February", 
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December"};

    const int MONTH = 12; 

    FILE *report;

    report = fopen("input.txt", "r");

    char line[12];
    
    double salesFigures[12];
    double saleNum;
    // read the first line
    fscanf(report, "%lf", &saleNum);
    salesFigures[0] = saleNum;

    for(int i = 1; i < 12; i++){
        while (fgets(line, 12, report) != NULL){
            fscanf(report, "%lf", &saleNum);
            salesFigures[i] = saleNum;
            i++;
        }
    }

    monthlyReport(salesFigures, monthList, MONTH);
    monthlySummary(salesFigures, monthList, MONTH);
    movingAverage(salesFigures, monthList, MONTH);
    highToLow(salesFigures, monthList, MONTH);


    return 0;
}

void monthlyReport(double salesFigures[], char monthList[12][10], int MONTH){
    printf("Monthly Sales Report for 2024\n");
    printf("Month     Sales\n");
    for(int i = 0; i < MONTH; i++){
        printf("%-9s ", monthList[i]);
        printf("%.2lf\n", salesFigures[i]);
    }
    printf("\n");
    
}

void monthlySummary(double salesFigures[], char monthList[12][10], int MONTH){
    int minIndex = 0;
    int maxIndex = 0;
    double min, max = salesFigures[0];
    double average = 0;

    for(int i = 0; i < 12; i++){
        if(salesFigures[i] < min){
            min = salesFigures[i];
            minIndex = i;
        }
        if(salesFigures[i] > max){
            max = salesFigures[i];
            maxIndex = i;
        }
        average += salesFigures[i];
    }
    average /= 12;

    printf("Sales Summary Report: \n");
    printf("Minimum Sales: %.2lf  (%s)\n", salesFigures[minIndex], monthList[minIndex]);
    printf("Maximum Sales: %.2lf  (%s)\n", salesFigures[maxIndex], monthList[maxIndex]);
    printf("Average Sales: %.2lf", average);
    printf("\n");
}

void movingAverage(double salesFigures[], char monthList[12][10], int MONTH){
    double averages[7];
    for(int i = 0; i < 7; i++){
        averages[i] = 0;
    }

    for(int i = 0; i < 6; i++){
        averages[0] += salesFigures[i];
        averages[1] += salesFigures[i+1];
        averages[2] += salesFigures[i+2];
        averages[3] += salesFigures[i+3];
        averages[4] += salesFigures[i+4];
        averages[5] += salesFigures[i+5];
        averages[6] += salesFigures[i+6];
    }

    for(int i = 0; i < 7; i++){
        averages[i] = averages[i] / 6;
    }

    
    printf("\nSix-Month moving average report\n");
    printf("January-June    %-5.2lf\n", averages[0]);
    printf("February-July   %-5.2lf\n", averages[1]);
    printf("March-August    %-5.2lf\n", averages[2]);
    printf("April-September %-5.2lf\n", averages[3]);
    printf("May-October     %-5.2lf\n", averages[4]);
    printf("June-November   %-5.2lf\n", averages[5]);
    printf("July-December   %-5.2lf\n", averages[6]);
}

void highToLow(double salesFigures[], char monthList[12][10], int MONTH){
    int monthIndexOrder[12]  = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    int i = 0;

    while(i != 11){
        if(salesFigures[i] < salesFigures[i+1]){
            double buffer = salesFigures[i+1];
            int bufferIndex = monthIndexOrder[i+1];
            salesFigures[i+1] = salesFigures[i];
            monthIndexOrder[i+1] = monthIndexOrder[i];
            salesFigures[i] = buffer;
            monthIndexOrder[i] = bufferIndex;
            i = 0;
        } if(salesFigures[i] > salesFigures[i+1]){
            i++;
        }
    }

    printf("\nSales Report (highest to lowest):\n");
    printf("Month        Sales\n");
    for(int i = 0; i < 12; i++){
        printf("%-12s $%.2lf\n", monthList[monthIndexOrder[i]], salesFigures[i]);
    }

}
