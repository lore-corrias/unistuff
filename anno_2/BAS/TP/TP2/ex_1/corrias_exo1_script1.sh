#!/bin/sh

if [ "$1" = ""  -o  "$2" = "" ]; then
  echo "usage: $0 repertoire fichier" >&2
  exit 1
fi

if [ ! -f "$2" ]; then
  echo "le fichier $2 n'existe pas" >&2
  exit 1
fi

mkdir "$1" > /dev/null
if [ $? -ne 0 ] ; then
  echo "erreur durant la creation du repertoire" >&2
  exit 1
fi

cp "$2" "$1" > /dev/null
if [ $? -ne 0 ] ; then
  echo "erreur durant la copie du fichier" >&2
  exit 1
fi

echo "operation terminée"
exit 0
