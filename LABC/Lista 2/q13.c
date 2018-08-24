#include <stdio.h>

int main()
{
	float valor_venda, comissao;
	
	printf("Digite o valor da venda: ");
	scanf("%f", &valor_venda);
	
	if(valor_venda >= 100.000)
		comissao=700+((valor_venda*16)/100);
	
	else if((valor_venda < 100.000) && (valor_venda>=80.000))
	    comissao=650 + ((valor_venda*14)/100);
	
	else if((valor_venda < 80.000) && (valor_venda >= 60.000))
	    comissao=600 + ((valor_venda*14)/100);
	    
	else if((valor_venda < 60.000) && (valor_venda >= 40.000))
	    comissao=550 + ((valor_venda*14)/100);
	    
	else if((valor_venda < 40.000) && (valor_venda >= 20.000))
		comissao=500 + ((valor_venda*14)/100);
		
	else if(valor_venda < 20.000)
		comissao=400 + ((valor_venda*14)/100);
		
	printf("\nComissao: R$%.2f", comissao);
	return 0;	
}
