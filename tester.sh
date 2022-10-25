#!/bin/bash

# //testes com o bash
< entradas/infile   ls  -l  |   wc  -l          >       original/saida1
< entradas/infile   grep brasil | grep espanha  >       original/saida2 
< entradas/infile   grep alemanha | grep        >       original/saida3
< entradas/infile   grep saturno   | grep espanha>      original/saida4
< entradas/infile   grep   | grep               >       original/saida5
< entradas/outfile  ls -l | wc                  >       original/saida6
< entradas/outfile  cat ./entradas/testes_cat | wc >    original/saida7
< entradas/infile grep -b | grep oito           >       original/saida8


# //testes com meu pipex
./pipex entradas/infile "ls -l" "wc -l"                  minha/saida1 
./pipex entradas/infile "grep brasil" "grep espanha"     minha/saida2 
./pipex entradas/infile "grep alemanha" "grep"           minha/saida3 
./pipex entradas/infile "grep saturno" "grep espanha"    minha/saida4 
./pipex entradas/infile "grep" "grep"                    minha/saida5 
./pipex entradas/outfile "ls -l" "wc"                    minha/saida6 
./pipex entradas/infile "cat ./entradas/teste_cat" "wc"  minha/saida7
./pipex entradas/infile "grep -b" "grep oito"            minha/saida8


# //diff
diff minha/saida1 original/saida1 > diff/diff1
diff minha/saida2 original/saida2 > diff/diff2
diff minha/saida3 original/saida3 > diff/diff3
diff minha/saida4 original/saida4 > diff/diff4
diff minha/saida5 original/saida5 > diff/diff5
diff minha/saida6 original/saida6 > diff/diff6
diff minha/saida7 original/saida7 > diff/diff7
