Negli algoritmi studiati dall'analisi numerica, gli errori relativi ai dati che possono essere riscontrati sono di diversa natura:
* Il problema può essere non preciso
* Modellizzazione (discretizzazione) dei valori
* Calcoli attraverso il computer (approssimazioni, e.s. **$\pi$**)
## Notazione Posizionale
La notazione posizionale è la più classica ed utilizzata, introdotta dagli arabi, ed è quella utilizzata anche dai calcolatori poiché permette di facilitare ampiamente molti processi di calcolo.

Nel nostro sistema, che ragiona su base $10$, a ogni cifra corrisponde una potenza di $10$. Per esempio:
$$
897.15 = 8\times10^2 + 9\times10^1 + 7\times10^0 + 1\times10^{-1} + 5\times10^{-2}
$$
In generale, possiamo ragionare però per qualsiasi base: utilizziamo $\alpha$ per rappresentare una qualsiasi cifra del nostro sistema, e indichiamo la base con $\beta$. In questo modo, un numero qualsiasi può essere rappresentato come:
$$
(\alpha_1\alpha_0\alpha_{-1}\alpha_{-2})_{\beta} = \alpha_1\times\beta^1 + \alpha_0\times\beta^0 + \alpha_{-1}\times\beta^{-1} + \alpha_{-2}\times\beta^{-2}
$$
## Numeri di Macchina
All'interno di un calcolatore, possiamo rappresentare i numeri tramite rappresentazione a **virgola fissa** o **mobile**
### Rappresentazione virgola fissa
Usiamo:
* $t$ cifre per la parte intera
* $s$ cifre per la parte decimale
$$
\alpha_{t-1}...\alpha_0\alpha_{-1}...\alpha_{-s}
$$
Questa tecnica pone tuttavia una limitazione notevole, ossia l'impossibilità di rappresentare un numero $n$ che si trovi al di fuori dell'intervallo $\beta^{-s} < n < \beta^{t}$
### Rappresentazione virgola mobile (floating point)
Questa rappresentazione ci permette di superare il limite posto da quella a virgola fissa, poiché all'interno del calcolatore sono memorizzati solo **le cifre significative** e l'**ordine di grandezza**. Per esempio, il numero $897.15$ viene rappresentato come $0.89715\times10^3$
Questa notazione ci permette di introdurre un insieme $\mathbb{F}$, contenente tutti i possibili numeri con una data base e numero di cifre significative. In particolare:
$$
\mathbb{F}(\beta, t, L, U) = \set{0} \cup \set{x = sign(x)\times m \times \beta^p}
$$
Dove:
* $\beta$ è la **base del numero**, $\beta > 2$
* $t$ sono le **cifre significative**, ossia sostanzialmente i numeri diversi da 0, $t > 0$
* $m$ è la **mantissa**, nella forma $$
		m = \sum^t_{i=1}{d_i\beta^{-i}} = 0.d_1d_2...d_t,\text{ con } d_1 \ne 0
	$$
	la condizione $d_1 \ne 0$ è detta **normalizzazione**, e comporta vantaggi e svantaggi nella rappresentazione per un calcolatore (vedi esempio sotto)
* $p$ è l'**ordine di grandezza**, chiamato anche **esponente** o **caratteristica** $L \le p \le U$
* $sign(x)$ è il segno del numero

* _Esempio_: Elencare tutti gli elementi positivi normalizzati dell'insieme $F(2,3,-1,1)$
	Sappiamo quindi che il numero è della forma:$$
		(0.d_1d_2d_3)_2 \ 2^p, p = -1,0,1
		$$
	ma dato che i numeri sono normalizzati, sappiamo che $d_1 \ne 0$, quindi può essere solo $1$ (la base $2$ permette solo $0$ e $1$ come cifre):
	$$
	0.1d_2d_3 = 
	\begin{cases} 
	0.100 = 
		\begin{cases}
		\text{preso }p=-1,\ (1\times2^{-1}+0\times2^{-2}+0\times2^{-3}) \times 2^{-1} = \frac{1}{4} \\
		\text{preso }p=0,\ (1\times2^{-1}+0\times2^{-2}+0\times2^{-3}) \times 2^0 = \frac{1}{2} \\
		\text{preso }p=1,\ (1\times2^{-1}+0\times2^{-2}+0\times2^{-3}) \times 2 = 1\end{cases} \\ \\
	0.101 =
		\begin{cases}
		\text{preso }p=-1,\ (1 \times 2^{-1} + 0 \times 2^{-2} + 1 \times 2^{-3}) \times 2^{-1} = \frac{5}{16} \\
		\text{preso }p=0,\ (1 \times 2^{-1} + 0 \times 2^{-2} + 1 \times 2^{-3}) \times 2^{0} = \frac{5}{8} \\
		\text{preso }p=1,\ (1 \times 2^{-1} + 0 \times 2^{-2} + 1 \times 2^{-3}) \times 2^{-1} = \frac{5}{4}
		\end{cases} \\ \\
	0.110 = 
		\begin{cases}
		\text{preso }p=-1,\ (1 \times 2^{-1} + 1 \times 2^{-2} + 0 \times 2^{-3}) \times 2^{-1} = \frac{3}{8}\\
		\text{preso }p=0,\ (1 \times 2^{-1} + 1 \times 2^{-2} + 0 \times 2^{-3}) \times 2^{0} = \frac{3}{4}\\
		\text{preso }p=1,\ (1 \times 2^{-1} + 1 \times 2^{-2} + 0 \times 2^{-3}) \times 2^{1} = \frac{3}{2}
		\end{cases}\\\\
	0.111 = 
		\begin{cases}
		\text{preso }p=-1,\ (1 \times 2^{-1} + 1 \times 2^{-2} + 1 \times 2^{-3}) \times 2^{-1} = \frac{7}{16}\\
		\text{preso }p=-1,\ (1 \times 2^{-1} + 1 \times 2^{-2} + 1 \times 2^{-3}) \times 2^{0} = \frac{7}{8}\\
		\text{preso }p=-1,\ (1 \times 2^{-1} + 1 \times 2^{-2} + 1 \times 2^{-3}) \times 2^{1} = \frac{7}{4}\\
		\end{cases}\\
	\end{cases}
	$$
	Tuttavia, abbandonando la condizione di normalizzazione, possiamo anche aggiungere i numeri:
	* $0.001$
	* $0.010$
	* $0.011$
	Come è facile notare, i numeri aggiunti in questo modo sono notevolmente più piccoli del più piccolo numero rappresentato tra quelli sopra. Questa tecnica di abbandonare la normalizzazione ci consente, infatti, una precisione maggiore per i numeri vicino allo zero, ed è chiamata **gradual underflow**.

