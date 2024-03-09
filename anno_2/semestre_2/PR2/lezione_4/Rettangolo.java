public class Rettangolo {

  private int x;
  private int y;
  private float base;
  private float altezza;

  Rettangolo(int x, int y, float base, float altezza) {
    this.x = x;
    this.y = y;
    this.base = base;
    this.altezza = altezza;
  }

  public int calcolaArea() {
    return this.base * this.altezza;
  }

  public static void main(String[] args) {
    Rettangolo rettangolo = new Rettangolo(0, 0, 100, 200);

    System.out.println(rettangolo.calcolaArea());
  }
}
