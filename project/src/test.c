#include <test.h>

void write_to_file(const char *pFileTest, Data *pData) {
    FILE *pFile = NULL;
    pFile = fopen(pFileTest, "r+");

    if (pFile == NULL) {
        puts("Not access");
        } else {
                fprintf(pFile, "%-12d%-11s%-11s%-16s%20s%12.2f%12.2f%12.2f\n",
                    pData->number,
                    pData->name,
                    pData->surname,
                    pData->addres,
                    pData->telNumber,
                    pData->indebtedness,
                    pData->credit_limit,
                    pData->cash_payments);
                fclose(pFile);
                }
}

void read_from_file(const char *pFileTest, Data *pData) {
    FILE *pFile = NULL;
    pFile = fopen(pFileTest, "r");
    if (pFile == NULL) {
                        puts("Not access");
                        } else {
                            fscanf(pFile, "%50d%50s%50s%50s%50s%50lf%50lf%50lf",
                                &pData->number,
                                pData->name,
                                pData->surname,
                                pData->addres,
                                pData->telNumber,
                                &pData->indebtedness,
                                &pData->credit_limit,
                                &pData->cash_payments);
                            fclose(pFile);
                            }
}

void test_write_to_file() {
    const char *pFileTest = "test_wr_tof.dat";

    Data expected_data = {1, "Ulya", "Ss", "g.Moscow,22", "88005550000", 345, 100, 10};
    write_to_file(pFileTest, &expected_data);

    Data got_data = {0};
    read_from_file(pFileTest, &got_data);

    if (expected_data.number == got_data.number &&
        (strcmp(expected_data.name, got_data.name) == 0) &&
        (strcmp(expected_data.surname, got_data.surname) == 0) &&
        (strcmp(expected_data.addres, got_data.addres) == 0) &&
        (strcmp(expected_data.telNumber, got_data.telNumber) == 0) &&
        expected_data.indebtedness == got_data.indebtedness &&
        expected_data.credit_limit == got_data.credit_limit &&
        expected_data.cash_payments == got_data.cash_payments) {
            puts("True");
            } else {
                puts("False");
                }
}
