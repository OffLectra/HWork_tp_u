#ifndef PROJECT_INCLUDE_UTILS_H_
#define PROJECT_INCLUDE_UTILS_H_
#define file_rec "record.dat"
#define file_transac "transaction.dat"
#define file_blackrec "blackrecord.dat"

#include <stdio.h>
#include <stdlib.h>

struct customer {
    int number;
    char name[20];
    char surname[20];
    char addres[30];
    char telNumber[15];
    double indebtedness;
    double credit_limit;
    double cash_payments;
};

typedef struct customer Data;

void WriteDataToFile(FILE *pDataFile, Data Client),
    EnterTransactionData(FILE *pDataFile, Data transfer),
    UpdateDataBase(FILE *pDataFile, FILE *pDataTransfer, FILE *pDataUpdate, Data client_data, Data transfer);

#endif  // PROJECT_INCLUDE_UTILS_H_
