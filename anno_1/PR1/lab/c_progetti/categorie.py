#!/usr/bin/python3

'''
al me del futuro: aggiusta sto bordello!!!

però dovrebbe funzionare :3, bisogna ancora testare git
'''

import datetime
import os


def add_category() -> bool:
    name = input("Inserisci nome della nuova categoria: ")
    tomakedir = f'PR1LabEsercizi/{name}'
    if os.path.isdir(tomakedir):
        print("Directory già esistente")
        return False
    os.makedirs(tomakedir)
    try:
        assert(os.path.isdir(tomakedir))
    except AssertionError:
        print("Errore nella creazione della cartella.")
        return False
    if input("Desideri aggiungere una descrizione per la nuova categoria di esercizi? (N/y): ").lower() == 'y':
        print("Apertura del file README.md...")
        os.system(f'kate {tomakedir}/README.md')
        input("Premi un tasto per continuare...")
    print("Categoria aggiunta.")
    return True

def get_categories() -> list:
    return [x for x in os.listdir('PR1LabEsercizi') if os.path.isdir(f'PR1LabEsercizi/{x}') and x != '.git' and x != '.idea']

def show_categories():
    print(get_categories())

def delete_category() -> bool:
    name = input("Inserisci il nome della categoria da eliminare: ")
    todeletedir = f'PR1LabEsercizi/{name}'
    if not os.path.isdir(todeletedir):
        print("La cartella non esiste.")
        return True
    try:
        os.rmdir(todeletedir)
        assert(not os.path.isdir(todeletedir))
    except AssertionError:
        print("Impossibile eliminare la cartella.")
        return False
    return True

def sync() -> bool:
    return bool(os.system('cd PR1LabEsercizi && git add --all && git commit -m "Aggiornamento esercizi." && git push'))

def get_homeworks_from_edited_date():
    possible_dates = {
                    'T': ['Oggi', datetime.datetime.now() - datetime.timedelta(days=1)],
                    'Y': ['Ieri', datetime.datetime.now() - datetime.timedelta(days=2)],
                    'W': ['1 settimana', datetime.datetime.now() - datetime.timedelta(days=8)],
                    'M': ['1 mese', datetime.datetime.now() - datetime.timedelta(days=32)],
                    'A': ['Tutti', -1],
                    }
    print("Inserisci la data di ultima modifica massima degli esercizi da spostare (formato dd-mm-yy).")
    print("Shortcuts:")
    for option, v in possible_dates.items():
        print(f"{option}) {v[0]}")
    choice = ""
    while choice not in possible_dates:
        choice = input("?) ").upper()
    data = 0
    if choice != 'A':
        if choice in possible_dates:
            data = possible_dates[choice][1].timestamp()
        else:
            data = datetime.datetime.strptime(choice, "%d-%m-%y").timestamp()
    print(data)
    print(os.path.getmtime(f'esercizi/11_2022/esercizio_10'))
    valids = {}
    for root_dir in [_ for _ in os.listdir('esercizi/') if os.path.isdir(f'esercizi/{_}')]:
        valids[root_dir] = [valid for valid in sorted(os.listdir(f'esercizi/{root_dir}'))
                if os.path.isdir(f'esercizi/{root_dir}/{valid}') and os.path.getmtime(f'esercizi/{root_dir}/{valid}') > data
                ]
    return valids

def move_homeworks():
    valids = get_homeworks_from_edited_date()
    if len(valids) == 0:
        print("Nessun compito da spostare trovato.")
        return False
    print("Esercizi trovati: ")
    for root_dir in valids.keys():
        for i, valid in enumerate(valids[root_dir]):
            print(f"{i}) {valid}")
            if input("Spostare questo esercizio? (Y/n): ").lower() in ['', 'y']:
                if input("Vuoi aprire il file main per verificare il contenuto dell'esercizio? (Y/n): ").lower() in ['', 'y']:
                    os.system(f'kate esercizi/{root_dir}/{valid}/main.c')
                print("Scegli una categoria in cui spostare l'esercizio.\nCategorie disponibili:")
                categories = get_categories()
                for i, category in enumerate(categories):
                    print(f"{i}) {category}")
                choice = -1
                while choice not in range(len(categories)):
                    choice = int(input("?) "))
                new_name = '' 
                while new_name == '' or new_name in os.listdir(f'PR1LabEsercizi/{categories[choice]}'):
                    new_name = input("Inserisci il nome del nuovo esercizio: ")
                os.system(f'cp -r esercizi/{root_dir}/{valid} PR1LabEsercizi/{categories[choice]}/{new_name}')
    return True

def show_homeworks():
    category = input("Inserisci una categoria: ")
    if category not in get_categories():
        print("Categoria non trovata.")
        return []
    else:
        print(f"Esercizi per la categoria {category}: ")
        for file in [_ for _ in os.listdir(f'PR1LabEsercizi/{category}') if os.path.isdir(f'PR1LabEsercizi/{category}/{_}')]:
            print(file)

def welcome():
    options = {
            'A': ['Aggiungi una categoria di esercizi', add_category], 
            'L': ['Mostra le categorie esistenti', show_categories],
            'G': ['Mostra gli esercizi in una categoria', show_homeworks],
            'D': ['Elimina una categoria di esercizi', delete_category],
            'M': ['Sposta gli esercizi non sincronizzati in una categoria.', move_homeworks],
            'S': ['Sincronizza gli esercizi su GitHub', sync]
            }
    print('''
                                                                                                           
,------. ,------.  ,--.,--.           ,--.   ,------.                          ,--.       ,--. 
|  .--. '|  .--. '/   ||  |    ,--,--.|  |-. |  .---' ,---. ,---. ,--.--. ,---.`--',-----.`--' 
|  '--' ||  '--'.'`|  ||  |   ' ,-.  || .-. '|  `--, (  .-'| .-. :|  .--'| .--',--.`-.  / ,--. 
|  | --' |  |\  \  |  ||  '--.\ '-'  || `-' ||  `---..-'  `)   --.|  |   \ `--.|  | /  `-.|  | 
`--'     `--' '--' `--'`-----' `--`--' `---' `------'`----' `----'`--'    `---'`--'`-----'`--' 

            ''')
    print("Benvenuto! Scegli pure cosa fare: ")
    for i, k in options.items():
        print(f"{i}) {k[0]}")
    option = ""
    while option not in options:
        option = input("?) ").upper()
    options[option][1]()


if __name__ == '__main__':
    
    if not os.path.isfile('/usr/bin/git'):
        print("Impossibile trovare git.")
        exit(-1)

    if not os.path.isdir('esercizi'):
        print("Cartella degli esercizi non trovata.")
        exit(-1)

    if not os.path.isdir('PR1LabEsercizi'):
        if not os.path.isfile('/usr/bin/gh'):
            print("Impossibile trovare la directory del git degli esercizi.")
            exit(-1)
        else:
            print("Impossibile trovare la directory del git degli esercizi.")
            if input("Clonare la repository? (Y/n): ").lower() in ['y', '']:
                print("Clone della repository.")
                try:
                    assert(os.system('gh clone PR1LabEsercizi') == 0)
                except AssertionError:
                    print("Impossibile clonare la repository.")
                    exit(-1)

    welcome()
