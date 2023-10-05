#!/bin/sh

mkdir "REP" > /dev/null 2>&1

touch "REP/liste.txt"
ls *.txt >> "REP/liste.txt" 2>/dev/null
ls *.sh  >> "REP/liste.txt" 2>/dev/null

cp "$(tail -n 1 "REP/liste.txt")" "REP" 2>/dev/null

cat "REP/liste.txt"

ls REP/*.txt >/dev/null 2>&1
txt_fichiers=$?
ls REP/*.sh >/dev/null 2>&1
sh_fichiers=$?

if [ ! -d "REP" ]; then
  echo "le repertoire \"REP\" n'a pas été crée" >&2
  exit 1
elif [ $txt_fichiers -ne 0 -a $sh_fichiers -ne 0 ]; then
  echo "pas des .sh ou .txt fichier dans le repertoire \"REP\"" >&2
  exit 1
fi

echo "operation terminée"
exit 0
