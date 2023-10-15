#!/bin/sh

while read -r ligne; do
  new_ligne=""
  for mot in $ligne; do
    new_ligne="$new_ligne$(grep ^"$mot" dico.txt | cut -d ' ' -f2) "
  done
  echo "$new_ligne" >> f_francais.txt
done < f_anglais.txt
