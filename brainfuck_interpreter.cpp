// brainfuck_interpreter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdlib.h>
#include <stdio.h>

int main(int argv, char *args[])
{
    
    char* code;
    if (argv < 2)
    {
        //Example code if you don't give an argument
        //char code[] = "[ This program prints Sierpinski triangle on 80-column display. ]>        ++        + +        [< ++        + +        ++++                          >   -] >       ++++++++        [>        ++++        < -] >                     > ++> > > +>                    > > +<        < < < < < < < <        < [-[-> +<        ] > [-< +> > > . < < ] > > >        [[            -> ++                + +++                ++[> ++++                < -] >                . <     <[-> +<                ] + >[-> ++                + +++++++< < +>] > .[                    -] > ]        ] + < < < [-[            -> +< ] + > [                -< +> > > -[-> +< ] + +>                    [-<       ->] < <                    < ] < < < < ] + ++++++++                        + . + ++.[-] < ] + ++++        * ****M a d e * B y : *N Y Y R I K K I * 2 0 0 2 * ****";
        char code_example[] = "+[>[<-[]>+[>+++>[+++++++++++>][>]-[<]>-]]++++++++++<]>>>>> > ----. << ++ + .<-..++ + .<-.>> > . << .++ + .------. > -. << +. < .";

        printf("no code input\n");
        code = code_example;
        //return 1;
    }
    else
    {
        code = args[1];
    }


    size_t tape_size = 30000;
    char* tape_front = (char*)calloc(tape_size, sizeof(char));

    if (tape_front == NULL)
    {
        return 1;
    }

    //printf("%s\n", code);

    char* tape_current = tape_front;

    char* code_position = code;
    int loop_lvl = 0;
    while (*code_position != '\0')
    {
        switch (*code_position)
        {
        case '\[':
            int loop_lvl_tmp = loop_lvl;
            if (*tape_current == 0)//goto the closing ] 
            {
                do
                {
                    switch (*code_position)
                    {
                    case '\[':
                        ++loop_lvl;
                        break;
                    case '\]':
                        --loop_lvl;
                        break;
                    default:
                        break;
                    }
                    ++code_position;
                } while (loop_lvl != loop_lvl_tmp);
                --code_position;
            }
            else
            {
                ++loop_lvl;
            }
            break;
        case '\]':
            loop_lvl_tmp = loop_lvl;
            --code_position;
            do
            {
                switch (*code_position)
                {
                case '\[':
                    --loop_lvl;
                    break;
                case '\]':
                    ++loop_lvl;
                    break;
                default:
                    break;
                }
                --code_position;
            } while (loop_lvl != loop_lvl_tmp - 1);
            
            break;
        case '+':
            ++(*tape_current);
            break;
        case '-':
            --(*tape_current);
            break;
        case ',':
            *tape_current = getchar();
            break;
        case '.':
            putchar(*tape_current);
            break;
        case '<':
            --tape_current;
            break;
        case '>':
            ++tape_current;
            break;

        default:
            break;
        }
        //putchar(*code_position);
        ++code_position;
    }
    printf("\n%d\n", loop_lvl);
    free(tape_front);

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
