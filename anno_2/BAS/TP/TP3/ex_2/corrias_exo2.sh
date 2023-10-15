#!/bin/sh

trap "echo SIGINT SIGNAL" INT
trap "echo SIGQUIT && exit 1" QUIT

while true; do
  echo 'bonjour'
  sleep 1
done
