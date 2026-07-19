#include <iostream>
using namespace std;

class Node
{
public:
    int coeff;
    int exp;
    Node *next;

    Node(int c, int e)
    {
        coeff = c;
        exp = e;
        next = NULL;
    }
};

class Polynomial
{
private:
    Node *head;

public:
    Polynomial()
    {
        head = NULL;
    }

    // Insert term in descending order of exponent
    void insertTerm(int coeff, int exp)
    {
        Node *newNode = new Node(coeff, exp);

        if (head == NULL)
        {
            head = newNode;
            return;
        }

        Node *temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    void display()
    {
        if (head == NULL)
        {
            cout << "0";
            return;
        }

        Node *temp = head;

        while (temp != NULL)
        {
            cout << temp->coeff << "x^" << temp->exp;

            if (temp->next != NULL)
                cout << " + ";

            temp = temp->next;
        }

        cout << endl;
    }

    Node *getHead()
    {
        return head;
    }

    static Polynomial add(Polynomial p1, Polynomial p2)
    {
        Polynomial result;

        Node *t1 = p1.getHead();
        Node *t2 = p2.getHead();

        while (t1 != NULL && t2 != NULL)
        {

            if (t1->exp == t2->exp)
            {
                result.insertTerm(
                    t1->coeff + t2->coeff,
                    t1->exp);

                t1 = t1->next;
                t2 = t2->next;
            }

            else if (t1->exp > t2->exp)
            {
                result.insertTerm(
                    t1->coeff,
                    t1->exp);

                t1 = t1->next;
            }

            else
            {
                result.insertTerm(
                    t2->coeff,
                    t2->exp);

                t2 = t2->next;
            }
        }

        while (t1 != NULL)
        {
            result.insertTerm(
                t1->coeff,
                t1->exp);
            t1 = t1->next;
        }

        while (t2 != NULL)
        {
            result.insertTerm(
                t2->coeff,
                t2->exp);
            t2 = t2->next;
        }

        return result;
    }
};

int main()
{
    Polynomial p1, p2, result;

    int n, coeff, exp;

    cout << "Enter number of terms in Polynomial 1: ";
    cin >> n;

    cout << "Enter coefficient and exponent:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> coeff >> exp;
        p1.insertTerm(coeff, exp);
    }

    cout << "Enter number of terms in Polynomial 2: ";
    cin >> n;

    cout << "Enter coefficient and exponent:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> coeff >> exp;
        p2.insertTerm(coeff, exp);
    }

    cout << "\nPolynomial 1: ";
    p1.display();

    cout << "Polynomial 2: ";
    p2.display();

    result = Polynomial::add(p1, p2);

    cout << "Sum Polynomial: ";
    result.display();

    return 0;
}