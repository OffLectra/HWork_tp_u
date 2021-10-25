#include <write_data_tofile.h>

void WriteDataToFile(FILE *pDataFile, Data Client) {
    printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n\n",
        "1 Number account: ",
        "2 Client name: ",
        "3 Surname: ",
        "4 Addres client: ",
        "5 Client telnumber: ",
        "6 Client indebtedness: ",
        "7 Client credit limit: ",
        "8 Client cash payments: ");

    while (scanf("%50d%50s%50s%50s%50s%50lf%50lf%50lf",
        &Client.number,
        Client.name,
        Client.surname,
        Client.addres,
        Client.telNumber,
        &Client.indebtedness,
        &Client.credit_limit,
        &Client.cash_payments) == 8) {
            fprintf(pDataFile, "%-12d%-11s%-11s%-16s%20s%12.2f%12.2f%12.2f\n",
                Client.number,
                Client.name,
                Client.surname,
                Client.addres,
                Client.telNumber,
                Client.indebtedness,
                Client.credit_limit,
                Client.cash_payments);
            printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n\n",
                "1 Number account: ",
                "2 Client name: ",
                "3 Surname: ",
                "4 Addres client: ",
                "5 Client telnumber: ",
                "6 Client indebtedness: ",
                "7 Client credit limit: ",
                "8 Client cash payments:");

            printf("if you want to exit just press ctrl+d\n");
    }
}
