class Libro {
  private String autore;
  private String titolo;
  private int nPagine;
  private int paginaCorrente = 0;

  /*
   * Il costruttore di default (senza parametri né corpo) viene inserito
   * automaticamente
   * dal compilatore, quindi non è necessario aggiungerlo a mano
   * Libro() {}
   */

  // Possiamo anche creare un costruttore senza parametri, ma con un corpo
  Libro() {
    this.autore = "Sconosciuto";
    this.titolo = "Ignoto";
  }

  // Possiamo avere più costruttori con un diverso numero/tipo di parametri
  Libro(String titolo, String autore, int nPagine) {
    this.titolo = titolo;
    this.autore = autore;
    this.nPagine = nPagine;

    // Una sintassi alternativa usa this(), che chiama un altro costruttore
    // this(titolo, autore, nPagine, 1);
  }

  Libro(String titolo, String autore, int nPagine, int paginaCorrente) {
    this.titolo = titolo;
    this.autore = autore;
    this.nPagine = nPagine;
    this.paginaCorrente = paginaCorrente;
  }

  // Esempio di metodo: sposto la pagina di uno
  // Se il metodo non restituisce nulla, il tipo di ritorno è "void"
  void sfogliaPagina() {
    if (paginaCorrente < nPagine)
      paginaCorrente++;
  }

  // incapsulamento per proteggere il codice da bug
  public void cambiaPaginaCorrente(int paginaCorrente) {
    // verifica che la pagina sia valida
    if (paginaCorrente < 0 || paginaCorrente > nPagine) {
      System.out.println("La pagina corrente non è valida!");
    } else {
      this.paginaCorrente = paginaCorrente;
    }
  }

  // Metodo che restituisce la pagina corrente, che è private
  public int prendiPaginaCorrente() {
    return this.paginaCorrente;
  }
}
