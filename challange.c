#include <stdio.h>
#include <math.h>

int main() {
    float loanAmount, interestRate, monthlyPayment;
    int loanDuration, attempts = 0;

    do {
        attempts++;
        if (attempts > 10) {
            printf("Maximum number of attempts reached. Exiting...\n");
            return 0;
        }

        printf("Enter the loan amount: ");
        scanf("%f", &loanAmount);

        printf("Enter the interest rate (between 3%% and 7%%): ");
        scanf("%f", &interestRate);

        printf("Enter the loan duration (in years, minimum 5 years): ");
        scanf("%d", &loanDuration);

        if (loanDuration < 5) {
            printf("Loan duration should be at least 5 years. Please try again.\n");
            continue;
        }

        if (interestRate < 3 || interestRate > 7) {
            printf("Interest rate should be between 3%% and 7%%. Please try again.\n");
            continue;
        }

        
        float monthlyInterestRate = interestRate / 100 / 12;
        int numberOfPayments = loanDuration * 12;
        monthlyPayment = (loanAmount * monthlyInterestRate) / (1 - pow(1 + monthlyInterestRate, -numberOfPayments));

        printf("Estimated monthly payment: %.2f\n", monthlyPayment);

    } while (1);

    return 0;
}