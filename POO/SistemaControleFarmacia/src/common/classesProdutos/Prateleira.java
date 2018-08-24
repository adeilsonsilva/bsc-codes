package common.classesProdutos;

public class Prateleira {
	private Farmaco[] farmacos;
	private final int numeroPrateleira;
	private static final int qtdMaxFarmacos = 10;
	public static int qtdAtualPrateleiras = 0;
        public static final int qtdMaxPrateleiras = 10;
	private int qtdAtualFarmacos;

	public Prateleira() {
		this.farmacos = new Farmaco[Prateleira.qtdMaxFarmacos];
		this.qtdAtualFarmacos = 0;
		this.numeroPrateleira = Prateleira.qtdAtualPrateleiras++;
	}
	
	public int getNumeroPrateleira() {
		return numeroPrateleira;
	}
	
	public boolean adicionaFarmaco(Farmaco farmaco){
	  	if(this.qtdAtualFarmacos < Prateleira.qtdMaxFarmacos){
	  		this.farmacos[this.qtdAtualFarmacos] = farmaco;
	  		this.qtdAtualFarmacos++;
	  		return true;
	  	}
	  	return false;
	}
   
	public Farmaco pesquisaFarmaco(String nome, String codigo){
		int i;
		
		if(Prateleira.qtdAtualPrateleiras > 0){
			for(i=0; i<this.qtdAtualFarmacos; i++){
				if((this.farmacos[i].getNome().equals(nome)) && (this.farmacos[i].getCodigo().equals(codigo))){
					return this.farmacos[i];
				}
			}
		}
		return null;
	}
}
