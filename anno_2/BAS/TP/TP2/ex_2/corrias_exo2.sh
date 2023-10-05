#!/bin/bash

fichiers_txt=$(ls -la | grep "^-" | grep -c ".*\.txt$")
fichiers_sh=$(ls -la | grep "^-" | grep -c ".*\.sh$")
fichiers_cache=$(ls -la | grep "^-" | grep -v "^.$" | grep -v "^..$" | grep -c "^\.")
fichiers_autres=$(ls -la | grep "^-" | grep -v ".*\.txt$" | grep -v ".*\.sh$" | grep -v -c "^\.")

echo "Il y a $fichiers_txt fichiers dont le nom se termine par .txt"
echo "Il y a $fichiers_sh fichiers dont le nom se termine par .sh"
echo "Il y a $fichiers_cache fichiers cachés"
echo "Il y a $fichiers_autres d'autres fichiers"
