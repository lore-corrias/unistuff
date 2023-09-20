abstract class Smartphone {
  /*
   * état d'un objet
   */
  bool turnedOn;
  String manufacturer;

  /*
   * Comportement d'un objet
   */
  abstract void turnOn();

  abstract void turnOff();
}
