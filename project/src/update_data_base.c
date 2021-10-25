#include <update_data_base.h>

void UpdateDataBase(FILE *pDataFile,
    FILE *pDataTransfer,
    FILE *pDataUpdate,
    Data client_data,
    Data transfer) {
        while (fscanf(pDataFile, "%50d%50s%50s%50s%50s%50lf%50lf%50lf",
            &client_data.number,
            client_data.name,
            client_data.surname,
            client_data.addres,
            client_data.telNumber,
            &client_data.indebtedness,
            &client_data.credit_limit,
            &client_data.cash_payments) == 8) {
                while (fscanf(pDataTransfer, "%d %lf", &transfer.number, &transfer.cash_payments) == 2) {
                    if (client_data.number == transfer.number && transfer.cash_payments != 0) {
                        client_data.credit_limit += transfer.cash_payments;
                    }
                }

                fprintf(pDataUpdate, "%-12d%-11s%-11s%-16s%20s%12.2f%12.2f%12.2f\n",
                    client_data.number,
                    client_data.name,
                    client_data.surname,
                    client_data.addres,
                    client_data.telNumber,
                    client_data.indebtedness,
                    client_data.credit_limit,
                    client_data.cash_payments);
                rewind(pDataTransfer);
        }
}
