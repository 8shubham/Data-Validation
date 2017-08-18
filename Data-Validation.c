#include <stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>


void initial();
void instruction(int x);
void name(char A[], int count);
void date_of_birth(char A[]);
void phone(char A[]);
int email(char A[]);
void PASSWORD(char A[]);
void identity_proof(char A[]);
void account(int A[], char B[]);
void display(char user_id[], char first_name[], char last_name[], char dob[], char email_address[], char phone_no[], int account_no[] );


int main()
{
    int count=0, l, account_no[13], i, a;
    char first_name[50], last_name[50], phone_no[100], email_address[100];
    char dob[100];
    char password[100], identity[100], user_id[100];

    initial();

    instruction(1);

    printf("Enter Your Name :\n\n");

    name(first_name, count);

    count++;

    name(last_name, count);
    system("cls");
    instruction(2);

    date_of_birth(dob);

    system("cls");
    instruction(3);

    printf("\n\n");
    printf("Enter Your Phone Number.\n");
    phone(phone_no);

    printf("\n");
    system("cls");
    instruction(4);

    printf("Enter Your Email Address.\n");

    l =  email(email_address);
    system("cls");
    instruction(5);

    printf("\nEnter Password.\n");

    PASSWORD(password);
    system("cls");
    instruction(6);

    printf("\nEnter Your Identity Card Number.(LNMIIT CARD)\n");

    identity_proof(identity);
    system("cls");

    account(account_no, user_id);

    display(user_id, first_name, last_name, dob, email_address, phone_no, account_no);

    return 0;
}

void initial()
{
    printf("\t\t     ****************************\n");
    printf("\t\t\tWELCOME TO LNMIIT BANK\n");
    printf("\t\t     ****************************\n");
    printf("\n\nINSTRUCTIONS SHOULD BE FOLLOWED WHILE FILLING UP THE FORM\n\n");

}

void instruction(int x)
{
    printf("INSTRUCTIONS : \n\n");

    if(x==1)
    {
        printf("\n1.The Name Should Contain Only Alphabets.\n\n\n");
    }

    if(x==2)
    {
        printf("1.Enter Date Of Birth According To Format Specified.\n\n\n");
    }

    if(x==3)
    {
        printf("1.Mobile Number Should Contain Only 10 Digits.\n");
    }

    if(x==4)
    {
        printf("Enter Email Address According To 'example@site.com'\n \n");
    }

    if(x==5)
    {
        printf("1.Your Password Must Be Atleast 8 Characters Long.\n\nIt Must Contain Following Things :\n\n");
        printf("a.Atleast 1 Upper-Case, Lower-Case, Special Character, Number\n\n");
    }

    if(x==6)
    {
        printf("1.Your Identity Card Number Is Unique 8 Digit Number (NNNN-NNNC)\n\n");
        printf("Properties Of ICN Is The Modulous Of Sum Of The First Seven Digits Of The ICN ");
        printf("\nMultiplied By Its Position In The Number (starting from 8,7,...2) \nBy 11 Must Be Equal To\n\n");
        printf("a.If Remainder = 0 Then Check Digit C=0 \n\nb.Else C=11-Remainder.\n\n");
        printf("2.Please Enter Your ICN According To The Specified Format.\n\n");
        printf("3.Example : 0378-5955\n\n");
    }

}


void name(char A[], int count)
{
    int i=0, ans=1, c;

    while(1)                     //character type checking
    {
        if(count==0)
        {
            printf("FIRST NAME : ");
            gets(A);
        }

        else
        {
            printf("LAST NAME : ");
            gets(A);
        }

        while(A[i] != '\0')
        {
            c = A[i];

            if( isalpha(c))
            {
                i++;
                ans=1;
            }
            else
            {
                ans=0;
                break;
            }
        }

        if(ans == 0)
        {
            printf("Invalid Name Type\n");
            printf("Please Enter Again.\n\n");
            i=0;
            continue;
        }

        else
        {
            break;
        }
    }

    printf("\n");

    i=0;

    while(A[i] != '\0')
    {
        if(A[i] >= 97  && A[i] <=122)   //lowercase to uppercase
            A[i] = A[i] - 32 ;
        i++;
    }
}

