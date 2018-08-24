public class Sala
{
    private int numero;
    private int qtd_assentos;
    private int qtd_assentos_ocupados;
    private int qtd_assentos_disp;
    private Filme filme_semana;
    
    public Sala(int numero, int qtd_assentos){
        this.numero = numero;
        this.qtd_assentos = qtd_assentos;
        this.qtd_assentos_disp = qtd_assentos;
        this.qtd_assentos_ocupados=0;
        filme_semana = null;
    }
    
    public void setFilme(String titulo, String ator, String lancamento, String faixa){
        filme_semana = new Filme(titulo, ator, lancamento, faixa);
    }
    
    public String getTitulo(){
        return filme_semana.getTitulo();
    }
    
    public boolean vendeIngresso(int qtd_ing){
       
        if(qtd_ing > this.qtd_assentos_disp){
            System.out.println("\nQuantidade de assentos insuficientes.");
            return false;
        }
        else{
          this.qtd_assentos_disp -= qtd_ing;
          this.qtd_assentos_ocupados = this.qtd_assentos - this.qtd_assentos_disp;
          return true;
        }        
    }
    
    public int getFrequencia(){
        return this.qtd_assentos_ocupados;
    }
}
