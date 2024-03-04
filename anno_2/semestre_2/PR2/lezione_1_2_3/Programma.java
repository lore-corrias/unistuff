public class Programma {

  // Sintassi del metodo main
  public static void main(String[] args) {
    System.out.println("Esempio classe libro");

    // Chiamata al costruttore della classe libro
    Libro romanzo = new Libro("Promessi sposi", "Manzoni", 200);

    // Chiamata al metodo sfogliaPagina, che aumenta la pagina corrente di uno
    romanzo.sfogliaPagina();

    // Che senso ha mettere una pagina negativa? Vedi gli appunti
    // romanzo.paginaCorrente = -6;

    // Modifico l'attributo paginaCorrente correttamente, attraverso il metodo
    // relativo
    romanzo.cambiaPaginaCorrente(-2); // la pagina non viene cambiata
    romanzo.cambiaPaginaCorrente(10); // la pagina viene cambiata

    // Errore: l'attributo è private, non posso accedere
    // System.out.println("Pagina corrente: " + romanzo.paginaCorrente);
    System.out.println("Pagina corrente: " + romanzo.prendiPaginaCorrente());
  }
}
