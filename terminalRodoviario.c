#include <stdio.h>
#include <stdlib.h>

int main (){
    float qtdePassageiros[24] = {200, 350, 500, 450, 700, 1000, 2000, 1500, 1000, 1300, 1200, 1500, 1500, 1300, 1300, 1500, 1300, 1800, 1700, 1600, 1500, 1200, 1000, 500};
    int i;
    float horaPicoManha, horaPicoTarde, qtdePicoManha = 0, qtdePicoTarde = 0;
    float mediaManha, mediaTarde, somaManha = 0, somaTarde = 0;
    float horaAnteriorManha, horaAnteriorTarde;

    for (i = 0; i < 25; i++){
        if (i < 12){
            somaManha += qtdePassageiros[i];
            if (qtdePassageiros[i] > qtdePicoManha){
                qtdePicoManha = qtdePassageiros[i];
                horaPicoManha = i + 1;
                horaAnteriorManha = qtdePassageiros[i - 1];
            }
            
            
        }
        if (i >= 12){
            somaTarde += qtdePassageiros[i];
            if (qtdePassageiros[i] > qtdePicoTarde){
                qtdePicoTarde = qtdePassageiros[i];
                horaPicoTarde = i + 1;
                horaAnteriorTarde = qtdePassageiros[i - 1];
                
            }
            
        }
    }
    mediaManha = somaManha / 12;
    mediaTarde = somaTarde / 12;
    printf("Quantidade Meda de Passageiros: %.0f\t %.0f\n", mediaManha, mediaTarde);
    printf("Hora de Pico: %.0fh\t %.0fh\n", horaPicoManha, horaPicoTarde);

    horaAnteriorManha = 100 * (horaAnteriorManha / mediaManha);
    horaAnteriorTarde = 100 * (horaAnteriorTarde / mediaTarde);

    if (horaAnteriorManha < 100 && horaAnteriorTarde < 100){
        horaAnteriorManha = 100 - horaAnteriorManha;
        horaAnteriorTarde = 100 - horaAnteriorTarde;
        printf("Percentual (hora anterior) ao pico: %.2f abaixo | %.2f abaixo\n", horaAnteriorManha, horaAnteriorTarde);
    }
    else if (horaAnteriorManha > 100 && horaAnteriorTarde > 100){
        horaAnteriorManha = horaAnteriorManha - 100;
        horaAnteriorTarde = horaAnteriorTarde - 100;
        printf("Percentual (hora anterior) ao pico: %.2f acima | %.2f acima\n", horaAnteriorManha, horaAnteriorTarde);

    }
    else if (horaAnteriorManha > 100 && horaAnteriorTarde < 100){
        horaAnteriorManha = horaAnteriorManha - 100;
        horaAnteriorTarde = 100 - horaAnteriorTarde;
        printf("Percentual (hora anterior) ao pico: %.2f acima | %.2f abaixo\n", horaAnteriorManha, horaAnteriorTarde);
    }
    else if (horaAnteriorManha < 100 && horaAnteriorTarde > 100){
        horaAnteriorManha = 100 - horaAnteriorManha;
        horaAnteriorTarde = horaAnteriorTarde - 100;
        printf("Percentual (hora anterior) ao pico: %.2f abaixo | %.2f acima\n", horaAnteriorManha, horaAnteriorTarde);
        
    }
    else{
        printf("Na hora anterior ao pico dos dois turnos, os valores sao identicos as medias!");
    }
}

