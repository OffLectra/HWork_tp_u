#include <utils.h>
#include <test.h>


int main(void) {
    int choice = 0;
    FILE *pDataF = NULL, *pDataTr = NULL, *pDataUpd = NULL;
    Data client_data = {0}, transfer = {0};

    printf("%s",
          "please enter action\n1 enter data client:\n2 enter data transaction:\n3 update base\n4 test\n");

    while (scanf("%d", &choice) != -1) {
        switch (choice) {
            case 1: {
                pDataF = fopen(file_rec, "r+");
                if (pDataF == NULL) {
                    puts("Not access");
                    } else {
                           WriteDataToFile(pDataF, client_data);
                           fclose(pDataF);
                           }
            break;}

            case 2: {
                pDataF = fopen(file_transac, "r+");
                if (pDataF == NULL) {
                    puts("Not access");
                } else {
                    EnterTransactionData(pDataF, transfer);
                    fclose(pDataF);
                    }
            break;}

            case 3: {
                pDataF = fopen(file_rec, "r");
                pDataTr = fopen(file_transac, "r");
                pDataUpd = fopen(file_blackrec, "w");

                if (pDataF == NULL || pDataTr == NULL || pDataUpd == NULL) {
                    puts("exit");
                } else {
                    UpdateDataBase(pDataF, pDataTr, pDataUpd, client_data, transfer);
                    fclose(pDataF);
                    fclose(pDataTr);
                    fclose(pDataUpd);
                    }
            break;}

            case 4: {
                test_write_to_file();
            break;}

            default: {
                puts("error");
                break;}
            }
    }
    printf("%s",
     "please enter action\n1 enter data client:\n2 enter data transaction:\n3 update base\n4 test case\n");

    return 0;
}
