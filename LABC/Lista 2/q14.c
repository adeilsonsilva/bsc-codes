#include <stdio.h>

int main()
{
	int hora_cheg, min_cheg, hora_sai, min_sai, aux_hora, aux_min;
	float total;
	
	printf("Digite a hora de chegada: ");
	scanf("%d %d", &hora_cheg, &min_cheg);
	printf("\nDigite a hora de saída: ");
	scanf("%d %d", &hora_sai, &min_sai);
	
	aux_hora=hora_sai - hora_cheg;
	aux_min=min_sai - min_cheg;
	
	if(aux_hora >=5) {
		aux_hora=aux_hora-4;
		if(aux_min > 0)
		  total=(1*2)+(2*1.40)+(2*aux_hora+1);
		else
		  total=(1*2)+(1.40*2)+(2*aux_hora);		
	}
	
	else if((aux_hora<5) && (aux_hora>2)){
		if(aux_hora==3){
		  if(aux_min>0)
		   total=(1*2)+(1.40*2);
		 else
		   total=(1*2)+(1.40*1);			
		}

		else if(aux_hora==4){
		  if(aux_min>0)
		   total=(1*2)+(1.40*2)+2;
		 else
		   total=(1*2)+(1.40*2);			
		}		
		
	}
	
	else if(aux_hora <= 2){
		if(aux_min>0)
		  total=(1*aux_hora)+1.40;
		else
		  total=(1*aux_hora);		
	}
	
	else if((aux_hora < 1)){
		if(aux_min >0)
		  total=(1*2)+(2*1.40)+(2*20)+(2*aux_hora+1);
		else
		  total=(1*2)+(2*1.40)+(2*20)+(2*aux_hora);		
	}
	
	printf("\nValor a ser pago: R$%.2f", total);
	return 0;
}
