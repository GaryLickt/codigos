#include <stdio.h>
#include <stdlib.h>

int main() {
  double km, l,kml;
  printf("Digite a distancia em Km: ");
  scanf("%lf",&km);
  printf("Digite a quantidade em litros de gasolina consumida: ");
  scanf("%lf",&l);
  kml = km/l;
  if (kml<8){
    printf("Venda o Carro!\n");
  }else if (8<kml && kml<14){
    printf("Econômico!\n");
  }else{
    printf("Super Econômico!\n");
  }
  return 0;
}
