#include <enter_transaction_data.h>

void EnterTransactionData(FILE *pDataFile, Data transfer) {
    printf("%s\n%s\n", "1 Number account: ", "2 Client cash payments: ");
    while (scanf("%d %lf",
        &transfer.number,
        &transfer.cash_payments) != -1) {
            fprintf(pDataFile, "%-3d%-6.2f\n", transfer.number, transfer.cash_payments);
            printf("%s\n%s\n", "1 Number account:", "2 Client cash payments: ");
    }
}
