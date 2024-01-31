#include <stdio.h>

FILE *input;
FILE *output;

int load_op();

int instruction_counter = 0x0000;

char buf[2];
char next;

void read_one_op()
{
    int val = load_op();
    while (val == 0)
    {
        val = load_op();
    }
}

void read_two_op()
{
    read_one_op();
    read_one_op();
}

void skip_n(int n)
{
    for (int i = 0; i < n; i++)
    {
        fgetc(input);
    }
}

void empty_buf()
{
    buf[0] = '*';
}

void process_op(char buf[2])
{
    char op_buf[2];
    char arg_buf[2];
    switch (buf[0])
    {
    case '0':
        switch (buf[1])
        {
        case '0':
            fprintf(output, "%x %c%c\tNOP\n", instruction_counter, buf[0], buf[1]);
            break;
        case '1':
            op_buf[0] = buf[0];
            op_buf[1] = buf[1];
            empty_buf();
            read_two_op();
            arg_buf[0] = buf[0];
            arg_buf[1] = buf[1];
            empty_buf();
            read_two_op();
            fprintf(output, "%x %c%c %c%c %c%c\tLXI B,#%c%c\n", instruction_counter, op_buf[0], op_buf[1], arg_buf[0], arg_buf[1], buf[0], buf[1], buf[0], buf[1], arg_buf[0], arg_buf[1]);
            break;
        case '2':
            fprintf(output, "%x %c%c\tSTAX B\n", instruction_counter, buf[0], buf[1]);
            break;
        case '3':
            fprintf(output, "%x %c%c\tINX B\n", instruction_counter, buf[0], buf[1]);
            break;
        case '4':
            fprintf(output, "%x %c%c\tINR B\n", instruction_counter, buf[0], buf[1]);
            break;
        case '5':
            fprintf(output, "%x %c%c\tDCR B\n", instruction_counter, buf[0], buf[1]);
            break;
        case '6':
            op_buf[0] = buf[0];
            op_buf[1] = buf[1];
            empty_buf();
            read_two_op();
            fprintf(output, "%x %c%c %c%c\tMVI B,#%c%c\n", instruction_counter, op_buf[0], op_buf[1], buf[0], buf[1], buf[0], buf[1]);
            break;
        case '7':
            fprintf(output, "%x %c%c\tRLC\n", instruction_counter, buf[0], buf[1]);
            break;
        case '8':
            // unallocated
            break;
        case '9':
            fprintf(output, "%x %c%c\tDAD B\n", instruction_counter, buf[0], buf[1]);
            break;
        case 'a':
            fprintf(output, "%x %c%c\tLDAX B\n", instruction_counter, buf[0], buf[1]);
            break;
        case 'b':
            fprintf(output, "%x %c%c\tDCX B\n", instruction_counter, buf[0], buf[1]);
            break;
        case 'c':
            fprintf(output, "%x %c%c\tINR C\n", instruction_counter, buf[0], buf[1]);
            break;
        case 'd':
            fprintf(output, "%x %c%c\tDCR C\n", instruction_counter, buf[0], buf[1]);
            break;
        case 'e':
            op_buf[0] = buf[0];
            op_buf[1] = buf[1];
            empty_buf();
            read_two_op();
            fprintf(output, "%x %c%c %c%c\tMVI C,#%c%c\n", instruction_counter, op_buf[0], op_buf[1], buf[0], buf[0], buf[0], buf[0]);
            break;
        case 'f':
            fprintf(output, "%x %c%c\tRRC\n", instruction_counter, buf[0], buf[1]);
            break;
        }
        break;
    case '1':
        switch (buf[1])
        {
        case '0':
            // unallocated
            break;
        case '1':
            op_buf[0] = buf[0];
            op_buf[1] = buf[1];
            empty_buf();
            read_two_op();
            arg_buf[0] = buf[0];
            arg_buf[1] = buf[1];
            empty_buf();
            load_op();
            load_op();
            fprintf(output, "%x %c%c %c%c %c%c\tLXI D,#%c%c%c%c\n", instruction_counter, op_buf[0], op_buf[1], arg_buf[0], arg_buf[1], buf[0], buf[1], buf[0], buf[1], arg_buf[0], arg_buf[1]);
            break;
        case '2':
            fprintf(output, "%x %c%c\tSTAX D\n", instruction_counter, buf[0], buf[1]);
            break;
        case '3':
            fprintf(output, "%x %c%c\tINX D\n", instruction_counter, buf[0], buf[1]);
            break;
        case '4':
            fprintf(output, "%x %c%c\tINR D\n", instruction_counter, buf[0], buf[1]);
            break;
        case '5':
            fprintf(output, "%x %c%c\tDCR D\n", instruction_counter, buf[0], buf[1]);
            break;
        case '6':
            op_buf[0] = buf[0];
            op_buf[1] = buf[1];
            empty_buf();
            read_two_op();
            fprintf(output, "%x %c%c %c%c\tMVI D,#%c%c\n", instruction_counter, op_buf[0], op_buf[1], buf[0], buf[1], buf[0], buf[1]);
            break;
        case '7':
            fprintf(output, "%x %c%c\tRAL\n", instruction_counter, buf[0], buf[1]);
            break;
        case '8':
            // unallocated
            break;
        case '9':
            fprintf(output, "%x %c%c\tDAD D\n", instruction_counter, buf[0], buf[1]);
            break;
        case 'a':
            fprintf(output, "%x %c%c\tLDAX D\n", instruction_counter, buf[0], buf[1]);
            break;
        case 'b':
            fprintf(output, "%x %c%c\tDCX D\n", instruction_counter, buf[0], buf[1]);
            break;
        case 'c':
            fprintf(output, "%x %c%c\tINR E\n", instruction_counter, buf[0], buf[1]);
            break;
        case 'd':
            fprintf(output, "%x %c%c\tDCR E\n", instruction_counter, buf[0], buf[1]);
            break;
        case 'e':
            op_buf[0] = buf[0];
            op_buf[1] = buf[1];
            empty_buf();
            read_two_op();
            fprintf(output, "%x %c%c %c%c\tMVI E,#%c%c\n", instruction_counter, op_buf[0], op_buf[1], buf[0], buf[1], buf[0], buf[1]);
            break;
        case 'f':
            fprintf(output, "%x %c%c\tRAR\n", instruction_counter, buf[0], buf[1]);
            break;
        }
        break;
    case '2':
        switch (buf[1])
        {
        case '0':
            // unallocated
            break;
        case '1':
            op_buf[0] = buf[0];
            op_buf[1] = buf[1];
            empty_buf();
            read_two_op();
            arg_buf[0] = buf[0];
            arg_buf[1] = buf[1];
            empty_buf();
            read_two_op();
            fprintf(output, "%x %c%c %c%c %c%c\tLXI H,#%c%c%c%c\n", instruction_counter, op_buf[0], op_buf[1], arg_buf[0], arg_buf[1], buf[0], buf[1], buf[0], buf[1], arg_buf[0], arg_buf[1]);
            break;
        case '2':
            op_buf[0] = buf[0];
            op_buf[1] = buf[1];
            empty_buf();
            read_two_op();
            arg_buf[0] = buf[0];
            arg_buf[1] = buf[1];
            empty_buf();
            read_two_op();
            fprintf(output, "%x %c%c %c%c %c%c\tSHLD $%c%c%c%c\n", instruction_counter, op_buf[0], op_buf[1], arg_buf[0], arg_buf[1], buf[0], buf[1], buf[0], buf[1], arg_buf[0], arg_buf[1]);
            break;
        case '3':
            fprintf(output, "%x %c%c\tINX H\n", instruction_counter, buf[0], buf[1]);
            break;
        case '4':
            fprintf(output, "%x %c%c\tINR H\n", instruction_counter, buf[0], buf[1]);
            break;
        case '5':
            fprintf(output, "%x %c%c\tDCR H\n", instruction_counter, buf[0], buf[1]);
            break;
        case '6':
            op_buf[0] = buf[0];
            op_buf[1] = buf[0];
            empty_buf();
            read_two_op();
            fprintf(output, "%x %c%c %c%c\tMVI H,#%c%c\n", instruction_counter, op_buf[0], op_buf[1], buf[0], buf[1], buf[0], buf[1]);
            break;
        case '7':
            fprintf(output, "%x %c%c\tDAA\n", instruction_counter, buf[0], buf[1]);
            break;
        case '8':
            // unallocated
            break;
        case '9':
            fprintf(output, "%x %c%c\tDAD H\n", instruction_counter, buf[0], buf[1]);
            break;
        case 'a':
            op_buf[0] = buf[0];
            op_buf[1] = buf[1];
            empty_buf();
            read_two_op();
            arg_buf[0] = buf[0];
            arg_buf[1] = buf[1];
            empty_buf();
            read_two_op();
            fprintf(output, "%x %c%c %c%c %c%c\tLHLD $%c%c%c%c\n", instruction_counter, op_buf[0], op_buf[1], arg_buf[0], arg_buf[1], buf[0], buf[1], buf[0], buf[1], arg_buf[0], arg_buf[1]);
            break;
        case 'b':
            fprintf(output, "%x %c%c\tDCX H\n", instruction_counter, buf[0], buf[1]);
            break;
        case 'c':
            fprintf(output, "%x %c%c\tINR L\n", instruction_counter, buf[0], buf[1]);
            break;
        case 'd':
            fprintf(output, "%x %c%c\tDCR L\n", instruction_counter, buf[0], buf[1]);
            break;
        case 'e':
            op_buf[0] = buf[0];
            op_buf[1] = buf[1];
            empty_buf();
            read_two_op();
            fprintf(output, "%x %c%c %c%c\tMVI L,#%c%c\n", instruction_counter, op_buf[1], op_buf[1], buf[0], buf[1]);
            break;
        case 'f':
            fprintf(output, "%x %c%c\tCMA\n", instruction_counter, buf[0], buf[1]);
            break;
        }
        break;
    case '3':
        switch (buf[1])
        {
        case '0':
            // unallocated
            break;
        case '1':
            op_buf[0] = buf[0];
            op_buf[1] = buf[1];
            empty_buf();
            read_two_op();
            arg_buf[0] = buf[0];
            arg_buf[1] = buf[1];
            empty_buf();
            read_two_op();
            fprintf(output, "%x %c%c %c%c %c%c\tLXI SP,#%c%c%c%c\n", instruction_counter, op_buf[0], op_buf[1], arg_buf[0], arg_buf[1], buf[0], buf[1], buf[0], buf[1], arg_buf[0], arg_buf[1]);
            break;
        case '2':
            op_buf[0] = buf[0];
            op_buf[1] = buf[1];
            empty_buf();
            read_two_op();
            arg_buf[0] = buf[0];
            arg_buf[1] = buf[1];
            empty_buf();
            read_two_op();
            fprintf(output, "%x %c%c %c%c %c%c\tSTA adr\n", instruction_counter, op_buf[0], op_buf[1], arg_buf[0], arg_buf[1], buf[0], buf[1], buf[0], buf[1], arg_buf[0], arg_buf[1]);
            break;
        case '3':
            fprintf(output, "%x %c%c\tINX SP\n", instruction_counter, buf[0], buf[1]);
            break;
        case '4':
            fprintf(output, "%x %c%c\tINR M\n", instruction_counter, buf[0], buf[1]);
            break;
        case '5':
            fprintf(output, "%x %c%c\tDCR M\n", instruction_counter, buf[0], buf[1]);
            break;
        case '6':
            op_buf[0] = buf[0];
            op_buf[1] = buf[1];
            empty_buf();
            read_two_op();
            fprintf(output, "%x %c%c %c%c\tMVI M, D8\n", instruction_counter, op_buf[0], op_buf[1], buf[0], buf[1], buf[0], buf[1]);
            break;
        case '7':
            fprintf(output, "%x %c%c\tSTC\n", instruction_counter, buf[0], buf[1]);
            break;
        case '8':
            // unallocated
            break;
        case '9':
            fprintf(output, "%x %c%c\tDAD SP\n", instruction_counter, buf[0], buf[1]);
            break;
        case 'a':
            op_buf[0] = buf[0];
            op_buf[1] = buf[1];
            empty_buf();
            read_two_op();
            arg_buf[0] = buf[0];
            arg_buf[1] = buf[1];
            empty_buf();
            read_two_op();
            fprintf(output, "%x %c%c %c%c %c%c\tLDA adr\n", instruction_counter, op_buf[0], op_buf[1], arg_buf[0], arg_buf[1], buf[0], buf[1], buf[0], buf[1], arg_buf[0], arg_buf[1]);
            break;
        case 'b':
            fprintf(output, "%x %c%c\tDCX SP\n", instruction_counter, buf[0], buf[1]);
            break;
        case 'c':
            fprintf(output, "%x %c%c\tINR A\n", instruction_counter, buf[0], buf[1]);
            break;
        case 'd':
            fprintf(output, "%x %c%c\tDCR A\n", instruction_counter, buf[0], buf[1]);
            break;
        case 'e':
            op_buf[0] = buf[0];
            op_buf[1] = buf[1];
            empty_buf();
            read_two_op();
            fprintf(output, "%x %c%c %c%c\tMVI A,D8\n", instruction_counter, op_buf[0], op_buf[1], buf[0], buf[1], buf[0], buf[1]);
            break;
        case 'f':
            fprintf(output, "%x %c%c\tCMC\n", instruction_counter, buf[0], buf[1]);
            break;
        }
        break;
    case '4':
        switch (buf[1])
        {
        case '0':
            fprintf(output, "%x %c%c\tMOV B,B\n", instruction_counter, buf[0], buf[1]);
            break;
        case '1':
            fprintf(output, "%x %c%c\tMOV B,C\n", instruction_counter, buf[0], buf[1]);
            break;
        case '2':
            fprintf(output, "%x %c%c\tMOV B,D\n", instruction_counter, buf[0], buf[1]);
            break;
        case '3':
            fprintf(output, "%x %c%c\tMOV B,E\n", instruction_counter, buf[0], buf[1]);
            break;
        case '4':
            fprintf(output, "%x %c%c\tMOV B,H\n", instruction_counter, buf[0], buf[1]);
            break;
        case '5':
            fprintf(output, "%x %c%c\tMOV B,L\n", instruction_counter, buf[0], buf[1]);
            break;
        case '6':
            fprintf(output, "%x %c%c\tMOV B,M\n", instruction_counter, buf[0], buf[1]);
            break;
        case '7':
            fprintf(output, "%x %c%c\tMOV B,A\n", instruction_counter, buf[0], buf[1]);
            break;
        case '8':
            fprintf(output, "%x %c%c\tMOV C,B\n", instruction_counter, buf[0], buf[1]);
            break;
        case '9':
            fprintf(output, "%x %c%c\tMOV C,C\n", instruction_counter, buf[0], buf[1]);
            break;
        case 'a':
            fprintf(output, "%x %c%c\tMOV C,D\n", instruction_counter, buf[0], buf[1]);
            break;
        case 'b':
            fprintf(output, "%x %c%c\tMOV C,E\n", instruction_counter, buf[0], buf[1]);
            break;
        case 'c':
            fprintf(output, "%x %c%c\tMOV C,H\n", instruction_counter, buf[0], buf[1]);
            break;
        case 'd':
            fprintf(output, "%x %c%c\tMOV C,L\n", instruction_counter, buf[0], buf[1]);
            break;
        case 'e':
            fprintf(output, "%x %c%c\tMOV C,M\n", instruction_counter, buf[0], buf[1]);
            break;
        case 'f':
            fprintf(output, "%x %c%c\tMOV C,A\n", instruction_counter, buf[0], buf[1]);
            break;
        }
        break;
    case '5':
        switch (buf[1])
        {
        case '0':
            fprintf(output, "%x %c%c\tMOV D,B\n", instruction_counter, buf[0], buf[1]);
            break;
        case '1':
            fprintf(output, "%x %c%c\tMOV D,C\n", instruction_counter, buf[0], buf[1]);
            break;
        case '2':
            fprintf(output, "%x %c%c\tMOV D,D\n", instruction_counter, buf[0], buf[1]);
            break;
        case '3':
            fprintf(output, "%x %c%c\tMOV D,E\n", instruction_counter, buf[0], buf[1]);
            break;
        case '4':
            fprintf(output, "%x %c%c\tMOV D,H\n", instruction_counter, buf[0], buf[1]);
            break;
        case '5':
            fprintf(output, "%x %c%c\tMOV D,L\n", instruction_counter, buf[0], buf[1]);
            break;
        case '6':
            fprintf(output, "%x %c%c\tMOV D,M\n", instruction_counter, buf[0], buf[1]);
            break;
        case '7':
            fprintf(output, "%x %c%c\tMOV D,A\n", instruction_counter, buf[0], buf[1]);
            break;
        case '8':
            fprintf(output, "%x %c%c\tMOV E,B\n", instruction_counter, buf[0], buf[1]);
            break;
        case '9':
            fprintf(output, "%x %c%c\tMOV E,C\n", instruction_counter, buf[0], buf[1]);
            break;
        case 'a':
            fprintf(output, "%x %c%c\tMOV E,D\n", instruction_counter, buf[0], buf[1]);
            break;
        case 'b':
            fprintf(output, "%x %c%c\tMOV E,E\n", instruction_counter, buf[0], buf[1]);
            break;
        case 'c':
            fprintf(output, "%x %c%c\tMOV E,H\n", instruction_counter, buf[0], buf[1]);
            break;
        case 'd':
            fprintf(output, "%x %c%c\tMOV E,L\n", instruction_counter, buf[0], buf[1]);
            break;
        case 'e':
            fprintf(output, "%x %c%c\tMOV E,M\n", instruction_counter, buf[0], buf[1]);
            break;
        case 'f':
            fprintf(output, "%x %c%c\tMOV E,A\n", instruction_counter, buf[0], buf[1]);
            break;
        }
        break;
    case '6':
        switch (buf[1])
        {
        case '0':
            fprintf(output, "%x %c%c\tMOV D,B\n", instruction_counter, buf[0], buf[1]);
            break;
        case '1':
            fprintf(output, "%x %c%c\tMOV H,C\n", instruction_counter, buf[0], buf[1]);
            break;
        case '2':
            fprintf(output, "%x %c%c\tMOV H,D\n", instruction_counter, buf[0], buf[1]);
            break;
        case '3':
            fprintf(output, "%x %c%c\tMOV H,E\n", instruction_counter, buf[0], buf[1]);
            break;
        case '4':
            fprintf(output, "%x %c%c\tMOV H,H\n", instruction_counter, buf[0], buf[1]);
            break;
        case '5':
            fprintf(output, "%x %c%c\tMOV H,L\n", instruction_counter, buf[0], buf[1]);
            break;
        case '6':
            fprintf(output, "%x %c%c\tMOV H,M\n", instruction_counter, buf[0], buf[1]);
            break;
        case '7':
            fprintf(output, "%x %c%c\tMOV H,A\n", instruction_counter, buf[0], buf[1]);
            break;
        case '8':
            fprintf(output, "%x %c%c\tMOV L,B\n", instruction_counter, buf[0], buf[1]);
            break;
        case '9':
            fprintf(output, "%x %c%c\tMOV L,C\n", instruction_counter, buf[0], buf[1]);
            break;
        case 'a':
            fprintf(output, "%x %c%c\tMOV L,D\n", instruction_counter, buf[0], buf[1]);
            break;
        case 'b':
            fprintf(output, "%x %c%c\tMOV L,E\n", instruction_counter, buf[0], buf[1]);
            break;
        case 'c':
            fprintf(output, "%x %c%c\tMOV L,H\n", instruction_counter, buf[0], buf[1]);
            break;
        case 'd':
            fprintf(output, "%x %c%c\tMOV L,L\n", instruction_counter, buf[0], buf[1]);
            break;
        case 'e':
            fprintf(output, "%x %c%c\tMOV L,M\n", instruction_counter, buf[0], buf[1]);
            break;
        case 'f':
            fprintf(output, "%x %c%c\tMOV L,A\n", instruction_counter, buf[0], buf[1]);
            break;
        }
        break;
    case '7':
        switch (buf[1])
        {
        case '0':
            fprintf(output, "%x %c%c\tMOV M,B\n", instruction_counter, buf[0], buf[1]);
            break;
        case '1':
            fprintf(output, "%x %c%c\tMOV M,C\n", instruction_counter, buf[0], buf[1]);
            break;
        case '2':
            fprintf(output, "%x %c%c\tMOV M,D\n", instruction_counter, buf[0], buf[1]);
            break;
        case '3':
            fprintf(output, "%x %c%c\tMOV M,E\n", instruction_counter, buf[0], buf[1]);
            break;
        case '4':
            fprintf(output, "%x %c%c\tMOV M,H\n", instruction_counter, buf[0], buf[1]);
            break;
        case '5':
            fprintf(output, "%x %c%c\tMOV M,L\n", instruction_counter, buf[0], buf[1]);
            break;
        case '6':
            fprintf(output, "%x %c%c\tHLT\n", instruction_counter, buf[0], buf[1]);
            break;
        case '7':
            fprintf(output, "%x %c%c\tMOV M,A\n", instruction_counter, buf[0], buf[1]);
            break;
        case '8':
            fprintf(output, "%x %c%c\tMOV A,B\n", instruction_counter, buf[0], buf[1]);
            break;
        case '9':
            fprintf(output, "%x %c%c\tMOV A,C\n", instruction_counter, buf[0], buf[1]);
            break;
        case 'a':
            fprintf(output, "%x %c%c\tMOV A,D\n", instruction_counter, buf[0], buf[1]);
            break;
        case 'b':
            fprintf(output, "%x %c%c\tMOV A,E\n", instruction_counter, buf[0], buf[1]);
            break;
        case 'c':
            fprintf(output, "%x %c%c\tMOV A,H\n", instruction_counter, buf[0], buf[1]);
            break;
        case 'd':
            fprintf(output, "%x %c%c\tMOV A,L\n", instruction_counter, buf[0], buf[1]);
            break;
        case 'e':
            fprintf(output, "%x %c%c\tMOV A,M\n", instruction_counter, buf[0], buf[1]);
            break;
        case 'f':
            fprintf(output, "%x %c%c\tMOV A,A\n", instruction_counter, buf[0], buf[1]);
            break;
        }
        break;
    case '8':
        switch (buf[1])
        {
        case '0':
            fprintf(output, "%x %c%c\tADD B\n", instruction_counter, buf[0], buf[1]);
            break;
        case '1':
            fprintf(output, "%x %c%c\tADD C\n", instruction_counter, buf[0], buf[1]);
            break;
        case '2':
            fprintf(output, "%x %c%c\tADD D\n", instruction_counter, buf[0], buf[1]);
            break;
        case '3':
            fprintf(output, "%x %c%c\tADD E\n", instruction_counter, buf[0], buf[1]);
            break;
        case '4':
            fprintf(output, "%x %c%c\tADD H\n", instruction_counter, buf[0], buf[1]);
            break;
        case '5':
            fprintf(output, "%x %c%c\tADD L\n", instruction_counter, buf[0], buf[1]);
            break;
        case '6':
            fprintf(output, "%x %c%c\tADD M\n", instruction_counter, buf[0], buf[1]);
            break;
        case '7':
            fprintf(output, "%x %c%c\tADD A\n", instruction_counter, buf[0], buf[1]);
            break;
        case '8':
            fprintf(output, "%x %c%c\tADC B\n", instruction_counter, buf[0], buf[1]);
            break;
        case '9':
            fprintf(output, "%x %c%c\tADC C\n", instruction_counter, buf[0], buf[1]);
            break;
        case 'a':
            fprintf(output, "%x %c%c\tACD D\n", instruction_counter, buf[0], buf[1]);
            break;
        case 'b':
            fprintf(output, "%x %c%c\tACD E\n", instruction_counter, buf[0], buf[1]);
            break;
        case 'c':
            fprintf(output, "%x %c%c\tACD H\n", instruction_counter, buf[0], buf[1]);
            break;
        case 'd':
            fprintf(output, "%x %c%c\tACD L\n", instruction_counter, buf[0], buf[1]);
            break;
        case 'e':
            fprintf(output, "%x %c%c\tADC M\n", instruction_counter, buf[0], buf[1]);
            break;
        case 'f':
            fprintf(output, "%x %c%c\tADC A\n", instruction_counter, buf[0], buf[1]);
            break;
        }
        break;
    case '9':
        switch (buf[1])
        {
        case '0':
            fprintf(output, "%x %c%c\tSUB B\n", instruction_counter, buf[0], buf[1]);
            break;
        case '1':
            fprintf(output, "%x %c%c\tSUB C\n", instruction_counter, buf[0], buf[1]);
            break;
        case '2':
            fprintf(output, "%x %c%c\tSUB D\n", instruction_counter, buf[0], buf[1]);
            break;
        case '3':
            fprintf(output, "%x %c%c\tSUB E\n", instruction_counter, buf[0], buf[1]);
            break;
        case '4':
            fprintf(output, "%x %c%c\tSUB H\n", instruction_counter, buf[0], buf[1]);
            break;
        case '5':
            fprintf(output, "%x %c%c\tSUB L\n", instruction_counter, buf[0], buf[1]);
            break;
        case '6':
            fprintf(output, "%x %c%c\tSUB M\n", instruction_counter, buf[0], buf[1]);
            break;
        case '7':
            fprintf(output, "%x %c%c\tSUB A\n", instruction_counter, buf[0], buf[1]);
            break;
        case '8':
            fprintf(output, "%x %c%c\tSBB B\n", instruction_counter, buf[0], buf[1]);
            break;
        case '9':
            fprintf(output, "%x %c%c\tSBB C\n", instruction_counter, buf[0], buf[1]);
            break;
        case 'a':
            fprintf(output, "%x %c%c\tSBB D\n", instruction_counter, buf[0], buf[1]);
            break;
        case 'b':
            fprintf(output, "%x %c%c\tSBB E\n", instruction_counter, buf[0], buf[1]);
            break;
        case 'c':
            fprintf(output, "%x %c%c\tSBB H\n", instruction_counter, buf[0], buf[1]);
            break;
        case 'd':
            fprintf(output, "%x %c%c\tSBB L\n", instruction_counter, buf[0], buf[1]);
            break;
        case 'e':
            fprintf(output, "%x %c%c\tSBB M\n", instruction_counter, buf[0], buf[1]);
            break;
        case 'f':
            fprintf(output, "%x %c%c\tSBB A\n", instruction_counter, buf[0], buf[1]);
            break;
        }
        break;
    case 'a':
        switch (buf[1])
        {
        case '0':
            fprintf(output, "%x %c%c\tANA B\n", instruction_counter, buf[0], buf[1]);
            break;
        case '1':
            fprintf(output, "%x %c%c\tANA C\n", instruction_counter, buf[0], buf[1]);
            break;
        case '2':
            fprintf(output, "%x %c%c\tANA D\n", instruction_counter, buf[0], buf[1]);
            break;
        case '3':
            fprintf(output, "%x %c%c\tANA E\n", instruction_counter, buf[0], buf[1]);
            break;
        case '4':
            fprintf(output, "%x %c%c\tANA H\n", instruction_counter, buf[0], buf[1]);
            break;
        case '5':
            fprintf(output, "%x %c%c\tANA L\n", instruction_counter, buf[0], buf[1]);
            break;
        case '6':
            fprintf(output, "%x %c%c\tANA M\n", instruction_counter, buf[0], buf[1]);
            break;
        case '7':
            fprintf(output, "%x %c%c\tANA A\n", instruction_counter, buf[0], buf[1]);
            break;
        case '8':
            fprintf(output, "%x %c%c\tXRA B\n", instruction_counter, buf[0], buf[1]);
            break;
        case '9':
            fprintf(output, "%x %c%c\tXRA C\n", instruction_counter, buf[0], buf[1]);
            break;
        case 'a':
            fprintf(output, "%x %c%c\tXRA D\n", instruction_counter, buf[0], buf[1]);
            break;
        case 'b':
            fprintf(output, "%x %c%c\tXRA E\n", instruction_counter, buf[0], buf[1]);
            break;
        case 'c':
            fprintf(output, "%x %c%c\tXRA H\n", instruction_counter, buf[0], buf[1]);
            break;
        case 'd':
            fprintf(output, "%x %c%c\tXRA L\n", instruction_counter, buf[0], buf[1]);
            break;
        case 'e':
            fprintf(output, "%x %c%c\tXRA M\n", instruction_counter, buf[0], buf[1]);
            break;
        case 'f':
            fprintf(output, "%x %c%c\tXRA A\n", instruction_counter, buf[0], buf[1]);
            break;
        }
        break;
    case 'b':
        switch (buf[1])
        {
        case '0':
            fprintf(output, "%x %c%c\tORA B\n", instruction_counter, buf[0], buf[1]);
            break;
        case '1':
            fprintf(output, "%x %c%c\tORA C\n", instruction_counter, buf[0], buf[1]);
            break;
        case '2':
            fprintf(output, "%x %c%c\tORA D\n", instruction_counter, buf[0], buf[1]);
            break;
        case '3':
            fprintf(output, "%x %c%c\tORA E\n", instruction_counter, buf[0], buf[1]);
            break;
        case '4':
            fprintf(output, "%x %c%c\tORA H\n", instruction_counter, buf[0], buf[1]);
            break;
        case '5':
            fprintf(output, "%x %c%c\tORA L\n", instruction_counter, buf[0], buf[1]);
            break;
        case '6':
            fprintf(output, "%x %c%c\tORA M\n", instruction_counter, buf[0], buf[1]);
            break;
        case '7':
            fprintf(output, "%x %c%c\tORA A\n", instruction_counter, buf[0], buf[1]);
            break;
        case '8':
            fprintf(output, "%x %c%c\tCMP B\n", instruction_counter, buf[0], buf[1]);
            break;
        case '9':
            fprintf(output, "%x %c%c\tCMP C\n", instruction_counter, buf[0], buf[1]);
            break;
        case 'a':
            fprintf(output, "%x %c%c\tCMP D\n", instruction_counter, buf[0], buf[1]);
            break;
        case 'b':
            fprintf(output, "%x %c%c\tCMP E\n", instruction_counter, buf[0], buf[1]);
            break;
        case 'c':
            fprintf(output, "%x %c%c\tCMP H\n", instruction_counter, buf[0], buf[1]);
            break;
        case 'd':
            fprintf(output, "%x %c%c\tCMP L\n", instruction_counter, buf[0], buf[1]);
            break;
        case 'e':
            fprintf(output, "%x %c%c\tCMP M\n", instruction_counter, buf[0], buf[1]);
            break;
        case 'f':
            fprintf(output, "%x %c%c\tCMP A\n", instruction_counter, buf[0], buf[1]);
            break;
        }
        break;
    case 'c':
        switch (buf[1])
        {
        case '0':
            fprintf(output, "%x %c%c\tRNZ\n", instruction_counter, buf[0], buf[1]);
            break;
        case '1':
            fprintf(output, "%x %c%c\tPOP B\n", instruction_counter, buf[0], buf[1]);
            break;
        case '2':
            op_buf[0] = buf[0];
            op_buf[1] = buf[1];
            empty_buf();
            read_two_op();
            arg_buf[0] = buf[0];
            arg_buf[1] = buf[1];
            empty_buf();
            read_two_op();
            fprintf(output, "%x %c%c %c%c %c%c\tJNZ $%c%c%c%c\n", instruction_counter, op_buf[0], op_buf[1], arg_buf[0], arg_buf[1], buf[0], buf[1], buf[0], buf[1], arg_buf[0], arg_buf[1]);
            break;
        case '3':
            op_buf[0] = buf[0];
            op_buf[1] = buf[1];
            empty_buf();
            read_two_op();
            arg_buf[0] = buf[0];
            arg_buf[1] = buf[1];
            empty_buf();
            read_two_op();
            fprintf(output, "%x %c%c %c%c %c%c\tJMP $%c%c%c%c\n", instruction_counter, op_buf[0], op_buf[1], arg_buf[0], arg_buf[1], buf[0], buf[1], arg_buf[0], arg_buf[1], buf[0], buf[1], buf[0], buf[1], arg_buf[0], arg_buf[1]);
            break;
        case '4':
            fprintf(output, "%x %c%c\tORA H\n", instruction_counter, buf[0], buf[1]);
            break;
        case '5':
            op_buf[0] = buf[0];
            op_buf[1] = buf[1];
            empty_buf();
            read_two_op();
            arg_buf[0] = buf[0];
            arg_buf[1] = buf[1];
            empty_buf();
            read_two_op();
            fprintf(output, "%x %c%c %c%c %c%c\tCNZ $%c%c%c%c\n", instruction_counter, op_buf[0], op_buf[1], arg_buf[0], arg_buf[1], buf[0], buf[1], buf[0], buf[1], arg_buf[0], arg_buf[1]);
            break;
        case '6':
            op_buf[0] = buf[0];
            op_buf[1] = buf[1];
            empty_buf();
            read_two_op();
            fprintf(output, "%x %c%c %c%c\tADI #%c%c\n", instruction_counter, op_buf[0], op_buf[1], buf[0], buf[1], buf[0], buf[1]);
            break;
        case '7':
            fprintf(output, "%x %c%c\tRST 0\n", instruction_counter, buf[0], buf[1]);
            break;
        case '8':
            fprintf(output, "%x %c%c\tRZ\n", instruction_counter, buf[0], buf[1]);
            break;
        case '9':
            fprintf(output, "%x %c%c\tRET\n", instruction_counter, buf[0], buf[1]);
            break;
        case 'a':
            op_buf[0] = buf[0];
            op_buf[1] = buf[1];
            empty_buf();
            read_two_op();
            arg_buf[0] = buf[0];
            arg_buf[1] = buf[1];
            empty_buf();
            read_two_op();
            fprintf(output, "%x %c%c %c%c %c%c\tLZ $%c%c%c%c\n", instruction_counter, op_buf[0], op_buf[1], arg_buf[0], arg_buf[1], buf[0], buf[1], buf[0], buf[1], arg_buf[0], arg_buf[1]);
            break;
        case 'b':
            // unallocated
            break;
        case 'c':
            op_buf[0] = buf[0];
            op_buf[1] = buf[1];
            empty_buf();
            read_two_op();
            arg_buf[0] = buf[0];
            arg_buf[1] = buf[1];
            empty_buf();
            read_two_op();
            fprintf(output, "%x %c%c %c%c %c%c\tCZ $%c%c%c%c\n", instruction_counter, op_buf[0], op_buf[1], arg_buf[0], arg_buf[1], buf[0], buf[1], buf[0], buf[1], arg_buf[0], arg_buf[1]);
            break;
        case 'd':
            op_buf[0] = buf[0];
            op_buf[1] = buf[1];
            empty_buf();
            read_two_op();
            arg_buf[0] = buf[0];
            arg_buf[1] = buf[1];
            empty_buf();
            read_two_op();
            fprintf(output, "%x %c%c %c%c %c%c\tCALL $%c%c%c%c\n", instruction_counter, op_buf[0], op_buf[1], arg_buf[0], arg_buf[1], buf[0], buf[1], buf[0], buf[1], arg_buf[0], arg_buf[1]);
            break;
        case 'e':
            op_buf[0] = buf[0];
            op_buf[1] = buf[1];
            empty_buf();
            read_two_op();
            fprintf(output, "%x %c%c %c%c\tACI #%c%c\n", instruction_counter, op_buf[0], op_buf[1], buf[0], buf[1], buf[0], buf[1]);
            break;
        case 'f':
            fprintf(output, "%x %c%c\tRST 1\n", instruction_counter, buf[0], buf[1]);
            break;
        }
        break;
    case 'd':
        switch (buf[1])
        {
        case '0':
            fprintf(output, "%x %c%c\tRNC\n", instruction_counter, buf[0], buf[1]);
            break;
        case '1':
            fprintf(output, "%x %c%c\tPOP D\n", instruction_counter, buf[0], buf[1]);
            break;
        case '2':
            op_buf[0] = buf[0];
            op_buf[1] = buf[1];
            empty_buf();
            read_two_op();
            arg_buf[0] = buf[0];
            arg_buf[1] = buf[1];
            empty_buf();
            read_two_op();
            fprintf(output, "%x %c%c %c%c %c%c\tJNC $%c%c%c%c\n", instruction_counter, op_buf[0], op_buf[1], arg_buf[0], arg_buf[1], buf[0], buf[1], buf[0], buf[1], arg_buf[0], arg_buf[1]);
            break;
        case '3':
            op_buf[0] = buf[0];
            op_buf[1] = buf[1];
            empty_buf();
            read_two_op();
            fprintf(output, "%x %c%c %c%c\tOUT #%c%c\n", instruction_counter, op_buf[0], op_buf[1], buf[0], buf[1], buf[0], buf[1]);
            break;
        case '4':
            op_buf[0] = buf[0];
            op_buf[1] = buf[1];
            empty_buf();
            read_two_op();
            arg_buf[0] = buf[0];
            arg_buf[1] = buf[1];
            empty_buf();
            read_two_op();
            fprintf(output, "%x %c%c %c%c %c%c\tCNC $%c%c%c%c\n", instruction_counter, op_buf[0], op_buf[1], arg_buf[0], arg_buf[1], buf[0], buf[1], buf[0], buf[1], arg_buf[0], arg_buf[1]);
            break;
        case '5':
            fprintf(output, "%x %c%c\tPUSH D\n", instruction_counter, buf[0], buf[1]);
            break;
        case '6':
            op_buf[0] = buf[0];
            op_buf[1] = buf[1];
            empty_buf();
            read_two_op();
            fprintf(output, "%x %c%c %c%c\tSUI #%c%c\n", instruction_counter, op_buf[0], op_buf[1], buf[0], buf[1], buf[0], buf[1]);
            break;
        case '7':
            fprintf(output, "%x %c%c\tRST 2\n", instruction_counter, buf[0], buf[1]);
            break;
        case '8':
            fprintf(output, "%x %c%c\tRC\n", instruction_counter, buf[0], buf[1]);
            break;
        case '9':
            // unallocated
            break;
        case 'a':
            op_buf[0] = buf[0];
            op_buf[1] = buf[1];
            empty_buf();
            read_two_op();
            arg_buf[0] = buf[0];
            arg_buf[1] = buf[1];
            empty_buf();
            read_two_op();
            fprintf(output, "%x %c%c %c%c %c%c\tJC $%c%c%c%c\n", instruction_counter, op_buf[0], op_buf[1], arg_buf[0], arg_buf[1], buf[0], buf[1], buf[0], buf[1], arg_buf[0], arg_buf[1]);
            break;
        case 'b':
            op_buf[0] = buf[0];
            op_buf[1] = buf[1];
            empty_buf();
            read_two_op();
            fprintf(output, "%x %c%c %c%c\tIN #%c%c\n", instruction_counter, op_buf[0], op_buf[1], buf[0], buf[1], buf[0], buf[1]);
            break;
        case 'c':
            op_buf[0] = buf[0];
            op_buf[1] = buf[1];
            empty_buf();
            read_two_op();
            arg_buf[0] = buf[0];
            arg_buf[1] = buf[1];
            empty_buf();
            read_two_op();
            fprintf(output, "%x %c%c %c%c %c%c\tCC $%c%c%c%c\n", instruction_counter, op_buf[0], op_buf[1], arg_buf[0], arg_buf[1], buf[0], buf[1], buf[0], buf[1], arg_buf[0], arg_buf[1]);
            break;
        case 'd':
            // unallocated
            break;
        case 'e':
            op_buf[0] = buf[0];
            op_buf[1] = buf[1];
            empty_buf();
            read_two_op();
            fprintf(output, "%x %c%c %c%c\tSBI #%c%c\n", instruction_counter, op_buf[0], op_buf[1], buf[0], buf[1], buf[0], buf[1]);
            break;
        case 'f':
            fprintf(output, "%x %c%c\tRST 3\n", instruction_counter, buf[0], buf[1]);
            break;
        }
        break;
    case 'e':
        switch (buf[1])
        {
        case '0':
            fprintf(output, "%x %c%c\tRPO\n", instruction_counter, buf[0], buf[1]);
            break;
        case '1':
            fprintf(output, "%x %c%c\tPOP H\n", instruction_counter, buf[0], buf[1]);
            break;
        case '2':
            op_buf[0] = buf[0];
            op_buf[1] = buf[1];
            empty_buf();
            read_two_op();
            arg_buf[0] = buf[0];
            arg_buf[1] = buf[1];
            empty_buf();
            read_two_op();
            fprintf(output, "%x %c%c %c%c %c%c\tJPO $%c%c%c%c\n", instruction_counter, op_buf[0], op_buf[1], arg_buf[0], arg_buf[1], buf[0], buf[1], buf[0], buf[1], arg_buf[0], arg_buf[1]);
            break;
        case '3':
            fprintf(output, "%x %c%c\tXTHL\n", instruction_counter, buf[0], buf[1]);
            break;
        case '4':
            op_buf[0] = buf[0];
            op_buf[1] = buf[1];
            empty_buf();
            read_two_op();
            arg_buf[0] = buf[0];
            arg_buf[1] = buf[1];
            empty_buf();
            read_two_op();
            fprintf(output, "%x %c%c %c%c %c%c\tCPO $%c%c%c%c\n", instruction_counter, op_buf[0], op_buf[1], arg_buf[0], arg_buf[1], buf[0], buf[1], buf[0], buf[1], arg_buf[0], arg_buf[1]);
            break;
        case '5':
            fprintf(output, "%x %c%c\tPUSH H\n", instruction_counter, buf[0], buf[1]);
            break;
        case '6':
            op_buf[0] = buf[0];
            op_buf[1] = buf[1];
            empty_buf();
            read_two_op();
            fprintf(output, "%x %c%c %c%c\tANI #%c%c\n", instruction_counter, op_buf[0], op_buf[1], buf[0], buf[1], buf[0], buf[1]);
            break;
        case '7':
            fprintf(output, "%x %c%c\tRST 4\n", instruction_counter, buf[0], buf[1]);
            break;
        case '8':
            fprintf(output, "%x %c%c\tRPE\n", instruction_counter, buf[0], buf[1]);
            break;
        case '9':
            fprintf(output, "%x %c%c\tPHCL\n", instruction_counter, buf[0], buf[1]);
            break;
        case 'a':
            op_buf[0] = buf[0];
            op_buf[1] = buf[1];
            empty_buf();
            read_two_op();
            arg_buf[0] = buf[0];
            arg_buf[1] = buf[1];
            empty_buf();
            read_two_op();
            fprintf(output, "%x %c%c %c%c %c%c\tJPE $%c%c%c%c\n", instruction_counter, op_buf[0], op_buf[1], arg_buf[0], arg_buf[1], buf[0], buf[1], buf[0], buf[1], arg_buf[0], arg_buf[1]);
            break;
        case 'b':
            op_buf[0] = buf[0];
            op_buf[1] = buf[1];
            empty_buf();
            read_two_op();
            fprintf(output, "%x %c%c %c%c\tXCHG\n", instruction_counter, op_buf[0], op_buf[1], buf[0], buf[1], buf[0], buf[1]);
            break;
        case 'c':
            op_buf[0] = buf[0];
            op_buf[1] = buf[1];
            empty_buf();
            read_two_op();
            arg_buf[0] = buf[0];
            arg_buf[1] = buf[1];
            empty_buf();
            read_two_op();
            fprintf(output, "%x %c%c %c%c\tCPE $%c%c%c%c\n", instruction_counter, op_buf[0], op_buf[1], arg_buf[0], arg_buf[1], buf[0], buf[1], buf[0], buf[1], arg_buf[0], arg_buf[1]);
            break;
        case 'd':
            // unallocated
            break;
        case 'e':
            op_buf[0] = buf[0];
            op_buf[1] = buf[1];
            empty_buf();
            read_two_op();
            fprintf(output, "%x %c%c %c%c\tXRI #%c%c\n", instruction_counter, op_buf[0], op_buf[1], buf[0], buf[1], buf[0], buf[1]);
            break;
        case 'f':
            fprintf(output, "%x %c%c\tRST 5\n", instruction_counter, buf[0], buf[1]);
            break;
        }
        break;
    case 'f':
        switch (buf[1])
        {
        case '0':
            fprintf(output, "%x %c%c\tRP\n", instruction_counter, buf[0], buf[1]);
            break;
        case '1':
            fprintf(output, "%x %c%c\tPOP PSW\n", instruction_counter, buf[0], buf[1]);
            break;
        case '2':
            op_buf[0] = buf[0];
            op_buf[1] = buf[1];
            empty_buf();
            read_two_op();
            arg_buf[0] = buf[0];
            arg_buf[1] = buf[1];
            empty_buf();
            read_two_op();
            fprintf(output, "%x %c%c %c%c %c%c\tJP $%c%c%c%c\n", instruction_counter, op_buf[0], op_buf[1], arg_buf[0], arg_buf[1], buf[0], buf[1], buf[0], buf[1], arg_buf[0], arg_buf[1]);
            break;
        case '3':
            fprintf(output, "%x %c%c\tDI\n", instruction_counter, buf[0], buf[1]);
            break;
        case '4':
            op_buf[0] = buf[0];
            op_buf[1] = buf[1];
            empty_buf();
            read_two_op();
            arg_buf[0] = buf[0];
            arg_buf[1] = buf[1];
            empty_buf();
            read_two_op();
            fprintf(output, "%x %c%c %c%c %c%c\tCP $%c%c%c%c\n", instruction_counter, op_buf[0], op_buf[1], arg_buf[0], arg_buf[1], buf[0], buf[1], buf[0], buf[1], arg_buf[0], arg_buf[1]);
            break;
        case '5':
            fprintf(output, "%x %c%c\tPUSH PSW\n", instruction_counter, buf[0], buf[1]);
            break;
        case '6':
            op_buf[0] = buf[0];
            op_buf[1] = buf[1];
            empty_buf();
            read_two_op();
            fprintf(output, "%x %c%c %c%c %c%c\tORI #%c%c\n", instruction_counter, op_buf[0], op_buf[1], buf[0], buf[1], buf[0], buf[1]);
            break;
        case '7':
            fprintf(output, "%x %c%c\tRST 6\n", instruction_counter, buf[0], buf[1]);
            break;
        case '8':
            fprintf(output, "%x %c%c\tRM\n", instruction_counter, buf[0], buf[1]);
            break;
        case '9':
            fprintf(output, "%x %c%c\tSPHL\n", instruction_counter, buf[0], buf[1]);
            break;
        case 'a':
            op_buf[0] = buf[0];
            op_buf[1] = buf[1];
            empty_buf();
            read_two_op();
            arg_buf[0] = buf[0];
            arg_buf[1] = buf[1];
            empty_buf();
            read_two_op();
            fprintf(output, "%x %c%c %c%c %c%c\tJM $%c%c%c%c\n", instruction_counter, op_buf[0], op_buf[1], arg_buf[0], arg_buf[1], buf[0], buf[1], buf[0], buf[1], arg_buf[0], arg_buf[1]);
            break;
        case 'b':
            fprintf(output, "%x %c%c\tEI\n", instruction_counter, buf[0], buf[1]);
            break;
        case 'c':
            op_buf[0] = buf[0];
            op_buf[1] = buf[1];
            empty_buf();
            read_two_op();
            arg_buf[0] = buf[0];
            arg_buf[1] = buf[1];
            empty_buf();
            read_two_op();
            fprintf(output, "%x %c%c %c%c %c%c\tCM $%c%c%c%c\n", instruction_counter, op_buf[0], op_buf[1], arg_buf[0], arg_buf[1], buf[0], buf[1], buf[0], buf[1], arg_buf[0], arg_buf[1]);
            break;
        case 'd':
            // unallocated
            break;
        case 'e':
            op_buf[0] = buf[0];
            op_buf[1] = buf[1];
            empty_buf();
            read_two_op();
            fprintf(output, "%x %c%c %c%c\tCPI #%c%c\n", instruction_counter, op_buf[0], op_buf[1], buf[0], buf[1], buf[0], buf[1]);
            break;
        case 'f':
            fprintf(output, "%x %c%c\tRST 7\n", instruction_counter, buf[0], buf[1]);
            break;
        }
        break;
    default:
        return;
    }
    instruction_counter++;
}

int load_op()
{
    next = fgetc(input);
    if (next == ' ')
    {
        return 0;
    }
    else if (next == '!')
    {
        return 1;
    }
    else if (next == '\n')
    {
        for (int i = 0; i < 8; i++)
        {
            next = fgetc(input);
            if (next == '*')
            {
                skip_n(9);
                return 0;
            }
        }
    }
    else
    {
        if (buf[0] == '*')
        {
            buf[0] = next;
            return 2;
        }
        else
        {
            buf[1] = next;
            return 3;
        }
    }
}

void dissassemble(char *file_name)
{
    input = fopen(file_name, "r");
    output = fopen("dissassembled.asm", "w");
    buf[0] = '*';
    buf[1] = '*';
    skip_n(8);

    while (1)
    {
        int ret_val = load_op();
        if (ret_val == 1)
        {
            break;
        }
        else if (ret_val == 3)
        {
            process_op(buf);
            buf[0] = '*';
        }
    }
    fclose(output);
}

int main()
{
    dissassemble("dump.txt");
}
