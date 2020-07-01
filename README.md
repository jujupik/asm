# asm

## But du projet :

Ce projet consiste a réaliser un programme permettant de compiler des "champions" et s'inscrit dans la réalisation du projet corewar
 ( la réalistation d'une arène virtuelle (VM) dans laquelle vont s'affronter des programmes champions).
 
L'asm va produire un fichier en bytecode, comprehensible par la VM.
Pour cela il va recupérer un fichier écrit en **assembleur** (.s) et générer un fichier du même nom en **bytcode** (.cor).

## Principe utilisé :

Le programme va réaliser une **analyse lexicale (ou tokenization/lexer)** du fichier .s passé en paramètre ( convertir une chaine de caractères en token), 
puis effectuer une **analyse syntaxique (parser)**, enfin il va traduire ces tokens en bytecode dans le .cor.

Toute erreur syntaxique ou de lecture du fichier sera signalé à l'arrêt du programme et aucun .cor ne sera produit.

