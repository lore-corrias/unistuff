#!/bin/sh

if [ $# -ne 1 ]; then
  echo "usage: $0 repertoire" >&2
  exit 1
fi

afficher_repertoire() {
  for fichier in "$1"/*.cpp; do
    echo "$fichier"
  done;
  for fichier in "$1"/*; do
    if [ -d "$fichier" ]; then
      if [ ! -r "$fichier" ]; then
        echo "$fichier est protege en lecture" >&2
      elif [ ! -x "$fichier" ]; then
        echo "$fichier n'est pas un repertoire accessible" >&2
      else
        afficher_repertoire "$fichier"
      fi
    fi
  done
}

afficher_repertoire "$1"
