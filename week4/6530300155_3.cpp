#include <iostream>
#include <cmath> 
using namespace std;

struct Term {
    int coefficient;
    int exponent;
    Term* next;
};

typedef Term* Polynomial;

void insertTerm(Polynomial& poly, int coeff, int exp) {
    Term* newTerm = new Term;
    newTerm->coefficient = coeff;
    newTerm->exponent = exp;
    newTerm->next = NULL;

    if (poly == NULL) {
        poly = newTerm;
    } else {
        Term* current = poly;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newTerm;
    }
}

void createPolynomial(Polynomial& poly) {
    int coeff, exp;
    while (true) {
        cin >> coeff;
        if (coeff == -99) {
            break;
        }
        cin >> exp;
        insertTerm(poly, coeff, exp);
    }
}

void displayPolynomial(Polynomial poly) {
    if (poly == NULL) {
        cout << "0" << endl;
        return;
    }

    Term* current = poly;
    bool firstTerm = true;

    while (current != NULL) {
        if (current->coefficient != 0) {
            if (!firstTerm) {
                if (current->coefficient > 0) {
                    cout << " + ";
                } else {
                    cout << " - ";
                }
            }

            int absCoeff = abs(current->coefficient); // Use abs() from cmath

            if (current->exponent == 0) {
                cout << absCoeff;
            } else {
                if (absCoeff != 1) {
                    cout << absCoeff;
                }
                cout << "x";
                if (current->exponent != 1) {
                    cout << "^" << current->exponent;
                }
            }

            firstTerm = false;
        }
        current = current->next;
    }

    cout << endl;
}

Polynomial addPolynomials(Polynomial p1, Polynomial p2) {
    Polynomial result = NULL;
    Term* current1 = p1;
    Term* current2 = p2;

    while (current1 != NULL && current2 != NULL) {
        if (current1->exponent == current2->exponent) {
            int sumCoeff = current1->coefficient + current2->coefficient;
            if (sumCoeff != 0) {
                insertTerm(result, sumCoeff, current1->exponent);
            }
            current1 = current1->next;
            current2 = current2->next;
        } else if (current1->exponent > current2->exponent) {
            insertTerm(result, current1->coefficient, current1->exponent);
            current1 = current1->next;
        } else {
            insertTerm(result, current2->coefficient, current2->exponent);
            current2 = current2->next;
        }
    }

    while (current1 != NULL) {
        insertTerm(result, current1->coefficient, current1->exponent);
        current1 = current1->next;
    }

    while (current2 != NULL) {
        insertTerm(result, current2->coefficient, current2->exponent);
        current2 = current2->next;
    }

    return result;
}

int main() {
    Polynomial p1 = NULL;
    Polynomial p2 = NULL;

    cout << "Input P1: ";
    createPolynomial(p1);

    cout << "Input P2: ";
    createPolynomial(p2);

    Polynomial result = addPolynomials(p1, p2);

    cout << "Longer: ";
    displayPolynomial(result);

    return 0;
}