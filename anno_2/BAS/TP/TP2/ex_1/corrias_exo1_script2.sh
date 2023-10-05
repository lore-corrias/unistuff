#!/bin/sh

if [ "$1" = "" ]; then
  echo "usage: $0 rep" >&2
  exit 1
fi

if [ ! -d "$1" ]; then
  echo "$1 n'est pas une repertoire" >&2
  exit 1
fi

ls "$1"
if [ $? -ne 0 ]; then
  echo "erreur durant l'execution du ls" >&2
  exit 1
fi

rm -r "$1"
if [ $? -ne 0 ] > /dev/null; then
  echo "erreur durant l'execution du rm" >&2
  exit 1
fi

echo "operation terminée"
exit 0