void date_of_birth(char A[])
{
    int j, l,i,ans=1;

    while(1)
    {
        printf("Enter Your Date Of Birth : DD/MM/YYYY : ");

        gets(A);

        l=strlen(A);

         if(l != 10)
        {
            printf("Please Give Valid Inputs.\n");
            continue;
        }

        for(i=0 ; i < 10 ; i++)
        {
            if(A[i] != '/')
                ans = isdigit(A[i]);

            if(ans==0)
            {
                printf("Please Give Valid Inputs.\n");
                break;
            }

            if(A[2] != '/' || A[5] != '/')
            {
                printf("Please Give Valid Inputs..\n");
                ans=0;
                break;
            }

            if( i != 2 && i != 5)
            {
                if(A[i] == '/')
                {
                    printf("Please Give Valid Inputs .\n");
                    ans=0;
                    break;
                }
            }
        }

        if(ans == 0 )
        {
            continue;
        }

        else
        {
            int date, month, year , i, leap_year;

            for(i=0; i<10; i++)
            {
                if(i != 2 && i != 5)
                    A[i]=A[i] - '0';
            }

            year = A[6]*1000 +A[7]*100 +A[8]*10+ A[9] ;
            month = A[3]*10 + A[4];
            date = A[0]*10 + A[1];

            if(year > 1997)
            {
                printf("Your Age Should Be Above 18 To Open The Form.\n\n");
                continue;
            }

            if(year % 400 == 0)
                leap_year= 1;

            else if (year % 100 == 0)
                leap_year= 0;

            else if(year % 4 == 0)
                leap_year= 1;

            else
                leap_year= 0;

            if(date < 1 || month < 1 || year < 1)
            {
                printf("Please Give Valid Inputs : ");
                continue;
            }

            if( month > 12 )
            {
                printf("Please Give Valid Inputs : ");
                continue;
            }

            else
            {
                if(month == 4 || month == 6 || month == 9 || month == 11)
                {
                    if(date > 30)
                    {
                        printf("Please Give Valid Input : ");
                        continue;
                    }
                }

                else if(month == 2)
                {
                    if(date > 28 && leap_year == 0)
                    {
                        printf("Please Give Valid Input : ");
                        continue;
                    }

                    else if(date > 29 && leap_year == 1)
                    {
                        printf("Please Give Valid Input : ");
                        continue;
                    }

                }

                else
                {
                    if(date > 31)
                    {
                        printf("Please Give Valid Input : ");
                        continue;
                    }

                    else
                        break;
                }
            }
        break;
        }
    }
}


void phone(char A[])
{
    int l, ans=1, i;

    gets(A);

    l=strlen(A);

    if(l != 10 )
    {
        printf("Please Enter Valid Phone Number.\n");
        printf("(CHECK NUMBER OF DIGITS)\n\n" );
        phone(A);
    }

    else
    {
        for(i=0 ; i < 10 ; i++)
        {
            ans = isdigit(A[i]);

            if(ans==0)
                break;
        }

        if(ans == 0 )
        {
            printf("Please Enter Valid Phone Number.\n");
            printf("(ENTER ONLY DIGITS NO OTHER CHARRACTER ALLOWED)\n\n");
            phone(A);
        }

        else
        {
            for(i=0; i<10; i++)
            {
                A[i]=A[i] - '0';
            }

            if(A[0] < 7)
            {
                printf("Please Enter Valid Phone Number.\n");
                printf("Indian Number Only Starts From 7,8 or 9\n\n");
                phone(A);
            }
        }
    }
}

int email(char A[])
{
    int i, j, l;

    while(1)
    {
        int count1=0, count2=0, count3=0;
        gets(A);

        l=strlen(A);
        A[l]='\0';

        for(i=0;i < l ;i++)
        {
            if(A[i] == '@')
            {
                count1++;
                j=i;
            }

            else if(A[i] == ' ')
                count2++;
        }

        if(count1 != 1)
        {
            printf("Your Email Address Must Contain 1 '@' symbol\n\n");
            count1=0;
            continue;
        }

        if(count2 != 0)
        {
            printf("Your Email Address Must Not Contain Any Space\n\n");
            count2=0;continue;
        }

        if( A[l-1] != 'm' || A[l-2] != 'o' || A[l-3] != 'c' || A[l-4] != '.' )
        {
            printf("Your Email Address Must End With '.com'\n\n");
            continue;
        }

        if(l-4 == j+1)
        {
            printf("Your Email Address Must Contain Domain(i.e. Site Name)\n\n");
            continue;
        }

        for(i=j ; i < l; i++)
        {
            if(A[i] == '.')
                count3++;
        }

        if(count3 != 1)
        {
            printf("%d", count3);
            printf("Your Email Address Must Contain Only 1 '.'\n\n");
            count3=0;
            continue;
       }

        else
            break;}

    return l;
}

void PASSWORD(char A[])
{
    int l, i, upper_case=0, lower_case=0, number=0, special=0;

    char B[100], confirm;

    gets(A);

    l= strlen(A);

    A[l]='\0';



    for(i=0; i<l; i++)
    {
        if(A[i] >= 'A' && A[i] <= 'Z')
            upper_case++;

        else if(A[i] >= 'a' && A[i] <= 'z')
            lower_case++;

        else if(A[i] >= '0' && A[i] <= '9')
            number++;

        else
            special++;
    }

    if(l < 8)
    {
        printf("WEAK PASSWORD.(ATLEAST 8 CHARACTERS)\n");
        printf("Please Enter A More Secure Password\n\n");
        PASSWORD(A);
    }

    else if(upper_case < 1)
    {
        printf("Your Password Must Contain 1 Upper Case Letter\n\n");
        PASSWORD(A);
    }

    else if(lower_case < 1)
    {
        printf("Your Password Must Contain 1 Lower Case Letter\n\n");
        PASSWORD(A);
    }

    else if(special < 1)
    {
        printf("Your Password Must Contain 1 Special Character\n\n");
        PASSWORD(A);
    }

        else if(number < 1)
    {
        printf("Your Password Must Contain 1 Number\n\n");
        PASSWORD(A);
    }

    else
    {
        system("cls");
        printf("\nConfirm Your Password\n");

        while(1)
        {
            gets(B);

            int p =strlen(B);
            B[p]='\0';

            if(strcmp(A, B) != 0)
                printf("Your Password Does Not Match Please Enter Again\n\n");

            else
                break;
            }
    }

}

