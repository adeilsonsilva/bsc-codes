package common.classesProdutos;
import common.interfaces.Receitavel;

public class Farmaco implements Receitavel {
	private String sintomas;
	private String efeitosColaterais;
	private String nome;
	private String codigo;
	private String tarja;
	private String fabricante;
	private double preco;
        private int quantidade;
	
	public Farmaco(String sintomas, String efeitosColaterais, String nome, String codigo, String fabricante, double preco, int quantidade) {
		this(sintomas, efeitosColaterais, nome, codigo, "livre", fabricante, preco, quantidade);
	}

	public Farmaco(String sintomas, String efeitosColaterais, String nome, String codigo, String tarja, String fabricante,  double preco, int quantidade) {
		this.sintomas = sintomas;
		this.efeitosColaterais = efeitosColaterais;
		this.nome = nome;
		this.codigo = codigo;
		this.tarja = tarja;
		this.fabricante = fabricante;
		this.preco = preco;
                this.quantidade = quantidade;
	}

	public String getSintomas() {
		return sintomas;
	}

	public void setSintomas(String sintomas) {
		this.sintomas = sintomas;
	}

	public String getEfeitosColaterais() {
		return efeitosColaterais;
	}

	public void setEfeitosColaterais(String efeitosColaterais) {
		this.efeitosColaterais = efeitosColaterais;
	}

	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public String getCodigo() {
		return codigo;
	}

	public void setCodigo(String codigo) {
		this.codigo = codigo;
	}

	public String getTarja() {
		return tarja;
	}

	public void setTarja(String tarja) {
		this.tarja = tarja;
	}

	public String getFabricante() {
		return fabricante;
	}

	public void setFabricante(String fabricante) {
		this.fabricante = fabricante;
	}

	public double getPreco() {
		return preco;
	}

	public void setPreco(double preco) {
		this.preco = preco;
	}

	public void ReceitaSugerida() {
		System.out.println("Esta droga é receitada diante dos seguintes sintomas:\n"+this.sintomas);
	}

	public void EfeitosColaterais() {
		System.out.println("Esta droga possui os seguintes efeitos colaterais:\n"+this.efeitosColaterais);
	}
        
        public boolean vender (int quantidade){
            int qtdTemp = this.quantidade - quantidade;
            if(qtdTemp >= 0){
                this.quantidade -= quantidade;
                return true;
            }
            return false;
        }

}