### Numero più piccolo
Per capire come trovare il più piccolo numero di un insieme, ragioniamo senza considerare loro segno. Quindi, generalizzando per la mantissa, la base e l'esponente, avremo:$$
	|x| = m \times \beta^p = (0.d_1d_2...d_{\tau})_\beta \ \beta^p
	$$
Logicamente, tenendo a mente la normalizzazione, la più piccola mantissa e il più piccolo esponente saranno:
$$
(0.10000...)_\beta \times \beta^L = \beta^{-1} \times \beta^L = \beta^{L-1}
$$
Nell'esempio di prima, avevamo che $\beta=2$ e $L=-1$, quindi il più piccolo numero è effettivamente $2^{-2} = \frac{1}{4}$

Senza normalizzazione, avremo che tutte le cifre della parte decimale del numero saranno a $0$, tranne l'ultima, che sarà a $1$. Sapendo che nel nostro numero ci sono $t$ cifre significative, la mantissa corrisponderà a $\beta^{-t}$. Quindi abbiamo:
$$
(0.000...1)_\beta\ \times \beta^L = \beta^{-t} \times \beta^L = \beta^{L-t}
$$
Sempre nell'esempio di prima, si ha $2^{-1-3}=2^{-4}=\frac{1}{16}$
### Numero più grande
In questo caso, la cifra più grande dipende ovviamente dalla base.
Per esempio, la più grande mantissa in base 10 con 3 cifre significative è $0.999$, che è anche uguale a $1-0.001$. In generale, il più grande numero sarà sempre della forma:
$$
1-\beta^{-\tau} \times \beta^U = \beta^U \times \beta^{U-t}
$$
Attenzione perché $\beta^U$ **non è rappresentabile**.
### Esercizio
* Trovare il numero più piccolo e più grande dell'insieme $F(2,3,-1,2)$
	Quindi abbiamo:
	* $\beta=2$, la base
	* $t=3$, le cifre significative
	* $-1 \leq p \leq 2$
	$$0.1d_2d_3\begin{cases}
		0.100 = 
			\begin{cases}
			0.100 \times 2^{-1} = \frac{1}{2} \times \frac{1}{2} =\frac{1}{4} \\
			0.100 \times 2^{0} = \frac{1}{2} \times 1 = \frac{1}{2}\\
			0.100 \times 2^{1} = \frac{1}{2} \times 2 = 1\\
			0.100 \times 2^{2} = \frac{1}{2} \times 4 = 2
			\end{cases}\\
		0.101 \\
		0.110 \\ 
		0.111 = 
			\begin{cases}
			(2^{-1}+2^{-2}+2^{-3}) \times 2^{-1} = \frac{7}{16} \\
			(2^{-1}+2^{-2}+2^{-3}) \times 2^{0} = \frac{7}{8} \\
			(2^{-1}+2^{-2}+2^{-3}) \times 2^{1} = \frac{7}{4} \\
			(2^{-1}+2^{-2}+2^{-3}) \times 2^{2} = \frac{7}{2}
			\end{cases}
			
		\end{cases}
	$$
	Questo significa che il più piccolo numero rappresentabile è $\frac{1}{4}$, il più grande $\frac{7}{2}$. E infatti:
	$$
	\text{numero più piccolo} = \beta^{L-1} = \frac{1}{4}
	$$
	$$
	\text{numero più grande} = \beta^U - \beta^{U-t} = 2^2 - 2^{2-3} \times 2^{1} = 4 - \frac{1}{2} = \frac{7}{2}
	$$