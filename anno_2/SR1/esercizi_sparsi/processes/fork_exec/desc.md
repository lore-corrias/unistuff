Il ``main`` esegue un fork una prima volta, e dal figlio esegue il comando ``ls -l`` attraverso la funzione ``execlp``.
Successivamente, il padre aspetta che il comando termini, e dopodiché esegue un secondo fork per eseguire il comando ``pwd``.
