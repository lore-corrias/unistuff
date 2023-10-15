#!/bin/sh

if [ $# -ne 1 ]; then
  echo "usage: $0 repertoire" >&2
fi

arbre_base() {
  for fich in "$1"/*; do
    if [ -d "$fich" ]; then
      basename "$fich"
      arbre_base "$fich"
    fi
  done
}

arbre_base "$1"