void identity_proof(char A[])
{
    while(1)
    {
        int l=0, i, j=8, sum=0, check=0, ans=1;

        gets(A);

        l= strlen(A);

        A[l]='\0';

        if(l != 9)
        {
            printf("Please Enter Valid Identity Number.\n");
            printf("(CHECK NUMBER OF DIGITS)\n\n");
            continue;
        }
        else
        {
            for(i=0 ; i < 9 ; i++)
            {
                if(i != 4)
                {
                    ans = isdigit(A[i]);

                    if(ans==0)
                    break;
                }
            }

            if(ans == 0 )
            {
                printf("%d%c", ans, A[i]);
                printf("INVALID\n");
                printf("(ENTER ONLY DIGITS NO OTHER CHARRACTER ALLOWED)\n\n");
            continue;
            }

            else
            {
                for(i=0; i < 8; i++)
                {
                    if(A[i] != '-')
                    {
                        A[i] = A[i]- '0';
                        sum += A[i]*j;
                        j--;
                    }
                }
            }
        }

        A[8] =A[8] - '0';

        check = sum % 11;

        if(check == 0 )
        {
            if (A[8] != 0)
            {
                printf("Invalid Identification Number.\n");
                printf("Please Enter Again.\n\n");
                continue;
            }
        }

        else
        {
            if( (11 - check) != (A[8]) )
            {
                printf("%d", A[8]); printf("Invalid Identification Number.\n");
                printf("Please Enter Again.\n\n");
                continue;
            }

            else
                break;
        }
    }
}

void account(int A[], char B[])
{
    int i, l, x, result;
    char ans[100];
    char c;

    for(i=0;i<13;i++)
    {
        if(i<10)
        {
            A[i]=rand()%10;
            B[i]=rand()%26 + 65;
        }

        else
            B[i]=rand()%26 + 97;
    }

    printf("Your Account Number Is : ");

    for(i=0;i<10;i++)
        printf("%d",A[i]);

    printf("\nYour User ID is : ");

    for(i=0; i<13 ; i++)
        printf("%c",B[i]);

    printf("\n\nYou Can Change Your User ID Once.\n");


    while(1)
    {
        printf("Would You Like To Change It: Press 'y' for yes or 'n' for no\n");
        gets(ans);

        x=strlen(ans);
        if (x != 1)
            printf("Please Give Valid Input:\n\n");

        else
        {
            if(ans[0]== 'n')
                return ;

            else if(ans[0] == 'y')
            {
                while(1)
                {
                    printf("Enter Your User ID : ");
                    gets(B);

                    l = strlen(B);
                    B[l]='\0';
                    if(l > 13 || l < 5)
                        printf("User ID Must Have 5-13 Characters\n\n");

                    else
                    {
                        while(B[i] != '\0')
                        {
                            c = B[i];

                            if( isalpha(c) )
                            {
                                i++;
                                result=1;
                            }
                            else
                            {
                                result=0;
                                break;
                            }
                        }

                                if(result == 0)
                                {
                                    printf("Invalid Name Type\n");
                                    printf("Please Enter Again.\n\n");
                                    i=0;
                                    continue;
                                }

                                else
                                {
                                    break;
                                }
                    }
                }
                break;
            }
            else
                printf("Please Give Valid Input :\n\n");
        }
    }
}


void display(char user_id[], char first_name[], char last_name[], char dob[], char email_address[], char phone_no[], int account_no[] )
{
    int i=0;

    system("cls");

    printf("WELCOME %s IN LNMIIT BANK.\n\n", first_name);

    printf("Name : %s %s\n\n", first_name, last_name);

    printf("Date Of Birth : ");

        for(i=0; i < 10 ; i++)
        {
            if(i == 2 || i == 5)
                printf("%c", dob[i]);       //printing '/'
            else
                printf("%d", dob[i]);
        }

    printf("\n\nEmail : %s\n\n", email_address);

    printf("Phone Number : ");

    for(i=0;i<10;i++)
        printf("%d", phone_no[i]);

    printf("\n\nUser ID : %s\n\n", user_id );

    printf("ACCOUNT NUMBER : ");

        for(i=0;i<10;i++)
            printf("%d", account_no[i]);

    printf("\n\nACCOUNT BALANCE : NIL");

    printf("\n\n\nTHANKS FOR VISITING LNMIIT BANK\n");

}



