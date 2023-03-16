#!/bin/bash

# Sincronizza tutti gli esercizi nuovi con la repository su github: https://github.com/justlel/PR1LabEsercizi

esercizi_path="/home/just/Personal/university/PR1_lab/c_progetti/esercizi/"
esercizi_synced_path="/home/just/Personal/university/PR1_lab/c_progetti/PR1LabEsercizi/"

echo "Sincronizzazione della repository locale con quella remota su github..."

if [[ $(cd $esercizi_synced_path && gh repo sync) != 0 ]];
then
  echo "Qualcosa è andato storto durante la sincronizzazione con la repository locale, probabilmente i file locali e quelli online divergono."
  echo "Forzare il pull della repository? Questo potrebbe cancellare i dati in locale (y/n)"
  read -r answer
  if [[ $answer == "y" ]]; then
    (cd $esercizi_synced_path && (gh repo sync || exit 0))
  else
    echo "Risolvi i conflitti e riavvia il programma."
  fi
fi

esercizi_synced=0
for esercizio_mese in "$esercizi_path"*
do
  for esercizio in "$esercizio_mese"/*
  do
    esercizio_label=$(basename "$esercizio") 
    esercizio_synced="$esercizi_synced_path/$esercizio_label"
    if [[ -d "$esercizio_synced" && $(date +%s -r "$esercizio_synced") < $(date +%s -r "$esercizio") ]]
    then
      continue
    fi
    echo "Sincronizzazione dell'esercizio $esercizio_label"
    cp -r "$esercizio" "$esercizio_synced"
    esercizi_synced=$((esercizi_synced+1))
  done
done

if [[ $esercizi_synced -eq 0 ]]
then
  echo "Nessun esercizio sincronizzato"
else
  echo "Sincronizzati $esercizi_synced esercizi. Commit e clone alla repository."
  (cd "$esercizi_synced_path" || exit 1 && git add --all && git commit -m "Aggiormamento esercizi." && git push --set-upstream origin master)
fi
