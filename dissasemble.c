#include <stdio.h>

FILE *input;
FILE *output;

int load_op();

int instruction_counter = 0x0000;

char buf[2];
char next;

void skip_n(int n)
{
    for (int i = 0; i < n; i++)
    {
        fgetc(input);
    }
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
            fprintf(output, "%x %c%c\tNOP", instruction_counter, buf[0], buf[1]);
            break;
        case '1':
            op_buf[0] = buf[0];
            op_buf[1] = buf[1];
            load_op();
            arg_buf[0] = buf[0];
            arg_buf[1] = buf[1];
            load_op();
            fprintf(output, "%x %c%c %c%c %c%c\tLXI B,#%c%c", instruction_counter, op_buf[0], op_buf[1], arg_buf[0], arg_buf[1], buf[0], buf[1], buf[0], buf[1], arg_buf[0], arg_buf[1]);
            break;
        case '2':
            fprintf(output, "%x %c%c\tSTAX B", instruction_counter, buf[0], buf[1]);
            break;
        case '3':
            fprintf(output, "%x %c%c\tINX B", instruction_counter, buf[0], buf[1]);
            break;
        case '4':
            fprintf(output, "%x %c%c\tINR B", instruction_counter, buf[0], buf[1]);
            break;
        case '5':
            fprintf(output, "%x %c%c\tDCR B", instruction_counter, buf[0], buf[1]);
            break;
        case '6':
            op_buf[0] = buf[0];
            op_buf[1] = buf[1];
            load_op();
            fprintf(output, "%x %c%c %c%c\tMVI B,#%c%c", instruction_counter, op_buf[0], op_buf[1], buf[0], buf[1], buf[0], buf[1]);
            break;
        case '7':
            fprintf(output, "%x %c%c\tRLC", instruction_counter, buf[0], buf[1]);
            break;
        case '8':
            // unallocated
            break;
        case '9':
            fprintf(output, "%x %c%c\tDAD B", instruction_counter, buf[0], buf[1]);
            break;
        case 'a':
            fprintf(output, "%x %c%c\tLDAX B", instruction_counter, buf[0], buf[1]);
            break;
        case 'b':
            fprintf(output, "%x %c%c\tDCX B", instruction_counter, buf[0], buf[1]);
            break;
        case 'c':
            fprintf(output, "%x %c%c\tINR C", instruction_counter, buf[0], buf[1]);
            break;
        case 'd':
            fprintf(output, "%x %c%c\tDCR C", instruction_counter, buf[0], buf[1]);
            break;
        case 'e':
            op_buf[0] = buf[0];
            op_buf[1] = buf[1];
            load_op();
            fprintf(output, "%x %c%c %c%c\tMVI C,#%c%c", instruction_counter, op_buf[0], op_buf[1], buf[0], buf[0], buf[0], buf[0]);
            break;
        case 'f':
            fprintf(output, "%x %c%c\tRRC", instruction_counter, buf[0], buf[1]);
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
            load_op();
            arg_buf[0] = buf[0];
            arg_buf[1] = buf[1];
            load_op();
            fprintf(output, "%x %c%c %c%c %c%c\tLXI D,#%c%c%c%c", instruction_counter, op_buf[0], op_buf[1], arg_buf[0], arg_buf[1], buf[0], buf[1], buf[0], buf[1], arg_buf[0], arg_buf[1]);
            break;
        case '2':
            fprintf(output, "%x %c%c\tSTAX D", instruction_counter, buf[0], buf[1]);
            break;
        case '3':
            fprintf(output, "%x %c%c\tINX D", instruction_counter, buf[0], buf[1]);
            break;
        case '4':
            fprintf(output, "%x %c%c\tINR D", instruction_counter, buf[0], buf[1]);
            break;
        case '5':
            fprintf(output, "%x %c%c\tDCR D", instruction_counter, buf[0], buf[1]);
            break;
        case '6':
            op_buf[0] = buf[0];
            op_buf[1] = buf[1];
            load_op();
            fprintf(output, "%x %c%c %c%c\tMVI D,#%c%c", instruction_counter, op_buf[0], op_buf[1], buf[0], buf[1], buf[0], buf[1]);
            break;
        case '7':
            fprintf(output, "%x %c%c\tRAL", instruction_counter, buf[0], buf[1]);
            break;
        case '8':
            // unallocated
            break;
        case '9':
            fprintf(output, "%x %c%c\tDAD D", instruction_counter, buf[0], buf[1]);
            break;
        case 'a':
            fprintf(output, "%x %c%c\tLDAX D", instruction_counter, buf[0], buf[1]);
            break;
        case 'b':
            fprintf(output, "%x %c%c\tDCX D", instruction_counter, buf[0], buf[1]);
            break;
        case 'c':
            fprintf(output, "%x %c%c\tINR E", instruction_counter, buf[0], buf[1]);
            break;
        case 'd':
            fprintf(output, "%x %c%c\tDCR E", instruction_counter, buf[0], buf[1]);
            break;
        case 'e':
            op_buf[0] = buf[0];
            op_buf[1] = buf[1];
            load_op();
            fprintf(output, "%x %c%c %c%c\tMVI E,#%c%c", instruction_counter, op_buf[0], op_buf[1], buf[0], buf[1], buf[0], buf[1]);
            break;
        case 'f':
            fprintf(output, "%x %c%c\tRAR", instruction_counter, buf[0], buf[1]);
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
            load_op();
            arg_buf[0] = buf[0];
            arg_buf[1] = buf[1];
            load_op();
            fprintf(output, "%x %c%c %c%c %c%c\tLXI H,#%c%c%c%c", instruction_counter, op_buf[0], op_buf[1], arg_buf[0], arg_buf[1], buf[0], buf[1], buf[0], buf[1], arg_buf[0], arg_buf[1]);
            break;
        case '2':
            op_buf[0] = buf[0];
            op_buf[1] = buf[1];
            load_op();
            arg_buf[0] = buf[0];
            arg_buf[1] = buf[1];
            load_op();
            fprintf(output, "%x %c%c %c%c %c%c\tSHLD $%c%c%c%c", instruction_counter, op_buf[0], op_buf[1], arg_buf[0], arg_buf[1], buf[0], buf[1], buf[0], buf[1], arg_buf[0], arg_buf[1]);
            break;
        case '3':
            fprintf(output, "%x %c%c\tINX H", instruction_counter, buf[0], buf[1]);
            break;
        case '4':
            fprintf(output, "%x %c%c\tINR H", instruction_counter, buf[0], buf[1]);
            break;
        case '5':
            fprintf(output, "%x %c%c\tDCR H", instruction_counter, buf[0], buf[1]);
            break;
        case '6':
            op_buf[0] = buf[0];
            op_buf[1] = buf[0];
            load_op();
            fprintf(output, "%x %c%c %c%c\tMVI H,#%c%c", instruction_counter, op_buf[0], op_buf[1], buf[0], buf[1], buf[0], buf[1]);
            break;
        case '7':
            fprintf(output, "%x %c%c\tDAA", instruction_counter, buf[0], buf[1]);
            break;
        case '8':
            // unallocated
            break;
        case '9':
            fprintf(output, "%x %c%c\tDAD H", instruction_counter, buf[0], buf[1]);
            break;
        case 'a':
            op_buf[0] = buf[0];
            op_buf[1] = buf[1];
            load_op();
            arg_buf[0] = buf[0];
            arg_buf[1] = buf[1];
            load_op();
            fprintf(output, "%x %c%c %c%c %c%c\tLHLD $%c%c%c%c", instruction_counter, op_buf[0], op_buf[1], arg_buf[0], arg_buf[1], buf[0], buf[1], buf[0], buf[1], arg_buf[0], arg_buf[1]);
            break;
        case 'b':
            fprintf(output, "%x %c%c\tDCX H", instruction_counter, buf[0], buf[1]);
            break;
        case 'c':
            fprintf(output, "%x %c%c\tINR L", instruction_counter, buf[0], buf[1]);
            break;
        case 'd':
            fprintf(output, "%x %c%c\tDCR L", instruction_counter, buf[0], buf[1]);
            break;
        case 'e':
            op_buf[0] = buf[0];
            op_buf[1] = buf[1];
            load_op();
            fprintf(output, "%x %c%c %c%c\tMVI L,#%c%c", instruction_counter, op_buf[1], op_buf[1], buf[0], buf[1]);
            break;
        case 'f':
            fprintf(output, "%x %c%c\tCMA", instruction_counter, buf[0], buf[1]);
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
            load_op();
            arg_buf[0] = buf[0];
            arg_buf[1] = buf[1];
            load_op();
            fprintf(output, "%x %c%c %c%c %c%c\tLXI SP,#%c%c%c%c", instruction_counter, op_buf[0], op_buf[1], arg_buf[0], arg_buf[1], buf[0], buf[1], buf[0], buf[1], arg_buf[0], arg_buf[1]);
            break;
        case '2':
            op_buf[0] = buf[0];
            op_buf[1] = buf[1];
            load_op();
            arg_buf[0] = buf[0];
            arg_buf[1] = buf[1];
            load_op();
            fprintf(output, "%x %c%c %c%c %c%c\tSTA adr", instruction_counter, op_buf[0], op_buf[1], arg_buf[0], arg_buf[1], buf[0], buf[1], buf[0], buf[1], arg_buf[0], arg_buf[1]);
            break;
        case '3':
            fprintf(output, "%x %c%c\tINX SP", instruction_counter, buf[0], buf[1]);
            break;
        case '4':
            fprintf(output, "%x %c%c\tINR M", instruction_counter, buf[0], buf[1]);
            break;
        case '5':
            fprintf(output, "%x %c%c\tDCR M", instruction_counter, buf[0], buf[1]);
            break;
        case '6':
            op_buf[0] = buf[0];
            op_buf[1] = buf[1];
            load_op();
            fprintf(output, "%x %c%c %c%c\tMVI M, D8", instruction_counter, op_buf[0], op_buf[1], buf[0], buf[1], buf[0], buf[1]);
            break;
        case '7':
            fprintf(output, "%x %c%c\tSTC", instruction_counter, buf[0], buf[1]);
            break;
        case '8':
            // unallocated
            break;
        case '9':
            fprintf(output, "%x %c%c\tDAD SP", instruction_counter, buf[0], buf[1]);
            break;
        case 'a':
            op_buf[0] = buf[0];
            op_buf[1] = buf[1];
            load_op();
            arg_buf[0] = buf[0];
            arg_buf[1] = buf[1];
            load_op();
            fprintf(output, "%x %c%c %c%c %c%c\tLDA adr", instruction_counter, op_buf[0], op_buf[1], arg_buf[0], arg_buf[1], buf[0], buf[1], buf[0], buf[1], arg_buf[0], arg_buf[1]);
            break;
        case 'b':
            fprintf(output, "%x %c%c\tDCX SP", instruction_counter, buf[0], buf[1]);
            break;
        case 'c':
            fprintf(output, "%x %c%c\tINR A", instruction_counter, buf[0], buf[1]);
            break;
        case 'd':
            fprintf(output, "%x %c%c\tDCR A", instruction_counter, buf[0], buf[1]);
            break;
        case 'e':
            op_buf[0] = buf[0];
            op_buf[1] = buf[1];
            load_op();
            fprintf(output, "%x %c%c %c%c\tMVI A,D8", instruction_counter, op_buf[0], op_buf[1], buf[0], buf[1], buf[0], buf[1]);
            break;
        case 'f':
            fprintf(output, "%x %c%c\tCMC", instruction_counter, buf[0], buf[1]);
            break;
        }
        break;
    case '4':
        switch (buf[1])
        {
        case '0':
            fprintf(output, "%x %c%c\tMOV B,B", instruction_counter, buf[0], buf[1]);
            break;
        case '1':
            fprintf(output, "%x %c%c\tMOV B,C", instruction_counter, buf[0], buf[1]);
            break;
        case '2':
            fprintf(output, "%x %c%c\tMOV B,D", instruction_counter, buf[0], buf[1]);
            break;
        case '3':
            fprintf(output, "%x %c%c\tMOV B,E", instruction_counter, buf[0], buf[1]);
            break;
        case '4':
            fprintf(output, "%x %c%c\tMOV B,H", instruction_counter, buf[0], buf[1]);
            break;
        case '5':
            fprintf(output, "%x %c%c\tMOV B,L", instruction_counter, buf[0], buf[1]);
            break;
        case '6':
            fprintf(output, "%x %c%c\tMOV B,M", instruction_counter, buf[0], buf[1]);
            break;
        case '7':
            fprintf(output, "%x %c%c\tMOV B,A", instruction_counter, buf[0], buf[1]);
            break;
        case '8':
            fprintf(output, "%x %c%c\tMOV C,B", instruction_counter, buf[0], buf[1]);
            break;
        case '9':
            fprintf(output, "%x %c%c\tMOV C,C", instruction_counter, buf[0], buf[1]);
            break;
        case 'a':
            fprintf(output, "%x %c%c\tMOV C,D", instruction_counter, buf[0], buf[1]);
            break;
        case 'b':
            fprintf(output, "%x %c%c\tMOV C,E", instruction_counter, buf[0], buf[1]);
            break;
        case 'c':
            fprintf(output, "%x %c%c\tMOV C,H", instruction_counter, buf[0], buf[1]);
            break;
        case 'd':
            fprintf(output, "%x %c%c\tMOV C,L", instruction_counter, buf[0], buf[1]);
            break;
        case 'e':
            fprintf(output, "%x %c%c\tMOV C,M", instruction_counter, buf[0], buf[1]);
            break;
        case 'f':
            fprintf(output, "%x %c%c\tMOV C,A", instruction_counter, buf[0], buf[1]);
            break;
        }
        break;
    case '5':
        switch (buf[1])
        {
        case '0':
            fprintf(output, "%x %c%c\tMOV D,B", instruction_counter, buf[0], buf[1]);
            break;
        case '1':
            fprintf(output, "%x %c%c\tMOV D,C", instruction_counter, buf[0], buf[1]);
            break;
        case '2':
            fprintf(output, "%x %c%c\tMOV D,D", instruction_counter, buf[0], buf[1]);
            break;
        case '3':
            fprintf(output, "%x %c%c\tMOV D,E", instruction_counter, buf[0], buf[1]);
            break;
        case '4':
            fprintf(output, "%x %c%c\tMOV D,H", instruction_counter, buf[0], buf[1]);
            break;
        case '5':
            fprintf(output, "%x %c%c\tMOV D,L", instruction_counter, buf[0], buf[1]);
            break;
        case '6':
            fprintf(output, "%x %c%c\tMOV D,M", instruction_counter, buf[0], buf[1]);
            break;
        case '7':
            fprintf(output, "%x %c%c\tMOV D,A", instruction_counter, buf[0], buf[1]);
            break;
        case '8':
            fprintf(output, "%x %c%c\tMOV E,B", instruction_counter, buf[0], buf[1]);
            break;
        case '9':
            fprintf(output, "%x %c%c\tMOV E,C", instruction_counter, buf[0], buf[1]);
            break;
        case 'a':
            fprintf(output, "%x %c%c\tMOV E,D", instruction_counter, buf[0], buf[1]);
            break;
        case 'b':
            fprintf(output, "%x %c%c\tMOV E,E", instruction_counter, buf[0], buf[1]);
            break;
        case 'c':
            fprintf(output, "%x %c%c\tMOV E,H", instruction_counter, buf[0], buf[1]);
            break;
        case 'd':
            fprintf(output, "%x %c%c\tMOV E,L", instruction_counter, buf[0], buf[1]);
            break;
        case 'e':
            fprintf(output, "%x %c%c\tMOV E,M", instruction_counter, buf[0], buf[1]);
            break;
        case 'f':
            fprintf(output, "%x %c%c\tMOV E,A", instruction_counter, buf[0], buf[1]);
            break;
        }
        break;
    case '6':
        switch (buf[1])
        {
        case '0':
            fprintf(output, "%x %c%c\tMOV D,B", instruction_counter, buf[0], buf[1]);
            break;
        case '1':
            fprintf(output, "%x %c%c\tMOV H,C", instruction_counter, buf[0], buf[1]);
            break;
        case '2':
            fprintf(output, "%x %c%c\tMOV H,D", instruction_counter, buf[0], buf[1]);
            break;
        case '3':
            fprintf(output, "%x %c%c\tMOV H,E", instruction_counter, buf[0], buf[1]);
            break;
        case '4':
            fprintf(output, "%x %c%c\tMOV H,H", instruction_counter, buf[0], buf[1]);
            break;
        case '5':
            fprintf(output, "%x %c%c\tMOV H,L", instruction_counter, buf[0], buf[1]);
            break;
        case '6':
            fprintf(output, "%x %c%c\tMOV H,M", instruction_counter, buf[0], buf[1]);
            break;
        case '7':
            fprintf(output, "%x %c%c\tMOV H,A", instruction_counter, buf[0], buf[1]);
            break;
        case '8':
            fprintf(output, "%x %c%c\tMOV L,B", instruction_counter, buf[0], buf[1]);
            break;
        case '9':
            fprintf(output, "%x %c%c\tMOV L,C", instruction_counter, buf[0], buf[1]);
            break;
        case 'a':
            fprintf(output, "%x %c%c\tMOV L,D", instruction_counter, buf[0], buf[1]);
            break;
        case 'b':
            fprintf(output, "%x %c%c\tMOV L,E", instruction_counter, buf[0], buf[1]);
            break;
        case 'c':
            fprintf(output, "%x %c%c\tMOV L,H", instruction_counter, buf[0], buf[1]);
            break;
        case 'd':
            fprintf(output, "%x %c%c\tMOV L,L", instruction_counter, buf[0], buf[1]);
            break;
        case 'e':
            fprintf(output, "%x %c%c\tMOV L,M", instruction_counter, buf[0], buf[1]);
            break;
        case 'f':
            fprintf(output, "%x %c%c\tMOV L,A", instruction_counter, buf[0], buf[1]);
            break;
        }
        break;
    case '7':
        switch (buf[1])
        {
        case '0':
            fprintf(output, "%x %c%c\tMOV M,B", instruction_counter, buf[0], buf[1]);
            break;
        case '1':
            fprintf(output, "%x %c%c\tMOV M,C", instruction_counter, buf[0], buf[1]);
            break;
        case '2':
            fprintf(output, "%x %c%c\tMOV M,D", instruction_counter, buf[0], buf[1]);
            break;
        case '3':
            fprintf(output, "%x %c%c\tMOV M,E", instruction_counter, buf[0], buf[1]);
            break;
        case '4':
            fprintf(output, "%x %c%c\tMOV M,H", instruction_counter, buf[0], buf[1]);
            break;
        case '5':
            fprintf(output, "%x %c%c\tMOV M,L", instruction_counter, buf[0], buf[1]);
            break;
        case '6':
            fprintf(output, "%x %c%c\tHLT", instruction_counter, buf[0], buf[1]);
            break;
        case '7':
            fprintf(output, "%x %c%c\tMOV M,A", instruction_counter, buf[0], buf[1]);
            break;
        case '8':
            fprintf(output, "%x %c%c\tMOV A,B", instruction_counter, buf[0], buf[1]);
            break;
        case '9':
            fprintf(output, "%x %c%c\tMOV A,C", instruction_counter, buf[0], buf[1]);
            break;
        case 'a':
            fprintf(output, "%x %c%c\tMOV A,D", instruction_counter, buf[0], buf[1]);
            break;
        case 'b':
            fprintf(output, "%x %c%c\tMOV A,E", instruction_counter, buf[0], buf[1]);
            break;
        case 'c':
            fprintf(output, "%x %c%c\tMOV A,H", instruction_counter, buf[0], buf[1]);
            break;
        case 'd':
            fprintf(output, "%x %c%c\tMOV A,L", instruction_counter, buf[0], buf[1]);
            break;
        case 'e':
            fprintf(output, "%x %c%c\tMOV A,M", instruction_counter, buf[0], buf[1]);
            break;
        case 'f':
            fprintf(output, "%x %c%c\tMOV A,A", instruction_counter, buf[0], buf[1]);
            break;
        }
        break;
    case '8':
        switch (buf[1])
        {
        case '0':
            fprintf(output, "%x %c%c\tADD B", instruction_counter, buf[0], buf[1]);
            break;
        case '1':
            fprintf(output, "%x %c%c\tADD C", instruction_counter, buf[0], buf[1]);
            break;
        case '2':
            fprintf(output, "%x %c%c\tADD D", instruction_counter, buf[0], buf[1]);
            break;
        case '3':
            fprintf(output, "%x %c%c\tADD E", instruction_counter, buf[0], buf[1]);
            break;
        case '4':
            fprintf(output, "%x %c%c\tADD H", instruction_counter, buf[0], buf[1]);
            break;
        case '5':
            fprintf(output, "%x %c%c\tADD L", instruction_counter, buf[0], buf[1]);
            break;
        case '6':
            fprintf(output, "%x %c%c\tADD M", instruction_counter, buf[0], buf[1]);
            break;
        case '7':
            fprintf(output, "%x %c%c\tADD A", instruction_counter, buf[0], buf[1]);
            break;
        case '8':
            fprintf(output, "%x %c%c\tADC B", instruction_counter, buf[0], buf[1]);
            break;
        case '9':
            fprintf(output, "%x %c%c\tADC C", instruction_counter, buf[0], buf[1]);
            break;
        case 'a':
            fprintf(output, "%x %c%c\tACD D", instruction_counter, buf[0], buf[1]);
            break;
        case 'b':
            fprintf(output, "%x %c%c\tACD E", instruction_counter, buf[0], buf[1]);
            break;
        case 'c':
            fprintf(output, "%x %c%c\tACD H", instruction_counter, buf[0], buf[1]);
            break;
        case 'd':
            fprintf(output, "%x %c%c\tACD L", instruction_counter, buf[0], buf[1]);
            break;
        case 'e':
            fprintf(output, "%x %c%c\tADC M", instruction_counter, buf[0], buf[1]);
            break;
        case 'f':
            fprintf(output, "%x %c%c\tADC A", instruction_counter, buf[0], buf[1]);
            break;
        }
        break;
    case '9':
        switch (buf[1])
        {
        case '0':
            fprintf(output, "%x %c%c\tSUB B", instruction_counter, buf[0], buf[1]);
            break;
        case '1':
            fprintf(output, "%x %c%c\tSUB C", instruction_counter, buf[0], buf[1]);
            break;
        case '2':
            fprintf(output, "%x %c%c\tSUB D", instruction_counter, buf[0], buf[1]);
            break;
        case '3':
            fprintf(output, "%x %c%c\tSUB E", instruction_counter, buf[0], buf[1]);
            break;
        case '4':
            fprintf(output, "%x %c%c\tSUB H", instruction_counter, buf[0], buf[1]);
            break;
        case '5':
            fprintf(output, "%x %c%c\tSUB L", instruction_counter, buf[0], buf[1]);
            break;
        case '6':
            fprintf(output, "%x %c%c\tSUB M", instruction_counter, buf[0], buf[1]);
            break;
        case '7':
            fprintf(output, "%x %c%c\tSUB A", instruction_counter, buf[0], buf[1]);
            break;
        case '8':
            fprintf(output, "%x %c%c\tSBB B", instruction_counter, buf[0], buf[1]);
            break;
        case '9':
            fprintf(output, "%x %c%c\tSBB C", instruction_counter, buf[0], buf[1]);
            break;
        case 'a':
            fprintf(output, "%x %c%c\tSBB D", instruction_counter, buf[0], buf[1]);
            break;
        case 'b':
            fprintf(output, "%x %c%c\tSBB E", instruction_counter, buf[0], buf[1]);
            break;
        case 'c':
            fprintf(output, "%x %c%c\tSBB H", instruction_counter, buf[0], buf[1]);
            break;
        case 'd':
            fprintf(output, "%x %c%c\tSBB L", instruction_counter, buf[0], buf[1]);
            break;
        case 'e':
            fprintf(output, "%x %c%c\tSBB M", instruction_counter, buf[0], buf[1]);
            break;
        case 'f':
            fprintf(output, "%x %c%c\tSBB A", instruction_counter, buf[0], buf[1]);
            break;
        }
        break;
    case 'a':
        switch (buf[1])
        {
        case '0':
            fprintf(output, "%x %c%c\tANA B", instruction_counter, buf[0], buf[1]);
            break;
        case '1':
            fprintf(output, "%x %c%c\tANA C", instruction_counter, buf[0], buf[1]);
            break;
        case '2':
            fprintf(output, "%x %c%c\tANA D", instruction_counter, buf[0], buf[1]);
            break;
        case '3':
            fprintf(output, "%x %c%c\tANA E", instruction_counter, buf[0], buf[1]);
            break;
        case '4':
            fprintf(output, "%x %c%c\tANA H", instruction_counter, buf[0], buf[1]);
            break;
        case '5':
            fprintf(output, "%x %c%c\tANA L", instruction_counter, buf[0], buf[1]);
            break;
        case '6':
            fprintf(output, "%x %c%c\tANA M", instruction_counter, buf[0], buf[1]);
            break;
        case '7':
            fprintf(output, "%x %c%c\tANA A", instruction_counter, buf[0], buf[1]);
            break;
        case '8':
            fprintf(output, "%x %c%c\tXRA B", instruction_counter, buf[0], buf[1]);
            break;
        case '9':
            fprintf(output, "%x %c%c\tXRA C", instruction_counter, buf[0], buf[1]);
            break;
        case 'a':
            fprintf(output, "%x %c%c\tXRA D", instruction_counter, buf[0], buf[1]);
            break;
        case 'b':
            fprintf(output, "%x %c%c\tXRA E", instruction_counter, buf[0], buf[1]);
            break;
        case 'c':
            fprintf(output, "%x %c%c\tXRA H", instruction_counter, buf[0], buf[1]);
            break;
        case 'd':
            fprintf(output, "%x %c%c\tXRA L", instruction_counter, buf[0], buf[1]);
            break;
        case 'e':
            fprintf(output, "%x %c%c\tXRA M", instruction_counter, buf[0], buf[1]);
            break;
        case 'f':
            fprintf(output, "%x %c%c\tXRA A", instruction_counter, buf[0], buf[1]);
            break;
        }
        break;
    case 'b':
        switch (buf[1])
        {
        case '0':
            fprintf(output, "%x %c%c\tORA B", instruction_counter, buf[0], buf[1]);
            break;
        case '1':
            fprintf(output, "%x %c%c\tORA C", instruction_counter, buf[0], buf[1]);
            break;
        case '2':
            fprintf(output, "%x %c%c\tORA D", instruction_counter, buf[0], buf[1]);
            break;
        case '3':
            fprintf(output, "%x %c%c\tORA E", instruction_counter, buf[0], buf[1]);
            break;
        case '4':
            fprintf(output, "%x %c%c\tORA H", instruction_counter, buf[0], buf[1]);
            break;
        case '5':
            fprintf(output, "%x %c%c\tORA L", instruction_counter, buf[0], buf[1]);
            break;
        case '6':
            fprintf(output, "%x %c%c\tORA M", instruction_counter, buf[0], buf[1]);
            break;
        case '7':
            fprintf(output, "%x %c%c\tORA A", instruction_counter, buf[0], buf[1]);
            break;
        case '8':
            fprintf(output, "%x %c%c\tCMP B", instruction_counter, buf[0], buf[1]);
            break;
        case '9':
            fprintf(output, "%x %c%c\tCMP C", instruction_counter, buf[0], buf[1]);
            break;
        case 'a':
            fprintf(output, "%x %c%c\tCMP D", instruction_counter, buf[0], buf[1]);
            break;
        case 'b':
            fprintf(output, "%x %c%c\tCMP E", instruction_counter, buf[0], buf[1]);
            break;
        case 'c':
            fprintf(output, "%x %c%c\tCMP H", instruction_counter, buf[0], buf[1]);
            break;
        case 'd':
            fprintf(output, "%x %c%c\tCMP L", instruction_counter, buf[0], buf[1]);
            break;
        case 'e':
            fprintf(output, "%x %c%c\tCMP M", instruction_counter, buf[0], buf[1]);
            break;
        case 'f':
            fprintf(output, "%x %c%c\tCMP A", instruction_counter, buf[0], buf[1]);
            break;
        }
        break;
    case 'c':
        switch (buf[1])
        {
        case '0':
            fprintf(output, "%x %c%c\tRNZ", instruction_counter, buf[0], buf[1]);
            break;
        case '1':
            fprintf(output, "%x %c%c\tPOP B", instruction_counter, buf[0], buf[1]);
            break;
        case '2':
            op_buf[0] = buf[0];
            op_buf[1] = buf[1];
            load_op();
            arg_buf[0] = buf[0];
            arg_buf[1] = buf[1];
            load_op();
            fprintf(output, "%x %c%c %c%c %c%c\tJNZ $%c%c%c%c", instruction_counter, op_buf[0], op_buf[1], arg_buf[0], arg_buf[1], buf[0], buf[1], buf[0], buf[1], arg_buf[0], arg_buf[1]);
            break;
        case '3':
            op_buf[0] = buf[0];
            op_buf[1] = buf[1];
            load_op();
            arg_buf[0] = buf[0];
            arg_buf[1] = buf[1];
            load_op();
            fprintf(output, "%x %c%c %c%c %c%c\tJMP $%c%c%c%c", instruction_counter, op_buf[0], op_buf[1], arg_buf[0], arg_buf[1], buf[0], buf[1], arg_buf[0], arg_buf[1], buf[0], buf[1], buf[0], buf[1], arg_buf[0], arg_buf[1]);
            break;
        case '4':
            fprintf(output, "%x %c%c\tORA H", instruction_counter, buf[0], buf[1]);
            break;
        case '5':
            op_buf[0] = buf[0];
            op_buf[1] = buf[1];
            load_op();
            arg_buf[0] = buf[0];
            arg_buf[1] = buf[1];
            load_op();
            fprintf(output, "%x %c%c %c%c %c%c\tCNZ $%c%c%c%c", instruction_counter, op_buf[0], op_buf[1], arg_buf[0], arg_buf[1], buf[0], buf[1], buf[0], buf[1], arg_buf[0], arg_buf[1]);
            break;
        case '6':
            op_buf[0] = buf[0];
            op_buf[1] = buf[1];
            load_op();
            fprintf(output, "%x %c%c %c%c\tADI #%c%c", instruction_counter, op_buf[0], op_buf[1], buf[0], buf[1], buf[0], buf[1]);
            break;
        case '7':
            fprintf(output, "%x %c%c\tRST 0", instruction_counter, buf[0], buf[1]);
            break;
        case '8':
            fprintf(output, "%x %c%c\tRZ", instruction_counter, buf[0], buf[1]);
            break;
        case '9':
            fprintf(output, "%x %c%c\tRET", instruction_counter, buf[0], buf[1]);
            break;
        case 'a':
            op_buf[0] = buf[0];
            op_buf[1] = buf[1];
            load_op();
            arg_buf[0] = buf[0];
            arg_buf[1] = buf[1];
            load_op();
            fprintf(output, "%x %c%c %c%c %c%c\tLZ $%c%c%c%c", instruction_counter, op_buf[0], op_buf[1], arg_buf[0], arg_buf[1], buf[0], buf[1], buf[0], buf[1], arg_buf[0], arg_buf[1]);
            break;
        case 'b':
            // unallocated
            break;
        case 'c':
            op_buf[0] = buf[0];
            op_buf[1] = buf[1];
            load_op();
            arg_buf[0] = buf[0];
            arg_buf[1] = buf[1];
            load_op();
            fprintf(output, "%x %c%c %c%c %c%c\tCZ $%c%c%c%c", instruction_counter, op_buf[0], op_buf[1], arg_buf[0], arg_buf[1], buf[0], buf[1], buf[0], buf[1], arg_buf[0], arg_buf[1]);
            break;
        case 'd':
            op_buf[0] = buf[0];
            op_buf[1] = buf[1];
            load_op();
            arg_buf[0] = buf[0];
            arg_buf[1] = buf[1];
            load_op();
            fprintf(output, "%x %c%c %c%c %c%c\tCALL $%c%c%c%c", instruction_counter, op_buf[0], op_buf[1], arg_buf[0], arg_buf[1], buf[0], buf[1], buf[0], buf[1], arg_buf[0], arg_buf[1]);
            break;
        case 'e':
            op_buf[0] = buf[0];
            op_buf[1] = buf[1];
            load_op();
            fprintf(output, "%x %c%c %c%c\tACI #%c%c", instruction_counter, op_buf[0], op_buf[1], buf[0], buf[1], buf[0], buf[1]);
            break;
        case 'f':
            fprintf(output, "%x %c%c\tRST 1", instruction_counter, buf[0], buf[1]);
            break;
        }
        break;
    case 'd':
        switch (buf[1])
        {
        case '0':
            fprintf(output, "%x %c%c\tRNC", instruction_counter, buf[0], buf[1]);
            break;
        case '1':
            fprintf(output, "%x %c%c\tPOP D", instruction_counter, buf[0], buf[1]);
            break;
        case '2':
            op_buf[0] = buf[0];
            op_buf[1] = buf[1];
            load_op();
            arg_buf[0] = buf[0];
            arg_buf[1] = buf[1];
            load_op();
            fprintf(output, "%x %c%c %c%c %c%c\tJNC $%c%c%c%c", instruction_counter, op_buf[0], op_buf[1], arg_buf[0], arg_buf[1], buf[0], buf[1], buf[0], buf[1], arg_buf[0], arg_buf[1]);
            break;
        case '3':
            op_buf[0] = buf[0];
            op_buf[1] = buf[1];
            load_op();
            fprintf(output, "%x %c%c %c%c\tOUT #%c%c", instruction_counter, op_buf[0], op_buf[1], buf[0], buf[1], buf[0], buf[1]);
            break;
        case '4':
            op_buf[0] = buf[0];
            op_buf[1] = buf[1];
            load_op();
            arg_buf[0] = buf[0];
            arg_buf[1] = buf[1];
            load_op();
            fprintf(output, "%x %c%c %c%c %c%c\tCNC $%c%c%c%c", instruction_counter, op_buf[0], op_buf[1], arg_buf[0], arg_buf[1], buf[0], buf[1], buf[0], buf[1], arg_buf[0], arg_buf[1]);
            break;
        case '5':
            fprintf(output, "%x %c%c\tPUSH D", instruction_counter, buf[0], buf[1]);
            break;
        case '6':
            op_buf[0] = buf[0];
            op_buf[1] = buf[1];
            load_op();
            fprintf(output, "%x %c%c %c%c\tSUI #%c%c", instruction_counter, op_buf[0], op_buf[1], buf[0], buf[1], buf[0], buf[1]);
            break;
        case '7':
            fprintf(output, "%x %c%c\tRST 2", instruction_counter, buf[0], buf[1]);
            break;
        case '8':
            fprintf(output, "%x %c%c\tRC", instruction_counter, buf[0], buf[1]);
            break;
        case '9':
            // unallocated
            break;
        case 'a':
            op_buf[0] = buf[0];
            op_buf[1] = buf[1];
            load_op();
            arg_buf[0] = buf[0];
            arg_buf[1] = buf[1];
            load_op();
            fprintf(output, "%x %c%c %c%c %c%c\tJC $%c%c%c%c", instruction_counter, op_buf[0], op_buf[1], arg_buf[0], arg_buf[1], buf[0], buf[1], buf[0], buf[1], arg_buf[0], arg_buf[1]);
            break;
        case 'b':
            op_buf[0] = buf[0];
            op_buf[1] = buf[1];
            load_op();
            fprintf(output, "%x %c%c %c%c\tIN #%c%c", instruction_counter, op_buf[0], op_buf[1], buf[0], buf[1], buf[0], buf[1]);
            break;
        case 'c':
            op_buf[0] = buf[0];
            op_buf[1] = buf[1];
            load_op();
            arg_buf[0] = buf[0];
            arg_buf[1] = buf[1];
            load_op();
            fprintf(output, "%x %c%c %c%c %c%c\tCC $%c%c%c%c", instruction_counter, op_buf[0], op_buf[1], arg_buf[0], arg_buf[1], buf[0], buf[1], buf[0], buf[1], arg_buf[0], arg_buf[1]);
            break;
        case 'd':
            // unallocated
            break;
        case 'e':
            op_buf[0] = buf[0];
            op_buf[1] = buf[1];
            load_op();
            fprintf(output, "%x %c%c %c%c\tSBI #%c%c", instruction_counter, op_buf[0], op_buf[1], buf[0], buf[1], buf[0], buf[1]);
            break;
        case 'f':
            fprintf(output, "%x %c%c\tRST 3", instruction_counter, buf[0], buf[1]);
            break;
        }
        break;
    case 'e':
        switch (buf[1])
        {
        case '0':
            fprintf(output, "%x %c%c\tRPO", instruction_counter, buf[0], buf[1]);
            break;
        case '1':
            fprintf(output, "%x %c%c\tPOP H", instruction_counter, buf[0], buf[1]);
            break;
        case '2':
            op_buf[0] = buf[0];
            op_buf[1] = buf[1];
            load_op();
            arg_buf[0] = buf[0];
            arg_buf[1] = buf[1];
            load_op();
            fprintf(output, "%x %c%c %c%c %c%c\tJPO $%c%c%c%c", instruction_counter, op_buf[0], op_buf[1], arg_buf[0], arg_buf[1], buf[0], buf[1], buf[0], buf[1], arg_buf[0], arg_buf[1]);
            break;
        case '3':
            fprintf(output, "%x %c%c\tXTHL", instruction_counter, buf[0], buf[1]);
            break;
        case '4':
            op_buf[0] = buf[0];
            op_buf[1] = buf[1];
            load_op();
            arg_buf[0] = buf[0];
            arg_buf[1] = buf[1];
            load_op();
            fprintf(output, "%x %c%c %c%c %c%c\tCPO $%c%c%c%c", instruction_counter, op_buf[0], op_buf[1], arg_buf[0], arg_buf[1], buf[0], buf[1], buf[0], buf[1], arg_buf[0], arg_buf[1]);
            break;
        case '5':
            fprintf(output, "%x %c%c\tPUSH H", instruction_counter, buf[0], buf[1]);
            break;
        case '6':
            op_buf[0] = buf[0];
            op_buf[1] = buf[1];
            load_op();
            fprintf(output, "%x %c%c %c%c\tANI #%c%c", instruction_counter, op_buf[0], op_buf[1], buf[0], buf[1], buf[0], buf[1]);
            break;
        case '7':
            fprintf(output, "%x %c%c\tRST 4", instruction_counter, buf[0], buf[1]);
            break;
        case '8':
            fprintf(output, "%x %c%c\tRPE", instruction_counter, buf[0], buf[1]);
            break;
        case '9':
            fprintf(output, "%x %c%c\tPHCL", instruction_counter, buf[0], buf[1]);
            break;
        case 'a':
            op_buf[0] = buf[0];
            op_buf[1] = buf[1];
            load_op();
            arg_buf[0] = buf[0];
            arg_buf[1] = buf[1];
            load_op();
            fprintf(output, "%x %c%c %c%c %c%c\tJPE $%c%c%c%c", instruction_counter, op_buf[0], op_buf[1], arg_buf[0], arg_buf[1], buf[0], buf[1], buf[0], buf[1], arg_buf[0], arg_buf[1]);
            break;
        case 'b':
            op_buf[0] = buf[0];
            op_buf[1] = buf[1];
            load_op();
            fprintf(output, "%x %c%c %c%c\tXCHG", instruction_counter, op_buf[0], op_buf[1], buf[0], buf[1], buf[0], buf[1]);
            break;
        case 'c':
            op_buf[0] = buf[0];
            op_buf[1] = buf[1];
            load_op();
            arg_buf[0] = buf[0];
            arg_buf[1] = buf[1];
            load_op();
            fprintf(output, "%x %c%c %c%c\tCPE $%c%c%c%c", instruction_counter, op_buf[0], op_buf[1], arg_buf[0], arg_buf[1], buf[0], buf[1], buf[0], buf[1], arg_buf[0], arg_buf[1]);
            break;
        case 'd':
            // unallocated
            break;
        case 'e':
            op_buf[0] = buf[0];
            op_buf[1] = buf[1];
            load_op();
            fprintf(output, "%x %c%c %c%c\tXRI #%c%c", instruction_counter, op_buf[0], op_buf[1], buf[0], buf[1], buf[0], buf[1]);
            break;
        case 'f':
            fprintf(output, "%x %c%c\tRST 5", instruction_counter, buf[0], buf[1]);
            break;
        }
        break;
    case 'f':
        switch (buf[1])
        {
        case '0':
            fprintf(output, "%x %c%c\tRP", instruction_counter, buf[0], buf[1]);
            break;
        case '1':
            fprintf(output, "%x %c%c\tPOP PSW", instruction_counter, buf[0], buf[1]);
            break;
        case '2':
            op_buf[0] = buf[0];
            op_buf[1] = buf[1];
            load_op();
            arg_buf[0] = buf[0];
            arg_buf[1] = buf[1];
            load_op();
            fprintf(output, "%x %c%c %c%c %c%c\tJP $%c%c%c%c", instruction_counter, op_buf[0], op_buf[1], arg_buf[0], arg_buf[1], buf[0], buf[1], buf[0], buf[1], arg_buf[0], arg_buf[1]);
            break;
        case '3':
            fprintf(output, "%x %c%c\tDI", instruction_counter, buf[0], buf[1]);
            break;
        case '4':
            op_buf[0] = buf[0];
            op_buf[1] = buf[1];
            load_op();
            arg_buf[0] = buf[0];
            arg_buf[1] = buf[1];
            load_op();
            fprintf(output, "%x %c%c %c%c %c%c\tCP $%c%c%c%c", instruction_counter, op_buf[0], op_buf[1], arg_buf[0], arg_buf[1], buf[0], buf[1], buf[0], buf[1], arg_buf[0], arg_buf[1]);
            break;
        case '5':
            fprintf(output, "%x %c%c\tPUSH PSW", instruction_counter, buf[0], buf[1]);
            break;
        case '6':
            op_buf[0] = buf[0];
            op_buf[1] = buf[1];
            load_op();
            fprintf(output, "%x %c%c %c%c %c%c\tORI #%c%c", instruction_counter, op_buf[0], op_buf[1], buf[0], buf[1], buf[0], buf[1]);
            break;
        case '7':
            fprintf(output, "%x %c%c\tRST 6", instruction_counter, buf[0], buf[1]);
            break;
        case '8':
            fprintf(output, "%x %c%c\tRM", instruction_counter, buf[0], buf[1]);
            break;
        case '9':
            fprintf(output, "%x %c%c\tSPHL", instruction_counter, buf[0], buf[1]);
            break;
        case 'a':
            op_buf[0] = buf[0];
            op_buf[1] = buf[1];
            load_op();
            arg_buf[0] = buf[0];
            arg_buf[1] = buf[1];
            load_op();
            fprintf(output, "%x %c%c %c%c %c%c\tJM $%c%c%c%c", instruction_counter, op_buf[0], op_buf[1], arg_buf[0], arg_buf[1], buf[0], buf[1], buf[0], buf[1], arg_buf[0], arg_buf[1]);
            break;
        case 'b':
            fprintf(output, "%x %c%c\tEI", instruction_counter, buf[0], buf[1]);
            break;
        case 'c':
            op_buf[0] = buf[0];
            op_buf[1] = buf[1];
            load_op();
            arg_buf[0] = buf[0];
            arg_buf[1] = buf[1];
            load_op();
            fprintf(output, "%x %c%c %c%c %c%c\tCM $%c%c%c%c", instruction_counter, op_buf[0], op_buf[1], arg_buf[0], arg_buf[1], buf[0], buf[1], buf[0], buf[1], arg_buf[0], arg_buf[1]);
            break;
        case 'd':
            // unallocated
            break;
        case 'e':
            op_buf[0] = buf[0];
            op_buf[1] = buf[1];
            load_op();
            fprintf(output, "%x %c%c %c%c\tCPI #%c%c", instruction_counter, op_buf[0], op_buf[1], buf[0], buf[1], buf[0], buf[1]);
            break;
        case 'f':
            fprintf(output, "%x %c%c\tRST 7", instruction_counter, buf[0], buf[1]);
            break;
        }
        break;
    default:
        return;
    }
    instruction_counter++;
    fprintf(output, "\n");
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
        }
        else
        {
            buf[1] = next;
            return 3;
        }
    }
    return 0;
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
